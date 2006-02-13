// 
//   Copyright (C) 2005, 2006 Free Software Foundation, Inc.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <typeinfo>
#include "log.h"
#include "Function.h"
#include "array.h"
#include "gnash.h"

namespace gnash {

static as_object* getFunctionPrototype()
{
	static as_object* proto = NULL;

	if ( proto == NULL ) {
		// Initialize Function prototype
		proto = new as_object();
		proto->set_member("apply", &function_apply);
		proto->set_member("call", &function_call);
	}

	return proto;

}


void function_init(as_object* global)
{
	// This is going to be the global Function "class"/"function"
	static function_as_object *func=new function_as_object();

	// We make the 'prototype' element be a reference to
	// the __proto__ element
	as_object* proto = func->m_prototype;
	proto->add_ref();

	proto->set_member("constructor", func); //as_value(func));
	proto->set_member_flags("constructor", 1);

	func->set_member("prototype", as_value(proto));

	// Register _global.Function
	global->set_member("Function", func);

}


function_as_object::~function_as_object()
{
	if ( m_properties ) m_properties->drop_ref();
}

void
function_as_object::init()
{
#if 1
#endif
}

function_as_object::function_as_object()
		:
		as_object(getFunctionPrototype()),
		m_action_buffer(NULL),
		m_env(NULL),
		m_with_stack(),
		m_start_pc(0),
		m_length(0),
		m_is_function2(false),
		m_local_register_count(0),
		m_function2_flags(0)
{
	init();

	// We do not define a new 'prototype' member.
	// Caller will take care of it 
}

function_as_object::function_as_object(action_buffer* ab, as_environment* env,
		int start, const array<with_stack_entry>& with_stack)
		:
		as_object(getFunctionPrototype()), 
		m_action_buffer(ab),
		m_env(env),
		m_with_stack(with_stack),
		m_start_pc(start),
		m_length(0),
		m_is_function2(false),
		m_local_register_count(0),
		m_function2_flags(0)
{
	assert(m_action_buffer);
	init();

	// Define the 'prototype' member as a new object with
	// only the 'constructor' element defined.
	m_properties = new as_object();
	as_object* proto = m_properties;
	proto->add_ref();

	proto->set_member("constructor", this); //as_value(func));
	proto->set_member_flags("constructor", 1);

	set_member("prototype", as_value(proto));
}

// Dispatch.
void
function_as_object::operator()(const fn_call& fn)
{
	as_environment*	our_env = m_env;
	if (our_env == NULL)
	{
		our_env = fn.env;
	}
	assert(our_env);

#if 0
	log_msg("function_as_object() stack:\n"); fn.env->dump_stack();
	log_msg("  first_arg_bottom_index: %d\n", fn.first_arg_bottom_index);
#endif

	// Set up local stack frame, for parameters and locals.
	int	local_stack_top = our_env->get_local_frame_top();
	our_env->add_frame_barrier();

	if (m_is_function2 == false)
	{
		// Conventional function.

		// Push the arguments onto the local frame.
		int	args_to_pass = imin(fn.nargs, m_args.size());
		for (int i = 0; i < args_to_pass; i++)
		{
			assert(m_args[i].m_register == 0);
			our_env->add_local(m_args[i].m_name, fn.arg(i));
		}

		// Set up local variable 'this'.
		//    --strk(2006-02-07);
		assert(fn.this_ptr);
		our_env->set_local("this", fn.this_ptr);

	}
	else
	{
		// function2: most args go in registers; any others get pushed.
		
		// Create local registers.
		our_env->add_local_registers(m_local_register_count);

		// Handle the explicit args.
		int	args_to_pass = imin(fn.nargs, m_args.size());
		for (int i = 0; i < args_to_pass; i++)
		{
			if (m_args[i].m_register == 0)
			{
				// Conventional arg passing: create a local var.
				our_env->add_local(m_args[i].m_name, fn.arg(i));
			}
			else
			{
				// Pass argument into a register.
				int	reg = m_args[i].m_register;
				*(our_env->local_register_ptr(reg)) = fn.arg(i);
			}
		}

		// Handle the implicit args.
		int	current_reg = 1;
		if (m_function2_flags & 0x01)
		{
			// preload 'this' into a register.
			(*(our_env->local_register_ptr(current_reg))).set_as_object(our_env->m_target);
			current_reg++;
		}

		if (m_function2_flags & 0x02)
		{
			// Don't put 'this' into a local var.
		}
		else
		{
			// Put 'this' in a local var.
			our_env->add_local("this", as_value(our_env->m_target));
		}

		// Init arguments array, if it's going to be needed.
		smart_ptr<as_array_object>	arg_array;
		if ((m_function2_flags & 0x04) || ! (m_function2_flags & 0x08))
		{
			arg_array = new as_array_object;

			as_value	index_number;
			for (int i = 0; i < fn.nargs; i++)
			{
				index_number.set_int(i);
				arg_array->set_member(index_number.to_string(), fn.arg(i));
			}
		}

		if (m_function2_flags & 0x04)
		{
			// preload 'arguments' into a register.
			(*(our_env->local_register_ptr(current_reg))).set_as_object(arg_array.get_ptr());
			current_reg++;
		}

		if (m_function2_flags & 0x08)
		{
			// Don't put 'arguments' in a local var.
		}
		else
		{
			// Put 'arguments' in a local var.
			our_env->add_local("arguments", as_value(arg_array.get_ptr()));
		}

		if (m_function2_flags & 0x10)
		{
			// Put 'super' in a register.
			log_error("TODO: implement 'super' in function2 dispatch (reg)\n");

			current_reg++;
		}

		if (m_function2_flags & 0x20)
		{
			// Don't put 'super' in a local var.
		}
		else
		{
			// Put 'super' in a local var.
			log_error("TODO: implement 'super' in function2 dispatch (var)\n");
		}

		if (m_function2_flags & 0x40)
		{
			// Put '_root' in a register.
			(*(our_env->local_register_ptr(current_reg))).set_as_object(
				our_env->m_target->get_root_movie());
			current_reg++;
		}

		if (m_function2_flags & 0x80)
		{
			// Put '_parent' in a register.
			array<with_stack_entry>	dummy;
			as_value	parent = our_env->get_variable("_parent", dummy);
			(*(our_env->local_register_ptr(current_reg))) = parent;
			current_reg++;
		}

		if (m_function2_flags & 0x100)
		{
			// Put '_global' in a register.
			(*(our_env->local_register_ptr(current_reg))).set_as_object(s_global.get_ptr());
			current_reg++;
		}
	}

	// Execute the actions.
	m_action_buffer->execute(our_env, m_start_pc, m_length, fn.result, m_with_stack, m_is_function2);

	// Clean up stack frame.
	our_env->set_local_frame_top(local_stack_top);

	if (m_is_function2)
	{
		// Clean up the local registers.
		our_env->drop_local_registers(m_local_register_count);
	}
}

void function_apply(const fn_call& fn)
{
	int pushed=0; // new values we push on the stack

	// Get function body 
	function_as_object* function_obj = fn.env->top(1).to_as_function();
	assert(function_obj);

	// Copy new function call from old one, we'll modify 
	// the copy only if needed
	fn_call new_fn_call(fn);
	new_fn_call.nargs=0;

	if ( ! fn.nargs )
	{
		IF_VERBOSE_DEBUG(log_msg("Function.apply() with no args\n"));
	}
	else
	{
		// Get the object to use as 'this' reference
		as_object *this_ptr = fn.arg(0).to_object();
		new_fn_call.this_ptr = this_ptr;

		if ( fn.nargs > 1 )
		// we have an 'arguments' array
		{
			if ( fn.nargs > 2 )
			{
	IF_VERBOSE_DEBUG(log_msg("Function.apply() with more then 2 args\n"));
			}

			as_object *arg1 = fn.arg(1).to_object();
			assert(arg1);

			as_array_object *arg_array = \
					dynamic_cast<as_array_object*>(arg1);

			if ( ! arg_array )
			{
	IF_VERBOSE_DEBUG(log_msg("Second argument to Function.apply() "
		"is not an array\n"));
			}
			else
			{

				unsigned int nelems = arg_array->size();

				//log_error("Function.apply(this_ref, array[%d])\n", nelems);
				as_value index, value;
				for (unsigned int i=nelems; i; i--)
				{
					value=arg_array->elements[i-1];
					//log_msg("value: %s\n", value.to_string());
					fn.env->push_val(value);
					pushed++;
				}

				new_fn_call.first_arg_bottom_index=fn.env->get_top_index();
				new_fn_call.nargs=nelems;
			}
		}
	}

	// Call the function 
	(*function_obj)(new_fn_call);

	// Drop additional values we pushed on the stack 
	fn.env->drop(pushed);

	//log_msg("at function_apply exit, stack: \n"); fn.env->dump_stack();
}

void function_call(const fn_call& fn) {

	// Get function body 
	function_as_object* function_obj = fn.env->top(1).to_as_function();
	assert(function_obj);

	// Copy new function call from old one, we'll modify 
	// the copy only if needed
	fn_call new_fn_call(fn);

	if ( ! fn.nargs )
	{
		IF_VERBOSE_DEBUG(log_msg("Function.call() with no args\n"));
		new_fn_call.nargs=0;
	}
	else
	{
		// Get the object to use as 'this' reference
		as_object *this_ptr = fn.arg(0).to_object();
		new_fn_call.this_ptr = this_ptr;
		new_fn_call.nargs--;
		new_fn_call.first_arg_bottom_index--;
	}

	// Call the function 
	(*function_obj)(new_fn_call);

	//log_msg("at function_call exit, stack: \n"); fn.env->dump_stack();

	//log_msg("%s: tocheck \n", __FUNCTION__);
}


} // end of gnash namespace


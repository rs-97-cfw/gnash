// 
//   Copyright (C) 2005, 2006 Free Software Foundation, Inc.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

// 
//
//

/* $Id: character.cpp,v 1.16 2007/01/30 18:29:40 strk Exp $ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "character.h"
#include "sprite_instance.h"
#include "drag_state.h" // for do_mouse_drag (to be moved in movie_root)
#include "VM.h" // for do_mouse_drag (to be moved in movie_root)
#include "fn_call.h" // for shared ActionScript getter-setters
#include "GnashException.h" // for shared ActionScript getter-setters (ensure_character)

namespace gnash
{

// TODO: this should likely go in movie_root instead !
void
character::do_mouse_drag()
{
	drag_state st;
	_vm.getRoot().get_drag_state(st);
	if ( this == st.getCharacter() )
	{
		// We're being dragged!
		int	x, y, buttons;
		get_root_movie()->get_mouse_state(x, y, buttons);

		point world_mouse(PIXELS_TO_TWIPS(x), PIXELS_TO_TWIPS(y));
		if ( st.hasBounds() )
		{
			// Clamp mouse coords within a defined rect.
			// (it is assumed that drag_state keeps
			st.getBounds().clamp(world_mouse);
		}

		if (st.isLockCentered())
		{
		    matrix	world_mat = get_world_matrix();
		    point	local_mouse;
		    world_mat.transform_by_inverse(&local_mouse, world_mouse);

		    matrix	parent_world_mat;
		    if (m_parent != NULL)
			{
			    parent_world_mat = m_parent->get_world_matrix();
			}

		    point	parent_mouse;
		    parent_world_mat.transform_by_inverse(&parent_mouse, world_mouse);
					
		    // Place our origin so that it coincides with the mouse coords
		    // in our parent frame.
		    matrix	local = get_matrix();
		    local.m_[0][2] = parent_mouse.m_x;
		    local.m_[1][2] = parent_mouse.m_y;
		    set_matrix(local);
		}
		else
		{
			// Implement relative drag...
			static bool warned_relative_drag = false;
			if ( ! warned_relative_drag )
			{
				log_warning("FIXME: Relative drag unsupported");
		    		warned_relative_drag = true;
		    	}
		}
	}
}

matrix
character::get_world_matrix() const
{
	matrix m;
	if (m_parent != NULL)
	{
	    m = m_parent->get_world_matrix();
	}
	m.concatenate(get_matrix());

	return m;
}

cxform
character::get_world_cxform() const
{
	cxform	m;
	if (m_parent != NULL)
	{
	    m = m_parent->get_world_cxform();
	}
	m.concatenate(get_cxform());

	return m;
}

sprite_instance*
character::get_root_movie()
{
	assert(m_parent != NULL);
	assert(m_parent->get_ref_count() > 0);
	return m_parent->get_root_movie();
}

void
character::get_mouse_state(int& x, int& y, int& buttons)
{
	assert(m_parent != NULL);
	assert(m_parent->get_ref_count() > 0);
	get_parent()->get_mouse_state(x, y, buttons);
}

character*
character::get_relative_target_common(const std::string& name)
{
	if (name == "." || name == "this")
	{
	    return this;
	}
	else if (name == "..")
	{
		// Never NULL
		character* parent = get_parent();
		if ( ! parent )
		{
			IF_VERBOSE_ASCODING_ERRORS(
			// AS code trying to access something before the root
			log_warning("ActionScript code trying to reference"
				" an unexistent parent with '..' "
				" (an unexistent parent probably only "
				"occurs in the root MovieClip)."
				" Returning a reference to top parent "
				"(probably the root clip).");
			);
			//parent = this;
			assert(this == get_root_movie());
			return this;
		}
		return parent;
	}
	else if (name == "_level0"
	     || name == "_root")
	{
		return get_root_movie();
	}

	return NULL;
}

void
character::set_invalidated()
{
	if ( m_parent ) m_parent->set_invalidated();
  
	// Ok, at this point the instance will change it's
	// visual aspect after the
	// call to set_invalidated(). We save the *current*
	// position of the instance because this region must
	// be updated even (or first of all) if the character
	// moves away from here.
	// 
	if ( ! m_invalidated )
	{
		m_invalidated = true;
		m_old_invalidated_bounds.set_null();
		get_invalidated_bounds(&m_old_invalidated_bounds, true);
	}

}

//---------------------------------------------------------------------
//
// Shared ActionScript getter-setters
//
//---------------------------------------------------------------------

// Wrapper around dynamic_cast to implement user warning.
// To be used by builtin properties and methods.
static character*
ensure_character(as_object* obj)
{
	character* ret = dynamic_cast<character*>(obj);
	if ( ! ret )
	{
		throw ActionException("builtin method or gettersetter for character objects called against non-character instance");
	}
	return ret;
}

void
character::onrollover_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		ptr->get_event_handler(event_id::ROLL_OVER, fn.result);
	}
	else // setter
	{
		ptr->set_event_handler(event_id::ROLL_OVER, fn.arg(0));
	}

}

void
character::x_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		matrix m = ptr->get_matrix();
		fn.result->set_double(TWIPS_TO_PIXELS(m.m_[0][2]));
	}
	else // setter
	{
		matrix m = ptr->get_matrix();
		m.m_[0][2] = infinite_to_fzero(PIXELS_TO_TWIPS(fn.arg(0).to_number()));
		ptr->set_matrix(m);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}

}

void
character::y_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		matrix m = ptr->get_matrix();
		fn.result->set_double(TWIPS_TO_PIXELS(m.m_[1][2]));
	}
	else // setter
	{
		matrix m = ptr->get_matrix();
		m.m_[1][2] = infinite_to_fzero(PIXELS_TO_TWIPS(fn.arg(0).to_number()));
		ptr->set_matrix(m);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}

}

void
character::xscale_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		matrix m = ptr->get_matrix();
		float xscale = m.get_x_scale();
		fn.result->set_double(xscale * 100); // result in percent
	}
	else // setter
	{
		matrix m = ptr->get_matrix();

		double scale_percent = fn.arg(0).to_number();

		// Handle bogus values
		if (isnan(scale_percent))
		{
			IF_VERBOSE_ASCODING_ERRORS(
			log_aserror("Attempt to set _xscale to %g, refused",
                            scale_percent);
			);
                        return;
		}
		else if (scale_percent < 0 )
		{
			IF_VERBOSE_ASCODING_ERRORS(
			log_aserror("Attempt to set _xscale to %g, use 0",
                            scale_percent);
			);
                        scale_percent = 0;
		}

		// input is in percent
		float scale = (float)scale_percent/100.f;

		// Decompose matrix and insert the desired value.
		float x_scale = scale;
		float y_scale = m.get_y_scale();
		float rotation = m.get_rotation();
		m.set_scale_rotation(x_scale, y_scale, rotation);

		ptr->set_matrix(m);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}

}

void
character::yscale_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		matrix m = ptr->get_matrix();
		float yscale = m.get_y_scale();
		fn.result->set_double(yscale * 100); // result in percent
	}
	else // setter
	{
		matrix m = ptr->get_matrix();

		double scale_percent = fn.arg(0).to_number();

		// Handle bogus values
		if (isnan(scale_percent))
		{
			IF_VERBOSE_ASCODING_ERRORS(
			log_aserror("Attempt to set _yscale to %g, refused",
                            scale_percent);
			);
                        return;
		}
		else if (scale_percent < 0 )
		{
			IF_VERBOSE_ASCODING_ERRORS(
			log_aserror("Attempt to set _yscale to %g, use 0",
                            scale_percent);
			);
                        scale_percent = 0;
		}

		// input is in percent
		float scale = (float)scale_percent/100.f;

		// Decompose matrix and insert the desired value.
		float x_scale = m.get_x_scale();
		float y_scale = scale;
		float rotation = m.get_rotation();
		m.set_scale_rotation(x_scale, y_scale, rotation);

		ptr->set_matrix(m);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}

}

void
character::xmouse_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		// Local coord of mouse IN PIXELS.
		int x, y, buttons;
		VM::get().getRoot().get_mouse_state(x, y, buttons);

		matrix m = ptr->get_world_matrix();

		point a(PIXELS_TO_TWIPS(x), PIXELS_TO_TWIPS(y));
		point b;
			
		m.transform_by_inverse(&b, a);

		fn.result->set_double(TWIPS_TO_PIXELS(b.m_x));
	}
	else // setter
	{
		IF_VERBOSE_ASCODING_ERRORS(
		log_aserror("Attempt to set read-only property '_xmouse'");
		);
	}
}

void
character::ymouse_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		// Local coord of mouse IN PIXELS.
		int x, y, buttons;
		VM::get().getRoot().get_mouse_state(x, y, buttons);

		matrix m = ptr->get_world_matrix();

		point a(PIXELS_TO_TWIPS(x), PIXELS_TO_TWIPS(y));
		point b;
			
		m.transform_by_inverse(&b, a);

		fn.result->set_double(TWIPS_TO_PIXELS(b.m_y));
	}
	else // setter
	{
		IF_VERBOSE_ASCODING_ERRORS(
		log_aserror("Attempt to set read-only property '_ymouse'");
		);
	}
}

void
character::alpha_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		fn.result->set_double(ptr->get_cxform().m_[3][0] * 100.f);
	}
	else // setter
	{
		// Set alpha modulate, in percent.
		cxform	cx = ptr->get_cxform();
		cx.m_[3][0] = infinite_to_fzero(fn.arg(0).to_number()) / 100.f;
		ptr->set_cxform(cx);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}

}

void
character::visible_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		fn.result->set_bool(ptr->get_visible());
	}
	else // setter
	{
		ptr->set_visible(fn.arg(0).to_bool());
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}

}

void
character::width_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		fn.result->set_double(TWIPS_TO_PIXELS(ptr->get_width()));
	}
	else // setter
	{
		// @@ tulrich: is parameter in world-coords or local-coords?
		matrix m = ptr->get_matrix();
		m.m_[0][0] = infinite_to_fzero(PIXELS_TO_TWIPS(fn.arg(0).to_number()));
		float w = ptr->get_width();
		if (fabsf(w) > 1e-6f)
		{
			m.m_[0][0] /= w;
		}
		ptr->set_matrix(m);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}
}

void
character::height_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		fn.result->set_double(TWIPS_TO_PIXELS(ptr->get_height()));
	}
	else // setter
	{
		// @@ tulrich: is parameter in world-coords or local-coords?
		matrix m = ptr->get_matrix();
		m.m_[1][1] = infinite_to_fzero(PIXELS_TO_TWIPS(fn.arg(0).to_number()));
		float h = ptr->get_height(); // WARNING: was get_width originally, sounds as a bug
		if (fabsf(h) > 1e-6f)
		{
			m.m_[1][1] /= h;
		}
		ptr->set_matrix(m);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}
}

void
character::rotation_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		// Verified against Macromedia player using samples/test_rotation.swf
		float	angle = ptr->get_matrix().get_rotation();

		// Result is CLOCKWISE DEGREES, [-180,180]
		angle *= 180.0f / float(M_PI);

		fn.result->set_double(angle);
	}
	else // setter
	{
		// @@ tulrich: is parameter in world-coords or local-coords?
		matrix m = ptr->get_matrix();

		// Decompose matrix and insert the desired value.
		float x_scale = m.get_x_scale();
		float y_scale = m.get_y_scale();
		// input is in degrees
		float rotation = (float) fn.arg(0).to_number() * float(M_PI) / 180.f;
		m.set_scale_rotation(x_scale, y_scale, rotation);

		ptr->set_matrix(m);
		ptr->transformedByScript(); // m_accept_anim_moves = false; 
	}
}

void
character::parent_getset(const fn_call& fn)
{
	character* ptr = ensure_character(fn.this_ptr);

	if ( fn.nargs == 0 ) // getter
	{
		// NOTE: will be NULL for root frame !
		// 	 should it be 'ptr' instead ?
		fn.result->set_as_object(ptr->get_parent());
	}
	else // setter
	{
		IF_VERBOSE_ASCODING_ERRORS(
		log_aserror("Attempt to set read-only property '_parent'");
		);
	}
}



} // namespace gnash

// Local Variables:
// mode: C++
// indent-tabs-mode: t
// End:

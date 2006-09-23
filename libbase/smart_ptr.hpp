#line 1 "smart_ptr.hpp"













#line 1 "../boost/config.hpp"
























#line 1 "../boost/config/user.hpp"









































#line 27 "../boost/config.hpp"






























#line 1 "../boost/config/suffix.hpp"
































#line 1 "/usr/include/limits.h"



#line 1 "/usr/include/internal/limits_core.h"
















 
 
 

 
 
 



#ident "$Revision: 1.1 $"
#line 1 "/usr/include/standards.h"

















 
#ident "$Id: smart_ptr.hpp,v 1.1 2006/09/23 08:21:18 nihilus Exp $"





























 












 












 

#line 85 "/usr/include/standards.h"
















 
#line 111 "/usr/include/standards.h"












 












 
#line 143 "/usr/include/standards.h"







 
#line 157 "/usr/include/standards.h"


 
#line 166 "/usr/include/standards.h"








 
#line 182 "/usr/include/standards.h"








 


















 


















 
#line 235 "/usr/include/standards.h"







 




 


#line 29 "/usr/include/internal/limits_core.h"
#line 1 "/usr/include/sgidefs.h"










 




extern "C" {


#ident "$Revision: 1.1 $"















 






 





 









 


		 










 



































 











 






 
#line 135 "/usr/include/sgidefs.h"

typedef int __int32_t;
typedef unsigned  __uint32_t;



typedef long __int64_t;
typedef unsigned long __uint64_t;

#line 217 "/usr/include/sgidefs.h"







typedef __int64_t __psint_t;
typedef __uint64_t __psunsigned_t;





 


 
typedef __int64_t __scint_t;
typedef __uint64_t __scunsigned_t;

#line 245 "/usr/include/sgidefs.h"




}


#line 30 "/usr/include/internal/limits_core.h"
#line 1 "/usr/include/internal/sgimacros.h"















 


















































 







#line 82 "/usr/include/internal/sgimacros.h"

#line 98 "/usr/include/internal/sgimacros.h"

#line 107 "/usr/include/internal/sgimacros.h"

#line 31 "/usr/include/internal/limits_core.h"

extern "C" {



 



 
#line 49 "/usr/include/internal/limits_core.h"




#line 67 "/usr/include/internal/limits_core.h"

#line 74 "/usr/include/internal/limits_core.h"












 

#line 102 "/usr/include/internal/limits_core.h"




 
#line 115 "/usr/include/internal/limits_core.h"






 
#line 132 "/usr/include/internal/limits_core.h"











#line 149 "/usr/include/internal/limits_core.h"



extern long _sysconf(int);	


 






 
#line 173 "/usr/include/internal/limits_core.h"





 










 




















#line 220 "/usr/include/internal/limits_core.h"










 







 
#line 250 "/usr/include/internal/limits_core.h"

#line 258 "/usr/include/internal/limits_core.h"

#line 270 "/usr/include/internal/limits_core.h"








 
#line 291 "/usr/include/internal/limits_core.h"





 












				 




				 











typedef union _h_val {




        __uint32_t i[2];

        double d;
} _h_val;

extern const _h_val __huge_val;





}

#line 5 "/usr/include/limits.h"



#line 34 "../boost/config/suffix.hpp"








































#line 80 "../boost/config/suffix.hpp"































































































































































#line 246 "../boost/config/suffix.hpp"




























































#line 320 "../boost/config/suffix.hpp"


























#line 361 "../boost/config/suffix.hpp"



















































namespace boost{




   typedef long long long_long_type;
   typedef unsigned long long ulong_long_type;

}













































#line 486 "../boost/config/suffix.hpp"











































#line 543 "../boost/config/suffix.hpp"





#line 58 "../boost/config.hpp"













#line 15 "smart_ptr.hpp"

#line 1 "../boost/scoped_ptr.hpp"













#line 1 "../boost/assert.hpp"
















#line 1 "/usr/include/assert.h"
 
#line 1 "/usr/include/internal/assert_core.h"
 











 
 
 

 
 
 

#ident "$Revision: 1.1 $"









 



extern "C" {







extern void __assert(const char *, const char *, int);
#line 50 "/usr/include/internal/assert_core.h"

}
#line 3 "/usr/include/assert.h"

#line 36 "../boost/assert.hpp"
#line 15 "../boost/scoped_ptr.hpp"
#line 1 "../boost/checked_delete.hpp"























namespace boost
{



template<class T> inline void checked_delete(T * x)
{
    
    typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
    (void) sizeof(type_must_be_complete);
    delete x;
}

template<class T> inline void checked_array_delete(T * x)
{
    typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
    (void) sizeof(type_must_be_complete);
    delete [] x;
}

template<class T> struct checked_deleter
{
    typedef void result_type;
    typedef T * argument_type;

    void operator()(T * x) const
    {
        
        boost::checked_delete(x);
    }
};

template<class T> struct checked_array_deleter
{
    typedef void result_type;
    typedef T * argument_type;

    void operator()(T * x) const
    {
        boost::checked_array_delete(x);
    }
};

} 

#line 16 "../boost/scoped_ptr.hpp"
#line 1 "../boost/detail/workaround.hpp"



























































#line 66 "../boost/detail/workaround.hpp"







#line 17 "../boost/scoped_ptr.hpp"

#line 1 "/usr/include/CC/memory"












 




#line 1 "/usr/include/CC/stl_algobase.h"
























 



 





#line 1 "/usr/include/CC/stl_config.h"
























 































































































#line 186 "/usr/include/CC/stl_config.h"

#line 215 "/usr/include/CC/stl_config.h"

#line 229 "/usr/include/CC/stl_config.h"

#line 238 "/usr/include/CC/stl_config.h"

#line 273 "/usr/include/CC/stl_config.h"

#line 288 "/usr/include/CC/stl_config.h"

































#line 327 "/usr/include/CC/stl_config.h"





#line 341 "/usr/include/CC/stl_config.h"

#line 349 "/usr/include/CC/stl_config.h"






#line 382 "/usr/include/CC/stl_config.h"


















#line 415 "/usr/include/CC/stl_config.h"

#line 424 "/usr/include/CC/stl_config.h"

#line 432 "/usr/include/CC/stl_config.h"






#line 37 "/usr/include/CC/stl_algobase.h"
#line 1 "/usr/include/CC/stl_relops.h"
























 



 




namespace std { namespace rel_ops {

template <class _Tp>
inline bool operator!=(const _Tp& __x, const _Tp& __y) {
  return !(__x == __y);
}

template <class _Tp>
inline bool operator>(const _Tp& __x, const _Tp& __y) {
  return __y < __x;
}

template <class _Tp>
inline bool operator<=(const _Tp& __x, const _Tp& __y) {
  return !(__y < __x);
}

template <class _Tp>
inline bool operator>=(const _Tp& __x, const _Tp& __y) {
  return !(__x < __y);
}

} }






#line 40 "/usr/include/CC/stl_algobase.h"
#line 1 "/usr/include/CC/stl_pair.h"
























 



 




namespace std {

template <class _T1, class _T2>
struct pair {
  typedef _T1 first_type;
  typedef _T2 second_type;

  _T1 first;
  _T2 second;
  pair() : first(_T1()), second(_T2()) {}
  pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) {}


  template <class _U1, class _U2>
  pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}

};

template <class _T1, class _T2>
inline bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ 
  return __x.first == __y.first && __x.second == __y.second; 
}

template <class _T1, class _T2>
inline bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{ 
  return __x.first < __y.first || 
         (!(__y.first < __x.first) && __x.second < __y.second); 
}



template <class _T1, class _T2>
inline bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x == __y);
}

template <class _T1, class _T2>
inline bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return __y < __x;
}

template <class _T1, class _T2>
inline bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__y < __x);
}

template <class _T1, class _T2>
inline bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x < __y);
}



template <class _T1, class _T2>
inline pair<_T1, _T2> make_pair(const _T1& __x, const _T2& __y)
{
  return pair<_T1, _T2>(__x, __y);
}

}






#line 43 "/usr/include/CC/stl_algobase.h"
#line 1 "/usr/include/CC/type_traits.h"












 






































 


struct __true_type {
};

struct __false_type {
};

template <class _Tp>
struct __type_traits { 
   typedef __true_type     this_dummy_member_must_be_first;
                   



 

   







 
 

   typedef __false_type    has_trivial_default_constructor;
   typedef __false_type    has_trivial_copy_constructor;
   typedef __false_type    has_trivial_assignment_operator;
   typedef __false_type    has_trivial_destructor;
   typedef __false_type    is_POD_type;
};









template< > struct __type_traits<bool> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};



template< > struct __type_traits<char> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<signed char> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<unsigned char> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};



template< > struct __type_traits<wchar_t> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};



template< > struct __type_traits<short> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<unsigned short> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<int> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<unsigned int> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<long> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<unsigned long> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};



template< > struct __type_traits<long long> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<unsigned long long> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};



template< > struct __type_traits<float> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<double> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

template< > struct __type_traits<long double> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};



template <class _Tp>
struct __type_traits<_Tp*> {
   typedef __true_type    has_trivial_default_constructor;
   typedef __true_type    has_trivial_copy_constructor;
   typedef __true_type    has_trivial_assignment_operator;
   typedef __true_type    has_trivial_destructor;
   typedef __true_type    is_POD_type;
};

#line 296 "/usr/include/CC/type_traits.h"





template <class _Tp> struct _Is_integer {
  typedef __false_type _Integral;
};



template< > struct _Is_integer<bool> {
  typedef __true_type _Integral;
};



template< > struct _Is_integer<char> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<signed char> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<unsigned char> {
  typedef __true_type _Integral;
};



template< > struct _Is_integer<wchar_t> {
  typedef __true_type _Integral;
};



template< > struct _Is_integer<short> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<unsigned short> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<int> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<unsigned int> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<long> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<unsigned long> {
  typedef __true_type _Integral;
};



template< > struct _Is_integer<long long> {
  typedef __true_type _Integral;
};

template< > struct _Is_integer<unsigned long long> {
  typedef __true_type _Integral;
};








#line 46 "/usr/include/CC/stl_algobase.h"


#line 1 "/usr/include/string.h"



#line 1 "/usr/include/internal/string_core.h"


#ident "$Revision: 1.1 $"
















 
 
 
 

 
 
 
 





 



extern "C" {
namespace std {

#line 47 "/usr/include/internal/string_core.h"
typedef unsigned long	size_t;









 

 

extern void *memcpy(void * , const void * , size_t);
extern void *memmove(void *, const void *, size_t);
extern char *strcpy(char * , const char * );
extern char *strncpy(char * , const char * , size_t);

 

extern char *strcat(char * , const char * );
extern char *strncat(char * , const char * , size_t);

 

extern void *memccpy(void *, const void *, int, size_t);
extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int strcoll(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern size_t strxfrm(char * , const char * , size_t);

 


extern void *memchr(const void *, int, size_t);
extern char *strchr(const char *, int);

extern size_t strcspn(const char *, const char *);
#pragma int_to_unsigned strcspn

extern char *strpbrk(const char *, const char *);
extern char *strrchr(const char *, int);

extern size_t strspn(const char *, const char *);
#pragma int_to_unsigned strspn

extern char *strstr(const char *, const char *);

extern char *strtok(char * , const char * );

 

extern void *memset(void *, int, size_t);
extern char *strerror(int);
extern size_t strlen(const char *);
#pragma int_to_unsigned strlen

}


extern int ffs(int);
 
extern int strcasecmp(const char *, const char *);
extern int strncasecmp(const char *, const char *,
		std:: size_t);

 
extern std:: size_t strlcat(char *, const char *,
		std:: size_t);
extern std:: size_t strlcpy(char *, const char *,
		std:: size_t);


#pragma optional strlcat
#pragma optional strlcpy





extern char *strdup(const char *);



extern char *strtok_r(char *, const char *, char **);



namespace std {


 




#pragma intrinsic (strcpy)  
#pragma intrinsic (strcmp)  
#pragma intrinsic (strlen)  


#pragma intrinsic (memcpy)
#pragma intrinsic (memmove)
#pragma intrinsic (memset)


#pragma intrinsic (memcmp)

}


}

#line 234 "/usr/include/internal/string_core.h"

#line 5 "/usr/include/string.h"

using std::size_t;

using std::memcpy;
using std::memmove;
using std::strcpy;
using std::strncpy;
using std::strcat;
using std::strncat;
using std::memccpy;
using std::memcmp;
using std::strcmp;
using std::strcoll;
using std::strncmp;
using std::strxfrm;
using std::memchr;
using std::strchr;
using std::strcspn;
using std::strpbrk;
using std::strrchr;
using std::strspn;
using std::strstr;
using std::strtok;
using std::memset;
using std::strerror;
using std::strlen;
#line 49 "/usr/include/CC/stl_algobase.h"
#line 1 "/usr/include/stdlib.h"



#line 1 "/usr/include/internal/stdlib_core.h"


#ident "$Revision: 1.1 $"
















 
 
 

 
 
 



 









 



 


#line 64 "/usr/include/internal/stdlib_core.h"






 




#line 87 "/usr/include/internal/stdlib_core.h"


extern "C" {

namespace std {

#line 102 "/usr/include/internal/stdlib_core.h"

#line 112 "/usr/include/internal/stdlib_core.h"

}

typedef	struct {
	 int	quot;
	 int	rem;
	} div_t;

typedef struct {
	 long	quot;
	 long	rem;
	} ldiv_t;



typedef struct {
	 long long	quot;
	 long long	rem;
	} lldiv_t;



#line 141 "/usr/include/internal/stdlib_core.h"
typedef long	ssize_t;





}
#line 1 "/usr/include/internal/locale_attr_core.h"










 







#ident "$Revision: 1.1 $"











 









 

extern "C" {

typedef struct {

    unsigned int	_class [ 257 ];
    signed short	_lower [ 257 ];
    signed short	_upper [ 257 ];

    char		_cswidth [ 7 ];
    char		_fill [ 1 ];

     

} __ctype_t;

 
typedef int	(*__isset_func_t)(int);

namespace std {
#line 68 "/usr/include/internal/locale_attr_core.h"
	typedef __int32_t wint_t;


}

 
typedef int	(*__iscodeset_func_t)(int, std:: wint_t);

 
typedef struct __attr {

    __ctype_t *		_ctype_tbl;	 

    struct _csinfo {			 
	unsigned char	_eucwidth[3];	 
	unsigned char	_scrwidth[3];	 
	unsigned char	_mb_cur_max;	 
    } _csinfo;

    struct _euc_func {			 
	int		_is_euc;	 
	__isset_func_t	_isset2;	 
	__isset_func_t	_isset3;	 
	__iscodeset_func_t _iscodeset;	 
    } _euc_func;

    struct _collate_res {		 
	unsigned char	_coll_as_cmp;	 
    } _collate_res;

    void *		_fill[15];	 
} __attr_t;



 
extern __attr_t __libc_attr;

}

#line 149 "/usr/include/internal/stdlib_core.h"
extern "C" {








 
namespace std {

 

extern double atof(const char *);

extern int atoi(const char *);
extern long int atol(const char *);

extern long long atoll(const char *);


extern double strtod(const char * , char ** );
#line 179 "/usr/include/internal/stdlib_core.h"
extern long double strtold(const char * , char ** );


extern long int strtol(const char * , char ** , int);

extern long long strtoll(const char * , char ** , int);

extern unsigned long int strtoul(const char * , char ** , int);


extern unsigned long long strtoull(const char * , char ** , int);



 

extern int rand(void);

extern void srand(unsigned int);

 

extern void *calloc(size_t, size_t);

extern void free(void *);

extern void *malloc(size_t);

extern void *realloc(void *, size_t);



#pragma intrinsic (calloc)
#pragma intrinsic (free)
#pragma intrinsic (malloc)
#pragma intrinsic (realloc)


 

extern void abort(void);

extern int atexit(void (*)(void));

extern void exit(int);


#pragma intrinsic (exit)






extern char *getenv(const char *);

extern int system(const char *);

 

extern void *bsearch(const void *, const void *, size_t, size_t,
	int (*)(const void *, const void *));

extern void qsort(void *, size_t, size_t,
	int (*)(const void *, const void *));

 




inline int abs(int x) {return x > 0 ? x : -x;}




extern long int labs(long);

extern long long llabs(long long);
#line 264 "/usr/include/internal/stdlib_core.h"
#pragma intrinsic (labs)

#pragma intrinsic (llabs)



extern div_t div(int, int);
extern ldiv_t ldiv(long, long);

extern lldiv_t lldiv(long long, long long);


 

extern int mblen(const char *, size_t);

extern int mbtowc(wchar_t * , const char * , size_t);

extern int wctomb(char *, wchar_t);

 

extern size_t mbstowcs(wchar_t * , const char * , size_t);

extern size_t wcstombs(char * , const wchar_t * , size_t);

}


	 



extern int	putenv(const char *);

extern double	drand48(void);
extern double	erand48(unsigned short [3]);
extern long	lrand48(void);
extern long	nrand48(unsigned short [3]);
extern long	mrand48(void);
extern long	jrand48(unsigned short [3]);
extern void	srand48(long);
extern void	lcong48(unsigned short int [7]);
extern void     setkey(const char *);
extern unsigned short * seed48(unsigned short int [3]);



	 
extern long a64l(const char *);
extern char *ecvt(double, int, int *, int *);
extern char *fcvt(double, int, int *, int *);
extern char *gcvt(double, int, char *);
extern int getsubopt(char **, char * const *, char **);
extern int grantpt(int);
extern char *initstate(unsigned int, char *, std:: size_t);
extern char *l64a(long);
extern char *mktemp(char *);
extern int mkstemp(char *);
extern char *ptsname(int);
extern long random(void);
extern char *realpath(const char *, char *);
extern char *setstate(const char *);
extern void srandom(unsigned);
extern int ttyslot(void);
extern int unlockpt(int);
extern void *valloc(std:: size_t);


#pragma intrinsic (valloc)




extern int rand_r(unsigned int *);



	 
}
#line 1 "../getopt.h"
 



































 




#line 1 "/usr/include/unistd.h"


#ident "$Revision: 1.1 $"
















 
 
 

 
 
 





 
#line 39 "/usr/include/unistd.h"







#line 52 "/usr/include/unistd.h"



 




 







 








 








#line 102 "/usr/include/unistd.h"

#line 110 "/usr/include/unistd.h"













 




 


































































 
#line 222 "/usr/include/unistd.h"
















#line 254 "/usr/include/unistd.h"




 
#line 268 "/usr/include/unistd.h"




 


 


#line 1 "/usr/include/sys/types.h"















 
 
 

 
 
 




#ident	"$Revision: 1.1 $"





 
typedef unsigned char   uchar_t;
typedef unsigned short  ushort_t;
typedef unsigned int    uint_t;
typedef unsigned long   ulong_t;

 
#line 1 "/usr/include/sys/pthread.h"




extern "C" {




 
typedef unsigned int 		pthread_t;		 


typedef struct { long __D[5]; } pthread_attr_t;		 
typedef struct { long __D[8]; } pthread_mutex_t;	 
typedef struct { long __D[2]; } pthread_mutexattr_t;	 
typedef struct { long __D[8]; } pthread_cond_t;		 
typedef struct { long __D[2]; } pthread_condattr_t;	 
typedef struct { long __D[16]; } pthread_rwlock_t;	 
typedef struct { long __D[4]; } pthread_rwlockattr_t;	 
typedef int			pthread_key_t;		 
typedef int			pthread_once_t;		 
typedef struct { long __D[2]; } pthread_barrierattr_t;	 
typedef struct { long __D[16]; } pthread_barrier_t;	 
typedef struct { long __D[4]; } pthread_spinlock_t;	 




}


#line 42 "/usr/include/sys/types.h"



typedef long blksize_t;
typedef long suseconds_t;






typedef	int	xtiscalar_t;
typedef	unsigned int	xtiuscalar_t;


typedef xtiscalar_t t_scalar_t;
typedef xtiuscalar_t t_uscalar_t;


 
typedef	char *		addr_t;		 
typedef	char *		caddr_t;	 



typedef	long		daddr_t;	 

typedef	long		pgno_t;		 
typedef	__uint32_t	pfn_t;		 
typedef	short		cnt_t;		 
typedef unsigned long	basictime_t;
typedef __int64_t	micro_t;



 
typedef __int32_t	pgcnt_t;	 

typedef enum { B_FALSE, B_TRUE } boolean_t;








 

#line 99 "/usr/include/sys/types.h"
typedef __int32_t		id_t;


 






typedef __uint32_t major_t;	 
typedef __uint32_t minor_t;	 












 
typedef	ushort_t o_mode_t;		 
typedef short	o_dev_t;		 
typedef	ushort_t o_uid_t;		 
typedef	o_uid_t	o_gid_t;		 
typedef	short	o_nlink_t;		 
typedef short	o_pid_t;		 
typedef __uint32_t o_ino_t;		 

#line 141 "/usr/include/sys/types.h"
typedef	__uint32_t	mode_t;		 
typedef	__uint32_t	dev_t;		 
typedef	__int32_t	uid_t;
typedef	__int32_t	gid_t;
typedef __uint32_t	nlink_t;	 
typedef __int32_t	pid_t;		 


typedef int tid_t;                       

typedef dev_t	vertex_hdl_t;		 




typedef	unsigned long	ino_t;		 

typedef __uint64_t	ino64_t;	 

#line 169 "/usr/include/sys/types.h"
typedef long		off_t;		 





typedef	__int64_t	off64_t;	 


typedef __scint_t	__scoff_t;	 

typedef __scoff_t	scoff_t;	 



	 
typedef	__int64_t	blkcnt64_t;
typedef	__uint64_t	fsblkcnt64_t;
typedef	__uint64_t	fsfilcnt64_t;







typedef	long		blkcnt_t;	 
typedef	ulong_t		fsblkcnt_t;	 
typedef	ulong_t		fsfilcnt_t;	 


typedef	long		swblk_t;
typedef	unsigned long	paddr_t;	 
typedef	unsigned long	iopaddr_t;	 
typedef	int		key_t;		 
typedef	unsigned char	use_t;		 
typedef	long		sysid_t;
typedef	short		index_t;

typedef signed short	nasid_t;         
typedef signed short	cnodeid_t;	 
typedef	signed char  	partid_t;	 
typedef signed short 	moduleid_t;	 
typedef signed short 	cmoduleid_t;	 
typedef	uchar_t		clusterid_t;	 

typedef unsigned int 	lock_t;		 
typedef	signed short	cpuid_t;	 
typedef	unsigned char	pri_t;		 
typedef __uint64_t	accum_t;	 
typedef __int64_t	prid_t;		 
typedef __int64_t	ash_t;		 
typedef short		cell_t;		 
typedef int		credid_t;	 
typedef __int64_t	jid_t;		 

typedef __int32_t	ncpus_t;
typedef	__uint64_t	id_type_t;

namespace std {

#line 239 "/usr/include/sys/types.h"

}
using std::size_t;

#line 252 "/usr/include/sys/types.h"

namespace std {

#line 261 "/usr/include/sys/types.h"
typedef	int		time_t;		 



#line 271 "/usr/include/sys/types.h"
typedef	int		clock_t;  



}
using std::time_t;
using std::clock_t;

#line 288 "/usr/include/sys/types.h"



typedef int             clockid_t;



typedef int		timer_t;







 
typedef	unsigned int	useconds_t;





 
typedef __scunsigned_t	bitnum_t;	 
typedef __scunsigned_t	bitlen_t;	 


typedef int processorid_t;		 
typedef int toid_t;			 
typedef	long *qaddr_t;		       
typedef __uint32_t inst_t;		 

 






typedef __uint64_t machreg_t;


 






typedef __uint64_t fpreg_t;





 




typedef signed char             int8_t;
typedef unsigned char           uint8_t;
typedef signed short            int16_t;
typedef unsigned short          uint16_t;
typedef signed int              int32_t;
typedef unsigned int            uint32_t;
typedef __int64_t 		int64_t;
typedef __uint64_t		uint64_t;
typedef __int64_t 		intmax_t;
typedef __uint64_t		uintmax_t;
typedef signed long int         intptr_t;
typedef unsigned long int       uintptr_t;





 
typedef	unsigned char	u_int8_t;
typedef	unsigned short	u_int16_t;
typedef	__uint32_t	u_int32_t;






 














 
typedef	long	hostid_t;




 








 
#line 1 "/usr/include/sys/bsd_types.h"















 




#ident	"$Revision: 1.1 $"





 
typedef	struct { int r[1]; } *	physadr;
typedef	unsigned char	unchar;
typedef	unsigned char	u_char;
typedef	unsigned short	ushort;
typedef	unsigned short	u_short;
typedef	unsigned int	uint;
typedef	unsigned int	u_int;
typedef	unsigned long	ulong;
typedef	unsigned long	u_long;
typedef	struct	_quad { long val[2]; } quad;






#line 1 "/usr/include/sys/select.h"















 
 
 
 

 
 
 
 




#ident	"$Revision: 1.1 $"


extern "C" {









 




 











typedef	int	fd_mask_t;
typedef	unsigned int	ufd_mask_t;






typedef struct fd_set {



	fd_mask_t	fds_bits[(((1024)+(((int)(sizeof(fd_mask_t) * 8))-1))/((int)(sizeof(fd_mask_t) * 8)))];
} fd_set;










namespace std {

#line 94 "/usr/include/sys/select.h"

}

using std::size_t;


#line 106 "/usr/include/sys/select.h"





 














typedef	int	fd_mask;





}
#line 45 "/usr/include/sys/bsd_types.h"

#line 407 "/usr/include/sys/types.h"



typedef __uint64_t k_sigset_t;	 
#line 419 "/usr/include/sys/types.h"

#line 537 "/usr/include/sys/types.h"


#line 279 "/usr/include/unistd.h"
#line 1 "/usr/include/sys/unistd.h"
 
 

 
 
 




 





 

#line 65 "/usr/include/sys/unistd.h"
 





 
#line 97 "/usr/include/sys/unistd.h"
 
 
#line 115 "/usr/include/sys/unistd.h"
 



 
#line 127 "/usr/include/sys/unistd.h"
 

 



					 

					 



					 





 
#line 152 "/usr/include/sys/unistd.h"



 








#line 191 "/usr/include/sys/unistd.h"

#line 280 "/usr/include/unistd.h"

extern "C" {



 
extern int access(const char *, int);
extern unsigned alarm(unsigned);
extern int chdir(const char *);
extern int chown(const char *, uid_t, gid_t);
extern int close(int);
extern char *ctermid(char *);
extern char *cuserid(char *);
extern int dup(int);
extern int dup2(int, int);
extern int execl(const char *, const char *, ...);
extern int execle(const char *, const char *, ...);
extern int execlp(const char *, const char *, ...);
extern int execv(const char *, char *const *);
extern int execve(const char *, char *const *, char *const *);
extern int execvp(const char *, char *const *);
extern void _exit(int);
extern pid_t fork(void);
extern long fpathconf(int, int);

extern char *getcwd(char *, size_t);     
extern gid_t getegid(void);
extern uid_t geteuid(void);
extern gid_t getgid(void);



extern int getgroups(int, gid_t *);

extern char *getlogin(void);



extern pid_t getpgrp(void);

extern pid_t getpid(void);
extern pid_t getppid(void);
extern uid_t getuid(void);
extern int isatty(int);

extern int link(const char *, const char *);
extern int linkfollow(const char *, const char *);
#line 338 "/usr/include/unistd.h"
extern off_t lseek(int, off_t, int);
extern long pathconf(const char *, int);
extern int pause(void);
extern int pipe(int *);
extern ssize_t read(int, void *, size_t);
extern int rmdir(const char *);
extern int setgid(gid_t);
extern int setpgid(pid_t, pid_t);
extern pid_t setsid(void);
extern int setuid(uid_t);
extern unsigned sleep(unsigned);
extern long sysconf(int);
extern pid_t tcgetpgrp(int);
extern int tcsetpgrp(int, pid_t);
extern char *ttyname(int);
extern int unlink(const char *);
extern ssize_t write(int, const void *, size_t);




 
extern int fdatasync(int);





 
extern int fsync(int);





 
extern int ftruncate(int, off_t);	





 
extern int getlogin_r(char *, size_t);
extern int ttyname_r(int, char *, size_t);
extern int pthread_atfork(void (*)(void), void (*)(void), void (*)(void));





 

}
#line 1 "../getopt.h"
 



































 

#line 393 "/usr/include/unistd.h"
extern "C" {
extern size_t   confstr(int, char *, size_t);





 
extern int chroot(const char *);
extern int nice(int);
extern char     *crypt(const char *, const char *);
extern void     encrypt(char *, int);
extern char     *getpass(const char *);
extern void     swab(const void *, void *, ssize_t);





 
extern int brk(void *);
extern int fchown(int, uid_t, gid_t);
extern int fchdir(int);
extern int getdtablesize(void);
extern long gethostid(void);
extern int gethostname(char *, size_t);
extern int getpagesize(void);
extern pid_t getpgid(pid_t);
extern pid_t getsid(pid_t);
extern char *getwd(char *);
extern int lchown(const char *, uid_t, gid_t);
extern int lockf(int, int, off_t);
extern int readlink(const char *, char *, size_t);
extern void *sbrk(ssize_t);



extern pid_t setpgrp(void);



extern int setregid(gid_t, gid_t);
#line 445 "/usr/include/unistd.h"

extern int setreuid(uid_t, uid_t);
extern int symlink(const char *, const char *);
extern void sync(void);
extern int truncate(const char *, off_t);
extern useconds_t ualarm(useconds_t, useconds_t);
extern int usleep(useconds_t);
#line 466 "/usr/include/unistd.h"
extern ssize_t pread(int, void *, size_t, off_t);
extern ssize_t pwrite(int, const void *, size_t, off_t);




 




 
struct timeval;
extern int select(int, fd_set *, fd_set *, fd_set *, struct timeval *);




 

}

#line 1 "/usr/include/sys/uio.h"
 
 
 

 
 
 
 



#ident	"@(#)uts-3b2:io/uio.h	1.2"
#ident	"$Revision: 1.1 $"


extern "C" {







 





typedef struct iovec {
        void *iov_base;
        size_t  iov_len;
} iovec_t;



extern ssize_t readv(int, const struct iovec *, int);
extern ssize_t writev(int, const struct iovec *, int);


#line 96 "/usr/include/sys/uio.h"


}
#line 489 "/usr/include/unistd.h"
#line 1 "/usr/include/utime.h"


#ident "$Revision: 1.1 $"
















 
 
 
 

 
 
 
 


#line 1 "/usr/include/sys/utime.h"
 
 
 

 
 
 
 




 



struct utimbuf {
	time_t actime;		 
	time_t modtime;		 
};

#line 32 "/usr/include/utime.h"


extern "C" {

extern int utime(const char *, const struct utimbuf *);

}
#line 490 "/usr/include/unistd.h"
#line 1 "/usr/include/re_comp.h"


#ident "$Revision: 1.1 $"
















 



extern "C" {

extern char *re_comp(const char *);
extern int re_exec(const char *);

}
#line 491 "/usr/include/unistd.h"

extern "C" {

extern int acct(const char *);
namespace std {
extern void exit(int);
}
extern char *gettxt(const char *, const char *);
extern int profil(unsigned short *, unsigned int, unsigned int, unsigned int);




 
extern long ptrace(int, pid_t, void *, long);




namespace std {
extern int rename(const char *, const char *);	 
}
extern int seteuid(uid_t);
extern int setegid(gid_t);
extern int stime(const time_t *);
extern off_t tell(int);



struct acct_spi;	 
extern int atfork_child(void (*func)(void));
extern int atfork_child_prepend(void (*func)(void));
extern int atfork_parent(void (*func)(int, int));
extern int atfork_pre(void (*func)(void));
extern int atsproc_child(void (*func)(void));
extern int atsproc_parent(void (*func)(int, int));
extern int atsproc_pre(void (*func)(unsigned int));
extern void bset(char *, bitnum_t);
extern void bclr(char *, bitnum_t);
extern int btst(char *, bitnum_t);
extern void bfset(char *, bitnum_t, bitlen_t);
extern void bfclr(char *, bitnum_t, bitlen_t);
extern bitlen_t bftstset(char *, bitnum_t, bitlen_t);
extern bitlen_t bftstclr(char *, bitnum_t, bitlen_t);
extern int BSDchown(const char *, uid_t, gid_t);
extern int BSDdup2(int, int);
extern int BSDfchown(int, uid_t, gid_t);
extern int BSDgetpgrp(int);
extern int BSDsetpgrp(int, int);
extern int BSDsetgroups(int, int *);
extern int BSDgetgroups(int, int *);
extern int _daemonize(int, int, int, int);
extern ash_t getash(void);
extern int getdtablehi(void);
extern int getdomainname(char *, int);
extern prid_t getprid(void);
extern char *_getpty(int *, int, mode_t, int);
extern int getspinfo(struct acct_spi *);
extern int mincore(caddr_t, size_t, char *);
extern int mpin(void *, size_t);
extern int munpin(void *, size_t);
extern int newarraysess(void);
extern pid_t pcreatel(const char *, const char *, ...);
extern pid_t pcreatelp(const char *, const char *, ...);
extern pid_t pcreatev(const char *, char *const *);
extern pid_t pcreateve(const char *, char *const *, char *const *);
extern pid_t pcreatevp(const char *, char *const *);

extern ssize_t pread64(int, void *, size_t, off64_t);
extern ssize_t pwrite64(int, const void *, size_t, off64_t);

extern int rexecl(cell_t, const char *, const char *, ...);
extern int rexecle(cell_t, const char *, const char *, ...);
extern int rexeclp(cell_t, const char *, const char *, ...);
extern int rexecv(cell_t, const char *, char *const *);
extern int rexecve(cell_t, const char *, char *const *, char *const *);
extern int rexecvp(cell_t, const char *, char *const *);
extern float _sqrt_s(float);
extern double _sqrt_d(double);
extern int setash(ash_t);
extern int setdomainname(const char *, int);



extern int setgroups(int, const gid_t *);

extern int sethostid(int);
extern int sethostname(const char *, int);
extern int setprid(prid_t);
extern int setrgid(gid_t);
extern int setruid(uid_t);
extern int setspinfo(struct acct_spi *);
extern int sgikopt(const char *, char *, int);
extern long sginap(long);
extern off64_t tell64(int);
extern int vhangup(void);




 
extern int fattach(int, const char *);
extern int fdetach(const char *);
extern int ioctl(int, int, ...);




	 
extern int ftruncate64(int, off64_t);
extern int lockf64(int, int, off64_t);
extern off64_t lseek64(int, off64_t, int);
extern int truncate64(const char *, off64_t);




}
#line 43 "../getopt.h"



 





struct option {
	 
	const char *name;
	


 
	int has_arg;
	 
	int *flag;
	 
	int val;
};


extern "C" {


int getopt_long(int, char * const *, const char *,
    const struct option *, int *);

 
extern int optreset;


};



 
#line 345 "/usr/include/internal/stdlib_core.h"
extern "C" {
extern int atcheckpoint(void (*)(void));
extern int atrestart(void (*)(void));
extern int dup2(int, int);
extern int getpw(int, char *);
extern char *getcwd(char *, std:: size_t);
extern char *getlogin(void);
extern char *getpass(const char *);
extern int isatty(int);
extern void l3tol(long *, const char *, int);
extern void ltol3(char *, const long *, int);
extern void *memalign(std:: size_t, std:: size_t);


#pragma intrinsic (memalign)
extern void swab(const void *, void *, ssize_t);
extern char *ttyname(int);


	 

extern long double atold(const char *);
extern char *qecvt(long double, int, int *, int *);
extern char *qfcvt(long double, int, int *, int *);
extern char *qgcvt(long double, int, char *);
extern char *ecvtl(long double, int, int *, int *);
extern char *fcvtl(long double, int, int *, int *);
extern char *gcvtl(long double, int, char *);










extern char *ecvt_r(double, int, int *, int *, char *);
extern char *fcvt_r(double, int, int *, int *, char *);

extern char *qecvt_r(long double, int, int *, int *, char *);
extern char *qfcvt_r(long double, int, int *, int *, char *);
extern char *ecvtl_r(long double, int, int *, int *, char *);
extern char *fcvtl_r(long double, int, int *, int *, char *);



}


#line 414 "/usr/include/internal/stdlib_core.h"

#line 5 "/usr/include/stdlib.h"

using std::size_t;
using std::atof;
using std::atoi;
using std::atol;
using std::strtod;
using std::strtol;
using std::strtoul;
using std::rand;
using std::srand;
using std::calloc;
using std::free;
using std::malloc;
using std::realloc;
using std::abort;
using std::atexit;
using std::exit;
using std::getenv;
using std::system;
using std::bsearch;
using std::qsort;
using std::abs;
using std::div;
using std::labs;
using std::ldiv;
using std::mbtowc;
using std::mblen;
using std::wctomb;
using std::mbstowcs;
using std::wcstombs;


#line 51 "/usr/include/CC/stl_algobase.h"
#line 1 "/usr/include/stddef.h"



#line 1 "/usr/include/internal/stddef_core.h"
















 
 
 
 

 
 
 
 


#ident "$Revision: 1.1 $"




namespace std {





typedef __int64_t 	ptrdiff_t;


#line 51 "/usr/include/internal/stddef_core.h"





#line 65 "/usr/include/internal/stddef_core.h"

}







#line 5 "/usr/include/stddef.h"

using std::ptrdiff_t;
using std::size_t;



#line 52 "/usr/include/CC/stl_algobase.h"
#line 1 "/usr/include/CC/new"


 




#line 1 "/usr/include/CC/exception"


 




 






 

 
namespace std {




  class exception {
  public:
    exception() throw();
    exception& operator=(const exception&) throw();
    virtual ~exception() throw();
    virtual const char* what() const throw();
  };

}   





 
namespace std {


  class bad_exception : public std::exception {
  public:
    bad_exception() throw();
    bad_exception(const bad_exception&) throw();
    bad_exception& operator=(const bad_exception&) throw();
    virtual ~bad_exception() throw();
    virtual const char* what() const throw();
  };

  typedef void (*terminate_handler)();
  extern terminate_handler set_terminate(terminate_handler);
  void terminate();

  typedef void (*unexpected_handler)();
  extern unexpected_handler set_unexpected(unexpected_handler);
  void unexpected();





 
  extern bool uncaught_exception();



}   





  






 
  typedef long (*_PFL)();
  
 
  extern _PFL set_thread_id_function(_PFL);


  















 
  typedef void (*_PFV)();
  extern _PFV set_abandon_exception_cleanup_function(_PFV);

     

#line 132 "/usr/include/CC/exception"








#line 12 "/usr/include/CC/new"

#line 20 "/usr/include/CC/new"



namespace std {
  class bad_alloc : public std::exception {
  public:
    bad_alloc() throw();
    bad_alloc(const bad_alloc&) throw();
    bad_alloc& operator=(const bad_alloc&) throw();
    virtual ~bad_alloc() throw();
    virtual const char* what() const throw();
  };

  typedef void (*new_handler)();
  new_handler set_new_handler(new_handler) throw();
  struct nothrow_t { };
  
  
  const nothrow_t nothrow = {};

}   








 
 void *operator new(size_t) throw(std::bad_alloc);



 


void *operator new(size_t, const std::nothrow_t&) throw();




 


inline void *operator new(size_t, void* __p) throw() { return __p; }







 
void *operator new[](size_t) throw(std::bad_alloc);



 


inline void *operator new[](size_t, void* __p) throw() { return __p; }







 


void *operator new[](size_t,
                     const std::nothrow_t&) throw();




 


void operator delete(void*) throw();
void operator delete[](void*) throw();
 










#line 54 "/usr/include/CC/stl_algobase.h"




#line 1 "/usr/include/CC/iosfwd"











  





















#line 1 "/usr/include/wchar.h"



#line 1 "/usr/include/stdio.h"



#line 1 "/usr/include/internal/stdio_core.h"


#ident "$Revision: 1.1 $"
















 
 
 

 
 
 





 




extern "C" {



namespace std {

#line 52 "/usr/include/internal/stdio_core.h"

#line 64 "/usr/include/internal/stdio_core.h"




typedef long		fpos_t;


}


 






#line 94 "/usr/include/internal/stdio_core.h"



typedef	long		fpos64_t;








 
namespace std {


typedef char *va_list;

}



























 

#line 148 "/usr/include/internal/stdio_core.h"





				 
#line 160 "/usr/include/internal/stdio_core.h"







#line 178 "/usr/include/internal/stdio_core.h"










#line 194 "/usr/include/internal/stdio_core.h"
















typedef struct	 








 
__file_s

{




	long		_cnt;	 

	unsigned char	*_ptr;	 
	unsigned char	*_base;	 

	unsigned char	_reserved;  
	unsigned char	_xflag;  
	unsigned short	_flag;	 
	unsigned int	_file;	 
#line 244 "/usr/include/internal/stdio_core.h"
} FILE;

extern FILE		__iob[100];	

extern FILE		*_lastbuf;
extern unsigned char 	*_bufendtab[];
extern unsigned char	 _sibuf[], _sobuf[];


namespace std {
extern int	remove(const char *);
extern int	rename(const char *, const char *);
extern FILE	*tmpfile(void);
extern char	*tmpnam(char *);
extern int	fclose(FILE *);
extern int	fflush(FILE *);
extern FILE	*fopen(const char * , const char * );
extern FILE	*freopen(const char * , const char * , FILE * );
extern void	setbuf(FILE * , char * );
extern int	setvbuf(FILE * , char * , int, size_t);
 
extern int	fprintf(FILE * , const char * , ...);
 
extern int	fscanf(FILE * , const char * , ...);
 
extern int	printf(const char * , ...);
 
extern int	scanf(const char * , ...);
}




extern int	vsnprintf(char * ,
			std:: size_t,
			const char * ,   char *);
#line 294 "/usr/include/internal/stdio_core.h"


 
extern int	snprintf(char * ,
			std:: size_t,
			const char * , ...);
#line 319 "/usr/include/internal/stdio_core.h"



 
namespace std {
extern int	sprintf(char * , const char * , ...);
 
extern int	sscanf(const char * , const char * , ...);
extern int	vfprintf(FILE * , const char * ,   char *);
extern int	vprintf(const char * ,   char *);
}

namespace std {
extern int	vsprintf(char * , const char * ,   char *);
}





namespace std {
#pragma intrinsic (printf)
#pragma intrinsic (fprintf)
#pragma intrinsic (sprintf)
#pragma intrinsic (scanf)
#pragma intrinsic (fscanf)
#pragma intrinsic (sscanf)
}


namespace std {
extern int	fgetc(FILE *);
extern char	*fgets(char * , int, FILE * ); 
extern int	fputc(int, FILE *);
extern int	fputs(const char * , FILE * );
extern int	getc(FILE *);
extern int	getchar(void);
extern char	*gets(char *);
extern int	putc(int, FILE *);
extern int	putchar(int);
extern int	puts(const char *);
extern int	ungetc(int, FILE *);
extern size_t	fread(void * , size_t, size_t, FILE * );
#pragma int_to_unsigned fread
extern size_t	fwrite(const void * , size_t, size_t, FILE * );
#pragma int_to_unsigned fwrite
extern int	fgetpos(FILE * , fpos_t * );
extern int	fseek(FILE *, long, int);
extern int	fsetpos(FILE *, const fpos_t *);
extern long	ftell(FILE *);
extern void	rewind(FILE *);
extern void	clearerr(FILE *);
extern int	feof(FILE *);
extern int	ferror(FILE *);
extern void	perror(const char *);


extern int	vfscanf(FILE * , const char * , va_list);
extern int	vscanf(const char * , va_list);
extern int	vsscanf(const char * , const char * , va_list);

#pragma optional vfscanf
#pragma optional vscanf
#pragma optional vsscanf



}

extern int	__filbuf(FILE *);	
extern int	__flsbuf(int, FILE *);	


	 
extern FILE    *fdopen(int, const char *);
extern int	fileno(FILE *);



	 
extern void	flockfile(FILE *);
extern int	ftrylockfile(FILE *);
extern void	funlockfile(FILE *);
extern int	getc_unlocked(FILE *);
extern int	putc_unlocked(int, FILE *);
extern int	getchar_unlocked(void);
extern int	putchar_unlocked(int);



extern FILE	*popen(const char *, const char *);
extern int	pclose(FILE *);


	 
}

extern "C" {
extern char	*ctermid(char *);
extern char	*cuserid(char *);
extern char	*tempnam(const char *, const char *);
extern int	getw(FILE *);
extern int	putw(int, FILE *);




	 
extern char	*mktemp(char *);
extern int	mkstemp(char *);
extern int	setbuffer(FILE *, char *, int);
extern int	setlinebuf(FILE *);
namespace std {
extern int	system(const char *);
}



	 
extern off_t	ftello(FILE *);
extern int	fseeko(FILE *, off_t, int);



	 
extern int	fgetpos64(FILE *, fpos64_t *);
extern FILE	*fopen64(const char *, const char *);
extern FILE	*freopen64(const char *, const char *, FILE *);
extern int	fseek64(FILE *, __int64_t, int);
extern int	fseeko64(FILE *, off64_t, int);
extern int	fsetpos64(FILE *, const fpos64_t *);
extern __int64_t ftell64(FILE *);
extern off64_t	ftello64(FILE *);
extern FILE	*tmpfile64(void);



extern int	__semputc(int, FILE *);
extern int	__semgetc(FILE *);
extern int	__us_rsthread_stdio;



extern char	*ctermid_r(char *);














 

 





 




 
#line 502 "/usr/include/internal/stdio_core.h"

 
#line 513 "/usr/include/internal/stdio_core.h"

#line 558 "/usr/include/internal/stdio_core.h"





}

#line 5 "/usr/include/stdio.h"

using std::fpos_t;
using std::size_t;
using std::clearerr;
using std::fclose;
using std::feof;
using std::ferror;
using std::fflush;
using std::fgetc;
using std::fgetpos;
using std::fgets;
using std::fopen;
using std::fprintf;
using std::fputc;
using std::fputs;
using std::fread;
using std::freopen;
using std::fscanf;
using std::fseek;
using std::fsetpos;
using std::ftell;
using std::fwrite;
using std::getc;
using std::getchar;
using std::gets;
using std::perror;
using std::printf;
using std::putc;
using std::putchar;
using std::puts;
using std::remove;
using std::rename;
using std::rewind;
using std::scanf;
using std::setbuf;
using std::setvbuf;
using std::sprintf;
using std::sscanf;
using std::tmpfile;
using std::tmpnam;
using std::ungetc;
using std::vfprintf;

using std::vfscanf;

using std::vprintf;

using std::vscanf;

using std::vsprintf;

using std::vsscanf;


#line 5 "/usr/include/wchar.h"
#line 1 "/usr/include/ctype.h"



#line 1 "/usr/include/internal/ctype_core.h"


#ident "$Revision: 1.1 $"
















 
 
 

 
 
 




 




#line 44 "/usr/include/internal/ctype_core.h"






#line 62 "/usr/include/internal/ctype_core.h"

extern "C" {

namespace std {
extern int isalnum(int);
extern int isalpha(int);
}
#line 75 "/usr/include/internal/ctype_core.h"
extern int __isblank(int);
namespace std {
extern int iscntrl(int);
extern int isdigit(int);
extern int isgraph(int);
extern int islower(int);
extern int isprint(int);
extern int ispunct(int);
extern int isspace(int);
extern int isupper(int);
extern int isxdigit(int);
extern int tolower(int);
extern int toupper(int);
}

 
extern int isascii(int);        
extern int toascii(int);        

extern int _tolower(int);
extern int _toupper(int);


}







#line 121 "/usr/include/internal/ctype_core.h"

#line 128 "/usr/include/internal/ctype_core.h"



#line 163 "/usr/include/internal/ctype_core.h"



 

#line 187 "/usr/include/internal/ctype_core.h"



#line 5 "/usr/include/ctype.h"

 

using std::isalnum;
using std::isalpha;
using std::iscntrl;
using std::isdigit;
using std::isgraph;
using std::islower;
using std::isprint;
using std::ispunct;
using std::isspace;
using std::isupper;
using std::isxdigit;
using std::tolower;
using std::toupper;



#line 6 "/usr/include/wchar.h"
#line 1 "/usr/include/time.h"



#line 1 "/usr/include/internal/time_core.h"


#ident "$Revision: 1.1 $"

















 
 
 

 
 
 



 



		
extern "C" {

namespace std {





#line 53 "/usr/include/internal/time_core.h"

#line 63 "/usr/include/internal/time_core.h"

#line 73 "/usr/include/internal/time_core.h"

}

}



#line 1 "/usr/include/sys/ptimers.h"















 


#ident "$Id: smart_ptr.hpp,v 1.1 2006/09/23 08:21:18 nihilus Exp $"




 
#line 1 "/usr/include/sys/timespec.h"















 


#ident	"$Revision: 1.1 $"



















 







 






typedef struct timespec {



	time_t  tv_sec;		 




	long    tv_nsec;

} timespec_t;

#line 26 "/usr/include/sys/ptimers.h"

typedef struct itimerspec {
	timespec_t it_interval;	 
	timespec_t it_value;	 
} itimerspec_t;


 

 




 


#line 61 "/usr/include/sys/ptimers.h"

#line 82 "/usr/include/internal/time_core.h"



#line 93 "/usr/include/internal/time_core.h"










 






extern "C" {



struct	tm {	 
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};



 
namespace std {

 

extern clock_t clock(void);			
extern double difftime(time_t, time_t);		
extern time_t mktime(struct tm *);		
extern time_t time(time_t *);			

 

extern char *asctime(const struct tm *);		
extern char *ctime (const time_t *);		
extern struct tm *gmtime(const time_t *);		
extern struct tm *localtime(const time_t *);	
extern size_t strftime(char * , size_t, const char * , const struct tm * );

 

extern uint64_t rdrtc(void);

#pragma optional rdrtc



}




 
extern void tzset(void);
extern char *tzname[2];

#line 169 "/usr/include/internal/time_core.h"

}




 

extern "C" {





struct sigevent;
extern int clock_settime(clockid_t, const timespec_t *);
extern int clock_gettime(clockid_t, timespec_t *);
extern int clock_getres(clockid_t, timespec_t *);
extern int nanosleep(const timespec_t *, timespec_t *);
extern int timer_create(clockid_t, struct sigevent *, timer_t *);
extern int timer_delete(timer_t);
extern int timer_settime(timer_t, int, const struct itimerspec *, struct itimerspec *);
extern int timer_gettime(timer_t, struct itimerspec *);
extern int timer_getoverrun(timer_t);
}


#pragma optional nanosleep




extern "C" {




 
extern time_t timezone;
extern int daylight;
extern char *strptime(const char *, const char *, struct tm *);





 
extern struct tm *getdate(const char *);
extern int getdate_err;



extern int cftime(char *, char *, const std:: time_t *);
extern int ascftime(char *, const char *, const struct tm *);
extern time_t altzone;





 
extern char *asctime_r(const struct tm *, char *);
extern char *ctime_r(const std:: time_t *, char *);
extern struct tm *gmtime_r(const std:: time_t *,
                           struct tm *);
extern struct tm *localtime_r(const std:: time_t *,
                              struct tm *);


}

#line 5 "/usr/include/time.h"

using std::size_t;
using std::clock_t;
using std::time_t;
using std::clock;
using std::difftime;
using std::mktime;
using std::time;
using std::asctime;
using std::ctime;
using std::gmtime;
using std::localtime;
using std::strftime;

#line 7 "/usr/include/wchar.h"
#line 1 "/usr/include/locale_attr.h"










 






using std::wint_t;

#line 8 "/usr/include/wchar.h"
#line 1 "/usr/include/wctype.h"
#ident "$Revision: 1.1 $"
 
 
 

 
 
 
 

 
 
 

 
 
 
 
 




#line 1 "/usr/include/wchar.h"
#line 25 "/usr/include/wctype.h"
#line 1 "/usr/include/internal/wctype_core.h"


#ident "$Revision: 1.1 $"
 
 
 

 
 
 
 

 
 
 

 
 
 
 
 





extern "C" {

namespace std {



 

#line 44 "/usr/include/internal/wctype_core.h"

#line 52 "/usr/include/internal/wctype_core.h"
	typedef __uint32_t	wctrans_t;




#line 63 "/usr/include/internal/wctype_core.h"
	typedef __uint32_t	wctype_t;







 

extern int	iswalnum(wint_t);
extern int	iswalpha(wint_t);
}



extern int	__iswblank(std:: wint_t);
namespace std {
extern int	iswcntrl(wint_t);
extern int	iswdigit(wint_t);
extern int	iswgraph(wint_t);
extern int	iswlower(wint_t);
extern int	iswprint(wint_t);
extern int	iswpunct(wint_t);
extern int	iswspace(wint_t);
extern int	iswupper(wint_t);
extern int	iswxdigit(wint_t);

extern int	iswctype(wint_t, wctype_t);
extern wctype_t	wctype(const char *);

 

extern wint_t	towlower(wint_t);
extern wint_t	towupper(wint_t);



extern wint_t	towctrans (wint_t, wctrans_t);
extern wctrans_t wctrans(const char *);

#pragma optional towctrans
#pragma optional wctrans




}

extern int __iswctype(std:: wint_t,
                      std:: wctype_t);
extern std:: wint_t
	   __trwctype(std:: wint_t,
                      std:: wctype_t);

#line 124 "/usr/include/internal/wctype_core.h"

 
 
 
#line 142 "/usr/include/internal/wctype_core.h"

#line 155 "/usr/include/internal/wctype_core.h"

#line 162 "/usr/include/internal/wctype_core.h"







extern int	iswascii(std:: wint_t);
extern int	isphonogram(std:: wint_t);
extern int	isideogram(std:: wint_t);
extern int	isenglish(std:: wint_t);
extern int	isnumber(std:: wint_t);
extern int	isspecial(std:: wint_t);



#line 213 "/usr/include/internal/wctype_core.h"

}



#line 26 "/usr/include/wctype.h"

using std::wint_t;
using std::wctrans_t;
using std::wctype_t;
using std::iswalnum;
using std::iswalpha;
using std::iswcntrl;
using std::iswdigit;
using std::iswgraph;
using std::iswlower;
using std::iswprint;
using std::iswpunct;
using std::iswspace;
using std::iswupper;
using std::iswxdigit;
using std::iswctype;
using std::wctype;
using std::towlower;
using std::towupper;
using std::towctrans;
using std::wctrans;



#line 10 "/usr/include/wchar.h"
#line 1 "/usr/include/internal/wchar_core.h"


#ident "$Revision: 1.1 $"
















 







 

extern "C" {

namespace std {






 

#line 50 "/usr/include/internal/wchar_core.h"

#line 60 "/usr/include/internal/wchar_core.h"

}

 

#line 71 "/usr/include/internal/wchar_core.h"
	typedef __uint32_t	wuchar_t;



namespace std {

#line 86 "/usr/include/internal/wchar_core.h"

#line 96 "/usr/include/internal/wchar_core.h"



	typedef char	mbstate_t;






#line 114 "/usr/include/internal/wchar_core.h"





 

extern int	iswalnum(wint_t);
extern int	iswalpha(wint_t);
}
#line 130 "/usr/include/internal/wchar_core.h"
extern int	__iswblank(std:: wint_t);
namespace std {
extern int	iswcntrl(wint_t);
extern int	iswdigit(wint_t);
extern int	iswgraph(wint_t);
extern int	iswlower(wint_t);
extern int	iswprint(wint_t);
extern int	iswpunct(wint_t);
extern int	iswspace(wint_t);
extern int	iswupper(wint_t);
extern int	iswxdigit(wint_t);

extern int	iswctype(wint_t, wctype_t);
extern wctype_t	wctype(const char *);

 

extern wint_t	towlower(wint_t);
extern wint_t	towupper(wint_t);

 


extern int fwprintf(FILE * , const wchar_t * , ...);
extern int fwscanf(FILE * , const wchar_t * , ...);
extern int swprintf(wchar_t * , size_t, const wchar_t * , ...);
extern int swscanf(const wchar_t * , const wchar_t * , ...);
extern int vfwprintf(FILE * , const wchar_t * , va_list);
#line 164 "/usr/include/internal/wchar_core.h"
extern int vswprintf(wchar_t * , size_t, const wchar_t * , va_list);
#line 171 "/usr/include/internal/wchar_core.h"
extern int vwprintf(const wchar_t * , va_list);
#line 178 "/usr/include/internal/wchar_core.h"
extern int wprintf(const wchar_t * , ...);
extern int wscanf(const wchar_t * , ...);

#pragma optional fwprintf
#pragma optional fwscanf
#pragma optional swprintf
#pragma optional swscanf
#pragma optional vfwprintf
#pragma optional vswprintf
#pragma optional vwprintf
#pragma optional wprintf
#pragma optional wscanf



 

extern wint_t	fgetwc(FILE *);
extern wchar_t	*fgetws(wchar_t * , int, FILE * );
extern wint_t	fputwc(wint_t, FILE *);
extern int	fputws(const wchar_t * , FILE * );
extern int      fwide(FILE *, int);
extern wint_t	getwc(FILE *);
extern wint_t	getwchar(void);
extern wint_t	putwc(wint_t, FILE *);
extern wint_t	putwchar(wint_t);
extern wint_t	ungetwc(wint_t, FILE *);

extern wchar_t	*getws(wchar_t *);
extern int	putws(wchar_t *);






 

 

extern double	wcstod(const wchar_t * , wchar_t ** );
#line 229 "/usr/include/internal/wchar_core.h"

extern long	wcstol(const wchar_t * , wchar_t ** , int);

extern long long wcstoll(const wchar_t * , wchar_t ** , int);

extern unsigned long	wcstoul(const wchar_t * , wchar_t ** , int);

extern unsigned long long wcstoull(const wchar_t * , wchar_t ** , int);


 

extern wchar_t	*wcscpy(wchar_t * , const wchar_t * );
extern wchar_t	*wcsncpy(wchar_t * , const wchar_t * , size_t);

extern wchar_t  *wmemcpy(wchar_t * , const wchar_t * , size_t);
extern wchar_t  *wmemmove(wchar_t *, const wchar_t *, size_t);

#pragma optional wmemcpy
#pragma optional wmemmove



 

extern wchar_t	*wcscat(wchar_t * , const wchar_t * );
extern wchar_t	*wcsncat(wchar_t * , const wchar_t * , size_t);

 

extern int	wcscmp(const wchar_t *, const wchar_t *);
extern int	wcscoll(const wchar_t *, const wchar_t *);
extern int	wcsncmp(const wchar_t *, const wchar_t *, size_t);
extern size_t	wcsxfrm(wchar_t * , const wchar_t * , size_t);

extern int      wmemcmp(const wchar_t *, const wchar_t *, size_t);

#pragma optional wmemcmp



 


extern wchar_t	*wcschr(const wchar_t *, wint_t);

extern size_t	wcscspn(const wchar_t *, const wchar_t *);
extern wchar_t	*wcspbrk(const wchar_t *, const wchar_t *);

extern wchar_t	*wcsrchr(const wchar_t *, wchar_t);

extern size_t	wcsspn(const wchar_t *, const wchar_t *);

extern wchar_t	*wcsstr(const wchar_t *, const wchar_t *);





extern wchar_t  *      wcstok(wchar_t *, const wchar_t *);
extern wchar_t  *_xpg4_wcstok(wchar_t *, const wchar_t *);
#pragma optional _xpg4_wcstok
#line 329 "/usr/include/internal/wchar_core.h"


extern wchar_t  *wmemchr(const wchar_t *, wchar_t, size_t);

#pragma optional wmemchr



 

extern size_t	wcslen(const wchar_t *);

extern wchar_t  *wmemset(wchar_t *, wchar_t, size_t);

#pragma optional wmemset



 




extern size_t          wcsftime(wchar_t *, std:: size_t, const char *, const struct tm *);
extern size_t    _xpg4_wcsftime(wchar_t *, std:: size_t, const char *, const struct tm *);
#pragma optional _xpg4_wcsftime
#line 393 "/usr/include/internal/wchar_core.h"

 

 


extern wint_t   btowc(int);
extern int      wctob(wint_t);

#pragma optional btowc
#pragma optional wctob



 


extern int      mbsinit(const mbstate_t *);

#pragma optional mbsinit



 


extern size_t   mbrlen(const char * , size_t, mbstate_t * );
extern size_t   mbrtowc(wchar_t * , const char * , size_t, mbstate_t * );
extern size_t   wcrtomb(char * , wchar_t, mbstate_t * );

#pragma optional mbrlen
#pragma optional mbrtowc
#pragma optional wcrtomb



 


extern size_t   mbsrtowcs(wchar_t * , const char ** , size_t, mbstate_t * );
extern size_t   wcsrtombs(char * , const wchar_t ** , size_t, mbstate_t * );

#pragma optional mbsrtowcs
#pragma optional wcsrtombs



 

extern int	wcwidth(wchar_t);
extern int	wcswidth(const wchar_t *, size_t);
extern wchar_t	*wcswcs(const wchar_t *, const wchar_t *);



#pragma optional fwide



}


extern wchar_t  *wcstok_r(wchar_t *, const wchar_t *, wchar_t **);


}

#line 519 "/usr/include/internal/wchar_core.h"

#line 12 "/usr/include/wchar.h"

using std::size_t;
using std::wint_t;
using std::mbstate_t;
using std::wctype_t;
using std::iswalnum;
using std::iswalpha;
using std::iswcntrl;
using std::iswdigit;
using std::iswgraph;
using std::iswlower;
using std::iswprint;
using std::iswpunct;
using std::iswspace;
using std::iswupper;
using std::iswxdigit;
using std::iswctype;
using std::wctype;
using std::towlower;
using std::towupper;

using std::fwprintf;
using std::fwscanf;
using std::swprintf;
using std::swscanf;
using std::vfwprintf;



using std::vswprintf;



using std::vwprintf;



using std::wprintf;
using std::wscanf;

using std::fgetwc;
using std::fgetws;
using std::fputwc;
using std::fputws;
using std::fwide;
using std::getwc;
using std::getwchar;
using std::putwc;
using std::putwchar;
using std::ungetwc;

using std::wcstod;





using std::wcstol;

using std::wcstoll;

using std::wcstoul;

using std::wcstoull;


using std::wcscpy;
using std::wcsncpy;
using std::wmemcpy;
using std::wmemmove;

using std::wcscat;
using std::wcsncat;

using std::wcscmp;
using std::wcscoll;
using std::wcsncmp;
using std::wcsxfrm;
using std::wmemcmp;

using std::wcschr;
using std::wcscspn;
using std::wcspbrk;
using std::wcsrchr;
using std::wcsspn;
using std::wcsstr;
using std::wcstok;
using std::wmemchr;
using std::wcslen;
using std::wmemset;

using std::wcsftime;


using std::btowc;
using std::wctob;



using std::mbsinit;



using std::mbrlen;
using std::mbrtowc;
using std::wcrtomb;



using std::mbsrtowcs;
using std::wcsrtombs;


using std::wcwidth;
using std::wcswidth;
using std::wcswcs;

#line 36 "/usr/include/CC/iosfwd"






namespace std {

template <class _CharT> class char_traits;
template<> class char_traits<char>;
template<> class char_traits<wchar_t>;
template <class _T> class allocator;

class ios_base;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ios;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_streambuf;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_istream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ostream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_iostream;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_stringbuf;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_istringstream;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_ostringstream;

template <class _CharT, class _Traits = char_traits<_CharT>,
          class _Allocator = allocator<_CharT> >
class basic_stringstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_filebuf;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ifstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_ofstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class basic_fstream;

template <class _CharT, class _Traits = char_traits<_CharT> >
class istreambuf_iterator;

template <class _CharT, class _Traits = char_traits<_CharT> >
class ostreambuf_iterator;

typedef basic_ios<char>    ios;
typedef basic_ios<wchar_t> wios;


typedef basic_streambuf<char> streambuf;
typedef basic_istream<char>   istream;
typedef basic_ostream<char>   ostream;
typedef basic_iostream<char>  iostream;

typedef basic_stringbuf<char>     stringbuf;
typedef basic_istringstream<char> istringstream;
typedef basic_ostringstream<char> ostringstream;
typedef basic_stringstream<char>  stringstream;

typedef basic_filebuf<char>  filebuf;
typedef basic_ifstream<char> ifstream;
typedef basic_ofstream<char> ofstream;
typedef basic_fstream<char>  fstream;


typedef basic_streambuf<wchar_t> wstreambuf;
typedef basic_istream<wchar_t>   wistream;
typedef basic_ostream<wchar_t>   wostream;
typedef basic_iostream<wchar_t>  wiostream;

typedef basic_stringbuf<wchar_t>     wstringbuf;
typedef basic_istringstream<wchar_t> wistringstream;
typedef basic_ostringstream<wchar_t> wostringstream;
typedef basic_stringstream<wchar_t>  wstringstream;

typedef basic_filebuf<wchar_t>  wfilebuf;
typedef basic_ifstream<wchar_t> wifstream;
typedef basic_ofstream<wchar_t> wofstream;
typedef basic_fstream<wchar_t>  wfstream;


typedef off64_t   streamoff;



typedef ptrdiff_t streamsize;

void __initialize_streams();
void __uninitialize_streams();




template <class _StateT> class fpos
{
public:                         
  fpos(streamoff __pos) : _M_pos(__pos), _M_st(0) {}
  fpos() : _M_pos(0), _M_st(0) {}

  operator streamoff() const { return _M_pos; }

  friend bool operator==(const fpos& __x, const fpos& __y)
    { return __x._M_pos == __y._M_pos; }
  friend bool operator!=(const fpos& __x, const fpos& __y)
    { return __x._M_pos != __y._M_pos; }

  fpos& operator+=(streamoff __off) {
    _M_pos += __off;
    return *this;
  }
  fpos& operator-=(streamoff __off) {
    _M_pos -= __off;
    return *this;
  }

  fpos operator+(streamoff __off) {
    fpos __tmp(*this);
    __tmp += __off;
    return __tmp;
  }
  fpos operator-(streamoff __off) {
    fpos __tmp(*this);
    __tmp -= __off;
    return __tmp;
  }

public:                         
  _StateT state() const { return _M_st; }
  void state(_StateT __st) { _M_st = __st; }
private:
  streamoff _M_pos;
  _StateT _M_st;
};

typedef fpos<mbstate_t> streampos;
typedef fpos<mbstate_t> wstreampos;


}


#line 1 "/usr/include/CC/functional"












 




#line 1 "/usr/include/CC/stl_function.h"
























 



 




namespace std {

template <class _Arg, class _Result>
struct unary_function {
  typedef _Arg argument_type;
  typedef _Result result_type;
};

template <class _Arg1, class _Arg2, class _Result>
struct binary_function {
  typedef _Arg1 first_argument_type;
  typedef _Arg2 second_argument_type;
  typedef _Result result_type;
};      

template <class _Tp>
struct plus : public binary_function<_Tp,_Tp,_Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x + __y; }
};

template <class _Tp>
struct minus : public binary_function<_Tp,_Tp,_Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x - __y; }
};

template <class _Tp>
struct multiplies : public binary_function<_Tp,_Tp,_Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x * __y; }
};

template <class _Tp>
struct divides : public binary_function<_Tp,_Tp,_Tp> {
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x / __y; }
};



template <class _Tp> inline _Tp identity_element(plus<_Tp>) {
  return _Tp(0);
}
template <class _Tp> inline _Tp identity_element(multiplies<_Tp>) {
  return _Tp(1);
}

template <class _Tp>
struct modulus : public binary_function<_Tp,_Tp,_Tp> 
{
  _Tp operator()(const _Tp& __x, const _Tp& __y) const { return __x % __y; }
};

template <class _Tp>
struct negate : public unary_function<_Tp,_Tp> 
{
  _Tp operator()(const _Tp& __x) const { return -__x; }
};

template <class _Tp>
struct equal_to : public binary_function<_Tp,_Tp,bool> 
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x == __y; }
};

template <class _Tp>
struct not_equal_to : public binary_function<_Tp,_Tp,bool> 
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x != __y; }
};

template <class _Tp>
struct greater : public binary_function<_Tp,_Tp,bool> 
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x > __y; }
};

template <class _Tp>
struct less : public binary_function<_Tp,_Tp,bool> 
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x < __y; }
};

template <class _Tp>
struct greater_equal : public binary_function<_Tp,_Tp,bool>
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x >= __y; }
};

template <class _Tp>
struct less_equal : public binary_function<_Tp,_Tp,bool> 
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x <= __y; }
};

template <class _Tp>
struct logical_and : public binary_function<_Tp,_Tp,bool>
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x && __y; }
};

template <class _Tp>
struct logical_or : public binary_function<_Tp,_Tp,bool>
{
  bool operator()(const _Tp& __x, const _Tp& __y) const { return __x || __y; }
};

template <class _Tp>
struct logical_not : public unary_function<_Tp,bool>
{
  bool operator()(const _Tp& __x) const { return !__x; }
};

template <class _Predicate>
class unary_negate
  : public unary_function<typename _Predicate::argument_type, bool> {
protected:
  _Predicate _M_pred;
public:
  explicit unary_negate(const _Predicate& __x) : _M_pred(__x) {}
  bool operator()(const typename _Predicate::argument_type& __x) const {
    return !_M_pred(__x);
  }
};

template <class _Predicate>
inline unary_negate<_Predicate> 
not1(const _Predicate& __pred)
{
  return unary_negate<_Predicate>(__pred);
}

template <class _Predicate> 
class binary_negate 
  : public binary_function<typename _Predicate::first_argument_type,
                           typename _Predicate::second_argument_type,
                           bool> {
protected:
  _Predicate _M_pred;
public:
  explicit binary_negate(const _Predicate& __x) : _M_pred(__x) {}
  bool operator()(const typename _Predicate::first_argument_type& __x, 
                  const typename _Predicate::second_argument_type& __y) const
  {
    return !_M_pred(__x, __y); 
  }
};

template <class _Predicate>
inline binary_negate<_Predicate> 
not2(const _Predicate& __pred)
{
  return binary_negate<_Predicate>(__pred);
}

template <class _Operation> 
class binder1st
  : public unary_function<typename _Operation::second_argument_type,
                          typename _Operation::result_type> {
protected:
  _Operation op;
  typename _Operation::first_argument_type value;
public:
  binder1st(const _Operation& __x,
            const typename _Operation::first_argument_type& __y)
      : op(__x), value(__y) {}
  typename _Operation::result_type
  operator()(const typename _Operation::second_argument_type& __x) const {
    return op(value, __x); 
  }
};

template <class _Operation, class _Tp>
inline binder1st<_Operation> 
bind1st(const _Operation& __fn, const _Tp& __x) 
{
  typedef typename _Operation::first_argument_type _Arg1_type;
  return binder1st<_Operation>(__fn, _Arg1_type(__x));
}

template <class _Operation> 
class binder2nd
  : public unary_function<typename _Operation::first_argument_type,
                          typename _Operation::result_type> {
protected:
  _Operation op;
  typename _Operation::second_argument_type value;
public:
  binder2nd(const _Operation& __x,
            const typename _Operation::second_argument_type& __y) 
      : op(__x), value(__y) {}
  typename _Operation::result_type
  operator()(const typename _Operation::first_argument_type& __x) const {
    return op(__x, value); 
  }
};

template <class _Operation, class _Tp>
inline binder2nd<_Operation> 
bind2nd(const _Operation& __fn, const _Tp& __x) 
{
  typedef typename _Operation::second_argument_type _Arg2_type;
  return binder2nd<_Operation>(__fn, _Arg2_type(__x));
}



template <class _Operation1, class _Operation2>
class unary_compose
  : public unary_function<typename _Operation2::argument_type,
                          typename _Operation1::result_type> 
{
protected:
  _Operation1 _M_fn1;
  _Operation2 _M_fn2;
public:
  unary_compose(const _Operation1& __x, const _Operation2& __y) 
    : _M_fn1(__x), _M_fn2(__y) {}
  typename _Operation1::result_type
  operator()(const typename _Operation2::argument_type& __x) const {
    return _M_fn1(_M_fn2(__x));
  }
};

template <class _Operation1, class _Operation2>
inline unary_compose<_Operation1,_Operation2> 
compose1(const _Operation1& __fn1, const _Operation2& __fn2)
{
  return unary_compose<_Operation1,_Operation2>(__fn1, __fn2);
}

template <class _Operation1, class _Operation2, class _Operation3>
class binary_compose
  : public unary_function<typename _Operation2::argument_type,
                          typename _Operation1::result_type> {
protected:
  _Operation1 _M_fn1;
  _Operation2 _M_fn2;
  _Operation3 _M_fn3;
public:
  binary_compose(const _Operation1& __x, const _Operation2& __y, 
                 const _Operation3& __z) 
    : _M_fn1(__x), _M_fn2(__y), _M_fn3(__z) { }
  typename _Operation1::result_type
  operator()(const typename _Operation2::argument_type& __x) const {
    return _M_fn1(_M_fn2(__x), _M_fn3(__x));
  }
};

template <class _Operation1, class _Operation2, class _Operation3>
inline binary_compose<_Operation1, _Operation2, _Operation3> 
compose2(const _Operation1& __fn1, const _Operation2& __fn2, 
         const _Operation3& __fn3)
{
  return binary_compose<_Operation1,_Operation2,_Operation3>
    (__fn1, __fn2, __fn3);
}

template <class _Arg, class _Result>
class pointer_to_unary_function : public unary_function<_Arg, _Result> {
protected:
  _Result (*_M_ptr)(_Arg);
public:
  pointer_to_unary_function() {}
  explicit pointer_to_unary_function(_Result (*__x)(_Arg)) : _M_ptr(__x) {}
  _Result operator()(_Arg __x) const { return _M_ptr(__x); }
};

template <class _Arg, class _Result>
inline pointer_to_unary_function<_Arg, _Result> ptr_fun(_Result (*__x)(_Arg))
{
  return pointer_to_unary_function<_Arg, _Result>(__x);
}

template <class _Arg1, class _Arg2, class _Result>
class pointer_to_binary_function : 
  public binary_function<_Arg1,_Arg2,_Result> {
protected:
    _Result (*_M_ptr)(_Arg1, _Arg2);
public:
    pointer_to_binary_function() {}
    explicit pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2)) 
      : _M_ptr(__x) {}
    _Result operator()(_Arg1 __x, _Arg2 __y) const {
      return _M_ptr(__x, __y);
    }
};

template <class _Arg1, class _Arg2, class _Result>
inline pointer_to_binary_function<_Arg1,_Arg2,_Result> 
ptr_fun(_Result (*__x)(_Arg1, _Arg2)) {
  return pointer_to_binary_function<_Arg1,_Arg2,_Result>(__x);
}


template <class _Tp>
struct _Identity : public unary_function<_Tp,_Tp> {
  const _Tp& operator()(const _Tp& __x) const { return __x; }
};

template <class _Tp> struct identity : public _Identity<_Tp> {};


template <class _Pair>
struct _Select1st : public unary_function<_Pair, typename _Pair::first_type> {
  const typename _Pair::first_type& operator()(const _Pair& __x) const {
    return __x.first;
  }
};

template <class _Pair>
struct _Select2nd : public unary_function<_Pair, typename _Pair::second_type>
{
  const typename _Pair::second_type& operator()(const _Pair& __x) const {
    return __x.second;
  }
};

template <class _Pair> struct select1st : public _Select1st<_Pair> {};
template <class _Pair> struct select2nd : public _Select2nd<_Pair> {};


template <class _Arg1, class _Arg2>
struct _Project1st : public binary_function<_Arg1, _Arg2, _Arg1> {
  _Arg1 operator()(const _Arg1& __x, const _Arg2&) const { return __x; }
};

template <class _Arg1, class _Arg2>
struct _Project2nd : public binary_function<_Arg1, _Arg2, _Arg2> {
  _Arg2 operator()(const _Arg1&, const _Arg2& __y) const { return __y; }
};

template <class _Arg1, class _Arg2> 
struct project1st : public _Project1st<_Arg1, _Arg2> {};

template <class _Arg1, class _Arg2>
struct project2nd : public _Project2nd<_Arg1, _Arg2> {};





template <class _Result>
struct _Constant_void_fun {
  typedef _Result result_type;
  result_type _M_val;

  _Constant_void_fun(const result_type& __v) : _M_val(__v) {}
  const result_type& operator()() const { return _M_val; }
};  

template <class _Result, class _Argument>
struct _Constant_unary_fun {
  typedef _Argument argument_type;
  typedef  _Result  result_type;
  result_type _M_val;

  _Constant_unary_fun(const result_type& __v) : _M_val(__v) {}
  const result_type& operator()(const _Argument&) const { return _M_val; }
};

template <class _Result, class _Arg1, class _Arg2>
struct _Constant_binary_fun {
  typedef  _Arg1   first_argument_type;
  typedef  _Arg2   second_argument_type;
  typedef  _Result result_type;
  _Result _M_val;

  _Constant_binary_fun(const _Result& __v) : _M_val(__v) {}
  const result_type& operator()(const _Arg1&, const _Arg2&) const {
    return _M_val;
  }
};

template <class _Result>
struct constant_void_fun : public _Constant_void_fun<_Result> {
  constant_void_fun(const _Result& __v) : _Constant_void_fun<_Result>(__v) {}
};  


template <class _Result,
          class _Argument = _Result>
struct constant_unary_fun : public _Constant_unary_fun<_Result, _Argument>
{
  constant_unary_fun(const _Result& __v)
    : _Constant_unary_fun<_Result, _Argument>(__v) {}
};


template <class _Result,
          class _Arg1 = _Result,
          class _Arg2 = _Arg1>
struct constant_binary_fun
  : public _Constant_binary_fun<_Result, _Arg1, _Arg2>
{
  constant_binary_fun(const _Result& __v)
    : _Constant_binary_fun<_Result, _Arg1, _Arg2>(__v) {}
};

template <class _Result>
inline constant_void_fun<_Result> constant0(const _Result& __val)
{
  return constant_void_fun<_Result>(__val);
}

template <class _Result>
inline constant_unary_fun<_Result,_Result> constant1(const _Result& __val)
{
  return constant_unary_fun<_Result,_Result>(__val);
}

template <class _Result>
inline constant_binary_fun<_Result,_Result,_Result> 
constant2(const _Result& __val)
{
  return constant_binary_fun<_Result,_Result,_Result>(__val);
}



class subtractive_rng : public unary_function<unsigned int, unsigned int> {
private:
  unsigned int _M_table[55];
  size_t _M_index1;
  size_t _M_index2;
public:
  unsigned int operator()(unsigned int __limit) {
    _M_index1 = (_M_index1 + 1) % 55;
    _M_index2 = (_M_index2 + 1) % 55;
    _M_table[_M_index1] = _M_table[_M_index1] - _M_table[_M_index2];
    return _M_table[_M_index1] % __limit;
  }

  void _M_initialize(unsigned int __seed)
  {
    unsigned int __k = 1;
    _M_table[54] = __seed;
    size_t __i;
    for (__i = 0; __i < 54; __i++) {
        size_t __ii = (21 * (__i + 1) % 55) - 1;
        _M_table[__ii] = __k;
        __k = __seed - __k;
        __seed = _M_table[__ii];
    }
    for (int __loop = 0; __loop < 4; __loop++) {
        for (__i = 0; __i < 55; __i++)
            _M_table[__i] = _M_table[__i] - _M_table[(1 + __i + 30) % 55];
    }
    _M_index1 = 0;
    _M_index2 = 31;
  }

  subtractive_rng(unsigned int __seed) { _M_initialize(__seed); }
  subtractive_rng() { _M_initialize(161803398u); }
};

























template <class _Ret, class _Tp>
class mem_fun_t : public unary_function<_Tp*,_Ret> {
public:
  explicit mem_fun_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}
  _Ret operator()(_Tp* __p) const { return (__p->*_M_f)(); }
private:
  _Ret (_Tp::*_M_f)();
};

template <class _Ret, class _Tp>
class const_mem_fun_t : public unary_function<const _Tp*,_Ret> {
public:
  explicit const_mem_fun_t(_Ret (_Tp::*__pf)() const) : _M_f(__pf) {}
  _Ret operator()(const _Tp* __p) const { return (__p->*_M_f)(); }
private:
  _Ret (_Tp::*_M_f)() const;
};


template <class _Ret, class _Tp>
class mem_fun_ref_t : public unary_function<_Tp,_Ret> {
public:
  explicit mem_fun_ref_t(_Ret (_Tp::*__pf)()) : _M_f(__pf) {}
  _Ret operator()(_Tp& __r) const { return (__r.*_M_f)(); }
private:
  _Ret (_Tp::*_M_f)();
};

template <class _Ret, class _Tp>
class const_mem_fun_ref_t : public unary_function<_Tp,_Ret> {
public:
  explicit const_mem_fun_ref_t(_Ret (_Tp::*__pf)() const) : _M_f(__pf) {}
  _Ret operator()(const _Tp& __r) const { return (__r.*_M_f)(); }
private:
  _Ret (_Tp::*_M_f)() const;
};

template <class _Ret, class _Tp, class _Arg>
class mem_fun1_t : public binary_function<_Tp*,_Arg,_Ret> {
public:
  explicit mem_fun1_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}
  _Ret operator()(_Tp* __p, _Arg __x) const { return (__p->*_M_f)(__x); }
private:
  _Ret (_Tp::*_M_f)(_Arg);
};

template <class _Ret, class _Tp, class _Arg>
class const_mem_fun1_t : public binary_function<const _Tp*,_Arg,_Ret> {
public:
  explicit const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}
  _Ret operator()(const _Tp* __p, _Arg __x) const
    { return (__p->*_M_f)(__x); }
private:
  _Ret (_Tp::*_M_f)(_Arg) const;
};

template <class _Ret, class _Tp, class _Arg>
class mem_fun1_ref_t : public binary_function<_Tp,_Arg,_Ret> {
public:
  explicit mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}
  _Ret operator()(_Tp& __r, _Arg __x) const { return (__r.*_M_f)(__x); }
private:
  _Ret (_Tp::*_M_f)(_Arg);
};

template <class _Ret, class _Tp, class _Arg>
class const_mem_fun1_ref_t : public binary_function<_Tp,_Arg,_Ret> {
public:
  explicit const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}
  _Ret operator()(const _Tp& __r, _Arg __x) const { return (__r.*_M_f)(__x); }
private:
  _Ret (_Tp::*_M_f)(_Arg) const;
};



template <class _Tp>
class mem_fun_t<void, _Tp> : public unary_function<_Tp*,void> {
public:
  explicit mem_fun_t(void (_Tp::*__pf)()) : _M_f(__pf) {}
  void operator()(_Tp* __p) const { (__p->*_M_f)(); }
private:
  void (_Tp::*_M_f)();
};

template <class _Tp>
class const_mem_fun_t<void, _Tp> : public unary_function<const _Tp*,void> {
public:
  explicit const_mem_fun_t(void (_Tp::*__pf)() const) : _M_f(__pf) {}
  void operator()(const _Tp* __p) const { (__p->*_M_f)(); }
private:
  void (_Tp::*_M_f)() const;
};

template <class _Tp>
class mem_fun_ref_t<void, _Tp> : public unary_function<_Tp,void> {
public:
  explicit mem_fun_ref_t(void (_Tp::*__pf)()) : _M_f(__pf) {}
  void operator()(_Tp& __r) const { (__r.*_M_f)(); }
private:
  void (_Tp::*_M_f)();
};

template <class _Tp>
class const_mem_fun_ref_t<void, _Tp> : public unary_function<_Tp,void> {
public:
  explicit const_mem_fun_ref_t(void (_Tp::*__pf)() const) : _M_f(__pf) {}
  void operator()(const _Tp& __r) const { (__r.*_M_f)(); }
private:
  void (_Tp::*_M_f)() const;
};

template <class _Tp, class _Arg>
class mem_fun1_t<void, _Tp, _Arg> : public binary_function<_Tp*,_Arg,void> {
public:
  explicit mem_fun1_t(void (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}
  void operator()(_Tp* __p, _Arg __x) const { (__p->*_M_f)(__x); }
private:
  void (_Tp::*_M_f)(_Arg);
};

template <class _Tp, class _Arg>
class const_mem_fun1_t<void, _Tp, _Arg> 
  : public binary_function<const _Tp*,_Arg,void> {
public:
  explicit const_mem_fun1_t(void (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}
  void operator()(const _Tp* __p, _Arg __x) const { (__p->*_M_f)(__x); }
private:
  void (_Tp::*_M_f)(_Arg) const;
};

template <class _Tp, class _Arg>
class mem_fun1_ref_t<void, _Tp, _Arg>
  : public binary_function<_Tp,_Arg,void> {
public:
  explicit mem_fun1_ref_t(void (_Tp::*__pf)(_Arg)) : _M_f(__pf) {}
  void operator()(_Tp& __r, _Arg __x) const { (__r.*_M_f)(__x); }
private:
  void (_Tp::*_M_f)(_Arg);
};

template <class _Tp, class _Arg>
class const_mem_fun1_ref_t<void, _Tp, _Arg>
  : public binary_function<_Tp,_Arg,void> {
public:
  explicit const_mem_fun1_ref_t(void (_Tp::*__pf)(_Arg) const) : _M_f(__pf) {}
  void operator()(const _Tp& __r, _Arg __x) const { (__r.*_M_f)(__x); }
private:
  void (_Tp::*_M_f)(_Arg) const;
};








template <class _Ret, class _Tp>
inline mem_fun_t<_Ret,_Tp> mem_fun(_Ret (_Tp::*__f)())
  { return mem_fun_t<_Ret,_Tp>(__f); }

template <class _Ret, class _Tp>
inline const_mem_fun_t<_Ret,_Tp> mem_fun(_Ret (_Tp::*__f)() const)
  { return const_mem_fun_t<_Ret,_Tp>(__f); }

template <class _Ret, class _Tp>
inline mem_fun_ref_t<_Ret,_Tp> mem_fun_ref(_Ret (_Tp::*__f)()) 
  { return mem_fun_ref_t<_Ret,_Tp>(__f); }

template <class _Ret, class _Tp>
inline const_mem_fun_ref_t<_Ret,_Tp> mem_fun_ref(_Ret (_Tp::*__f)() const)
  { return const_mem_fun_ref_t<_Ret,_Tp>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline mem_fun1_t<_Ret,_Tp,_Arg> mem_fun(_Ret (_Tp::*__f)(_Arg))
  { return mem_fun1_t<_Ret,_Tp,_Arg>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline const_mem_fun1_t<_Ret,_Tp,_Arg> mem_fun(_Ret (_Tp::*__f)(_Arg) const)
  { return const_mem_fun1_t<_Ret,_Tp,_Arg>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline mem_fun1_ref_t<_Ret,_Tp,_Arg> mem_fun_ref(_Ret (_Tp::*__f)(_Arg))
  { return mem_fun1_ref_t<_Ret,_Tp,_Arg>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline const_mem_fun1_ref_t<_Ret,_Tp,_Arg>
mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const)
  { return const_mem_fun1_ref_t<_Ret,_Tp,_Arg>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline mem_fun1_t<_Ret,_Tp,_Arg> mem_fun1(_Ret (_Tp::*__f)(_Arg))
  { return mem_fun1_t<_Ret,_Tp,_Arg>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline const_mem_fun1_t<_Ret,_Tp,_Arg> mem_fun1(_Ret (_Tp::*__f)(_Arg) const)
  { return const_mem_fun1_t<_Ret,_Tp,_Arg>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline mem_fun1_ref_t<_Ret,_Tp,_Arg> mem_fun1_ref(_Ret (_Tp::*__f)(_Arg))
  { return mem_fun1_ref_t<_Ret,_Tp,_Arg>(__f); }

template <class _Ret, class _Tp, class _Arg>
inline const_mem_fun1_ref_t<_Ret,_Tp,_Arg>
mem_fun1_ref(_Ret (_Tp::*__f)(_Arg) const)
  { return const_mem_fun1_ref_t<_Ret,_Tp,_Arg>(__f); }

}






#line 21 "/usr/include/CC/functional"






#line 198 "/usr/include/CC/iosfwd"
#line 1 "/usr/include/CC/char_traits.h"











  











namespace std {



template <class _CharT, class _IntT> struct __char_traits_base {
  typedef _CharT char_type;
  typedef _IntT int_type;

  typedef streamoff off_type;
  typedef streampos pos_type;
  typedef mbstate_t state_type;


  static void assign(char_type& __c1, const char_type& __c2) { __c1 = __c2; }
  static bool eq(const _CharT& __c1, const _CharT& __c2) 
    { return __c1 == __c2; }
  static bool lt(const _CharT& __c1, const _CharT& __c2) 
    { return __c1 < __c2; }

  static int compare(const _CharT* __s1, const _CharT* __s2, size_t __n) {
    for (size_t __i = 0; __i < __n; ++__i)
      if (!eq(__s1[__i], __s2[__i]))
        return __s1[__i] < __s2[__i] ? -1 : 1;
    return 0;
  }

  static size_t length(const _CharT* __s) {
    const _CharT __nullchar = _CharT();
    size_t __i;
    for (__i = 0; !eq(__s[__i], __nullchar); ++__i)
      {}
    return __i;
  }

  static const _CharT* find(const _CharT* __s, size_t __n, const _CharT& __c)
  {
    for ( ; __n > 0 ; ++__s, --__n)
      if (eq(*__s, __c))
        return __s;
    return 0;
  }

  static _CharT* move(_CharT* __s1, const _CharT* __s2, size_t __n) {
    memmove(__s1, __s2, __n * sizeof(_CharT));
    return __s1;
  }
    
  static _CharT* copy(_CharT* __s1, const _CharT* __s2, size_t __n) {
    memcpy(__s1, __s2, __n * sizeof(_CharT));
    return __s1;
  } 

  static _CharT* assign(_CharT* __s, size_t __n, _CharT __c) {
    for (size_t __i = 0; __i < __n; ++__i)
      __s[__i] = __c;
    return __s;
  }

  static int_type not_eof(const int_type& __c) {
    return !eq_int_type(__c, eof()) ? __c : 0;
  }

  static char_type to_char_type(const int_type& __c) {
    return static_cast<char_type>(__c);
  }

  static int_type to_int_type(const char_type& __c) {
    return static_cast<int_type>(__c);
  }

  static bool eq_int_type(const int_type& __c1, const int_type& __c2) {
    return __c1 == __c2;
  }

  static int_type eof() {
    return static_cast<int_type>(-1);
  }
};






template <class _CharT> struct char_traits
  : public __char_traits_base<_CharT, _CharT>
{};



template< > struct char_traits<char> 
  : public __char_traits_base<char, int>
{
  static int compare(const char* __s1, const char* __s2, size_t __n) 
    { return memcmp(__s1, __s2, __n); }
  
  static size_t length(const char* __s) { return strlen(__s); }

  static void assign(char& __c1, const char& __c2) { __c1 = __c2; }

  static char* assign(char* __s, size_t __n, char __c)
    { memset(__s, __c, __n); return __s; }
};



template< > struct char_traits<wchar_t>
  : public __char_traits_base<wchar_t, wint_t>
{};



template <class _Traits>
struct _Eq_traits
  : public binary_function<typename _Traits::char_type,
                           typename _Traits::char_type,
                           bool>
{
  bool operator()(const typename _Traits::char_type& __x,
                  const typename _Traits::char_type& __y) const
    { return _Traits::eq(__x, __y); }
};

template <class _Traits>
struct _Eq_int_traits
  : public binary_function<typename _Traits::char_type,
                           typename _Traits::int_type,
                           bool>
{
  bool operator()(const typename _Traits::char_type& __x,
                  const typename _Traits::int_type& __y) const
    { return _Traits::eq_int_type(_Traits::to_int_type(__x), __y); }
};

template <class _Traits>
struct _Lt_traits
  : public binary_function<typename _Traits::char_type,
                           typename _Traits::char_type,
                           bool>
{
  bool operator()(const typename _Traits::char_type& __x,
                  const typename _Traits::char_type& __y) const
    { return _Traits::lt(__x, __y); }
};

}







#line 201 "/usr/include/CC/iosfwd"







#line 60 "/usr/include/CC/stl_algobase.h"




#line 1 "/usr/include/CC/stl_iterator_base.h"
























 



 








namespace std {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};






template <class _Tp, class _Distance> struct input_iterator {
  typedef input_iterator_tag iterator_category;
  typedef _Tp                value_type;
  typedef _Distance          difference_type;
  typedef _Tp*               pointer;
  typedef _Tp&               reference;
};

struct output_iterator {
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;
};

template <class _Tp, class _Distance> struct forward_iterator {
  typedef forward_iterator_tag iterator_category;
  typedef _Tp                  value_type;
  typedef _Distance            difference_type;
  typedef _Tp*                 pointer;
  typedef _Tp&                 reference;
};


template <class _Tp, class _Distance> struct bidirectional_iterator {
  typedef bidirectional_iterator_tag iterator_category;
  typedef _Tp                        value_type;
  typedef _Distance                  difference_type;
  typedef _Tp*                       pointer;
  typedef _Tp&                       reference;
};

template <class _Tp, class _Distance> struct random_access_iterator {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                        value_type;
  typedef _Distance                  difference_type;
  typedef _Tp*                       pointer;
  typedef _Tp&                       reference;
};


template <class _Category, class _Tp, class _Distance = ptrdiff_t,
          class _Pointer = _Tp*, class _Reference = _Tp&>
struct iterator {
  typedef _Category  iterator_category;
  typedef _Tp        value_type;
  typedef _Distance  difference_type;
  typedef _Pointer   pointer;
  typedef _Reference reference;
};




template <class _Iterator>
struct iterator_traits {
  typedef typename _Iterator::iterator_category iterator_category;
  typedef typename _Iterator::value_type        value_type;
  typedef typename _Iterator::difference_type   difference_type;
  typedef typename _Iterator::pointer           pointer;
  typedef typename _Iterator::reference         reference;
};

template <class _Tp>
struct iterator_traits<_Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef _Tp*                        pointer;
  typedef _Tp&                        reference;
};

template <class _Tp>
struct iterator_traits<const _Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp                         value_type;
  typedef ptrdiff_t                   difference_type;
  typedef const _Tp*                  pointer;
  typedef const _Tp&                  reference;
};








template <class _Iter>
inline typename iterator_traits<_Iter>::iterator_category
__iterator_category(const _Iter&)
{
  typedef typename iterator_traits<_Iter>::iterator_category _Category;
  return _Category();
}

template <class _Iter>
inline typename iterator_traits<_Iter>::difference_type*
__distance_type(const _Iter&)
{
  return static_cast<typename iterator_traits<_Iter>::difference_type*>(0);
}

template <class _Iter>
inline typename iterator_traits<_Iter>::value_type*
__value_type(const _Iter&)
{
  return static_cast<typename iterator_traits<_Iter>::value_type*>(0);
}

template <class _Iter>
inline typename iterator_traits<_Iter>::iterator_category
iterator_category(const _Iter& __i) { return __iterator_category(__i); }


template <class _Iter>
inline typename iterator_traits<_Iter>::difference_type*
distance_type(const _Iter& __i) { return __distance_type(__i); }

template <class _Iter>
inline typename iterator_traits<_Iter>::value_type*
value_type(const _Iter& __i) { return __value_type(__i); }





#line 264 "/usr/include/CC/stl_iterator_base.h"

template <class _InputIterator, class _Distance>
inline void __distance(_InputIterator __first, _InputIterator __last,
                       _Distance& __n, input_iterator_tag)
{
  while (__first != __last) { ++__first; ++__n; }
}

template <class _RandomAccessIterator, class _Distance>
inline void __distance(_RandomAccessIterator __first, 
                       _RandomAccessIterator __last, 
                       _Distance& __n, random_access_iterator_tag)
{
  __n += __last - __first;
}

template <class _InputIterator, class _Distance>
inline void distance(_InputIterator __first, 
                     _InputIterator __last, _Distance& __n)
{
  __distance(__first, __last, __n, iterator_category(__first));
}



template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
__distance(_InputIterator __first, _InputIterator __last, input_iterator_tag)
{
  typename iterator_traits<_InputIterator>::difference_type __n = 0;
  while (__first != __last) {
    ++__first; ++__n;
  }
  return __n;
}

template <class _RandomAccessIterator>
inline typename iterator_traits<_RandomAccessIterator>::difference_type
__distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
           random_access_iterator_tag) {
  return __last - __first;
}

template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
distance(_InputIterator __first, _InputIterator __last) {
  typedef typename iterator_traits<_InputIterator>::iterator_category 
    _Category;
  return __distance(__first, __last, _Category());
}



template <class _InputIter, class _Distance>
inline void __advance(_InputIter& __i, _Distance __n, input_iterator_tag) {
  while (__n--) ++__i;
}


#pragma set woff 1183


template <class _BidirectionalIterator, class _Distance>
inline void __advance(_BidirectionalIterator& __i, _Distance __n, 
                      bidirectional_iterator_tag) {
  if (__n >= 0)
    while (__n--) ++__i;
  else
    while (__n++) --__i;
}


#pragma reset woff 1183


template <class _RandomAccessIterator, class _Distance>
inline void __advance(_RandomAccessIterator& __i, _Distance __n, 
                      random_access_iterator_tag) {
  __i += __n;
}

template <class _InputIterator, class _Distance>
inline void advance(_InputIterator& __i, _Distance __n) {
  __advance(__i, __n, iterator_category(__i));
}

}








#line 66 "/usr/include/CC/stl_algobase.h"
#line 1 "/usr/include/CC/stl_iterator.h"
























 



 




namespace std {


template <class _Container>
class back_insert_iterator {
protected:
  _Container* container;
public:
  typedef _Container          container_type;
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;

  explicit back_insert_iterator(_Container& __x) : container(&__x) {}
  back_insert_iterator<_Container>&
  operator=(const typename _Container::value_type& __value) { 
    container->push_back(__value);
    return *this;
  }
  back_insert_iterator<_Container>& operator*() { return *this; }
  back_insert_iterator<_Container>& operator++() { return *this; }
  back_insert_iterator<_Container>& operator++(int) { return *this; }
};

#line 70 "/usr/include/CC/stl_iterator.h"

template <class _Container>
inline back_insert_iterator<_Container> back_inserter(_Container& __x) {
  return back_insert_iterator<_Container>(__x);
}

template <class _Container>
class front_insert_iterator {
protected:
  _Container* container;
public:
  typedef _Container          container_type;
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;

  explicit front_insert_iterator(_Container& __x) : container(&__x) {}
  front_insert_iterator<_Container>&
  operator=(const typename _Container::value_type& __value) { 
    container->push_front(__value);
    return *this;
  }
  front_insert_iterator<_Container>& operator*() { return *this; }
  front_insert_iterator<_Container>& operator++() { return *this; }
  front_insert_iterator<_Container>& operator++(int) { return *this; }
};

#line 109 "/usr/include/CC/stl_iterator.h"

template <class _Container>
inline front_insert_iterator<_Container> front_inserter(_Container& __x) {
  return front_insert_iterator<_Container>(__x);
}

template <class _Container>
class insert_iterator {
protected:
  _Container* container;
  typename _Container::iterator iter;
public:
  typedef _Container          container_type;
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;

  insert_iterator(_Container& __x, typename _Container::iterator __i) 
    : container(&__x), iter(__i) {}
  insert_iterator<_Container>&
  operator=(const typename _Container::value_type& __value) { 
    iter = container->insert(iter, __value);
    ++iter;
    return *this;
  }
  insert_iterator<_Container>& operator*() { return *this; }
  insert_iterator<_Container>& operator++() { return *this; }
  insert_iterator<_Container>& operator++(int) { return *this; }
};

#line 151 "/usr/include/CC/stl_iterator.h"

template <class _Container, class _Iterator>
inline 
insert_iterator<_Container> inserter(_Container& __x, _Iterator __i)
{
  typedef typename _Container::iterator __iter;
  return insert_iterator<_Container>(__x, __iter(__i));
}


template <class _BidirectionalIterator, class _Tp, class _Reference = _Tp&, 
          class _Distance = ptrdiff_t> 




class reverse_bidirectional_iterator {
  typedef reverse_bidirectional_iterator<_BidirectionalIterator, _Tp, 
                                         _Reference, _Distance>  _Self;
protected:
  _BidirectionalIterator current;
public:
  typedef bidirectional_iterator_tag iterator_category;
  typedef _Tp                        value_type;
  typedef _Distance                  difference_type;
  typedef _Tp*                       pointer;
  typedef _Reference                 reference;

  reverse_bidirectional_iterator() {}
  explicit reverse_bidirectional_iterator(_BidirectionalIterator __x)
    : current(__x) {}
  _BidirectionalIterator base() const { return current; }
  _Reference operator*() const {
    _BidirectionalIterator __tmp = current;
    return *--__tmp;
  }

  pointer operator->() const { return &(operator*()); }

  _Self& operator++() {
    --current;
    return *this;
  }
  _Self operator++(int) {
    _Self __tmp = *this;
    --current;
    return __tmp;
  }
  _Self& operator--() {
    ++current;
    return *this;
  }
  _Self operator--(int) {
    _Self __tmp = *this;
    ++current;
    return __tmp;
  }
};

#line 242 "/usr/include/CC/stl_iterator.h"

template <class _BiIter, class _Tp, class _Ref, class _Distance>
inline bool operator==(
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __x, 
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __y)
{
  return __x.base() == __y.base();
}



template <class _BiIter, class _Tp, class _Ref, class _Distance>
inline bool operator!=(
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __x, 
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __y)
{
  return !(__x == __y);
}












template <class _Iterator>
class reverse_iterator 
{
protected:
  _Iterator current;
public:
  typedef typename iterator_traits<_Iterator>::iterator_category
          iterator_category;
  typedef typename iterator_traits<_Iterator>::value_type
          value_type;
  typedef typename iterator_traits<_Iterator>::difference_type
          difference_type;
  typedef typename iterator_traits<_Iterator>::pointer
          pointer;
  typedef typename iterator_traits<_Iterator>::reference
          reference;

  typedef _Iterator iterator_type;
  typedef reverse_iterator<_Iterator> _Self;

public:
  reverse_iterator() {}
  explicit reverse_iterator(iterator_type __x) : current(__x) {}

  reverse_iterator(const _Self& __x) : current(__x.current) {}

  template <class _Iter>
  reverse_iterator(const reverse_iterator<_Iter>& __x)
    : current(__x.base()) {}

    
  iterator_type base() const { return current; }
  reference operator*() const {
    _Iterator __tmp = current;
    return *--__tmp;
  }

  pointer operator->() const { return &(operator*()); }


  _Self& operator++() {
    --current;
    return *this;
  }
  _Self operator++(int) {
    _Self __tmp = *this;
    --current;
    return __tmp;
  }
  _Self& operator--() {
    ++current;
    return *this;
  }
  _Self operator--(int) {
    _Self __tmp = *this;
    ++current;
    return __tmp;
  }

  _Self operator+(difference_type __n) const {
    return _Self(current - __n);
  }
  _Self& operator+=(difference_type __n) {
    current -= __n;
    return *this;
  }
  _Self operator-(difference_type __n) const {
    return _Self(current + __n);
  }
  _Self& operator-=(difference_type __n) {
    current += __n;
    return *this;
  }
  reference operator[](difference_type __n) const { return *(*this + __n); }  
}; 
 
template <class _Iterator>
inline bool operator==(const reverse_iterator<_Iterator>& __x, 
                       const reverse_iterator<_Iterator>& __y) {
  return __x.base() == __y.base();
}

template <class _Iterator>
inline bool operator<(const reverse_iterator<_Iterator>& __x, 
                      const reverse_iterator<_Iterator>& __y) {
  return __y.base() < __x.base();
}



template <class _Iterator>
inline bool operator!=(const reverse_iterator<_Iterator>& __x, 
                       const reverse_iterator<_Iterator>& __y) {
  return !(__x == __y);
}

template <class _Iterator>
inline bool operator>(const reverse_iterator<_Iterator>& __x, 
                      const reverse_iterator<_Iterator>& __y) {
  return __y < __x;
}

template <class _Iterator>
inline bool operator<=(const reverse_iterator<_Iterator>& __x, 
                       const reverse_iterator<_Iterator>& __y) {
  return !(__y < __x);
}

template <class _Iterator>
inline bool operator>=(const reverse_iterator<_Iterator>& __x, 
                      const reverse_iterator<_Iterator>& __y) {
  return !(__x < __y);
}



template <class _Iterator>
inline typename reverse_iterator<_Iterator>::difference_type
operator-(const reverse_iterator<_Iterator>& __x, 
          const reverse_iterator<_Iterator>& __y) {
  return __y.base() - __x.base();
}

template <class _Iterator>
inline reverse_iterator<_Iterator> 
operator+(typename reverse_iterator<_Iterator>::difference_type __n,
          const reverse_iterator<_Iterator>& __x) {
  return reverse_iterator<_Iterator>(__x.base() - __n);
}

#line 581 "/usr/include/CC/stl_iterator.h"







template <class _Tp, 
          class _CharT = char, class _Traits = char_traits<_CharT>,
          class _Dist = ptrdiff_t> 
class istream_iterator {
public:
  typedef _CharT                         char_type;
  typedef _Traits                        traits_type;
  typedef basic_istream<_CharT, _Traits> istream_type;

  typedef input_iterator_tag             iterator_category;
  typedef _Tp                            value_type;
  typedef _Dist                          difference_type;
  typedef const _Tp*                     pointer;
  typedef const _Tp&                     reference;

  istream_iterator() : _M_stream(0), _M_ok(false) {}
  istream_iterator(istream_type& __s) : _M_stream(&__s) { _M_read(); }

  reference operator*() const { return _M_value; }
  pointer operator->() const { return &(operator*()); }

  istream_iterator& operator++() { 
    _M_read(); 
    return *this;
  }
  istream_iterator operator++(int)  {
    istream_iterator __tmp = *this;
    _M_read();
    return __tmp;
  }

  bool _M_equal(const istream_iterator& __x) const
    { return (_M_ok == __x._M_ok) && (!_M_ok || _M_stream == __x._M_stream); }

private:
  istream_type* _M_stream;
  _Tp _M_value;
  bool _M_ok;

  void _M_read() {
    _M_ok = (_M_stream && *_M_stream) ? true : false;
    if (_M_ok) {
      *_M_stream >> _M_value;
      _M_ok = *_M_stream ? true : false;
    }
  }
};

template <class _Tp, class _CharT, class _Traits, class _Dist>
inline bool 
operator==(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) {
  return __x._M_equal(__y);
}



template <class _Tp, class _CharT, class _Traits, class _Dist>
inline bool 
operator!=(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) {
  return !__x._M_equal(__y);
}



template <class _Tp,
          class _CharT = char, class _Traits = char_traits<_CharT> >
class ostream_iterator {
public:
  typedef _CharT                         char_type;
  typedef _Traits                        traits_type;
  typedef basic_ostream<_CharT, _Traits> ostream_type;

  typedef output_iterator_tag            iterator_category;
  typedef void                           value_type;
  typedef void                           difference_type;
  typedef void                           pointer;
  typedef void                           reference;

  ostream_iterator(ostream_type& __s) : _M_stream(&__s), _M_string(0) {}
  ostream_iterator(ostream_type& __s, const _CharT* __c) 
    : _M_stream(&__s), _M_string(__c)  {}
  ostream_iterator<_Tp>& operator=(const _Tp& __value) { 
    *_M_stream << __value;
    if (_M_string) *_M_stream << _M_string;
    return *this;
  }
  ostream_iterator<_Tp>& operator*() { return *this; }
  ostream_iterator<_Tp>& operator++() { return *this; } 
  ostream_iterator<_Tp>& operator++(int) { return *this; } 
private:
  ostream_type* _M_stream;
  const _CharT* _M_string;
};







template<class _CharT, class _Traits>
class istreambuf_iterator
{
public:
  typedef _CharT                           char_type;
  typedef _Traits                          traits_type;
  typedef typename _Traits::int_type       int_type;
  typedef basic_streambuf<_CharT, _Traits> streambuf_type;
  typedef basic_istream<_CharT, _Traits>   istream_type;

  typedef input_iterator_tag               iterator_category;
  typedef _CharT                           value_type;
  typedef typename _Traits::off_type       difference_type;
  typedef const _CharT*                    pointer;
  typedef const _CharT&                    reference;

public:
  istreambuf_iterator(streambuf_type* __p = 0) { this->_M_init(__p); }
  istreambuf_iterator(istream_type& __is) { this->_M_init(__is.rdbuf()); }

  char_type operator*() const 
    { return _M_is_initialized ? _M_c : _M_dereference_aux(); }

  istreambuf_iterator& operator++() { this->_M_nextc(); return *this; }
  istreambuf_iterator  operator++(int) {
    if (!_M_is_initialized)
      _M_postincr_aux();
    istreambuf_iterator __tmp = *this;
    this->_M_nextc();
    return __tmp;
  }

  bool equal(const istreambuf_iterator& __i) const {
    return this->_M_is_initialized && __i._M_is_initialized
      ? this->_M_eof == __i._M_eof
      : this->_M_equal_aux(__i);
  }

private:
  void _M_init(streambuf_type* __p) {
    _M_buf = __p;
    _M_eof = !__p;
    _M_is_initialized = _M_eof;
  }

  char_type _M_dereference_aux() const;
  bool _M_equal_aux(const istreambuf_iterator&) const;
  void _M_postincr_aux();

  void _M_nextc() {
    int_type __c = _M_buf->snextc();
    _M_c = traits_type::to_char_type(__c);    
    _M_eof = traits_type::eq_int_type(__c, traits_type::eof());
    _M_is_initialized = true;
  }

  void _M_getc() const {
    int_type __c = _M_buf->sgetc();
    _M_c = traits_type::to_char_type(__c);
    _M_eof = traits_type::eq_int_type(__c, traits_type::eof());
    _M_is_initialized = true;
  }

private:
  streambuf_type* _M_buf;
  mutable _CharT _M_c;
  mutable bool _M_eof : 1;
  mutable bool _M_is_initialized : 1;
};

template<class _CharT, class _Traits>
_CharT istreambuf_iterator<_CharT, _Traits>::_M_dereference_aux() const
{
  this->_M_getc();
  return _M_c;
}

template<class _CharT, class _Traits>
bool istreambuf_iterator<_CharT, _Traits>
  ::_M_equal_aux(const istreambuf_iterator& __i) const
{
  if (!this->_M_is_initialized)
    this->_M_getc();
  if (!__i._M_is_initialized)
    __i._M_getc();

  return this->_M_eof == __i._M_eof;
}

template<class _CharT, class _Traits>
void istreambuf_iterator<_CharT, _Traits>::_M_postincr_aux()
{
  this->_M_getc();
}

template<class _CharT, class _Traits>
inline bool operator==(const istreambuf_iterator<_CharT, _Traits>& __x,
                       const istreambuf_iterator<_CharT, _Traits>& __y) {
  return __x.equal(__y);
}



template<class _CharT, class _Traits>
inline bool operator!=(const istreambuf_iterator<_CharT, _Traits>& __x,
                       const istreambuf_iterator<_CharT, _Traits>& __y) {
  return !__x.equal(__y);
}




template<class _CharT, class _Traits>
class ostreambuf_iterator
{
public:
  typedef _CharT                           char_type;
  typedef _Traits                          traits_type;
  typedef typename _Traits::int_type       int_type;
  typedef basic_streambuf<_CharT, _Traits> streambuf_type;
  typedef basic_ostream<_CharT, _Traits>   ostream_type;

  typedef output_iterator_tag              iterator_category;
  typedef void                             value_type;
  typedef void                             difference_type;
  typedef void                             pointer;
  typedef void                             reference;

public:
  ostreambuf_iterator(streambuf_type* __buf) : _M_buf(__buf), _M_ok(__buf) {}
  ostreambuf_iterator(ostream_type& __o)
    : _M_buf(__o.rdbuf()), _M_ok(__o.rdbuf()) {}

  ostreambuf_iterator& operator=(char_type __c) {
    _M_ok = _M_ok && !traits_type::eq_int_type(_M_buf->sputc(__c),
                                               traits_type::eof());
    return *this;
  }    
  
  ostreambuf_iterator& operator*()     { return *this; }
  ostreambuf_iterator& operator++()    { return *this; }
  ostreambuf_iterator& operator++(int) { return *this; }

  bool failed() const { return !_M_ok; }

private:
  streambuf_type* _M_buf;
  bool _M_ok;
};

#line 958 "/usr/include/CC/stl_iterator.h"

}






#line 67 "/usr/include/CC/stl_algobase.h"


namespace std {



template <class _ForwardIter1, class _ForwardIter2, class _Tp>
inline void __iter_swap(_ForwardIter1 __a, _ForwardIter2 __b, _Tp*) {
  _Tp __tmp = *__a;
  *__a = *__b;
  *__b = __tmp;
}

template <class _ForwardIter1, class _ForwardIter2>
inline void iter_swap(_ForwardIter1 __a, _ForwardIter2 __b) {
  __iter_swap(__a, __b, __value_type(__a));
}

template <class _Tp>
inline void swap(_Tp& __a, _Tp& __b) {
  _Tp __tmp = __a;
  __a = __b;
  __b = __tmp;
}









template <class _Tp>
inline const _Tp& min(const _Tp& __a, const _Tp& __b) {
  return __b < __a ? __b : __a;
}

template <class _Tp>
inline const _Tp& max(const _Tp& __a, const _Tp& __b) {
  return  __a < __b ? __b : __a;
}



template <class _Tp, class _Compare>
inline const _Tp& min(const _Tp& __a, const _Tp& __b, _Compare __comp) {
  return __comp(__b, __a) ? __b : __a;
}

template <class _Tp, class _Compare>
inline const _Tp& max(const _Tp& __a, const _Tp& __b, _Compare __comp) {
  return __comp(__a, __b) ? __b : __a;
}












template <class _InputIter, class _OutputIter, class _Distance>
inline _OutputIter __copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result,
                          input_iterator_tag, _Distance*)
{
  for ( ; __first != __last; ++__result, ++__first)
    *__result = *__first;
  return __result;
}

template <class _RandomAccessIter, class _OutputIter, class _Distance>
inline _OutputIter
__copy(_RandomAccessIter __first, _RandomAccessIter __last,
       _OutputIter __result, random_access_iterator_tag, _Distance*)
{
  for (_Distance __n = __last - __first; __n > 0; --__n) {
    *__result = *__first;
    ++__first;
    ++__result;
  }
  return __result;
}

template <class _Tp>
inline _Tp*
__copy_trivial(const _Tp* __first, const _Tp* __last, _Tp* __result) {
  memmove(__result, __first, sizeof(_Tp) * (__last - __first));
  return __result + (__last - __first);
}



template <class _InputIter, class _OutputIter, class _BoolType>
struct __copy_dispatch {
  static _OutputIter copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result) {
    typedef typename iterator_traits<_InputIter>::iterator_category _Category;
    typedef typename iterator_traits<_InputIter>::difference_type _Distance;
    return __copy(__first, __last, __result, _Category(), (_Distance*) 0);
  }
};

template <class _Tp>
struct __copy_dispatch<_Tp*, _Tp*, __true_type>
{
  static _Tp* copy(const _Tp* __first, const _Tp* __last, _Tp* __result) {
    return __copy_trivial(__first, __last, __result);
  }
};

template <class _Tp>
struct __copy_dispatch<const _Tp*, _Tp*, __true_type>
{
  static _Tp* copy(const _Tp* __first, const _Tp* __last, _Tp* __result) {
    return __copy_trivial(__first, __last, __result);
  }
};

template <class _InputIter, class _OutputIter>
inline _OutputIter copy(_InputIter __first, _InputIter __last,
                        _OutputIter __result) {
  typedef typename iterator_traits<_InputIter>::value_type _Tp;
  typedef typename __type_traits<_Tp>::has_trivial_assignment_operator
          _Trivial;
  return __copy_dispatch<_InputIter, _OutputIter, _Trivial>
    ::copy(__first, __last, __result);
}

#line 224 "/usr/include/CC/stl_algobase.h"




template <class _BidirectionalIter1, class _BidirectionalIter2, 
          class _Distance>
inline _BidirectionalIter2 __copy_backward(_BidirectionalIter1 __first, 
                                           _BidirectionalIter1 __last, 
                                           _BidirectionalIter2 __result,
                                           bidirectional_iterator_tag,
                                           _Distance*)
{
  while (__first != __last)
    *--__result = *--__last;
  return __result;
}

template <class _RandomAccessIter, class _BidirectionalIter, class _Distance>
inline _BidirectionalIter __copy_backward(_RandomAccessIter __first, 
                                          _RandomAccessIter __last, 
                                          _BidirectionalIter __result,
                                          random_access_iterator_tag,
                                          _Distance*)
{
  for (_Distance __n = __last - __first; __n > 0; --__n)
    *--__result = *--__last;
  return __result;
}








template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BoolType>
struct __copy_backward_dispatch
{
  typedef typename iterator_traits<_BidirectionalIter1>::iterator_category 
          _Cat;
  typedef typename iterator_traits<_BidirectionalIter1>::difference_type
          _Distance;

  static _BidirectionalIter2 copy(_BidirectionalIter1 __first, 
                                  _BidirectionalIter1 __last, 
                                  _BidirectionalIter2 __result) {
    return __copy_backward(__first, __last, __result, _Cat(), (_Distance*) 0);
  }
};

template <class _Tp>
struct __copy_backward_dispatch<_Tp*, _Tp*, __true_type>
{
  static _Tp* copy(const _Tp* __first, const _Tp* __last, _Tp* __result) {
    const ptrdiff_t _Num = __last - __first;
    memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
    return __result - _Num;
  }
};

template <class _Tp>
struct __copy_backward_dispatch<const _Tp*, _Tp*, __true_type>
{
  static _Tp* copy(const _Tp* __first, const _Tp* __last, _Tp* __result) {
    return  __copy_backward_dispatch<_Tp*, _Tp*, __true_type>
      ::copy(__first, __last, __result);
  }
};

template <class _BI1, class _BI2>
inline _BI2 copy_backward(_BI1 __first, _BI1 __last, _BI2 __result) {
  typedef typename __type_traits<typename iterator_traits<_BI2>::value_type>
                        ::has_trivial_assignment_operator
          _Trivial;
  return __copy_backward_dispatch<_BI1, _BI2, _Trivial>
              ::copy(__first, __last, __result);
}

#line 314 "/usr/include/CC/stl_algobase.h"




template <class _InputIter, class _Size, class _OutputIter>
pair<_InputIter, _OutputIter> __copy_n(_InputIter __first, _Size __count,
                                       _OutputIter __result,
                                       input_iterator_tag) {
  for ( ; __count > 0; --__count) {
    *__result = *__first;
    ++__first;
    ++__result;
  }
  return pair<_InputIter, _OutputIter>(__first, __result);
}

template <class _RAIter, class _Size, class _OutputIter>
inline pair<_RAIter, _OutputIter>
__copy_n(_RAIter __first, _Size __count,
         _OutputIter __result,
         random_access_iterator_tag) {
  _RAIter __last = __first + __count;
  return pair<_RAIter, _OutputIter>(__last, copy(__first, __last, __result));
}

template <class _InputIter, class _Size, class _OutputIter>
inline pair<_InputIter, _OutputIter>
__copy_n(_InputIter __first, _Size __count, _OutputIter __result) {
  return __copy_n(__first, __count, __result,
                  __iterator_category(__first));
}

template <class _InputIter, class _Size, class _OutputIter>
inline pair<_InputIter, _OutputIter>
copy_n(_InputIter __first, _Size __count, _OutputIter __result) {
  return __copy_n(__first, __count, __result);
}





template <class _ForwardIter, class _Tp>
void fill(_ForwardIter __first, _ForwardIter __last, const _Tp& __value) {
  for ( ; __first != __last; ++__first)
    *__first = __value;
}

template <class _OutputIter, class _Size, class _Tp>
_OutputIter fill_n(_OutputIter __first, _Size __n, const _Tp& __value) {
  for ( ; __n > 0; --__n, ++__first)
    *__first = __value;
  return __first;
}




template <class _InputIter1, class _InputIter2>
pair<_InputIter1, _InputIter2> mismatch(_InputIter1 __first1,
                                        _InputIter1 __last1,
                                        _InputIter2 __first2) {
  while (__first1 != __last1 && *__first1 == *__first2) {
    ++__first1;
    ++__first2;
  }
  return pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
pair<_InputIter1, _InputIter2> mismatch(_InputIter1 __first1,
                                        _InputIter1 __last1,
                                        _InputIter2 __first2,
                                        _BinaryPredicate __binary_pred) {
  while (__first1 != __last1 && __binary_pred(*__first1, *__first2)) {
    ++__first1;
    ++__first2;
  }
  return pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2>
inline bool equal(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2) {
  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (*__first1 != *__first2)
      return false;
  return true;
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
inline bool equal(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2, _BinaryPredicate __binary_pred) {
  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (!__binary_pred(*__first1, *__first2))
      return false;
  return true;
}





template <class _InputIter1, class _InputIter2>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2) {
  for ( ; __first1 != __last1 && __first2 != __last2
        ; ++__first1, ++__first2) {
    if (*__first1 < *__first2)
      return true;
    if (*__first2 < *__first1)
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}

template <class _InputIter1, class _InputIter2, class _Compare>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _Compare __comp) {
  for ( ; __first1 != __last1 && __first2 != __last2
        ; ++__first1, ++__first2) {
    if (__comp(*__first1, *__first2))
      return true;
    if (__comp(*__first2, *__first1))
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}

inline bool 
lexicographical_compare(const unsigned char* __first1,
                        const unsigned char* __last1,
                        const unsigned char* __first2,
                        const unsigned char* __last2)
{
  const size_t __len1 = __last1 - __first1;
  const size_t __len2 = __last2 - __first2;
  const int __result = memcmp(__first1, __first2, min(__len1, __len2));
  return __result != 0 ? __result < 0 : __len1 < __len2;
}

inline bool lexicographical_compare(const char* __first1, const char* __last1,
                                    const char* __first2, const char* __last2)
{
#line 465 "/usr/include/CC/stl_algobase.h"
  return lexicographical_compare((const unsigned char*) __first1,
                                 (const unsigned char*) __last1,
                                 (const unsigned char*) __first2,
                                 (const unsigned char*) __last2);

}

template <class _InputIter1, class _InputIter2>
int __lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                   _InputIter2 __first2, _InputIter2 __last2)
{
  while (__first1 != __last1 && __first2 != __last2) {
    if (*__first1 < *__first2)
      return -1;
    if (*__first2 < *__first1)
      return 1;
    ++__first1;
    ++__first2;
  }
  if (__first2 == __last2) {
    return !(__first1 == __last1);
  }
  else {
    return -1;
  }
}

inline int
__lexicographical_compare_3way(const unsigned char* __first1,
                               const unsigned char* __last1,
                               const unsigned char* __first2,
                               const unsigned char* __last2)
{
  const ptrdiff_t __len1 = __last1 - __first1;
  const ptrdiff_t __len2 = __last2 - __first2;
  const int __result = memcmp(__first1, __first2, min(__len1, __len2));
  return __result != 0 ? __result 
                       : (__len1 == __len2 ? 0 : (__len1 < __len2 ? -1 : 1));
}

inline int 
__lexicographical_compare_3way(const char* __first1, const char* __last1,
                               const char* __first2, const char* __last2)
{
#line 516 "/usr/include/CC/stl_algobase.h"
  return __lexicographical_compare_3way((const unsigned char*) __first1,
                                        (const unsigned char*) __last1,
                                        (const unsigned char*) __first2,
                                        (const unsigned char*) __last2);

}

template <class _InputIter1, class _InputIter2>
int lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                 _InputIter2 __first2, _InputIter2 __last2)
{
  return __lexicographical_compare_3way(__first1, __last1, __first2, __last2);
}

}






#line 19 "/usr/include/CC/memory"
#line 1 "/usr/include/CC/stl_alloc.h"











 



 




#line 28 "/usr/include/CC/stl_alloc.h"













#line 51 "/usr/include/CC/stl_alloc.h"





#line 1 "/usr/include/assert.h"
 
#line 1 "/usr/include/internal/assert_core.h"
 











 
 
 

 
 
 

#ident "$Revision: 1.1 $"









 



extern "C" {







extern void __assert(const char *, const char *, int);
#line 50 "/usr/include/internal/assert_core.h"

}
#line 3 "/usr/include/assert.h"

#line 60 "/usr/include/CC/stl_alloc.h"




#line 1 "/usr/include/CC/stl_threads.h"











 










#line 1 "/usr/include/mutex.h"










 



#ident "$Revision: 1.1 $"




extern "C" {

#line 32 "/usr/include/mutex.h"

#line 43 "/usr/include/mutex.h"

extern unsigned long (*__test_and_set)(unsigned long *, unsigned long);
extern unsigned long (*__test_then_and)(unsigned long *, unsigned long);
extern unsigned long (*__test_then_nand)(unsigned long *, unsigned long);
extern unsigned long (*__test_then_not)(unsigned long *, unsigned long);
extern unsigned long (*__test_then_nor)(unsigned long *, unsigned long);
extern unsigned long (*__test_then_xor)(unsigned long *, unsigned long);
extern unsigned long (*__test_then_or)(unsigned long *, unsigned long);
extern unsigned long (*__test_then_add)(unsigned long *, unsigned long);
extern unsigned long (*__add_then_test)(unsigned long *, unsigned long);
extern unsigned long atomic_op(
		unsigned long (*)(unsigned long *, unsigned long),
		unsigned long *, unsigned long);

extern __uint32_t (*__test_and_set32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__test_then_and32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__test_then_nand32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__test_then_not32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__test_then_nor32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__test_then_xor32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__test_then_or32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__test_then_add32)(__uint32_t *, __uint32_t);
extern __uint32_t (*__add_then_test32)(__uint32_t *, __uint32_t);
extern __uint32_t atomic_op32(
		__uint32_t (*)(__uint32_t *, __uint32_t),
		__uint32_t *, __uint32_t);

 
extern int _test_and_set(int *, int);

extern int is_mips2(void);

}

#line 25 "/usr/include/CC/stl_threads.h"
#line 31 "/usr/include/CC/stl_threads.h"

namespace std {














struct _Refcount_Base
{
  



  typedef size_t _RC_t;

  
  
   volatile _RC_t _M_ref_count;

  





  _Refcount_Base(_RC_t __n) : _M_ref_count(__n) {}


  

  void _M_incr() {  __add_and_fetch(&_M_ref_count, 1); }
  _RC_t _M_decr() { return __add_and_fetch(&_M_ref_count, (size_t) -1); }
#line 91 "/usr/include/CC/stl_threads.h"
};






    inline unsigned long _Atomic_swap(unsigned long * __p, unsigned long __q) {



            return __test_and_set(__p, (unsigned long)__q);

    }
#line 164 "/usr/include/CC/stl_threads.h"













struct _STL_mutex_lock
{

  
  volatile unsigned long _M_lock;
  void _M_initialize() { _M_lock = 0; }
  static void _S_nsec_sleep(int __log_nsec) {

          struct timespec __ts;
           
          __ts.tv_sec = 0;
          __ts.tv_nsec = 1 << __log_nsec;
          nanosleep(&__ts, 0);
#line 199 "/usr/include/CC/stl_threads.h"
  }
  void _M_acquire_lock() {
    const unsigned __low_spin_max = 30;  
    const unsigned __high_spin_max = 1000; 
    static unsigned __spin_max = __low_spin_max;
    unsigned __my_spin_max;
    static unsigned __last_spins = 0;
    unsigned __my_last_spins;
    unsigned __junk;
    int __i;
    volatile unsigned long* __lock = &this->_M_lock;

    if (!_Atomic_swap((unsigned long*)__lock, 1)) {
      return;
    }
    __my_spin_max = __spin_max;
    __my_last_spins = __last_spins;
    for (__i = 0; __i < __my_spin_max; __i++) {
      if (__i < __my_last_spins/2 || *__lock) {
        __junk *= __junk; __junk *= __junk;
        __junk *= __junk; __junk *= __junk;
        continue;
      }
      if (!_Atomic_swap((unsigned long*)__lock, 1)) {
        
        
        
        
        __last_spins = __i;
        __spin_max = __high_spin_max;
        return;
      }
    }
    
    __spin_max = __low_spin_max;
    for (__i = 0 ;; ++__i) {
      int __log_nsec = __i + 6;

      if (__log_nsec > 27) __log_nsec = 27;
      if (!_Atomic_swap((unsigned long *)__lock, 1)) {
        return;
      }
      _S_nsec_sleep(__log_nsec);
    }
  }
  void _M_release_lock() {
    volatile unsigned long* __lock = &_M_lock;





        __lock_release(__lock);





  }





#line 273 "/usr/include/CC/stl_threads.h"
};

#line 284 "/usr/include/CC/stl_threads.h"







struct _STL_auto_lock
{
  _STL_mutex_lock& _M_lock;
  
  _STL_auto_lock(_STL_mutex_lock& __lock) : _M_lock(__lock)
    { _M_lock._M_acquire_lock(); }
  ~_STL_auto_lock() { _M_lock._M_release_lock(); }

private:
  void operator=(const _STL_auto_lock&);
  _STL_auto_lock(const _STL_auto_lock&);
};

}






#line 66 "/usr/include/CC/stl_alloc.h"


  
  
  
  
    extern "C" {
      extern int __us_rsthread_malloc;
    }
	
	
	
#line 94 "/usr/include/CC/stl_alloc.h"

namespace std {


#pragma set woff 1174




#line 111 "/usr/include/CC/stl_alloc.h"

template <int __inst>
class __malloc_alloc_template {

private:

  static void* _S_oom_malloc(size_t);
  static void* _S_oom_realloc(void*, size_t);


  static void (* __malloc_alloc_oom_handler)();


public:

  static void* allocate(size_t __n)
  {
    void* __result = malloc(__n);
    if (0 == __result) __result = _S_oom_malloc(__n);
    return __result;
  }

  static void deallocate(void* __p, size_t  )
  {
    free(__p);
  }

  static void* reallocate(void* __p, size_t  , size_t __new_sz)
  {
    void* __result = realloc(__p, __new_sz);
    if (0 == __result) __result = _S_oom_realloc(__p, __new_sz);
    return __result;
  }

  static void (* __set_malloc_handler(void (*__f)()))()
  {
    void (* __old)() = __malloc_alloc_oom_handler;
    __malloc_alloc_oom_handler = __f;
    return(__old);
  }

};




template <int __inst>
void (* __malloc_alloc_template<__inst>::__malloc_alloc_oom_handler)() = 0;


template <int __inst>
void*
__malloc_alloc_template<__inst>::_S_oom_malloc(size_t __n)
{
    void (* __my_malloc_handler)();
    void* __result;

    for (;;) {
        __my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == __my_malloc_handler) { throw std::bad_alloc(); }
        (*__my_malloc_handler)();
        __result = malloc(__n);
        if (__result) return(__result);
    }
}

template <int __inst>
void* __malloc_alloc_template<__inst>::_S_oom_realloc(void* __p, size_t __n)
{
    void (* __my_malloc_handler)();
    void* __result;

    for (;;) {
        __my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == __my_malloc_handler) { throw std::bad_alloc(); }
        (*__my_malloc_handler)();
        __result = realloc(__p, __n);
        if (__result) return(__result);
    }
}

typedef __malloc_alloc_template<0> malloc_alloc;

template<class _Tp, class _Alloc>
class simple_alloc {

public:
    static _Tp* allocate(size_t __n)
      { return 0 == __n ? 0 : (_Tp*) _Alloc::allocate(__n * sizeof (_Tp)); }
    static _Tp* allocate(void)
      { return (_Tp*) _Alloc::allocate(sizeof (_Tp)); }
    static void deallocate(_Tp* __p, size_t __n)
      { if (0 != __n) _Alloc::deallocate(__p, __n * sizeof (_Tp)); }
    static void deallocate(_Tp* __p)
      { _Alloc::deallocate(__p, sizeof (_Tp)); }
};






template <class _Alloc>
class debug_alloc {

private:

  enum {_S_extra = 8};  
                        
                        

public:

  static void* allocate(size_t __n)
  {
    char* __result = (char*)_Alloc::allocate(__n + (int) _S_extra);
    *(size_t*)__result = __n;
    return __result + (int) _S_extra;
  }

  static void deallocate(void* __p, size_t __n)
  {
    char* __real_p = (char*)__p - (int) _S_extra;
    ((*(size_t*)__real_p == __n)?((void)0):__assert( "*(size_t*)__real_p == __n" , "/usr/include/CC/stl_alloc.h", 234));
    _Alloc::deallocate(__real_p, __n + (int) _S_extra);
  }

  static void* reallocate(void* __p, size_t __old_sz, size_t __new_sz)
  {
    char* __real_p = (char*)__p - (int) _S_extra;
    ((*(size_t*)__real_p == __old_sz)?((void)0):__assert( "*(size_t*)__real_p == __old_sz" , "/usr/include/CC/stl_alloc.h", 241));
    char* __result = (char*)
      _Alloc::reallocate(__real_p, __old_sz + (int) _S_extra,
                                   __new_sz + (int) _S_extra);
    *(size_t*)__result = __new_sz;
    return __result + (int) _S_extra;
  }

};


#line 258 "/usr/include/CC/stl_alloc.h"


























#line 290 "/usr/include/CC/stl_alloc.h"

template <bool threads, int inst>
class __default_alloc_template {

private:
  
  

    enum {_ALIGN = 8};
    enum {_MAX_BYTES = 128};
    enum {_NFREELISTS = 16}; 

  static size_t
  _S_round_up(size_t __bytes) 
    { return (((__bytes) + (size_t) _ALIGN-1) & ~((size_t) _ALIGN - 1)); }

private:
  union _Obj {
        union _Obj* _M_free_list_link;
        char _M_client_data[1];     
  };
private:




    static _Obj* volatile _S_free_list[_NFREELISTS]; 

  static  size_t _S_freelist_index(size_t __bytes) {
        return (((__bytes) + (size_t)_ALIGN-1)/(size_t)_ALIGN - 1);
  }

  
  static void* _S_refill(size_t __n);
  
  
  static char* _S_chunk_alloc(size_t __size, int& __nobjs);

  
  static char* _S_start_free;
  static char* _S_end_free;
  static size_t _S_heap_size;


    static _STL_mutex_lock _S_node_allocator_lock;


    
    
    
    class _Lock;
    friend class _Lock;
    class _Lock {
        public:
            _Lock() { if (threads && __us_rsthread_malloc) { _S_node_allocator_lock . _M_acquire_lock(); }; }
            ~_Lock() { if (threads && __us_rsthread_malloc) { _S_node_allocator_lock . _M_release_lock(); }; }
    };

public:

   
  static void* allocate(size_t __n)
  {
    _Obj* volatile* __my_free_list;
    _Obj*  __result;

    if (__n > (size_t) _MAX_BYTES) {
        return(malloc_alloc::allocate(__n));
    }
    __my_free_list = _S_free_list + _S_freelist_index(__n);
    
    
    

         
        _Lock __lock_instance;

    __result = *__my_free_list;
    if (__result == 0) {
        void* __r = _S_refill(_S_round_up(__n));
        return __r;
    }
    *__my_free_list = __result -> _M_free_list_link;
    return (__result);
  };

   
  static void deallocate(void* __p, size_t __n)
  {
    _Obj* __q = (_Obj*)__p;
    _Obj* volatile* __my_free_list;

    if (__n > (size_t) _MAX_BYTES) {
        malloc_alloc::deallocate(__p, __n);
        return;
    }
    __my_free_list = _S_free_list + _S_freelist_index(__n);
    

         
        _Lock __lock_instance;

    __q -> _M_free_list_link = *__my_free_list;
    *__my_free_list = __q;
    
  }

  static void* reallocate(void* __p, size_t __old_sz, size_t __new_sz);

} ;

typedef __default_alloc_template<true, 0> alloc;
typedef __default_alloc_template<false, 0> single_client_alloc;



 
 
 
 
template <bool __threads, int __inst>
char*
__default_alloc_template<__threads, __inst>::_S_chunk_alloc(size_t __size, 
                                                            int& __nobjs)
{
    char* __result;
    size_t __total_bytes = __size * __nobjs;
    size_t __bytes_left = _S_end_free - _S_start_free;

    if (__bytes_left >= __total_bytes) {
        __result = _S_start_free;
        _S_start_free += __total_bytes;
        return(__result);
    } else if (__bytes_left >= __size) {
        __nobjs = (int)(__bytes_left/__size);
        __total_bytes = __size * __nobjs;
        __result = _S_start_free;
        _S_start_free += __total_bytes;
        return(__result);
    } else {
        size_t __bytes_to_get = 
	  2 * __total_bytes + _S_round_up(_S_heap_size >> 4);
        
        if (__bytes_left > 0) {
            _Obj* volatile* __my_free_list =
                        _S_free_list + _S_freelist_index(__bytes_left);

            ((_Obj*)_S_start_free) -> _M_free_list_link = *__my_free_list;
            *__my_free_list = (_Obj*)_S_start_free;
        }
        _S_start_free = (char*)malloc(__bytes_to_get);
        if (0 == _S_start_free) {
            size_t __i;
            _Obj* volatile* __my_free_list;
	    _Obj* __p;
            
            
            
            for (__i = __size;
                 __i <= (size_t) _MAX_BYTES;
                 __i += (size_t) _ALIGN) {
                __my_free_list = _S_free_list + _S_freelist_index(__i);
                __p = *__my_free_list;
                if (0 != __p) {
                    *__my_free_list = __p -> _M_free_list_link;
                    _S_start_free = (char*)__p;
                    _S_end_free = _S_start_free + __i;
                    return(_S_chunk_alloc(__size, __nobjs));
                    
                    
                }
            }
	    _S_end_free = 0;	
            _S_start_free = (char*)malloc_alloc::allocate(__bytes_to_get);
            
            
            
        }
        _S_heap_size += __bytes_to_get;
        _S_end_free = _S_start_free + __bytes_to_get;
        return(_S_chunk_alloc(__size, __nobjs));
    }
}


 
 
 
template <bool __threads, int __inst>
void*
__default_alloc_template<__threads, __inst>::_S_refill(size_t __n)
{
    int __nobjs = 20;
    char* __chunk = _S_chunk_alloc(__n, __nobjs);
    _Obj* volatile* __my_free_list;
    _Obj* __result;
    _Obj* __current_obj;
    _Obj* __next_obj;
    int __i;

    if (1 == __nobjs) return(__chunk);
    __my_free_list = _S_free_list + _S_freelist_index(__n);

     
      __result = (_Obj*)__chunk;
      *__my_free_list = __next_obj = (_Obj*)(__chunk + __n);
      for (__i = 1; ; __i++) {
        __current_obj = __next_obj;
        __next_obj = (_Obj*)((char*)__next_obj + __n);
        if (__nobjs - 1 == __i) {
            __current_obj -> _M_free_list_link = 0;
            break;
        } else {
            __current_obj -> _M_free_list_link = __next_obj;
        }
      }
    return(__result);
}

template <bool threads, int inst>
void*
__default_alloc_template<threads, inst>::reallocate(void* __p,
                                                    size_t __old_sz,
                                                    size_t __new_sz)
{
    void* __result;
    size_t __copy_sz;

    if (__old_sz > (size_t) _MAX_BYTES && __new_sz > (size_t) _MAX_BYTES) {
        return(realloc(__p, __new_sz));
    }
    if (_S_round_up(__old_sz) == _S_round_up(__new_sz)) return(__p);
    __result = allocate(__new_sz);
    __copy_sz = __new_sz > __old_sz? __old_sz : __new_sz;
    memcpy(__result, __p, __copy_sz);
    deallocate(__p, __old_sz);
    return(__result);
}


    template <bool __threads, int __inst>
    _STL_mutex_lock
    __default_alloc_template<__threads, __inst>::_S_node_allocator_lock
        = { 0 };



template <bool __threads, int __inst>
char* __default_alloc_template<__threads, __inst>::_S_start_free = 0;

template <bool __threads, int __inst>
char* __default_alloc_template<__threads, __inst>::_S_end_free = 0;

template <bool __threads, int __inst>
size_t __default_alloc_template<__threads, __inst>::_S_heap_size = 0;

template <bool __threads, int __inst>
__default_alloc_template<__threads, __inst>::_Obj* volatile
__default_alloc_template<__threads, __inst> ::_S_free_list[



    __default_alloc_template<__threads, __inst>::_NFREELISTS

] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
















template <class _Tp>
class allocator {
  typedef alloc _Alloc;          
public:
  typedef size_t     size_type;
  typedef ptrdiff_t  difference_type;
  typedef _Tp*       pointer;
  typedef const _Tp* const_pointer;
  typedef _Tp&       reference;
  typedef const _Tp& const_reference;
  typedef _Tp        value_type;

  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };

  allocator() throw() {}
  allocator(const allocator&) throw() {}
  template <class _Tp1> allocator(const allocator<_Tp1>&) throw() {}
  ~allocator() throw() {}

  pointer address(reference __x) const { return &__x; }
  const_pointer address(const_reference __x) const { return &__x; }

  
  
  _Tp* allocate(size_type __n, const void* = 0) {
    return __n != 0 ? static_cast<_Tp*>(_Alloc::allocate(__n * sizeof(_Tp))) 
                    : 0;
  }

  
  void deallocate(pointer __p, size_type __n)
    { _Alloc::deallocate(__p, __n * sizeof(_Tp)); }

  size_type max_size() const throw() 
    { return size_t(-1) / sizeof(_Tp); }

  void construct(pointer __p, const _Tp& __val) { new(__p) _Tp(__val); }
  void destroy(pointer __p) { __p->~_Tp(); }
};

template<>
class allocator<void> {
public:
  typedef size_t      size_type;
  typedef ptrdiff_t   difference_type;
  typedef void*       pointer;
  typedef const void* const_pointer;
  typedef void        value_type;

  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };
};


template <class _T1, class _T2>
inline bool operator==(const allocator<_T1>&, const allocator<_T2>&) throw()
{
  return true;
}

template <class _T1, class _T2>
inline bool operator!=(const allocator<_T1>&, const allocator<_T2>&) throw()
{
  return false;
}








template <class _Tp, class _Alloc>
struct __allocator {
  _Alloc __underlying_alloc;

  typedef size_t    size_type;
  typedef ptrdiff_t difference_type;
  typedef _Tp*       pointer;
  typedef const _Tp* const_pointer;
  typedef _Tp&       reference;
  typedef const _Tp& const_reference;
  typedef _Tp        value_type;

  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, _Alloc> other;
  };

  __allocator() throw() {}
  __allocator(const __allocator& __a) throw()
    : __underlying_alloc(__a.__underlying_alloc) {}
  template <class _Tp1> 
  __allocator(const __allocator<_Tp1, _Alloc>& __a) throw()
    : __underlying_alloc(__a.__underlying_alloc) {}
  ~__allocator() throw() {}

  pointer address(reference __x) const { return &__x; }
  const_pointer address(const_reference __x) const { return &__x; }

  
  _Tp* allocate(size_type __n, const void* = 0) {
    return __n != 0 
        ? static_cast<_Tp*>(__underlying_alloc.allocate(__n * sizeof(_Tp))) 
        : 0;
  }

  
  void deallocate(pointer __p, size_type __n)
    { __underlying_alloc.deallocate(__p, __n * sizeof(_Tp)); }

  size_type max_size() const throw() 
    { return size_t(-1) / sizeof(_Tp); }

  void construct(pointer __p, const _Tp& __val) { new(__p) _Tp(__val); }
  void destroy(pointer __p) { __p->~_Tp(); }
};

template <class _Alloc>
class __allocator<void, _Alloc> {
  typedef size_t      size_type;
  typedef ptrdiff_t   difference_type;
  typedef void*       pointer;
  typedef const void* const_pointer;
  typedef void        value_type;

  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, _Alloc> other;
  };
};

template <class _Tp, class _Alloc>
inline bool operator==(const __allocator<_Tp, _Alloc>& __a1,
                       const __allocator<_Tp, _Alloc>& __a2)
{
  return __a1.__underlying_alloc == __a2.__underlying_alloc;
}


template <class _Tp, class _Alloc>
inline bool operator!=(const __allocator<_Tp, _Alloc>& __a1,
                       const __allocator<_Tp, _Alloc>& __a2)
{
  return __a1.__underlying_alloc != __a2.__underlying_alloc;
}






template <int inst>
inline bool operator==(const __malloc_alloc_template<inst>&,
                       const __malloc_alloc_template<inst>&)
{
  return true;
}


template <int __inst>
inline bool operator!=(const __malloc_alloc_template<__inst>&,
                       const __malloc_alloc_template<__inst>&)
{
  return false;
}


template <bool __threads, int __inst>
inline bool operator==(const __default_alloc_template<__threads, __inst>&,
                       const __default_alloc_template<__threads, __inst>&)
{
  return true;
}


template <bool __threads, int __inst>
inline bool operator!=(const __default_alloc_template<__threads, __inst>&,
                       const __default_alloc_template<__threads, __inst>&)
{
  return false;
}


template <class _Alloc>
inline bool operator==(const debug_alloc<_Alloc>&,
                       const debug_alloc<_Alloc>&) {
  return true;
}


template <class _Alloc>
inline bool operator!=(const debug_alloc<_Alloc>&,
                       const debug_alloc<_Alloc>&) {
  return false;
}






























template <class _Tp, class _Allocator>
struct _Alloc_traits
{
  static const bool _S_instanceless = false;
  typedef typename _Allocator::template rebind<_Tp>::other 
          allocator_type;
};

template <class _Tp, class _Allocator>
const bool _Alloc_traits<_Tp, _Allocator>::_S_instanceless;



template <class _Tp, class _Tp1>
struct _Alloc_traits<_Tp, allocator<_Tp1> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, alloc> _Alloc_type;
  typedef allocator<_Tp> allocator_type;
};



template <class _Tp, int __inst>
struct _Alloc_traits<_Tp, __malloc_alloc_template<__inst> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __malloc_alloc_template<__inst> > _Alloc_type;
  typedef __allocator<_Tp, __malloc_alloc_template<__inst> > allocator_type;
};

template <class _Tp, bool __threads, int __inst>
struct _Alloc_traits<_Tp, __default_alloc_template<__threads, __inst> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __default_alloc_template<__threads, __inst> > 
          _Alloc_type;
  typedef __allocator<_Tp, __default_alloc_template<__threads, __inst> > 
          allocator_type;
};

template <class _Tp, class _Alloc>
struct _Alloc_traits<_Tp, debug_alloc<_Alloc> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, debug_alloc<_Alloc> > _Alloc_type;
  typedef __allocator<_Tp, debug_alloc<_Alloc> > allocator_type;
};




template <class _Tp, class _Tp1, int __inst>
struct _Alloc_traits<_Tp, 
                     __allocator<_Tp1, __malloc_alloc_template<__inst> > >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __malloc_alloc_template<__inst> > _Alloc_type;
  typedef __allocator<_Tp, __malloc_alloc_template<__inst> > allocator_type;
};

template <class _Tp, class _Tp1, bool __thr, int __inst>
struct _Alloc_traits<_Tp, 
                      __allocator<_Tp1, 
                                  __default_alloc_template<__thr, __inst> > >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __default_alloc_template<__thr,__inst> > 
          _Alloc_type;
  typedef __allocator<_Tp, __default_alloc_template<__thr,__inst> > 
          allocator_type;
};

template <class _Tp, class _Tp1, class _Alloc>
struct _Alloc_traits<_Tp, __allocator<_Tp1, debug_alloc<_Alloc> > >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, debug_alloc<_Alloc> > _Alloc_type;
  typedef __allocator<_Tp, debug_alloc<_Alloc> > allocator_type;
};





#pragma reset woff 1174


}








#line 20 "/usr/include/CC/memory"
#line 1 "/usr/include/CC/stl_construct.h"
























 



 










namespace std {




template <class _Tp>
inline void destroy(_Tp* __pointer) {
  __pointer->~_Tp();
}

template <class _T1, class _T2>
inline void construct(_T1* __p, const _T2& __value) {
  new (__p) _T1(__value);
}

template <class _T1>
inline void construct(_T1* __p) {
  new (__p) _T1();
}

template <class _ForwardIterator>
void
__destroy_aux(_ForwardIterator __first, _ForwardIterator __last, __false_type)
{
  for ( ; __first != __last; ++__first)
    destroy(&*__first);
}

template <class _ForwardIterator> 
inline void __destroy_aux(_ForwardIterator, _ForwardIterator, __true_type) {}

template <class _ForwardIterator, class _Tp>
inline void 
__destroy(_ForwardIterator __first, _ForwardIterator __last, _Tp*)
{
  typedef typename __type_traits<_Tp>::has_trivial_destructor
          _Trivial_destructor;
  __destroy_aux(__first, __last, _Trivial_destructor());
}

template <class _ForwardIterator>
inline void destroy(_ForwardIterator __first, _ForwardIterator __last) {
  __destroy(__first, __last, __value_type(__first));
}

inline void destroy(char*, char*) {}
inline void destroy(wchar_t*, wchar_t*) {}

}






#line 21 "/usr/include/CC/memory"
#line 1 "/usr/include/CC/stl_tempbuf.h"
























 



 





namespace std {

#pragma set woff 1424
template <class _Tp>
pair<_Tp*, ptrdiff_t> 
__get_temporary_buffer(ptrdiff_t __len, _Tp*)
{
  if (__len > ptrdiff_t(2147483647 / sizeof(_Tp)))
    __len = 2147483647 / sizeof(_Tp);

  while (__len > 0) {
    _Tp* __tmp = (_Tp*) malloc((size_t)__len * sizeof(_Tp));
    if (__tmp != 0)
      return pair<_Tp*, ptrdiff_t>(__tmp, __len);
    __len /= 2;
  }

  return pair<_Tp*, ptrdiff_t>((_Tp*)0, 0);
}



template <class _Tp>
inline pair<_Tp*, ptrdiff_t> get_temporary_buffer(ptrdiff_t __len) {
  return __get_temporary_buffer(__len, (_Tp*) 0);
}








template <class _Tp>
inline pair<_Tp*, ptrdiff_t> get_temporary_buffer(ptrdiff_t __len, _Tp*) {
  return __get_temporary_buffer(__len, (_Tp*) 0);
}

template <class _Tp>
void return_temporary_buffer(_Tp* __p) {
  free(__p);
}

template <class _ForwardIterator, class _Tp>
class _Temporary_buffer {
private:
  ptrdiff_t  _M_original_len;
  ptrdiff_t  _M_len;
  _Tp*       _M_buffer;

  void _M_allocate_buffer() {
    _M_original_len = _M_len;
    _M_buffer = 0;

    if (_M_len > (ptrdiff_t)(2147483647 / sizeof(_Tp)))
      _M_len = 2147483647 / sizeof(_Tp);

    while (_M_len > 0) {
      _M_buffer = (_Tp*) malloc(_M_len * sizeof(_Tp));
      if (_M_buffer)
        break;
      _M_len /= 2;
    }
  }

  void _M_initialize_buffer(const _Tp&, __true_type) {}
  void _M_initialize_buffer(const _Tp& val, __false_type) {
    uninitialized_fill_n(_M_buffer, _M_len, val);
  }

public:
  ptrdiff_t size() const { return _M_len; }
  ptrdiff_t requested_size() const { return _M_original_len; }
  _Tp* begin() { return _M_buffer; }
  _Tp* end() { return _M_buffer + _M_len; }

  _Temporary_buffer(_ForwardIterator __first, _ForwardIterator __last) {
    



    typedef typename __type_traits<_Tp>::has_trivial_default_constructor
            _Trivial;


    try {
      _M_len = 0;
      distance(__first, __last, _M_len);
      _M_allocate_buffer();
      if (_M_len > 0)
        _M_initialize_buffer(*__first, _Trivial());
    }
    catch(...) { free(_M_buffer); _M_buffer = 0; _M_len = 0; throw; };
  }
 
  ~_Temporary_buffer() {  
    destroy(_M_buffer, _M_buffer + _M_len);
    free(_M_buffer);
  }

private:
  
  _Temporary_buffer(const _Temporary_buffer&) {}
  void operator=(const _Temporary_buffer&) {}
};



template <class _ForwardIterator, 
          class _Tp 

                    = typename iterator_traits<_ForwardIterator>::value_type

         >
struct temporary_buffer : public _Temporary_buffer<_ForwardIterator, _Tp>
{
  temporary_buffer(_ForwardIterator __first, _ForwardIterator __last)
    : _Temporary_buffer<_ForwardIterator, _Tp>(__first, __last) {}
  ~temporary_buffer() {}
};
    
#pragma reset woff 1424

}






#line 22 "/usr/include/CC/memory"
#line 1 "/usr/include/CC/stl_uninitialized.h"
























 



 




namespace std {





template <class _InputIter, class _ForwardIter>
inline _ForwardIter 
__uninitialized_copy_aux(_InputIter __first, _InputIter __last,
                         _ForwardIter __result,
                         __true_type)
{
  return copy(__first, __last, __result);
}

template <class _InputIter, class _ForwardIter>
_ForwardIter 
__uninitialized_copy_aux(_InputIter __first, _InputIter __last,
                         _ForwardIter __result,
                         __false_type)
{
  _ForwardIter __cur = __result;
  try {
    for ( ; __first != __last; ++__first, ++__cur)
      construct(&*__cur, *__first);
    return __cur;
  }
  catch(...) { destroy(__result, __cur); throw; };
}


template <class _InputIter, class _ForwardIter, class _Tp>
inline _ForwardIter
__uninitialized_copy(_InputIter __first, _InputIter __last,
                     _ForwardIter __result, _Tp*)
{
  typedef typename __type_traits<_Tp>::is_POD_type _Is_POD;
  return __uninitialized_copy_aux(__first, __last, __result, _Is_POD());
}

template <class _InputIter, class _ForwardIter>
inline _ForwardIter
  uninitialized_copy(_InputIter __first, _InputIter __last,
                     _ForwardIter __result)
{
  return __uninitialized_copy(__first, __last, __result,
                              __value_type(__result));
}

inline char* uninitialized_copy(const char* __first, const char* __last,
                                char* __result) {
  memmove(__result, __first, __last - __first);
  return __result + (__last - __first);
}

inline wchar_t* 
uninitialized_copy(const wchar_t* __first, const wchar_t* __last,
                   wchar_t* __result)
{
  memmove(__result, __first, sizeof(wchar_t) * (__last - __first));
  return __result + (__last - __first);
}



template <class _InputIter, class _Size, class _ForwardIter>
pair<_InputIter, _ForwardIter>
__uninitialized_copy_n(_InputIter __first, _Size __count,
                       _ForwardIter __result,
                       input_iterator_tag)
{
  _ForwardIter __cur = __result;
  try {
    for ( ; __count > 0 ; --__count, ++__first, ++__cur) 
      construct(&*__cur, *__first);
    return pair<_InputIter, _ForwardIter>(__first, __cur);
  }
  catch(...) { destroy(__result, __cur); throw; };
}

template <class _RandomAccessIter, class _Size, class _ForwardIter>
inline pair<_RandomAccessIter, _ForwardIter>
__uninitialized_copy_n(_RandomAccessIter __first, _Size __count,
                       _ForwardIter __result,
                       random_access_iterator_tag) {
  _RandomAccessIter __last = __first + __count;
  return pair<_RandomAccessIter, _ForwardIter>(
                 __last,
                 uninitialized_copy(__first, __last, __result));
}

template <class _InputIter, class _Size, class _ForwardIter>
inline pair<_InputIter, _ForwardIter>
__uninitialized_copy_n(_InputIter __first, _Size __count,
                     _ForwardIter __result) {
  return __uninitialized_copy_n(__first, __count, __result,
                                __iterator_category(__first));
}

template <class _InputIter, class _Size, class _ForwardIter>
inline pair<_InputIter, _ForwardIter>
uninitialized_copy_n(_InputIter __first, _Size __count,
                     _ForwardIter __result) {
  return __uninitialized_copy_n(__first, __count, __result,
                                __iterator_category(__first));
}



template <class _ForwardIter, class _Tp>
inline void
__uninitialized_fill_aux(_ForwardIter __first, _ForwardIter __last, 
                         const _Tp& __x, __true_type)
{
  fill(__first, __last, __x);
}

template <class _ForwardIter, class _Tp>
void
__uninitialized_fill_aux(_ForwardIter __first, _ForwardIter __last, 
                         const _Tp& __x, __false_type)
{
  _ForwardIter __cur = __first;
  try {
    for ( ; __cur != __last; ++__cur)
      construct(&*__cur, __x);
  }
  catch(...) { destroy(__first, __cur); throw; };
}

template <class _ForwardIter, class _Tp, class _Tp1>
inline void __uninitialized_fill(_ForwardIter __first, 
                                 _ForwardIter __last, const _Tp& __x, _Tp1*)
{
  typedef typename __type_traits<_Tp1>::is_POD_type _Is_POD;
  __uninitialized_fill_aux(__first, __last, __x, _Is_POD());
                   
}

template <class _ForwardIter, class _Tp>
inline void uninitialized_fill(_ForwardIter __first,
                               _ForwardIter __last, 
                               const _Tp& __x)
{
  __uninitialized_fill(__first, __last, __x, __value_type(__first));
}



template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter
__uninitialized_fill_n_aux(_ForwardIter __first, _Size __n,
                           const _Tp& __x, __true_type)
{
  return fill_n(__first, __n, __x);
}

template <class _ForwardIter, class _Size, class _Tp>
_ForwardIter
__uninitialized_fill_n_aux(_ForwardIter __first, _Size __n,
                           const _Tp& __x, __false_type)
{
  _ForwardIter __cur = __first;
  try {
    for ( ; __n > 0; --__n, ++__cur)
      construct(&*__cur, __x);
    return __cur;
  }
  catch(...) { destroy(__first, __cur); throw; };
}

template <class _ForwardIter, class _Size, class _Tp, class _Tp1>
inline _ForwardIter 
__uninitialized_fill_n(_ForwardIter __first, _Size __n, const _Tp& __x, _Tp1*)
{
  typedef typename __type_traits<_Tp1>::is_POD_type _Is_POD;
  return __uninitialized_fill_n_aux(__first, __n, __x, _Is_POD());
}

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter 
uninitialized_fill_n(_ForwardIter __first, _Size __n, const _Tp& __x)
{
  return __uninitialized_fill_n(__first, __n, __x, __value_type(__first));
}









template <class _InputIter1, class _InputIter2, class _ForwardIter>
inline _ForwardIter
__uninitialized_copy_copy(_InputIter1 __first1, _InputIter1 __last1,
                          _InputIter2 __first2, _InputIter2 __last2,
                          _ForwardIter __result)
{
  _ForwardIter __mid = uninitialized_copy(__first1, __last1, __result);
  try {
    return uninitialized_copy(__first2, __last2, __mid);
  }
  catch(...) { destroy(__result, __mid); throw; };
}




template <class _ForwardIter, class _Tp, class _InputIter>
inline _ForwardIter 
__uninitialized_fill_copy(_ForwardIter __result, _ForwardIter __mid,
                          const _Tp& __x,
                          _InputIter __first, _InputIter __last)
{
  uninitialized_fill(__result, __mid, __x);
  try {
    return uninitialized_copy(__first, __last, __mid);
  }
  catch(...) { destroy(__result, __mid); throw; };
}




template <class _InputIter, class _ForwardIter, class _Tp>
inline void
__uninitialized_copy_fill(_InputIter __first1, _InputIter __last1,
                          _ForwardIter __first2, _ForwardIter __last2,
                          const _Tp& __x)
{
  _ForwardIter __mid2 = uninitialized_copy(__first1, __last1, __first2);
  try {
    uninitialized_fill(__mid2, __last2, __x);
  }
  catch(...) { destroy(__first2, __mid2); throw; };
}

}






#line 23 "/usr/include/CC/memory"
#line 1 "/usr/include/CC/stl_raw_storage_iter.h"
























 



 




namespace std {

template <class _ForwardIterator, class _Tp>
class raw_storage_iterator

  : public iterator<output_iterator_tag, void, void, void, void>

{
protected:
  _ForwardIterator _M_iter;
public:
  typedef output_iterator_tag iterator_category;
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;

  explicit raw_storage_iterator(_ForwardIterator __x) : _M_iter(__x) {}
  raw_storage_iterator& operator*() { return *this; }
  raw_storage_iterator& operator=(const _Tp& __element) {
    construct(&*_M_iter, __element);
    return *this;
  }        
  raw_storage_iterator<_ForwardIterator, _Tp>& operator++() {
    ++_M_iter;
    return *this;
  }
  raw_storage_iterator<_ForwardIterator, _Tp> operator++(int) {
    raw_storage_iterator<_ForwardIterator, _Tp> __tmp = *this;
    ++_M_iter;
    return __tmp;
  }
};

#line 78 "/usr/include/CC/stl_raw_storage_iter.h"

}






#line 24 "/usr/include/CC/memory"


namespace std {




template<class _Tp1> struct auto_ptr_ref {
  _Tp1* _M_ptr;
  auto_ptr_ref(_Tp1* __p) : _M_ptr(__p) {}
};



template <class _Tp> class auto_ptr {
private:
  _Tp* _M_ptr;

public:
  typedef _Tp element_type;

  explicit auto_ptr(_Tp* __p = 0) throw() : _M_ptr(__p) {}
  auto_ptr(auto_ptr& __a) throw() : _M_ptr(__a.release()) {}


  template <class _Tp1> auto_ptr(auto_ptr<_Tp1>& __a) throw()
    : _M_ptr(__a.release()) {}


  auto_ptr& operator=(auto_ptr& __a) throw() {
    if (&__a != this) {
      delete _M_ptr;
      _M_ptr = __a.release();
    }
    return *this;
  }


  template <class _Tp1>
  auto_ptr& operator=(auto_ptr<_Tp1>& __a) throw() {
    if (__a.get() != this->get()) {
      delete _M_ptr;
      _M_ptr = __a.release();
    }
    return *this;
  }


  ~auto_ptr() throw() { delete _M_ptr; }

  _Tp& operator*() const throw() {
    return *_M_ptr;
  }
  _Tp* operator->() const throw() {
    return _M_ptr;
  }
  _Tp* get() const throw() {
    return _M_ptr;
  }
  _Tp* release() throw() {
    _Tp* __tmp = _M_ptr;
    _M_ptr = 0;
    return __tmp;
  }
  void reset(_Tp* __p = 0) throw() {
    if (__p != _M_ptr) {
      delete _M_ptr;
      _M_ptr = __p;
    }
  }

  
  
  
  
  



public:
  auto_ptr(auto_ptr_ref<_Tp> __ref) throw()
    : _M_ptr(__ref._M_ptr) {}

  auto_ptr& operator=(auto_ptr_ref<_Tp> __ref) throw() {
    if (__ref._M_ptr != this->get()) {
      delete _M_ptr;
      _M_ptr = __ref._M_ptr;
    }
    return *this;
  }

  template <class _Tp1> operator auto_ptr_ref<_Tp1>() throw() 
    { return auto_ptr_ref<_Tp1>(this->release()); }
  template <class _Tp1> operator auto_ptr<_Tp1>() throw()
    { return auto_ptr<_Tp1>(this->release()); }


};

}







#line 20 "../boost/scoped_ptr.hpp"


namespace boost
{



#line 33 "../boost/scoped_ptr.hpp"






template<class T> class scoped_ptr 
{
private:

    T * ptr;

    scoped_ptr(scoped_ptr const &);
    scoped_ptr & operator=(scoped_ptr const &);

    typedef scoped_ptr<T> this_type;

public:

    typedef T element_type;

    explicit scoped_ptr(T * p = 0): ptr(p) 
    {



    }



    explicit scoped_ptr(std::auto_ptr<T> p): ptr(p.release()) 
    {



    }



    ~scoped_ptr() 
    {



        boost::checked_delete(ptr);
    }

    void reset(T * p = 0) 
    {
        ((p == 0 || p != ptr)?((void)0):__assert( "p == 0 || p != ptr" , "../boost/scoped_ptr.hpp", 82)); 
        this_type(p).swap(*this);
    }

    T & operator*() const 
    {
        ((ptr != 0)?((void)0):__assert( "ptr != 0" , "../boost/scoped_ptr.hpp", 88));
        return *ptr;
    }

    T * operator->() const 
    {
        ((ptr != 0)?((void)0):__assert( "ptr != 0" , "../boost/scoped_ptr.hpp", 94));
        return ptr;
    }

    T * get() const 
    {
        return ptr;
    }

    

#line 121 "../boost/scoped_ptr.hpp"
    typedef T * this_type::*unspecified_bool_type;

    operator unspecified_bool_type() const 
    {
        return ptr == 0? 0: &this_type::ptr;
    }



    bool operator! () const 
    {
        return ptr == 0;
    }

    void swap(scoped_ptr & b) 
    {
        T * tmp = b.ptr;
        b.ptr = ptr;
        ptr = tmp;
    }
};

template<class T> inline void swap(scoped_ptr<T> & a, scoped_ptr<T> & b) 
{
    a.swap(b);
}



template<class T> inline T * get_pointer(scoped_ptr<T> const & p)
{
    return p.get();
}

} 

#line 17 "smart_ptr.hpp"
#line 1 "../boost/scoped_array.hpp"













#line 1 "../boost/assert.hpp"
















#line 1 "/usr/include/assert.h"
 
#line 1 "/usr/include/internal/assert_core.h"
 











 
 
 

 
 
 

#ident "$Revision: 1.1 $"









 



extern "C" {







extern void __assert(const char *, const char *, int);
#line 50 "/usr/include/internal/assert_core.h"

}
#line 3 "/usr/include/assert.h"

#line 36 "../boost/assert.hpp"
#line 15 "../boost/scoped_array.hpp"





#line 1 "/usr/include/CC/cstddef"
#line 8 "/usr/include/CC/cstddef"




#line 21 "../boost/scoped_array.hpp"

namespace boost
{



#line 33 "../boost/scoped_array.hpp"





template<class T> class scoped_array 
{
private:

    T * ptr;

    scoped_array(scoped_array const &);
    scoped_array & operator=(scoped_array const &);

    typedef scoped_array<T> this_type;

public:

    typedef T element_type;

    explicit scoped_array(T * p = 0) : ptr(p) 
    {



    }

    ~scoped_array() 
    {



        boost::checked_array_delete(ptr);
    }

    void reset(T * p = 0) 
    {
        ((p == 0 || p != ptr)?((void)0):__assert( "p == 0 || p != ptr" , "../boost/scoped_array.hpp", 70)); 
        this_type(p).swap(*this);
    }

    T & operator[](std::ptrdiff_t i) const 
    {
        ((ptr != 0)?((void)0):__assert( "ptr != 0" , "../boost/scoped_array.hpp", 76));
        ((i >= 0)?((void)0):__assert( "i >= 0" , "../boost/scoped_array.hpp", 77));
        return ptr[i];
    }

    T * get() const 
    {
        return ptr;
    }

    

#line 104 "../boost/scoped_array.hpp"

    typedef T * this_type::*unspecified_bool_type;

    operator unspecified_bool_type() const 
    {
        return ptr == 0? 0: &this_type::ptr;
    }



    bool operator! () const 
    {
        return ptr == 0;
    }

    void swap(scoped_array & b) 
    {
        T * tmp = b.ptr;
        b.ptr = ptr;
        ptr = tmp;
    }

};

template<class T> inline void swap(scoped_array<T> & a, scoped_array<T> & b) 
{
    a.swap(b);
}

} 

#line 18 "smart_ptr.hpp"
#line 1 "../boost/shared_ptr.hpp"






















#line 1 "../boost/assert.hpp"
















#line 1 "/usr/include/assert.h"
 
#line 1 "/usr/include/internal/assert_core.h"
 











 
 
 

 
 
 

#ident "$Revision: 1.1 $"









 



extern "C" {







extern void __assert(const char *, const char *, int);
#line 50 "/usr/include/internal/assert_core.h"

}
#line 3 "/usr/include/assert.h"

#line 36 "../boost/assert.hpp"
#line 24 "../boost/shared_ptr.hpp"
#line 1 "../boost/throw_exception.hpp"



























namespace boost
{







template<class E> inline void throw_exception(E const & e)
{
    throw e;
}



} 

#line 26 "../boost/shared_ptr.hpp"
#line 1 "../boost/detail/shared_count.hpp"
























#line 1 "../boost/detail/bad_weak_ptr.hpp"

























namespace boost
{











class bad_weak_ptr: public std::exception
{
public:

    virtual char const * what() const throw()
    {
        return "boost::bad_weak_ptr";
    }
};





} 





#line 29 "../boost/detail/shared_count.hpp"
#line 1 "../boost/detail/sp_counted_base.hpp"





















#line 55 "../boost/detail/sp_counted_base.hpp"

#line 1 "../boost/detail/sp_counted_base_nt.hpp"




















#line 1 "/usr/include/CC/typeinfo"


 






 






 
namespace std {


  

 

  typedef bool _bool;




 
#pragma define_type_info
  class type_info {
  public:
    virtual ~type_info();
    _bool operator==(const type_info&) const;
    _bool operator!=(const type_info&) const;
    _bool before(const type_info&) const;
    const char* name() const;
  private:
    type_info& operator=(const type_info&);  
  protected:
    
    
    type_info(const type_info&); 
  };

  class bad_cast : public std::exception {
  public:
    bad_cast() throw();
    bad_cast(const bad_cast&) throw();
    bad_cast& operator=(const bad_cast&) throw();
    virtual ~bad_cast() throw();
    virtual const char* what() const throw();
  };

  class bad_typeid : public std::exception {
  public:
    bad_typeid() throw();
    bad_typeid(const bad_typeid&) throw();
    bad_typeid& operator=(const bad_typeid&) throw();
    virtual ~bad_typeid() throw();
    virtual const char* what() const throw();
  };


}   









#line 22 "../boost/detail/sp_counted_base_nt.hpp"

namespace boost
{

namespace detail
{

class sp_counted_base
{
private:

    sp_counted_base( sp_counted_base const & );
    sp_counted_base & operator= ( sp_counted_base const & );

    long use_count_;        
    long weak_count_;       

public:

    sp_counted_base(): use_count_( 1 ), weak_count_( 1 )
    {
    }

    virtual ~sp_counted_base() 
    {
    }

    
    

    virtual void dispose() = 0; 

    

    virtual void destroy() 
    {
        delete this;
    }

    virtual void * get_deleter( std::type_info const & ti ) = 0;

    void add_ref_copy()
    {
        ++use_count_;
    }

    bool add_ref_lock() 
    {
        if( use_count_ == 0 ) return false;
        ++use_count_;
        return true;
    }

    void release() 
    {
        if( --use_count_ == 0 )
        {
            dispose();
            weak_release();
        }
    }

    void weak_add_ref() 
    {
        ++weak_count_;
    }

    void weak_release() 
    {
        if( --weak_count_ == 0 )
        {
            destroy();
        }
    }

    long use_count() const 
    {
        return use_count_;
    }
};

} 

} 

#line 57 "../boost/detail/sp_counted_base.hpp"

#line 68 "../boost/detail/sp_counted_base.hpp"

#line 30 "../boost/detail/shared_count.hpp"
#line 1 "../boost/detail/sp_counted_impl.hpp"





































namespace boost
{

#line 47 "../boost/detail/sp_counted_impl.hpp"

namespace detail
{

template<class X> class sp_counted_impl_p: public sp_counted_base
{
private:

    X * px_;

    sp_counted_impl_p( sp_counted_impl_p const & );
    sp_counted_impl_p & operator= ( sp_counted_impl_p const & );

    typedef sp_counted_impl_p<X> this_type;

public:

    explicit sp_counted_impl_p( X * px ): px_( px )
    {



    }

    virtual void dispose() 
    {



        boost::checked_delete( px_ );
    }

    virtual void * get_deleter( std::type_info const & )
    {
        return 0;
    }

#line 97 "../boost/detail/sp_counted_impl.hpp"

#line 111 "../boost/detail/sp_counted_impl.hpp"
};








template<class P, class D> class sp_counted_impl_pd: public sp_counted_base
{
private:

    P ptr; 
    D del; 

    sp_counted_impl_pd( sp_counted_impl_pd const & );
    sp_counted_impl_pd & operator= ( sp_counted_impl_pd const & );

    typedef sp_counted_impl_pd<P, D> this_type;

public:

    

    sp_counted_impl_pd( P p, D d ): ptr(p), del(d)
    {
    }

    virtual void dispose() 
    {
        del( ptr );
    }

    virtual void * get_deleter( std::type_info const & ti )
    {
        return ti == typeid(D)? &del: 0;
    }

#line 163 "../boost/detail/sp_counted_impl.hpp"

#line 177 "../boost/detail/sp_counted_impl.hpp"
};





} 

} 

#line 31 "../boost/detail/shared_count.hpp"






namespace boost
{

namespace detail
{

#line 49 "../boost/detail/shared_count.hpp"

class weak_count;

class shared_count
{
private:

    sp_counted_base * pi_;





    friend class weak_count;

public:

    shared_count(): pi_(0) 



    {
    }

    template<class Y> explicit shared_count( Y * p ): pi_( 0 )



    {


        try
        {
            pi_ = new sp_counted_impl_p<Y>( p );
        }
        catch(...)
        {
            boost::checked_delete( p );
            throw;
        }

#line 101 "../boost/detail/shared_count.hpp"
    }

    template<class P, class D> shared_count(P p, D d): pi_(0)



    {


        try
        {
            pi_ = new sp_counted_impl_pd<P, D>(p, d);
        }
        catch(...)
        {
            d(p); 
            throw;
        }

#line 131 "../boost/detail/shared_count.hpp"
    }



    

    template<class Y>
    explicit shared_count( std::auto_ptr<Y> & r ): pi_( new sp_counted_impl_p<Y>( r.get() ) )



    {
#line 151 "../boost/detail/shared_count.hpp"

        r.release();
    }



    ~shared_count() 
    {
        if( pi_ != 0 ) pi_->release();



    }

    shared_count(shared_count const & r): pi_(r.pi_) 



    {
        if( pi_ != 0 ) pi_->add_ref_copy();
    }

    explicit shared_count(weak_count const & r); 

    shared_count & operator= (shared_count const & r) 
    {
        sp_counted_base * tmp = r.pi_;

        if( tmp != pi_ )
        {
            if( tmp != 0 ) tmp->add_ref_copy();
            if( pi_ != 0 ) pi_->release();
            pi_ = tmp;
        }

        return *this;
    }

    void swap(shared_count & r) 
    {
        sp_counted_base * tmp = r.pi_;
        r.pi_ = pi_;
        pi_ = tmp;
    }

    long use_count() const 
    {
        return pi_ != 0? pi_->use_count(): 0;
    }

    bool unique() const 
    {
        return use_count() == 1;
    }

    friend inline bool operator==(shared_count const & a, shared_count const & b)
    {
        return a.pi_ == b.pi_;
    }

    friend inline bool operator<(shared_count const & a, shared_count const & b)
    {
        return std::less<sp_counted_base *>()( a.pi_, b.pi_ );
    }

    void * get_deleter(std::type_info const & ti) const
    {
        return pi_? pi_->get_deleter( ti ): 0;
    }
};


class weak_count
{
private:

    sp_counted_base * pi_;





    friend class shared_count;

public:

    weak_count(): pi_(0) 



    {
    }

    weak_count(shared_count const & r): pi_(r.pi_) 



    {
        if(pi_ != 0) pi_->weak_add_ref();
    }

    weak_count(weak_count const & r): pi_(r.pi_) 



    {
        if(pi_ != 0) pi_->weak_add_ref();
    }

    ~weak_count() 
    {
        if(pi_ != 0) pi_->weak_release();



    }

    weak_count & operator= (shared_count const & r) 
    {
        sp_counted_base * tmp = r.pi_;
        if(tmp != 0) tmp->weak_add_ref();
        if(pi_ != 0) pi_->weak_release();
        pi_ = tmp;

        return *this;
    }

    weak_count & operator= (weak_count const & r) 
    {
        sp_counted_base * tmp = r.pi_;
        if(tmp != 0) tmp->weak_add_ref();
        if(pi_ != 0) pi_->weak_release();
        pi_ = tmp;

        return *this;
    }

    void swap(weak_count & r) 
    {
        sp_counted_base * tmp = r.pi_;
        r.pi_ = pi_;
        pi_ = tmp;
    }

    long use_count() const 
    {
        return pi_ != 0? pi_->use_count(): 0;
    }

    friend inline bool operator==(weak_count const & a, weak_count const & b)
    {
        return a.pi_ == b.pi_;
    }

    friend inline bool operator<(weak_count const & a, weak_count const & b)
    {
        return std::less<sp_counted_base *>()(a.pi_, b.pi_);
    }
};

inline shared_count::shared_count( weak_count const & r ): pi_( r.pi_ )



{
    if( pi_ == 0 || !pi_->add_ref_lock() )
    {
        boost::throw_exception( boost::bad_weak_ptr() );
    }
}

} 

} 





#line 27 "../boost/shared_ptr.hpp"


#line 1 "/usr/include/CC/algorithm"
























 




#line 1 "/usr/include/CC/stl_algo.h"
























 



 




#line 1 "/usr/include/CC/stl_heap.h"























 



 




namespace std {


#pragma set woff 1209




template <class _RandomAccessIterator, class _Distance, class _Tp>
void 
__push_heap(_RandomAccessIterator __first,
            _Distance __holeIndex, _Distance __topIndex, _Tp __value)
{
  _Distance __parent = (__holeIndex - 1) / 2;
  while (__holeIndex > __topIndex && *(__first + __parent) < __value) {
    *(__first + __holeIndex) = *(__first + __parent);
    __holeIndex = __parent;
    __parent = (__holeIndex - 1) / 2;
  }    
  *(__first + __holeIndex) = __value;
}

template <class _RandomAccessIterator, class _Distance, class _Tp>
inline void 
__push_heap_aux(_RandomAccessIterator __first,
                _RandomAccessIterator __last, _Distance*, _Tp*)
{
  __push_heap(__first, _Distance((__last - __first) - 1), _Distance(0), 
              _Tp(*(__last - 1)));
}

template <class _RandomAccessIterator>
inline void 
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
  __push_heap_aux(__first, __last,
                  __distance_type(__first), __value_type(__first));
}

template <class _RandomAccessIterator, class _Distance, class _Tp, 
          class _Compare>
void
__push_heap(_RandomAccessIterator __first, _Distance __holeIndex,
            _Distance __topIndex, _Tp __value, _Compare __comp)
{
  _Distance __parent = (__holeIndex - 1) / 2;
  while (__holeIndex > __topIndex && __comp(*(__first + __parent), __value)) {
    *(__first + __holeIndex) = *(__first + __parent);
    __holeIndex = __parent;
    __parent = (__holeIndex - 1) / 2;
  }
  *(__first + __holeIndex) = __value;
}

template <class _RandomAccessIterator, class _Compare,
          class _Distance, class _Tp>
inline void 
__push_heap_aux(_RandomAccessIterator __first,
                _RandomAccessIterator __last, _Compare __comp,
                _Distance*, _Tp*) 
{
  __push_heap(__first, _Distance((__last - __first) - 1), _Distance(0), 
              _Tp(*(__last - 1)), __comp);
}

template <class _RandomAccessIterator, class _Compare>
inline void 
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
          _Compare __comp)
{
  __push_heap_aux(__first, __last, __comp,
                  __distance_type(__first), __value_type(__first));
}

template <class _RandomAccessIterator, class _Distance, class _Tp>
void 
__adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex,
              _Distance __len, _Tp __value)
{
  _Distance __topIndex = __holeIndex;
  _Distance __secondChild = 2 * __holeIndex + 2;
  while (__secondChild < __len) {
    if (*(__first + __secondChild) < *(__first + (__secondChild - 1)))
      __secondChild--;
    *(__first + __holeIndex) = *(__first + __secondChild);
    __holeIndex = __secondChild;
    __secondChild = 2 * (__secondChild + 1);
  }
  if (__secondChild == __len) {
    *(__first + __holeIndex) = *(__first + (__secondChild - 1));
    __holeIndex = __secondChild - 1;
  }
  __push_heap(__first, __holeIndex, __topIndex, __value);
}

template <class _RandomAccessIterator, class _Tp, class _Distance>
inline void 
__pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
           _RandomAccessIterator __result, _Tp __value, _Distance*)
{
  *__result = *__first;
  __adjust_heap(__first, _Distance(0), _Distance(__last - __first), __value);
}

template <class _RandomAccessIterator, class _Tp>
inline void 
__pop_heap_aux(_RandomAccessIterator __first, _RandomAccessIterator __last,
               _Tp*)
{
  __pop_heap(__first, __last - 1, __last - 1, 
             _Tp(*(__last - 1)), __distance_type(__first));
}

template <class _RandomAccessIterator>
inline void pop_heap(_RandomAccessIterator __first, 
                     _RandomAccessIterator __last)
{
  __pop_heap_aux(__first, __last, __value_type(__first));
}

template <class _RandomAccessIterator, class _Distance,
          class _Tp, class _Compare>
void
__adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex,
              _Distance __len, _Tp __value, _Compare __comp)
{
  _Distance __topIndex = __holeIndex;
  _Distance __secondChild = 2 * __holeIndex + 2;
  while (__secondChild < __len) {
    if (__comp(*(__first + __secondChild), *(__first + (__secondChild - 1))))
      __secondChild--;
    *(__first + __holeIndex) = *(__first + __secondChild);
    __holeIndex = __secondChild;
    __secondChild = 2 * (__secondChild + 1);
  }
  if (__secondChild == __len) {
    *(__first + __holeIndex) = *(__first + (__secondChild - 1));
    __holeIndex = __secondChild - 1;
  }
  __push_heap(__first, __holeIndex, __topIndex, __value, __comp);
}

template <class _RandomAccessIterator, class _Tp, class _Compare, 
          class _Distance>
inline void 
__pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
           _RandomAccessIterator __result, _Tp __value, _Compare __comp,
           _Distance*)
{
  *__result = *__first;
  __adjust_heap(__first, _Distance(0), _Distance(__last - __first), 
                __value, __comp);
}

template <class _RandomAccessIterator, class _Tp, class _Compare>
inline void 
__pop_heap_aux(_RandomAccessIterator __first,
               _RandomAccessIterator __last, _Tp*, _Compare __comp)
{
  __pop_heap(__first, __last - 1, __last - 1, _Tp(*(__last - 1)), __comp,
             __distance_type(__first));
}

template <class _RandomAccessIterator, class _Compare>
inline void 
pop_heap(_RandomAccessIterator __first,
         _RandomAccessIterator __last, _Compare __comp)
{
    __pop_heap_aux(__first, __last, __value_type(__first), __comp);
}

template <class _RandomAccessIterator, class _Tp, class _Distance>
void 
__make_heap(_RandomAccessIterator __first,
            _RandomAccessIterator __last, _Tp*, _Distance*)
{
  if (__last - __first < 2) return;
  _Distance __len = __last - __first;
  _Distance __parent = (__len - 2)/2;
    
  for (;;) {
    __adjust_heap(__first, __parent, __len, _Tp(*(__first + __parent)));
    if (__parent == 0) return;
    __parent--;
  }
}

template <class _RandomAccessIterator>
inline void 
make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
  __make_heap(__first, __last,
              __value_type(__first), __distance_type(__first));
}

template <class _RandomAccessIterator, class _Compare,
          class _Tp, class _Distance>
void
__make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
            _Compare __comp, _Tp*, _Distance*)
{
  if (__last - __first < 2) return;
  _Distance __len = __last - __first;
  _Distance __parent = (__len - 2)/2;
    
  for (;;) {
    __adjust_heap(__first, __parent, __len, _Tp(*(__first + __parent)),
                  __comp);
    if (__parent == 0) return;
    __parent--;
  }
}

template <class _RandomAccessIterator, class _Compare>
inline void 
make_heap(_RandomAccessIterator __first, 
          _RandomAccessIterator __last, _Compare __comp)
{
  __make_heap(__first, __last, __comp,
              __value_type(__first), __distance_type(__first));
}

template <class _RandomAccessIterator>
void sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{
  while (__last - __first > 1)
    pop_heap(__first, __last--);
}

template <class _RandomAccessIterator, class _Compare>
void 
sort_heap(_RandomAccessIterator __first,
          _RandomAccessIterator __last, _Compare __comp)
{
  while (__last - __first > 1)
    pop_heap(__first, __last--, __comp);
}


#pragma reset woff 1209


}






#line 35 "/usr/include/CC/stl_algo.h"

namespace std {


#pragma set woff 1209




template <class _Tp>
inline const _Tp& __median(const _Tp& __a, const _Tp& __b, const _Tp& __c) {
  if (__a < __b)
    if (__b < __c)
      return __b;
    else if (__a < __c)
      return __c;
    else
      return __a;
  else if (__a < __c)
    return __a;
  else if (__b < __c)
    return __c;
  else
    return __b;
}

template <class _Tp, class _Compare>
inline const _Tp&
__median(const _Tp& __a, const _Tp& __b, const _Tp& __c, _Compare __comp) {
  if (__comp(__a, __b))
    if (__comp(__b, __c))
      return __b;
    else if (__comp(__a, __c))
      return __c;
    else
      return __a;
  else if (__comp(__a, __c))
    return __a;
  else if (__comp(__b, __c))
    return __c;
  else
    return __b;
}


template <class _InputIter, class _Function>
_Function for_each(_InputIter __first, _InputIter __last, _Function __f) {
  for ( ; __first != __last; ++__first)
    __f(*__first);
  return __f;
}



template <class _InputIter, class _Tp>
inline _InputIter __find(_InputIter __first, _InputIter __last,
                       const _Tp& __val,
                       input_iterator_tag)
{
  while (__first != __last && *__first != __val)
    ++__first;
  return __first;
}

template <class _InputIter, class _Predicate>
inline _InputIter __find_if(_InputIter __first, _InputIter __last,
                          _Predicate __pred,
                          input_iterator_tag)
{
  while (__first != __last && !__pred(*__first))
    ++__first;
  return __first;
}



template <class _RandomAccessIter, class _Tp>
_RandomAccessIter __find(_RandomAccessIter __first, _RandomAccessIter __last,
                       const _Tp& __val,
                       random_access_iterator_tag)
{
  typename iterator_traits<_RandomAccessIter>::difference_type __trip_count
    = (__last - __first) >> 2;

  for ( ; __trip_count > 0 ; --__trip_count) {
    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;
  }

  switch(__last - __first) {
  case 3:
    if (*__first == __val) return __first;
    ++__first;
  case 2:
    if (*__first == __val) return __first;
    ++__first;
  case 1:
    if (*__first == __val) return __first;
    ++__first;
  case 0:
  default:
    return __last;
  }
}

template <class _RandomAccessIter, class _Predicate>
_RandomAccessIter __find_if(_RandomAccessIter __first, 
                            _RandomAccessIter __last,
                            _Predicate __pred,
                            random_access_iterator_tag)
{
  typename iterator_traits<_RandomAccessIter>::difference_type __trip_count
    = (__last - __first) >> 2;

  for ( ; __trip_count > 0 ; --__trip_count) {
    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;
  }

  switch(__last - __first) {
  case 3:
    if (__pred(*__first)) return __first;
    ++__first;
  case 2:
    if (__pred(*__first)) return __first;
    ++__first;
  case 1:
    if (__pred(*__first)) return __first;
    ++__first;
  case 0:
  default:
    return __last;
  }
}



template <class _InputIter, class _Tp>
inline _InputIter find(_InputIter __first, _InputIter __last,
                       const _Tp& __val)
{
  return __find(__first, __last, __val, __iterator_category(__first));
}

template <class _InputIter, class _Predicate>
inline _InputIter find_if(_InputIter __first, _InputIter __last,
                          _Predicate __pred) {
  return __find_if(__first, __last, __pred, __iterator_category(__first));
}



template <class _ForwardIter>
_ForwardIter adjacent_find(_ForwardIter __first, _ForwardIter __last) {
  if (__first == __last)
    return __last;
  _ForwardIter __next = __first;
  while(++__next != __last) {
    if (*__first == *__next)
      return __first;
    __first = __next;
  }
  return __last;
}

template <class _ForwardIter, class _BinaryPredicate>
_ForwardIter adjacent_find(_ForwardIter __first, _ForwardIter __last,
                           _BinaryPredicate __binary_pred) {
  if (__first == __last)
    return __last;
  _ForwardIter __next = __first;
  while(++__next != __last) {
    if (__binary_pred(*__first, *__next))
      return __first;
    __first = __next;
  }
  return __last;
}







template <class _InputIter, class _Tp, class _Size>
void count(_InputIter __first, _InputIter __last, const _Tp& __value,
           _Size& __n) {
  for ( ; __first != __last; ++__first)
    if (*__first == __value)
      ++__n;
}

template <class _InputIter, class _Predicate, class _Size>
void count_if(_InputIter __first, _InputIter __last, _Predicate __pred,
              _Size& __n) {
  for ( ; __first != __last; ++__first)
    if (__pred(*__first))
      ++__n;
}



template <class _InputIter, class _Tp>
typename iterator_traits<_InputIter>::difference_type
count(_InputIter __first, _InputIter __last, const _Tp& __value) {
  typename iterator_traits<_InputIter>::difference_type __n = 0;
  for ( ; __first != __last; ++__first)
    if (*__first == __value)
      ++__n;
  return __n;
}

template <class _InputIter, class _Predicate>
typename iterator_traits<_InputIter>::difference_type
count_if(_InputIter __first, _InputIter __last, _Predicate __pred) {
  typename iterator_traits<_InputIter>::difference_type __n = 0;
  for ( ; __first != __last; ++__first)
    if (__pred(*__first))
      ++__n;
  return __n;
}






template <class _ForwardIter1, class _ForwardIter2>
_ForwardIter1 search(_ForwardIter1 __first1, _ForwardIter1 __last1,
                     _ForwardIter2 __first2, _ForwardIter2 __last2) 
{
  
  if (__first1 == __last1 || __first2 == __last2)
    return __first1;

  
  _ForwardIter2 __tmp(__first2);
  ++__tmp;
  if (__tmp == __last2)
    return find(__first1, __last1, *__first2);

  

  _ForwardIter2 __p1, __p;

  __p1 = __first2; ++__p1;

  _ForwardIter1 __current = __first1;

  while (__first1 != __last1) {
    __first1 = find(__first1, __last1, *__first2);
    if (__first1 == __last1)
      return __last1;

    __p = __p1;
    __current = __first1; 
    if (++__current == __last1)
      return __last1;

    while (*__current == *__p) {
      if (++__p == __last2)
        return __first1;
      if (++__current == __last1)
        return __last1;
    }

    ++__first1;
  }
  return __first1;
}

template <class _ForwardIter1, class _ForwardIter2, class _BinaryPred>
_ForwardIter1 search(_ForwardIter1 __first1, _ForwardIter1 __last1,
                     _ForwardIter2 __first2, _ForwardIter2 __last2,
                     _BinaryPred  __predicate) 
{
  
  if (__first1 == __last1 || __first2 == __last2)
    return __first1;

  
  _ForwardIter2 __tmp(__first2);
  ++__tmp;
  if (__tmp == __last2) {
    while (__first1 != __last1 && !__predicate(*__first1, *__first2))
      ++__first1;
    return __first1;    
  }

  

  _ForwardIter2 __p1, __p;

  __p1 = __first2; ++__p1;

  _ForwardIter1 __current = __first1;

  while (__first1 != __last1) {
    while (__first1 != __last1) {
      if (__predicate(*__first1, *__first2))
        break;
      ++__first1;
    }
    while (__first1 != __last1 && !__predicate(*__first1, *__first2))
      ++__first1;
    if (__first1 == __last1)
      return __last1;

    __p = __p1;
    __current = __first1; 
    if (++__current == __last1) return __last1;

    while (__predicate(*__current, *__p)) {
      if (++__p == __last2)
        return __first1;
      if (++__current == __last1)
        return __last1;
    }

    ++__first1;
  }
  return __first1;
}



template <class _ForwardIter, class _Integer, class _Tp>
_ForwardIter search_n(_ForwardIter __first, _ForwardIter __last,
                      _Integer __count, const _Tp& __val) {
  if (__count <= 0)
    return __first;
  else {
    __first = find(__first, __last, __val);
    while (__first != __last) {
      _Integer __n = __count - 1;
      _ForwardIter __i = __first;
      ++__i;
      while (__i != __last && __n != 0 && *__i == __val) {
        ++__i;
        --__n;
      }
      if (__n == 0)
        return __first;
      else
        __first = find(__i, __last, __val);
    }
    return __last;
  }
}

template <class _ForwardIter, class _Integer, class _Tp, class _BinaryPred>
_ForwardIter search_n(_ForwardIter __first, _ForwardIter __last,
                      _Integer __count, const _Tp& __val,
                      _BinaryPred __binary_pred) {
  if (__count <= 0)
    return __first;
  else {
    while (__first != __last) {
      if (__binary_pred(*__first, __val))
        break;
      ++__first;
    }
    while (__first != __last) {
      _Integer __n = __count - 1;
      _ForwardIter __i = __first;
      ++__i;
      while (__i != __last && __n != 0 && __binary_pred(*__i, __val)) {
        ++__i;
        --__n;
      }
      if (__n == 0)
        return __first;
      else {
        while (__i != __last) {
          if (__binary_pred(*__i, __val))
            break;
          ++__i;
        }
        __first = __i;
      }
    }
    return __last;
  }
} 



template <class _ForwardIter1, class _ForwardIter2>
_ForwardIter2 swap_ranges(_ForwardIter1 __first1, _ForwardIter1 __last1,
                          _ForwardIter2 __first2) {
  for ( ; __first1 != __last1; ++__first1, ++__first2)
    iter_swap(__first1, __first2);
  return __first2;
}



template <class _InputIter, class _OutputIter, class _UnaryOperation>
_OutputIter transform(_InputIter __first, _InputIter __last,
                      _OutputIter __result, _UnaryOperation __opr) {
  for ( ; __first != __last; ++__first, ++__result)
    *__result = __opr(*__first);
  return __result;
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _BinaryOperation>
_OutputIter transform(_InputIter1 __first1, _InputIter1 __last1,
                      _InputIter2 __first2, _OutputIter __result,
                      _BinaryOperation __binary_op) {
  for ( ; __first1 != __last1; ++__first1, ++__first2, ++__result)
    *__result = __binary_op(*__first1, *__first2);
  return __result;
}



template <class _ForwardIter, class _Tp>
void replace(_ForwardIter __first, _ForwardIter __last,
             const _Tp& __old_value, const _Tp& __new_value) {
  for ( ; __first != __last; ++__first)
    if (*__first == __old_value)
      *__first = __new_value;
}

template <class _ForwardIter, class _Predicate, class _Tp>
void replace_if(_ForwardIter __first, _ForwardIter __last,
                _Predicate __pred, const _Tp& __new_value) {
  for ( ; __first != __last; ++__first)
    if (__pred(*__first))
      *__first = __new_value;
}

template <class _InputIter, class _OutputIter, class _Tp>
_OutputIter replace_copy(_InputIter __first, _InputIter __last,
                         _OutputIter __result,
                         const _Tp& __old_value, const _Tp& __new_value) {
  for ( ; __first != __last; ++__first, ++__result)
    *__result = *__first == __old_value ? __new_value : *__first;
  return __result;
}

template <class Iterator, class _OutputIter, class _Predicate, class _Tp>
_OutputIter replace_copy_if(Iterator __first, Iterator __last,
                            _OutputIter __result,
                            _Predicate __pred, const _Tp& __new_value) {
  for ( ; __first != __last; ++__first, ++__result)
    *__result = __pred(*__first) ? __new_value : *__first;
  return __result;
}



template <class _ForwardIter, class _Generator>
void generate(_ForwardIter __first, _ForwardIter __last, _Generator __gen) {
  for ( ; __first != __last; ++__first)
    *__first = __gen();
}

template <class _OutputIter, class _Size, class _Generator>
_OutputIter generate_n(_OutputIter __first, _Size __n, _Generator __gen) {
  for ( ; __n > 0; --__n, ++__first)
    *__first = __gen();
  return __first;
}



template <class _InputIter, class _OutputIter, class _Tp>
_OutputIter remove_copy(_InputIter __first, _InputIter __last,
                        _OutputIter __result, const _Tp& __value) {
  for ( ; __first != __last; ++__first)
    if (*__first != __value) {
      *__result = *__first;
      ++__result;
    }
  return __result;
}

template <class _InputIter, class _OutputIter, class _Predicate>
_OutputIter remove_copy_if(_InputIter __first, _InputIter __last,
                           _OutputIter __result, _Predicate __pred) {
  for ( ; __first != __last; ++__first)
    if (!__pred(*__first)) {
      *__result = *__first;
      ++__result;
    }
  return __result;
}

template <class _ForwardIter, class _Tp>
_ForwardIter remove(_ForwardIter __first, _ForwardIter __last,
                    const _Tp& __value) {
  __first = find(__first, __last, __value);
  _ForwardIter __i = __first;
  return __first == __last ? __first 
                           : remove_copy(++__i, __last, __first, __value);
}

template <class _ForwardIter, class _Predicate>
_ForwardIter remove_if(_ForwardIter __first, _ForwardIter __last,
                       _Predicate __pred) {
  __first = find_if(__first, __last, __pred);
  _ForwardIter __i = __first;
  return __first == __last ? __first 
                           : remove_copy_if(++__i, __last, __first, __pred);
}



template <class _InputIter, class _OutputIter, class _Tp>
_OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result, _Tp*) {
  _Tp __value = *__first;
  *__result = __value;
  while (++__first != __last)
    if (__value != *__first) {
      __value = *__first;
      *++__result = __value;
    }
  return ++__result;
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                                 _OutputIter __result, 
                                 output_iterator_tag) {
  return __unique_copy(__first, __last, __result, __value_type(__first));
}

template <class _InputIter, class _ForwardIter>
_ForwardIter __unique_copy(_InputIter __first, _InputIter __last,
                           _ForwardIter __result, forward_iterator_tag) {
  *__result = *__first;
  while (++__first != __last)
    if (*__result != *__first) *++__result = *__first;
  return ++__result;
}

template <class _InputIter, class _OutputIter>
inline _OutputIter unique_copy(_InputIter __first, _InputIter __last,
                               _OutputIter __result) {
  if (__first == __last) return __result;
  return __unique_copy(__first, __last, __result,
                       __iterator_category(__result));
}

template <class _InputIter, class _OutputIter, class _BinaryPredicate,
          class _Tp>
_OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result,
                          _BinaryPredicate __binary_pred, _Tp*) {
  _Tp __value = *__first;
  *__result = __value;
  while (++__first != __last)
    if (!__binary_pred(__value, *__first)) {
      __value = *__first;
      *++__result = __value;
    }
  return ++__result;
}

template <class _InputIter, class _OutputIter, class _BinaryPredicate>
inline _OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                                 _OutputIter __result,
                                 _BinaryPredicate __binary_pred,
                                 output_iterator_tag) {
  return __unique_copy(__first, __last, __result, __binary_pred,
                       __value_type(__first));
}

template <class _InputIter, class _ForwardIter, class _BinaryPredicate>
_ForwardIter __unique_copy(_InputIter __first, _InputIter __last,
                           _ForwardIter __result, 
                           _BinaryPredicate __binary_pred,
                           forward_iterator_tag) {
  *__result = *__first;
  while (++__first != __last)
    if (!__binary_pred(*__result, *__first)) *++__result = *__first;
  return ++__result;
}

template <class _InputIter, class _OutputIter, class _BinaryPredicate>
inline _OutputIter unique_copy(_InputIter __first, _InputIter __last,
                               _OutputIter __result,
                               _BinaryPredicate __binary_pred) {
  if (__first == __last) return __result;
  return __unique_copy(__first, __last, __result, __binary_pred,
                       __iterator_category(__result));
}

template <class _ForwardIter>
_ForwardIter unique(_ForwardIter __first, _ForwardIter __last) {
  __first = adjacent_find(__first, __last);
  return unique_copy(__first, __last, __first);
}

template <class _ForwardIter, class _BinaryPredicate>
_ForwardIter unique(_ForwardIter __first, _ForwardIter __last,
                    _BinaryPredicate __binary_pred) {
  __first = adjacent_find(__first, __last, __binary_pred);
  return unique_copy(__first, __last, __first, __binary_pred);
}



template <class _FwdIter, class _Distance, class _Pointer>
void __reverse_adaptive(_FwdIter __first, _FwdIter __last,
   _Distance __len,
   _Pointer __buffer,
   _Distance __buffer_size)
{
  if (__len <= 1)
    return;
  if (__len <= __buffer_size)
    reverse_copy(__buffer, copy(__first, __last, __buffer), __first);
  else {
    _FwdIter __middle = __first;
    advance(__middle, __len/2);
    __reverse_adaptive(__first, __middle,
   __len/2, __buffer, __buffer_size);
    __reverse_adaptive(__middle, __last,
         __len - __len/2, __buffer, __buffer_size);
    rotate(__first, __middle, __last);
  }
}

template <class _FwdIter, class _Distance>
void __inplace_reverse(_FwdIter __first, _FwdIter __last, _Distance
__len)
{
  if (__len <= 1)
    return;
  _FwdIter __middle = __first;
  advance(__middle, __len/2);
  __inplace_reverse(__first, __middle, __len/2);

  __inplace_reverse(__middle, __last, __len - __len/2);
  rotate(__first, __middle, __last);
}

template <class _FwdIter>
void __reverse(_FwdIter __first, _FwdIter __last,
        forward_iterator_tag)
{
  typedef typename iterator_traits<_FwdIter>::value_type _Tp;
  typedef typename iterator_traits<_FwdIter>::difference_type _Distance;

  if (__first == __last)
    return;

  _Temporary_buffer<_FwdIter, _Tp> __buf(__first, __last);
  if (__buf.size() > 0)
    __reverse_adaptive(__first, __last,
         _Distance(__buf.requested_size()),
         __buf.begin(), __buf.size());
  else
    __inplace_reverse(__first, __last,
_Distance(__buf.requested_size()));
}

template <class _BidirectionalIter>
void __reverse(_BidirectionalIter __first, _BidirectionalIter __last, 
               bidirectional_iterator_tag) {
  for (;;)
    if (__first == __last || __first == --__last)
      return;
    else
      iter_swap(__first++, __last);
}

template <class _RandomAccessIter>
void __reverse(_RandomAccessIter __first, _RandomAccessIter __last,
               random_access_iterator_tag) {
  while (__first < __last)
    iter_swap(__first++, --__last);
}

template <class _ForwardIter>
inline void reverse(_ForwardIter __first, _ForwardIter __last) {
  __reverse(__first, __last, __iterator_category(__first));
}

template <class _BidirectionalIter, class _OutputIter>
_OutputIter reverse_copy(_BidirectionalIter __first,
                            _BidirectionalIter __last,
                            _OutputIter __result) {
  while (__first != __last) {
    --__last;
    *__result = *__last;
    ++__result;
  }
  return __result;
}



template <class _EuclideanRingElement>
_EuclideanRingElement __gcd(_EuclideanRingElement __m,
                            _EuclideanRingElement __n)
{
  while (__n != 0) {
    _EuclideanRingElement __t = __m % __n;
    __m = __n;
    __n = __t;
  }
  return __m;
}

template <class _ForwardIter, class _Distance>
_ForwardIter __rotate(_ForwardIter __first,
                      _ForwardIter __middle,
                      _ForwardIter __last,
                      _Distance*,
                      forward_iterator_tag) {
  if (__first == __middle)
    return __last;
  if (__last  == __middle)
    return __first;

  _ForwardIter __first2 = __middle;
  do {
    swap(*__first++, *__first2++);
    if (__first == __middle)
      __middle = __first2;
  } while (__first2 != __last);

  _ForwardIter __new_middle = __first;

  __first2 = __middle;

  while (__first2 != __last) {
    swap (*__first++, *__first2++);
    if (__first == __middle)
      __middle = __first2;
    else if (__first2 == __last)
      __first2 = __middle;
  }

  return __new_middle;
}


template <class _BidirectionalIter, class _Distance>
_BidirectionalIter __rotate(_BidirectionalIter __first,
                            _BidirectionalIter __middle,
                            _BidirectionalIter __last,
                            _Distance*,
                            bidirectional_iterator_tag) {
  if (__first == __middle)
    return __last;
  if (__last  == __middle)
    return __first;

  __reverse(__first,  __middle, bidirectional_iterator_tag());
  __reverse(__middle, __last,   bidirectional_iterator_tag());

  while (__first != __middle && __middle != __last)
    swap (*__first++, *--__last);

  if (__first == __middle) {
    __reverse(__middle, __last,   bidirectional_iterator_tag());
    return __last;
  }
  else {
    __reverse(__first,  __middle, bidirectional_iterator_tag());
    return __first;
  }
}

template <class _RandomAccessIter, class _Distance, class _Tp>
_RandomAccessIter __rotate(_RandomAccessIter __first,
                           _RandomAccessIter __middle,
                           _RandomAccessIter __last,
                           _Distance *, _Tp *) {

  _Distance __n = __last   - __first;
  _Distance __k = __middle - __first;
  _Distance __l = __n - __k;
  _RandomAccessIter __result = __first + (__last - __middle);

  if (__k == 0)
    return __last;

  else if (__k == __l) {
    swap_ranges(__first, __middle, __middle);
    return __result;
  }

  _Distance __d = __gcd(__n, __k);

  for (_Distance __i = 0; __i < __d; __i++) {
    _Tp __tmp = *__first;
    _RandomAccessIter __p = __first;

    if (__k < __l) {
      for (_Distance __j = 0; __j < __l/__d; __j++) {
        if (__p > __first + __l) {
          *__p = *(__p - __l);
          __p -= __l;
        }

        *__p = *(__p + __k);
        __p += __k;
      }
    }

    else {
      for (_Distance __j = 0; __j < __k/__d - 1; __j ++) {
        if (__p < __last - __k) {
          *__p = *(__p + __k);
          __p += __k;
        }

        *__p = * (__p - __l);
        __p -= __l;
      }
    }

    *__p = __tmp;
    ++__first;
  }

  return __result;
}

template <class _ForwardIter>
inline _ForwardIter rotate(_ForwardIter __first, _ForwardIter __middle,
                           _ForwardIter __last) {
  return __rotate(__first, __middle, __last,
                  __distance_type(__first),
                  __iterator_category(__first));
}

template <class _ForwardIter, class _OutputIter>
_OutputIter rotate_copy(_ForwardIter __first, _ForwardIter __middle,
                            _ForwardIter __last, _OutputIter __result) {
  return copy(__first, __middle, copy(__middle, __last, __result));
}





template <class _Distance>
inline _Distance __random_number(_Distance __n) {



  return lrand48() % __n;

}



template <class _Distance>
struct __default_rng {
  _Distance operator() (_Distance __n) {return __random_number(__n);}
};

template <class _Tp, class _Distance,
	  class _RandomNumberGenerator = __default_rng<_Distance> >
struct __random_predicate {
  bool operator()(_Tp) {return _RandomNumberGenerator()(2);}
};

template <class _ForwardIter,
	  class _RandomNumberGenerator,
          class _Distance, class _Pointer>
void __random_shuffle_adaptive (_ForwardIter           __first,
				       _ForwardIter           __last,
				       _RandomNumberGenerator __rand,
				       _Distance	      __len,
				       _Pointer		      __buffer,
				       _Distance	      __buffer_size) {
  typedef typename iterator_traits<_ForwardIter>::value_type _Tp;

  if (__len <= 1)
    return;
  if (__len == 2) {
    if (__rand(2)) {
      _ForwardIter __next = __first;
      ++__next;
      iter_swap(__first, __next);
    }
    return;
  }

  if (__len <= __buffer_size) {
    copy(__first, __last, __buffer);
    __random_shuffle(__buffer, __buffer+__len, __rand,
	             random_access_iterator_tag());
    copy(__buffer, __buffer+__len, __first);
  }
  else {
    _ForwardIter
      __mid = partition(__first, __last,
	                __random_predicate<_Tp, _Distance,
					   _RandomNumberGenerator>());
      _Distance __len1 = distance(__first, __mid);
      _Distance __len2 = distance(__mid, __last);
      if (__len1 < __len2) {
        __random_shuffle_adaptive(__first, __mid, __rand, __len1,
				  __buffer, __buffer_size);
        __random_shuffle_adaptive(__mid, __last, __rand, __len2,
				  __buffer, __buffer_size);
      }
      else {
        __random_shuffle_adaptive(__mid,  __last, __rand, __len2,
				  __buffer, __buffer_size);
        __random_shuffle_adaptive(__first, __mid, __rand, __len1,
				  __buffer, __buffer_size);
      }
  }
}

template <class _ForwardIter, class _RandomNumberGenerator>
void __random_shuffle(_ForwardIter __first, _ForwardIter __last,
	               _RandomNumberGenerator __rand,
		       forward_iterator_tag) {
  typedef typename iterator_traits<_ForwardIter>::value_type      _Tp;
  typedef typename iterator_traits<_ForwardIter>::difference_type _Distance;

  if (__first == __last)
    return;

  _Temporary_buffer<_ForwardIter, _Tp> __buf(__first, __last);
  __random_shuffle_adaptive(__first, __last, __rand,
		            __buf.requested_size(),
			    __buf.begin(), __buf.size());
}

template <class _RandomAccessIter, class _RandomNumberGenerator>
void __random_shuffle(_RandomAccessIter __first, _RandomAccessIter __last,
		      _RandomNumberGenerator __rand,
		      random_access_iterator_tag) {
  typedef typename iterator_traits<_RandomAccessIter>::difference_type _Dist;
  _RandomAccessIter __next = __first; ++__next;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i) {
    iter_swap(__i, __first + (_Dist) __rand((__i - __first) + 1));
  }
}

template <class _ForwardIter>
inline void random_shuffle(_ForwardIter __first, _ForwardIter __last) {
  typedef typename iterator_traits<_ForwardIter>::iterator_category _Cat;
  __random_shuffle(__first, __last, __default_rng<long>(), _Cat());
}
	           
template <class _ForwardIter, class _RandomNumberGenerator>
inline void random_shuffle(_ForwardIter __first, _ForwardIter __last,
                           _RandomNumberGenerator __rand) {
  typedef typename iterator_traits<_ForwardIter>::iterator_category _Cat;
  __random_shuffle(__first, __last, __rand, _Cat());
}



template <class _ForwardIter, class _OutputIter, class _Distance>
_OutputIter random_sample_n(_ForwardIter __first, _ForwardIter __last,
                            _OutputIter __out, const _Distance __n)
{
  _Distance __remaining = 0;
  distance(__first, __last, __remaining);
  _Distance __m = min(__n, __remaining);

  while (__m > 0) {
    if (__random_number(__remaining) < __m) {
      *__out = *__first;
      ++__out;
      --__m;
    }

    --__remaining;
    ++__first;
  }
  return __out;
}

template <class _ForwardIter, class _OutputIter, class _Distance,
          class _RandomNumberGenerator>
_OutputIter random_sample_n(_ForwardIter __first, _ForwardIter __last,
                            _OutputIter __out, const _Distance __n,
                            _RandomNumberGenerator& __rand)
{
  _Distance __remaining = 0;
  distance(__first, __last, __remaining);
  _Distance __m = min(__n, __remaining);

  while (__m > 0) {
    if (__rand(__remaining) < __m) {
      *__out = *__first;
      ++__out;
      --__m;
    }

    --__remaining;
    ++__first;
  }
  return __out;
}

template <class _InputIter, class _RandomAccessIter, class _Distance>
_RandomAccessIter __random_sample(_InputIter __first, _InputIter __last,
                                  _RandomAccessIter __out,
                                  const _Distance __n)
{
  _Distance __m = 0;
  _Distance __t = __n;
  for ( ; __first != __last && __m < __n; ++__m, ++__first) 
    __out[__m] = *__first;

  while (__first != __last) {
    ++__t;
    _Distance __M = __random_number(__t);
    if (__M < __n)
      __out[__M] = *__first;
    ++__first;
  }

  return __out + __m;
}

template <class _InputIter, class _RandomAccessIter,
          class _RandomNumberGenerator, class _Distance>
_RandomAccessIter __random_sample(_InputIter __first, _InputIter __last,
                                  _RandomAccessIter __out,
                                  _RandomNumberGenerator& __rand,
                                  const _Distance __n)
{
  _Distance __m = 0;
  _Distance __t = __n;
  for ( ; __first != __last && __m < __n; ++__m, ++__first)
    __out[__m] = *__first;

  while (__first != __last) {
    ++__t;
    _Distance __M = __rand(__t);
    if (__M < __n)
      __out[__M] = *__first;
    ++__first;
  }

  return __out + __m;
}

template <class _InputIter, class _RandomAccessIter>
inline _RandomAccessIter
random_sample(_InputIter __first, _InputIter __last,
              _RandomAccessIter __out_first, _RandomAccessIter __out_last) 
{
  return __random_sample(__first, __last,
                         __out_first, __out_last - __out_first);
}


template <class _InputIter, class _RandomAccessIter, 
          class _RandomNumberGenerator>
inline _RandomAccessIter
random_sample(_InputIter __first, _InputIter __last,
              _RandomAccessIter __out_first, _RandomAccessIter __out_last,
              _RandomNumberGenerator& __rand) 
{
  return __random_sample(__first, __last,
                         __out_first, __rand,
                         __out_last - __out_first);
}



template <class _ForwardIter, class _Predicate>
_ForwardIter __partition(_ForwardIter __first,
		         _ForwardIter __last,
			 _Predicate   __pred,
			 forward_iterator_tag) {
  if (__first == __last) return __first;

  while (__pred(*__first))
    if (++__first == __last) return __first;

  _ForwardIter __next = __first;

  while (++__next != __last)
    if (__pred(*__next)) {
      swap(*__first, *__next);
      ++__first;
    }

  return __first;
}

template <class _BidirectionalIter, class _Predicate>
_BidirectionalIter __partition(_BidirectionalIter __first,
                               _BidirectionalIter __last,
			       _Predicate __pred,
			       bidirectional_iterator_tag) {
  for (;;) {
    for (;;)
      if (__first == __last)
        return __first;
      else if (__pred(*__first))
        ++__first;
      else
        break;
    --__last;
    for (;;)
      if (__first == __last)
        return __first;
      else if (!__pred(*__last))
        --__last;
      else
        break;
    iter_swap(__first, __last);
    ++__first;
  }
}

template <class _ForwardIter, class _Predicate>
inline _ForwardIter partition(_ForwardIter __first,
   			      _ForwardIter __last,
			      _Predicate   __pred) {
  return __partition(__first, __last, __pred, __iterator_category(__first));
}


template <class _ForwardIter, class _Predicate, class _Distance>
_ForwardIter __inplace_stable_partition(_ForwardIter __first,
                                        _ForwardIter __last,
                                        _Predicate __pred, _Distance __len) {
  if (__len == 1)
    return __pred(*__first) ? __last : __first;
  _ForwardIter __middle = __first;
  advance(__middle, __len / 2);
  return rotate(__inplace_stable_partition(__first, __middle, __pred, 
                                           __len / 2),
                __middle,
                __inplace_stable_partition(__middle, __last, __pred,
                                           __len - __len / 2));
}

template <class _ForwardIter, class _Pointer, class _Predicate, 
          class _Distance>
_ForwardIter __stable_partition_adaptive(_ForwardIter __first,
                                         _ForwardIter __last,
                                         _Predicate __pred, _Distance __len,
                                         _Pointer __buffer,
                                         _Distance __buffer_size) 
{
  if (__len <= __buffer_size) {
    _ForwardIter __result1 = __first;
    _Pointer __result2 = __buffer;
    for ( ; __first != __last ; ++__first)
      if (__pred(*__first)) {
        *__result1 = *__first;
        ++__result1;
      }
      else {
        *__result2 = *__first;
        ++__result2;
      }
    copy(__buffer, __result2, __result1);
    return __result1;
  }
  else {
    _ForwardIter __middle = __first;
    advance(__middle, __len / 2);
    return rotate(__stable_partition_adaptive(
                          __first, __middle, __pred,
                          __len / 2, __buffer, __buffer_size),
                    __middle,
                    __stable_partition_adaptive(
                          __middle, __last, __pred,
                          __len - __len / 2, __buffer, __buffer_size));
  }
}

template <class _ForwardIter, class _Predicate, class _Tp, class _Distance>
inline _ForwardIter
__stable_partition_aux(_ForwardIter __first, _ForwardIter __last, 
                       _Predicate __pred, _Tp*, _Distance*)
{
  _Temporary_buffer<_ForwardIter, _Tp> __buf(__first, __last);
  if (__buf.size() > 0)
    return __stable_partition_adaptive(__first, __last, __pred,
                                       _Distance(__buf.requested_size()),
                                       __buf.begin(), _Distance(__buf.size()));
  else
    return __inplace_stable_partition(__first, __last, __pred, 
                                      _Distance(__buf.requested_size()));
}

template <class _ForwardIter, class _Predicate>
inline _ForwardIter stable_partition(_ForwardIter __first,
                                     _ForwardIter __last, 
                                     _Predicate __pred) {
  if (__first == __last)
    return __first;
  else
    return __stable_partition_aux(__first, __last, __pred,
                                  __value_type(__first),
                                  __distance_type(__first));
}

template <class _RandomAccessIter, class _Tp>
_RandomAccessIter __unguarded_partition(_RandomAccessIter __first, 
                                        _RandomAccessIter __last, 
                                        _Tp __pivot) 
{
  for (;;) {
    while (*__first < __pivot)
      ++__first;
    --__last;
    while (__pivot < *__last)
      --__last;
    if (!(__first < __last))
      return __first;
    iter_swap(__first, __last);
    ++__first;
  }
}    

template <class _RandomAccessIter, class _Tp, class _Compare>
_RandomAccessIter __unguarded_partition(_RandomAccessIter __first, 
                                        _RandomAccessIter __last, 
                                        _Tp __pivot, _Compare __comp) 
{
  for (;;) {
    while (__comp(*__first, __pivot))
      ++__first;
    --__last;
    while (__comp(__pivot, *__last))
      --__last;
    if (!(__first < __last))
      return __first;
    iter_swap(__first, __last);
    ++__first;
  }
}

const int __stl_threshold = 16;



template <class _RandomAccessIter, class _Tp>
void __unguarded_linear_insert(_RandomAccessIter __last, _Tp __val) {
  _RandomAccessIter __next = __last;
  --__next;
  while (__val < *__next) {
    *__last = *__next;
    __last = __next;
    --__next;
  }
  *__last = __val;
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __unguarded_linear_insert(_RandomAccessIter __last, _Tp __val, 
                               _Compare __comp) {
  _RandomAccessIter __next = __last;
  --__next;  
  while (__comp(__val, *__next)) {
    *__last = *__next;
    __last = __next;
    --__next;
  }
  *__last = __val;
}

template <class _RandomAccessIter, class _Tp>
inline void __linear_insert(_RandomAccessIter __first, 
                            _RandomAccessIter __last, _Tp*) {
  _Tp __val = *__last;
  if (__val < *__first) {
    copy_backward(__first, __last, __last + 1);
    *__first = __val;
  }
  else
    __unguarded_linear_insert(__last, __val);
}

template <class _RandomAccessIter, class _Tp, class _Compare>
inline void __linear_insert(_RandomAccessIter __first, 
                            _RandomAccessIter __last, _Tp*, _Compare __comp) {
  _Tp __val = *__last;
  if (__comp(__val, *__first)) {
    copy_backward(__first, __last, __last + 1);
    *__first = __val;
  }
  else
    __unguarded_linear_insert(__last, __val, __comp);
}

template <class _RandomAccessIter>
void __insertion_sort(_RandomAccessIter __first, _RandomAccessIter __last) {
  if (__first == __last) return; 
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    __linear_insert(__first, __i, __value_type(__first));
}

template <class _RandomAccessIter, class _Compare>
void __insertion_sort(_RandomAccessIter __first,
                      _RandomAccessIter __last, _Compare __comp) {
  if (__first == __last) return;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    __linear_insert(__first, __i, __value_type(__first), __comp);
}

template <class _RandomAccessIter, class _Tp>
void __unguarded_insertion_sort_aux(_RandomAccessIter __first, 
                                    _RandomAccessIter __last, _Tp*) {
  for (_RandomAccessIter __i = __first; __i != __last; ++__i)
    __unguarded_linear_insert(__i, _Tp(*__i));
}

template <class _RandomAccessIter>
inline void __unguarded_insertion_sort(_RandomAccessIter __first, 
                                _RandomAccessIter __last) {
  __unguarded_insertion_sort_aux(__first, __last, __value_type(__first));
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __unguarded_insertion_sort_aux(_RandomAccessIter __first, 
                                    _RandomAccessIter __last,
                                    _Tp*, _Compare __comp) {
  for (_RandomAccessIter __i = __first; __i != __last; ++__i)
    __unguarded_linear_insert(__i, _Tp(*__i), __comp);
}

template <class _RandomAccessIter, class _Compare>
inline void __unguarded_insertion_sort(_RandomAccessIter __first, 
                                       _RandomAccessIter __last,
                                       _Compare __comp) {
  __unguarded_insertion_sort_aux(__first, __last, __value_type(__first),
                                 __comp);
}

template <class _RandomAccessIter>
void __final_insertion_sort(_RandomAccessIter __first, 
                            _RandomAccessIter __last) {
  if (__last - __first > __stl_threshold) {
    __insertion_sort(__first, __first + __stl_threshold);
    __unguarded_insertion_sort(__first + __stl_threshold, __last);
  }
  else
    __insertion_sort(__first, __last);
}

template <class _RandomAccessIter, class _Compare>
void __final_insertion_sort(_RandomAccessIter __first, 
                            _RandomAccessIter __last, _Compare __comp) {
  if (__last - __first > __stl_threshold) {
    __insertion_sort(__first, __first + __stl_threshold, __comp);
    __unguarded_insertion_sort(__first + __stl_threshold, __last, __comp);
  }
  else
    __insertion_sort(__first, __last, __comp);
}

template <class _Size>
inline _Size __lg(_Size __n) {
  _Size __k;
  for (__k = 0; __n != 1; __n >>= 1) ++__k;
  return __k;
}

template <class _RandomAccessIter, class _Tp, class _Size>
void __introsort_loop(_RandomAccessIter __first,
                      _RandomAccessIter __last, _Tp*,
                      _Size __depth_limit)
{
  while (__last - __first > __stl_threshold) {
    if (__depth_limit == 0) {
      partial_sort(__first, __last, __last);
      return;
    }
    --__depth_limit;
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1))));
    __introsort_loop(__cut, __last, (_Tp*) 0, __depth_limit);
    __last = __cut;
  }
}

template <class _RandomAccessIter, class _Tp, class _Size, class _Compare>
void __introsort_loop(_RandomAccessIter __first,
                      _RandomAccessIter __last, _Tp*,
                      _Size __depth_limit, _Compare __comp)
{
  while (__last - __first > __stl_threshold) {
    if (__depth_limit == 0) {
      partial_sort(__first, __last, __last, __comp);
      return;
    }
    --__depth_limit;
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1), __comp)),
       __comp);
    __introsort_loop(__cut, __last, (_Tp*) 0, __depth_limit, __comp);
    __last = __cut;
  }
}

template <class _RandomAccessIter>
inline void sort(_RandomAccessIter __first, _RandomAccessIter __last) {
  if (__first != __last) {
    __introsort_loop(__first, __last,
                     __value_type(__first),
                     __lg(__last - __first) * 2);
    __final_insertion_sort(__first, __last);
  }
}

template <class _RandomAccessIter, class _Compare>
inline void sort(_RandomAccessIter __first, _RandomAccessIter __last,
                 _Compare __comp) {
  if (__first != __last) {
    __introsort_loop(__first, __last,
                     __value_type(__first),
                     __lg(__last - __first) * 2,
                     __comp);
    __final_insertion_sort(__first, __last, __comp);
  }
}



template <class _RandomAccessIter>
void __inplace_stable_sort(_RandomAccessIter __first,
                           _RandomAccessIter __last) {
  if (__last - __first < 15) {
    __insertion_sort(__first, __last);
    return;
  }
  _RandomAccessIter __middle = __first + (__last - __first) / 2;
  __inplace_stable_sort(__first, __middle);
  __inplace_stable_sort(__middle, __last);
  __merge_without_buffer(__first, __middle, __last,
                         __middle - __first,
                         __last - __middle);
}

template <class _RandomAccessIter, class _Compare>
void __inplace_stable_sort(_RandomAccessIter __first,
                           _RandomAccessIter __last, _Compare __comp) {
  if (__last - __first < 15) {
    __insertion_sort(__first, __last, __comp);
    return;
  }
  _RandomAccessIter __middle = __first + (__last - __first) / 2;
  __inplace_stable_sort(__first, __middle, __comp);
  __inplace_stable_sort(__middle, __last, __comp);
  __merge_without_buffer(__first, __middle, __last,
                         __middle - __first,
                         __last - __middle,
                         __comp);
}

template <class _RandomAccessIter1, class _RandomAccessIter2,
          class _Distance>
void __merge_sort_loop(_RandomAccessIter1 __first,
                       _RandomAccessIter1 __last, 
                       _RandomAccessIter2 __result, _Distance __step_size) {
  _Distance __two_step = 2 * __step_size;

  while (__last - __first >= __two_step) {
    __result = merge(__first, __first + __step_size,
                     __first + __step_size, __first + __two_step,
                     __result);
    __first += __two_step;
  }

  __step_size = min(_Distance(__last - __first), __step_size);
  merge(__first, __first + __step_size, __first + __step_size, __last,
        __result);
}

template <class _RandomAccessIter1, class _RandomAccessIter2,
          class _Distance, class _Compare>
void __merge_sort_loop(_RandomAccessIter1 __first,
                       _RandomAccessIter1 __last, 
                       _RandomAccessIter2 __result, _Distance __step_size,
                       _Compare __comp) {
  _Distance __two_step = 2 * __step_size;

  while (__last - __first >= __two_step) {
    __result = merge(__first, __first + __step_size,
                     __first + __step_size, __first + __two_step,
                     __result,
                     __comp);
    __first += __two_step;
  }
  __step_size = min(_Distance(__last - __first), __step_size);

  merge(__first, __first + __step_size,
        __first + __step_size, __last,
        __result,
        __comp);
}

const int __stl_chunk_size = 7;
        
template <class _RandomAccessIter, class _Distance>
void __chunk_insertion_sort(_RandomAccessIter __first, 
                            _RandomAccessIter __last, _Distance __chunk_size)
{
  while (__last - __first >= __chunk_size) {
    __insertion_sort(__first, __first + __chunk_size);
    __first += __chunk_size;
  }
  __insertion_sort(__first, __last);
}

template <class _RandomAccessIter, class _Distance, class _Compare>
void __chunk_insertion_sort(_RandomAccessIter __first, 
                            _RandomAccessIter __last,
                            _Distance __chunk_size, _Compare __comp)
{
  while (__last - __first >= __chunk_size) {
    __insertion_sort(__first, __first + __chunk_size, __comp);
    __first += __chunk_size;
  }
  __insertion_sort(__first, __last, __comp);
}

template <class _RandomAccessIter, class _Pointer, class _Distance>
void __merge_sort_with_buffer(_RandomAccessIter __first, 
                              _RandomAccessIter __last,
                              _Pointer __buffer, _Distance*) {
  _Distance __len = __last - __first;
  _Pointer __buffer_last = __buffer + __len;

  _Distance __step_size = __stl_chunk_size;
  __chunk_insertion_sort(__first, __last, __step_size);

  while (__step_size < __len) {
    __merge_sort_loop(__first, __last, __buffer, __step_size);
    __step_size *= 2;
    __merge_sort_loop(__buffer, __buffer_last, __first, __step_size);
    __step_size *= 2;
  }
}

template <class _RandomAccessIter, class _Pointer, class _Distance,
          class _Compare>
void __merge_sort_with_buffer(_RandomAccessIter __first, 
                              _RandomAccessIter __last, _Pointer __buffer,
                              _Distance*, _Compare __comp) {
  _Distance __len = __last - __first;
  _Pointer __buffer_last = __buffer + __len;

  _Distance __step_size = __stl_chunk_size;
  __chunk_insertion_sort(__first, __last, __step_size, __comp);

  while (__step_size < __len) {
    __merge_sort_loop(__first, __last, __buffer, __step_size, __comp);
    __step_size *= 2;
    __merge_sort_loop(__buffer, __buffer_last, __first, __step_size, __comp);
    __step_size *= 2;
  }
}

template <class _RandomAccessIter, class _Pointer, class _Distance>
void __stable_sort_adaptive(_RandomAccessIter __first, 
                            _RandomAccessIter __last, _Pointer __buffer,
                            _Distance __buffer_size) {
  _Distance __len = (__last - __first + 1) / 2;
  _RandomAccessIter __middle = __first + __len;
  if (__len > __buffer_size) {
    __stable_sort_adaptive(__first, __middle, __buffer, __buffer_size);
    __stable_sort_adaptive(__middle, __last, __buffer, __buffer_size);
  }
  else {
    __merge_sort_with_buffer(__first, __middle, __buffer, (_Distance*)0);
    __merge_sort_with_buffer(__middle, __last, __buffer, (_Distance*)0);
  }
  __merge_adaptive(__first, __middle, __last, _Distance(__middle - __first), 
                   _Distance(__last - __middle), __buffer, __buffer_size);
}

template <class _RandomAccessIter, class _Pointer, class _Distance, 
          class _Compare>
void __stable_sort_adaptive(_RandomAccessIter __first, 
                            _RandomAccessIter __last, _Pointer __buffer,
                            _Distance __buffer_size, _Compare __comp) {
  _Distance __len = (__last - __first + 1) / 2;
  _RandomAccessIter __middle = __first + __len;
  if (__len > __buffer_size) {
    __stable_sort_adaptive(__first, __middle, __buffer, __buffer_size, 
                           __comp);
    __stable_sort_adaptive(__middle, __last, __buffer, __buffer_size, 
                           __comp);
  }
  else {
    __merge_sort_with_buffer(__first, __middle, __buffer, (_Distance*)0,
                               __comp);
    __merge_sort_with_buffer(__middle, __last, __buffer, (_Distance*)0,
                               __comp);
  }
  __merge_adaptive(__first, __middle, __last, _Distance(__middle - __first), 
                   _Distance(__last - __middle), __buffer, __buffer_size,
                   __comp);
}

template <class _RandomAccessIter, class _Tp, class _Distance>
inline void __stable_sort_aux(_RandomAccessIter __first,
                              _RandomAccessIter __last, _Tp*, _Distance*) {
  _Temporary_buffer<_RandomAccessIter, _Tp> buf(__first, __last);
  if (buf.begin() == 0)
    __inplace_stable_sort(__first, __last);
  else 
    __stable_sort_adaptive(__first, __last, buf.begin(),
                           _Distance(buf.size()));
}

template <class _RandomAccessIter, class _Tp, class _Distance, class _Compare>
inline void __stable_sort_aux(_RandomAccessIter __first,
                              _RandomAccessIter __last, _Tp*, _Distance*,
                              _Compare __comp) {
  _Temporary_buffer<_RandomAccessIter, _Tp> buf(__first, __last);
  if (buf.begin() == 0)
    __inplace_stable_sort(__first, __last, __comp);
  else 
    __stable_sort_adaptive(__first, __last, buf.begin(),
                           _Distance(buf.size()),
                           __comp);
}

template <class _RandomAccessIter>
inline void stable_sort(_RandomAccessIter __first,
                        _RandomAccessIter __last) {
  __stable_sort_aux(__first, __last,
                    __value_type(__first),
                    __distance_type(__first));
}

template <class _RandomAccessIter, class _Compare>
inline void stable_sort(_RandomAccessIter __first,
                        _RandomAccessIter __last, _Compare __comp) {
  __stable_sort_aux(__first, __last,
                    __value_type(__first),
                    __distance_type(__first), 
                    __comp);
}



template <class _RandomAccessIter, class _Tp>
void __partial_sort(_RandomAccessIter __first, _RandomAccessIter __middle,
                    _RandomAccessIter __last, _Tp*) {
  make_heap(__first, __middle);
  for (_RandomAccessIter __i = __middle; __i < __last; ++__i)
    if (*__i < *__first) 
      __pop_heap(__first, __middle, __i, _Tp(*__i),
                 __distance_type(__first));
  sort_heap(__first, __middle);
}

template <class _RandomAccessIter>
inline void partial_sort(_RandomAccessIter __first,
                         _RandomAccessIter __middle,
                         _RandomAccessIter __last) {
  __partial_sort(__first, __middle, __last, __value_type(__first));
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __partial_sort(_RandomAccessIter __first, _RandomAccessIter __middle,
                    _RandomAccessIter __last, _Tp*, _Compare __comp) {
  make_heap(__first, __middle, __comp);
  for (_RandomAccessIter __i = __middle; __i < __last; ++__i)
    if (__comp(*__i, *__first))
      __pop_heap(__first, __middle, __i, _Tp(*__i), __comp,
                 __distance_type(__first));
  sort_heap(__first, __middle, __comp);
}

template <class _RandomAccessIter, class _Compare>
inline void partial_sort(_RandomAccessIter __first,
                         _RandomAccessIter __middle,
                         _RandomAccessIter __last, _Compare __comp) {
  __partial_sort(__first, __middle, __last, __value_type(__first), __comp);
}

template <class _InputIter, class _RandomAccessIter, class _Distance,
          class _Tp>
_RandomAccessIter __partial_sort_copy(_InputIter __first,
                                         _InputIter __last,
                                         _RandomAccessIter __result_first,
                                         _RandomAccessIter __result_last, 
                                         _Distance*, _Tp*) {
  if (__result_first == __result_last) return __result_last;
  _RandomAccessIter __result_real_last = __result_first;
  while(__first != __last && __result_real_last != __result_last) {
    *__result_real_last = *__first;
    ++__result_real_last;
    ++__first;
  }
  make_heap(__result_first, __result_real_last);
  while (__first != __last) {
    if (*__first < *__result_first) 
      __adjust_heap(__result_first, _Distance(0),
                    _Distance(__result_real_last - __result_first),
                    _Tp(*__first));
    ++__first;
  }
  sort_heap(__result_first, __result_real_last);
  return __result_real_last;
}

template <class _InputIter, class _RandomAccessIter>
inline _RandomAccessIter
partial_sort_copy(_InputIter __first, _InputIter __last,
                  _RandomAccessIter __result_first,
                  _RandomAccessIter __result_last) {
  return __partial_sort_copy(__first, __last, __result_first, __result_last, 
                             __distance_type(__result_first),
                             __value_type(__first));
}

template <class _InputIter, class _RandomAccessIter, class _Compare,
          class _Distance, class _Tp>
_RandomAccessIter __partial_sort_copy(_InputIter __first,
                                         _InputIter __last,
                                         _RandomAccessIter __result_first,
                                         _RandomAccessIter __result_last,
                                         _Compare __comp, _Distance*, _Tp*) {
  if (__result_first == __result_last) return __result_last;
  _RandomAccessIter __result_real_last = __result_first;
  while(__first != __last && __result_real_last != __result_last) {
    *__result_real_last = *__first;
    ++__result_real_last;
    ++__first;
  }
  make_heap(__result_first, __result_real_last, __comp);
  while (__first != __last) {
    if (__comp(*__first, *__result_first))
      __adjust_heap(__result_first, _Distance(0),
                    _Distance(__result_real_last - __result_first),
                    _Tp(*__first),
                    __comp);
    ++__first;
  }
  sort_heap(__result_first, __result_real_last, __comp);
  return __result_real_last;
}

template <class _InputIter, class _RandomAccessIter, class _Compare>
inline _RandomAccessIter
partial_sort_copy(_InputIter __first, _InputIter __last,
                  _RandomAccessIter __result_first,
                  _RandomAccessIter __result_last, _Compare __comp) {
  return __partial_sort_copy(__first, __last, __result_first, __result_last,
                             __comp,
                             __distance_type(__result_first),
                             __value_type(__first));
}



const int __stl_riselect_b = 4;

static unsigned long __stl_riselect_rng_seed = 19670121;

inline unsigned long __riselect_rng(unsigned long __limit) {
  __stl_riselect_rng_seed = __stl_riselect_rng_seed * 3141592621UL + 1;
  double __scale = (double) __stl_riselect_rng_seed / 18446744073709551615LU;
  return (unsigned long) (__scale * __limit);
}

template <class _RandomAccessIter, class _Tp>
void __hoare_find(_RandomAccessIter __first, _RandomAccessIter __nth,
                   _RandomAccessIter __last, _Tp*) {
  while (__last - __first > 3) {
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1))));
    if (__cut <= __nth)
      __first = __cut;
    else 
      __last = __cut;
  }
  __insertion_sort(__first, __last);
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __hoare_find(_RandomAccessIter __first, _RandomAccessIter __nth,
                   _RandomAccessIter __last, _Tp*, _Compare __comp) {
  while (__last - __first > 3) {
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2), 
                                         *(__last - 1),
                                         __comp)),
                            __comp);
    if (__cut <= __nth)
      __first = __cut;
    else 
      __last = __cut;
  }
  __insertion_sort(__first, __last, __comp);
}

const int __stl_linear_select_chunk = 7;
const int __stl_hoare_find_cutoff = 70;

template <class _RandomAccessIter, class _Tp>
void __sort_chunks(_RandomAccessIter __first, 
		  _RandomAccessIter __last, const unsigned __chunk, _Tp*) {
  const _RandomAccessIter __stop = __first + __chunk;
  for (; __first != __stop; ++__first) {
    _RandomAccessIter __end 
      = __first + (__stl_linear_select_chunk - 1) * __chunk;
    for (_RandomAccessIter __i=__first+__chunk; __i <= __end; __i += __chunk) {
      _Tp __value = *__i;
      _RandomAccessIter __dest = __i;
      _RandomAccessIter __src = __i;
      if (__value < *__first) {
	while (__src != __first) {
	  __src -= __chunk;
	  *__dest = *__src;
	  __dest -= __chunk;
	}
	*__first = __value;
      } 
      else {
	__src -= __chunk;
	while (__value < *__src) {
	  *__dest = *__src;
	  __dest -= __chunk;
	  __src -= __chunk;
	}
	*__dest = __value;
      }
    }
  }
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __sort_chunks(_RandomAccessIter __first, _RandomAccessIter __last, 
		    const unsigned __chunk, _Compare __comp, _Tp*) {
  const _RandomAccessIter __stop = __first + __chunk;
  for (; __first != __stop; ++__first) {
    _RandomAccessIter __end 
      = __first + (__stl_linear_select_chunk - 1) * __chunk;
    for (_RandomAccessIter __i=__first+__chunk; __i <= __end; __i += __chunk) {
      _Tp __value = *__i;
      _RandomAccessIter __dest = __i;
      _RandomAccessIter __src = __i;
      if (__comp(__value, *__first)) {
	while (__src != __first) {
	  __src -= __chunk;
	  *__dest = *__src;
	  __dest -= __chunk;
	}
	*__first = __value;
      } 
      else {
	__src -= __chunk;
	while (__comp(__value, *__src)) {
	  *__dest = *__src;
	  __dest -= __chunk;
	  __src -= __chunk;
	}
	*__dest = __value;
      }
    }
  }
}

template <class _RandomAccessIter, class _Tp>
void __linear_select(_RandomAccessIter __first, _RandomAccessIter __nth,
		      _RandomAccessIter __last, _Tp*) {
  while (__last-__first > __stl_hoare_find_cutoff) {
    const unsigned __chunk = (__last - __first) / __stl_linear_select_chunk;
    __sort_chunks(__first, __last, __chunk, (_Tp*) 0);
    _RandomAccessIter __med = 
      __first + __stl_linear_select_chunk/2 *__chunk + __chunk/2;
    __linear_select(__first + __stl_linear_select_chunk/2 *__chunk, __med, 
		    __first + (__stl_linear_select_chunk/2 + 1) * __chunk,
		    (_Tp*) 0);
    _RandomAccessIter __cut = __unguarded_partition(__first, __last, *__med);
    if (__cut <= __nth)
      __first = __cut;
    else
      __last = __cut;
  }
  __hoare_find(__first, __nth, __last, (_Tp*) 0);
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __linear_select(_RandomAccessIter __first, _RandomAccessIter __nth,
		      _RandomAccessIter __last, _Compare __comp, _Tp*) {
  while (__last-__first > __stl_hoare_find_cutoff) {
    const unsigned __chunk = (__last - __first) / __stl_linear_select_chunk;
    __sort_chunks(__first, __last, __chunk, __comp, (_Tp*) 0);
    _RandomAccessIter __med = 
      __first + __stl_linear_select_chunk/2 *__chunk + __chunk/2;
    __linear_select(__first + __stl_linear_select_chunk/2 *__chunk, __med, 
		    __first + (__stl_linear_select_chunk/2 + 1) * __chunk,
		    __comp, (_Tp*) 0);
    _RandomAccessIter __cut = __unguarded_partition(__first, __last, *__med, 
						    __comp);
    if (__cut <= __nth)
      __first = __cut;
    else
      __last = __cut;
  }
  __hoare_find(__first, __nth, __last,  (_Tp*) 0, __comp);
}

template <class _RandomAccessIter, class _Tp>
void __nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                   _RandomAccessIter __last, _Tp*) {
  unsigned __len = __last - __first;
  unsigned __limit = __len;

__begin:

  unsigned __threshold = __len / 2;
  int __counter = __stl_riselect_b + 2;

  while (__len > 3 && --__counter) {
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1))));
    if (__cut <= __nth)
      __first = __cut;
    else 
      __last = __cut;
    __len = __last - __first;
  }

  __counter = -1;
  while (__len > 3) {
    if (--__counter < 0) {
      if (__len >= __threshold) {
	if (__len / 4 <= __limit) {
	  __limit -= __len / 4;
	  iter_swap(__first, __first + __riselect_rng(__last-__first));
	  iter_swap(__last-1, __first+1 + __riselect_rng(__last-__first - 1));
	  iter_swap(__first + (__last-__first)/2, 
		    __first + 1 + __riselect_rng(__last-__first - 2));
	  goto __begin;
 	}
 	else {
 	  __linear_select(__first, __nth, __last, (_Tp*) 0);
 	  return;
 	}
      }
      else {
	if (__counter == -5)
	  __counter = 1;
	__threshold /= 2;
      }
    }
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1))));
    if (__cut <= __nth)
      __first = __cut;
    else 
      __last = __cut;
    __len = __last - __first;
  }
  __insertion_sort(__first, __last);
}


template <class _RandomAccessIter, class _Tp, class _Compare>
void __nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                   _RandomAccessIter __last, _Tp*, _Compare __comp) {
  unsigned __len = __last - __first;
  unsigned __limit = __len;

__begin:

  unsigned __threshold = __len / 2;
  int __counter = __stl_riselect_b + 2;

  while (__len > 3 && --__counter) {
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1),
					 __comp)),
			    __comp);
    if (__cut <= __nth)
      __first = __cut;
    else 
      __last = __cut;
    __len = __last - __first;
  }

  __counter = -1;
  while (__len > 3) {
    if (--__counter < 0) {
      if (__len >= __threshold) {
	if (__len / 4 <= __limit) {
	  __limit -= __len / 4;
	  iter_swap(__first, __first + __riselect_rng(__last-__first));
	  iter_swap(__last-1, __first+1 + __riselect_rng(__last-__first - 1));
	  iter_swap(__first + (__last-__first)/2, 
		    __first + 1 + __riselect_rng(__last-__first - 2));
	  goto __begin;
 	}
 	else {
 	  __linear_select(__first, __nth, __last, __comp, (_Tp*) 0);
 	  return;
 	}
      }
      else {
	if (__counter == -5)
	  __counter = 1;
	__threshold /= 2;
      }
    }
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1),
					 __comp)),
			    __comp);
    if (__cut <= __nth)
      __first = __cut;
    else 
      __last = __cut;
    __len = __last - __first;
  }
  __insertion_sort(__first, __last, __comp);
}

template <class _RandomAccessIter>
inline void nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                        _RandomAccessIter __last) {
  __nth_element(__first, __nth, __last, __value_type(__first));
}

template <class _RandomAccessIter, class _Compare>
inline void nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                 _RandomAccessIter __last, _Compare __comp) {
  __nth_element(__first, __nth, __last, __value_type(__first), __comp);
}




template <class _ForwardIter, class _Tp, class _Distance>
_ForwardIter __lower_bound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val, _Distance*) 
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (*__middle < __val) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else
      __len = __half;
  }
  return __first;
}

template <class _ForwardIter, class _Tp>
inline _ForwardIter lower_bound(_ForwardIter __first, _ForwardIter __last,
                                   const _Tp& __val) {
  return __lower_bound(__first, __last, __val,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Compare, class _Distance>
_ForwardIter __lower_bound(_ForwardIter __first, _ForwardIter __last,
                              const _Tp& __val, _Compare __comp, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__comp(*__middle, __val)) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else
      __len = __half;
  }
  return __first;
}

template <class _ForwardIter, class _Tp, class _Compare>
inline _ForwardIter lower_bound(_ForwardIter __first, _ForwardIter __last,
                                const _Tp& __val, _Compare __comp) {
  return __lower_bound(__first, __last, __val, __comp,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Distance>
_ForwardIter __upper_bound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__val < *__middle)
      __len = __half;
    else {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
  }
  return __first;
}

template <class _ForwardIter, class _Tp>
inline _ForwardIter upper_bound(_ForwardIter __first, _ForwardIter __last,
                                const _Tp& __val) {
  return __upper_bound(__first, __last, __val,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Compare, class _Distance>
_ForwardIter __upper_bound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val, _Compare __comp, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__comp(__val, *__middle))
      __len = __half;
    else {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
  }
  return __first;
}

template <class _ForwardIter, class _Tp, class _Compare>
inline _ForwardIter upper_bound(_ForwardIter __first, _ForwardIter __last,
                                const _Tp& __val, _Compare __comp) {
  return __upper_bound(__first, __last, __val, __comp,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Distance>
pair<_ForwardIter, _ForwardIter>
__equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
              _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle, __left, __right;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (*__middle < __val) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else if (__val < *__middle)
      __len = __half;
    else {
      __left = lower_bound(__first, __middle, __val);
      advance(__first, __len);
      __right = upper_bound(++__middle, __first, __val);
      return pair<_ForwardIter, _ForwardIter>(__left, __right);
    }
  }
  return pair<_ForwardIter, _ForwardIter>(__first, __first);
}

template <class _ForwardIter, class _Tp>
inline pair<_ForwardIter, _ForwardIter>
equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val) {
  return __equal_range(__first, __last, __val,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Compare, class _Distance>
pair<_ForwardIter, _ForwardIter>
__equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
              _Compare __comp, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle, __left, __right;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__comp(*__middle, __val)) {
      __first = __middle;
      ++__first;
       __len = __len - __half - 1;
    }
    else if (__comp(__val, *__middle))
      __len = __half;
    else {
      __left = lower_bound(__first, __middle, __val, __comp);
      advance(__first, __len);
      __right = upper_bound(++__middle, __first, __val, __comp);
      return pair<_ForwardIter, _ForwardIter>(__left, __right);
    }
  }
  return pair<_ForwardIter, _ForwardIter>(__first, __first);
}           

template <class _ForwardIter, class _Tp, class _Compare>
inline pair<_ForwardIter, _ForwardIter>
equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
            _Compare __comp) {
  return __equal_range(__first, __last, __val, __comp,
                       __distance_type(__first));
} 

template <class _ForwardIter, class _Tp>
bool binary_search(_ForwardIter __first, _ForwardIter __last,
                   const _Tp& __val) {
  _ForwardIter __i = lower_bound(__first, __last, __val);
  return __i != __last && !(__val < *__i);
}

template <class _ForwardIter, class _Tp, class _Compare>
bool binary_search(_ForwardIter __first, _ForwardIter __last,
                   const _Tp& __val,
                   _Compare __comp) {
  _ForwardIter __i = lower_bound(__first, __last, __val, __comp);
  return __i != __last && !__comp(__val, *__i);
}



template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter merge(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2, _InputIter2 __last2,
                  _OutputIter __result) {
  while (__first1 != __last1 && __first2 != __last2) {
    if (*__first2 < *__first1) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter merge(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2, _InputIter2 __last2,
                  _OutputIter __result, _Compare __comp) {
  while (__first1 != __last1 && __first2 != __last2) {
    if (__comp(*__first2, *__first1)) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}



template <class _BidirectionalIter, class _Distance>
void __merge_without_buffer(_BidirectionalIter __first,
                            _BidirectionalIter __middle,
                            _BidirectionalIter __last,
                            _Distance __len1, _Distance __len2) {
  if (__len1 == 0 || __len2 == 0)
    return;
  if (__len1 + __len2 == 2) {
    if (*__middle < *__first)
      iter_swap(__first, __middle);
    return;
  }
  _BidirectionalIter __first_cut = __first;
  _BidirectionalIter __second_cut = __middle;
  _Distance __len11 = 0;
  _Distance __len22 = 0;
  if (__len1 > __len2) {
    __len11 = __len1 / 2;
    advance(__first_cut, __len11);
    __second_cut = lower_bound(__middle, __last, *__first_cut);
    distance(__middle, __second_cut, __len22);
  }
  else {
    __len22 = __len2 / 2;
    advance(__second_cut, __len22);
    __first_cut = upper_bound(__first, __middle, *__second_cut);
    distance(__first, __first_cut, __len11);
  }
  _BidirectionalIter __new_middle
    = rotate(__first_cut, __middle, __second_cut);
  __merge_without_buffer(__first, __first_cut, __new_middle,
                         __len11, __len22);
  __merge_without_buffer(__new_middle, __second_cut, __last, __len1 - __len11,
                         __len2 - __len22);
}

template <class _BidirectionalIter, class _Distance, class _Compare>
void __merge_without_buffer(_BidirectionalIter __first,
                            _BidirectionalIter __middle,
                            _BidirectionalIter __last,
                            _Distance __len1, _Distance __len2,
                            _Compare __comp) {
  if (__len1 == 0 || __len2 == 0)
    return;
  if (__len1 + __len2 == 2) {
    if (__comp(*__middle, *__first))
      iter_swap(__first, __middle);
    return;
  }
  _BidirectionalIter __first_cut = __first;
  _BidirectionalIter __second_cut = __middle;
  _Distance __len11 = 0;
  _Distance __len22 = 0;
  if (__len1 > __len2) {
    __len11 = __len1 / 2;
    advance(__first_cut, __len11);
    __second_cut = lower_bound(__middle, __last, *__first_cut, __comp);
    distance(__middle, __second_cut, __len22);
  }
  else {
    __len22 = __len2 / 2;
    advance(__second_cut, __len22);
    __first_cut = upper_bound(__first, __middle, *__second_cut, __comp);
    distance(__first, __first_cut, __len11);
  }
  _BidirectionalIter __new_middle
    = rotate(__first_cut, __middle, __second_cut);
  __merge_without_buffer(__first, __first_cut, __new_middle, __len11, __len22,
                         __comp);
  __merge_without_buffer(__new_middle, __second_cut, __last, __len1 - __len11,
                         __len2 - __len22, __comp);
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _Distance>
_BidirectionalIter1 __rotate_adaptive(_BidirectionalIter1 __first,
                                      _BidirectionalIter1 __middle,
                                      _BidirectionalIter1 __last,
                                      _Distance __len1, _Distance __len2,
                                      _BidirectionalIter2 __buffer,
                                      _Distance __buffer_size) {
  _BidirectionalIter2 __buffer_end;
  if (__len1 > __len2 && __len2 <= __buffer_size) {
    __buffer_end = copy(__middle, __last, __buffer);
    copy_backward(__first, __middle, __last);
    return copy(__buffer, __buffer_end, __first);
  }
  else if (__len1 <= __buffer_size) {
    __buffer_end = copy(__first, __middle, __buffer);
    copy(__middle, __last, __first);
    return copy_backward(__buffer, __buffer_end, __last);
  }
  else
    return rotate(__first, __middle, __last);
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BidirectionalIter3>
_BidirectionalIter3 __merge_backward(_BidirectionalIter1 __first1,
                                     _BidirectionalIter1 __last1,
                                     _BidirectionalIter2 __first2,
                                     _BidirectionalIter2 __last2,
                                     _BidirectionalIter3 __result) {
  if (__first1 == __last1)
    return copy_backward(__first2, __last2, __result);
  if (__first2 == __last2)
    return copy_backward(__first1, __last1, __result);
  --__last1;
  --__last2;
  for (;;) {
    if (*__last2 < *__last1) {
      *--__result = *__last1;
      if (__first1 == __last1)
        return copy_backward(__first2, ++__last2, __result);
      --__last1;
    }
    else {
      *--__result = *__last2;
      if (__first2 == __last2)
        return copy_backward(__first1, ++__last1, __result);
      --__last2;
    }
  }
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BidirectionalIter3, class _Compare>
_BidirectionalIter3 __merge_backward(_BidirectionalIter1 __first1,
                                     _BidirectionalIter1 __last1,
                                     _BidirectionalIter2 __first2,
                                     _BidirectionalIter2 __last2,
                                     _BidirectionalIter3 __result,
                                     _Compare __comp) {
  if (__first1 == __last1)
    return copy_backward(__first2, __last2, __result);
  if (__first2 == __last2)
    return copy_backward(__first1, __last1, __result);
  --__last1;
  --__last2;
  for (;;) {
    if (__comp(*__last2, *__last1)) {
      *--__result = *__last1;
      if (__first1 == __last1)
        return copy_backward(__first2, ++__last2, __result);
      --__last1;
    }
    else {
      *--__result = *__last2;
      if (__first2 == __last2)
        return copy_backward(__first1, ++__last1, __result);
      --__last2;
    }
  }
}

template <class _BidirectionalIter, class _Distance, class _Pointer>
void __merge_adaptive(_BidirectionalIter __first,
                      _BidirectionalIter __middle, 
                      _BidirectionalIter __last,
                      _Distance __len1, _Distance __len2,
                      _Pointer __buffer, _Distance __buffer_size) {
  if (__len1 <= __len2 && __len1 <= __buffer_size) {
    _Pointer __buffer_end = copy(__first, __middle, __buffer);
    merge(__buffer, __buffer_end, __middle, __last, __first);
  }
  else if (__len2 <= __buffer_size) {
    _Pointer __buffer_end = copy(__middle, __last, __buffer);
    __merge_backward(__first, __middle, __buffer, __buffer_end, __last);
  }
  else {
    _BidirectionalIter __first_cut = __first;
    _BidirectionalIter __second_cut = __middle;
    _Distance __len11 = 0;
    _Distance __len22 = 0;
    if (__len1 > __len2) {
      __len11 = __len1 / 2;
      advance(__first_cut, __len11);
      __second_cut = lower_bound(__middle, __last, *__first_cut);
      distance(__middle, __second_cut, __len22); 
    }
    else {
      __len22 = __len2 / 2;
      advance(__second_cut, __len22);
      __first_cut = upper_bound(__first, __middle, *__second_cut);
      distance(__first, __first_cut, __len11);
    }
    _BidirectionalIter __new_middle =
      __rotate_adaptive(__first_cut, __middle, __second_cut, __len1 - __len11,
                        __len22, __buffer, __buffer_size);
    __merge_adaptive(__first, __first_cut, __new_middle, __len11,
                     __len22, __buffer, __buffer_size);
    __merge_adaptive(__new_middle, __second_cut, __last, __len1 - __len11,
                     __len2 - __len22, __buffer, __buffer_size);
  }
}

template <class _BidirectionalIter, class _Distance, class _Pointer,
          class _Compare>
void __merge_adaptive(_BidirectionalIter __first, 
                      _BidirectionalIter __middle, 
                      _BidirectionalIter __last,
                      _Distance __len1, _Distance __len2,
                      _Pointer __buffer, _Distance __buffer_size,
                      _Compare __comp) {
  if (__len1 <= __len2 && __len1 <= __buffer_size) {
    _Pointer __buffer_end = copy(__first, __middle, __buffer);
    merge(__buffer, __buffer_end, __middle, __last, __first, __comp);
  }
  else if (__len2 <= __buffer_size) {
    _Pointer __buffer_end = copy(__middle, __last, __buffer);
    __merge_backward(__first, __middle, __buffer, __buffer_end, __last,
                     __comp);
  }
  else {
    _BidirectionalIter __first_cut = __first;
    _BidirectionalIter __second_cut = __middle;
    _Distance __len11 = 0;
    _Distance __len22 = 0;
    if (__len1 > __len2) {
      __len11 = __len1 / 2;
      advance(__first_cut, __len11);
      __second_cut = lower_bound(__middle, __last, *__first_cut, __comp);
      distance(__middle, __second_cut, __len22);   
    }
    else {
      __len22 = __len2 / 2;
      advance(__second_cut, __len22);
      __first_cut = upper_bound(__first, __middle, *__second_cut, __comp);
      distance(__first, __first_cut, __len11);
    }
    _BidirectionalIter __new_middle =
      __rotate_adaptive(__first_cut, __middle, __second_cut, __len1 - __len11,
                        __len22, __buffer, __buffer_size);
    __merge_adaptive(__first, __first_cut, __new_middle, __len11,
                     __len22, __buffer, __buffer_size, __comp);
    __merge_adaptive(__new_middle, __second_cut, __last, __len1 - __len11,
                     __len2 - __len22, __buffer, __buffer_size, __comp);
  }
}

template <class _BidirectionalIter, class _Tp, class _Distance>
inline void __inplace_merge_aux(_BidirectionalIter __first,
                                _BidirectionalIter __middle,
                                _BidirectionalIter __last, _Tp*, _Distance*) {
  _Distance __len1 = 0;
  distance(__first, __middle, __len1);
  _Distance __len2 = 0;
  distance(__middle, __last, __len2);

  _Temporary_buffer<_BidirectionalIter, _Tp> __buf(__first, __last);
  if (__buf.begin() == 0)
    __merge_without_buffer(__first, __middle, __last, __len1, __len2);
  else
    __merge_adaptive(__first, __middle, __last, __len1, __len2,
                     __buf.begin(), _Distance(__buf.size()));
}

template <class _BidirectionalIter, class _Tp, 
          class _Distance, class _Compare>
inline void __inplace_merge_aux(_BidirectionalIter __first,
                                _BidirectionalIter __middle,
                                _BidirectionalIter __last, _Tp*, _Distance*,
                                _Compare __comp) {
  _Distance __len1 = 0;
  distance(__first, __middle, __len1);
  _Distance __len2 = 0;
  distance(__middle, __last, __len2);

  _Temporary_buffer<_BidirectionalIter, _Tp> __buf(__first, __last);
  if (__buf.begin() == 0)
    __merge_without_buffer(__first, __middle, __last, __len1, __len2, __comp);
  else
    __merge_adaptive(__first, __middle, __last, __len1, __len2,
                     __buf.begin(), _Distance(__buf.size()),
                     __comp);
}

template <class _BidirectionalIter>
inline void inplace_merge(_BidirectionalIter __first,
                          _BidirectionalIter __middle,
                          _BidirectionalIter __last) {
  if (__first == __middle || __middle == __last)
    return;
  __inplace_merge_aux(__first, __middle, __last,
                      __value_type(__first), __distance_type(__first));
}

template <class _BidirectionalIter, class _Compare>
inline void inplace_merge(_BidirectionalIter __first,
                          _BidirectionalIter __middle,
                          _BidirectionalIter __last, _Compare __comp) {
  if (__first == __middle || __middle == __last)
    return;
  __inplace_merge_aux(__first, __middle, __last,
                      __value_type(__first), __distance_type(__first),
                      __comp);
}






template <class _InputIter1, class _InputIter2>
bool includes(_InputIter1 __first1, _InputIter1 __last1,
              _InputIter2 __first2, _InputIter2 __last2) {
  while (__first1 != __last1 && __first2 != __last2)
    if (*__first2 < *__first1)
      return false;
    else if(*__first1 < *__first2) 
      ++__first1;
    else
      ++__first1, ++__first2;

  return __first2 == __last2;
}

template <class _InputIter1, class _InputIter2, class _Compare>
bool includes(_InputIter1 __first1, _InputIter1 __last1,
              _InputIter2 __first2, _InputIter2 __last2, _Compare __comp) {
  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first2, *__first1))
      return false;
    else if(__comp(*__first1, *__first2)) 
      ++__first1;
    else
      ++__first1, ++__first2;

  return __first2 == __last2;
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter set_union(_InputIter1 __first1, _InputIter1 __last1,
                      _InputIter2 __first2, _InputIter2 __last2,
                      _OutputIter __result) {
  while (__first1 != __last1 && __first2 != __last2) {
    if (*__first1 < *__first2) {
      *__result = *__first1;
      ++__first1;
    }
    else if (*__first2 < *__first1) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter set_union(_InputIter1 __first1, _InputIter1 __last1,
                      _InputIter2 __first2, _InputIter2 __last2,
                      _OutputIter __result, _Compare __comp) {
  while (__first1 != __last1 && __first2 != __last2) {
    if (__comp(*__first1, *__first2)) {
      *__result = *__first1;
      ++__first1;
    }
    else if (__comp(*__first2, *__first1)) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter set_intersection(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _OutputIter __result) {
  while (__first1 != __last1 && __first2 != __last2) 
    if (*__first1 < *__first2) 
      ++__first1;
    else if (*__first2 < *__first1) 
      ++__first2;
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
      ++__result;
    }
  return __result;
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter set_intersection(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _OutputIter __result, _Compare __comp) {
  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first1, *__first2))
      ++__first1;
    else if (__comp(*__first2, *__first1))
      ++__first2;
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
      ++__result;
    }
  return __result;
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter set_difference(_InputIter1 __first1, _InputIter1 __last1,
                           _InputIter2 __first2, _InputIter2 __last2,
                           _OutputIter __result) {
  while (__first1 != __last1 && __first2 != __last2)
    if (*__first1 < *__first2) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (*__first2 < *__first1)
      ++__first2;
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first1, __last1, __result);
}

template <class _InputIter1, class _InputIter2, class _OutputIter, 
          class _Compare>
_OutputIter set_difference(_InputIter1 __first1, _InputIter1 __last1,
                           _InputIter2 __first2, _InputIter2 __last2, 
                           _OutputIter __result, _Compare __comp) {
  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first1, *__first2)) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (__comp(*__first2, *__first1))
      ++__first2;
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first1, __last1, __result);
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter 
set_symmetric_difference(_InputIter1 __first1, _InputIter1 __last1,
                         _InputIter2 __first2, _InputIter2 __last2,
                         _OutputIter __result) {
  while (__first1 != __last1 && __first2 != __last2)
    if (*__first1 < *__first2) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (*__first2 < *__first1) {
      *__result = *__first2;
      ++__first2;
      ++__result;
    }
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter 
set_symmetric_difference(_InputIter1 __first1, _InputIter1 __last1,
                         _InputIter2 __first2, _InputIter2 __last2,
                         _OutputIter __result,
                         _Compare __comp) {
  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first1, *__first2)) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (__comp(*__first2, *__first1)) {
      *__result = *__first2;
      ++__first2;
      ++__result;
    }
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}




template <class _ForwardIter>
_ForwardIter max_element(_ForwardIter __first, _ForwardIter __last) {
  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last) 
    if (*__result < *__first)
      __result = __first;
  return __result;
}

template <class _ForwardIter, class _Compare>
_ForwardIter max_element(_ForwardIter __first, _ForwardIter __last,
                            _Compare __comp) {
  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last) 
    if (__comp(*__result, *__first)) __result = __first;
  return __result;
}

template <class _ForwardIter>
_ForwardIter min_element(_ForwardIter __first, _ForwardIter __last) {
  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last) 
    if (*__first < *__result)
      __result = __first;
  return __result;
}

template <class _ForwardIter, class _Compare>
_ForwardIter min_element(_ForwardIter __first, _ForwardIter __last,
                            _Compare __comp) {
  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last) 
    if (__comp(*__first, *__result))
      __result = __first;
  return __result;
}




template <class _BidirectionalIter>
bool next_permutation(_BidirectionalIter __first, _BidirectionalIter __last) {
  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (*__i < *__ii) {
      _BidirectionalIter __j = __last;
      while (!(*__i < *--__j))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}

template <class _BidirectionalIter, class _Compare>
bool next_permutation(_BidirectionalIter __first, _BidirectionalIter __last,
                      _Compare __comp) {
  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (__comp(*__i, *__ii)) {
      _BidirectionalIter __j = __last;
      while (!__comp(*__i, *--__j))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}

template <class _BidirectionalIter>
bool prev_permutation(_BidirectionalIter __first, _BidirectionalIter __last) {
  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (*__ii < *__i) {
      _BidirectionalIter __j = __last;
      while (!(*--__j < *__i))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}

template <class _BidirectionalIter, class _Compare>
bool prev_permutation(_BidirectionalIter __first, _BidirectionalIter __last,
                      _Compare __comp) {
  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (__comp(*__ii, *__i)) {
      _BidirectionalIter __j = __last;
      while (!__comp(*--__j, *__i))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}



template <class _InputIter, class _ForwardIter>
_InputIter find_first_of(_InputIter __first1, _InputIter __last1,
                         _ForwardIter __first2, _ForwardIter __last2)
{
  for ( ; __first1 != __last1; ++__first1) 
    for (_ForwardIter __iter = __first2; __iter != __last2; ++__iter)
      if (*__first1 == *__iter)
        return __first1;
  return __last1;
}

template <class _InputIter, class _ForwardIter, class _BinaryPredicate>
_InputIter find_first_of(_InputIter __first1, _InputIter __last1,
                         _ForwardIter __first2, _ForwardIter __last2,
                         _BinaryPredicate __comp)
{
  for ( ; __first1 != __last1; ++__first1) 
    for (_ForwardIter __iter = __first2; __iter != __last2; ++__iter)
      if (__comp(*__first1, *__iter))
        return __first1;
  return __last1;
}








template <class _ForwardIter1, class _ForwardIter2>
_ForwardIter1 __find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
                         _ForwardIter2 __first2, _ForwardIter2 __last2,
                         forward_iterator_tag, forward_iterator_tag)
{
  if (__first2 == __last2)
    return __last1;
  else {
    _ForwardIter1 __result = __last1;
    for (;;) {
      _ForwardIter1 __new_result
        = search(__first1, __last1, __first2, __last2);
      if (__new_result == __last1)
        return __result;
      else {
        __result = __new_result;
        __first1 = __new_result;
        ++__first1;
      }
    }
  }
}

template <class _ForwardIter1, class _ForwardIter2,
          class _BinaryPredicate>
_ForwardIter1 __find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
                         _ForwardIter2 __first2, _ForwardIter2 __last2,
                         forward_iterator_tag, forward_iterator_tag,
                         _BinaryPredicate __comp)
{
  if (__first2 == __last2)
    return __last1;
  else {
    _ForwardIter1 __result = __last1;
    for (;;) {
      _ForwardIter1 __new_result
        = search(__first1, __last1, __first2, __last2, __comp);
      if (__new_result == __last1)
        return __result;
      else {
        __result = __new_result;
        __first1 = __new_result;
        ++__first1;
      }
    }
  }
}




template <class _BidirectionalIter1, class _BidirectionalIter2>
_BidirectionalIter1
__find_end(_BidirectionalIter1 __first1, _BidirectionalIter1 __last1,
           _BidirectionalIter2 __first2, _BidirectionalIter2 __last2,
           bidirectional_iterator_tag, bidirectional_iterator_tag)
{
  typedef reverse_iterator<_BidirectionalIter1> _RevIter1;
  typedef reverse_iterator<_BidirectionalIter2> _RevIter2;

  _RevIter1 __rlast1(__first1);
  _RevIter2 __rlast2(__first2);
  _RevIter1 __rresult = search(_RevIter1(__last1), __rlast1,
                               _RevIter2(__last2), __rlast2);

  if (__rresult == __rlast1)
    return __last1;
  else {
    _BidirectionalIter1 __result = __rresult.base();
    advance(__result, -distance(__first2, __last2));
    return __result;
  }
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BinaryPredicate>
_BidirectionalIter1
__find_end(_BidirectionalIter1 __first1, _BidirectionalIter1 __last1,
           _BidirectionalIter2 __first2, _BidirectionalIter2 __last2,
           bidirectional_iterator_tag, bidirectional_iterator_tag, 
           _BinaryPredicate __comp)
{
  typedef reverse_iterator<_BidirectionalIter1> _RevIter1;
  typedef reverse_iterator<_BidirectionalIter2> _RevIter2;

  _RevIter1 __rlast1(__first1);
  _RevIter2 __rlast2(__first2);
  _RevIter1 __rresult = search(_RevIter1(__last1), __rlast1,
                               _RevIter2(__last2), __rlast2,
                               __comp);

  if (__rresult == __rlast1)
    return __last1;
  else {
    _BidirectionalIter1 __result = __rresult.base();
    advance(__result, -distance(__first2, __last2));
    return __result;
  }
}




template <class _ForwardIter1, class _ForwardIter2>
inline _ForwardIter1 
find_end(_ForwardIter1 __first1, _ForwardIter1 __last1, 
         _ForwardIter2 __first2, _ForwardIter2 __last2)
{
  return __find_end(__first1, __last1, __first2, __last2,
                    __iterator_category(__first1),
                    __iterator_category(__first2));
}

template <class _ForwardIter1, class _ForwardIter2, 
          class _BinaryPredicate>
inline _ForwardIter1 
find_end(_ForwardIter1 __first1, _ForwardIter1 __last1, 
         _ForwardIter2 __first2, _ForwardIter2 __last2,
         _BinaryPredicate __comp)
{
  return __find_end(__first1, __last1, __first2, __last2,
                    __iterator_category(__first1),
                    __iterator_category(__first2),
                    __comp);
}





template <class _RandomAccessIter, class _Distance>
bool __is_heap(_RandomAccessIter __first, _Distance __n)
{
  _Distance __parent = 0;
  for (_Distance __child = 1; __child < __n; ++__child) {
    if (__first[__parent] < __first[__child]) 
      return false;
    if ((__child & 1) == 0)
      ++__parent;
  }
  return true;
}

template <class _RandomAccessIter, class _Distance, class _StrictWeakOrdering>
bool __is_heap(_RandomAccessIter __first, _StrictWeakOrdering __comp,
               _Distance __n)
{
  _Distance __parent = 0;
  for (_Distance __child = 1; __child < __n; ++__child) {
    if (__comp(__first[__parent], __first[__child]))
      return false;
    if ((__child & 1) == 0)
      ++__parent;
  }
  return true;
}

template <class _RandomAccessIter>
inline bool is_heap(_RandomAccessIter __first, _RandomAccessIter __last)
{
  return __is_heap(__first, __last - __first);
}


template <class _RandomAccessIter, class _StrictWeakOrdering>
inline bool is_heap(_RandomAccessIter __first, _RandomAccessIter __last,
                    _StrictWeakOrdering __comp)
{
  return __is_heap(__first, __comp, __last - __first);
}





template <class _ForwardIter>
bool is_sorted(_ForwardIter __first, _ForwardIter __last)
{
  if (__first == __last)
    return true;

  _ForwardIter __next = __first;
  for (++__next; __next != __last; __first = __next, ++__next) {
    if (*__next < *__first)
      return false;
  }

  return true;
}

template <class _ForwardIter, class _StrictWeakOrdering>
bool is_sorted(_ForwardIter __first, _ForwardIter __last,
               _StrictWeakOrdering __comp)
{
  if (__first == __last)
    return true;

  _ForwardIter __next = __first;
  for (++__next; __next != __last; __first = __next, ++__next) {
    if (__comp(*__next, *__first))
      return false;
  }

  return true;
}


#pragma reset woff 1209


}






#line 35 "/usr/include/CC/algorithm"






#line 31 "../boost/shared_ptr.hpp"









namespace boost
{

template<class T> class weak_ptr;
template<class T> class enable_shared_from_this;

namespace detail
{

struct static_cast_tag {};
struct const_cast_tag {};
struct dynamic_cast_tag {};
struct polymorphic_cast_tag {};

template<class T> struct shared_ptr_traits
{
    typedef T & reference;
};

template<> struct shared_ptr_traits<void>
{
    typedef void reference;
};



template<> struct shared_ptr_traits<void const>
{
    typedef void reference;
};

template<> struct shared_ptr_traits<void volatile>
{
    typedef void reference;
};

template<> struct shared_ptr_traits<void const volatile>
{
    typedef void reference;
};





template<class T, class Y> void sp_enable_shared_from_this( shared_count const & pn, boost::enable_shared_from_this<T> const * pe, Y const * px )
{
    if(pe != 0) pe->_internal_weak_this._internal_assign(const_cast<Y*>(px), pn);
}

inline void sp_enable_shared_from_this( shared_count const &  , ... )
{
}

} 










template<class T> class shared_ptr
{
private:

    
    typedef shared_ptr<T> this_type;

public:

    typedef T element_type;
    typedef T value_type;
    typedef T * pointer;
    typedef typename detail::shared_ptr_traits<T>::reference reference;

    shared_ptr(): px(0), pn() 
    {
    }

    template<class Y>
    explicit shared_ptr( Y * p ): px( p ), pn( p ) 
    {
        detail::sp_enable_shared_from_this( pn, p, p );
    }

    
    
    
    
    

    template<class Y, class D> shared_ptr(Y * p, D d): px(p), pn(p, d)
    {
        detail::sp_enable_shared_from_this( pn, p, p );
    }




#line 153 "../boost/shared_ptr.hpp"

    template<class Y>
    explicit shared_ptr(weak_ptr<Y> const & r): pn(r.pn) 
    {
        
        px = r.px;
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r): px(r.px), pn(r.pn) 
    {
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, detail::static_cast_tag): px(static_cast<element_type *>(r.px)), pn(r.pn)
    {
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, detail::const_cast_tag): px(const_cast<element_type *>(r.px)), pn(r.pn)
    {
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, detail::dynamic_cast_tag): px(dynamic_cast<element_type *>(r.px)), pn(r.pn)
    {
        if(px == 0) 
        {
            pn = detail::shared_count();
        }
    }

    template<class Y>
    shared_ptr(shared_ptr<Y> const & r, detail::polymorphic_cast_tag): px(dynamic_cast<element_type *>(r.px)), pn(r.pn)
    {
        if(px == 0)
        {
            boost::throw_exception(std::bad_cast());
        }
    }



    template<class Y>
    explicit shared_ptr(std::auto_ptr<Y> & r): px(r.get()), pn()
    {
        Y * tmp = r.get();
        pn = detail::shared_count(r);
        detail::sp_enable_shared_from_this( pn, tmp, tmp );
    }





    template<class Y>
    shared_ptr & operator=(shared_ptr<Y> const & r) 
    {
        px = r.px;
        pn = r.pn; 
        return *this;
    }





    template<class Y>
    shared_ptr & operator=(std::auto_ptr<Y> & r)
    {
        this_type(r).swap(*this);
        return *this;
    }



    void reset() 
    {
        this_type().swap(*this);
    }

    template<class Y> void reset(Y * p) 
    {
        ((p == 0 || p != px)?((void)0):__assert( "p == 0 || p != px" , "../boost/shared_ptr.hpp", 236)); 
        this_type(p).swap(*this);
    }

    template<class Y, class D> void reset(Y * p, D d)
    {
        this_type(p, d).swap(*this);
    }

    reference operator* () const 
    {
        ((px != 0)?((void)0):__assert( "px != 0" , "../boost/shared_ptr.hpp", 247));
        return *px;
    }

    T * operator-> () const 
    {
        ((px != 0)?((void)0):__assert( "px != 0" , "../boost/shared_ptr.hpp", 253));
        return px;
    }
    
    T * get() const 
    {
        return px;
    }

    

#line 283 "../boost/shared_ptr.hpp"

    typedef T * this_type::*unspecified_bool_type;

    operator unspecified_bool_type() const 
    {
        return px == 0? 0: &this_type::px;
    }



    

    bool operator! () const 
    {
        return px == 0;
    }

    bool unique() const 
    {
        return pn.unique();
    }

    long use_count() const 
    {
        return pn.use_count();
    }

    void swap(shared_ptr<T> & other) 
    {
        std::swap(px, other.px);
        pn.swap(other.pn);
    }

    template<class Y> bool _internal_less(shared_ptr<Y> const & rhs) const
    {
        return pn < rhs.pn;
    }

    void * _internal_get_deleter(std::type_info const & ti) const
    {
        return pn.get_deleter(ti);
    }






private:

    template<class Y> friend class shared_ptr;
    template<class Y> friend class weak_ptr;




    T * px;                     
    detail::shared_count pn;    

};  

template<class T, class U> inline bool operator==(shared_ptr<T> const & a, shared_ptr<U> const & b)
{
    return a.get() == b.get();
}

template<class T, class U> inline bool operator!=(shared_ptr<T> const & a, shared_ptr<U> const & b)
{
    return a.get() != b.get();
}

#line 364 "../boost/shared_ptr.hpp"

template<class T, class U> inline bool operator<(shared_ptr<T> const & a, shared_ptr<U> const & b)
{
    return a._internal_less(b);
}

template<class T> inline void swap(shared_ptr<T> & a, shared_ptr<T> & b)
{
    a.swap(b);
}

template<class T, class U> shared_ptr<T> static_pointer_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, detail::static_cast_tag());
}

template<class T, class U> shared_ptr<T> const_pointer_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, detail::const_cast_tag());
}

template<class T, class U> shared_ptr<T> dynamic_pointer_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, detail::dynamic_cast_tag());
}



template<class T, class U> shared_ptr<T> shared_static_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, detail::static_cast_tag());
}

template<class T, class U> shared_ptr<T> shared_dynamic_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, detail::dynamic_cast_tag());
}

template<class T, class U> shared_ptr<T> shared_polymorphic_cast(shared_ptr<U> const & r)
{
    return shared_ptr<T>(r, detail::polymorphic_cast_tag());
}

template<class T, class U> shared_ptr<T> shared_polymorphic_downcast(shared_ptr<U> const & r)
{
    ((dynamic_cast<T * >(r . get()) == r . get())?((void)0):__assert( "dynamic_cast<T *>(r.get()) == r.get()" , "../boost/shared_ptr.hpp", 409));
    return shared_static_cast<T>(r);
}



template<class T> inline T * get_pointer(shared_ptr<T> const & p)
{
    return p.get();
}



#line 431 "../boost/shared_ptr.hpp"






template<class E, class T, class Y> std::basic_ostream<E, T> & operator<< (std::basic_ostream<E, T> & os, shared_ptr<Y> const & p)

{
    os << p.get();
    return os;
}





#line 462 "../boost/shared_ptr.hpp"

template<class D, class T> D * get_deleter(shared_ptr<T> const & p)
{
    return static_cast<D *>(p._internal_get_deleter(typeid(D)));
}



} 







#line 19 "smart_ptr.hpp"
#line 1 "../boost/shared_array.hpp"






















#line 1 "../boost/assert.hpp"
















#line 1 "/usr/include/assert.h"
 
#line 1 "/usr/include/internal/assert_core.h"
 











 
 
 

 
 
 

#ident "$Revision: 1.1 $"









 



extern "C" {







extern void __assert(const char *, const char *, int);
#line 50 "/usr/include/internal/assert_core.h"

}
#line 3 "/usr/include/assert.h"

#line 36 "../boost/assert.hpp"
#line 24 "../boost/shared_array.hpp"









namespace boost
{









template<class T> class shared_array
{
private:

    
    typedef checked_array_deleter<T> deleter;
    typedef shared_array<T> this_type;

public:

    typedef T element_type;

    explicit shared_array(T * p = 0): px(p), pn(p, deleter())
    {
    }

    
    
    
    
    

    template<class D> shared_array(T * p, D d): px(p), pn(p, d)
    {
    }



    void reset(T * p = 0)
    {
        ((p == 0 || p != px)?((void)0):__assert( "p == 0 || p != px" , "../boost/shared_array.hpp", 74));
        this_type(p).swap(*this);
    }

    template <class D> void reset(T * p, D d)
    {
        this_type(p, d).swap(*this);
    }

    T & operator[] (std::ptrdiff_t i) const 
    {
        ((px != 0)?((void)0):__assert( "px != 0" , "../boost/shared_array.hpp", 85));
        ((i >= 0)?((void)0):__assert( "i >= 0" , "../boost/shared_array.hpp", 86));
        return px[i];
    }
    
    T * get() const 
    {
        return px;
    }

    

#line 113 "../boost/shared_array.hpp"

    typedef T * this_type::*unspecified_bool_type;

    operator unspecified_bool_type() const 
    {
        return px == 0? 0: &this_type::px;
    }



    bool operator! () const 
    {
        return px == 0;
    }

    bool unique() const 
    {
        return pn.unique();
    }

    long use_count() const 
    {
        return pn.use_count();
    }

    void swap(shared_array<T> & other) 
    {
        std::swap(px, other.px);
        pn.swap(other.pn);
    }

private:

    T * px;                     
    detail::shared_count pn;    

};  

template<class T> inline bool operator==(shared_array<T> const & a, shared_array<T> const & b) 
{
    return a.get() == b.get();
}

template<class T> inline bool operator!=(shared_array<T> const & a, shared_array<T> const & b) 
{
    return a.get() != b.get();
}

template<class T> inline bool operator<(shared_array<T> const & a, shared_array<T> const & b) 
{
    return std::less<T*>()(a.get(), b.get());
}

template<class T> void swap(shared_array<T> & a, shared_array<T> & b) 
{
    a.swap(b);
}

} 



#line 20 "smart_ptr.hpp"

#line 1 "../boost/weak_ptr.hpp"






















namespace boost
{

template<class T> class weak_ptr
{
private:

    
    typedef weak_ptr<T> this_type;

public:

    typedef T element_type;

    weak_ptr(): px(0), pn() 
    {
    }





















    template<class Y>
    weak_ptr(weak_ptr<Y> const & r): pn(r.pn) 
    {
        px = r.lock().get();
    }

    template<class Y>
    weak_ptr(shared_ptr<Y> const & r): px(r.px), pn(r.pn) 
    {
    }



    template<class Y>
    weak_ptr & operator=(weak_ptr<Y> const & r) 
    {
        px = r.lock().get();
        pn = r.pn;
        return *this;
    }

    template<class Y>
    weak_ptr & operator=(shared_ptr<Y> const & r) 
    {
        px = r.px;
        pn = r.pn;
        return *this;
    }



    shared_ptr<T> lock() const 
    {
#line 114 "../boost/weak_ptr.hpp"

        
        return expired()? shared_ptr<element_type>(): shared_ptr<element_type>(*this);


    }

    long use_count() const 
    {
        return pn.use_count();
    }

    bool expired() const 
    {
        return pn.use_count() == 0;
    }

    void reset() 
    {
        this_type().swap(*this);
    }

    void swap(this_type & other) 
    {
        std::swap(px, other.px);
        pn.swap(other.pn);
    }

    void _internal_assign(T * px2, detail::shared_count const & pn2)
    {
        px = px2;
        pn = pn2;
    }

    template<class Y> bool _internal_less(weak_ptr<Y> const & rhs) const
    {
        return pn < rhs.pn;
    }






private:

    template<class Y> friend class weak_ptr;
    template<class Y> friend class shared_ptr;



    T * px;                     
    detail::weak_count pn;      

};  

template<class T, class U> inline bool operator<(weak_ptr<T> const & a, weak_ptr<U> const & b)
{
    return a._internal_less(b);
}

template<class T> void swap(weak_ptr<T> & a, weak_ptr<T> & b)
{
    a.swap(b);
}


template<class T> shared_ptr<T> make_shared(weak_ptr<T> const & r)
{
    return r.lock();
}

} 





#line 23 "smart_ptr.hpp"
#line 1 "../boost/intrusive_ptr.hpp"






















#line 1 "../boost/assert.hpp"
















#line 1 "/usr/include/assert.h"
 
#line 1 "/usr/include/internal/assert_core.h"
 











 
 
 

 
 
 

#ident "$Revision: 1.1 $"









 



extern "C" {







extern void __assert(const char *, const char *, int);
#line 50 "/usr/include/internal/assert_core.h"

}
#line 3 "/usr/include/assert.h"

#line 36 "../boost/assert.hpp"
#line 24 "../boost/intrusive_ptr.hpp"






namespace boost
{
















template<class T> class intrusive_ptr
{
private:

    typedef intrusive_ptr this_type;

public:

    typedef T element_type;

    intrusive_ptr(): p_(0)
    {
    }

    intrusive_ptr(T * p, bool add_ref = true): p_(p)
    {
        if(p_ != 0 && add_ref) intrusive_ptr_add_ref(p_);
    }



    template<class U> intrusive_ptr(intrusive_ptr<U> const & rhs): p_(rhs.get())
    {
        if(p_ != 0) intrusive_ptr_add_ref(p_);
    }



    intrusive_ptr(intrusive_ptr const & rhs): p_(rhs.p_)
    {
        if(p_ != 0) intrusive_ptr_add_ref(p_);
    }

    ~intrusive_ptr()
    {
        if(p_ != 0) intrusive_ptr_release(p_);
    }



    template<class U> intrusive_ptr & operator=(intrusive_ptr<U> const & rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }



    intrusive_ptr & operator=(intrusive_ptr const & rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }

    intrusive_ptr & operator=(T * rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }

    T * get() const
    {
        return p_;
    }

    T & operator*() const
    {
        return *p_;
    }

    T * operator->() const
    {
        return p_;
    }

#line 139 "../boost/intrusive_ptr.hpp"

    typedef T * this_type::*unspecified_bool_type;

    operator unspecified_bool_type () const
    {
        return p_ == 0? 0: &this_type::p_;
    }



    
    bool operator! () const
    {
        return p_ == 0;
    }

    void swap(intrusive_ptr & rhs)
    {
        T * tmp = p_;
        p_ = rhs.p_;
        rhs.p_ = tmp;
    }

private:

    T * p_;
};

template<class T, class U> inline bool operator==(intrusive_ptr<T> const & a, intrusive_ptr<U> const & b)
{
    return a.get() == b.get();
}

template<class T, class U> inline bool operator!=(intrusive_ptr<T> const & a, intrusive_ptr<U> const & b)
{
    return a.get() != b.get();
}

template<class T> inline bool operator==(intrusive_ptr<T> const & a, T * b)
{
    return a.get() == b;
}

template<class T> inline bool operator!=(intrusive_ptr<T> const & a, T * b)
{
    return a.get() != b;
}

template<class T> inline bool operator==(T * a, intrusive_ptr<T> const & b)
{
    return a == b.get();
}

template<class T> inline bool operator!=(T * a, intrusive_ptr<T> const & b)
{
    return a != b.get();
}

#line 207 "../boost/intrusive_ptr.hpp"

template<class T> inline bool operator<(intrusive_ptr<T> const & a, intrusive_ptr<T> const & b)
{
    return std::less<T *>()(a.get(), b.get());
}

template<class T> void swap(intrusive_ptr<T> & lhs, intrusive_ptr<T> & rhs)
{
    lhs.swap(rhs);
}



template<class T> T * get_pointer(intrusive_ptr<T> const & p)
{
    return p.get();
}

template<class T, class U> intrusive_ptr<T> static_pointer_cast(intrusive_ptr<U> const & p)
{
    return static_cast<T *>(p.get());
}

template<class T, class U> intrusive_ptr<T> const_pointer_cast(intrusive_ptr<U> const & p)
{
    return const_cast<T *>(p.get());
}

template<class T, class U> intrusive_ptr<T> dynamic_pointer_cast(intrusive_ptr<U> const & p)
{
    return dynamic_cast<T *>(p.get());
}



#line 251 "../boost/intrusive_ptr.hpp"






template<class E, class T, class Y> std::basic_ostream<E, T> & operator<< (std::basic_ostream<E, T> & os, intrusive_ptr<Y> const & p)

{
    os << p.get();
    return os;
}



} 





#line 24 "smart_ptr.hpp"
#line 1 "../boost/enable_shared_from_this.hpp"















#line 1 "../boost/assert.hpp"
















#line 1 "/usr/include/assert.h"
 
#line 1 "/usr/include/internal/assert_core.h"
 











 
 
 

 
 
 

#ident "$Revision: 1.1 $"









 



extern "C" {







extern void __assert(const char *, const char *, int);
#line 50 "/usr/include/internal/assert_core.h"

}
#line 3 "/usr/include/assert.h"

#line 36 "../boost/assert.hpp"
#line 19 "../boost/enable_shared_from_this.hpp"


namespace boost
{

template<class T> class enable_shared_from_this
{
protected:

    enable_shared_from_this()
    {
    }

    enable_shared_from_this(enable_shared_from_this const &)
    {
    }

    enable_shared_from_this & operator=(enable_shared_from_this const &)
    {
        return *this;
    }

    ~enable_shared_from_this()
    {
    }

public:

    shared_ptr<T> shared_from_this()
    {
        shared_ptr<T> p(_internal_weak_this);
        ((p . get() == this)?((void)0):__assert( "p.get() == this" , "../boost/enable_shared_from_this.hpp", 50));
        return p;
    }

    shared_ptr<T const> shared_from_this() const
    {
        shared_ptr<T const> p(_internal_weak_this);
        ((p . get() == this)?((void)0):__assert( "p.get() == this" , "../boost/enable_shared_from_this.hpp", 57));
        return p;
    }

    typedef T _internal_element_type; 
    mutable weak_ptr<_internal_element_type> _internal_weak_this;
};

} 

#line 25 "smart_ptr.hpp"

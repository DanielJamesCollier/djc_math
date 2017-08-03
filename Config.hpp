#ifndef config_hpp 
#define config_hpp
//----------------------

//------------------------------------------------------------
#define DJC_MATH_STD_IOSTREAM
//------------------------------------------------------------
/*
  - If defined all types will include <iostream> and an overload of << to be used with std::cout
  - If commented out no types will include <iostream> or overload <<
*/



//------------------------------------------------------------
#define DJC_MATH_DEFAULT_TYPE float
//------------------------------------------------------------
/*
  - default template argument for all types
  - i.e template<T = DJC_MATH_DEFAULT_TYPE> class Vec3 { ... };
*/



//------------------------------------------------------------
#define DJC_MATH_EXPLICIT 0
#define DJC_MATH_ARRAY    1
#define DJC_MATH_UNION    2

#define DJC_MATH_VEC_DATA DJC_MATH_EXPLICIT 
//------------------------------------------------------------
/*
  - if defined then the storage of all vec types is represented as T[size] T 
    T being the template type argument and size being the vec size i.e vec3 size = 3
  - if not defined then the storage of all vector types will be x,y,z,w
  - the array representation is usefull when passing the data to another library such as opengl
*/


// implementation details - do not modify 
//------------------------------------------------------------
#define DJC_X x
#define DJC_Y y
#define DJC_Z z
#define DJC_W w

#if DJC_MATH_VEC_DATA == DJC_MATH_ARRAY
#   define DJC_X data[0] 
#   define DJC_Y data[1] 
#   define DJC_Z data[2] 
#   define DJC_W data[3]
#endif
//------------------------------------------------------------

#endif // config_hpp 

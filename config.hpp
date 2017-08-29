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
//------------------------

#define DJC_MATH_VEC_DATA DJC_MATH_EXPLICIT 
//------------------------------------------------------------
/*
 - DJC_MATH_VEC_DATA = DJC_MATH_EXCPLICIT 
   * this means that vec2, vec3, vec4 should be accesed using x,y,z,w 
 
 - DJC_MATH_VEC_DATA = DJC_MATH_ARRAY
   *  this means that vec2, vec3, vec4 should be accessed using array notation. so [0] for x. be carefull as 
      out of bounds access is not handled.

 - DJC_MATH_VEC_DATA = DJC_MATH_UNION
   * this means vec2, vec3, vec4 can being accessed explicity using x,y,z,w or using array notation,
     note that this using union type punning and is not defined to work by the standard, but
     most compilers support it
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

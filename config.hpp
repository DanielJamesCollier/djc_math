#ifndef DJC_MATH_CONFIG_HPP
#define DJC_MATH_CONFIG_HPP
//----------------------

//------------------------------------------------------------
#define DJC_MATH_STD_IOSTREAM
//------------------------------------------------------------
/*
 * - If defined all types will include <iostream> and an overload of << to be used with std::cout
 * - If commented out no types will include <iostream> or overload <<
 */



//------------------------------------------------------------
#define DJC_MATH_DEFAULT_TYPE float
//------------------------------------------------------------
/*
 * - default template argument for all types [vec2, vec3, vec4, quaternion] 
 * - i.e template<T = DJC_MATH_DEFAULT_TYPE> class Vec3 { ... };
 */



//------------------------------------------------------------
#define DJC_MATH_EXPLICIT 0
#define DJC_MATH_ARRAY    1
#define DJC_MATH_UNION    2
//------------------------

#define DJC_MATH_DATA DJC_MATH_EXPLICIT 
//------------------------------------------------------------
/*
 *  - DJC_MATH_DATA = DJC_MATH_EXPLICIT 
 *    this means that [vec2, vec3, vec4, quaternion] should be accesed using x,y,z,w 
 * 
 *  - DJC_MATH_DATA = DJC_MATH_ARRAY
 *     this means that [vec2, vec3, vec4, quaternion] should be accessed using array notation. so [0] for x. be carefull as 
 *     out of bounds access is not handled.
 *
 *  - DJC_MATH_DATA = DJC_MATH_UNION
 *    this means v[vec2, vec3, vec4, quaternion] can being accessed explicity using x,y,z,w or using array notation,
 *   
 *    note that this using union type punning and is not defined to work by the standard, but
 *    most compilers support it but double check to be sure
 */



//------------------------------------------------------------
#define DJC_MATH_QUATERNION_X_REAL 3
#define DJC_MATH_QUATERNION_W_REAL 4
//-------------------------------

#define DJC_MATH_QUATERNION_REAL DJC_MATH_QUATERNION_W_REAL 
//------------------------------------------------------------
/*
 *  - define which part of the quaternion is the real part x or w
 *  - if x is defined as real then y, z, w are the complex parts
 *  - if w is defined as real then x, y, z are the complex parts
 */



// implementation details - do not modify 
//------------------------------------------------------------
// vector types
#define DJC_X x
#define DJC_Y y
#define DJC_Z z
#define DJC_W w

#if DJC_MATH_DATA == DJC_MATH_ARRAY
#   define DJC_X data[0] 
#   define DJC_Y data[1] 
#   define DJC_Z data[2] 
#   define DJC_W data[3]
#endif

// quaternion
#if DJC_MATH_QUATERNION_REAL == DJC_MATH_QUATERNION_X_REAL 
#   define DJC_REAL DJC_X
#   define DJC_COMPLEX_X DJC_Y
#   define DJC_COMPLEX_Y DJC_Z
#   define DJC_COMPLEX_Z DJC_W 
#elif DJC_MATH_QUATERNION_REAL == DJC_MATH_QUATERNION_W_REAL
#   define DJC_COMPLEX_X DJC_X
#   define DJC_COMPLEX_Y DJC_Y
#   define DJC_COMPLEX_Z DJC_Z 
#   define DJC_REAL DJC_W
#endif
//------------------------------------------------------------

#endif // DJC_MATH_CONFIG_HPP

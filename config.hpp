#ifndef CONFIG_HPP
#define CONFIG_HPP
//----------------------

/*
  - If defined all types will include <iostream> and an overload of << to be used with std::cout
  - IF commented out no types will include <iostream> or overload <<
 */
#define DJC_MATH_STD_IOSTREAM

/*
  - default template argument for all types
  - i.e template<T = DJC_MATH_DEFAULT_TYPE> class Vec3 { ....};
 */
#define DJC_MATH_DEFAULT_TYPE float

/*
 - If defined all maths classes will not use eachother
 - example... Vec3 will not allow construction with Vec3(Vec2(0,0), 0)... this 
   applies to all maths classes
 - this define allows you to use a math class independantly without having any
   of the other maths headers.
 */

// @TODO: needs implementing
//#define DJC_MATH_NO_INTERCLASS_DEPENDENCIES

//---------------------
#endif /* CONFIG_HPP */

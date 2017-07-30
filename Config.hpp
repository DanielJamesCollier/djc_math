#ifndef CONFIG_HPP
#define CONFIG_HPP
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
  - i.e template<T = DJC_MATH_DEFAULT_TYPE> class Vec3 { ....};
 */


#endif /* CONFIG_HPP */

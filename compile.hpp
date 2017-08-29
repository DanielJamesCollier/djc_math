#ifndef constexpr_math_hpp
#define constexpr_math_hpp

#include <cstddef> // std::size_t

/* to force all operations to happen at compile time the function return
 must be assigned to a constexpr variable. if not bound to a constexpr variable prepare to incure massive runtime costs :)

example

auto constexpr test =  constexpr_power(2.0f , 10); // compile time
auto test =  constexpr_power(2.0f , 10); // runtime 
*/

namespace djc::math::compile {

//------------------------------------------------------------
template <typename T>
constexpr T constexpr_power(T const& x, std::size_t n);

//------------------------------------------------------------
template<typename T>
constexpr T constexpr_factoral(T x);

//------------------------------------------------------------
constexpr double
constexpr_sqrt(double x);
    
//------------------------------------------------------------
constexpr double
constexpr_sin();
    
//------------------------------------------------------------
constexpr double
constexpr_cos(); // @todo:

//------------------------------------------------------------
constexpr double
constexpr_tan(); // @todo:
    
    
}; // djc::math::compile
#include "./inline/compile.inl"
#endif // constexpr_math_hpp

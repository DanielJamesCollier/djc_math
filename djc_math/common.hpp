#ifndef DJC_MATH_COMMON_HPP 
#define DJC_MATH_COMMON_HPP 

// djc_math 
#include "constants.hpp" 

namespace djc::math {

//------------------------------------------------------------
template <typename T>
constexpr T 
lerp(T v0, T v1, float t);

//------------------------------------------------------------
template <typename T>
constexpr T 
lerp(T v0, T v1, double t);

//------------------------------------------------------------
template<typename T>
constexpr T 
clamp(T v, T low, T hi);

//------------------------------------------------------------
constexpr float 
floor(float val);

//------------------------------------------------------------
constexpr double
floor(double val);

//------------------------------------------------------------
constexpr int
floor_int(float val);

//------------------------------------------------------------
constexpr int 
floor_int(double val);

//------------------------------------------------------------
constexpr float 
to_radians(float degrees);

//------------------------------------------------------------
constexpr double 
to_radians(double degrees);

//------------------------------------------------------------
constexpr float 
to_degrees(float radians);

//------------------------------------------------------------
constexpr double 
to_degrees(double radians);

//------------------------------------------------------------
// map value from range(a, b) -> range(c, d)
template<typename T>
constexpr T
map(T value, T a, T b, T c, T d);

//------------------------------------------------------------
// map value from range(a, b) -> range(0, 1)
template<typename T>
constexpr T
map_AB_01(T value, T a, T b);

//------------------------------------------------------------
// map value from range(a, b) -> range(0, d)
template<typename T>
constexpr T
map_AB_0D(T value, T a, T b, T d); 

//------------------------------------------------------------
// map value from range(0, b) -> range(0, 1)
template<typename T>
constexpr T
map_0B_01(T value, T b);

//------------------------------------------------------------
// map value from range(0, b) -> range(0, d)
template<typename T>
constexpr T
map_0B_0D(T value, T b, T d);

//------------------------------------------------------------
// map value from range(0, b) -> range(c, d)
template<typename T>
constexpr T
map_0B_CD(T value, T b, T c, T d);

//------------------------------------------------------------
// map value from range(0, 1) -> range(0, d)
template<typename T>
constexpr T
map_01_0D(T value, T b);

//------------------------------------------------------------
// map value from range(0, 1) -> range(c, d)
template<typename T>
constexpr T
map_01_CD(T value, T c, T d);

} // namespace djc::math
#include "inline/common_inl.hpp"
#endif // DJC_MATH_COMMON_HPP 

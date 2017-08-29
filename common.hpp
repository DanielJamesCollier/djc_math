#ifndef common_hpp
#define common_hpp

// my
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

} // namespace djc::math
#include "./inline/common.inl"
#endif // common_hpp

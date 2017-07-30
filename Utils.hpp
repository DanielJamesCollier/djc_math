#ifndef utils_hpp
#define utils_hpp

// my
#include "vec4.hpp"
#include "constants.hpp" // pi<T>

// std
#include <cstdlib> // std::rand()
#include <limits> // std::numeric_limits<double>::quiet_NaN() - std::numeric_limits<double>::infinity()

namespace djc::math {

//------------------------------------------------------------
template<typename T> 
constexpr T 
to_radians(T degrees);

//------------------------------------------------------------
inline float 
rand_float_between_zero_one();

//------------------------------------------------------------
inline unsigned char 
rand_UC_Between_0_N_255();

//------------------------------------------------------------
constexpr float
normalise(float valToNormalise, float min, float max);

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
template<typename T>
void
perspective_divide(vec4<T> & vec);

} // namespace djc::math 

#include "inline/utils.inl"
#endif /* utils_hpp */

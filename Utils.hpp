#ifndef utils_hpp
#define utils_hpp

// my
#include "constants.hpp" // pi<T>

// std
#include <cstdlib> // std::rand()

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

} // namespace djc::math 

#include "inline/utils.inl"
#endif /* utils_hpp */

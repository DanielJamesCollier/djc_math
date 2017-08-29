#ifndef Constants_hpp
#define Constants_hpp

namespace djc::math {

//------------------------------------------------------------
template<typename T> 
constexpr T pi = 3.14159265358979323846264338327;

//------------------------------------------------------------
template<typename T> 
constexpr T tau = 6.28318530717958647692528676656;

//------------------------------------------------------------
template<typename T> 
constexpr T half_pi = pi<T> * 0.5;

} // namespace djc::math 
#endif /* Constants_hpp */

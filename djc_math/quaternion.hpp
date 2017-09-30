#ifndef DJC_MATH_QUATERNION_HPP
#define DJC_MATH_QUATERNION_HPP

// djc_math 
#include "config.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

// std
#include <type_traits>
#include <iostream>
#include <cmath>

namespace djc::math {
/*
 * INFO
 * - either x or w in can be used as the real part internaly
 *   specify which one is used in config.hpp and the implementation of
 *   all the functions will change accordingly
 * 
 * - the default construct initialises the real part to 1
 *
 */
template<typename T = DJC_MATH_DEFAULT_TYPE>
class quaternion final {
    static_assert(std::is_floating_point<T>::value, "T must be floating point");
//                         RAII                             // 
//------------------------------------------------------------
public:
    quaternion() noexcept; 
    explicit quaternion(T x, T y, T z, T w) noexcept;
    quaternion(quaternion const & rhs) noexcept = default;
    quaternion(quaternion && rhs) noexcept = default;

//                       functions                          // 
//------------------------------------------------------------
    constexpr vec4<T> to_vec4() const noexcept;
    constexpr T real() const noexcept;
    constexpr vec3<T> complex() const noexcept;

//                   operator overloads                     // 
//------------------------------------------------------------
    constexpr quaternion<T> operator + () const noexcept;
    constexpr quaternion<T> operator - () const noexcept;

    quaternion<T> & operator += (quaternion<T> const & rhs) noexcept;
    quaternion<T> & operator -= (quaternion<T> const & rhs) noexcept;
    quaternion<T> & operator *= (quaternion<T> const & rhs) noexcept;
    quaternion<T> & operator /= (quaternion<T> const & rhs) noexcept;

    quaternion<T> & operator += (T rhs) noexcept;
    quaternion<T> & operator -= (T rhs) noexcept;
    quaternion<T> & operator *= (T rhs) noexcept;
    quaternion<T> & operator /= (T rhs) noexcept;
  
//                         data                             // 
//------------------------------------------------------------
#if DJC_MATH_DATA == DJC_MATH_EXPLICIT
    T x;
    T y;
    T z;
    T w;
    
#elif DJC_MATH_DATA == DJC_MATH_ARRAY
    T data[4];

#elif DJC_MATH_DATA == DJC_MATH_UNION
    union {
        T data[4];

        struct {
            T x;
            T y;
            T z;
            T w;
        };
    };
#endif

}; // quaternion

//                     free functions                       //
//------------------------------------------------------------
template<typename T>
quaternion<T> quaternion_from_euler(vec3<T> const & euler) noexcept;

//------------------------------------------------------------
template<typename T>
quaternion<T> quaternion_from_euler(T x, T y, T z) noexcept;

//------------------------------------------------------------
template<typename T>
quaternion<T> slerp(quaternion<T> const & a, quaternion<T> const & b, T t) noexcept;

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator + (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator - (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator * (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator / (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator + (T lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator - (T lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator * (T lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator / (T lhs, quaternion<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator + (quaternion<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator - (quaternion<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator * (quaternion<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> operator / (quaternion<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
#    if defined(DJC_MATH_STD_IOSTREAM)
template<typename T>
std::ostream & operator << (std::ostream & lhs, quaternion<T> const & rhs);  
#    endif

//            type alias - for use in client code           // 
//------------------------------------------------------------
using quaternion_f = quaternion<float>;
using quaternion_d = quaternion<double>;

} // namespace djc::math
#include "inline/quaternion_inl.hpp"
#endif // DJC_MATH_QUATERNION_HPP

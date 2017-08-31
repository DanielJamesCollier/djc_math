#ifndef vec4_hpp
#define vec4_hpp

// my
#include "vec2.hpp"
#include "vec3.hpp"
#include "config.hpp"

// std
#include <cmath> // std::sqrt
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream> // std::ostream
#   endif
#include <type_traits> // std::is_integral<T> - std::is_floating_point<T>

namespace djc::math {

template<typename T = DJC_MATH_DEFAULT_TYPE>
class vec4 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
public:
//                         RAII                             // 
//------------------------------------------------------------
    constexpr explicit vec4(T _xyzw = T()) noexcept;
    constexpr vec4(T _x, T _y, T _z, T _w) noexcept;
    constexpr vec4(vec2<T> const & _xy, T _z, T _w) noexcept;
    constexpr vec4(T _x, T _y, vec2<T> const & _zw) noexcept;
    constexpr vec4(vec2<T> const & _xy, vec2<T> const & _zw) noexcept;
    constexpr vec4(vec3<T> const & _xyz, T _w) noexcept;
    constexpr vec4(T _x, vec3<T> const & _yzw) noexcept;
    constexpr vec4(vec4<T> const & _rhs) noexcept = default;
    ~vec4() noexcept = default;

//                       functions                         // 
//------------------------------------------------------------
    T length() const noexcept(false);
    constexpr T length2() const noexcept;
    void normalise() noexcept(false);
    constexpr T dot(vec4<T> const & vec) const noexcept;
    
    // for cross cast to vec3
    constexpr vec2<T> to_vec2() const noexcept;
    constexpr vec3<T> to_vec3() const noexcept;

//                   operator overloads                     // 
//------------------------------------------------------------
    constexpr vec4<T> operator + () const noexcept;
    constexpr vec4<T> operator - () const noexcept;

    vec4<T> & operator += (vec4<T> const & rhs) noexcept;
    vec4<T> & operator -= (vec4<T> const & rhs) noexcept;
    vec4<T> & operator *= (vec4<T> const & rhs) noexcept;
    vec4<T> & operator /= (vec4<T> const & rhs) noexcept;

    vec4<T> & operator += (T rhs) noexcept;
    vec4<T> & operator -= (T rhs) noexcept;
    vec4<T> & operator *= (T rhs) noexcept;
    vec4<T> & operator /= (T rhs) noexcept;

//                         data                             // 
//------------------------------------------------------------
#if   DJC_MATH_VEC_DATA == DJC_MATH_EXPLICIT
    T x;
    T y;
    T z;
    T w;

#elif DJC_MATH_VEC_DATA == DJC_MATH_ARRAY
    T data[4]; 

#elif DJC_MATH_VEC_DATA == DJC_MATH_UNION
    union {

        T data[4];

        struct {
            T x;
            T y;
            T z;
            T w;
        };

        struct {
            T r;
            T g;
            T b;
            T a; 
        };
    };
#endif

}; // class vec4


//                  free function operators                 // 
//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator + (vec4<T> const & lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator - (vec4<T> const & lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator * (vec4<T> const & lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator / (vec4<T> const & lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator + (T lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator - (T lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator * (T lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator / (T lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator + (vec4<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator - (vec4<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator * (vec4<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> operator / (vec4<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
#    if defined(DJC_MATH_STD_IOSTREAM)
template<typename T>
std::ostream & operator << (std::ostream & lhs, vec4<T> const & rhs);  
#    endif

// @todo: think about where this should go
//------------------------------------------------------------
// template<typename T>
// vec4<T> operator * (Mat4<T> const & rhs & lhs, vec4<T> const & rhs); - defined in Mat4.inl

//                     free functions                       //
//------------------------------------------------------------
template<typename T>
vec4<T> normalise(vec4<T> const & vec) noexcept(false);

//------------------------------------------------------------
template<typename T>
constexpr T dot(vec4<T> const & lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
vec3<T> limit(vec4<T> vec, T limit) noexcept(false);

//            type alias - for use in client code           // 
//------------------------------------------------------------
using vec4i = vec4<int>;
using vec4f = vec4<float>;
using vec4d = vec4<double>;

} // namespace djc::math 

#include "./inline/vec4.inl"
#endif /* vec4_hpp */

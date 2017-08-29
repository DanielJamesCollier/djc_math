#ifndef vec3_hpp
#define vec3_hpp

// my
#include "vec2.hpp"
#include "config.hpp"

// std
#include <cmath> // std::sqrt
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream> // std::ostream
#   endif
#include <type_traits> // std::is_intergra<T> - std::is_floating_point<T>

namespace djc::math {

template<typename T = DJC_MATH_DEFAULT_TYPE>
class vec3 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
public:
//                         RAII                             // 
//------------------------------------------------------------
    constexpr explicit vec3(T _xyz = T()) noexcept;
    constexpr vec3(T _x, T _y, T _z) noexcept;
    constexpr vec3(vec2<T> const & _xy, T _z) noexcept;
    constexpr vec3(T _x, vec2<T> const & _yz) noexcept;
    constexpr vec3(vec3<T> const & _xyz) noexcept = default;
    ~vec3() noexcept = default;

//                       functions                          // 
//------------------------------------------------------------
    T length() const noexcept(false);
    constexpr T length2() const noexcept;
    void normalise() noexcept(false);
    constexpr T dot(vec3<T> const & vec) const noexcept;
    constexpr vec3<T> cross(vec3<T> const & vec) const noexcept;
    constexpr vec2<T> to_vec2() const noexcept;

//                   operator overloads                     // 
//------------------------------------------------------------
    constexpr vec3<T> operator + () const noexcept;
    constexpr vec3<T> operator - () const noexcept;

    vec3<T> & operator += (vec3<T> const & rhs) noexcept;
    vec3<T> & operator -= (vec3<T> const & rhs) noexcept;
    vec3<T> & operator *= (vec3<T> const & rhs) noexcept;
    vec3<T> & operator /= (vec3<T> const & rhs) noexcept;

    vec3<T> & operator += (T rhs) noexcept;
    vec3<T> & operator -= (T rhs) noexcept;
    vec3<T> & operator *= (T rhs) noexcept;
    vec3<T> & operator /= (T rhs) noexcept;

//                         data                             // 
//------------------------------------------------------------
#if   DJC_MATH_VEC_DATA == DJC_MATH_EXPLICIT 
    T x;
    T y;
    T z;

#elif DJC_MATH_VEC_DATA == DJC_MATH_ARRAY
    T data[3];

#elif DJC_MATH_VEC_DATA == DJC_MATH_UNION
    union {

        T data[3];
        
        struct {
            T x;
            T y;
            T z;
        };

        struct {
            T r;
            T g;
            T b;
        };

        struct {
            T u;
            T v;
            T w;
        };
    };
    
#endif

}; // class vec3


//                  free function operators                 // 
//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator + (vec3<T> const & lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator - (vec3<T> const & lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator * (vec3<T> const & lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator / (vec3<T> const & lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator + (T lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator - (T lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator * (T lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator / (T lhs, vec3<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator + (vec3<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator - (vec3<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator * (vec3<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> operator / (vec3<T> const & lhs, T rhs) noexcept;
   
//------------------------------------------------------------
#    if defined(DJC_MATH_STD_IOSTREAM)
template<typename T>
std::ostream & operator << (std::ostream & lhs, vec3<T> const & rhs);  
#    endif
 
// @todo: think about where this should go
//------------------------------------------------------------
//template<typename T>
//constexpr vec3<T> operator * (Mat3<T> const & lhs, vec3<T> const & rhs); // defined in Mat3.inl

//                     free functions                       //
//------------------------------------------------------------
template<typename T>
vec3<T> normalise(vec3<T> const & vec) noexcept(false);

//------------------------------------------------------------
template<typename T>
constexpr T dot(vec3<T> const & lhs, vec3<T> const & rhs) noexcept;

//            type alias - for use in client code           // 
//------------------------------------------------------------
using vec3i = vec3<int>;
using vec3f = vec3<float>;
using vec3d = vec3<double>;

} // namespace djc::math 

#include "./inline/vec3.inl"
#endif /* vec3_hpp */

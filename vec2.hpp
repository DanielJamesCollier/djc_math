#ifndef vec2_hpp
#define vec2_hpp

// my
#include "config.hpp"

// std
#include <cmath> // std::sqrt
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream> // std::ostream
#   endif
#include <type_traits> // std::is_integral<T> - std::is_floating_point<T>

namespace djc::math {

template<typename T = DJC_MATH_DEFAULT_TYPE>
class vec2 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
public:
//                         RAII                             // 
//------------------------------------------------------------
    constexpr explicit vec2(T _xy = T()) noexcept;
    constexpr vec2(T _x, T _y) noexcept;
    constexpr vec2(vec2<T> const & _xy) noexcept = default;
    ~vec2() noexcept = default;


//                       functions                         // 
//------------------------------------------------------------
     T length() const noexcept(false);
     constexpr T length2() const noexcept;
     void normalise() noexcept(false);
     constexpr T dot(vec2<T> const & vec) const noexcept;

    
//                   operator overloads                     // 
//------------------------------------------------------------
    constexpr vec2<T> operator + () const noexcept;
    constexpr vec2<T> operator - () const noexcept;
    
    vec2<T> & operator += (vec2<T> const & rhs) noexcept;
    vec2<T> & operator -= (vec2<T> const & rhs) noexcept;
    vec2<T> & operator *= (vec2<T> const & rhs) noexcept;
    vec2<T> & operator /= (vec2<T> const & rhs) noexcept;

    vec2<T> & operator += (T rhs) noexcept;
    vec2<T> & operator -= (T rhs) noexcept;
    vec2<T> & operator *= (T rhs) noexcept;
    vec2<T> & operator /= (T rhs) noexcept;

//                         data                             // 
//------------------------------------------------------------
#if   DJC_MATH_VEC_DATA == DJC_MATH_EXPLICIT 
    T x;
    T y;

#elif DJC_MATH_VEC_DATA == DJC_MATH_ARRAY
    T data[2];

#elif DJC_MATH_VEC_DATA == DJC_MATH_UNION
    union {
        
        T data[2];
        
        struct {
            T x;
            T y;
        };
        
        struct {
            T u;
            T v;
        };
    };

#endif

}; // class vec2


//                  free function operators                 // 
//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator + (vec2<T> const & lhs, vec2<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator -  (vec2<T> const & lhs, vec2<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator *  (vec2<T> const & lhs, vec2<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator / (vec2<T> const & lhs, vec2<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator + (T lhs, vec2<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator - (T lhs, vec2<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator * (T lhs, vec2<T> const & rhs) noexcept;
  
//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator / (T lhs, vec2<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator + (vec2<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator - (vec2<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator * (vec2<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> operator / (vec2<T> const & lhs, T rhs) noexcept;

//------------------------------------------------------------
#    if defined(DJC_MATH_STD_IOSTREAM)
template<typename T>
std::ostream & operator << (std::ostream & lhs, vec2<T> const & rhs);  
#    endif

//                     free functions                       //
//------------------------------------------------------------
template<typename T>
vec2<T> normalise(vec2<T> const & vec) noexcept(false);

//------------------------------------------------------------
template<typename T>
constexpr T dot(vec2<T> const & lhs, vec2<T> const & rhs) noexcept;

//            type alias - for use in client code          // 
//------------------------------------------------------------
using vec2i = vec2<int>;
using vec2f = vec2<float>;
using vec2d = vec2<double>;

} // namespace djc::math 

#include "./inline/vec2.inl"
#endif /* vec2_hpp */

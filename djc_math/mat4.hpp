#ifndef DJC_MATH_MAT4_HPP
#define DJC_MATH_MAT4_HPP

// djc_math
#include "vec4.hpp"
#include "mat3.hpp"
#include "config.hpp"

// std
#include <array>
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream> // std::ostream
#   endif
#include <cstddef> // std::size_t
#include <type_traits> // std::is_integral<T> - std::is_floating_point<T>

namespace djc::math {
   
template<typename T = DJC_MATH_DEFAULT_TYPE>
class mat4 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
    static_assert(std::is_nothrow_move_constructible<T>::value, "T must be no throw move constructable");
public:
    //                         RAII                             // 
    //------------------------------------------------------------
    constexpr mat4() noexcept;
    constexpr mat4(std::array<T, 16> const & matrix) noexcept;
    constexpr mat4(mat3<T> const & matrix, T lastVal) noexcept;
    ~mat4() noexcept = default;

    
    //                       operators                          // 
    //------------------------------------------------------------
     constexpr T & operator [] (std::size_t index) noexcept;
     constexpr T const & operator [] (std::size_t index) const noexcept;
   

    //                         data                             // 
    //------------------------------------------------------------
     std::array<T, 16> m_matrix;
     
}; // class mat4
    
//                     free functions                       //
//------------------------------------------------------------
// @TODO:

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T>
constexpr mat4<T>
operator * (mat4<T> const & lhs, mat4<T> const & rhs) noexcept;

//------------------------------------------------------------
template<typename T>
constexpr vec4<T>
operator * (mat4<T> const & lhs, vec4<T> const & rhs) noexcept;

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T>
std::ostream &
operator << (std::ostream & lhs, mat4<T> const & rhs);
#   endif


//            type alias - for use in client code           // 
//------------------------------------------------------------
    using mat4i = mat4<int>;
    using mat4f = mat4<float>;
    using mat4d = mat4<double>;
    
} // namespace djc::math 
#include "inline/mat4_inl.hpp"
#endif // DJC_MATH_MAT4_HPP

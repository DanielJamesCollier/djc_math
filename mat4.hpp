#ifndef mat4_hpp
#define mat4_hpp

// my
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
    
//                template forward declaration              // 
//------------------------------------------------------------
template<typename T> class mat4;
template<typename T> constexpr mat4<T> operator * (mat4<T> const & lhs, mat4<T> const & rhs);
template<typename T> constexpr vec4<T> operator * (mat4<T> const & lhs, vec4<T> const & rhs);
#   if defined(DJC_MATH_STD_IOSTREAM)
 template<typename T> std::ostream & operator << (std::ostream & lhs, mat4<T> const & rhs);
#   endif
   
//                         class                             // 
//------------------------------------------------------------
template<typename T = DJC_MATH_DEFAULT_TYPE>
class mat4 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
    static_assert(std::is_nothrow_move_constructible<T>::value, "T must be no throw move constructable");
public:
    //                         RAII                             // 
    //------------------------------------------------------------
    constexpr mat4() noexcept;
    constexpr explicit mat4(std::array<T, 16> const & matrix) noexcept;
    constexpr mat4(mat3<T> const & matrix, T lastVal) noexcept;
    ~mat4() noexcept = default;
        
    //                       functions                          // 
    //------------------------------------------------------------
    constexpr mat3<T> to_mat3() const noexcept;
        
    //                 friend free operators                    // 
    //------------------------------------------------------------
    friend constexpr mat4<T> operator * <>(mat4<T> const & lhs, mat4<T> const & rhs);
    friend constexpr vec4<T> operator * <>(mat4<T> const & lhs, vec4<T> const & rhs);
#   if defined(DJC_MATH_STD_IOSTREAM)
    friend std::ostream & operator << <>(std::ostream & lhs, mat4<T> const & rhs);
#   endif
    
private:   
    //                 [private] - operators                    // 
    //------------------------------------------------------------
     constexpr T & operator [] (std::size_t index) noexcept;
     constexpr T const & operator [] (std::size_t index) const noexcept;
        
    //                   [private] - data                       // 
    //------------------------------------------------------------
     std::array<T, 16> m_matrix;
     
}; // class mat4
    

//            type alias - for use in client code           // 
//------------------------------------------------------------
    using mat4i = mat4<int>;
    using mat4f = mat4<float>;
    using mat4d = mat4<double>;
    
} // namespace djc::math 

#include "./inline/mat4.inl"
#endif /* mat4_hpp */

#ifndef mat3_hpp
#define mat3_hpp

// my 
#include "vec3.hpp"
#include "config.hpp"

// std
#include <array>
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream> // std::ostream
#   endif

#include <cstddef> // std::size_t
#include <type_traits> // std::is_interral<T> - std::is_floating_point<T>

namespace djc::math {

//                template forward declaration              // 
//------------------------------------------------------------
template<typename T> class mat3;
template<typename T> constexpr mat3<T> operator * (mat3<T> const & lhs, mat3<T> const & rhs);
template<typename T> constexpr vec3<T> operator * (mat3<T> const & lhs, vec3<T> const & rhs);
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream & operator << (std::ostream & lhs, mat3<T> const & rhs);
#   endif

//                         class                             // 
//------------------------------------------------------------
template<typename T = DJC_MATH_DEFAULT_TYPE>
class mat3 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
    static_assert(std::is_nothrow_move_constructible<T>::value, "T must be no throw move constructable");
    
    template<typename U> 
    friend class mat4;

public:
    //                         RAII                             // 
    //------------------------------------------------------------
    constexpr mat3() noexcept;
    constexpr explicit mat3(std::array<T, 9> matrix) noexcept;
    ~mat3() noexcept = default;

    //                 friend free operators                    // 
    //------------------------------------------------------------
    friend mat3<T> constexpr operator * <>(mat3<T> const & lhs, mat3<T> const & rhs); // mat3 * mat3
    friend vec3<T> constexpr operator * <>(mat3<T> const & lhs, vec3<T> const & rhs); // mat3 * vec3
    
    #   if defined(DJC_MATH_STD_IOSTREAM)    
    friend std::ostream & operator << <>(std::ostream & lhs, mat3<T> const & rhs); // std::cout << mat3 
    #   endif

private:   
    //                 [private] - operators                    // 
    //------------------------------------------------------------
    constexpr T & operator [] (std::size_t index) noexcept;
    constexpr T const & operator [] (std::size_t index) const noexcept;

    //                   [private] - data                       // 
    //------------------------------------------------------------
    std::array<T, 9> m_matrix;

}; // class mat3


//            type alias - for use in client code           // 
//------------------------------------------------------------
using mat3i = mat3<int>;
using mat3f = mat3<float>;
using mat3d = mat3<double>;

} // namespace djc::math 

#include "./inline/mat3.inl"
#endif /* mat3_hpp */

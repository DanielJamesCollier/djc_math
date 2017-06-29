#ifndef Mat4_hpp
#define Mat4_hpp

// my
#include "Vec4.hpp"
#include "Mat3.hpp"
#include "Config.hpp"

// std
#include <array>
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream>
#   endif
#include <cstddef> // for std::size_t
#include <type_traits>

namespace djc_math {

// template forward declarations
template<typename T> class Mat4;
template<typename T> constexpr Mat4<T> operator * (Mat4<T> const & lhs, Mat4<T> const & rhs);
template<typename T> constexpr Vec4<T> operator * (Mat4<T> const & lhs, Vec4<T> const & rhs);
#   if defined(DJC_MATH_IOSTREAM)
template<typename T> std::ostream & operator << (std::ostream & lhs, Mat4<T> const & rhs);
#   endif

template<typename T = DJC_MATH_STD_IOSTREAM>
class Mat4 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
    static_assert(std::is_nothrow_move_constructible<T>::value, "T must be no throw move constructable");
public: // RAII
    constexpr Mat4();
    constexpr explicit Mat4(std::array<T, 16> const & matrix);
    constexpr Mat4(Mat3<T> const & matrix, T lastVal);
    ~Mat4() = default;

public: // member - functions
    constexpr Mat3<T> toMat3() const;

public: // friend free functions - // @TODO: needs implementing
    // friend void clear();
    // friend void clear(T value);

public: // friend free operators - defined in Mat4.inl
    friend constexpr Mat4<T> operator *<> (Mat4<T> const & lhs, Mat4<T> const & rhs);
    friend constexpr Vec4<T> operator *<> (Mat4<T> const & lhs, Vec4<T> const & rhs);
    #   if defined(DJC_MATH_STD_IOSTREAM)
    friend std::ostream & operator <<<> (std::ostream & lhs, Mat4<T> const & rhs);  
    #   endif

private: // private operators
    constexpr T & operator [] (std::size_t index);
    constexpr T const & operator [] (std::size_t index) const;

private: // private data
    std::array<T, 16> m_matrix;
};

// for ease of use in C++ 14 - in C++ 17 class templates can be deduced
using Mat4i = Mat4<int>;
using Mat4f = Mat4<float>;
using Mat4d = Mat4<double>;

} /* namespace djc_math */
#include "inline/Mat4.inl"
#endif /* Mat4_hpp */

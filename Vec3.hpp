#ifndef Vec3_hpp
#define Vec3_hpp

// std
#include <cmath>
#include <iostream>
#include <type_traits>

// my
#include "Vec2.hpp"

namespace djc_math {

template<typename T = float>
class Vec3 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
public: // RAII
    constexpr explicit Vec3(T _xyz = T());
    constexpr Vec3(T _x, T _y, T _z);
    constexpr Vec3(Vec2<T> const & _xy, T _z);
    constexpr Vec3(T _x, Vec2<T> const & _yz);
    constexpr Vec3(Vec3<T> const & _xyz) = default;
    ~Vec3() = default;

public: // member - functions
    T length() const;
    constexpr T length2() const;
    void normalise();
    constexpr T dot(Vec3<T> const & vec) const;
    constexpr Vec3<T> cross(Vec3<T> const & vec) const;
    constexpr Vec2<T> toVec2() const;

public:  // member - operator overloads
    constexpr Vec3<T> operator + () const;
    constexpr Vec3<T> operator - () const;

    Vec3<T> & operator += (Vec3<T> const & rhs);
    Vec3<T> & operator -= (Vec3<T> const & rhs);
    Vec3<T> & operator *= (Vec3<T> const & rhs);
    Vec3<T> & operator /= (Vec3<T> const & rhs);

    Vec3<T> & operator += (T rhs);
    Vec3<T> & operator -= (T rhs);
    Vec3<T> & operator *= (T rhs);
    Vec3<T> & operator /= (T rhs);

public: // free function operator overloads - defined in Vec3.inl
    // constexpr Vec3<T> operator + (Vec3<T> const & lhs, Vec3<T> const & rhs);
    // constexpr Vec3<T> operator - (Vec3<T> const & lhs, Vec3<T> const & rhs);
    // constexpr Vec3<T> operator * (Vec3<T> const & lhs, Vec3<T> const & rhs);
    // constexpr Vec3<T> operator / (Vec3<T> const & lhs, Vec3<T> const & rhs);

    // constexpr Vec3<T> operator + (T lhs, Vec3<T> const & rhs);
    // constexpr Vec3<T> operator - (T lhs, Vec3<T> const & rhs);
    // constexpr Vec3<T> operator * (T lhs, Vec3<T> const & rhs);
    // constexpr Vec3<T> operator / (T lhs, Vec3<T> const & rhs);

    // constexpr Vec3<T> operator + (Vec3<T> const & lhs, T rhs);
    // constexpr Vec3<T> operator - (Vec3<T> const & lhs, T rhs);
    // constexpr Vec3<T> operator * (Vec3<T> const & lhs, T rhs);
    // constexpr Vec3<T> operator / (Vec3<T> const & lhs, T rhs);

    // std::ostream & operator << (std::ostream & lhs, Vec3<T> const & rhs);  

public: // free function operator overload for use with other classes
    // constexpr Vec3<T> operator * (Mat3<T> const & lhs, Vec3<T> const & rhs); // defined in Mat3.inl

public: // free functions
    // Vec3<T> normalise(Vec3<T> const & vec);
    // constexpr T dot(Vec3<T> const & lhs, Vec3<T> const & rhs);

public: // public data
    T x;
    T y;
    T z;
};

// for ease of use in C++ 14 - in C++ 17 class templates can be deduced
using Vec3i = Vec3<int>;
using Vec3f = Vec3<float>;
using Vec3d = Vec3<double>;

} /* namespace djc_math */
#include "inline/Vec3.inl"
#endif /* Vec3_hpp */

#ifndef Vec4_hpp
#define Vec4_hpp

// my
#include "Vec2.hpp"
#include "Vec3.hpp"
#include "Config.hpp"

// std
#include <cmath>
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream>
#   endif
#include <type_traits>

namespace djc_math {

template<typename T = DJC_MATH_DEFAULT_TYPE>
class Vec4 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
public: // RAII
    constexpr explicit Vec4(T _xyzw = T());
    constexpr Vec4(T _x, T _y, T _z, T _w);
    constexpr Vec4(Vec2<T> const & _xy, T _z, T _w);
    constexpr Vec4(T _x, T _y, Vec2<T> const & _zw);
    constexpr Vec4(Vec2<T> const & _xy, Vec2<T> const & _zw);
    constexpr Vec4(Vec3<T> const & _xyz, T _w);
    constexpr Vec4(T _x, Vec3<T> const & _yzw);
    constexpr Vec4(Vec4<T> const & _rhs) = default;
    ~Vec4() = default;

public: // member - functions
    T length() const;
    constexpr T length2() const;
    void normalise();
    constexpr T dot(Vec4<T> const & vec) const;
    
    // for cross cast to Vec3
    constexpr Vec2<T> toVec2() const;
    constexpr Vec3<T> toVec3() const;

public: // member - operator overloads
    constexpr Vec4<T> operator + () const;
    constexpr Vec4<T> operator - () const;

    Vec4<T> & operator += (Vec4<T> const & rhs);
    Vec4<T> & operator -= (Vec4<T> const & rhs);
    Vec4<T> & operator *= (Vec4<T> const & rhs);
    Vec4<T> & operator /= (Vec4<T> const & rhs);

    Vec4<T> & operator += (T rhs);
    Vec4<T> & operator -= (T rhs);
    Vec4<T> & operator *= (T rhs);
    Vec4<T> & operator /= (T rhs);

// random function
    // @todo: remove this garbage
    T operator [] (int index) {
        switch(index) {
            case 0: return x; break;
            case 1: return y; break;
            case 2: return z; break;
            case 3: return w; break;
            default: 
                std::cout << "vec4 index invalid\n";
                return T(); // FIX: need to remove this operator for a better solution
                break;
        }
    }

public: // free function operator overloads - defined in Vec4.inl
    //  constexpr Vec4<T> operator + (Vec4<T> const & lhs, Vec4<T> const & rhs);
    //  constexpr Vec4<T> operator - (Vec4<T> const & lhs, Vec4<T> const & rhs);
    //  constexpr Vec4<T> operator * (Vec4<T> const & lhs, Vec4<T> const & rhs);
    //  constexpr Vec4<T> operator / (Vec4<T> const & lhs, Vec4<T> const & rhs);

    //  constexpr Vec4<T> operator + (T lhs, Vec4<T> const & rhs);
    //  constexpr Vec4<T> operator - (T lhs, Vec4<T> const & rhs);
    //  constexpr Vec4<T> operator * (T lhs, Vec4<T> const & rhs);
    //  constexpr Vec4<T> operator / (T lhs, Vec4<T> const & rhs);

    //  constexpr Vec4<T> operator + (Vec4<T> const & lhs, T rhs);
    //  constexpr Vec4<T> operator - (Vec4<T> const & lhs, T rhs);
    //  constexpr Vec4<T> operator * (Vec4<T> const & lhs, T rhs);
    //  constexpr Vec4<T> operator / (Vec4<T> const & lhs, T rhs);
    
    // #    if defined(DJC_MATH_STD_IOSTREAM)
    //  std::ostream & operator << (std::ostream & lhs, Vec4<T> const & rhs);  
    // #    endif

public: // free function operator overload for use with other classes - defined in Vec34.inl
    // Vec4<T> operator * (Mat4<T> const & rhs & lhs, Vec4<T> const & rhs); - defined in Mat4.inl

public: // free functions
    // Vec4<T> normalise(Vec4<T> const & vec);
    // constexpr T dot(Vec4<T> const & lhs, Vec4<T> const & rhs);

public: // public data
    T x;
    T y;
    T z;
    T w;
};

// for ease of use in C++ 14 - in C++ 17 class templates can be deduced
using Vec4i = Vec4<int>;
using Vec4f = Vec4<float>;
using Vec4d = Vec4<double>;

} /* namespace djc_math */
#include "inline/Vec4.inl"
#endif /* Vec4_hpp */

#ifndef Vec2_hpp
#define Vec2_hpp

// my
#include "Config.hpp"

// std
#include <cmath>
#   if defined(DJC_MATH_STD_IOSTREAM)
#include <iostream>
#   endif
#include <type_traits>

namespace djc_math {

template<typename T = DJC_MATH_DEFAULT_TYPE>
class Vec2 final {
    static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value, "T must be intergral or floating point");
public: // RAII
    constexpr explicit Vec2(T _xy = T());
    constexpr Vec2(T _x, T _y);
    constexpr Vec2(Vec2<T> const & _xy) = default;
    ~Vec2() = default;

public: // members - functions
     T length() const;
     constexpr T length2() const;
     void normalise();
     constexpr T dot(Vec2<T> const & vec);

public: // members - operator overloads   
    constexpr Vec2<T> operator + () const;
    constexpr Vec2<T> operator - () const;
    
    Vec2<T> & operator += (Vec2<T> const & rhs);
    Vec2<T> & operator -= (Vec2<T> const & rhs);
    Vec2<T> & operator *= (Vec2<T> const & rhs);
    Vec2<T> & operator /= (Vec2<T> const & rhs);

    Vec2<T> & operator += (T rhs);
    Vec2<T> & operator -= (T rhs);
    Vec2<T> & operator *= (T rhs);
    Vec2<T> & operator /= (T rhs);

public: // free functions - operator overloads 
    // constexpr Vec2<T> operator + (Vec2<T> const & lhs, Vec2<T> const & rhs);
    // constexpr Vec2<T> operator - (Vec2<T> const & lhs, Vec2<T> const & rhs);
    // constexpr Vec2<T> operator * (Vec2<T> const & lhs, Vec2<T> const & rhs);
    // constexpr Vec2<T> operator / (Vec2<T> const & lhs, Vec2<T> const & rhs);

    // constexpr Vec2<T> operator + (T lhs, Vec2<T> const & rhs);
    // constexpr Vec2<T> operator - (T lhs, Vec2<T> const & rhs);
    // constexpr Vec2<T> operator * (T lhs, Vec2<T> const & rhs);
    // constexpr Vec2<T> operator / (T lhs, Vec2<T> const & rhs);
    
    // constexpr Vec2<T> operator + (Vec2<T> const & lhs, T rhs);
    // constexpr Vec2<T> operator - (Vec2<T> const & lhs, T rhs);
    // constexpr Vec2<T> operator * (Vec2<T> const & lhs, T rhs);
    // constexpr Vec2<T> operator / (Vec2<T> const & lhs, T rhs);
    
    // #    if _defined(DJC_MATH_STD_IOSTREAM)
    // std::ostream & operator << (std::ostream & lhs, Vec2<T> const & rhs);  
    // #    endif

public: // free functions
    // Vec2<T> normalise(Vec2<T> const & vec);
    // constexpr T dot(Vec2<T> const & lhs, Vec2<T> const & rhs);

public:
    T x;
    T y;
};

// for ease of use in C++ 14 - in C++ 17 class templates can be deduced
using Vec2i = Vec2<int>;
using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;

} /* namespace djc_math */
#include "inline/Vec2.inl"
#endif /* Vec2_hpp */

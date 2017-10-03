namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
vec2<T>::vec2(T _xy) noexcept 
:   DJC_X{_xy}
,   DJC_Y{_xy}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec2<T>::vec2(T _x, T _y) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}{}

//                       functions                         // 
//------------------------------------------------------------
template<typename T>
constexpr std::size_t 
vec2<T>::size() const noexcept {
    return 2;
}

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T> 
vec2<T>::operator + () const noexcept {
    return {+DJC_X, +DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T> 
vec2<T>::operator - () const noexcept {
    return {-DJC_X, -DJC_Y};
}

//------------------------------------------------------------
template<typename T>
vec2<T> &
vec2<T>::operator += (vec2<T> const & rhs) noexcept {
    DJC_X += rhs.DJC_X;
    DJC_Y += rhs.DJC_Y;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator -= (vec2<T> const & rhs) noexcept {
    DJC_X -= rhs.DJC_X;
    DJC_Y -= rhs.DJC_Y;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> & 
vec2<T>::operator *= (vec2<T> const & rhs) noexcept {
    DJC_X *= rhs.DJC_X;
    DJC_Y *= rhs.DJC_Y;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator /= (vec2<T> const & rhs) noexcept {
    DJC_X /= rhs.DJC_X;
    DJC_Y /= rhs.DJC_Y;
    return *this;
}

//------------------------------------------------------------
template<typename T>
vec2<T> &
vec2<T>::operator += (T rhs) noexcept {
    DJC_X += rhs;
    DJC_Y += rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator -= (T rhs) noexcept {
    DJC_X -= rhs;
    DJC_Y -= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator *= (T rhs) noexcept {
    DJC_X *= rhs;
    DJC_Y *= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator /= (T rhs) noexcept {
    DJC_X /= rhs;
    DJC_Y /= rhs;
    return *this;
}

//                     free functions                       //
//------------------------------------------------------------
template<typename T>
T
magnitude(vec2<T> const & vec) noexcept {
    return std::sqrt(vec.DJC_X * vec.DJC_X + vec.DJC_Y * vec.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
magnitude_squared(vec2<T> const & vec) noexcept {
    return vec.DJC_X * vec.DJC_X + vec.DJC_Y * vec.DJC_Y;
}

//------------------------------------------------------------
template<typename T> vec2<T>
normalise(vec2<T> const & vec) noexcept {
    T length {std::sqrt((vec.DJC_X * vec.DJC_X) + (vec.DJC_Y * vec.DJC_Y))};
    return {vec.DJC_X / length, vec.DJC_Y / length};
}

//------------------------------------------------------------
template<typename T> 
constexpr T
dot(vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return (lhs.DJC_X * rhs.DJC_X) + (lhs.DJC_Y * rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T>
vec2<T>
clamp_magnitude(vec2<T> vec, T max) noexcept {
    T length {djc::math::magnitude(vec)};

    if (length > max) {
        vec = djc::math::normalise(vec);
        vec *= max;
    }

    return vec;
}

//------------------------------------------------------------
template<typename T>
vec2<T>
clamp(vec2<T> vec, T min, T max) noexcept {
    T length {djc::math::magnitude(vec)};
    
    if (length > max) {
        vec = djc::math::normalise(vec);
        vec *= max;
    } else if (length < min) {
        vec = djc::math::normalise(vec);
        vec *= min;
    }

    return vec;
}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return {lhs.DJC_X + rhs.DJC_X, lhs.DJC_Y + rhs.DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return {lhs.DJC_X - rhs.DJC_X, lhs.DJC_Y - rhs.DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return {lhs.DJC_X * rhs.DJC_X, lhs.DJC_Y * rhs.DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return {lhs.DJC_X / rhs.DJC_X, lhs.DJC_Y / rhs.DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (T lhs, vec2<T> const & rhs) noexcept {
    return {lhs + rhs.DJC_X, lhs + rhs.DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (T lhs, vec2<T> const & rhs) noexcept {
    return {lhs - rhs.DJC_X, lhs - rhs.DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (T lhs, vec2<T> const & rhs) noexcept {
    return {lhs * rhs.DJC_X, lhs * rhs.DJC_Y};
}
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (T lhs, vec2<T> const & rhs) noexcept {
    return {lhs / rhs.DJC_X, lhs / rhs.DJC_Y};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (vec2<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X + rhs, lhs.DJC_Y + rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (vec2<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X - rhs, lhs.DJC_Y - rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (vec2<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X * rhs, lhs.DJC_Y * rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (vec2<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X / rhs, lhs.DJC_Y / rhs};
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec2<T> const & rhs) {
    return lhs << "vec2(" << rhs.DJC_X << ", " << rhs.DJC_Y << ")";
}
#   endif

} // namespace djc::math 

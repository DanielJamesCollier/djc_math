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
T
vec2<T>::length() const noexcept(false) {
    return std::sqrt(DJC_X * DJC_X + DJC_Y * DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec2<T>::length2() const noexcept {
    return DJC_X * DJC_X + DJC_Y * DJC_Y;
}

//------------------------------------------------------------
template<typename T> 
void
vec2<T>::normalise() noexcept(false) {
    T length {std::sqrt(DJC_X * DJC_X + DJC_Y * DJC_Y)};
    DJC_X /= length;
    DJC_Y /= length;
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec2<T>::dot(vec2<T> const & vec) const noexcept {
    return DJC_X * vec.DJC_X + DJC_Y * vec.DJC_Y;
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
limit(vec2<T> vec, T limit) noexcept {
    T length {vec.length()};

    if (length > limit) {
        vec.normalise();
        vec *= limit;
    }

    return vec;
}

//------------------------------------------------------------
template<typename T>
vec2<T>
clamp(vec2<T> vec, T min, T max) noexcept {
    T length {vec.length()};
    
    if (vec.length > max) {
        vec.normalise();
        vec *= max;
    } else if (vec.length < min) {
        vec.normalise();
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
    return {lhs * rhs.DJC_X, lhs * rhs.DJC_Y};
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

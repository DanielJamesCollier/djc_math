namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
vec2<T>::vec2(T _xy) noexcept 
:   DJC_X{_xy}
,   DJC_Y{_xy}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec2<T>::vec2(T _x, T _y) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}
{
    // empty
}


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
    return vec2<T>(DJC_X, DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T> 
vec2<T>::operator - () const noexcept {
    return vec2<T>(-DJC_X, -DJC_Y);
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

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.DJC_X + rhs.DJC_X, lhs.DJC_Y + rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.DJC_X - rhs.DJC_X, lhs.DJC_Y - rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.DJC_X * rhs.DJC_X, lhs.DJC_Y * rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.DJC_X / rhs.DJC_X, lhs.DJC_Y / rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs + rhs.DJC_X, lhs + rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs - rhs.DJC_X, lhs - rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs * rhs.DJC_X, lhs * rhs.DJC_Y);
}
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs * rhs.DJC_X, lhs * rhs.DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.DJC_X + rhs, lhs.DJC_Y + rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.DJC_X - rhs, lhs.DJC_Y - rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.DJC_X * rhs, lhs.DJC_Y * rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.DJC_X / rhs, lhs.DJC_Y / rhs);
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec2<T> const & rhs) {
    return lhs << "vec2(" << rhs.DJC_X << ", " << rhs.DJC_Y << ")";
}
#   endif

//                     free functions                       //
//------------------------------------------------------------
template<typename T> vec2<T>
normalise(vec2<T> const & vec) noexcept(false) {
    T length {std::sqrt((vec.DJC_X * vec.DJC_X) + (vec.DJC_Y * vec.DJC_Y))};
    return vec2<T>(vec.DJC_X / length, vec.DJC_Y / length);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
dot(vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return (lhs.DJC_X * rhs.DJC_X) + (lhs.DJC_Y * rhs.DJC_Y);
}

} // namespace djc::math 

namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
vec2<T>::vec2(T _xy) noexcept 
:   x(_xy)
,   y(_xy)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec2<T>::vec2(T _x, T _y) noexcept 
:   x(_x)
,   y(_y)
{
    // empty
}


//                       functions                         // 
//------------------------------------------------------------
template<typename T>
T
vec2<T>::length() const noexcept(false) {
    return std::sqrt(x * x + y * y);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec2<T>::length2() const noexcept {
    return x * x + y * y;
}

//------------------------------------------------------------
template<typename T> 
void
vec2<T>::normalise() noexcept(false) {
    T length = std::sqrt(x * x + y * y);
    x /= length;
    y /= length;
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec2<T>::dot(vec2<T> const & vec) const noexcept {
    return x * vec.x + y * vec.y;
}

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T> 
vec2<T>::operator + () const noexcept {
    return vec2<T>(x, y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T> 
vec2<T>::operator - () const noexcept {
    return vec2<T>(-x, -y);
}

//------------------------------------------------------------
template<typename T>
vec2<T> &
vec2<T>::operator += (vec2<T> const & rhs) noexcept {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator -= (vec2<T> const & rhs) noexcept {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> & 
vec2<T>::operator *= (vec2<T> const & rhs) noexcept {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator /= (vec2<T> const & rhs) noexcept {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

//------------------------------------------------------------
template<typename T>
vec2<T> &
vec2<T>::operator += (T rhs) noexcept {
    x += rhs;
    y += rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator -= (T rhs) noexcept {
    x -= rhs;
    y -= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator *= (T rhs) noexcept {
    x *= rhs;
    y *= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec2<T> &
vec2<T>::operator /= (T rhs) noexcept {
    x /= rhs;
    y /= rhs;
    return *this;
}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs.x / rhs.x, lhs.y / rhs.y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs + rhs.x, lhs + rhs.y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs - rhs.x, lhs - rhs.y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs * rhs.x, lhs * rhs.y);
}
//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (T lhs, vec2<T> const & rhs) noexcept {
    return vec2<T>(lhs * rhs.x, lhs * rhs.y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator + (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.x + rhs, lhs.y + rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator - (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.x - rhs, lhs.y - rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator * (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.x * rhs, lhs.y * rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
operator / (vec2<T> const & lhs, T rhs) noexcept {
    return vec2<T>(lhs.x / rhs, lhs.y / rhs);
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec2<T> const & rhs) {
    return lhs << "vec2(" << rhs.x << ", " << rhs.y << ")";
}
#   endif

//                     free functions                       //
//------------------------------------------------------------
template<typename T> vec2<T>
normalise(vec2<T> const & vec) noexcept(false) {
    T length = std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
    return vec2<T>(vec.x / length, vec.y / length);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
dot(vec2<T> const & lhs, vec2<T> const & rhs) noexcept {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

} // namespace djc::math 

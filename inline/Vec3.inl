namespace djc::math {

// RAII

//------------------------------------------------------------
template<typename T> 
constexpr
vec3<T>::vec3(T _xyz) noexcept 
:   x(_xyz)
,   y(_xyz)
,   z(_xyz) 
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec3<T>::vec3(T _x, T _y, T _z) noexcept 
: x(_x)
, y(_y)
, z(_z)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec3<T>::vec3(vec2<T> const & _xy, T _z) noexcept 
: x(_xy.x)
, y(_xy.y)
, z(_z)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr 
vec3<T>::vec3(T _x, vec2<T> const & _yz) noexcept
:   x(_x)
,   y(_yz.x)
,   z(_yz.y)
{
    // empty
}
// member - functions

//------------------------------------------------------------
template<typename T> 
T
vec3<T>::length() const noexcept(false) {
    return std::sqrt(x * x + y * y + z * z);
}

//------------------------------------------------------------
template<typename T> 
T constexpr
vec3<T>::length2() const noexcept {
    return x * x + y * y + z * z;
}

//------------------------------------------------------------
template<typename T> 
void
vec3<T>::normalise() noexcept(false) {
    T length = std::sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec3<T>::dot(vec3<T> const & vec) const noexcept {
    return x * vec.x + y * vec.y + z * vec.z;
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
vec3<T>::cross(vec3<T> const & vec) const noexcept {
    return vec3<T>((y * vec.z) - (z * vec.y),
                   (z * vec.x) - (x * vec.z),
                   (x * vec.y) - (y * vec.x));
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
vec3<T>::to_vec2() const noexcept {
    return vec2<T>(x, y);
}

// member - operator overloads

//------------------------------------------------------------
template<typename T>
constexpr vec3<T>
vec3<T>::operator + () const noexcept {
    return vec3<T>(x, y, z);
}

//------------------------------------------------------------
template<typename T>
constexpr vec3<T>
vec3<T>::operator - () const noexcept {
    return vec3<T>(-x, -y, -z);
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator += (vec3<T> const & rhs) noexcept {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

//------------------------------------------------------------
template<typename T>
vec3<T> &
vec3<T>::operator -= (vec3<T> const & rhs) noexcept {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

//------------------------------------------------------------
template<typename T>
vec3<T> &
vec3<T>::operator *= (vec3<T> const & rhs) noexcept {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator /= (vec3<T> const & rhs) noexcept {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator += (T rhs) noexcept {
    x += rhs;
    y += rhs;
    z += rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator -= (T rhs) noexcept {
    x -= rhs;
    y -= rhs;
    z -= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator *= (T rhs) noexcept{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator /= (T rhs) noexcept {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

// free function operator overloads

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec3<T> const & rhs) {
    lhs << "vec3\n-----------------\n";
    lhs << "vec3(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ")\n";
    lhs << "-----------------\n";
    return lhs;
}
#   endif

// free functions

//------------------------------------------------------------
template<typename T> 
vec3<T>
normalise(vec3<T> const & vec) noexcept(false) {
    T length = std::sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
    return vec3<T>(vec.x / length, vec.y / length, vec.z / length);
}

//------------------------------------------------------------
template<typename T> 
constexpr T 
dot(vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

} // namespace djc::math 

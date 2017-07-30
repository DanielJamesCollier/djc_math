namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _xyzw) noexcept 
:   x(_xyzw)
,   y(_xyzw)
,   z(_xyzw)
,   w(_xyzw)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, T _y, T _z, T _w) noexcept 
:   x(_x)
,   y(_y)
,   z(_z)
,   w(_w)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec2<T> const & _xy, T _z, T _w) noexcept
:   x(_xy.x)
,   y(_xy.y)
,   z(_z)
,   w(_w)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, T _y, vec2<T> const & _zw) noexcept 
:   x(_x)
,   y(_y)
,   z(_zw.x)
,   w(_zw.y) 
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec2<T> const & _xy, vec2<T> const & _zw) noexcept
:   x(_xy.x)
,   y(_xy.y)
,   z(_zw.x)
,   w(_zw.y)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec3<T> const & _xyz, T _w) noexcept  
:   x(_xyz.x)
,   y(_xyz.y)
,   z(_xyz.z)
,   w(_w)
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, vec3<T> const & _yzw) noexcept
:   x(_x)
,   y(_yzw.x)
,   z(_yzw.y)
,   w(_yzw.z)
{
    // empty
}

//                       functions                         // 
//------------------------------------------------------------
template<typename T>
T
vec4<T>::length() const noexcept(false) {
    return std::sqrt(x * x + y * y + z * z + w * w);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec4<T>::length2() const noexcept {
    return x * x + y * y + z * z + w * w;
}

//------------------------------------------------------------
template<typename T>
void
vec4<T>::normalise() noexcept(false) {
    T length = std::sqrt(x * x + y * y + z * z + w * w);
    x /= length;
    y /= length;
    z /= length;
    w /= length;
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec4<T>::dot(vec4<T> const & vec) const noexcept {
     return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
vec4<T>::to_vec2() const noexcept {
    return vec2<T>(x, y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
vec4<T>::to_vec3() const noexcept {
    return vec3<T>(x, y, z);
}

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
vec4<T>::operator + () const noexcept {
    return vec4<T>(x, y, z, w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
vec4<T>::operator - () const noexcept {
    return vec4<T>(-x, -y, -z, -w);
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator += (vec4<T> const & rhs) noexcept {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator -= (vec4<T> const & rhs) noexcept {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator *= (vec4<T> const & rhs) noexcept {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    w *= rhs.w;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator /= (vec4<T> const & rhs) noexcept {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    w /= rhs.w;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator += (T rhs) noexcept {
    x += rhs;
    y += rhs;
    z += rhs;
    w += rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator -= (T rhs) noexcept {
    x -= rhs;
    y -= rhs;
    z -= rhs;
    w -= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator *= (T rhs) noexcept {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator /= (T rhs) noexcept {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    w /= rhs;
    return *this;
}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator + (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> 
operator - (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator * (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator / (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator + (T lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z, lhs + rhs.w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator - (T lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z, lhs - rhs.w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator * (T lhs, vec4<T> const & rhs) noexcept { 
    return vec4<T>(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator / (T lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z, lhs / rhs.w);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator + (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.x + rhs, lhs.y + rhs, lhs.z + rhs, lhs.w + rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator - (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.x - rhs, lhs.y - rhs, lhs.z - rhs, lhs.w - rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator * (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator / (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec4<T> const & rhs) {
    lhs << "vec4(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ", " << rhs.w << ")";
    return lhs;
}
#   endif

//                     free functions                       //
//------------------------------------------------------------
template<typename T> vec4<T>
normalise(vec4<T> const & vec) noexcept(false) {
    T length = std::sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z) + (vec.w * vec.w));
    return vec4<T>(vec.x / length, vec.y / length, vec.z / length, vec.w / length);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
dot(vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
   return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
}

} // namespace djc::math 

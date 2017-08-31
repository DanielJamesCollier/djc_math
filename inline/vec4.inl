namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _xyzw) noexcept 
:   DJC_X{_xyzw}
,   DJC_Y{_xyzw}
,   DJC_Z{_xyzw}
,   DJC_W{_xyzw}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, T _y, T _z, T _w) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}
,   DJC_Z{_z}
,   DJC_W{_w}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec2<T> const & _xy, T _z, T _w) noexcept
:   DJC_X{_xy.DJC_X}
,   DJC_Y{_xy.DJC_Y}
,   DJC_Z{_z}
,   DJC_W{_w}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, T _y, vec2<T> const & _zw) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}
,   DJC_Z{_zw.DJC_X}
,   DJC_W{_zw.DJC_Y}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec2<T> const & _xy, vec2<T> const & _zw) noexcept
:   DJC_X{_xy.DJC_X}
,   DJC_Y{_xy.DJC_Y}
,   DJC_Z{_zw.DJC_X}
,   DJC_W{_zw.DJC_Y}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec3<T> const & _xyz, T _w) noexcept  
:   DJC_X{_xyz.DJC_X}
,   DJC_Y{_xyz.DJC_Y}
,   DJC_Z{_xyz.DJC_Z}
,   DJC_W{_w}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, vec3<T> const & _yzw) noexcept
:   DJC_X{_x}
,   DJC_Y{_yzw.DJC_X}
,   DJC_Z{_yzw.DJC_Y}
,   DJC_W{_yzw.DJC_Z}
{
    // empty
}

//                       functions                         // 
//------------------------------------------------------------
template<typename T>
T
vec4<T>::length() const noexcept(false) {
    return std::sqrt(DJC_X * DJC_X + DJC_Y * DJC_Y + DJC_Z * DJC_Z + DJC_W * DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec4<T>::length2() const noexcept {
    return DJC_X * DJC_X + DJC_Y * DJC_Y + DJC_Z * DJC_Z + DJC_W * DJC_W;
}

//------------------------------------------------------------
template<typename T>
void
vec4<T>::normalise() noexcept(false) {
    T length {std::sqrt(DJC_X * DJC_X + DJC_Y * DJC_Y + DJC_Z * DJC_Z + DJC_W * DJC_W)};
    DJC_X /= length;
    DJC_Y /= length;
    DJC_Z /= length;
    DJC_W /= length;
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec4<T>::dot(vec4<T> const & vec) const noexcept {
     return DJC_X * vec.DJC_X + DJC_Y * vec.DJC_Y + DJC_Z * vec.DJC_Z + DJC_W * vec.DJC_W;
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
vec4<T>::to_vec2() const noexcept {
    return vec2<T>(DJC_X, DJC_Y);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
vec4<T>::to_vec3() const noexcept {
    return vec3<T>(DJC_X, DJC_Y, DJC_Z);
}

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
vec4<T>::operator + () const noexcept {
    return vec4<T>(DJC_X, DJC_Y, DJC_Z, DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
vec4<T>::operator - () const noexcept {
    return vec4<T>(-DJC_X, -DJC_Y, -DJC_Z, -DJC_W);
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator += (vec4<T> const & rhs) noexcept {
    DJC_X += rhs.DJC_X;
    DJC_Y += rhs.DJC_Y;
    DJC_Z += rhs.DJC_Z;
    DJC_W += rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator -= (vec4<T> const & rhs) noexcept {
    DJC_X -= rhs.DJC_X;
    DJC_Y -= rhs.DJC_Y;
    DJC_Z -= rhs.DJC_Z;
    DJC_W -= rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator *= (vec4<T> const & rhs) noexcept {
    DJC_X *= rhs.DJC_X;
    DJC_Y *= rhs.DJC_Y;
    DJC_Z *= rhs.DJC_Z;
    DJC_W *= rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator /= (vec4<T> const & rhs) noexcept {
    DJC_X /= rhs.DJC_X;
    DJC_Y /= rhs.DJC_Y;
    DJC_Z /= rhs.DJC_Z;
    DJC_W /= rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator += (T rhs) noexcept {
    DJC_X += rhs;
    DJC_Y += rhs;
    DJC_Z += rhs;
    DJC_W += rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator -= (T rhs) noexcept {
    DJC_X -= rhs;
    DJC_Y -= rhs;
    DJC_Z -= rhs;
    DJC_W -= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator *= (T rhs) noexcept {
    DJC_X *= rhs;
    DJC_Y *= rhs;
    DJC_Z *= rhs;
    DJC_W *= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec4<T> &
vec4<T>::operator /= (T rhs) noexcept {
    DJC_X /= rhs;
    DJC_Y /= rhs;
    DJC_Z /= rhs;
    DJC_W /= rhs;
    return *this;
}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator + (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.DJC_X + rhs.DJC_X, lhs.DJC_Y + rhs.DJC_Y, lhs.DJC_Z + rhs.DJC_Z, lhs.DJC_W + rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> 
operator - (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.DJC_X - rhs.DJC_X, lhs.DJC_Y - rhs.DJC_Y, lhs.DJC_Z - rhs.DJC_Z, lhs.DJC_W - rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator * (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.DJC_X * rhs.DJC_X, lhs.DJC_Y * rhs.DJC_Y, lhs.DJC_Z * rhs.DJC_Z, lhs.DJC_W * rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator / (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs.DJC_X / rhs.DJC_X, lhs.DJC_Y / rhs.DJC_Y, lhs.DJC_Z / rhs.DJC_Z, lhs.DJC_W / rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator + (T lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs + rhs.DJC_X, lhs + rhs.DJC_Y, lhs + rhs.DJC_Z, lhs + rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator - (T lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs - rhs.DJC_X, lhs - rhs.DJC_Y, lhs - rhs.DJC_Z, lhs - rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator * (T lhs, vec4<T> const & rhs) noexcept { 
    return vec4<T>(lhs * rhs.DJC_X, lhs * rhs.DJC_Y, lhs * rhs.DJC_Z, lhs * rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator / (T lhs, vec4<T> const & rhs) noexcept {
    return vec4<T>(lhs / rhs.DJC_X, lhs / rhs.DJC_Y, lhs / rhs.DJC_Z, lhs / rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator + (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.DJC_X + rhs, lhs.DJC_Y + rhs, lhs.DJC_Z + rhs, lhs.DJC_W + rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator - (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.DJC_X - rhs, lhs.DJC_Y - rhs, lhs.DJC_Z - rhs, lhs.DJC_W - rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator * (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.DJC_X * rhs, lhs.DJC_Y * rhs, lhs.DJC_Z * rhs, lhs.DJC_W * rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator / (vec4<T> const & lhs, T rhs) noexcept {
    return vec4<T>(lhs.DJC_X / rhs, lhs.DJC_Y / rhs, lhs.DJC_Z / rhs, lhs.DJC_W / rhs);
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec4<T> const & rhs) {
    lhs << "vec4(" << rhs.DJC_X << ", " << rhs.DJC_Y << ", " << rhs.DJC_Z << ", " << rhs.DJC_W << ")";
    return lhs;
}
#   endif

//                     free functions                       //
//------------------------------------------------------------
template<typename T> vec4<T>
normalise(vec4<T> const & vec) noexcept(false) {
    T length {std::sqrt((vec.DJC_X * vec.DJC_X) + (vec.DJC_Y * vec.DJC_Y) + (vec.DJC_Z * vec.DJC_Z) + (vec.DJC_W * vec.DJC_W))};
    return vec4<T>(vec.DJC_X / length, vec.DJC_Y / length, vec.DJC_Z / length, vec.DJC_W / length);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
dot(vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
   return (lhs.DJC_X * rhs.DJC_X) + (lhs.DJC_Y * rhs.DJC_Y) + (lhs.DJC_Z * rhs.DJC_Z) + (lhs.DJC_W * rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T>
vec4<T>
limit(vec4<T> vec, T limit) noexcept(false) {
    T length {vec.length()};

    if (length > limit) {
        vec.normalise();
        vec *= limit;
    }

    return vec;
}

} // namespace djc::math 

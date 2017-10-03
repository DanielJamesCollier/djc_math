namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _xyzw) noexcept 
:   DJC_X{_xyzw}
,   DJC_Y{_xyzw}
,   DJC_Z{_xyzw}
,   DJC_W{_xyzw}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, T _y, T _z, T _w) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}
,   DJC_Z{_z}
,   DJC_W{_w}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec2<T> const & _xy, T _z, T _w) noexcept
:   DJC_X{_xy.DJC_X}
,   DJC_Y{_xy.DJC_Y}
,   DJC_Z{_z}
,   DJC_W{_w}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, T _y, vec2<T> const & _zw) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}
,   DJC_Z{_zw.DJC_X}
,   DJC_W{_zw.DJC_Y}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec2<T> const & _xy, vec2<T> const & _zw) noexcept
:   DJC_X{_xy.DJC_X}
,   DJC_Y{_xy.DJC_Y}
,   DJC_Z{_zw.DJC_X}
,   DJC_W{_zw.DJC_Y}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(vec3<T> const & _xyz, T _w) noexcept  
:   DJC_X{_xyz.DJC_X}
,   DJC_Y{_xyz.DJC_Y}
,   DJC_Z{_xyz.DJC_Z}
,   DJC_W{_w}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec4<T>::vec4(T _x, vec3<T> const & _yzw) noexcept
:   DJC_X{_x}
,   DJC_Y{_yzw.DJC_X}
,   DJC_Z{_yzw.DJC_Y}
,   DJC_W{_yzw.DJC_Z}{}

//                       functions                         // 
//------------------------------------------------------------
template<typename T>
constexpr std::size_t
vec4<T>::size() const noexcept {
    return 4;
}

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
vec4<T>::operator + () const noexcept {
    return {+DJC_X, +DJC_Y, +DJC_Z, +DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
vec4<T>::operator - () const noexcept {
    return {-DJC_X, -DJC_Y, -DJC_Z, -DJC_W};
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

//                     free functions                       //
//------------------------------------------------------------
template<typename T>
T
magnitude(vec4<T> const & vec) noexcept {
    return std::sqrt(vec.DJC_X * vec.DJC_X + vec.DJC_Y * vec.DJC_Y + vec.DJC_Z * vec.DJC_Z + vec.DJC_W * vec.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr T
magnitude_squared(vec4<T> const & vec) noexcept {
    return vec.DJC_X * vec.DJC_X + vec.DJC_Y * vec.DJC_Y + vec.DJC_Z * vec.DJC_Z + vec.DJC_W * vec.DJC_W;
}

//------------------------------------------------------------
template<typename T> vec4<T>
normalise(vec4<T> const & vec) noexcept {
    T length {std::sqrt((vec.DJC_X * vec.DJC_X) + (vec.DJC_Y * vec.DJC_Y) + (vec.DJC_Z * vec.DJC_Z) + (vec.DJC_W * vec.DJC_W))};
    return {vec.DJC_X / length, vec.DJC_Y / length, vec.DJC_Z / length, vec.DJC_W / length};
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
clamp_magnitude(vec4<T> vec, T max) noexcept {
    T length {djc::math::magnitude(vec)};

    if (length > max) {
        vec = djc::math::normalise(vec);
        vec *= max;
    }

    return vec;
}

//------------------------------------------------------------
template<typename T>
vec4<T>
clamp(vec4<T> vec, T min, T max) noexcept {
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
constexpr vec4<T> 
operator + (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return {lhs.DJC_X + rhs.DJC_X, lhs.DJC_Y + rhs.DJC_Y, lhs.DJC_Z + rhs.DJC_Z, lhs.DJC_W + rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> 
operator - (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return {lhs.DJC_X - rhs.DJC_X, lhs.DJC_Y - rhs.DJC_Y, lhs.DJC_Z - rhs.DJC_Z, lhs.DJC_W - rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator * (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return {lhs.DJC_X * rhs.DJC_X, lhs.DJC_Y * rhs.DJC_Y, lhs.DJC_Z * rhs.DJC_Z, lhs.DJC_W * rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator / (vec4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return {lhs.DJC_X / rhs.DJC_X, lhs.DJC_Y / rhs.DJC_Y, lhs.DJC_Z / rhs.DJC_Z, lhs.DJC_W / rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator + (T lhs, vec4<T> const & rhs) noexcept {
    return {lhs + rhs.DJC_X, lhs + rhs.DJC_Y, lhs + rhs.DJC_Z, lhs + rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator - (T lhs, vec4<T> const & rhs) noexcept {
    return {lhs - rhs.DJC_X, lhs - rhs.DJC_Y, lhs - rhs.DJC_Z, lhs - rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator * (T lhs, vec4<T> const & rhs) noexcept { 
    return {lhs * rhs.DJC_X, lhs * rhs.DJC_Y, lhs * rhs.DJC_Z, lhs * rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator / (T lhs, vec4<T> const & rhs) noexcept {
    return {lhs / rhs.DJC_X, lhs / rhs.DJC_Y, lhs / rhs.DJC_Z, lhs / rhs.DJC_W};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator + (vec4<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X + rhs, lhs.DJC_Y + rhs, lhs.DJC_Z + rhs, lhs.DJC_W + rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator - (vec4<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X - rhs, lhs.DJC_Y - rhs, lhs.DJC_Z - rhs, lhs.DJC_W - rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator * (vec4<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X * rhs, lhs.DJC_Y * rhs, lhs.DJC_Z * rhs, lhs.DJC_W * rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T>
operator / (vec4<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X / rhs, lhs.DJC_Y / rhs, lhs.DJC_Z / rhs, lhs.DJC_W / rhs};
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec4<T> const & rhs) {
    lhs << "vec4(" << rhs.DJC_X << ", " << rhs.DJC_Y << ", " << rhs.DJC_Z << ", " << rhs.DJC_W << ")";
    return lhs;
}
#   endif

} // namespace djc::math 

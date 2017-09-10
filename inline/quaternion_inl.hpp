namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
quaternion<T>::quaternion() noexcept 
:   DJC_X{0}
,   DJC_Y{0}
,   DJC_Z{0}
,   DJC_W{0}
{
    DJC_REAL = 1;
}

//------------------------------------------------------------
template<typename T>
quaternion<T>::quaternion(T x, T y, T z, T w) noexcept 
:   DJC_X{x}
,   DJC_Y{y}
,   DJC_Z{z}
,   DJC_W{w}
{
    // empty
}

//                       functions                          // 
//------------------------------------------------------------
template<typename T>
constexpr vec4<T>
quaternion<T>::to_vec4() const noexcept {
    return vec4<T>(DJC_X, DJC_Y, DJC_Z, DJC_W);
}

//------------------------------------------------------------
template<typename T>
constexpr T
quaternion<T>::real() const noexcept {
    return DJC_REAL; 
}

//------------------------------------------------------------
template<typename T>
constexpr vec3<T>
quaternion<T>::complex() const noexcept {
    return vec3<T>(DJC_COMPLEX_X, DJC_COMPLEX_Y, DJC_COMPLEX_Z); 
};

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
quaternion<T>::operator + () const noexcept {
    return quaternion<T>(+DJC_X, +DJC_Y, +DJC_Z, +DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
quaternion<T>::operator - () const noexcept {
    return quaternion<T>(-DJC_X, -DJC_Y, -DJC_Z, -DJC_W);
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator += (quaternion<T> const & rhs) noexcept {
    DJC_X += rhs.DJC_X;
    DJC_Y += rhs.DJC_Y;
    DJC_Z += rhs.DJC_Z;
    DJC_W += rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator -= (quaternion<T> const & rhs) noexcept {
    DJC_X -= rhs.DJC_X;
    DJC_Y -= rhs.DJC_Y;
    DJC_Z -= rhs.DJC_Z;
    DJC_W -= rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator *= (quaternion<T> const & rhs) noexcept {
    DJC_X *= rhs.DJC_X;
    DJC_Y *= rhs.DJC_Y;
    DJC_Z *= rhs.DJC_Z;
    DJC_W *= rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator /= (quaternion<T> const & rhs) noexcept {
    DJC_X /= rhs.DJC_X;
    DJC_Y /= rhs.DJC_Y;
    DJC_Z /= rhs.DJC_Z;
    DJC_W /= rhs.DJC_W;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator += (T rhs) noexcept {
    DJC_X += rhs;
    DJC_Y += rhs;
    DJC_Z += rhs;
    DJC_W += rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator -= (T rhs) noexcept {
    DJC_X -= rhs;
    DJC_Y -= rhs;
    DJC_Z -= rhs;
    DJC_W -= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator *= (T rhs) noexcept {
    DJC_X *= rhs;
    DJC_Y *= rhs;
    DJC_Z *= rhs;
    DJC_W *= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
quaternion<T> &
quaternion<T>::operator /= (T rhs) noexcept {
    DJC_X /= rhs;
    DJC_Y /= rhs;
    DJC_Z /= rhs;
    DJC_W /= rhs;
    return *this;
}

//                     free functions                       //
//------------------------------------------------------------
template<typename T>
quaternion<T> 
quaternion_from_euler(vec3<T> const & euler) noexcept {
    T c1 {std::cos(euler.DJC_Z * static_cast<T>(0.5))};
    T c2 {std::cos(euler.DJC_Y * static_cast<T>(0.5))};
    T c3 {std::cos(euler.DJC_X * static_cast<T>(0.5))};
    T s1 {std::sin(euler.DJC_X * static_cast<T>(0.5))};
    T s2 {std::sin(euler.DJC_Y * static_cast<T>(0.5))};
    T s3 {std::sin(euler.DJC_Z * static_cast<T>(0.5))};
    
    quaternion<T> q;

    q.DJC_COMPLEX_X = (c1 * c2 * s3) - (s1 * s2 * c3);
    q.DJC_COMPLEX_Y = (c1 * s2 * c3) + (s1 * c2 * s3);
    q.DJC_COMPLEX_Z = (s1 * c2 * c3) - (c1 * s2 * s3);
    q.DJC_REAL      = (c1 * c2 * c3) + (s1 * s2 * s3);    
    
    return q;
}

//------------------------------------------------------------
template<typename T>
quaternion<T> 
quaternion_from_euler(T x, T y, T z) noexcept {
    T c1 {std::cos(z * static_cast<T>(0.5))};
    T c2 {std::cos(y * static_cast<T>(0.5))};
    T c3 {std::cos(x * static_cast<T>(0.5))};
    T s1 {std::sin(x * static_cast<T>(0.5))};
    T s2 {std::sin(y * static_cast<T>(0.5))};
    T s3 {std::sin(z * static_cast<T>(0.5))};
    
    quaternion<T> q;

    q.DJC_COMPLEX_X = (c1 * c2 * s3) - (s1 * s2 * c3);
    q.DJC_COMPLEX_Y = (c1 * s2 * c3) + (s1 * c2 * s3);
    q.DJC_COMPLEX_Z = (s1 * c2 * c3) - (c1 * s2 * s3);
    q.DJC_REAL      = (c1 * c2 * c3) + (s1 * s2 * s3);    
    
    return q;
}

//------------------------------------------------------------
template<typename T>
quaternion<T>
slerp(quaternion<T> const & a, quaternion<T> const & b, T t) noexcept {

}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T> 
operator + (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept {
    return quaternion<T>(lhs.DJC_X + rhs.DJC_X, lhs.DJC_Y + rhs.DJC_Y, lhs.DJC_Z + rhs.DJC_Z, lhs.DJC_W + rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T>
constexpr quaternion<T> 
operator - (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept {
    return quaternion<T>(lhs.DJC_X - rhs.DJC_X, lhs.DJC_Y - rhs.DJC_Y, lhs.DJC_Z - rhs.DJC_Z, lhs.DJC_W - rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T> 
operator * (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept {
    return quaternion<T>(lhs.DJC_X * rhs.DJC_X, lhs.DJC_Y * rhs.DJC_Y, lhs.DJC_Z * rhs.DJC_Z, lhs.DJC_W * rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T> 
operator / (quaternion<T> const & lhs, quaternion<T> const & rhs) noexcept {
    return quaternion<T>(lhs.DJC_X / rhs.DJC_X, lhs.DJC_Y / rhs.DJC_Y, lhs.DJC_Z / rhs.DJC_Z, lhs.DJC_W / rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator + (T lhs, quaternion<T> const & rhs) noexcept {
    return quaternion<T>(lhs + rhs.DJC_X, lhs + rhs.DJC_Y, lhs + rhs.DJC_Z, lhs + rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator - (T lhs, quaternion<T> const & rhs) noexcept {
    return quaternion<T>(lhs - rhs.DJC_X, lhs - rhs.DJC_Y, lhs - rhs.DJC_Z, lhs - rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator * (T lhs, quaternion<T> const & rhs) noexcept { 
    return quaternion<T>(lhs * rhs.DJC_X, lhs * rhs.DJC_Y, lhs * rhs.DJC_Z, lhs * rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator / (T lhs, quaternion<T> const & rhs) noexcept {
    return quaternion<T>(lhs / rhs.DJC_X, lhs / rhs.DJC_Y, lhs / rhs.DJC_Z, lhs / rhs.DJC_W);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator + (quaternion<T> const & lhs, T rhs) noexcept {
    return quaternion<T>(lhs.DJC_X + rhs, lhs.DJC_Y + rhs, lhs.DJC_Z + rhs, lhs.DJC_W + rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator - (quaternion<T> const & lhs, T rhs) noexcept {
    return quaternion<T>(lhs.DJC_X - rhs, lhs.DJC_Y - rhs, lhs.DJC_Z - rhs, lhs.DJC_W - rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator * (quaternion<T> const & lhs, T rhs) noexcept {
    return quaternion<T>(lhs.DJC_X * rhs, lhs.DJC_Y * rhs, lhs.DJC_Z * rhs, lhs.DJC_W * rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr quaternion<T>
operator / (quaternion<T> const & lhs, T rhs) noexcept {
    return quaternion<T>(lhs.DJC_X / rhs, lhs.DJC_Y / rhs, lhs.DJC_Z / rhs, lhs.DJC_W / rhs);
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, quaternion<T> const & rhs) {
    lhs << "quaternion(" << rhs.DJC_X << ", " << rhs.DJC_Y << ", " << rhs.DJC_Z << ", " << rhs.DJC_W << ")";
    return lhs;
}
#   endif

} // djc::math

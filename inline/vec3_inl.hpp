namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T> 
constexpr
vec3<T>::vec3(T _xyz) noexcept 
:   DJC_X{_xyz}
,   DJC_Y{_xyz}
,   DJC_Z{_xyz} 
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec3<T>::vec3(T _x, T _y, T _z) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}
,   DJC_Z{_z}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
vec3<T>::vec3(vec2<T> const & _xy, T _z) noexcept 
:   DJC_X{_xy.DJC_X}
,   DJC_Y{_xy.DJC_Y}
,   DJC_Z{_z}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr 
vec3<T>::vec3(T _x, vec2<T> const & _yz) noexcept
:   DJC_X(_x)
,   DJC_Y(_yz.DJC_X)
,   DJC_Z(_yz.DJC_Y)
{
    // empty
}

//                       functions                          // 
//------------------------------------------------------------
template<typename T> 
T
vec3<T>::length() const noexcept(false) {
    return std::sqrt(DJC_X * DJC_X + DJC_Y * DJC_Y + DJC_Z * DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
T constexpr
vec3<T>::length2() const noexcept {
    return DJC_X * DJC_X + DJC_Y * DJC_Y + DJC_Z * DJC_Z;
}

//------------------------------------------------------------
template<typename T> 
void
vec3<T>::normalise() noexcept(false) {
    T length {std::sqrt(DJC_X * DJC_X + DJC_Y * DJC_Y + DJC_Z * DJC_Z)};
    DJC_X /= length;
    DJC_Y /= length;
    DJC_Z /= length;
}

//------------------------------------------------------------
template<typename T> 
constexpr T
vec3<T>::dot(vec3<T> const & vec) const noexcept {
    return DJC_X * vec.DJC_X + DJC_Y * vec.DJC_Y + DJC_Z * vec.DJC_Z;
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
vec3<T>::cross(vec3<T> const & vec) const noexcept {
    return vec3<T>((DJC_Y * vec.DJC_Z) - (DJC_Z * vec.DJC_Y),
                   (DJC_Z * vec.DJC_X) - (DJC_X * vec.DJC_Z),
                   (DJC_X * vec.DJC_Y) - (DJC_Y * vec.DJC_X));
}

//------------------------------------------------------------
template<typename T> 
constexpr vec2<T>
vec3<T>::to_vec2() const noexcept {
    return vec2<T>(DJC_X, DJC_Y);
}

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T>
constexpr vec3<T>
vec3<T>::operator + () const noexcept {
    return vec3<T>(+DJC_X, +DJC_Y, +DJC_Z);
}

//------------------------------------------------------------
template<typename T>
constexpr vec3<T>
vec3<T>::operator - () const noexcept {
    return vec3<T>(-DJC_X, -DJC_Y, -DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator += (vec3<T> const & rhs) noexcept {
    DJC_X += rhs.DJC_X;
    DJC_Y += rhs.DJC_Y;
    DJC_Z += rhs.DJC_Z;
    return *this;
}

//------------------------------------------------------------
template<typename T>
vec3<T> &
vec3<T>::operator -= (vec3<T> const & rhs) noexcept {
    DJC_X -= rhs.DJC_X;
    DJC_Y -= rhs.DJC_Y;
    DJC_Z -= rhs.DJC_Z;
    return *this;
}

//------------------------------------------------------------
template<typename T>
vec3<T> &
vec3<T>::operator *= (vec3<T> const & rhs) noexcept {
    DJC_X *= rhs.DJC_X;
    DJC_Y *= rhs.DJC_Y;
    DJC_Z *= rhs.DJC_Z;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator /= (vec3<T> const & rhs) noexcept {
    DJC_X /= rhs.DJC_X;
    DJC_Y /= rhs.DJC_Y;
    DJC_Z /= rhs.DJC_Z;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator += (T rhs) noexcept {
    DJC_X += rhs;
    DJC_Y += rhs;
    DJC_Z += rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator -= (T rhs) noexcept {
    DJC_X -= rhs;
    DJC_Y -= rhs;
    DJC_Z -= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator *= (T rhs) noexcept{
    DJC_X *= rhs;
    DJC_Y *= rhs;
    DJC_Z *= rhs;
    return *this;
}

//------------------------------------------------------------
template<typename T> 
vec3<T> &
vec3<T>::operator /= (T rhs) noexcept {
    DJC_X /= rhs;
    DJC_Y /= rhs;
    DJC_Z /= rhs;
    return *this;
}

//                     free functions                       //
//------------------------------------------------------------
template<typename T> 
vec3<T>
normalise(vec3<T> const & vec) noexcept {
    T length {std::sqrt((vec.DJC_X * vec.DJC_X) + (vec.DJC_Y * vec.DJC_Y) + (vec.DJC_Z * vec.DJC_Z))};
    return vec3<T>(vec.DJC_X / length, vec.DJC_Y / length, vec.DJC_Z / length);
}

//------------------------------------------------------------
template<typename T> 
constexpr T 
dot(vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return (lhs.DJC_X * rhs.DJC_X) + (lhs.DJC_Y * rhs.DJC_Y) + (lhs.DJC_Z * rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T>
vec3<T>
limit(vec3<T> vec, T limit) noexcept {
    T length {vec.length()};

    if (length > limit) {
        vec.normalise();
        vec *= limit;
    }

    return vec;
}

//------------------------------------------------------------
template<typename T>
vec3<T>
clamp(vec3<T> vec, T min, T max) noexcept {
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

//------------------------------------------------------------
template<typename T>
vec3<T> 
slerp(vec3<T> const & start, vec3<T> const & end, T percent) noexcept {
    // Dot product - the cosine of the angle between 2 vectors.
     T dot_start_end {dot(start, end)};     
     // Clamp it to be in the range of Acos()
     // This may be unnecessary, but floating point
     // precision can be a fickle mistress.
     dot_start_end = clamp(dot_start_end, static_cast<T>(-1.0), static_cast<T>(1.0));
     // Acos(dot) returns the angle between start and end,
     // And multiplying that by percent returns the angle between
     // start and the final result.
     T theta {std::acos(dot_start_end) * percent};
     
     vec3<T> relative_vec {end - start * dot_start_end};
     relative_vec.normalise();     // Orthonormal basis

     // The final result.
     return ((start * std::cos(theta)) + (relative_vec * std::sin(theta)));
}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.DJC_X + rhs.DJC_X, lhs.DJC_Y + rhs.DJC_Y, lhs.DJC_Z + rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.DJC_X - rhs.DJC_X, lhs.DJC_Y - rhs.DJC_Y, lhs.DJC_Z - rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.DJC_X * rhs.DJC_X, lhs.DJC_Y * rhs.DJC_Y, lhs.DJC_Z * rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs.DJC_X / rhs.DJC_X, lhs.DJC_Y / rhs.DJC_Y, lhs.DJC_Z / rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs + rhs.DJC_X, lhs + rhs.DJC_Y, lhs + rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs - rhs.DJC_X, lhs - rhs.DJC_Y, lhs - rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs * rhs.DJC_X, lhs * rhs.DJC_Y, lhs * rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (T const lhs, vec3<T> const & rhs) noexcept {
    return vec3<T>(lhs / rhs.DJC_X, lhs / rhs.DJC_Y, lhs / rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.DJC_X + rhs, lhs.DJC_Y + rhs, lhs.DJC_Z + rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.DJC_X - rhs, lhs.DJC_Y - rhs, lhs.DJC_Z - rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.DJC_X * rhs, lhs.DJC_Y * rhs, lhs.DJC_Z * rhs);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (vec3<T> const & lhs, T rhs) noexcept {
    return vec3<T>(lhs.DJC_X / rhs, lhs.DJC_Y / rhs, lhs.DJC_Z / rhs);
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> std::ostream &
operator << (std::ostream & lhs, vec3<T> const & rhs) {
    lhs << "vec3(" << rhs.DJC_X << ", " << rhs.DJC_Y << ", " << rhs.DJC_Z << ")\n";
    return lhs;
}
#   endif

} // namespace djc::math 

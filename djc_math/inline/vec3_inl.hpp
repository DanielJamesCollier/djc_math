namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T> 
constexpr
vec3<T>::vec3(T _xyz) noexcept 
:   DJC_X{_xyz}
,   DJC_Y{_xyz}
,   DJC_Z{_xyz}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec3<T>::vec3(T _x, T _y, T _z) noexcept 
:   DJC_X{_x}
,   DJC_Y{_y}
,   DJC_Z{_z}{}

//------------------------------------------------------------
template<typename T>
constexpr
vec3<T>::vec3(vec2<T> const & _xy, T _z) noexcept 
:   DJC_X{_xy.DJC_X}
,   DJC_Y{_xy.DJC_Y}
,   DJC_Z{_z}{}

//------------------------------------------------------------
template<typename T>
constexpr 
vec3<T>::vec3(T _x, vec2<T> const & _yz) noexcept
:   DJC_X(_x)
,   DJC_Y(_yz.DJC_X)
,   DJC_Z(_yz.DJC_Y){}

//                       functions                          // 
//------------------------------------------------------------
template<typename T>
constexpr std::size_t 
vec3<T>::size() const noexcept {
    return 3;
};

//                   operator overloads                     // 
//------------------------------------------------------------
template<typename T>
constexpr vec3<T>
vec3<T>::operator + () const noexcept {
    return {+DJC_X, +DJC_Y, +DJC_Z};
}

//------------------------------------------------------------
template<typename T>
constexpr vec3<T>
vec3<T>::operator - () const noexcept {
    return {-DJC_X, -DJC_Y, -DJC_Z};
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
T
magnitude(vec3<T> const & vec) noexcept {
    return std::sqrt(vec.DJC_X * vec.DJC_X + vec.DJC_Y * vec.DJC_Y + vec.DJC_Z * vec.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
T constexpr
magnitude_squared(vec3<T> const & vec) noexcept {
    return vec.DJC_X * vec.DJC_X + vec.DJC_Y * vec.DJC_Y + vec.DJC_Z * vec.DJC_Z;
}

//------------------------------------------------------------
template<typename T> 
vec3<T>
normalise(vec3<T> const & vec) noexcept {
    T length {std::sqrt((vec.DJC_X * vec.DJC_X) + (vec.DJC_Y * vec.DJC_Y) + (vec.DJC_Z * vec.DJC_Z))};
    return {vec.DJC_X / length, vec.DJC_Y / length, vec.DJC_Z / length};
}

//------------------------------------------------------------
template<typename T> 
constexpr T 
dot(vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return (lhs.DJC_X * rhs.DJC_X) + (lhs.DJC_Y * rhs.DJC_Y) + (lhs.DJC_Z * rhs.DJC_Z);
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
cross(vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return {(lhs.DJC_Y * rhs.DJC_Z) - (lhs.DJC_Z * rhs.DJC_Y),
            (lhs.DJC_Z * rhs.DJC_X) - (lhs.DJC_X * rhs.DJC_Z),
            (lhs.DJC_X * rhs.DJC_Y) - (lhs.DJC_Y * rhs.DJC_X)};
}

//------------------------------------------------------------
template<typename T>
vec3<T>
clamp_magnitude(vec3<T> vec, T max) noexcept {
    T length {djc::math::magnitude(vec)};

    if (length > max) {
        vec = djc::math::normalise(vec);
        vec *= max;
    }

    return vec;
}

//------------------------------------------------------------
template<typename T>
vec3<T>
clamp(vec3<T> vec, T min, T max) noexcept {
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

//------------------------------------------------------------
template<typename T>
vec3<T> 
slerp(vec3<T> const & start, vec3<T> const & end, T percent) noexcept {
    // Dot product - the cosine of the angle between 2 vectors.
     T dot_start_end {dot(start, end)};     
     // Clamp it to be in the range of Acos()
     // This may be unnecessary, but floating point
     // precision can be a fickle mistress.
     dot_start_end = djc::math::clamp(dot_start_end, static_cast<T>(-1.0), static_cast<T>(1.0));
     // Acos(dot) returns the angle between start and end,
     // And multiplying that by percent returns the angle between
     // start and the final result.
     T theta {std::acos(dot_start_end) * percent};
     
     vec3<T> relative_vec {end - start * dot_start_end};
     relative_vec = djc::math::normalise(relative_vec);

     // The final result.
     return ((start * std::cos(theta)) + (relative_vec * std::sin(theta)));
}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return {lhs.DJC_X + rhs.DJC_X, lhs.DJC_Y + rhs.DJC_Y, lhs.DJC_Z + rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return {lhs.DJC_X - rhs.DJC_X, lhs.DJC_Y - rhs.DJC_Y, lhs.DJC_Z - rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return {lhs.DJC_X * rhs.DJC_X, lhs.DJC_Y * rhs.DJC_Y, lhs.DJC_Z * rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (vec3<T> const & lhs, vec3<T> const & rhs) noexcept {
    return {lhs.DJC_X / rhs.DJC_X, lhs.DJC_Y / rhs.DJC_Y, lhs.DJC_Z / rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (T const lhs, vec3<T> const & rhs) noexcept {
    return {lhs + rhs.DJC_X, lhs + rhs.DJC_Y, lhs + rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (T const lhs, vec3<T> const & rhs) noexcept {
    return {lhs - rhs.DJC_X, lhs - rhs.DJC_Y, lhs - rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (T const lhs, vec3<T> const & rhs) noexcept {
    return {lhs * rhs.DJC_X, lhs * rhs.DJC_Y, lhs * rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (T const lhs, vec3<T> const & rhs) noexcept {
    return {lhs / rhs.DJC_X, lhs / rhs.DJC_Y, lhs / rhs.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator + (vec3<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X + rhs, lhs.DJC_Y + rhs, lhs.DJC_Z + rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator - (vec3<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X - rhs, lhs.DJC_Y - rhs, lhs.DJC_Z - rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (vec3<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X * rhs, lhs.DJC_Y * rhs, lhs.DJC_Z * rhs};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator / (vec3<T> const & lhs, T rhs) noexcept {
    return {lhs.DJC_X / rhs, lhs.DJC_Y / rhs, lhs.DJC_Z / rhs};

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

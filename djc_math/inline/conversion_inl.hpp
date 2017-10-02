namespace djc::math {

//                         truncate                         // 
//------------------------------------------------------------
template<typename T>
constexpr vec2<T> 
truncate_to_vec2(vec3<T> const & vec) noexcept {
    return {vec.DJC_X, vec.DJC_Y};
}

//------------------------------------------------------------
template<typename T>
constexpr vec2<T> 
truncate_to_vec2(vec4<T> const & vec) noexcept {
    return {vec.DJC_X, vec.DJC_Y};
}

//------------------------------------------------------------
template<typename T>
constexpr vec3<T> 
truncate_to_vec3(vec4<T> const & vec) noexcept {
    return {vec.DJC_X, vec.DJC_Y, vec.DJC_Z};
}

//------------------------------------------------------------
template<typename T> 
constexpr mat3<T>
truncate_to_mat3(mat4<T> const & mat) noexcept {
    return {std::array<T, 9> {{mat[0], mat[1], mat[2],
                               mat[4], mat[5], mat[6],
                               mat[8], mat[9], mat[10]}}};
}

//                         extend                           // 
//------------------------------------------------------------
template<typename T>
constexpr vec3<T> 
extend_to_vec3(vec2<T> const & vec) noexcept {
    return {vec.DJC_X, vec.DJC_Y, T{}};
}

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> 
extend_to_vec4(vec2<T> const & vec) noexcept {
    return {vec.DJC_X, vec.DJC_Y, T{}, T{}}; }

//------------------------------------------------------------
template<typename T>
constexpr vec4<T> 
extend_to_vec4(vec3<T> const & vec) noexcept {
    return {vec.DJC_X, vec.DJC_Y, vec.DJC_Z, T{}};
}

//------------------------------------------------------------
template<typename T>
constexpr mat4<T>
extend_to_mat4(mat3<T> const & mat) noexcept {
    return {std::array<T, 16> {{mat[0], mat[1], mat[2],  T{},
                                mat[4], mat[5], mat[6],  T{},
                                mat[8], mat[9], mat[10], T{},
                                   T{},    T{},     T{}, T{}}}};
}

} // namespace djc::math

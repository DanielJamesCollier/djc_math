namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
mat4<T>::mat4() noexcept 
:   m_matrix{}{}

//------------------------------------------------------------
template<typename T>
constexpr
mat4<T>::mat4(std::array<T, 16> const & matrix) noexcept 
:   m_matrix{matrix}{}

//------------------------------------------------------------
template<typename T> 
constexpr
mat4<T>::mat4(mat3<T> const & matrix, T lastVal) noexcept 
:   m_matrix{std::array<T, 16>{{
             matrix[3], matrix[4], matrix[5], 0,
             matrix[6], matrix[7], matrix[8], 0,
                     0,         0,         0, lastVal}}}{} // [15] fix : should be 1 ? 0 maybe make this function in utils?

//                       operators                          // 
//------------------------------------------------------------
template<typename T>
constexpr T & 
mat4<T>::operator [] (std::size_t index) noexcept {
    return m_matrix[index];
}

//------------------------------------------------------------
template<typename T> 
constexpr T const & 
mat4<T>::operator [] (std::size_t index) const noexcept {
    return m_matrix[index];
}

//                  free function operators                 // 
//------------------------------------------------------------
template<typename T> 
constexpr mat4<T> 
operator * (mat4<T> const & lhs, mat4<T> const & rhs) noexcept {
    return {std::array<T, 16>{{
           (lhs[ 0] * rhs[ 0]) + (lhs[ 1] * rhs[ 4]) + (lhs[ 2] * rhs[ 8]) + (lhs[ 3] * rhs[12]),
           (lhs[ 0] * rhs[ 1]) + (lhs[ 1] * rhs[ 5]) + (lhs[ 2] * rhs[ 9]) + (lhs[ 3] * rhs[13]),
           (lhs[ 0] * rhs[ 2]) + (lhs[ 1] * rhs[ 6]) + (lhs[ 2] * rhs[10]) + (lhs[ 3] * rhs[14]),
           (lhs[ 0] * rhs[ 3]) + (lhs[ 1] * rhs[ 7]) + (lhs[ 2] * rhs[11]) + (lhs[ 3] * rhs[15]),

           (lhs[ 4] * rhs[ 0]) + (lhs[ 5] * rhs[ 4]) + (lhs[ 6] * rhs[ 8]) + (lhs[ 7] * rhs[12]),
           (lhs[ 4] * rhs[ 1]) + (lhs[ 5] * rhs[ 5]) + (lhs[ 6] * rhs[ 9]) + (lhs[ 7] * rhs[13]),
           (lhs[ 4] * rhs[ 2]) + (lhs[ 5] * rhs[ 6]) + (lhs[ 6] * rhs[10]) + (lhs[ 7] * rhs[14]),
           (lhs[ 4] * rhs[ 3]) + (lhs[ 5] * rhs[ 7]) + (lhs[ 6] * rhs[11]) + (lhs[ 7] * rhs[15]),

           (lhs[ 8] * rhs[ 0]) + (lhs[ 9] * rhs[ 4]) + (lhs[10] * rhs[ 8]) + (lhs[11] * rhs[12]),
           (lhs[ 8] * rhs[ 1]) + (lhs[ 9] * rhs[ 5]) + (lhs[10] * rhs[ 9]) + (lhs[11] * rhs[13]),
           (lhs[ 8] * rhs[ 2]) + (lhs[ 9] * rhs[ 6]) + (lhs[10] * rhs[10]) + (lhs[11] * rhs[14]),
           (lhs[ 8] * rhs[ 3]) + (lhs[ 9] * rhs[ 7]) + (lhs[10] * rhs[11]) + (lhs[11] * rhs[15]),

           (lhs[12] * rhs[ 0]) + (lhs[13] * rhs[ 4]) + (lhs[14] * rhs[ 8]) + (lhs[15] * rhs[12]),
           (lhs[12] * rhs[ 1]) + (lhs[13] * rhs[ 5]) + (lhs[14] * rhs[ 9]) + (lhs[15] * rhs[13]),
           (lhs[12] * rhs[ 2]) + (lhs[13] * rhs[ 6]) + (lhs[14] * rhs[10]) + (lhs[15] * rhs[14]),
           (lhs[12] * rhs[ 3]) + (lhs[13] * rhs[ 7]) + (lhs[14] * rhs[11]) + (lhs[15] * rhs[15])}}};
}

//------------------------------------------------------------
template<typename T> 
constexpr vec4<T> 
operator * (mat4<T> const & lhs, vec4<T> const & rhs) noexcept {
    return {(lhs[ 0] * rhs.DJC_X) + (lhs[ 1] * rhs.DJC_Y) + (lhs[ 2] * rhs.DJC_Z) + (lhs[ 3] * rhs.DJC_W),
            (lhs[ 4] * rhs.DJC_X) + (lhs[ 5] * rhs.DJC_Y) + (lhs[ 6] * rhs.DJC_Z) + (lhs[ 7] * rhs.DJC_W),
            (lhs[ 8] * rhs.DJC_X) + (lhs[ 9] * rhs.DJC_Y) + (lhs[10] * rhs.DJC_Z) + (lhs[11] * rhs.DJC_W),
            (lhs[12] * rhs.DJC_X) + (lhs[13] * rhs.DJC_Y) + (lhs[14] * rhs.DJC_Z) + (lhs[15] * rhs.DJC_W)};
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T>
std::ostream & 
operator << (std::ostream & lhs, mat4<T> const & rhs) {
    lhs << "mat4\n-----------------\n";
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
                lhs << "[" << rhs.m_matrix[4 * x + y] << "] "; 
        }
          lhs << "\n";
    }
    lhs << "-----------------";
    return lhs;
}
#   endif

} // namespace djc::math 

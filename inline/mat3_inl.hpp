namespace djc::math {

//                         RAII                             // 
//------------------------------------------------------------
template<typename T>
constexpr
mat3<T>::mat3() noexcept 
:   m_matrix{}
{
    // empty
}

//------------------------------------------------------------
template<typename T>
constexpr
mat3<T>::mat3(std::array<T, 9> matrix) noexcept
:   m_matrix{matrix}
{
    // empty
}

//                 friend free operators                    // 
//------------------------------------------------------------
template<typename T> 
constexpr mat3<T> 
operator * (mat3<T> const & lhs, mat3<T> const & rhs) {
    return mat3<T>(std::array<T, 9>{{
        ///////
        /*[0]*/ (lhs[0] * rhs[0]) + (lhs[1] * rhs[3]) + (lhs[2] * rhs[6]),
        /*[1]*/ (lhs[0] * rhs[1]) + (lhs[1] * rhs[4]) + (lhs[2] * rhs[7]),
        /*[2]*/ (lhs[0] * rhs[2]) + (lhs[1] * rhs[5]) + (lhs[2] * rhs[8]),
        ///////
        /*[0]*/ (lhs[3] * rhs[0]) + (lhs[4] * rhs[3]) + (lhs[5] * rhs[6]),
        /*[1]*/ (lhs[3] * rhs[1]) + (lhs[4] * rhs[4]) + (lhs[5] * rhs[7]),
        /*[2]*/ (lhs[3] * rhs[2]) + (lhs[4] * rhs[5]) + (lhs[5] * rhs[8]),
        ///////
        /*[0]*/ (lhs[6] * rhs[0]) + (lhs[7] * rhs[3]) + (lhs[8] * rhs[6]),
        /*[1]*/ (lhs[6] * rhs[1]) + (lhs[7] * rhs[4]) + (lhs[8] * rhs[7]),
        /*[2]*/ (lhs[6] * rhs[2]) + (lhs[7] * rhs[5]) + (lhs[8] * rhs[8]),
        ///////
    }});
}

//------------------------------------------------------------
template<typename T> 
constexpr vec3<T>
operator * (mat3<T> const & lhs, vec3<T> const & rhs) {
    return vec3<T>(
        /*[x]*/ (lhs[0] * rhs.DJC_X) + (lhs[1] * rhs.DJC_Y) + (lhs[2] * rhs.DJC_Z),
        /*[y]*/ (lhs[3] * rhs.DJC_X) + (lhs[4] * rhs.DJC_Y) + (lhs[5] * rhs.DJC_Z),
        /*[z]*/ (lhs[6] * rhs.DJC_X) + (lhs[7] * rhs.DJC_Y) + (lhs[8] * rhs.DJC_Z));
}

//------------------------------------------------------------
#   if defined(DJC_MATH_STD_IOSTREAM)
template<typename T> 
std::ostream & 
operator << (std::ostream & lhs, mat3<T> const & rhs) {

    lhs << " mat3\n-----------------\n";
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
                lhs << "[" << rhs.m_matrix[3 * x + y] << "] "; 
        }
        lhs << "\n";
    }
    lhs << "-----------------";
    return lhs;
}
#   endif

//                 [private] - operators                    // 
//------------------------------------------------------------
template<typename T> 
constexpr T & 
mat3<T>::operator [] (std::size_t index) noexcept {
    return m_matrix[index];
}

//------------------------------------------------------------
template<typename T> 
constexpr T const & 
mat3<T>::operator [] (std::size_t index) const noexcept {
    return m_matrix[index];
}

} // namespace djc::math 

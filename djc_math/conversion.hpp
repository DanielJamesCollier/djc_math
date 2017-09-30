#ifndef DJC_MATH_CONVERSION_HPP
#define DJC_MATH_CONVERSION_HPP

// djc_math 
#include "config.hpp"
#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"
#include "mat3.hpp"
#include "mat4.hpp"

// std
#include <array>

namespace djc::math {

    //                         truncate                         // 
    //------------------------------------------------------------
    template<typename T>
    constexpr vec2<T> truncate_to_vec2(vec3<T> const & vec) noexcept;

    //------------------------------------------------------------
    template<typename T>
    constexpr vec2<T> truncate_to_vec2(vec4<T> const & vec) noexcept;
    
    //------------------------------------------------------------
    template<typename T>
    constexpr vec3<T> truncate_to_vec3(vec4<T> const & vec) noexcept;
    
    //------------------------------------------------------------
    template<typename T>
    constexpr mat3<T> truncate_to_mat3(mat4<T> const & mat) noexcept;

    //                         extend                           // 
    //------------------------------------------------------------
    template<typename T>
    constexpr vec3<T> extend_to_vec3(vec2<T> const & vec) noexcept;

    //------------------------------------------------------------
    template<typename T>
    constexpr vec4<T> extend_to_vec4(vec2<T> const & vec) noexcept;

    //------------------------------------------------------------
    template<typename T>
    constexpr vec4<T> extend_to_vec4(vec3<T> const & vec) noexcept;
    
    //------------------------------------------------------------
    template<typename T>
    constexpr mat4<T> extend_to_mat4(mat4<T> const & mat) noexcept;
    
} // namespace djc::math
#include "inline/conversion_inl.hpp"
#endif // DJC_MATH_CONVERSION_HPP

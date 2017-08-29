#ifndef transform_hpp
#define transform_hpp

// my
#include "vec3.hpp"
#include "mat3.hpp"
#include "mat4.hpp"
#include "config.hpp"

// std
#include <array>
#include <cmath> // std::sqrt - std::sin - std::cos - std::tan

namespace djc::math {

//                        mat3                              // 
//------------------------------------------------------------
template<typename T> 
constexpr mat3<T>
create_mat3_identity_matrix() noexcept;

//------------------------------------------------------------
template<typename T> 
mat3<T>
create_mat3_rotation_matrix(vec3<T> const & vec) noexcept;

//                        mat4                              // 
//------------------------------------------------------------
template<typename T> 
constexpr mat4<T> 
create_mat4_identity_matrix() noexcept;

//------------------------------------------------------------
template<typename T>
constexpr mat4<T>
create_mat4_translation_matrix(vec3<T> const & vec) noexcept;

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_rotation_matrix(vec3<T> const & vec) noexcept;

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_scale_matrix(vec3<T> const & vec) noexcept;

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_model_matrix(vec3<T> const & position, vec3<T> const & rotation, vec3<T> const & scale) noexcept;

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_orthographic_matrix(int width, int  height, T zNear, T zFar) noexcept;

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_projection_matrix(T fov, T aspect, T zNear, T zFar) noexcept;

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_view_matrix(vec3<T> const & eye, vec3<T> const & centre, vec3<T> const & up) noexcept;

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_birds_eye_view_matrix() noexcept;

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_screenspace_transform(int half_width, int half_height) noexcept;

//                    Vector operations                     // 
//------------------------------------------------------------
template<typename T> 
void
transform(vec4<T> & vec, mat4<T> const & transformation);

//------------------------------------------------------------
template<typename T> 
mat3<T>
rotate(T angle, vec3<T> const & axis) noexcept;

//------------------------------------------------------------
template<typename T> 
mat4<T>
rotate(T angle, vec4<T> const & axis) noexcept;

} // namespace djc::math 

#include "./inline/transform.inl"
#endif /* transform_hpp */


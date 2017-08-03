namespace djc::math {

//                        mat3                              // 
//------------------------------------------------------------
template<typename T> 
constexpr mat3<T>
create_mat3_identity_matrix() noexcept { 
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, 
                  "create_mat3_identity_matrix() only accepts floating point, and integral values");

    return mat3<T>(std::array<T, 9> {{ 
        1,  0,  0,
        0,  1,  0,
        0,  0,  1
    }});
}

//------------------------------------------------------------
template<typename T> 
mat3<T>
create_mat3_rotation_matrix(vec3<T> const & rotation) noexcept {
     static_assert(std::is_floating_point<T>::value,
                  "create_mat3_rotation_matrix() only accepts floating point values");

    T x_sin {std::sin(rotation.DJC_X)};
    T x_cos {std::cos(rotation.DJC_X)};

    T y_sin {std::sin(rotation.DJC_Y)};
    T y_cos {std::cos(rotation.DJC_Y)};

    T z_sin {std::sin(rotation.DJC_Z)};
    T z_cos {std::cos(rotation.DJC_Z)};
    
    mat3<T> rotX(std::array<T, 9> {{
        1,    0,        0,
        0,    x_cos,    -x_sin,
        0,    x_sin,    x_cos,
    }});

    mat3<T> rotY(std::array<T, 9>{{
        y_cos,  0,    y_sin,
        0,      1,    0,
        -y_sin, 0,    y_cos
    }});

    mat3<T> rotZ(std::array<T, 9>{{
        z_cos,    -z_sin,   0,
        z_sin,    z_cos,    0,
        0,        0,        1
    }});
   
    return rotX * rotY * rotZ;
}

//                        mat4                              // 
//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_identity_matrix() noexcept {
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, 
                  "create_mat4_identity_matrix() only accepts floating point, and integral values");

    return mat4<T>(std::array<T, 16>{{
        1,    0,    0,    0,
        0,    1,    0,    0,
        0,    0,    1,    0,
        0,    0,    0,    1
    }});
}

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T> 
create_mat4_translation_matrix(vec3<T> const & vec) noexcept {
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, 
                  "create_mat4_translation_matrix() only accepts floating point, and integral values");    

    return mat4<T>(std::array<T, 16>{{
        1,    0,    0,    vec.DJC_X,
        0,    1,    0,    vec.DJC_Y,
        0,    0,    1,    vec.DJC_Z,
        0,    0,    0,    1
    }});
}

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_rotation_matrix(vec3<T> const & rotation) noexcept {
     static_assert(std::is_floating_point<T>::value,
                  "create_mat4_rotation_matrix() only accepts floating point values"); 

    T x_sin {std::sin(rotation.DJC_X)};
    T x_cos {std::cos(rotation.DJC_X)};

    T y_sin {std::sin(rotation.DJC_Y)};
    T y_cos {std::cos(rotation.DJC_Y)};

    T z_sin {std::sin(rotation.DJC_Z)};
    T z_cos {std::cos(rotation.DJC_Z)};

    mat3<T> rotX(std::array<T, 9>{{
        1,    0,        0,    
        0,    x_cos,    -x_sin,
        0,    x_sin,    x_cos
    }});

    mat3<T> rotY(std::array<T, 9>{{
        y_cos,     0,    y_sin,
        0,         1,    0,
        -y_sin,    0,    y_cos
    }});

    mat3<T> rotZ(std::array<T, 9>{{
        z_cos,    -z_sin,  0,
        z_sin,    z_cos,   0,
        0,        0,       1
    }});

    return mat4<T>((rotX * rotY * rotZ), static_cast<T>(1));
}

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_scale_matrix(vec3<T> const & vec) noexcept {
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, 
                "create_mat4_scale_matrix() only accepts floating point, and integral values"); 

     return mat4<T>(std::array<T, 16>{{
        vec.DJC_X,    0,         0,         0,
        0,            vec.DJC_Y, 0,         0,
        0,            0,         vec.DJC_Z, 0,
        0,            0,         0,         1
    }});
}

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_model_matrix(vec3<T> const & translation, vec3<T> const & rotation, vec3<T> const & scale) noexcept {
    mat4<T> t {create_mat4_translation_matrix<T>(translation)};
    mat4<T> r {create_mat4_rotation_matrix<T>(rotation)};
    mat4<T> s {create_mat4_scale_matrix<T>(scale)};
    return t * r * s;
}

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T> // @todo : needs review
create_mat4_orthographic_matrix(int width, int height, T zNear, T zFar) noexcept { 
    T a {static_cast<T>(1) / static_cast<T>(width)};
    T b {static_cast<T>(1) / static_cast<T>(height)};
    T c {-(static_cast<T>(2) / (zFar - zNear))};
    T d {-((zFar + zNear) / (zFar - zNear))};

    return mat4<T>(std::array<T, 16>{{
        a,    0,    0,    0,
        0,    b,    0,    0,
        0,    0,    c,    0,
        0,    0,    d,    1,
    }});
}

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_projection_matrix(T fov, T aspect, T near, T far) noexcept {
    static_assert(std::is_floating_point<T>::value, "createmat4ProjectionMatrix only accepts floating point values");

    T const rad {fov};
    T const tan_half_fov_y {std::tan(rad / static_cast<T>(2))};

    T sX {static_cast<T>(1) / (aspect * tan_half_fov_y)};
    T sY {static_cast<T>(1) / (tan_half_fov_y)};
    T sZ { -(far + near) / (far - near)};
    T sA {static_cast<T>(-1)};
    T sB { -(static_cast<T>(2) * far * near) / (far - near)};
    
    T zero {static_cast<T>(0)};

    return mat4<T>(std::array<T, 16>{{
         sX,    0,     0,     0,
         0,     sY,    0,     0,
         0,     0,     sZ,    sB,
         0,     0,     sA,    0
    }});
}

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T> 
create_mat4_view_matrix(vec3<T> const & eye, vec3<T> const & centre, vec3<T> const & up) noexcept {
    vec3<T> forward(0, 0, -1);
    vec3<T> right(1, 0, 0);

    return mat4<T>(std::array<T, 16>{{
           right.DJC_X,       right.DJC_Y,       right.DJC_Z,    -eye.DJC_X,
           up.DJC_X,          up.DJC_Y,          up.DJC_Z,       -eye.DJC_Y,
           -forward.DJC_X,    -forward.DJC_Y,    -forward.DJC_Z, -eye.DJC_Z,
           0,                 0,                 0,              1
    }});
}

//------------------------------------------------------------
template<typename T>
constexpr mat4<T>
create_mat4_birds_eye_view_matrix() noexcept {
    return mat4<T>(std::array<T, 16> {{
        1,    0,    0,     0,
        0,    0,    -1,    0,
        0,    1,    0,     0,
        0,    0,    0,     1
    }});
}

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T>
create_mat4_screenspace_transform(T half_width, T half_height) noexcept {
    T hw {half_width};
    T hh {half_height};

    return mat4<T>(std::array<T, 16>{{ 
         hw,    0,      0,    0,
         0,     -hh,    0,    0,
         0,     0,      1,    0,
         hw,    hh,     0,    1
    }});
}

//                    Vector operations                     // 
//------------------------------------------------------------
template<typename T> 
void
transform(vec4<T> & vec, mat4<T> const & transformation) {
    vec = transformation * vec;
}

//------------------------------------------------------------
template<typename T>
mat3<T>
rotate(T angle, vec3<T> const & axis) noexcept {
    return create_mat3_rotation_matrix<T>(axis * angle);
}

//------------------------------------------------------------
template<typename T> 
mat4<T>
rotate(T angle, vec4<T> const & axis) noexcept {
    return create_mat4_rotation_matrix<T>(axis * angle);
}

} // namespace djc::math 

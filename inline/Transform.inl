namespace djc::math {

//                        mat3                              // 
//------------------------------------------------------------
template<typename T> 
constexpr mat3<T>
create_mat3_identity_matrix() noexcept { 
    static_assert(std::is_floating_point<T>::value || std::is_integral<T>::value, 
                  "rcreate_mat3_identity_matrix() only accepts floating point, and integral values");

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
                  "ccreate_mat3_rotation_matrix() only accepts floating point values");

    T xSin = std::sin(rotation.x);
    T xCos = std::cos(rotation.x);

    T ySin = std::sin(rotation.y);
    T yCos = std::cos(rotation.y);

    T zSin = std::sin(rotation.z);
    T zCos = std::cos(rotation.z);
    
    mat3<T> rotX(std::array<T, 9> {{
        1,    0,       0,
        0,    xCos,    -xSin,
        0,    xSin,    xCos,
    }});

    mat3<T> rotY(std::array<T, 9>{{
        yCos,    0,    ySin,
        0,       1,    0,
        -ySin,   0,    yCos
    }});

    mat3<T> rotZ(std::array<T, 9>{{
        zCos,    -zSin,   0,
        zSin,    zCos,    0,
        0,       0,       1
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
        1,    0,    0,    vec.x,
        0,    1,    0,    vec.y,
        0,    0,    1,    vec.z,
        0,    0,    0,    1
    }});
}

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_rotation_matrix(vec3<T> const & rotation) noexcept {
     static_assert(std::is_floating_point<T>::value,
                  "create_mat4_rotation_matrix() only accepts floating point values"); 

    T xSin(std::sin(rotation.x));
    T xCos(std::cos(rotation.x));

    T ySin(std::sin(rotation.y));
    T yCos(std::cos(rotation.y));

    T zSin(std::sin(rotation.z));
    T zCos(std::cos(rotation.z));

    mat3<T> rotX(std::array<T, 9>{{
        1,    0,       0,    
        0,    xCos,    -xSin,
        0,    xSin,    xCos
    }});

    mat3<T> rotY(std::array<T, 9>{{
        yCos,     0,    ySin,
        0,        1,    0,
        -ySin,    0,    yCos
    }});

    mat3<T> rotZ(std::array<T, 9>{{
        zCos,    -zSin,  0,
        zSin,    zCos,   0,
        0,       0,      1
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
        vec.x,    0,        0,        0,
        0,        vec.y,    0,        0,
        0,        0,        vec.z,    0,
        0,        0,        0,        1
    }});
}

//------------------------------------------------------------
template<typename T> 
mat4<T>
create_mat4_model_matrix(vec3<T> const & position, vec3<T> const & rotation, vec3<T> const & scale) noexcept {
    mat4<T> _translation {create_mat4_translation_matrix<T>(position)};
    mat4<T> _rotation    {create_mat4_rotation_matrix<T>(rotation)};
    mat4<T> _scale       {create_mat4_scale_matrix<T>(scale)};
    return _translation * _rotation * _scale;
}

//------------------------------------------------------------
template<typename T> 
constexpr mat4<T> // @todo : needs looking at
create_mat4_orthographic_matrix(int width, int height, T zNear, T zFar) noexcept { 
    T a(1.0 / static_cast<T>(width));
    T b(1.0 / static_cast<T>(height));
    T c(-(2.0 / (zFar - zNear)));
    T d(-((zFar + zNear) / (zFar - zNear)));

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

    T const rad = fov;
    T const tanHalfFovy = std::tan(rad / static_cast<T>(2));

    T sX(static_cast<T>(1) / (aspect * tanHalfFovy));
    T sY(static_cast<T>(1) / (tanHalfFovy));
    T sZ(- (far + near) / (far - near));
    T sA(static_cast<T>(-1));
    T sB(- (static_cast<T>(2) * far * near) / (far - near));
    
    T zero(static_cast<T>(0));

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
           right.x,       right.y,       right.z,    -eye.x,
           up.x,          up.y,          up.z,       -eye.y,
           -forward.x,    -forward.y,    -forward.z, -eye.z,
           0,             0,              0,          1
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

namespace djc_math {

//-------------------
/*      Mat3       */
//-------------------

// creates new

//------------------------------------------------------------
template<typename T> inline Mat3<T>
createMat3IdentityMatrix() {
    return Mat3<T>(std::array<T, 9> {{1, 0, 0,
                                      0, 1, 0,
                                      0, 0, 1}});
}

//------------------------------------------------------------
template<typename T> inline Mat3<T>
createMat3RotationMatrix(Vec3<T> const & rotation) {

    T xSin = std::sin(rotation.x);
    T xCos = std::cos(rotation.x);

    T ySin = std::sin(rotation.y);
    T yCos = std::cos(rotation.y);

    T zSin = std::sin(rotation.z);
    T zCos = std::cos(rotation.z);
    
    Mat3<T> rotX(std::array<T, 9> {{
        1,     0,     0,
        0,  xCos, -xSin,
        0,  xSin,  xCos,
    }});

    Mat3<T> rotY(std::array<T, 9>{{
        yCos, 0,  ySin,
           0, 1,     0,
       -ySin, 0,  yCos
    }});

    Mat3<T> rotZ(std::array<T, 9>{{
         zCos, -zSin,  0,
         zSin,  zCos,  0,
            0,     0,  1
    }});
   
    return rotX * rotY * rotZ;
}

// use existing

//-------------------
/*      Mat4       */
//-------------------

// create new

//------------------------------------------------------------
template<typename T> inline Mat4<T>
createMat4IdentityMatrix() {
    return Mat4<T>(std::array<T, 16>{{
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    }});
}

//------------------------------------------------------------
template<typename T> inline Mat4<T>
createMat4TranslationMatrix(Vec3<T> const & vec) {
    T zero = static_cast<T>(0);
    T one  = static_cast<T>(1);
    return Mat4<T>(std::array<T, 16>{{
            one, zero, zero, vec.x,
            zero, one, zero, vec.y,
            zero, zero, one, vec.z,
            zero, zero, zero, one
    }});
}

//------------------------------------------------------------
template<typename T> inline Mat4<T>
createMat4RotationMatrix(Vec3<T> const & rotation) {
    T xSin = std::sin(rotation.x);
    T xCos = std::cos(rotation.x);

    T ySin = std::sin(rotation.y);
    T yCos = std::cos(rotation.y);

    T zSin = std::sin(rotation.z);
    T zCos = std::cos(rotation.z);

    // perf : change this to Mat3 then put into Mat4 on return

    Mat4<T> rotX(std::array<T, 16>{{
        1,     0,     0, 0,
        0,  xCos, -xSin, 0,
        0,  xSin,  xCos, 0,
        0,     0,     0, 1
    }});

    Mat4<T> rotY(std::array<T, 16>{{
         yCos,  0, ySin, 0,
            0,  1,    0, 0,
        -ySin,  0, yCos, 0,
            0,  0,    0, 1
    }});

    Mat4<T> rotZ(std::array<T, 16>{{
         zCos, -zSin, 0, 0,
         zSin,  zCos, 0, 0,
            0,     0, 1, 0,
            0,     0, 0, 1
    }});

    return rotX * rotY * rotZ;
}

//------------------------------------------------------------
template<typename T> inline Mat4<T>
createMat4ScaleMatrix(Vec3<T> const & vec) {
     return Mat4<T>(std::array<T, 16>{{
        vec.x,     0,     0, 0,
            0, vec.y,     0, 0,
            0,     0, vec.z, 0,
            0,     0,     0, 1
    }});
}

//------------------------------------------------------------
template<typename T> inline Mat4<T>
createMat4ModelMatrix(Vec3<T> const & position, Vec3<T> const & rotation, Vec3<T> const & scale) {
    Mat4<T> _translation = createMat4TranslationMatrix<T>(position);
    Mat4<T> _rotation    = createMat4RotationMatrix<T>(rotation);
    Mat4<T> _scale       = createMat4ScaleMatrix<T>(scale);
    return _translation * _rotation * _scale;
}

//------------------------------------------------------------
template<typename T, typename U> inline Mat4<U> // @todo : needs looking at
createMat4OrthographicMatrix(T width, T height, U zNear, U zFar) { 
    U a =   1.0f / static_cast<U>(width);
    U b =   1.0f / static_cast<U>(height);
    U c = -(2.0f / (zFar - zNear));
    U d = -((zFar + zNear) / (zFar - zNear));
    U e =   1.0f;

    return Mat4<U>(std::array<U, 16>{{
        a, 0, 0, 0,
        0, b, 0, 0,
        0, 0, c, 0,
        0, 0, d, e,
    }});
}

//------------------------------------------------------------
// template<typename T> inline Mat4<T> // @todo: enable_if float / double
// createMat4ProjectionMatrix(T fov, T aspect, T zNear, T zFar) {
//     T range =  std::tan(fov / static_cast<T>(2)) * zNear;
//     T Sx    =  (static_cast<T>(2) * zNear) / (range * aspect + range * aspect);
//     T Sy    =   zNear / range;
//     T Sz    = -(zFar + zNear) / (zFar - zNear);
//     T Pz    = -(static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
//     T zero  = T();

//     return Mat4<T>(std::array<T, 16>{{
//         Sx,   zero,  zero,  zero,
//         zero,   Sy,  zero,  zero,
//         zero, zero,    Sz,    -1,
//         zero, zero,    Pz,  zero
//     }});
// }

// //------------------------------------------------------------
// inline Mat4<float>
// createMat4ProjectionMatrix(float fov, float aspect, float zNear, float zFar) {
//     float range =  std::tan(fov / 2.0f) * zNear;
//     float Sx    =  (2.0f * zNear) / (range * aspect + range * aspect);
//     float Sy    =   zNear / range;
//     float Sz    = -(zFar + zNear) / (zFar - zNear);
//     float Pz    = -(2.0f * zFar * zNear) / (zFar - zNear);
//     float zero  = 0.0f;

//     return Mat4<float>(std::array<float, 16>{{
//         Sx,   zero,  zero,  zero,
//         zero,   Sy,  zero,  zero,
//         zero, zero,    Sz,    -1.0f,
//         zero, zero,    Pz,  zero
//     }});
// }

//------------------------------------------------------------
template<typename T> inline Mat4<T>
createMat4ProjectionMatrix(T fov, T aspect, T near, T far) {
    T const rad = fov;
    T const tanHalfFovy = std::tan(rad / static_cast<T>(2));

    T sX =    static_cast<T>(1) / (aspect * tanHalfFovy);
    T sY =    static_cast<T>(1) / (tanHalfFovy);
    T sZ = - (far + near) / (far - near);
    T sA =    static_cast<T>(-1);
    T sB = - (static_cast<T>(2) * far * near) / (far - near);
    T z  =    static_cast<T>(0);
     
    return Mat4<T>(std::array<T, 16>{{
        sX,  z,  z, z,
         z, sY,  z, z,
         z,  z, sZ, sB,
         z,  z, sA, z
    }});

    // most basic projection matrix - projecs Vec4 to [z]:-1 plane
    // return Mat4<T>(std::array<T, 16>{{
    //       1, 0,  0, 0,
    //       0, 1,  0, 0,
    //       0, 0,  1, 0,
    //       0, 0, -1, 0
    // }});
}

//------------------------------------------------------------
template<typename T> inline Mat4<T> 
createMat4ViewMatrix(Vec3<T> const & eye, Vec3<T> const & centre, Vec3<T> const & up) {

    Vec3<T> forward(0, 0,-1);
    Vec3<T> right(1, 0, 0);

    return Mat4<T>(std::array<T, 16>{{
           right.x,    right.y,    right.z, -eye.x,
              up.x,       up.y,       up.z, -eye.y,
        -forward.x, -forward.y, -forward.z, -eye.z,
                 0,          0,          0,      1
    }});

}

//----------------------w--------------------------------------
template<typename T> inline Mat4<T>
createMat4BirdsEyeViewMatrix() {
    return Mat4<T>(std::array<T, 16> {{
        1, 0,  0, 0,
        0, 0, -1, 0,
        0, 1,  0, 0,
        0, 0,  0, 1
    }});
}

//------------------------------------------------------------
template<typename T> inline Mat4<T>
createMat4ScreenSpaceTransform(T halfWidth, T halfHeight) {
    return Mat4<T>(std::array<T, 16>{{
          halfWidth,                 0, 0, 0,
                  0,       -halfHeight, 0, 0,
                  0,                 0, 1, 0,
          halfWidth,        halfHeight, 0, 1
    }});
}

// use existing

//------------------------------------------------------------
template<typename T> inline void 
setMat4Identity(Mat4<T> & matrix) {
    matrix = Mat4<T>(std::array<T, 16>{{ 
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    }});
}

//-------------------//
/*      Other        */
//-------------------//

//------------------------------------------------------------
template<typename T> inline void
transform(Vec4<T> & vec, Mat4<T> const & transformation) {
    vec = transformation * vec;
}

//------------------------------------------------------------
template<typename T> inline Mat3<T>
rotate(T angle, Vec3<T> const & axis) {
    return createMat3RotationMatrix<T>(axis * angle);
}

//------------------------------------------------------------
template<typename T> inline Mat4<T>
rotate(T angle, Vec4<T> const & axis) {
    return createMat4RotationMatrix<T>(axis * angle);
}

} /* namespace djc_math */
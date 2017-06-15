#include "djc_math.hpp"
#include <iostream>

using namespace djc_math;

void vec2_tests() {
    Vec2f vec_one(6, 5);
    Vec2f vec_two(4, 6);
    
    // member functions
    auto len = vec_one.length();
    auto len2 = vec_one.length();
    
    vec_one.normalise();
    
    auto dot = vec_one.dot(vec_two);
    
    // operator overloads - members
    +vec_one;
    -vec_one;

    vec_one += vec_two;
    vec_one -= vec_two;
    vec_one *= vec_two;
    vec_one /= vec_two;

    vec_one += 1.0f;
    vec_one -= 1.0f;
    vec_one *= 1.0f;
    vec_one /= 1.0f;

    // operator overloads - free funcitons
    auto add = vec_one + vec_two;
    auto sub = vec_one - vec_two;
    auto mul = vec_one * vec_two;
    auto div = vec_one / vec_two;   
    
    auto addF = 1.0f + vec_one;
    auto subF = 1.0f - vec_two;
    auto mulF = 1.0f * vec_one;
    auto divF = 1.0f / vec_one;
    
    auto addFF = vec_one + 1.0f;
    auto subFF = vec_one - 1.0f;
    auto mulFF = vec_one * 1.0f;
    auto divFF = vec_one / 1.0f;
    
    std::cout << vec_one << std::endl;
    
    // free functions
    ::normalise(vec_one);
    ::dot(vec_one, vec_two);
 
}

void vec3_tests() {
    // construction
    Vec3f vec_one(4, 5, 6);
    Vec3f vec_two(8, 8, 4);

    // member functions
    auto len = vec_one.length();
    auto len2 = vec_one.length2();
    
    vec_one.normalise();
    
    auto dot = vec_one.dot(vec_two);
    auto cross = vec_one.cross(vec_two); 
    
    auto to_vec2 = vec_one.toVec2();
   
    // free functino operator overloads
    auto add = vec_one + vec_two;
    auto sub = vec_one - vec_two;
    auto mul = vec_one * vec_two;
    auto div = vec_one / vec_two;
    
    auto addF = 1.0f + vec_one;
    auto subnF = 1.0f - vec_one;
    auto mulF = 1.0f * vec_one;
    auto divF = 1.0f / vec_one;

    auto addFF = vec_one + 1.0f;
    auto subFF = vec_one - 1.0f;
    auto mulFF = vec_one * 1.0f;
    auto divFF = vec_one / 1.0f;
    
    std::cout << vec_one << std::endl;

    // free function operator overload for use with other classes
    auto matrix_test = Mat3f() * vec_one;

    // free functions
    ::normalise(vec_one);
    auto dot_free = ::dot(vec_one, vec_two);

}

void vec4_tests() {
    Vec4f vec_one(1,1,1,1);
    Vec4f vec_two(2,2,2,2);
    
    // member functions
    auto len = vec_one.length();
    auto len2 = vec_one.length2();
    
    vec_one.normalise();

    auto dot = vec_one.dot(vec_two);
    auto to_vec2 = vec_one.toVec2();
    auto to_vec3 = vec_one.toVec3();
    
    // member operator overloads
    auto pos = +vec_one;
    auto neg = -vec_one;

    vec_one += vec_two;
    vec_one -= vec_two;
    vec_one *= vec_two;
    vec_one /= vec_two;

    vec_one += 1.0f;
    vec_one -= 1.0f;
    vec_one /= 1.0f;
    vec_one *= 1.0f;

    // free function operator overloads
    auto add = vec_one + vec_two;
    auto sub = vec_one - vec_two;
    auto mul = vec_one * vec_two;
    auto div = vec_one / vec_two;

    auto addF = 1.0f + vec_two;
    auto subF = 1.0f - vec_two;
    auto mulF = 1.0f * vec_two;
    auto divF = 1.0f / vec_two;

    auto addFF = vec_two + 1.0f;
    auto subFF = vec_two - 1.0f;
    auto mulFF = vec_two * 1.0f;
    auto divFF = vec_two / 1.0f;

    std::cout << vec_one << std::endl;

    // free function operator overloads for use with other classes
    auto matrix_test = Mat4f() * vec_one;

    // free functions
    ::normalise(vec_one);
    auto dot_free = ::dot(vec_one, vec_two);
}

void Mat3_tests() {
    // construction
    Mat3f mat_one;
    Mat3f mat_two;

    // friend free - // @TODO : clear() clear(T) need implementing 

    // friend free operators
    auto mult = mat_one * mat_two;
    auto mult_vec4 = mat_one * Vec3f(1.0f);
    std::cout << mat_one << std::endl;

    // private operators - cant test
    // ...
}

void Mat4_tests() {
    // construction
    Mat4f mat_one;
    Mat4f mat_two;

    // member functions
    auto to_mat3 = mat_one.toMat3();

    // friend free - // @TODO : clear() clear(T) need implementing 
    

    // friend free operators
    auto mult = mat_one * mat_two;
    auto mult_vec4 = mat_one * Vec4f(1.0f);
    std::cout << mat_one << std::endl;

    // private operators - cant test
    // ...
}

void Transform_test() {
    // mat3 

    auto iden_mat3 = createMat3IdentityMatrix<float>();
    auto rot_mat3 = createMat3RotationMatrix(Vec3f(1.0f));
    
    // mat4
    auto iden_mat4 = createMat4IdentityMatrix<float>();
    auto trans_mat4 = createMat4TranslationMatrix(Vec3f(1.0f));
    auto rot_mat4 = createMat4RotationMatrix(Vec3f(1.0f));
    auto scale_mat4 = createMat4ScaleMatrix(Vec3f(1.0f));
    auto model_mat4 = createMat4ModelMatrix(Vec3f(0.0f), Vec3f(0.0f), Vec3f(1.0f)); 
    auto ortho_mat4 = createMat4OrthographicMatrix(900, 600, 0.01f, 1000.0f);
    auto proj_mat4 = createMat4ProjectionMatrix(toRadians(70.0f), 900.0f / 600.0f, 0.01f, 1000.0f);
    auto view_mat4 = createMat4ViewMatrix(Vec3f(0), Vec3f(0), Vec3f(0,1,0));
    auto bird_view_mat4 = createMat4BirdsEyeViewMatrix<float>();
    auto screen_spaceTrans_mat4 = createMat4ScreenSpaceTransform(900.0f / 2.0f, 600.0f / 2.0f);
    
    // other
    Vec4f position(1.0, 1.0f, 1.0f, 1.0f);
     ::transform(position, trans_mat4);
    auto rotate_mat = ::rotate(90.0f, Vec3f(0,1,0));
}

void Utils_tests() {
    constexpr auto toRad = ::toRadians(90.0f);
    auto rand01 = ::randFBetweenZeroOne();
    auto randUC = ::randUCBetween0N255();
    auto norm = ::normalise(24.6f, 0.0f, 1.0f);
    auto lerp = ::lerp(0.0f, 100.0f, 50.0f);
    auto clamp = ::clamp(100.0f, 10.0f, 50.0f);

    Vec4f position (1.0, 1.0, 1.0, 5.0);
    ::perspectiveDivide(position);
}

int main() {

    // vector tests
    vec2_tests();
    vec3_tests();
    vec4_tests(); 

    // matrix tests

    return 0;
}

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

int main() {

    // vector tests
    vec2_tests();
    vec3_tests();
    vec4_tests(); 

    // matrix tests

    return 0;
}

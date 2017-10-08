#include "../djc_math/vec3.hpp"

//                         RAII                             // 
//------------------------------------------------------------
TEST_CASE("vec3 default constructor", "[vec3]") {
    djc::math::vec3i vec_a;

    REQUIRE(vec_a.x == 0);
    REQUIRE(vec_a.y == 0);
    REQUIRE(vec_a.z == 0);
}

TEST_CASE("vec3 1 for all constructor", "[vec3]") {
    djc::math::vec3i vec_a(4);

    REQUIRE(vec_a.x == 4);
    REQUIRE(vec_a.y == 4);
    REQUIRE(vec_a.z == 4);
}

TEST_CASE("vec3 standard constructor", "[vec3]") {
    djc::math::vec3i vec_a(1, 2, 3);

    REQUIRE(vec_a.x == 1);
    REQUIRE(vec_a.y == 2);
    REQUIRE(vec_a.z == 3);
}

TEST_CASE("vec3 constructor(vec2, scalar)", "[vec3]") {
    djc::math::vec3i vec_a(djc::math::vec2i(1, 2), 3);

    REQUIRE(vec_a.x == 1);
    REQUIRE(vec_a.y == 2);
    REQUIRE(vec_a.z == 3);
}

TEST_CASE("vec3 constructor(scalar, vec2)", "[vec3]") {
    djc::math::vec3i vec_a(1, djc::math::vec2i(2, 3));

    REQUIRE(vec_a.x == 1);
    REQUIRE(vec_a.y == 2);
    REQUIRE(vec_a.z == 3);
}

TEST_CASE("vec3 copy constructor", "[vec3]") {
    djc::math::vec3i vec_a(djc::math::vec3i(1, 2, 3));

    REQUIRE(vec_a.x == 1);
    REQUIRE(vec_a.y == 2);
    REQUIRE(vec_a.z == 3);
}

//                       functions                          // 
//------------------------------------------------------------
TEST_CASE("vec3 size", "[vec3]") {
    djc::math::vec3i vec;

    REQUIRE(vec.size() == 3);
}

//                   operator overloads                     // 
//------------------------------------------------------------
TEST_CASE("vec3 operator unary +", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3);
    
    vec = +vec;
    
    REQUIRE(vec.x == 1);
    REQUIRE(vec.y == 2);
    REQUIRE(vec.z == 3);

    vec = +vec;
    
    REQUIRE(vec.x == 1);
    REQUIRE(vec.y == 2);
    REQUIRE(vec.z == 3);
}

TEST_CASE("vec3 operator unary -", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3); 

    vec = -vec;
    
    REQUIRE(vec.x == -1);
    REQUIRE(vec.y == -2);
    REQUIRE(vec.z == -3);

    vec = -vec;

    REQUIRE(vec.x == 1);
    REQUIRE(vec.y == 2);
    REQUIRE(vec.z == 3);
}

TEST_CASE("vec3 operator +=", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3);
    
    vec += djc::math::vec3i(1, 2, 3);

    REQUIRE(vec.x == 2);
    REQUIRE(vec.y == 4);
    REQUIRE(vec.z == 6);
}

TEST_CASE("vec3 operator -=", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3);

    vec -= djc::math::vec3i(2, 3, 4);

    REQUIRE(vec.x == -1);
    REQUIRE(vec.y == -1);
    REQUIRE(vec.z == -1);
}

TEST_CASE("vec3 operator *=", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3);

    vec *= djc::math::vec3i(1, 2, 3);

    REQUIRE(vec.x == 1);
    REQUIRE(vec.y == 4);
    REQUIRE(vec.z == 9);
}

TEST_CASE("vec3 operator /=", "[vec3]") {
    djc::math::vec3i vec(10, 5, 20);

    vec /= djc::math::vec3i(2, 5, 10);

    REQUIRE(vec.x == 5);
    REQUIRE(vec.y == 1);
    REQUIRE(vec.z == 2); 
}

TEST_CASE("vec3 operator += scalar", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3);

    vec += 10;

    REQUIRE(vec.x == 11);
    REQUIRE(vec.y == 12);
    REQUIRE(vec.z == 13);
}

TEST_CASE("vec3 operator -= scalar", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3);

    vec -= 10;

    REQUIRE(vec.x == -9);
    REQUIRE(vec.y == -8);
    REQUIRE(vec.z == -7);
}

TEST_CASE("vec3 operator *= scalar", "[vec3]") {
    djc::math::vec3i vec(1, 2, 3);

    vec *= 10;

    REQUIRE(vec.x == 10);
    REQUIRE(vec.y == 20);
    REQUIRE(vec.z == 30);
}

TEST_CASE("vec3 operator /= scalar", "[vec3]") {
    djc::math::vec3i vec(10, 20, 30);

    vec /= 10;

    REQUIRE(vec.x == 1);
    REQUIRE(vec.y == 2);
    REQUIRE(vec.z == 3);
}

//                     free functions                       //
//------------------------------------------------------------
TEST_CASE("vec3 free function - magnitude", "[vec3]") {
    // unit vector tests 
    djc::math::vec3d vec(1.0, 0.0, 0.0);
    auto mag = djc::math::magnitude(vec);
    REQUIRE(mag == Approx(1.0));
    
    // negative unit vector test
    vec = djc::math::vec3d(-1.0, 0.0, 0.0);
    mag = djc::math::magnitude(vec);
    REQUIRE(mag == Approx(1.0));
    
    // non unit vector test
    vec = djc::math::vec3d(1.0, 1.0, 1.0);
    mag = djc::math::magnitude(vec);
    REQUIRE(mag == Approx(1.732050807568877)); 

}

TEST_CASE("vec3 free function - magnitude_squared", "[vec3]") {
    // unit vector
    djc::math::vec3d vec(1.0, 0.0, 0.0);
    auto mag_squared = djc::math::magnitude_squared(vec);
    REQUIRE(mag_squared == Approx(1.0));
    
    // negative unit vector
    vec = djc::math::vec3d(-1.0, 0.0, 0.0);
    mag_squared = djc::math::magnitude_squared(vec);
    REQUIRE(mag_squared == Approx(1.0));
    
    // non unit vector 
    vec = djc::math::vec3d(1.0, 1.0, 1.0);
    mag_squared = djc::math::magnitude_squared(vec);
    REQUIRE(mag_squared == Approx(3.0));
}

TEST_CASE("vec3 free function - normalise", "[vec3]") {
    // unit vector
    djc::math::vec3d vec(1.0, 0.0, 0.0);
    djc::math::vec3d norm_vec = djc::math::normalise(vec);
    REQUIRE(norm_vec.x == Approx(1.0));
    REQUIRE(norm_vec.y == Approx(0.0));
    REQUIRE(norm_vec.z == Approx(0.0));
    
    // negative unit vector
    vec = djc::math::vec3d(-1.0, 0.0, 0.0);
    norm_vec = djc::math::normalise(vec);
    REQUIRE(norm_vec.x == Approx(-1.0));
    REQUIRE(norm_vec.y == Approx(0.0));
    REQUIRE(norm_vec.z == Approx(0.0));
    
    // non unit vector
    vec = djc::math::vec3d(1.0, 1.0, 1.0);
    norm_vec = djc::math::normalise(vec);
    REQUIRE(norm_vec.x == Approx(0.577350269189626));
    REQUIRE(norm_vec.y == Approx(0.577350269189626));
    REQUIRE(norm_vec.z == Approx(0.577350269189626));
}

TEST_CASE("vec3 free function - dot", "[vec3]") {
    
}

TEST_CASE("vec3 free function - cross", "[vec3]") {
    
}

TEST_CASE("vec3 free function - clamp_magnitude", "[vec3]") {
    
}

TEST_CASE("vec3 free function - clamp", "[vec3]") {
    
}

TEST_CASE("vec3 free function - slerp", "[vec3]") {
    
}

//                  free function operators                 // 
//------------------------------------------------------------


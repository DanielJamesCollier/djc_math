#include "../djc_math/vec3.hpp"

//                         RAII                             // 
//------------------------------------------------------------
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
    REQUIRE(vec_a.z == 2);
}

TEST_CASE("vec3 copy constructor", "[vec3]") {
    djc::math::vec3i vec_a(djc::math::vec3i(1, 2, 3));

    REQUIRE(vec_a.x == 1);
    REQUIRE(vec_a.y == 2);
    REQUIRE(vec_a.z == 3);
}

//                       functions                          // 
//------------------------------------------------------------

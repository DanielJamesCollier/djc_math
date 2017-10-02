#include "../djc_math/vec2.hpp"

//                         RAII                             // 
//------------------------------------------------------------
TEST_CASE("vec2 1 value for all constructor", "[vec2]") {
    
    djc::math::vec2d vec(5);

    REQUIRE(vec.x == 5);
    REQUIRE(vec.y == 5); 
}

TEST_CASE("vec2 standard constructor", "[vec2]") {
    
    djc::math::vec2d vec(1, 2);

    REQUIRE(vec.x == 1);
    REQUIRE(vec.y == 2); 
}

TEST_CASE("vec2 copy constructor test", "[vec2]") {
    djc::math::vec2d vec_a(1, 2); 
    djc::math::vec2d vec_b(vec_a);

    REQUIRE(vec_b.x == 1);
    REQUIRE(vec_b.y == 2); 
}

//                       functions                          // 
//------------------------------------------------------------
TEST_CASE("vec2 length", "[vec2]") {
    // length of a positive vector 
    djc::math::vec2d vec_a(1, 1);

    REQUIRE(vec_a.length() == Approx(1.41421356237)); 
    
    // length of a negative vector
    djc::math::vec2d vec_b(-1, -1);

    REQUIRE(vec_b.length() == Approx(1.41421356237));
}

TEST_CASE("vec2 length2", "[vec2]") {
    // length2 of a positive vector
    djc::math::vec2d vec_a(1, 1);

    REQUIRE(vec_a.length2() == Approx(2.0));
    
    // length2 of a negative vector 
    djc::math::vec2d vec_b(-1, -1);

    REQUIRE(vec_b.length2() == Approx(2.0));
}

TEST_CASE("vec2 normalise", "[vec2]") {
    djc::math::vec2d vec(9812, 1893); // random numbers
    
    vec.normalise();

    REQUIRE(vec.length() == Approx(1.0));
}

TEST_CASE("vec2 dot", "[vec2]") {
    djc::math::vec2d vec_a(10, 10);
    djc::math::vec2d vec_b(5, 5);
    
    REQUIRE(vec_a.dot(vec_b) == Approx(100.0));
}

//                   operator overloads                     // 
//------------------------------------------------------------
TEST_CASE("operator unary +", "[vec2]") {
    // positive
    djc::math::vec2i vec_a(1, 2);
    auto result_a = +vec_a;
    REQUIRE(result_a.x == 1);
    REQUIRE(result_a.y == 2);

    // negative
    djc::math::vec2i vec_b(-1, -2);
    auto result_b = +vec_b;
    REQUIRE(result_b.x == -1);
    REQUIRE(result_b.y == -2);
}

TEST_CASE("operator unary -", "[vec2]") {
    // positive
    djc::math::vec2i vec_a(1, 2);
    auto result_a = -vec_a;
    REQUIRE(result_a.x == -1);
    REQUIRE(result_a.y == -2);
    
    // positive
    djc::math::vec2i vec_b(-1, -2);
    auto result_b = -vec_b;
    REQUIRE(result_b.x == 1);
    REQUIRE(result_b.y == 2);
}

TEST_CASE("operator += vec2", "[vec2]") {
    // positive 
    djc::math::vec2i vec(1, 1);
    vec += djc::math::vec2i(10,11);

    REQUIRE(vec.x == 11);
    REQUIRE(vec.y == 12);
    
    // negative
    djc::math::vec2i vec2(-1, -2);
    vec2 += djc::math::vec2i(15, 14);

    REQUIRE(vec2.x == 14);
    REQUIRE(vec2.y == 12);
}

TEST_CASE("operator -= vec2", "[vec2]") {
    // positive
    djc::math::vec2i vec(10, 10);
    vec -= djc::math::vec2i(4, 6);

    REQUIRE(vec.x == 6);
    REQUIRE(vec.y == 4);

    // negative
    djc::math::vec2i vec2(-10, -10);
    vec2 -= djc::math::vec2i(-4, -3);

    REQUIRE(vec2.x == -6);
    REQUIRE(vec2.y == -7);
}

TEST_CASE("operator *= vec2", "[vec2]") {
    // positive *= positive
    djc::math::vec2i vec(10, 10);
    vec *= djc::math::vec2i(8, 7);

    REQUIRE(vec.x == 80);
    REQUIRE(vec.y == 70);
    
    // positive *= negative
    djc::math::vec2i vec2(10, 10);
    vec2 *= djc::math::vec2i(-8, -7);

    REQUIRE(vec2.x == -80);
    REQUIRE(vec2.y == -70);

    // negative *= negative
    djc::math::vec2i vec3(-10, -10);
    vec3 *= djc::math::vec2i(-8, -7);

    REQUIRE(vec3.x == 80);
    REQUIRE(vec3.y == 70);
}

TEST_CASE("operator /= vec2", "[vec2]") {
    // positive /= positive
    djc::math::vec2i vec(10, 10);
    vec /= djc::math::vec2i(2, 5);
    
    REQUIRE(vec.x == 5);
    REQUIRE(vec.y == 2);

    // positive /= negative
    djc::math::vec2i vec2(10, 10);
    vec2 /= djc::math::vec2i(-2, -5);
    
    REQUIRE(vec2.x == -5);
    REQUIRE(vec2.y == -2);

    // negative /= negative
    djc::math::vec2i vec3(-10, -10);
    vec3 /= djc::math::vec2i(-2, -5); 

    REQUIRE(vec3.x == 5);
    REQUIRE(vec3.y == 2);
}

TEST_CASE("operator += scalar", "[vec2]") {
    // positive += positive
    djc::math::vec2i vec (1, 2);
    vec += 2;

    REQUIRE(vec.x == 3);
    REQUIRE(vec.y == 4);    

    // positive += negative
    djc::math::vec2i vec2(1, 2);
    vec2 += -2;

    REQUIRE(vec2.x == -1);
    REQUIRE(vec2.y ==  0);

    // negative += negative
    djc::math::vec2i vec3(-1, -2);
    vec3 += -2;

    REQUIRE(vec3.x == -3);
    REQUIRE(vec3.y == -4);
}

TEST_CASE("operator -= scalar", "[vec2]") {
    // positive -= positive
    djc::math::vec2i vec (1, 2);
    vec -= 2;

    REQUIRE(vec.x == -1);
    REQUIRE(vec.y ==  0);    

    // positive -= negative
    djc::math::vec2i vec2(1, 2);
    vec2 -= 2;

    REQUIRE(vec2.x == -1);
    REQUIRE(vec2.y ==  0);

    // negative -= negative
    djc::math::vec2i vec3(-1, -2);
    vec3 -= -2;

    REQUIRE(vec3.x == 1);
    REQUIRE(vec3.y == 0); 
}

TEST_CASE("operator *= scalar", "[vec2]") {
    // positive *= positive
    djc::math::vec2i vec (1, 2);
    vec *= 2;

    REQUIRE(vec.x == 2);
    REQUIRE(vec.y == 4);    

    // positive *= negative
    djc::math::vec2i vec2(1, 2);
    vec2 *= -2;

    REQUIRE(vec2.x == -2);
    REQUIRE(vec2.y == -4);

    // negative *= negative
    djc::math::vec2i vec3(-1, -2);
    vec3 *= -2;

    REQUIRE(vec3.x == 2);
    REQUIRE(vec3.y == 4);
}

TEST_CASE("operator /= scalar", "[vec2]") {
    // positive /= positive
    djc::math::vec2i vec (10, 20);
    vec /= 2;

    REQUIRE(vec.x == 5);
    REQUIRE(vec.y == 10);    

    // positive /= negative
    djc::math::vec2i vec2(10, 20);
    vec2 /= -2;

    REQUIRE(vec2.x == -5);
    REQUIRE(vec2.y == -10);

    // negative /= negative
    djc::math::vec2i vec3(-10, -20);
    vec3 /= -2;

    REQUIRE(vec3.x == 5);
    REQUIRE(vec3.y == 10);
}

//                     free functions                       //
//------------------------------------------------------------
TEST_CASE("free function - vec2 normalise", "[vec2]") {
    djc::math::vec2d vec(1 , 1);
    auto result = djc::math::normalise(vec);
    REQUIRE(result.length() == Approx(1.0));
}

TEST_CASE("free function - vec2 dot", "[vec2]") {
    djc::math::vec2d vec_a(10, 10);
    djc::math::vec2d vec_b(10, 10);
    REQUIRE(djc::math::dot(vec_a, vec_b) == 200);
}


TEST_CASE("free function - vec2 clamp_length", "[vec2]") {
    // positive 
    djc::math::vec2d vec_a(100, 100);

    auto result_a = djc::math::clamp_length(vec_a, 50.0);
    
    REQUIRE(result_a.length() == Approx(50.0));

    // negative
    djc::math::vec2d vec_b(-100, -100);

    auto result_b = djc::math::clamp_length(vec_b, 50.0);

    REQUIRE(result_b.length() == Approx(50));
}

TEST_CASE("free function - vec2 clamp", "[vec2]") {
    // upper bound clamp test 
    djc::math::vec2d vec_a(200, 200);
    
    REQUIRE(vec_a.length() == Approx(282.842712475));

    auto result_a = djc::math::clamp(vec_a, 200.0, 250.0);

    REQUIRE(result_a.length() == Approx(250.0));

    // lower bound clamp test
    djc::math::vec2d vec_b(200, 200);
   
    REQUIRE(vec_b.length() == Approx(282.842712475));

    auto result_v = djc::math::clamp(vec_b, 300.0, 400.0);

    REQUIRE(result_v.length() == Approx(300.0));
}

//                  free function operators                 // 
//------------------------------------------------------------
TEST_CASE("free function operator vec2 + vec2", "[vec2]") {
    // positive + positive
    auto vec_a = djc::math::vec2d(1.0, 2.0) + djc::math::vec2d(5.0, 10.0);
    REQUIRE(vec_a.x == Approx(6.0));
    REQUIRE(vec_a.y == Approx(12.0));

    // positive + negative
    auto vec_b = djc::math::vec2d(1.0, 2.0) + djc::math::vec2d(-5.0, -10.0);
    REQUIRE(vec_b.x == Approx(-4.0));
    REQUIRE(vec_b.y == Approx(-8.0));
    
    // negative + negative
    auto vec_c = djc::math::vec2d(-1.0, -2.0) + djc::math::vec2d(-5.0, -10.0);
    REQUIRE(vec_c.x == Approx(-6.0));
    REQUIRE(vec_c.y == Approx(-12.0));
}

TEST_CASE("free function operator vec2 - vec2", "[vec2]") { 
    // positive - positive
    auto vec_a = djc::math::vec2d(1.0, 2.0) - djc::math::vec2d(5.0, 10.0);
    REQUIRE(vec_a.x == Approx(-4.0));
    REQUIRE(vec_a.y == Approx(-8.0));

    // positive - negative
    auto vec_b = djc::math::vec2d(1.0, 2.0) - djc::math::vec2d(-5.0, -10.0);
    REQUIRE(vec_b.x == Approx(6.0));
    REQUIRE(vec_b.y == Approx(12.0));
    
    // negative - negative
    auto vec_c = djc::math::vec2d(-1.0, -2.0) - djc::math::vec2d(-5.0, -10.0);
    REQUIRE(vec_c.x == Approx(4.0));
    REQUIRE(vec_c.y == Approx(8.0));
}

TEST_CASE("free function operator vec2 * vec2", "[vec2]") { 
    // positive * positive
    auto vec_a = djc::math::vec2d(1.0, 2.0) * djc::math::vec2d(5.0, 10.0);
    REQUIRE(vec_a.x == Approx(5.0));
    REQUIRE(vec_a.y == Approx(20.0));

    // positive * negative
    auto vec_b = djc::math::vec2d(1.0, 2.0) * djc::math::vec2d(-5.0, -10.0);
    REQUIRE(vec_b.x == Approx(-5.0));
    REQUIRE(vec_b.y == Approx(-20.0));
    
    // negative * negative
    auto vec_c = djc::math::vec2d(-1.0, -2.0) * djc::math::vec2d(-5.0, -10.0);
    REQUIRE(vec_c.x == Approx(5.0));
    REQUIRE(vec_c.y == Approx(20.0));
}

TEST_CASE("free function operator vec2 / vec2", "[vec2]") { 
    // positive / positive
    auto vec_a = djc::math::vec2d(20.0, 10.0) / djc::math::vec2d(2.0, 2.0);
    REQUIRE(vec_a.x == Approx(10.0));
    REQUIRE(vec_a.y == Approx(5.0));

    // positive / negative
    auto vec_b = djc::math::vec2d(20.0, 10.0) / djc::math::vec2d(-2.0, -2.0);
    REQUIRE(vec_b.x == Approx(-10.0));
    REQUIRE(vec_b.y == Approx(-5.0));
    
    // negative / negative
    auto vec_c = djc::math::vec2d(-20.0, -10.0) / djc::math::vec2d(-2.0, -2.0);
    REQUIRE(vec_c.x == Approx(10.0));
    REQUIRE(vec_c.y == Approx(5.0));
}

TEST_CASE("free function operator scalar + vec2", "[vec2]") { 
    // positive + positive
    auto vec_a = 10.0 + djc::math::vec2d(2.0, 4.0);
    REQUIRE(vec_a.x == Approx(12.0));
    REQUIRE(vec_a.y == Approx(14.0));

    // positive + negative
    auto vec_b = 10.0 + djc::math::vec2d(-2.0, -4.0);
    REQUIRE(vec_b.x == Approx(8.0));
    REQUIRE(vec_b.y == Approx(6.0));
    
    // negative + negative
    auto vec_c = -10.0 + djc::math::vec2d(-2.0, -4.0);
    REQUIRE(vec_c.x == Approx(-12.0));
    REQUIRE(vec_c.y == Approx(-14.0));
}

TEST_CASE("free function operator scalar - vec2", "[vec2]") { 
    // positive - positive
    auto vec_a = 10.0 - djc::math::vec2d(2.0, 4.0);
    REQUIRE(vec_a.x == Approx(8.0));
    REQUIRE(vec_a.y == Approx(6.0));

    // positive - negative
    auto vec_b = 10.0 - djc::math::vec2d(-2.0, -4.0);
    REQUIRE(vec_b.x == Approx(12.0));
    REQUIRE(vec_b.y == Approx(14.0));
    
    // negative - negative
    auto vec_c = -10.0 - djc::math::vec2d(-2.0, -4.0);
    REQUIRE(vec_c.x == Approx(-8.0));
    REQUIRE(vec_c.y == Approx(-6.0));
}

TEST_CASE("free function operator scalar * vec2", "[vec2]") { 
    // positive * positive
    auto vec_a = 10.0 * djc::math::vec2d(2.0, 4.0);
    REQUIRE(vec_a.x == Approx(20.0));
    REQUIRE(vec_a.y == Approx(40.0));

    // positive * negative
    auto vec_b = 10.0 * djc::math::vec2d(-2.0, -4.0);
    REQUIRE(vec_b.x == Approx(-20.0));
    REQUIRE(vec_b.y == Approx(-40.0));
    
    // negative * negative
    auto vec_c = -10.0 * djc::math::vec2d(-2.0, -4.0);
    REQUIRE(vec_c.x == Approx(20.0));
    REQUIRE(vec_c.y == Approx(40.0));
}

TEST_CASE("free function operator scalar / vec2", "[vec2]") { 
    // positive / positive
    auto vec_a = 10.0 / djc::math::vec2d(2.0, 5.0);
    REQUIRE(vec_a.x == Approx(5.0));
    REQUIRE(vec_a.y == Approx(2.0));

    // positive / negative
    auto vec_b = 10.0 / djc::math::vec2d(-2.0, -5.0);
    REQUIRE(vec_b.x == Approx(-5.0));
    REQUIRE(vec_b.y == Approx(-2.0));
    
    // negative / negative
    auto vec_c = -10.0 / djc::math::vec2d(-2.0, -5.0);
    REQUIRE(vec_c.x == Approx(5.0));
    REQUIRE(vec_c.y == Approx(2.0));
}

TEST_CASE("free function operator vec2 + scalar", "[vec2]") {
    // positive + positive
    auto vec_a = djc::math::vec2d(2.0, 5.0) + 10.0;
    REQUIRE(vec_a.x == Approx(12.0));
    REQUIRE(vec_a.y == Approx(15.0));

    // positive + negative
    auto vec_b = djc::math::vec2d(2.0, 5.0) + -10.0;
    REQUIRE(vec_b.x == Approx(-8.0));
    REQUIRE(vec_b.y == Approx(-5.0));
    
    // negative + negative
    auto vec_c = djc::math::vec2d(-2.0, -5.0) + -10.0;
    REQUIRE(vec_c.x == Approx(-12.0));
    REQUIRE(vec_c.y == Approx(-15.0));
}

TEST_CASE("free function operator vec2 - scalar", "[vec2]") {
    // positive - positive
    auto vec_a = djc::math::vec2d(2.0, 5.0) - 10.0;
    REQUIRE(vec_a.x == Approx(-8.0));
    REQUIRE(vec_a.y == Approx(-5.0));

    // positive - negative
    auto vec_b = djc::math::vec2d(2.0, 5.0) - -10.0;
    REQUIRE(vec_b.x == Approx(12.0));
    REQUIRE(vec_b.y == Approx(15.0));
    
    // negative - negative
    auto vec_c = djc::math::vec2d(-2.0, -5.0) - -10.0;
    REQUIRE(vec_c.x == Approx(8.0));
    REQUIRE(vec_c.y == Approx(5.0));
}

TEST_CASE("free function operator vec2 * scalar", "[vec2]") {
    // positive * positive
    auto vec_a = djc::math::vec2d(2.0, 5.0) * 10.0;
    REQUIRE(vec_a.x == Approx(20.0));
    REQUIRE(vec_a.y == Approx(50.0));

    // positive * negative
    auto vec_b = djc::math::vec2d(2.0, 5.0) * -10.0;
    REQUIRE(vec_b.x == Approx(-20.0));
    REQUIRE(vec_b.y == Approx(-50.0));
    
    // negative * negative
    auto vec_c = djc::math::vec2d(-2.0, -5.0) * -10.0;
    REQUIRE(vec_c.x == Approx(20.0));
    REQUIRE(vec_c.y == Approx(50.0));
}

TEST_CASE("free function operator vec2 / scalar", "[vec2]") {
    // positive / positive
    auto vec_a = djc::math::vec2d(10.0, 4.0) / 2.0;
    REQUIRE(vec_a.x == Approx(5.0));
    REQUIRE(vec_a.y == Approx(2.0));

    // positive / negative
    auto vec_b = djc::math::vec2d(10.0, 4.0) / -2.0;
    REQUIRE(vec_b.x == Approx(-5.0));
    REQUIRE(vec_b.y == Approx(-2.0));
    
    // negative / negative
    auto vec_c = djc::math::vec2d(-10.0, -4.0) / -2.0;
    REQUIRE(vec_c.x == Approx(5.0));
    REQUIRE(vec_c.y == Approx(2.0));
}

#include "ostream"
#include "vector.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE("constructor, no parameters"){
    vector v;
    std::stringstream s;
    s << v;
    REQUIRE( s.str() == "(0,0)" );
}

TEST_CASE("constructor, two parameters"){
    vector v (1,2);
    std::stringstream s;
    s << v;
    REQUIRE( s.str() == "(1,2)" );
}

TEST_CASE ("add two vectors"){
    vector v1 (1,3);
    vector v2 (4,6);
    vector y = v1 + v2;
    std::stringstream s;
    s << y;
    REQUIRE(s.str() == "(5,9)");
}

TEST_CASE ("add negative vectors"){
    vector v1 (-1,6);
    vector v2 (4,-3);
    vector y = v1 + v2;
    std::stringstream s;
    s << y;
    REQUIRE(s.str() == "(3,3)");
}

TEST_CASE ("add vector into vector"){
    vector v1 (8,1);
    vector v2 (4,9);
    v2 += v1;
    std::stringstream s;
    s << v2;
    REQUIRE(s.str() == "(12,10)");
}

TEST_CASE("multiply, two vectors"){
    vector v (2,6);
    vector x = v * vector(8,3);
    std::stringstream s;
    s << x;
    REQUIRE( s.str() == "(16,18)" );
}

TEST_CASE("multiply, vector by integer"){
    vector v (2,6);
    vector x = v * 3;
    std::stringstream s;
    s << x;
    REQUIRE( s.str() == "(6,18)" );
}

TEST_CASE("multiply, integer by vector"){
    vector v (2,6);
    vector x = 3 * v;
    std::stringstream s;
    s << x;
    REQUIRE( s.str() == "(6,18)" );
}

TEST_CASE("multiply vector into vector"){
    vector x (2,3);
    x *= vector(8,3);
    std::stringstream s;
    s << x;
    REQUIRE( s.str() == "(16,9)" );
}

TEST_CASE("multiply vector with integer into vector"){
    vector x (2,3);
    x *= 6;
    std::stringstream s;
    s << x;
    REQUIRE( s.str() == "(12,18)" );
}

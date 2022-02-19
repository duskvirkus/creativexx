#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <creativexxspec.hxx>

TEST_CASE("linear_interpolate 0.5", "[math][interpolate]") {

  REQUIRE(0.5 == creative::math::linear_interpolate<float, float>(0.0, 1.0, 0.5));

}

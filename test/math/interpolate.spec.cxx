#define CATCH_CONFIG_MAIN
#include <torch/torch.h>
#include <catch.hpp>
#include <creativexxspec.hxx>

TEST_CASE("linear_interpolate 0.5", "[math][interpolate]") {
  REQUIRE(0.5 ==
          creative::math::linear_interpolate<float_t, float_t>(0.0, 1.0, 0.5));
}

TEST_CASE("linear_interpolate double linear", "[math][interpolate]") {
  double_t start = 0.0;
  double_t stop = 100.0;

  double_t expected[100];
  for (int i = 0; i < 100; ++i) {
    expected[i] = i;
  }

  for (int i = 0; i < 100; ++i) {
    REQUIRE(Approx(expected[i]) ==
            creative::math::linear_interpolate<double_t, double_t>(
                start, stop, (i) / 100.0));
  }
}

TEST_CASE("linear_interpolate torch::Tensor", "[math][interpolate]") {
  uint8_t size = 2;
  float_t* start_src = (float_t*)malloc(size * sizeof(float_t));
  float_t* stop_src = (float_t*)malloc(size * sizeof(float_t));
  float_t* expected_src = (float_t*)malloc(size * sizeof(float_t));
  start_src[0] = static_cast<float_t>(0.0);
  start_src[1] = static_cast<float_t>(1.0);
  stop_src[0] = static_cast<float_t>(1.0);
  stop_src[1] = static_cast<float_t>(4.0);
  expected_src[0] = static_cast<float_t>(0.5);
  expected_src[1] = static_cast<float_t>(2.5);
  torch::Tensor start = torch::from_blob(start_src, size, at::kFloat);
  torch::Tensor stop = torch::from_blob(stop_src, size, at::kFloat);
  torch::Tensor expected = torch::from_blob(expected_src, size, at::kFloat);

  torch::Tensor actual =
      creative::math::linear_interpolate<torch::Tensor, float_t>(
          start, stop, static_cast<float_t>(0.5));

  REQUIRE((expected == actual).sum().is_nonzero());
}

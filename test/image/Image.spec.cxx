#define CATCH_CONFIG_MAIN
#include <torch/torch.h>
#include <catch.hpp>
#include <creativexxspec.hxx>

TEST_CASE("Image test", "[image][Image]") {
  std::string path = "./assets/roses-256.jpg";
  std::cout << path << '\n';
  creative::image::Image img(path);
}

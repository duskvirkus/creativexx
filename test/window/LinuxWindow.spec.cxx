#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <creativexxspec.hxx>

TEST_CASE("Basic Linux Window", "[window][LinuxWindow]") {
  auto a = creative::window::Window::create();

  REQUIRE(a->width() == 800);
  REQUIRE(a->height() == 600);
}

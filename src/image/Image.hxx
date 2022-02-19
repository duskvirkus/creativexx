#ifndef CREATIVEXX_IMAGE_H
#define CREATIVEXX_IMAGE_H

#include <torch/torch.h>
#include <nonstd/string_view.hpp>

#include "../renderer/Texture.hxx"

namespace creative {
namespace image {

class Image {
 public:
  Image(const nonstd::string_view&);

  Image(const Image&) = delete;

  Image(const Image&&) = delete;

  Image& operator=(const Image&) = delete;

  Image& operator=(const Image&&) = delete;

  virtual ~Image() = default;

 private:
  std::unique_ptr<renderer::Texture> m_texture;
};

}  // namespace image
}  // namespace creative

#endif  // CREATIVEXX_IMAGE_H
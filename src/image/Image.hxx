#ifndef CREATIVEXX_IMAGE_H
#define CREATIVEXX_IMAGE_H

#include <torch/torch.h>
#include <nonstd/string_view.hpp>

#include "../renderer/Texture.hxx"

namespace creative {
namespace image {

class Image : renderer::Texture {
 public:
  Image(const nonstd::string_view&);

  Image(const Image&) = delete;

  Image(const Image&&) = delete;

  Image& operator=(const Image&) = delete;

  Image& operator=(const Image&&) = delete;

  virtual ~Image() = default;

  // size_t width() const;

  // size_t height() const;

  // size_t channels() const;

  // friend std::ostream& operator<<(std::ostream&, const
  // creative::image::Image&);

 private:
  // std::unique_ptr<renderer::Texture> m_texture;
};

}  // namespace image
}  // namespace creative

// std::ostream& operator<<(std::ostream&, const creative::image::Image&);

#endif  // CREATIVEXX_IMAGE_H
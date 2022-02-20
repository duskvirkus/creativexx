#ifndef CREATIVEXX_TEXTURE_H
#define CREATIVEXX_TEXTURE_H

#include <torch/torch.h>
#include <cstdint>

namespace creative {
namespace renderer {

class Texture {
 public:
  Texture();

  Texture(const torch::Tensor&);

  Texture(const Texture&) = delete;

  Texture(const Texture&&) = delete;

  Texture& operator=(const Texture&) = delete;

  Texture& operator=(const Texture&&) = delete;

  virtual ~Texture();

  // friend std::ostream& operator<<(std::ostream&, const Texture&);

 protected:
  // uint32_t m_texture_id;
  torch::Tensor* m_tensor_ptr;
};

}  // namespace renderer
}  // namespace creative

// std::ostream& operator<<(std::ostream&, const creative::renderer::Texture&);

#endif  // CREATIVEXX_TEXTURE_H

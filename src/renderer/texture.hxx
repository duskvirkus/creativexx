#ifndef CREATIVEXX_TEXTURE_H
#define CREATIVEXX_TEXTURE_H

#include <torch/torch.h>
#include <cstdint>

namespace creative {
namespace renderer {

class Texture {
 public:
  Texture(const torch::Tensor&);

  Texture(const Texture&) = delete;

  Texture(const Texture&&) = delete;

  Texture& operator=(const Texture&) = delete;

  Texture& operator=(const Texture&&) = delete;

  virtual ~Texture() = default;

 private:
  uint32_t m_texture_id;
  torch::Tensor m_texture;
};

}  // namespace renderer
}  // namespace creative

#endif  // CREATIVEXX_TEXTURE_H

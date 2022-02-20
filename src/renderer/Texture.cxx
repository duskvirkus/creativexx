#include "Texture.hxx"

namespace creative {
namespace renderer {

Texture::Texture() : m_tensor_ptr(nullptr) {}

Texture::Texture(const torch::Tensor& t) {
  m_tensor_ptr = new torch::Tensor(t);
}

Texture::~Texture() {
  if (m_tensor_ptr != nullptr) {
    delete m_tensor_ptr;
  }
}

}  // namespace renderer
}  // namespace creative

// std::ostream& operator<<(std::ostream& os, const creative::renderer::Texture&
// texture) {
//     os << *(texture.m_tensor_ptr);
//     return os;
// }

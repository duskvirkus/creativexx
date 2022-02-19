#include "Texture.hxx"

namespace creative {
namespace renderer {

Texture::Texture(const torch::Tensor& tex) : m_texture(tex) {}

}  // namespace renderer
}  // namespace creative
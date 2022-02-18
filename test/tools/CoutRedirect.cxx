#include "CoutRedirect.hxx"

namespace test {
namespace tools {

CoutRedirect::CoutRedirect() {
  m_saved = std::cout.rdbuf();
  std::cout.rdbuf(m_redirect.rdbuf());
}

CoutRedirect::~CoutRedirect() {
  std::cout.rdbuf(m_saved);
}

std::string CoutRedirect::str() const {
  return m_redirect.str();
}

}  // namespace tools
}  // namespace test

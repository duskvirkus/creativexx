#include "Path.hxx"

#include "../core/globals.hxx"
#include "../log/Log.hxx"

namespace creative {
namespace io {

Path::Path() {}

Path::Path(const nonstd::string_view& in_path) : m_data(in_path) {
  if (in_path[0] != '/') {
    CREATIVE_TRACE("Relative path detected.")

    m_data = program_path.get_path();
    append(in_path);
  }
}

std::string Path::get_path() const {
  return m_data;
}

void Path::append(const nonstd::string_view& to_append) {
  std::string append(to_append);
  if (append[0] == '.') {
    append = append.substr(1, append.size());
  }
  m_data += append;
}

}  // namespace io
}  // namespace creative

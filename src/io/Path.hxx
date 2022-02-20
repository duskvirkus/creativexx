
#ifndef CREATIVEXX_PATH_H
#define CREATIVEXX_PATH_H

#include <torch/torch.h>
#include <nonstd/string_view.hpp>
#include <string>

#include "../renderer/Texture.hxx"

namespace creative {
namespace io {

class Path {
 public:
  Path();

  Path(const nonstd::string_view&);

  Path(const Path&) = default;

  Path(Path&&) = default;

  Path& operator=(const Path&) = default;

  Path& operator=(Path&&) = default;

  virtual ~Path() = default;

  std::string get_path() const;

  void append(const nonstd::string_view&);

 protected:
  std::string m_data;
};

}  // namespace io
}  // namespace creative

#endif  // CREATIVEXX_PATH_H

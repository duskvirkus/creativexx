#include "init.hxx"

#include <unistd.h>
#include <cstring>

#include "./globals.hxx"

namespace creative {

void initialize(int argc, char** argv) {
  CREATIVE_TRACE("argc: " + std::to_string(argc))
  for (int i = 0; i < argc; ++i) {
    CREATIVE_TRACE("argv[" + std::to_string(i) + "]: " + argv[i])
  }

  char buf[FILENAME_MAX];
  getcwd(buf, FILENAME_MAX);
  program_path = io::Path(strcat(buf, (argv[0] + sizeof(char))));

  CREATIVE_INFO("creative::program_path: " + program_path.get_path())

  CREATIVE_INFO("Creative++ Was Initialized!")
}

}  // namespace creative

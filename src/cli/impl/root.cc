module;

#include "CLI/CLI.hpp"
#include <cstddef>
#include <fmt/format.h>

module cfxt.cli.cmd.root;

namespace cfxt {
std::string Version::ToString() const {
  return fmt::format("{}.{}.{}", major, minor, patch);
}

Version::Version(size_t major, size_t minor, size_t patch)
    : major(major), minor(minor), patch(patch) {}

void RootCommand::Setup(CLI::App &app, Version &version) {
  app.add_flag("-v, --verbose", this->verbose_, "verbose mode");
  app.set_version_flag(
          "-V, --version",
          fmt::format(
                  R"(cfxt is a scaffolding tool for C++ projects.
Copyright (c) 2026 CFLUXX
Copyright (c) 2026 the cfxt contributors
Licensed under the MIT License.


  ██████╗███████╗██╗  ██╗████████╗
  ██╔════╝██╔════╝╚██╗██╔╝╚══██╔══╝
  ██║     █████╗   ╚███╔╝    ██║
  ██║     ██╔══╝   ██╔██╗    ██║
  ╚██████╗██║     ██╔╝ ██╗   ██║
   ╚═════╝╚═╝     ╚═╝  ╚═╝   ╚═╝
               v{}
)",
                  version.ToString()
          )
  );
}


}  // namespace cfxt

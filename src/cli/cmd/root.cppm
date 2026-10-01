module;

#include "CLI/CLI.hpp"
#include <cli/command.h>
#include <cstddef>
#include <fmt/base.h>
#include <fmt/core.h>
#include <string>
#include <string_view>
#include <utils/logger.h>

export module cfxt.cli.cmd.root;
import cli11;

export namespace cfxt {
std::string logo = R"(
██████╗███████╗██╗  ██╗████████╗
██╔════╝██╔════╝╚██╗██╔╝╚══██╔══╝
██║     █████╗   ╚███╔╝    ██║
██║     ██╔══╝   ██╔██╗    ██║
╚██████╗██║     ██╔╝ ██╗   ██║
 ╚═════╝╚═╝     ╚═╝  ╚═╝   ╚═╝
             v1.0.0
)";

class Version {
public:
  std::string ToString() const;

  Version(size_t major, size_t minor, size_t patch);

private:
  size_t major;
  size_t minor;
  size_t patch;
};

class RootCommand {
public:
  void Setup(CLI::App &app, Version &version);
  int Run(Context &ctx);
  std::string_view Name() const;
  std::string_view Description() const;

private:
  bool verbose_ = false;
  CLI::App *root_;
};


}  // namespace cfxt

#include "cli/command.h"
import cfxt.cli.cmd.root;
#include "CLI/CLI.hpp"

int main(int argc, char **argv) {
  CLI::App app{"A project tool", "cfxt"};
  cfxt::Version version(1, 0, 0);
  cfxt::Context ctx{.verbose = false};
  cfxt::RootCommand root_cmd;
  root_cmd.Setup(app, version);
  CLI11_PARSE(app, argc, argv);
  return 0;
}

#pragma once
#include "CLI/CLI.hpp"
#include <string>
#include <string_view>

namespace cfxt {
struct Context {
  bool verbose = false;
};

class Command {
public:
  virtual ~Command()                           = default;
  virtual std::string_view Name() const        = 0;
  virtual std::string_view Description() const = 0;
  virtual void Setup(CLI::App &app)            = 0;
  virtual int Run(const Context &ctx)          = 0;
  bool triggered() const;

protected:
  CLI::App *sub_ = nullptr;
};
}  // namespace cfxt

#pragma once

#include <chrono>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/color.h>
#include <fmt/compile.h>
#include <fmt/core.h>
#include <string>
#include <utility>

#ifdef _WIN32
void EnableUTF8Console();
#endif  // _WIN32


namespace cfxt {
template <typename... Args>
void Info(fmt::format_string<Args...> fmt, Args &&...args) {
  fmt::print("{}\n", fmt::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void Step(fmt::format_string<Args...> fmt, Args &&...args) {
  fmt::print(fmt::fg(fmt::color::cyan), "[→] ");
  fmt::print("{}\n", fmt::format(fmt, std::forward<Args>(args)...));
}
template <typename... Args>
void Ok(fmt::format_string<Args...> fmt, Args &&...args) {
  fmt::print(fmt::fg(fmt::color::cyan), "[√] ");
  fmt::print("{}\n", fmt::format(fmt, std::forward<Args>(args)...));
}


template <typename... Args>
void Warn(fmt::format_string<Args...> fmt, Args &&...args) {
  fmt::print(fmt::fg(fmt::color::yellow), "[!] ");
  fmt::print("{}\n", fmt::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void Error(fmt::format_string<Args...> fmt, Args &&...args) {
  fmt::print(stderr, fmt::fg(fmt::color::red), "[×] ");
  fmt::print(stderr, "{}\n", fmt::format(fmt, std::forward<Args>(args)...));
}

template <typename... Args>
void Fatal(fmt::format_string<Args...> fmt, Args &&...args) {
  fmt::print(stderr, fmt::fg(fmt::color::red), "[EXIT] ");
  fmt::print(stderr, "{}\n", fmt::format(fmt, std::forward<Args>(args)...));
  std::exit(1);
}

}  // namespace cfxt

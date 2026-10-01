cmake_minimum_required(VERSION 3.28.0)
project(cfxt
    LANGUAGES CXX C
    VERSION 0.1.0
)

include(cmake/Settings.cmake)
include(cmake/DepPackage.cmake)
include(cmake/BuildOption.cmake)


add_subdirectory(src)
add_subdirectory(src/cli)
add_subdirectory(tests)

include(cmake/InstallRules.cmake)
include(cmake/CPackConfig.cmake)

file(GLOB CORE_CFXT_SOURCES
        ${CMAKE_SOURCE_DIR}/src/config/impl/*.cc
        ${CMAKE_SOURCE_DIR}/src/core/impl/*.cc
        ${CMAKE_SOURCE_DIR}/src/template/impl/*.cc
        ${CMAKE_SOURCE_DIR}/src/utils/*.cc
)

file(GLOB CORE_CFXT_MODULES
        ${CMAKE_SOURCE_DIR}/src/config/*.cppm
        ${CMAKE_SOURCE_DIR}/src/core/*.cppm
        ${CMAKE_SOURCE_DIR}/src/template/*.cppm
)

message("[sources]: ${CORE_CFXT_SOURCES}")
message("[modules]: ${CORE_CFXT_MODULES}")

add_library(cfxtcore STATIC)

target_sources(cfxtcore
    PRIVATE
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}
        FILES ${CORE_CFXT_MODULES}
)

target_sources(cfxtcore
    PRIVATE
        ${CORE_CFXT_SOURCES}
)

target_include_directories(cfxtcore
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/third_party
)

set(DEPS_MODULE_CORE
        nlohmann_json::nlohmann_json
        fmt::fmt
        tomlplusplus::tomlplusplus
)

target_link_libraries(cfxtcore
    PRIVATE
        ${DEPS_MODULE_CORE}
)

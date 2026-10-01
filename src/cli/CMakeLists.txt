add_executable(cfxt)

file(GLOB CLI_SOURCE
    ${CMAKE_SOURCE_DIR}/src/cli/main.cc
    ${CMAKE_SOURCE_DIR}/src/cli/impl/*.cc
)

file(GLOB CLI_MODULE
    ${CMAKE_SOURCE_DIR}/src/cli/cmd/*.cppm
)

target_link_libraries(cfxt
    PRIVATE
        cfxtcore
        ${DEPS_MODULE_CORE}
)


target_sources(cfxt
    PRIVATE
        FILE_SET CXX_MODULES
        BASE_DIRS ${CMAKE_SOURCE_DIR}/src/cli
        FILES
            CLI11/CLI11.cppm
            ${CLI_MODULE}

)

target_sources(cfxt
    PRIVATE
        ${CLI_SOURCE}
)

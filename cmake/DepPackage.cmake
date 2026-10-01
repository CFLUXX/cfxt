include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/dep)
set(FETCHCONTENT_QUIET OFF)

if(DEFINED VCPKG_TARGET_TRIPLET OR DEFINED VCPKG_INSTALLED_DIR)
    set(VCPKG_ENABLED ON)
    message(STATUS "[Deps] vcpkg environment detected")
else()
    set(VCPKG_ENABLED OFF)
    message(STATUS "[Deps] vcpkg not detected, fallback to system/FetchContent")
endif()

macro(find_or_fetch packageName targetName gitRepo gitTag)
    string(TOLOWER ${packageName} _lc_name)

    find_package(${packageName} CONFIG QUIET)

    if(NOT ${packageName}_FOUND)
        find_package(${packageName} QUIET)
    endif()

    if((NOT ${packageName}_FOUND) AND VCPKG_ENABLED)
        find_package(${packageName} CONFIG QUIRED)
        message(STATUS "[Deps] ${packageName} via vcpkg ✓")
    endif()

    if(NOT ${packageName}_FOUND)
        message(STATUS "[Deps] ${packageName} NOT FOUND, Try Fetching From ${gitRepo}")
        FetchContent_Declare(
            ${_lc_name}
            GIT_REPOSITORY ${gitRepo}
            GIT_TAG ${gitTag}
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE
        )
        FetchContent_MakeAvailable(${_lc_name})

        message(STATUS "[Deps] ${packageName} fetched and built")
    else()
        message(STATUS "[Deps] ${packageName} found system-wide: ${${packageName}_DIR}")
    endif()

    if(NOT TARGET ${targetName})
        message(FATAL_ERROR
            "[Deps] Target '${targetName}' not found for package '${packageName}'.\n"
            "Available targets may differ. Check the library's CMakeLists.txt for exported target names."
        )
    endif()
endmacro()


# fmt: v11.2.0
find_or_fetch(fmt fmt::fmt
    "https://github.com/fmtlib/fmt.git"
    "v11.2.0"
)

# nlohmann_json: v3.12.0
find_or_fetch(nlohmann_json nlohmann_json::nlohmann_json
    "https://github.com/nlohmann/json.git"
    "v3.12.0"
)

# toml++: v3.4.0
find_or_fetch(tomlplusplus tomlplusplus::tomlplusplus
    "https://github.com/marzer/tomlplusplus.git"
    "v3.4.0"
)

# ====== GTEST ======
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
find_or_fetch(GTest GTest::gtest_main
    "https://github.com/google/googletest.git"
    "v1.18.0"
)

if(NOT TARGET GTest::gtest_main)
    message(FATAL_ERROR "[Deps] GTest::gtest_main not found")
endif()

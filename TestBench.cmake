
set(GTEST_ROOT "${PROJECT_PATH};${PROJECT_PATH}/googletest;${PROJECT_PATH}/googletest/googletest;${PROJECT_PATH}/..;${PROJECT_PATH}/../googletest;${PROJECT_PATH}/../googletest/googletest;${PROJECT_PATH}/googletest/googlemock"
          CACHE PATH "Path to googletest")

macro(fetch_googletest _download_module_path _download_root)
    set(GOOGLETEST_DOWNLOAD_ROOT ${_download_root})
    configure_file(
        ${_download_module_path}/googletest-download.cmake
        ${_download_root}/CMakeLists.txt
        @ONLY
        )
    unset(GOOGLETEST_DOWNLOAD_ROOT)

    execute_process(
        COMMAND
            "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY
            ${_download_root}
        )
    execute_process(
        COMMAND
            "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY
            ${_download_root}
        )

    # adds the targers: gtest, gtest_main, gmock, gmock_main
    add_subdirectory(
        ${_download_root}/googletest-src
        ${_download_root}/googletest-build
        )
endmacro()

# fetch googletest
fetch_googletest(
    ${GTEST_ROOT}/external
    ${GTEST_ROOT}/external/googletest
    )

# enable testing
enable_testing()

# define tests
add_subdirectory(test)

find_path(GMOCK_INCLUDE_DIR gtest/gtest.h
  HINTS
    $ENV{GMOCK_ROOT}/include
    ${GMOCK_ROOT}/include
)
mark_as_advanced(GMOCK_INCLUDE_DIR)
set(GMOCK_INCLUDE_DIRS ${GMOCK_INCLUDE_DIR})

cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(motor-control)
set(PROJECT_NAME "motor-control")
set(PROJECT_PATH                               "${CMAKE_CURRENT_SOURCE_DIR}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}     "${PROJECT_PATH}/cmake/Modules")
set(INCLUDE_PATH                               "${PROJECT_PATH}/include")
set(SRC_PATH                                   "${PROJECT_PATH}/src")
set(TEST_SRC_PATH                              "${PROJECT_PATH}/test")

if(NOT EXTERNAL_PATH)
  set(EXTERNAL_PATH                            "${PROJECT_PATH}/external")
endif(NOT EXTERNAL_PATH)
if(NOT DOXYGEN_PATH)
  set(DOXYGEN_PATH                             "${PROJECT_PATH}/docs")
endif(NOT DOXYGEN_PATH)

set(MAIN_NAME                                  "${PROJECT_NAME}_main")
set(TEST_PATH                                  "${PROJECT_BINARY_DIR}/test")
set(TEST_NAME                                  "test_${PROJECT_NAME}")

OPTION(BUILD_MAIN                              "Build main function"            ON)
OPTION(BUILD_DOXYGEN_DOCS                      "Build Doxygen docs"             OFF)
OPTION(BUILD_DEPENDENCIES                      "Force build of dependencies"    OFF)

# Set platform-specific compiler flags.
if(WIN32)
  if(MSVC)
    set(TEST_PATH                                  "${PROJECT_BINARY_DIR}/test/Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /Ox /W3 /FC -D_SCL_SECURE_NO_WARNINGS")
    # We need to force MSVC to use static runtime:
    # (from http://www.cmake.org/Wiki/CMake_FAQ#Dynamic_Replace).
    foreach(flag_var
      CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
      # Find all dynamic runtime (MD) references and replace with static (MT)
      if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
      endif(${flag_var} MATCHES "/MD")
    endforeach(flag_var)
  else(MSVC)
    set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -Wall -Woverloaded-virtual -Wold-style-cast -Wnon-virtual-dtor")
  endif(MSVC)
else(WIN32)
  set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Woverloaded-virtual -Wold-style-cast -Wnon-virtual-dtor")
endif(WIN32)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif(CMAKE_COMPILER_IS_GNUCXX)

include(TestBench.cmake)
include(ProjectConfig.cmake)
include_directories(AFTER "${INCLUDE_PATH}")


add_executable(${PROJECT_NAME} ${MAIN_SRC})

if(BUILD_DOXYGEN_DOCS)
  find_package(Doxygen)

  if(NOT DOXYGEN_FOUND)
    message(FATAL_ERROR
            "Doxygen is needed to build the documentation. Please make sure it is installed.")
  endif(NOT DOXYGEN_FOUND)

  configure_file(${PROJECT_PATH}/Doxyfile.in
                 ${PROJECT_BINARY_DIR}/Doxyfile @ONLY IMMEDIATE)

  # Add a custom target to run Doxygen whenever the project is built.
  # If you want the documentation to be generated EVERY time you build the project
  # then add the 'ALL' keyword before 'COMMAND' below.
  add_custom_target(doxygen_docs COMMAND ${DOXYGEN_EXECUTABLE}
                    ${PROJECT_BINARY_DIR}/Doxyfile
                    SOURCES ${PROJECT_BINARY_DIR}/Doxyfile)
endif(BUILD_DOXYGEN_DOCS)

install(DIRECTORY ${INCLUDE_PATH}/${CMAKE_PROJECT_NAME}
        DESTINATION include
        FILES_MATCHING PATTERN "*.hpp")
install(TARGETS ${BIN_NAME} DESTINATION bin)

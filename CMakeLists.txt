cmake_minimum_required(VERSION 3.5)

project(stream VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

# config

if(NOT PROJECT_ROOT)
  set(PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
endif()

# option

option(BUILD_TEST "Build test" ON)

# target

set(OUTPUT_DIR "${PROJECT_ROOT}/_output")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

include_directories(
  ${PROJECT_ROOT}/include
)

## test

if(BUILD_TEST)
  add_subdirectory(test)
endif()

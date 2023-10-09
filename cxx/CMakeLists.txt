cmake_minimum_required(VERSION 3.18)

project(
  cxx
  VERSION 0.0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
include(Cache)
include(Sanitizers)
include(Warnings)

file(
  GLOB_RECURSE
  ${PROJECT_NAME}_SRC
  include/*.hpp
  include/*.h
  src/*.cpp
  src/*.hpp
  src/*.h
  ${PROJECT_SOURCE_DIR}/../target/cxxbridge/cxx-bindings/src/*.cc
  ${PROJECT_SOURCE_DIR}/../target/cxxbridge/cxx-bindings/src/*.h)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRC})
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE include ${PROJECT_SOURCE_DIR}/../target/cxxbridge/cxx-bindings/src)
target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC
    ${PROJECT_SOURCE_DIR}/../target/$<IF:$<CONFIG:Debug>,debug,release>/libcxx_bindings.a
)
target_precompile_headers(${PROJECT_NAME} PRIVATE "include/Precompiled.hpp")

enable_sanitizers(${PROJECT_NAME})
set_project_warnings(${PROJECT_NAME})

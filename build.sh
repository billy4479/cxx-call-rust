#!/bin/sh

set -e

if [ "$1" = "--release" ]; then 
    cargo build --release
    cmake -B build -S cxx -D CMAKE_BUILD_TYPE=Release
    cmake --build build
else
    cargo build
    cmake -B build -S cxx -D CMAKE_BUILD_TYPE=Debug
    cmake --build build
fi
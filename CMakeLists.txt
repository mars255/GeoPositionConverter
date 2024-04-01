cmake_minimum_required(VERSION 3.0)
project(GeoPositionConverter)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    include
)

set(SOURCES
    src/test.cpp
    src/coordinates/coordinates.cpp
    src/conversion/conversion.cpp
)

add_executable(test ${SOURCES})


cmake_minimum_required(VERSION 3.10)
project(cpputils CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header files directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)

# Find all .cpp files recursively, excluding the build directory
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "/build/")

# Build executable
add_executable(main ${SOURCES})

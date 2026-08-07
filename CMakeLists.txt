cmake_minimum_required(VERSION 3.14)
project(cpputils CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define cpputils library target
add_library(cpputils
    RString/RString.cpp
    RString/RStringUtils.cpp
)

# Export include directory for cpputils target
target_include_directories(cpputils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(cpputils PUBLIC cxx_std_17)

# Alias target so consumers can link against cpputils::cpputils
add_library(cpputils::cpputils ALIAS cpputils)

# Build driver executable only when cpputils is the root project
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    add_executable(main main.cpp)
    target_link_libraries(main PRIVATE cpputils)
endif()


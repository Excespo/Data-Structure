# Project name/ type
project(Sample 1 CXX)

# Build flags
set(CMAKE_CXX_FLAGs "${CMAKE_CXX_FLAGS_INIT} -Wall --std=c++17")

# Source file
file(GLOB SRC
        "src/*.c"
        "src/*.cpp")

# Include headers
include_directories("include")

add_executable(main ${SRC})
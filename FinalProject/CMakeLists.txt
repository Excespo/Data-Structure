cmake_minimum_required(VERSION 3.16)
project(Data-Structure-Final-Project)
set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/include)

# add test
add_executable(test_adjacency tests/test_adjacency.cc src/adjacency.cc)
add_executable(test_minHeap tests/test_minHeap.cc)
add_executable(test_edges tests/test_edges.cc src/adjacency.cc src/edges.cc)
add_executable(test_MST tests/test_MST.cc src/MST.cc src/edges.cc src/adjacency.cc)
add_executable(test_dijkstra tests/test_dijkstra.cc src/dijkstra.cc src/adjacency.cc src/edges.cc)
# add main
add_executable(main src/main.cpp)

#
# How to use CMAKE
# 
# > cd build
# > cmake ..
# > make
# > ./executable
#
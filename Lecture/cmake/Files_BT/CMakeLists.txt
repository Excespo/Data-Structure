cmake_minimum_required(VERSION 3.16)
project(2022-03-26_BT)
set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(BinNodePtrMain src/BinNodePtrMain.cpp)
add_executable(MixBinNodeMain src/MixBinNodeMain.cpp)
add_executable(VarBinNodeCompMain src/VarBinNodeCompMain.cpp)
add_executable(VarBinNodeInhMain src/VarBinNodeInhMain.cpp)
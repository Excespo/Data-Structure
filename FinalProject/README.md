# Route Planning
Route Planning is the final project of SJTU SPEIT Data Structure 2022 Spring. 

_Author_: LUO Yijie

_SJTU ID_: 519260910009

## Overview
In this project, I've accomplished
- [x] Adjacency Matrix
- [x] Adjacency List
- [x] MinHeap Sort
- [x] 2-way Merge Sort
- [x] Minimum-cost Spanning Tree(MST)
- [x] Shortest Path

## Directory

In order to use compile toolkit including `make`, `cmake`, the directory includes:
 - `include:` C++ header files
 - `src`: C++ source files
 - `tests`: C++ source files constructed for testing
 - `script`: Shell script to pack all works
 - `report`: Latex files to produce the lab report
 - `Dockerfile`: Docker configurations
 - `CMakeLists.txt`: Used to control the compile procedure
 - `Makefile`: Used to control the whole project

More details for directory structure, look at [this tree file](./Dir)

## Quick run
Make sure that your machine support the usage of `docker`, as this project environment is established a the `docker` container.

To establish the docker environment, use
```
make env-build
```
This may take some time, but you will only have to build it for one time. Then to activate the container, use
```
make env-activate
```
If the bash command prompt changes to like `>root@xxx`, Congratulations! The environment is successfully activated. If you want to leave the environment, use `exit`

Then to build the executables, use
```
make all
```
If you can see the welcome words shown, Congratulations! This means all the executables are successfully built now.

To run the executables, as an example, use
```
build/test_dijkstra
```
And you will see the test for _dijkstra_ algorithm. The optional executables includes:
- main
- test_adjacency
- test_edges
- test_minHeap
- test_MST
- test_dijkstra

## Other usages

You can get some other usages in the Makefile, and also you can run `sh script/update.sh` to update every changes in the project (locally) and it will pack the directory into a zip file.
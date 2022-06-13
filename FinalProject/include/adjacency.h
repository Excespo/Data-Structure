#pragma once

// #include <bits/stdc++.h> // too slow???
#include "types.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>

// AL dtype
using adj_list_node_type = std::pair<vertice_type,
                                     std::vector<vertice_type>>;  // first store the head of sublist,
                                                                  // second is the subsequent list
using adj_list_type = std::vector<adj_list_node_type>;

class AdjacencyMatrix {
  private:
    ;

  protected:
    int _v_size;  // size of vertice
    int _e_size;  // size of edge
    std::vector<vertice_type> _vertices;
    vertice_to_idx_map_type _v2idx;
    idx_to_vertice_map_type _idx2v;
    adj_matrix_type _adjMat;

  public:
    AdjacencyMatrix(std::vector<vertice_type> vs, std::vector<weighted_edge_type> wes);
    // AdjacencyMatrix(weight_type **adj_mat, int size);
    ~AdjacencyMatrix(){};
    std::vector<vertice_type> get_vertices() { return _vertices; }
    vertice_to_idx_map_type get_v2idx() { return _v2idx; }
    idx_to_vertice_map_type get_idx2v() { return _idx2v; }
    adj_matrix_type get_adjMat() { return _adjMat; }
    int get_v_size(void) { return _v_size; }
    int get_e_size(void) { return _e_size; }
    // friend std::ostream& operator<<(std::ostream cout, AdjacencyMatrix am);
    void print();
};

class AdjacencyList  // use vector to inplement AdjList
{
  private:
    ;

  protected:
    int _v_size;
    int _e_size;
    std::vector<vertice_type> _vertices;
    vertice_to_idx_map_type _v2idx;
    idx_to_vertice_map_type _idx2v;
    adj_list_type _adjList;

  public:
    AdjacencyList(std::vector<vertice_type> vs, std::vector<weighted_edge_type> wes);
    AdjacencyList(AdjacencyMatrix am);
    ~AdjacencyList(){};
    int get_v_size(void) { return _v_size; }
    int get_e_size(void) { return _e_size; }
    void print();
};

// interface to use
using AM = AdjacencyMatrix;
using AL = AdjacencyList;
void printAM(AM am);
void printAL(AL al);
AM genAM(void);
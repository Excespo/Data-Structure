#include "adjacency.h"  // AM
#include "edges.h"      // sort
#include "types.h"

#include <algorithm>
#include <iostream>
#include <stack>

/* only vertices included to represent a connected graph
 * just a constraint, so the original graph structure is needed
 */
using connected_graph_type = std::vector<weighted_edge_type>;

std::vector<vertice_type> all_vertices(std::vector<weighted_edge_type> w);

std::vector<vertice_type> adjacent_vertices(std::vector<weighted_edge_type> w_edges, vertice_type vertex);

std::vector<weighted_edge_type> adjacent_weighted_edges(std::vector<weighted_edge_type> w, vertice_type v);

std::vector<connected_graph_type> connected_components(std::vector<weighted_edge_type> w_edges);

bool is_connected(std::vector<weighted_edge_type> w_edges);

int count_vertices(std::vector<weighted_edge_type> w_edges);  // should be connected graph

bool is_cyclic(std::vector<weighted_edge_type> w_edges);  // should be connected graph

std::vector<weighted_edge_type> GenMST(std::vector<weighted_edge_type> w_edges);

weight_type sum_weight(std::vector<weighted_edge_type> w_edges);

// build_tree
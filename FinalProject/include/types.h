#pragma once

#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

// basic dtype for vertice and edge
using vertice_type = std::string;  // can be replaced by template
using edge_type = std::pair<std::string, std::string>;
using weighted_edge_type = std::pair<edge_type, int>;
// bidirectional map vertice <-> idx
using vertice_to_idx_map_type = std::map<vertice_type, int>;
using idx_to_vertice_map_type = std::map<int, vertice_type>;
// weight
using weight_type = int;
#define INF 0x7f7f7f7f  // valid on map as there is no negative distance
// AM dtype
using adj_matrix_row_type = std::vector<weight_type>;
using adj_matrix_type = std::vector<adj_matrix_row_type>;

inline std::ostream &operator<<(std::ostream &cout, weighted_edge_type w_edge) {
    weight_type w = w_edge.second;
    vertice_type v1 = w_edge.first.first, v2 = w_edge.first.second;
    std::cout << "[" << v1 << " <--" << w << "--> " << v2 << "]";
    return std::cout;
}  // need inline to avoid multiple definition

/* Comparison of weighted edges */
#define eq(we1, we2)                                                                                                   \
    (((we1).second == (we2).second) &&                                                                                 \
         (((we1).first.first == (we2).first.first) && ((we1).first.second == (we2).first.second)) ||                   \
     (((we1).first.second == (we2).first.first) && ((we1).first.first == (we2).first.second)))

#define neq(we1, we2) (!eq((we1), (we2)))

inline bool operator==(const weighted_edge_type &we1, const weighted_edge_type &we2) {
    bool order1 = (we1.first.first == we2.first.first) && (we1.first.second == we2.first.second);
    bool order2 = (we1.first.first == we2.first.second) && (we1.first.second == we2.first.first);
    return ((we1.second == we2.second) && (order1 || order2));
}

inline bool operator!=(const weighted_edge_type &we1, const weighted_edge_type &we2) {
    bool order1 = (we1.first.first != we2.first.first) || (we1.first.second != we2.first.second);
    bool order2 = (we1.first.first != we2.first.second) || (we1.first.second != we2.first.first);
    return ((we1.second != we2.second) || (order1 && order2));
}
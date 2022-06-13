#pragma once

#include "adjacency.h"  // AM
#include "minHeap.h"
#include "types.h"

std::vector<weighted_edge_type> getEdgesAM(AM am);

/* overload << for weighted_edge_type */
// std::ostream& operator<<(std::ostream& cout, weighted_edge_type w_edge);
/* duplicated. Move to types.h */

weight_type get_weight(weighted_edge_type w_edge);

/* Ascending Sort*/
/* need to show intermediate configurations */
void minHeapSort(std::vector<weighted_edge_type> &w_edges);

/* Ascending Sort */
/* need to show intermediate configurations */
void MergeSort(std::vector<weighted_edge_type> &w_edges);

/* Asc Sort Clear Ver */
void EdgeSort(std::vector<weighted_edge_type> &w_edges);
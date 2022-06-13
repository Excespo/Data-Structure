#include "adjacency.h"  // AM, types
#include "edges.h"      // sort
#include "minHeap.h"

#include <queue>
#include <set>

using preceding_vertice_map_type = std::map<vertice_type, vertice_type>;

preceding_vertice_map_type dijkstraAM(AM am, vertice_type src, vertice_type dst);
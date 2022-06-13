#include "adjacency.h"
#include "dijkstra.h"

int main() {
    AM am = genAM();
    vertice_type src, dst;
    // src = "WL", dst = "SH";
    src = "SY";
    dst = "LS";
    // src = "WL"; dst = "SY";

    dijkstraAM(am, src, dst);
}
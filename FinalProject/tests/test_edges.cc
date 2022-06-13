#include "edges.h"

int main() {
    std::cout << "Test for edges.cc\n";
    AM testAM = genAM();
    std::vector<weighted_edge_type> w_edges = getEdgesAM(testAM);
    std::cout << "============= TEST FOR getEdgeAM BEGINS =============\n";
    std::cout << "Got Weighted Edges in this AM:\n";
    for (int i = 0; i < w_edges.size(); i++)
        std::cout << w_edges[i] << "\n";
    std::cout << "============== TEST FOR getEdgeAM ENDS ==============\n";

    std::cout << "============ TEST FOR minHeapSort BEGINS ============\n";
    std::cout << "Got Sorted Weighted Edges\n";

    minHeapSort(w_edges);
    for (int i = 0; i < w_edges.size(); i++)
        std::cout << w_edges[i] << "\n";

    std::cout << "============= TEST FOR minHeapSort ENDS =============\n";

    testAM = genAM();
    w_edges = getEdgesAM(testAM);  // reinitiate
    std::cout << "============= TEST FOR MergeSort BEGINS =============\n";
    std::cout << "Got Sorted Weighted Edges\n";

    MergeSort(w_edges);
    for (int i = 0; i < w_edges.size(); i++)
        std::cout << w_edges[i] << "\n";

    std::cout << "============== TEST FOR MergeSort ENDS ==============\n";
    return 0;
}
#include "edges.h"

std::vector<weighted_edge_type> getEdgesAM(AM am) {
    adj_matrix_type mat = am.get_adjMat();
    // std::vector<vertice_type> vertices = am.get_vertices();
    idx_to_vertice_map_type idx2v = am.get_idx2v();
    int size = am.get_v_size();

    std::vector<weighted_edge_type> edges;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (mat[i][j] != INF) {
                edge_type edge = {idx2v[i], idx2v[j]};
                weighted_edge_type w_edge = {edge, mat[i][j]};
                edges.push_back(w_edge);
            }
        }
    }
    return edges;
}

// std::ostream& operator<<(std::ostream& cout, weighted_edge_type w_edge) {
//     weight_type w = w_edge.second;
//     vertice_type v1 = w_edge.first.first, v2 = w_edge.first.second;
//     cout << "[" << v1 << " <--" << w << "--> " << v2 << "]";
//     return cout;
// }

weight_type get_weight(weighted_edge_type w_edge) { return w_edge.second; }

void minHeapSort(std::vector<weighted_edge_type> &w_edges) {
    std::vector<weight_type> weights;
    for (int i = 0; i < w_edges.size(); i++)
        weights.push_back(get_weight(w_edges[i]));
    minHeap<weighted_edge_type, int> h = {w_edges, weights};
    int i = 0;
    while (!h.empty()) {
        weighted_edge_type w_edge = h.get_min_key();
        h.delMin();
        w_edges[i++] = w_edge;
        // std::cout << "???\n";
        h.print_keys();
    }
}

void merge(std::vector<weighted_edge_type> &w_edges, int lo, int hi) {
    int mid = (hi + lo) / 2;
    std::vector<weighted_edge_type> left, right;
    left.assign(w_edges.begin() + lo, w_edges.begin() + mid);
    right.assign(w_edges.begin() + mid, w_edges.begin() + hi);
    int len_l = mid - lo, len_r = hi - mid;
    for (int i = lo, j = 0, k = 0; (j < len_l) || (k < len_r);) {  // j, k keep the position of left head and right head
        if ((j < len_l) && (!(k < len_r) || (get_weight(left[j]) <= get_weight(right[k]))))
            w_edges[i++] = left[j++];
        if ((k < len_r) && (!(j < len_l) || (get_weight(right[k]) < get_weight(left[j]))))
            w_edges[i++] = right[k++];
    }
    std::vector<weighted_edge_type>().swap(left);
    std::vector<weighted_edge_type>().swap(right);
}

void merge_then_sort(std::vector<weighted_edge_type> &w_edges, int lo, int hi) {  // sort [lo, hi)
    if ((hi - lo) < 2)
        return;
    int mid = (hi + lo) / 2;
    merge_then_sort(w_edges, lo, mid);
    merge_then_sort(w_edges, mid, hi);
    merge(w_edges, lo, hi);
    std::cout << "After merge:\n";
    for (auto elem : w_edges)
        std::cout << elem << " ";
    std::cout << "\n";
}

void MergeSort(std::vector<weighted_edge_type> &w_edges) { merge_then_sort(w_edges, 0, w_edges.size()); }

void EdgeSort(std::vector<weighted_edge_type> &w_edges) {
    std::vector<weight_type> weights;
    for (int i = 0; i < w_edges.size(); i++)
        weights.push_back(get_weight(w_edges[i]));
    minHeap<weighted_edge_type, int> h = {w_edges, weights};
    int i = 0;
    while (!h.empty()) {
        weighted_edge_type w_edge = h.get_min_key();
        h.delMin();
        w_edges[i++] = w_edge;
    }
}
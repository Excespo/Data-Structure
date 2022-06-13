#include "dijkstra.h"

preceding_vertice_map_type dijkstraAM(AM am, vertice_type src, vertice_type dst) {
    /*
     * dijkstra's return - map: preceding_edge_map_type
     * Algorithm:
     *  1 Push src to PriorQueue Q
     *  2 While Q not empty, and dst still in Q
     *  3  - Pop vertex v with minimum distance(kept in Q)
     *  4  - for non-visited adj a of v
     *  5    - if a not in Q, then push a into Q
     *  5(?) - rewrite a from INF to some distance
     *  6    - if a in Q, update distance
     *
     * Validity: All paths are positive
     */

    /* Data from AM */
    std::vector<vertice_type> vs = am.get_vertices();
    vertice_to_idx_map_type v2i = am.get_v2idx();
    idx_to_vertice_map_type i2v = am.get_idx2v();
    adj_matrix_type mat = am.get_adjMat();
    int size = am.get_v_size();

    /* Initiate */
    preceding_vertice_map_type pre_of;

    // int src_id = v2i[src], dst_id = v2i[src];
    // certain DS that keeps the visit order
    std::queue<vertice_type> Q;
    Q.push(src);
    // key - vertice, val - distance: from src to key
    minHeap<vertice_type, int> distance;
    distance.push_back(src, 0);
    for (auto v : vs)
        distance.push_back(v, INF);
    distance.set_val_with(src, 0);
    std::set<vertice_type> decided;  // decided.insert(src);
    weight_type min_dist;

    /* Iterate */
    int num = 1;
    // while (!Q.empty() && num <= 4) {
    while (!Q.empty()) {
        vertice_type v = Q.front();
        Q.pop();
        // if ((v != src ) && (decided.find(v) != decided.end())) continue; // v
        // is decided
        if (decided.find(v) != decided.end())
            continue;
        weight_type d = distance.get_val_at(v);  // from v the basic distance is d
        int iv = v2i[v];                         // index of v
        std::cout << "Updating around: " << v << "\n";
        /* update adjacent distance */
        for (int i = 0; i < size; i++) {
            weight_type w = mat[i][iv];
            vertice_type vi = i2v[i];  // vertex with id=i
            if (decided.find(vi) != decided.end())
                continue;                                   // avoid duplicated vertices
            if (w != INF) {                                 // adjacent
                Q.push(vi);                                 // add to waitlist to visit
                weight_type dvi = distance.get_val_at(vi);  // original weight at vi
                if ((dvi == INF) || (dvi > (d + w))) {      // INF + w may be negative
                    distance.set_val_with(vi, d + w);
                    pre_of[vi] = v;  // update preceding with shorter prefix
                }
            }
        }
        std::cout << "turn: " << num++ << "\n";
        distance.print_all();
        /* pop shortest */
        vertice_type sv = distance.get_min_key();
        weight_type sd = distance.get_min_val();
        distance.delMin();
        std::cout << "Poping: " << sv << " : " << sd << "\n";
        if (sv == dst) {
            min_dist = sd;
            break;
        }  // arrived dst
        /* add sv to decided */
        decided.insert(sv);
    }

    /* output the shortest path and the weight */
    using std::cout;
    cout << "Minimum distance from src: " << src << ", dst: " << dst << " >> " << min_dist << "\n";
    vertice_type curr = dst;

    for (auto iter = pre_of.begin(); iter != pre_of.end(); iter++) {
        cout << iter->first << " : " << iter->second << "\n";
    }
    while (curr != src) {
        cout << curr << " <- ";
        curr = pre_of[curr];
    }
    cout << src << "\n";

    return pre_of;
}
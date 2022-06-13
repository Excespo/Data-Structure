#include "MST.h"

std::vector<vertice_type> all_vertices(std::vector<weighted_edge_type> w) {
    std::vector<vertice_type> vertices;
    for (int i = 0; i < w.size(); i++) {
        vertice_type v1 = w[i].first.first, v2 = w[i].first.second;
        if ((std::find(vertices.begin(), vertices.end(), v1) == vertices.end()))
            vertices.push_back(v1);
        if ((std::find(vertices.begin(), vertices.end(), v2) == vertices.end()))
            vertices.push_back(v2);
    }  // get all vertices
    return vertices;
}

std::vector<vertice_type> adjacent_vertices(std::vector<weighted_edge_type> w, vertice_type v) {
    std::vector<vertice_type> adj;
    for (int i = 0; i < w.size(); i++) {
        vertice_type v1 = w[i].first.first, v2 = w[i].first.second;
        if (v1 == v) {
            adj.push_back(v2);
            continue;
        }
        if (v2 == v) {
            adj.push_back(v1);
            continue;
        }
    }
    return adj;
}

std::vector<weighted_edge_type> adjacent_weighted_edges(std::vector<weighted_edge_type> w, vertice_type v) {
    std::vector<weighted_edge_type> wes;
    std::vector<vertice_type> allv = all_vertices(w);
    AM am = {allv, w};
    int idx = am.get_v2idx()[v];
    adj_matrix_type mat = am.get_adjMat();
    for (int j = 0; j < allv.size(); j++) {
        weight_type weight = mat[idx][j];
        if (weight == INF || weight == 0)
            continue;  // not adjacent or is self
        edge_type _e = {v, am.get_idx2v()[j]};
        weighted_edge_type _we = {_e, weight};
        wes.push_back(_we);
    }
    return wes;
}

std::vector<connected_graph_type> connected_components(std::vector<weighted_edge_type> w_edges) {
    /*
     * components - vertices of connected components,
     * connected_graph_type is edges of a component
     *
     * How to construct a connected component?
     *  1 choose an arbitrary vertex
     *  2 expand it with a stack structure
     *  3 remove all edges related, and remove the visited vertex
     *  4 until all possible vertices is visited
     *  5 if vertices isn't empty repeat 1-4 and construct a new component
     *  6 combine all components and return
     *
     * Notice some Stop Iteration Condition:
     *  1 no usable adj vertices, step over
     *  2 no usable vertices, step out
     *  3 task stack call for deleted vertex? maybe not
     */
    std::vector<connected_graph_type> components;
    std::vector<vertice_type> vertices = all_vertices(w_edges);
    std::stack<vertice_type> to_visit;

    while (!vertices.empty()) {
        components.push_back(connected_graph_type());  // new component
        vertice_type v = vertices.back();
        to_visit.push(v);  // get one vertex

        while (!to_visit.empty()) {
            vertice_type v = to_visit.top();
            to_visit.pop();
            if (vertices.empty())
                break;
            // if (std::find(vertices.begin(), vertices.end(), v) ==
            // vertices.end()) continue;
            std::vector<vertice_type>::iterator iter = vertices.begin();
            while (*iter != v)
                iter++;
            vertices.erase(iter);  // v is visited

            std::vector<vertice_type> adjv = adjacent_vertices(w_edges, v);
            if (adjv.empty())
                continue;  // no adj, step
            std::vector<weighted_edge_type> adjwes = adjacent_weighted_edges(w_edges, v);

            for (int i = 0; i < adjwes.size(); i++) {
                components.back().push_back(adjwes[i]);  // add edge to current component
                std::vector<weighted_edge_type>::iterator weit = w_edges.begin();
                while (neq(*weit, adjwes[i]))
                    weit++;
                w_edges.erase(weit);  // set edge visited
            }

            for (int i = 0; i < adjv.size(); i++) {
                to_visit.push(adjv[i]);
            }
        }
    }
    // if (components.back().empty()) components.pop_back();
    return components;
}

bool is_connected(std::vector<weighted_edge_type> w_edges) { return connected_components(w_edges).size() == 1; }

int count_vertices(std::vector<weighted_edge_type> w_edges) { return all_vertices(w_edges).size(); }

bool is_cyclic(std::vector<weighted_edge_type> w_edges) {
    std::vector<connected_graph_type> cc = connected_components(w_edges);
    for (int i = 0; i < cc.size(); i++) {
        connected_graph_type c = cc[i];
        int num_edges = c.size(), num_vertices = count_vertices(c);

        // std::cout << "Component " << i << ": num_e: " << num_edges << ":
        // num_v: " << num_vertices << " >> "; for (int i = 0; i < c.size();
        // i++)
        //     std::cout << c[i] << " ";
        // std::cout << "\n";

        if (num_vertices <= num_edges) {
            // std::cout << "cyclic!\n";
            return true;
        }
    }
    return false;
}

std::vector<weighted_edge_type> GenMST(std::vector<weighted_edge_type> w_edges) {
    if (!is_connected(w_edges)) {
        std::cout << "Input graph is not connected\n";
        exit(0);
    }
    int spanning_tree_size = all_vertices(w_edges).size() - 1;  // Stop Interation Conditon
    std::vector<weighted_edge_type> mst;
    // Use Krustal's Algorithm
    EdgeSort(w_edges);
    // for (int i = 0; i < w_edges.size(); i++)
    //     std::cout << w_edges[i] << "\n";
    for (int i = 0; i < w_edges.size(); i++) {
        // std::cout << "Push: " << w_edges[i] << "\n";
        mst.push_back(w_edges[i]);
        if (is_cyclic(mst)) {
            // std::cout << "Pop: " << mst.back() << "\n";
            mst.pop_back();  // avoid cycle
        }
        if (mst.size() == spanning_tree_size)
            break;  // visit all vertices
    }

    return mst;
}

weight_type sum_weight(std::vector<weighted_edge_type> w_edges) {
    weight_type sum = 0;
    for (int i = 0; i < w_edges.size(); i++)
        sum = sum + w_edges[i].second;
    return sum;
}
#include "adjacency.h"

AdjacencyMatrix::AdjacencyMatrix(std::vector<vertice_type> vs, std::vector<weighted_edge_type> wes) {
    // Construct vertice<->idx map with `vs`
    _v_size = vs.size();
    _e_size = wes.size();
    _vertices.assign(vs.begin(), vs.end());
    for (int i = 0; i < _v_size; i++) {
        _v2idx[vs[i]] = i;
        _idx2v[i] = vs[i];
    }

    // Construct and initiate adj matrix
    for (int i = 0; i < _v_size; i++) {
        adj_matrix_row_type row(_v_size, INF);
        row[i] = 0;  // diagonal to 0
        _adjMat.push_back(row);
    }

    // Fill adj matrix with `wes`
    for (int i = 0; i < _e_size; i++) {
        weight_type weight = wes[i].second;
        vertice_type v1 = wes[i].first.first, v2 = wes[i].first.second;
        int idx1 = _v2idx[v1], idx2 = _v2idx[v2];
        if (_adjMat[idx1][idx2] != INF) {
            std::cout << "Multiple weights on one edge. Wrong.\n";
            exit(0);
        }
        _adjMat[idx1][idx2] = _adjMat[idx2][idx1] = weight;
    }
}

// AdjacencyMatrix::AdjacencyMatrix(weight_type **adj_mat, int size)
// {
//     _v_size = size;
//     for (int i = 0; i < _v_size; i++) {
//         adj_matrix_row_type row(_v_size);
//         for (int j = 0; j < _v_size; j++)
//             row[j] = adj_mat[i][j];
//         _adjMat.push_back(row);
//     }
// } // TODO Haven't implement add map and vertice to protected data

void AdjacencyMatrix::print() {
    using std::cout;
    using std::setw;
    // int DEFAULT_BLOCK_WIDTH = 4;
    cout << "Print Adjacency Matrix:\n";
    // first row
    cout << setw(4) << "";
    for (int i = 0; i < _v_size; i++)
        cout << " " << setw(4) << _vertices[i];
    cout << "\n";
    // row 1 to _v_size
    for (int i = 0; i < _v_size; i++) {
        cout << setw(4) << _vertices[i];
        for (int j = 0; j < _v_size; j++) {
            if (_adjMat[i][j] == INF)
                cout << " " << setw(4) << "N";
            else
                cout << " " << setw(4) << _adjMat[i][j];
        }
        cout << "\n";
    }
}

void printAM(AM am) { am.print(); }

AdjacencyList::AdjacencyList(std::vector<vertice_type> vs, std::vector<weighted_edge_type> wes) {
    // Construct vertice<->idx map with `vs`, and construct primary nodes of adj
    // list
    _v_size = vs.size();
    _e_size = wes.size();
    _vertices.assign(vs.begin(), vs.end());
    for (int i = 0; i < _v_size; i++) {
        _v2idx[vs[i]] = i;
        _idx2v[i] = vs[i];
        std::vector<vertice_type> sub_adj_list;
        adj_list_node_type node = {vs[i], sub_adj_list};
        _adjList.push_back(node);
    }

    for (int i = 0; i < _e_size; i++) {
        // weight_type weight = wes[i].second;
        vertice_type v1 = wes[i].first.first, v2 = wes[i].first.second;
        _adjList[_v2idx[v2]].second.push_back(v1);
        _adjList[_v2idx[v1]].second.push_back(v2);
    }
}

AdjacencyList::AdjacencyList(AdjacencyMatrix am) {
    ;  // TODO
}

void AdjacencyList::print() {
    using std::cout;
    // using std::setw;
    cout << "Print Adjacency List:\n";
    for (int i = 0; i < _v_size; i++) {
        adj_list_node_type curr = _adjList[i];
        // std::cout << "curr.second size: " << curr.second.size() << "\n";
        cout << curr.first << " -> ";
        for (int j = 0; j < curr.second.size(); j++) {
            cout << curr.second[j] << " -> ";
        }
        cout << "N\n";
    }
}

void printAL(AL al) { al.print(); }

AM genAM() {
    // test ctor method 1
    vertice_type v0 = "WL";
    vertice_type v1 = "LZ";
    vertice_type v2 = "LS";
    vertice_type v3 = "XA";
    vertice_type v4 = "CD";
    vertice_type v5 = "KM";
    vertice_type v6 = "BJ";
    vertice_type v7 = "WH";
    vertice_type v8 = "GZ";
    vertice_type v9 = "SY";
    vertice_type v10 = "TJ";
    vertice_type v11 = "SH";
    vertice_type v12 = "FZ";

    edge_type e0 = {v0, v1};
    weighted_edge_type we0 = {e0, 130};
    edge_type e1 = {v0, v2};
    weighted_edge_type we1 = {e1, 120};
    edge_type e1p5 = {v1, v2};  // Forget to add in the first time ahh
    weighted_edge_type we1p5 = {e1p5, 111};
    edge_type e2 = {v1, v3};
    weighted_edge_type we2 = {e2, 84};
    edge_type e3 = {v1, v4};
    weighted_edge_type we3 = {e3, 85};
    edge_type e4 = {v2, v4};
    weighted_edge_type we4 = {e4, 110};
    edge_type e5 = {v3, v4};
    weighted_edge_type we5 = {e5, 87};
    edge_type e6 = {v4, v5};
    weighted_edge_type we6 = {e6, 86};
    edge_type e7 = {v3, v6};
    weighted_edge_type we7 = {e7, 90};
    edge_type e8 = {v3, v7};
    weighted_edge_type we8 = {e8, 94};
    edge_type e9 = {v4, v7};
    weighted_edge_type we9 = {e9, 99};
    edge_type e10 = {v4, v8};
    weighted_edge_type we10 = {e10, 102};
    edge_type e11 = {v5, v8};
    weighted_edge_type we11 = {e11, 101};
    edge_type e12 = {v6, v7};
    weighted_edge_type we12 = {e12, 100};
    edge_type e13 = {v7, v8};
    weighted_edge_type we13 = {e13, 98};
    edge_type e14 = {v6, v9};
    weighted_edge_type we14 = {e14, 88};
    edge_type e15 = {v6, v10};
    weighted_edge_type we15 = {e15, 9};
    edge_type e16 = {v7, v10};
    weighted_edge_type we16 = {e16, 97};
    edge_type e17 = {v7, v11};
    weighted_edge_type we17 = {e17, 96};
    edge_type e18 = {v7, v12};
    weighted_edge_type we18 = {e18, 95};
    edge_type e19 = {v8, v12};
    weighted_edge_type we19 = {e19, 91};
    edge_type e20 = {v9, v10};
    weighted_edge_type we20 = {e20, 89};
    edge_type e21 = {v10, v11};
    weighted_edge_type we21 = {e21, 93};
    edge_type e22 = {v11, v12};
    weighted_edge_type we22 = {e22, 92};

    // In all 13 vertices, 24 edges
    std::vector<vertice_type> vertices = {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12};
    std::vector<weighted_edge_type> edges = {we0,  we1,  we1p5, we2,  we3,  we4,  we5,  we6,  we7,  we8,  we9,  we10,
                                             we11, we12, we13,  we14, we15, we16, we17, we18, we19, we20, we21, we22};

    AM am = {vertices, edges};
    return am;
}
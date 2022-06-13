#include "MST.h"

int main() {
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
    // std::vector<vertice_type> vertices = {v0, v1, v2, v3, v4, v5, v6, v7, v8,
    // v9, v10, v11, v12};
    std::vector<weighted_edge_type> edges = {we0,  we1,  we1p5, we2,  we3,  we4,  we5,  we6,  we7,  we8,  we9,  we10,
                                             we11, we12, we13,  we14, we15, we16, we17, we18, we19, we20, we21, we22};

    std::vector<weighted_edge_type> e_advers;
    e_advers.assign(edges.begin(), edges.end());
    edge_type e100 = {"XN", "SC"};
    weighted_edge_type we100 = {e100, -5};
    e_advers.push_back(we100);
    edge_type e101 = {"XN", "GG"};
    weighted_edge_type we101 = {e101, -5};
    e_advers.push_back(we101);
    edge_type e102 = {"GG", "SC"};
    weighted_edge_type we102 = {e102, -5};
    e_advers.push_back(we102);

    using std::cout;

    cout << "================ Test for eq, neq ================\n";
    cout << "neq(we1, we10): " << neq(we1, we10) << "\n";
    cout << "eq(we4, we4): " << eq(we4, we4) << "\n";

    cout << "================ Test for all_vertices ================\n";
    std::vector<vertice_type> allv = all_vertices(edges);
    cout << "In All We Have " << allv.size() << " vertices\n";
    for (int i = 0; i < allv.size(); i++)
        cout << allv[i] << " ";
    cout << "\n";

    cout << "================ Test for adjacent_vertices ================\n";
    std::vector<vertice_type> adj = adjacent_vertices(edges, v7);
    cout << "v7: WH Has " << adj.size() << " vertices adjacent\n";
    for (int i = 0; i < adj.size(); i++)
        cout << adj[i] << " ";
    cout << "\n";

    edge_type et = {"t1", "t2"};
    std::vector<weighted_edge_type> wet = {weighted_edge_type({et, 99})};
    std::vector<vertice_type> adjt = adjacent_vertices(wet, "t3");
    cout << "t3 Has " << adjt.size() << " vertices adjacent\n";
    for (int i = 0; i < adjt.size(); i++)
        cout << adjt[i] << " ";
    cout << "\n";

    cout << "================ Test for adjacent_weighted_edges "
            "================\n";
    std::vector<weighted_edge_type> adjwe = adjacent_weighted_edges(edges, v3);
    cout << "v3: XA Has " << adjwe.size() << " edges adjacent\n";
    for (int i = 0; i < adjwe.size(); i++)
        cout << adjwe[i] << " ";
    cout << "\n";

    cout << "================ Test for connected_components ================\n";
    std::vector<connected_graph_type> cc = connected_components(edges);
    cout << "For edge, In All " << cc.size() << " Component(s)\n";
    connected_graph_type c2 = cc[0];
    for (int i = 0; i < c2.size(); i++)
        cout << c2[i] << " ";
    cout << "\n";
    cc = connected_components(e_advers);
    cout << "For e_advers, In All " << cc.size() << " Component(s)\n";
    connected_graph_type c0 = cc[0];
    for (int i = 0; i < c0.size(); i++)
        cout << c0[i] << " ";
    cout << "\n";
    connected_graph_type c1 = cc[1];
    for (int i = 0; i < c1.size(); i++)
        cout << c1[i] << " ";
    cout << "\n";

    cout << "================ Test for is_connected ================\n";
    cout << "is_connected?: " << is_connected(edges);
    cout << "\n";

    cout << "================ Test for count_vertices ================\n";
    cout << "count_vetices: " << count_vertices(edges);
    cout << "\n";

    cout << "================ Test for GenMST ================\n";
    cout << "MST including edges:\n";
    std::vector<weighted_edge_type> mst = GenMST(edges);
    for (int i = 0; i < mst.size(); i++)
        cout << mst[i] << " ";
    cout << "\n";

    cout << "================ Test for GenMST ================\n";
    cout << "MST weights:\n";
    weight_type w = sum_weight(mst);
    cout << w << "\n";

    return 0;
}
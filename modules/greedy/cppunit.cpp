#include <greedy.h>
#include <iostream>

using namespace compendium;

int main()
{

    // TODO fix to get inputs from /bin
    // NoInputException
    // if(argc < 2)
    // {
    //     return 0;
    // }

    int V, E;
    int v, w; double weight;
    std::cin >> V >> E;
    EdgeWeightedGraph graph(V);

    while(E--)
    {
        std::cin >> v >> w >> weight;
        graph.add_edge(new Edge(v, w, weight));
    }

    KruskalMST kruskal_mst(graph);
    kruskal_mst.get_result();

    PrimMST prim_mst(graph);
    prim_mst.get_result();

    return 0;

}

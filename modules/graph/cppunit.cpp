#include <graph.h>
#include <iostream>

using namespace compendium;

int main()
{

    int V(13), E(13);

    Graph g(V);

    g.add_edge(0, 5);
    g.add_edge(4, 3);
    g.add_edge(0, 1);
    g.add_edge(9, 12);
    g.add_edge(6, 4);
    g.add_edge(5, 4);
    g.add_edge(0, 2);
    g.add_edge(11, 12);
    g.add_edge(9, 10);
    g.add_edge(0, 6);
    g.add_edge(7, 8);
    g.add_edge(9, 11);
    g.add_edge(5, 3);

    std::cout << g.to_string() << std::endl;
    std::cout << "Number of vertices: " << g.V() << std::endl;
    std::cout << "Number of edges: " << g.E() << std::endl;
    std::cout << "Degree of vertex 5: " << Graph::degree(g, 5) << std::endl;
    std::cout << "Max degree: " << Graph::max_degree(g) << std::endl;
    std::cout << "Average degree: " << Graph::average_degree(g) << std::endl;
    std::cout << "Number of self loops: " << Graph::number_of_self_loops(g) << std::endl;

    return 0;

}

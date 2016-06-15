#include <graph.h>
#include <iostream>

// using namespace compendium;

int main()
{

    int V, E, v, w;

    std::cin >> V >> E;

    Graph g(V);

    while(E--)
    {
        std::cin >> v >> w;
        g.add_edge(v, w);
    }

    std::cout << g.to_string() << std::endl;
    std::cout << "Number of vertices: " << g.V() << std::endl;
    std::cout << "Number of edges: " << g.E() << std::endl;
    std::cout << "Degree of vertex 5: " << Graph::degree(g, 5) << std::endl;
    std::cout << "Max degree: " << Graph::max_degree(g) << std::endl;
    std::cout << "Average degree: " << Graph::average_degree(g) << std::endl;
    std::cout << "Number of self loops: " << Graph::number_of_self_loops(g) << std::endl;

    return 0;

}

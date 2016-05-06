#include <graph.h>

namespace compendium
{
    Graph::~Graph(){}

    void Graph::add_edge(int v, int w)
    {
        ++e;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    std::string Graph::to_string()
    {

        std::stringstream ss;

        for(unsigned int v = 0; v < adj.size(); ++v)
        {
            ss << v << ":";

            for_each(adj[v].begin(), adj[v].end(),
                [&](int w)
                {
                    ss << ' ' << w;
                }
            );

            ss << std::endl;
        }

        return ss.str();

    }

    double Graph::average_degree(Graph &g)
    {
        return 2.0 * g.E() / g.V();
    }

    int Graph::max_degree(Graph &g)
    {

        int max(0);

        for(int v = 0; v < g.V(); ++v)
            if(degree(g, v) > max)
                max = Graph::degree(g, v);

        return max;

    }

    int Graph::number_of_self_loops(Graph &g)
    {
        int count(0);

        for(int v = 0; v < g.V(); ++v)
           for_each(g.adj[v].begin(), g.adj[v].end(),
                [&](int w)
                {
                    if(v == w) ++count;
                }
            );

        return count;

    }

}//end of namespace

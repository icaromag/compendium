#include <graph.h>

namespace compendium
{
    Graph::~Graph()
    {
        delete adj;
    };

    void Graph::add_edge(const int v, const int w)
    {
        ++e;
        ((*adj)[v]).push_back(w);
        ((*adj)[w]).push_back(v);
    }

    std::string Graph::to_string()
    {

        std::stringstream ss;

        for(unsigned int v = 0; v < adj->size(); ++v)
        {
            ss << v << ":";

            for_each((*adj)[v].begin(), (*adj)[v].end(),
                [&](int w)
                {
                    ss << ' ' << w;
                }
            );

            ss << std::endl;
        }

        return ss.str();

    }

    double Graph::average_degree(const Graph &_g)
    {
        return 2.0 * _g.E() / _g.V();
    }

    int Graph::max_degree(const Graph &_g)
    {

        int max(0);

        for(int v = 0, gv = _g.V(); v < gv; ++v)
            if(degree(_g, v) > max)
                max = Graph::degree(_g, v);

        return max;

    }

    int Graph::number_of_self_loops(Graph &_g)
    {
        int count(0);

        for(int v = 0, gv = _g.V(); v < gv; ++v)
           for_each((*(_g.adj))[v].begin(), (*(_g.adj))[v].end(),
                [&count, &v](int w)
                {
                    if(v == w) ++count;
                }
            );

        return count;

    }

}//end of namespace

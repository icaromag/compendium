#include <graph.h>

namespace compendium {

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

    DisjointSets::DisjointSets(int n)
    {
        p.assign(n, 0);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    DisjointSets::~DisjointSets() { }

    int DisjointSets::findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }

    bool DisjointSets::isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void DisjointSets::unionSet(int i, int j)
    {
        int is = findSet(i);
        int js = findSet(j);

        if (is != js)
        {
            if (rank[is] > rank[js])
                p[js] = is;
            else {
                p[is] = js;

                if (rank[is] == rank[js])
                    rank[js]++;
            }
        }
    }

    int kruskal(DisjointSets& ds, const std::vector<std::pair<int, IntPair>>& edgeList)
    {
        int cost = 0;

        for (uint i = 0; i < edgeList.size(); i++)
        {
            std::pair<int, IntPair> front = edgeList[i];

            if ( ! ds.isSameSet(front.second.first, front.second.second))
            {
                cost += front.first;
                ds.unionSet(front.second.first, front.second.second);
            }
        }

        return cost;
    }

    void prim_process(int vertex, std::vector<bool>& marked, std::priority_queue<IntPair> edges, std::vector<std::vector<IntPair>> adjList)
    {
        marked[vertex] = true;

        for (std::size_t i = 0; i < adjList[vertex].size(); i++)
        {
            IntPair u = adjList[vertex][i];

            if ( ! marked[u.first])
                // Adds negative value for weight to get smallers first
                edges.push(std::make_pair(-u.second, u.first));
        }
    }

    int prim(std::size_t size, std::vector<std::vector<IntPair>> adjList)
    {
        // global boolean flag to avoid cycle
        std::vector<bool> marked;
        marked.assign(size, false);

        // priority queue to help choose shorter edges
        std::priority_queue<IntPair> edges;

        // take vertex 0 and process all edges incident to vertex 0
        prim_process(0, marked, edges, adjList);
        int cost = 0;

        while ( ! edges.empty())
        {
            IntPair front = edges.top(); edges.pop();

            // The weight was inserted as negative value
            int weight = -front.first;
            int vertex = front.second;

            if ( ! marked[vertex])
            {
                cost += weight;
                prim_process(vertex, marked, edges, adjList);
            }
        }

        return cost;
    }

} // end of namespace

#include <vector>
#include <set>
#include <queue>
#include <iterator>
#include <iostream>
#include <deque>

class Edge
{

public:
    Edge(int v, int w, double weight) :
        v_(v), w_(w), weight_(weight) {}

    inline int either() const
    {
        return v_;
    }

    inline int other(const int vertex) const
    {
        return (vertex == v_) ? w_ : v_;
    }

    int compare_to(const Edge &that) const
    {
        if (this->weight_ < that.weight_)
        {
            return -1;
        }
        else if (this->weight_ > that.weight_)
        {
            return +1;
        }
        else
        {
            return 0;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Edge &obj)
    {
        os << "|" << obj.v_
           << "|" << obj.w_
           << "|" << obj.weight_;
        return os;
    }

    friend bool operator > (const Edge& l, const Edge& r)
    {
        return l.weight_ > r.weight_;
    }

// private:
    int v_, w_;
    double weight_;

};

class EdgeWeightedGraph
{
public:
    EdgeWeightedGraph(int V) {
        V_ = V;
        adj_ = new std::deque<Edge*>[V];
    }

    void add_edge(Edge *edge)
    {
        const int v = edge->either();
        const int w = edge->other(v);
        adj_[v].push_front(edge);
        adj_[w].push_front(edge);
    }

    void print_graph()
    {
        for (int i = 0; i < V_; ++i)
        {
            std::cout << i << ":  ";
            for (int j = 0; j < adj_[i].size(); ++j)
            {
                std::cout << *adj_[i][j] << '\t';
            }
            std::cout << std::endl;
        }
    }

// private:
    int V_;
    std::deque<Edge*> *adj_;

};

class KruskalMST
{

public:

    template<typename T> void print_queue(T& q) {
        while(!q.empty()) {
            std::cout << q.top() << '\n';
            q.pop();
        }
        std::cout << '\n';
    }

    KruskalMST(const EdgeWeightedGraph graph)
    {
        for (int i = 0; i < graph.V_; ++i)
        {
            for (int j = 0; j < graph.adj_[i].size(); ++j)
            {
                min_heap.push(*graph.adj_[i][j]);
            }
        }

        print_queue(min_heap);
    }

private:
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge> > min_heap;
    std::queue<Edge *> mst;
};

int main(int argc, char const *argv[])
{

    int V, E;
    int v, w; double weight;
    std::cin >> V >> E;
    EdgeWeightedGraph graph(V);

    while(E--)
    {
        std::cin >> v >> w >> weight;
        graph.add_edge(new Edge(v, w, weight));
    }

    KruskalMST kruskals_mst(graph);

    // graph.print_graph();

    return 0;

}

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

    int V() const { return V_; }

// private:
    int V_;
    std::deque<Edge*> *adj_;

};

class UnionFind
{
public:

    UnionFind(int N)
    {
        parent_ = new int[N];
        rank_ = new short[N];

        for (int i = 0; i < N; ++i)
        {
            parent_[i] = i;
            rank_[i] = 0;
        }
    }

    int find(int p)
    {
        while (p != parent_[p])
        {
            // path compression by halving
            // read Robert Sedgewick's book, noob
            parent_[p] = parent_[parent_[p]];
            p = parent_[p];
        }
        return p;
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    void unite(int p, int q)
    {
        int root_p = find(p);
        int root_q = find(q);

        if (root_p == root_q)
        {
            return;
        }

        // make root of smaller rank point to root of larger rank
        if (rank_[root_p] < rank_[root_q])
        {
            parent_[root_p] = root_q;
        }
        else if (rank_[root_p] > rank_[root_q])
        {
            parent_[root_q] = root_p;
        }
        else
        {
            parent_[root_q] = root_p;
            rank_[root_p]++;
        }

        count_--;
    }

    int count() const { return count_; }

private:
    int *parent_;
    short *rank_;
    int count_;

};

class KruskalMST
{

public:

    // Add to util class
    template<typename T> void printer(T q) {
        while(!q.empty())
        {
            std::cout << q.front() << '\n';
            // std::cout << q.top() << '\n';
            q.pop();
        }
        std::cout << '\n';
    }

    KruskalMST(const EdgeWeightedGraph graph)
    {
        for (int i = 0; i < graph.V_; ++i)
            for (int j = 0; j < graph.adj_[i].size(); ++j)
                min_heap_.push(*graph.adj_[i][j]);

        // printer(min_heap_);
        int v, w;
        UnionFind uf(graph.V());
        while (!min_heap_.empty()) //&& mst_.size() < graph.V() - 1)
        {
            Edge e = min_heap_.top();
            min_heap_.pop();
            min_heap_.pop();

            v = e.either();
            w = e.other(v);


            if(!uf.connected(v, w))
            {
                uf.unite(v, w);
                mst_.push(e);
            }

        }

    }

    void print_mst()
    {
        printer(mst_);
    }

private:
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge> > min_heap_;
    std::queue<Edge> mst_;
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

    KruskalMST kruskal_mst(graph);
    kruskal_mst.print_mst();


    return 0;

}
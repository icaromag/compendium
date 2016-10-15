/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Marcello Marques
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file greedy.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \author Marcello Marques
 *
 ***************************************************************************/

#ifndef GREEDY_H
#define GREEDY_H

#include <algorithm>
#include <climits>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace compendium
{

    /**
     * \brief TODO brief content
     * Prim and Kruskal at end of file
     */
    class GREEDY
    {
        static std::vector< std::pair<int, int> > activity_selection(
            std::vector< std::pair<int, int> > &act);

        static double fractional_knapsack(
            int W, std::vector< std::pair<int, int> > items);
    };

    // TODO move to Graph module
    class Edge
    {

    public:
        Edge(const int v, const int w, const double weight) :
            v_(v), w_(w), weight_(weight) {}

        inline int either() const
        {
            return v_;
        }

        inline int other(const unsigned int vertex) const
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

        friend std::ostream& operator<<(std::ostream& os, const Edge &e)
        {
            os << "|" << e.v_
               << "|" << e.w_
               << "|" << e.weight_;
            return os;
        }

        friend bool operator > (const Edge& l, const Edge& r)
        {
            return l.weight_ > r.weight_;
        }

    // private:
        unsigned int v_;
        unsigned int w_;
        double weight_;

    };

    // TODO move to graph module
    class EdgeWeightedGraph
    {
    public:
        EdgeWeightedGraph(const int V) :
            V_(V), adj_(new std::deque<Edge *>[V]) { }

        void add_edge(Edge *const edge)
        {
            const int v = edge->either();
            const int w = edge->other(v);
            adj_[v].push_front(edge);
            adj_[w].push_front(edge);
        }

        void print_graph()
        {
            for (unsigned int i = 0; i < V_; ++i)
            {
                std::cout << i << ":  ";
                for (unsigned int j = 0; j < adj_[i].size(); ++j)
                {
                    std::cout << *adj_[i][j] << '\t';
                }
                std::cout << std::endl;
            }
        }

        unsigned int V() const { return V_; }

    // private:
        unsigned int V_;
        std::deque<Edge*> *adj_;

    };

    // TODO create DataStructures module to comport UnionFind
    // Here it's used for cycle finding
    class UnionFind
    {
    public:

        UnionFind(int N)
        {
            parent_ = new int[N];
            rank_ = new unsigned short[N];

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

        bool connected(const int p, const int q)
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
        unsigned short *rank_;
        int count_;

    };

    class KruskalMST
    {

    public:

        // Add to util class
        template<typename T> void printer(T q) //copy
        {
            double path_cost(0);

            while(!q.empty())
            {
                std::cout << q.front() << '\n';
                path_cost += q.front().weight_;
                q.pop();
            }
            std::cout << "\nKruskalMST path cost cost is: " << path_cost << std::endl;
        }

        KruskalMST(const EdgeWeightedGraph graph)
        {
            for (unsigned int i = 0; i < graph.V_; ++i)
                for (unsigned int j = 0; j < graph.adj_[i].size(); ++j)
                    min_heap_.push(*graph.adj_[i][j]);

            int v, w;
            UnionFind uf(graph.V());
            while (!min_heap_.empty() && mst_.size() < graph.V() - 1)
            {
                Edge e = min_heap_.top();

                // double pop adj[v]=w and adj[w]=v
                min_heap_.pop(); min_heap_.pop();

                v = e.either(), w = e.other(v);


                if(!uf.connected(v, w))
                {
                    uf.unite(v, w);
                    mst_.push(e);
                }

            }

        }

        void get_result()
        {
            printer(mst_);
        }

    private:
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge> > min_heap_;
        std::queue<Edge> mst_;
    };

    class PrimMST
    {

    public:

        PrimMST(const EdgeWeightedGraph graph) // Lazy
        {
            marked = new bool[graph.V()];
            std::memset(marked, false, sizeof(*marked));

            visit(graph, 0); // assume graph is connected

            int v, w;
            while (!min_heap_.empty())
            {

                Edge e = min_heap_.top();
                min_heap_.pop();

                v = e.either(), w = e.other(v);

                if(marked[v] && marked[w])
                {
                    continue;
                }

                mst_.push(e);

                if(!marked[v])
                {
                    visit(graph, v);
                }

                if(!marked[w])
                {
                    visit(graph, w);
                }

            }

        }

        void get_result()
        {
            get_result(mst_);
        }

        template<typename T> void get_result(T q)
        {
            double path_cost(0);

            while(!q.empty())
            {
                std::cout << q.front() << '\n';
                path_cost += q.front().weight_;
                q.pop();
            }
            std::cout << "\nPrimMST path cost cost is: " << path_cost << std::endl;
        }

    private:

        void visit(const EdgeWeightedGraph &graph, const int v)
        {
            marked[v] = true;
            for (unsigned int j = 0; j < graph.adj_[v].size(); ++j)
            {
                Edge e = *graph.adj_[v][j];
                if(!marked[e.other(v)])
                {
                    min_heap_.push(e);
                }
            }

        }

        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge> > min_heap_;
        std::queue<Edge> mst_;
        bool *marked;
    };

}

#endif // GREEDY_H

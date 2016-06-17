/***************************************************************************
 *
 *   The Graph class represents an undirected graph of vertices
 *   named 0 through V - 1.
 *   Supports add an edge, iterate over the vertices adjacent to a vertex.
 *   Provides methods for returning the number of vertices and the number
 *   of edges.
 *   This implementation uses an adjacency-list representation, represented
 *   as a vector of vectors.
 *
 *  The DisjointSet class //TODO
 *
 *   Copyright (C) 2016 by Ícaro Magalhães and Mateus Pires
 *
 *   \file graph.h
 *   \author Ícaro Magalhães <icaro.lmag@gmail.com>
 *   \author Mateus Pires <mateusplpl@gmail.com>
 *   \date 05/05/2016
 *
 ***************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>

namespace compendium
{

    typedef std::pair<int, int> IntPair;

    /**
     * \brief The class represents an undirected graph of vertices.
     */
    class Graph
    {

    public:
        /**
         * \brief Create a graph with V vertices
         */
        Graph(const int _V) : v(_V), adj(
            new std::vector< std::vector<int> >(_V)
        ) { }

        /**
         * \brief Default destructor
         */
        ~Graph();

        /**
         * \brief Return number of vertices
         */
        int V() const { return v; }

        /**
         * \brief Return number of edges
         */
        int E() const { return e; }

        /**
         * \brief Add an edge v-w
         */
        void add_edge(const int v, const int w);

        /**
         * \brief Return graph string representation
         */
        std::string to_string();

        /**
         * \brief Compute the degree of Graph g v's vertex
         */
        static int degree(const Graph &_g, const int _v)
        {
            return (*(_g.adj))[_v].size();
        }

        static double average_degree(const Graph &_g);
        static int max_degree(const Graph &_g);
        static int number_of_self_loops(Graph &_g);

    private:
        int v;
        int e;
        std::vector< std::vector<int> > *adj;

    };


    /**
     * \brief Data structure that keeps track of a set of elements partitioned into a number of disjoint (nonoverlapping) subsets
     */
    class DisjointSets {

    public:

        /**
         * \brief Creates a struct for n elements
         * \param n - number of elements
         */
        DisjointSets(int n);

        ~DisjointSets();

        /**
         * \brief Finds the representant element of the set that contains i
         * \param i - id of the element
         * \return id of the representant element
         */
        int findSet(int i);

        /**
         * \brief Checks if two elements are from the same set
         * \param i - id of the first  element
         * \param i - id of the second element
         * \return true if they are, or false otherwise
         */
        bool isSameSet(int i, int j);

        /*
         * \brief Joins two subsets
         * \param i - id of one element of the first subset
         * \param i - id of one element of the second subset
         */
        void unionSet(int i, int j);

    private:
        std::vector<int> p;
        std::vector<int> rank;

    };

    /**
     * \brief Returns the cost of the minimum spanning tree and represents it in a disjoint sets structure
     * \param ds - disjoint sets structure to populate
     * \param edgeList - sorted edge list, the first element is the weith, the second is a pair of vertex
     * \return the cost
     */
    int kruskal(DisjointSets& ds, const std::vector<std::pair<int, IntPair>>& edgeList);

    /**
     * \brief Returns the cost of the minimum spanning tree
     * \param size - number of vertex
     * \param adjList - list of adjacencies
     * \return the cost
     */
    int prim(std::size_t size, std::vector<std::vector<IntPair>> adjList);


}

#endif /* GRAPH_H */

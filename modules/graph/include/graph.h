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
 *   Copyright (C) 2016 by Ícaro Magalhães
 *
 *   \file graph.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \date 05/05/2016
 *
 ***************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

namespace compendium
{

    /**
     * \brief The class represents an undirected graph of vertices.
     */
    class Graph
    {

    public:
        /**
         * \brief Create a graph with V vertices
         */
         Graph(int V) : adj(V), v(V) { }

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
        void add_edge(int v, int w);

        /**
         * \brief Return graph string representation
         */
        std::string to_string();

        /**
         * /brief Compute the degree of Graph g v's vertex
         */
        static int degree(Graph &g, int v) { return g.adj[v].size(); }
        static double average_degree(Graph &g);
        static int max_degree(Graph &g);
        static int number_of_self_loops(Graph &g);

    private:
        int v;
        int e;
        std::vector< std::vector<int> > adj;

    };

}

#endif /* GRAPH_H */

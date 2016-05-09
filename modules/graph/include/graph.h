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
         * /brief Compute the degree of Graph g v's vertex
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

}

#endif /* GRAPH_H */

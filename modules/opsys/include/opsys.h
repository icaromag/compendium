/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Mateus Pires Lustosa
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file opsys.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \author Mateus Pires Lustosa <mateusplpl@gmail.com>
 *   \date 02/06/2016
 *
 ***************************************************************************/

#ifndef OPSYS_H
#define OPSYS_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iomanip>

namespace compendium
{

    /**
     * \brief Static methods and algorithms that simulates memory paging and proccess scheduling
     */
    class OpSys
    {

    public:


        /**
         * \brief static method containing all method calls
         * \return string containing all method calls
         */
        static std::string methods();

        /**
         * \brief Memory Paging Algorithm that receives a vector of integers and a size
         *      for the memory layout. The first element that enters is the first that leaves
         * \params vector of integers and unsigned int size for a chunk of memory
         * \return number of times that occours memory substitutions
         */
        static int FIFOAlgorithm(const std::vector<int> &, const uint);

        /**
         * \brief Memory Paging Algorithm that receives a vector of integers and a size
         *      for the memory layout. Looks for the last element to be called and remove it
         * \params vector of integers and unsigned int size for a chunk of memory
         * \return number of times that occours memory substitutions
         */
        static int OptimumAlgorithm(const std::vector<int> &, const uint);

        /**
         * \brief Memory Paging Algorithm that receives a vector of integers and a size
         *      for the memory layout. Look for the last recently used element and removes it
         * \params vector of integers and unsigned int size for a chunk of memory
         * \return number of times that occours memory substitutions
         */
        static int LRUAlgorithm(const std::vector<int> &, const uint);

        /**
         * \brief Time slices are assigned to each process in equal portions
         *        and in circular order, handling all processes without priority
         *        (also known as cyclic executive).
         * \params const vector of pairs representing proccesses and time slices
         * \return void
         */
        static void round_robin(const std::vector< std::pair<int, int> > &);

        /**
         * \brief Jobs are executed on first come, first serve basis.
         * \params const vector of pairs representing proccesses and time slices
         * \return void
         */
        static void first_come_first_serve(const std::vector< std::pair<int, int> > &);

        /**
         * \brief Processer should know in advance how much time process will take. It is
         *      the bestapproach to minimize wasting time
         * \params const vector of pairs representing proccesses and time slices
         * \return void
         */
        static void shortest_job_first(const std::vector< std::pair<int, int> > &);

	}; //class

}

#endif // OPSYS_H

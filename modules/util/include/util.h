/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file util.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \date 01/05/2016
 *
 ***************************************************************************/

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>

#define COUT(msg) std::cout << msg << std::endl

namespace compendium
{

    /**
     * \brief This class helps other classes offering frequently used functions
     *        with static calls
     */
    class Util
    {

	public:

        /**
         * \brief Return manhattan distance between two points in a matrix plane
         * \return integer manhattan distance between two points
         */
        static int manhattan_distance(std::pair<int, int> p, std::pair<int, int> q);

        static std::vector<int> vector_with_random_ints(int size, int bound);

        /**
         * \brief prints a vector content
         * \param vector with integer elements and a delimiter character
         * \return void
         */
        static void print_vector(const std::vector<int> &, const char);

        /**
         * \brief check if integer vector contains element
         * \param vector of ints and a a const int element to look for
         * \return true if contains, false otherwise
         */
        static bool vector_contains(const std::vector<int> &, const int);

		/**
         * \brief executes a command and pipes the executes command to the calling program
         */
		static std::string hello();

	};

}

#endif // UTIL_H

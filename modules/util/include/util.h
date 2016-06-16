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
        template <typename T>
        static void print_vector(const std::vector<T> &_v, const char _delimit)
        {
            for_each(_v.begin(), _v.end(),
                [&](const T _element)
                {
                    std::cout << _element << _delimit;
                }
            );
            std::cout << std::endl;
        }

        /**
         * \brief check if integer vector contains element
         * \param vector of ints and a a const int element to look for
         * \return true if contains, false otherwise
         */
        template <typename T>
        static bool vector_contains(const std::vector<T> &_v, const T _element)
        {
            for(auto it = _v.begin(); it != _v.end(); ++it)
                if((*it) == _element) return true;
            return false;
        }

        /**
         * \brief aux function that exchage two values based on position
         * \params a vector and two positions from elements that needs
         *      to be exchanged
         */
        template <typename T>
        static void exchange(std::vector<T> &v, const uint i, const uint j)
        {
            T aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }

		/**
         * \brief executes a command and pipes the executes command to the calling program
         */
		static std::string hello();

	};

}

#endif // UTIL_H

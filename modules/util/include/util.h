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

namespace compendium
{

    /**
     * \brief This class helps other classes offering frequently used functions
     */
    class Util
    {

	public:

		/**
         * \brief default constructor
         */
	 	Util();

		/**
         * \brief default destructor
         */
	 	~Util();

        /**
         * \brief Return manhattan distance between two points in a matrix plane
         */
        static int manhattan_distance(std::pair<int, int> p, std::pair<int, int> q);

        static std::vector<int> vector_with_random_ints(int size, int bound);

		/**
         * \brief executes a command and pipes the executes command to the calling program
         */
		static std::string hello();

	};

}

#endif // UTIL_H

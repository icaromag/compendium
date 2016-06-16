/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Mateus Pires
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file sorting.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
     \author Mateus Pires <mateusplpl@gmail.com>
 *   \date 05/06/2016
 *
 ***************************************************************************/

#ifndef SORTING_H
#define SORTING_H

#include <util.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>

namespace compendium
{

    /**
     * \brief
     */
    class Sorting
    {

	public:

        /**
         * \brief executes a command and pipes the executes command to the calling program
         * \params void
         * \return std::string
         */
        // static std::string hello();

        template <typename T>
        static void insertion(std::vector<T> &v)
        {
            for(unsigned int i = 0; i < v.size(); ++i)
            {
                for(unsigned int j = i; j > 0 && (v[j] < v[j-1]); --j)
                {
                    T aux = v[j];
                    v[j] = v[j-1];
                    v[j-1] = aux;
                }
            }
        }

	};

}

#endif // SORTING_H

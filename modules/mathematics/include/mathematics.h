/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Mateus Pires Lustosa
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file mathematics.h
 *   \author Ícaro Magalhães <icaro.lmag@gmail.com>
 *   \author Mateus Pires <mateusplpl@gmail.com>
 *   \date 11/05/2016
 *
 ***************************************************************************/

#ifndef MATHEMATICS_H
#define MATHEMATICS_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>

namespace compendium
{

    #define cls(arr) memset(arr, 0, sizeof arr);
    /**
     * \brief This class helps other classes offering mathematics algorithms
     */
    class Mathematics
    {

    public:

        /**
         * \brief return base powered to expoent
         * \param base
         * \param exponent
         * \return integer
         */
        static long power(const int b, const int e);

        template<typename T>
        static void swap(T *f, T *s)
        {
            *f = *f ^ *s;
            *s = *f ^ *s;
            *f = *f ^ *s;
        }

        static ulong factorial(const uint n);

        /**
         * \brief Calculate arithmetic progression sum
         * \param first
         * \param ratio
         * \param quantity
         * \return long with AP sum
         */
        static long arithmetic_progression_sum(int initial, int ratio, int quantity);

        /**
         * \brief Calculate geometric progression sum
         * \param first
         * \param ratio
         * \param quantity
         * \return long with GP sum
         */
        static long geometric_progression_sum(int initial, int ratio, int quantity);

        /**
         * \brief Returns array with fibonacci numbers calculated dynamically
         * \param quantity of fibonacci numbers
         * \return unsigned int array with fibonacci numbers
         */
        static uint *dynamic_fibonacci(const uint n);

        /**
         * \brief In combinatorial mathematics, the Catalan numbers form a sequence
         *      of natural numbers that occur in various counting problems,
         *      often involving recursively-defined objects
         * \param quantity of catalan numbers
         * \return unsigned int array with catalan numbers
         */
        static uint *dynamic_catalan_numbers(const uint n);


        /**
         * \brief converts number from base 10 to another base
         * \param integer number
         * \param integer base
         * \return char* with number in requested base
         */
        static char *convert_num_to_base(int n, const uint b);

	};

}

#endif // MATHEMATICS_H

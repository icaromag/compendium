/***************************************************************************
 *   Copyright (C) 2016 by Ícaro Magalhães and Marcello Marques
 *
 *   João Pessoa - PB - Brasil
 *
 *   \file dp.h
 *   \author Ícaro Lima Magalhães <icaro.lmag@gmail.com>
 *   \author Marcello Marques
 *
 ***************************************************************************/

#ifndef DP_H
#define DP_H

#include <iostream>
#include <string>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <util.h>

namespace compendium
{

    /**
     * \brief TODO brief content
     */
    class DP
    {

    public:

        static int binary_knapsack(int W, std::vector< std::pair<int, int> > &sack, int n);

        static int coin_change(int cents, int* coins, int s);

        static bool word_break(std::string str, const std::vector<std::string> dictionary);

        static int binomial_coefficient(const int n, const int k);


    };

}

#endif // DP_H

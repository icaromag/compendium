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

        // TODO docs
        static int binary_knapsack(int W, std::vector< std::pair<int, int> > &sack, int n);

        // TODO docs
        static int coin_change(int cents, int* coins, int s);

        // TODO docs
        static bool word_break(std::string str, const std::vector<std::string> dictionary);

        // TODO docs
        static int binomial_coefficient(const int n, const int k);

        // TODO docs
        static int longest_common_subsequence(const std::string &str1, const std::string &str2);

        // TODO docs
        static int coin_change(const std::vector<int> &coins, const int N);

    };

}

#endif // DP_H

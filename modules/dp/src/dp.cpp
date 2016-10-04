#include <dp.h>

namespace compendium
{

    // Check dp.h that contains doc and header refs
    // Check cpp unit that contains unit tests
    int DP::binary_knapsack(int W, std::vector< std::pair<int, int> > &sack, int n)
    {

        int K[n+1][W+1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (i==0 || j==0)
                {
                   K[i][j] = 0;
                }
                else if (sack[i-1].second <= j)
                {
                    K[i][j] = std::max(sack[i-1].first + K[i-1][j-sack[i-1].second],  K[i-1][j]);
                }
                else
                {
                    K[i][j] = K[i-1][j];
                }
            }
        }

        return K[n][W];

    }

    int DP::coin_change(int cents, int* coins, int s)
    {
        if(cents <= 0) return 0;

        int **dp;
        dp = new int*[cents+1];
        for (int i = 0; i < cents + 1; i++)
        {
            dp[i] = new int[s];
        }

        for (int i = 0; i < s; i++)
        {
            dp[0][i] = 1;
        }


        for (int i = 1; i <= cents; i++)
        {
            for (int j = 0; j < s; j++)
            {
                int with_j = (((i - coins[j]) >= 0) ? dp[i-coins[j]][j] : 0);
                int without_j = ((j > 0 ? dp[i][j-1] : 0 ));
                dp[i][j] = without_j + with_j;
            }
        }

        return dp[cents][s-1];

    }

    // Just the implementation
    // Check dp.h that contains doc and header refs
    // Check cpp unit that contains unit tests
    int DP::binomial_coefficient(const int n, const int k)
    {
        int dp[n+1][k+1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= std::min(k, n); j++) //k > n doesn't make sense
            {
                if (i == 0 || j == 0 || j == i) //C(i, 0) = C(i, i) = 1 : base case
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; //recursion on table
                }
            }
        }

        return dp[n][k];
    }


    bool DP::word_break(std::string str, const std::vector<std::string> dictionary)
    {
        int size = str.size();
        if (size == 0) return true;

        bool piece[size+1]; // 1 if str[0..i-1] is in dictionary
        std::memset(piece, 0, sizeof(piece));

        for (int i = 1; i <= size; i++)
        {
            if (piece[i] == false && Util::vector_contains(dictionary, str.substr(0, i)))
            {
                piece[i] = true; //if piece[i] == true we dont need check
            }

            if (piece[i] == true)
            {
                if (i == size)
                {
                    return true; //the complete word
                }

                for (int j = i+1; j <= size; j++)
                {
                    if (piece[j] == false && Util::vector_contains(dictionary, str.substr(i, j-i)))
                    {
                        piece[j] = true; //same check, but now in the remainders
                    }

                    if (j == size && piece[j] == true)
                    {
                        return true; //last char
                    }
                }
            }
        }

        return false;
    }



}

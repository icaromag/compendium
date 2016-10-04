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


}

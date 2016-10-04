#include <dp.h>

namespace compendium
{
    // Emty in case of generic programming
    int DP::knapSack(int W, std::vector< std::pair<int, int> > &sack, int n)
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
}

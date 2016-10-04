#include <dp.h>
#include <iostream>
#include <cassert>

using namespace compendium;

bool binary_knapsack()
{
    int N, V, W(10), C;
    std::vector< std::pair<int, int> > sack;
    while(std::cin >> N && N > 0)
    {

        std::cin >> C;

        sack.clear();

        while(N--)
        {
            std::cin >> V >> W;
            sack.push_back(std::make_pair(V, W));
        }

        std::cout <<
            DP::knapSack(C, sack, sack.size()) << " min." << std::endl;

    }

    return true;
}

int main()
{

    assert(binary_knapsack());

    return 0;
}

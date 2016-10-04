#include <dp.h>
#include <iostream>
#include <cassert>

using namespace compendium;

bool binary_knapsack_UnitTest()
{
    // TODO remove hardcoded "10" value
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

        std::cout << DP::binary_knapsack(C, sack, sack.size())
            << " min." << std::endl;

    }

    return true;
}

bool coin_change_UnitTest()
{
    /* TODO refactor this unit test

    int cents, q;

    while (cin >> cents >> q)
    {
        int *coins = new int[q];
        for (int i = 0; i < q; i++) cin >> coins[i];

        cout << "Cents: "<< cents << endl << "Coins: ";
        for (int i = 0; i < q; i++) cout << coins[i] << " ";
        cout << endl << DP::coin_change(cents, coins, q) << endl;

        delete coins;
    }

    */

    // TODO remove hardcoded return val
    return true;
}

bool word_break_UnitTest()
{

    // TODO add namespaces and refactor input parsing
/*
    cin >> dictionary_size;

    // TODO refactor input parsing
    dictionary = new string[dictionary_size];
    for (int i = 0; i < dictionary_size; i++)
        cin >> dictionary[i];

    int tries;
    string in;

    cin >> tries;
    while (tries--)
    {
        cin >> in;
        cout << in << " ";
        word_break(in) ? cout << "In\n": cout << "Out\n";
    }
*/

    // TODO remove hardcoded return val
    return true;

}

bool binomial_coefficient_UnitTest()
{
    // TODO refactor inputs
    // int n, k;

    // while (cin >> n >> k)
    //     cout << "C(" << n << ", " << k << "): " << DP::binomial_coefficient(n, k) << endl;

    // TODO remove hardcoded return val
    return true;

}

int main( /* int argc, char const *argv[] */ ) // temp wunused input parsing vars
{

    assert(binary_knapsack_UnitTest());
    assert(coin_change_UnitTest());
    assert(word_break_UnitTest());
    assert(binomial_coefficient_UnitTest());

    std::clog << "all tests passed" << std::endl;

    return 0;
}

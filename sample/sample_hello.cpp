/*
 *
 * This sample file shows how to use the shared library compendium.so
 *
 * To compile use:
 *
 * g++ -std=c++11 -Wall -Wextra -I /usr/local/include/compendium/core/ -L /usr/local/lib/compendium/core/ -lcompendium sample_hello.cpp -o a.out
 *
 */

#include <compendium.h>
#include <iostream>
#include <vector>

/* optional namespace */
// using namespace compendium;

int main()
{

    std::vector<int> v = Util::vector_with_random_ints(10,100);
    Sorting::insertion(v);

    return 0;

}

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

/* optional namespace */
// using namespace compendium;

int main()
{

    std::cout << compendium::Util::hello() << std::endl;

    return 0;

}

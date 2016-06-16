/*
 * This is a sample code
 */

#include <compendium.h>
#include <iostream>

using namespace compendium;

void _init()
{
    std::cout << "Running sample code and testing modules" << std::endl;
}

int main()
{

    _init();

    std::cout << Util::hello() << std::endl;
    std::cout << Sorting::hello() << std::endl;

    return 0;

}

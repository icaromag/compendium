#include <util.h>
#include <iostream>

using namespace compendium;

int main()
{

    std::cout << "Util module test unit is running" << std::endl;
    std::cout << Util::hello() << std::endl;

    std::cout << "Getting a vector with size 15 and numbers between 0 and 1000" << std::endl;
    std::vector<int> v = Util::vector_with_random_ints(15, 1000);

    Util::print_vector(v, ' ');

    return 0;

}

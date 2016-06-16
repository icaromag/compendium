#include <sorting.h>
#include <util.h>
#include <iostream>

using namespace compendium;

int main()
{

    std::cout << "Module Sorting unit tests are running" << std::endl;

    std::vector<int> random_ints = Util::vector_with_random_ints(10,1000);
    Sorting::insertion(random_ints);
    Util::print_vector(random_ints, ' ');

    std::vector<char> random_chars = {'t','e','s','t','a','n','d','o'};
    Sorting::insertion(random_chars);
    Util::print_vector(random_chars, ' ');

    std::cout << "random_chars contains the character \'o\' ? : ";
    std::cout << (Util::vector_contains(random_chars, 'o') ? "True\n" : "False\n");

    return 0;

}

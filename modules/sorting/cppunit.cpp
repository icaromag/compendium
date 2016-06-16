#include <sorting.h>
#include <util.h>
#include <iostream>

using namespace compendium;

int main()
{

    std::cout << "Module Sorting unit tests are running" << std::endl;

    std::vector<int> random_ints = Util::vector_with_random_ints(10,1000);
    std::vector<char> random_chars = {'t','e','s','t','a','n','d','o'};
    Util::print_vector(random_ints, ' ');
    Util::print_vector(random_chars, ' ');

    // Sorting::insertionsort(random_ints);
    // Sorting::selectionsort(random_ints);
    // Sorting::shellsort(random_ints);
    // Sorting::heapsort(random_ints);
    // Sorting::mergesort(random_ints);
    Sorting::quicksort(random_ints);

    // Sorting::insertionsort(random_chars);
    // Sorting::selectionsort(random_chars);
    // Sorting::shellsort(random_chars);
    // Sorting::heapsort(random_chars);
    // Sorting::mergesort(random_chars);
    Sorting::quicksort(random_chars);


    Util::print_vector(random_ints, ' ');
    Util::print_vector(random_chars, ' ');
    // std::cout << "random_chars contains the character \'o\' ? : ";
    // std::cout << (Util::vector_contains(random_chars, 'o') ? "True\n" : "False\n");

    return 0;

}

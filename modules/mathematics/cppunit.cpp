#include <mathematics.h>
#include <util.h>
#include <iostream>

using namespace compendium;

int main()
{

    COUT(Mathematics::power(2,10));
    COUT(Mathematics::factorial(10));
    COUT(Mathematics::arithmetic_progression_sum(1, 1, 50));
    COUT(Mathematics::geometric_progression_sum(2, 2, 5));

    uint *fib10 = Mathematics::dynamic_fibonacci(10);
    std::vector<uint> vfib10(fib10, fib10+10);
    Util::print_vector(vfib10, ' ');

    uint *cat10 = Mathematics::dynamic_catalan_numbers(10);
    std::vector<uint> vcat10(cat10, cat10+10);
    Util::print_vector(vcat10, ' ');

    COUT(Mathematics::convert_num_to_base(100, 2));

    return 0;

}

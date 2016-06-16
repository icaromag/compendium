#include <strings.h>
#include <iostream>

using namespace compendium;

int main()
{
    std::cout << Strings::hello_strings() << std::endl;

    std::string str = "abababcabababcabababc";
    int* preffixLengths = Strings::generatePreffixLengths(str);

    for (std::size_t i = 0; i <= str.length(); i++)
        std::cout << preffixLengths[i] << " ";

    std::cout << std::endl;

    std::cout << Strings::countPeriodicSubstring(str) << std::endl;

    return 0;
}

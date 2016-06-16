#include <strings.h>
#include <iostream>

using namespace compendium;

int main()
{
    int n; std::cin >> n;

    bool notFirst = false;
    std::string str;

    while (n--)
    {
        std::cin >> str;
        std::cin >> str;

        if (notFirst)
            std::cout << std::endl;
        else
            notFirst = true;

        std::cout << Strings::countPeriodicSubstring(str) << std::endl;
    }

    return 0;
}

#include <strings.h>
#include <iostream>
#include <fstream>

using namespace compendium;

bool uva10298_powerStrings()
{
    std::ifstream pin("uva10298.in");
    std::ifstream pout("uva10298.out");
    std::string in;

    if ( ! pin)
        std::cout << "Strings: uva10298_powerStrings: file error: uva10298.in" << std::endl;

    if ( ! pout)
        std::cout << "Strings: uva10298_powerStrings: file error: uva10298.out" << std::endl;

    while (pin >> in && in != ".")
    {
        int* preffixLengths = Strings::generatePreffixLengths(in);
        int periodicLength = in.length() - preffixLengths[in.length()];
        int n = in.length() % periodicLength ? 1 : in.length() / periodicLength;

        int check; pout >> check;
        if (n != check)
        {
            std::cout << "Strings: uva10298_powerStrings: " << in << std::endl;
            return false;
        }
    }

    return true;
}

bool uva526_stringDistanceAndTransformProcess()
{
    std::ifstream pin("uva526.in");
    // std::ifstream pout("uva10298.out");

    if ( ! pin)
        std::cout << "Strings: uva10298_powerStrings: file error: uva10298.in" << std::endl;

    std::string from, to;
    while (pin >> from && pin >> to)
    {
        int ed = Strings::editDistance(from, to);
        std::cout << "For " << from << " and " << to << " : ED " << ed << std::endl;
    }

    return true;
}

int main()
{
    bool status;

    status = uva10298_powerStrings();
    std::cout << "Strings: uva10298_powerStrings " << (status ? "[OK]" : "[ERROR]") << std::endl;

    uva526_stringDistanceAndTransformProcess();

    return 0;
}

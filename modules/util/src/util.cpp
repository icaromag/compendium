#include <util.h>


namespace compendium
{

    int Util::manhattan_distance(std::pair<int, int> p, std::pair<int, int> q)
    {
        return abs(q.first - p.first) + abs(q.second - p.second);
    }

    //TODO: Random elements instead of ints
    std::vector<int> Util::vector_with_random_ints(int size, int bound)
    {

        std::vector<int> vec(size);
        std::generate(vec.begin(), vec.end(),
            [&]()
            {
                return std::rand() % bound + 1;
            }
        );

        return vec;

    }

    std::string Util::hello()
    {
        return "compendium-lib :: module util";
    }

}

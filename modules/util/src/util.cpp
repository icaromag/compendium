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

    void Util::print_vector(const std::vector<int> &_v, const char _delimit)
    {
        for_each(_v.begin(), _v.end(),
            [&](const int _element)
            {
                std::cout << _element << _delimit;
            }
        );
        std::cout << std::endl;
    }

    bool Util::vector_contains(const std::vector<int> &_v, const int _element)
    {
        for(auto it = _v.begin(); it != _v.end(); ++it)
            if((*it) == _element) return true;
        return false;
    }

    std::string Util::hello()
    {
        return "Hello World :: compendium-lib";
    }

}

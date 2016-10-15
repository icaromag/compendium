#include <greedy.h>


// CHECK ../greedy.h FOR FULL CONTENT
// THIS MODULE IS UNDER IMPLEMENTATION
namespace compendium
{
    // Greedy activity selection implementation
    std::vector< std::pair<int, int> > GREEDY::activity_selection(
        std::vector< std::pair<int, int> > &act)
    {
        std::sort(std::begin(act), std::end(act));
        std::vector< std::pair<int, int> > sol;

        sol.push_back(act[0]);

        for(unsigned int i = 1; i < act.size(); i++)
        {
            if(act[i].second >= sol[sol.size()-1].first)
            {
                sol.push_back(act[i]);
            }
        }
        return sol;
    }


}

#include <greedy.h>

// CHECK ../greedy.h for DataStructures implementation
//   Prim's and Kruskal's MST algorithms
//   Union Find, minimum Priority Queues and EdgeWeightedGraph
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

    double GREEDY::fractional_knapsack(int W, std::vector< std::pair<int, int> > items)
    {
        unsigned int n = items.size();
        // pair is <int, int> -> <value, weight>
        std::sort(std::begin(items), std::end(items),
            [&](const std::pair<int, int> a, const std::pair<int, int> b)
            {
                return ((double) a.first / a.second) > ((double) b.first / b.second);
            });

        int curr_weight = 0;
        double final_val = 0.0;

        for (unsigned int i = 0; i < n; i++)
        {
            if (curr_weight + items[i].second <= W)
            {
                curr_weight += items[i].second;
                final_val += items[i].first;
            }
            else
            {
                int remain = W - curr_weight;
                final_val += items[i].first * ((double) remain / items[i].second);
                break;
            }
        }

        return final_val;
    }

}

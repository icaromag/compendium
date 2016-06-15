#include <opsys.h>
#include <iostream>

#define PRINT(s, f) std::cout << s << ' ' << f << std::endl

using namespace compendium;

int main()
{

    //Testing CPU Scheduler algorithms
    std::vector< std::pair<int, int> > processes
    {
        std::make_pair(0, 20),
        std::make_pair(0, 20),
        std::make_pair(0, 20),
        std::make_pair(0, 20)
    };

    std::cout << "Simulating algorithms for " << processes.size() << " processes." << std::endl;

    OpSys::shortest_job_first(processes);
    OpSys::round_robin(processes);
    OpSys::first_come_first_serve(processes);


    //Testing memory paging algorithms
    std::cout << "Simulating memory Paging Algorithms" << std::endl;

    unsigned int qt_memory_pages(3);

    std::vector<int> memory_ref_sequence
    { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };

    std::vector<int> memory_pages(qt_memory_pages);

    PRINT("FIFO", OpSys::FIFOAlgorithm(memory_ref_sequence, qt_memory_pages));
    PRINT("OTM", OpSys::OptimumAlgorithm(memory_ref_sequence, qt_memory_pages));
    PRINT("LRU", OpSys::LRUAlgorithm(memory_ref_sequence, qt_memory_pages));


    return 0;
}

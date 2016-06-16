#include <opsys.h>

namespace compendium
{

    enum Algorithm { RR, FCFS, SJF };

    struct process {
        /*
            Simple processes control blocks for measurements
                and data manipulation.
       */
        process(
            int _pid, double _arrival_time, double _burst_time)
        {
            pid = _pid;

            arrival_time = _arrival_time;
            burst_time = _burst_time;
            return_time = 0;
            response_time = 0;
            wait_time = 0;

        }

        int pid;

        double arrival_time;
        double burst_time;
        double return_time;
        double response_time;
        double wait_time;

    };//proccess struct

    std::string OpSys::methods()
    {
        return "methods are: ";
    }

    /*Aux function to find element in memory pages*/
    bool memory_contains(std::vector< std::pair<int, int> > &_memory_pages,
        const int _element)
    {
        for(auto it = _memory_pages.begin(); it != _memory_pages.end(); ++it)
            if((*it).first == _element) return true;
        return false;
    }

    int OpSys::FIFOAlgorithm(const std::vector<int> &_memory_ref_sequence,
        const uint _qt_memory_pages)
    {
        std::vector< std::pair<int, int> > _memory_pages;
        int result = 0;

        for_each(_memory_ref_sequence.begin(), _memory_ref_sequence.end(),
            [&](int element)
            {

                for_each(_memory_pages.begin(), _memory_pages.end(),
                    [&](std::pair<int, int> &_element)
                    {
                        _element.second++;
                    }
                );

                sort(_memory_pages.begin(), _memory_pages.end(),
                    [&](const std::pair<int, int> &_this,
                        const std::pair<int, int> &_that) -> bool
                    {
                        return _this.second < _that.second;
                    }
                );

                if(!memory_contains(_memory_pages, element))
                {

                    if(_memory_pages.size() >= _qt_memory_pages)
                    {
                        _memory_pages.pop_back();
                    }

                    _memory_pages.emplace_back(std::make_pair(element, 0));
                    result++;

                }

            }
        );

        return result;

    }

    /* Aux for OptimumAlgorithm */
    int get_last_used_index(std::vector< std::pair< int, int> > __memory_pages,
        const std::vector<int> &__memory_ref_sequence, const int _curr_index)
    {

        for(uint i = 0; i < __memory_pages.size(); ++i)
        {

            for(uint j = _curr_index; j < __memory_ref_sequence.size(); ++j)
            {
                if(__memory_pages[i].first == __memory_ref_sequence[j])
                {
                    __memory_pages[i].second++;
                    break;
                }
                else
                {
                    __memory_pages[i].second++;
                }
            }
        }

        int maximum_index(INT_MIN);
        int maximum_value(INT_MIN);
        for(uint i = 0; i < __memory_pages.size(); ++i)
        {
            if(__memory_pages[i].second > maximum_value)
            {
                maximum_value = __memory_pages[i].second;
                maximum_index = i;
            }

        }

        return maximum_index;

    }

    int OpSys::OptimumAlgorithm(const std::vector<int> &_memory_ref_sequence,
        const uint _qt_memory_pages)
    {

        std::vector< std::pair<int, int> > _memory_pages;
        int result = 0;
        int curr_index(0);
        for(auto it = _memory_ref_sequence.begin(); it != _memory_ref_sequence.end(); ++it)
        {
            ++curr_index;
            int curr_element = *it;

            if(_memory_pages.size() < _qt_memory_pages)
            {

                if(!memory_contains(_memory_pages, curr_element))
                {
                    _memory_pages.emplace_back(std::make_pair(curr_element, 0));
                    ++result;
                }
                else
                {
                    continue;
                }

            }
            else
            {

                if(!memory_contains(_memory_pages, curr_element))
                {
                    int index = get_last_used_index(_memory_pages, _memory_ref_sequence, curr_index);
                    _memory_pages[index].first = *it;
                    ++result;
                }

            }

        }

        return result;

    }

    /* Aux for LRUAlgorithm */
    int get_last_recently_used_index(std::vector< std::pair< int, int> > &__memory_pages)
    {

        int maximum_index(INT_MIN);
        int maximum_value(INT_MIN);
        for(uint i = 0; i < __memory_pages.size(); ++i)
        {
            if(__memory_pages[i].second > maximum_value)
            {
                maximum_value = __memory_pages[i].second;
                maximum_index = i;
            }

        }

        return maximum_index;

    }

    int OpSys::LRUAlgorithm(const std::vector<int> &_memory_ref_sequence,
        const uint _qt_memory_pages)
    {

        std::vector< std::pair<int, int> > _memory_pages;
        int result = 0;
        int curr_index(0);

        for(auto it = _memory_ref_sequence.begin(); it != _memory_ref_sequence.end(); ++it, ++curr_index)
        {

            int curr_element = *it;

            for(uint i = 0; i < _memory_pages.size(); ++i)
            {
                _memory_pages[i].second++;
            }

            if(_memory_pages.size() < _qt_memory_pages)
            {

                if(!memory_contains(_memory_pages, curr_element))
                {
                    _memory_pages.emplace_back(std::make_pair(curr_element, 0));
                    ++result;
                }
                else
                {
                    _memory_pages[curr_index].second = 0;
                    continue;
                }

            }
            else
            {

                if(!memory_contains(_memory_pages, curr_element))
                {
                    int index = get_last_recently_used_index(_memory_pages);
                    _memory_pages[index].first = *it;
                    _memory_pages[index].second = 0;
                    ++result;
                }
                else
                {

                    for(uint i = 0; i < _memory_pages.size(); i++)
                    {
                        if(_memory_pages[i].first == curr_element)
                        {
                            _memory_pages[i].second = 0;
                            break;
                        }
                    }

                    continue;

                }

            }

        }

        return result;

    }

    //PCB Algorithms Section

    /**
     * \brief Helper Function to sort vector of procces control blocks
     * \params vector of PCBs to sort
     * \return void
     */
    void sort_pcb(std::vector<process> &_pcb)
    {
        std::sort(
            _pcb.begin(),
            _pcb.end(),
            [](process i, process j) -> bool{
                return(
                    i.burst_time < j.burst_time
                );
            }
        );
    }


    void present_results(Algorithm _algorithm, std::vector< process > &_processes,
        double *values)
    {

        double return_time(0);
        double response_time(0);
        double wait_time(0);

        std::string alg;

        switch(_algorithm)
        {

            case FCFS:
                alg = "FCFS";
                for(uint i = 0; i < _processes.size(); i++)
                {
                    return_time += _processes[i].return_time - _processes[i].arrival_time;
                    response_time += _processes[i].response_time;
                    wait_time += _processes[i].wait_time;
                }

                return_time /= _processes.size();
                response_time /= _processes.size();
                wait_time /= _processes.size();
                break;
            case SJF:
                alg = "SJF";
                return_time = values[1];
                response_time = values[2];
                wait_time = values[0];
                break;;

            case RR:
                alg = "RR";
                return_time = values[1];
                response_time = values[2];
                wait_time = values[0];
                break;

            default:
                std::cout << "UNSUPPORTED ALGORITHM" << std::endl;
                return;

        }

        std::cout << std::fixed << std::setprecision(1) << alg << ' ' <<
            return_time << ' ' << response_time << ' ' << wait_time << ' ' << std::endl;

    }

    void OpSys::round_robin(const std::vector< std::pair<int, int> > &_procs)
    {

        int time_quantum(2);
        bool semaphore(false);
        int total_time(0);
        double wait_time(0);
        double turnaround_time(0);
        int remaining_processes(_procs.size());
        uint i(0);

        //The vector received as argument should not be modified.
        std::vector<process> processes;

        for(uint i = 0; i < _procs.size(); i++)
        {
            processes.push_back(
                process(
                    i+1,
                    _procs[i].first,
                    _procs[i].second
                )
            );

            processes[i].return_time = processes[i].burst_time;
        }

        while(remaining_processes)
        {
            if(processes[i].return_time <= time_quantum && processes[i].return_time > 0)
            {
                total_time += processes[i].return_time;
                processes[i].return_time = 0;
                semaphore = true;
            }
            else if(processes[i].return_time > 0)
            {
                processes[i].return_time -= time_quantum;
                total_time += time_quantum;
            }

            if(processes[i].return_time == 0 && semaphore)
            {
                remaining_processes--;
                wait_time += total_time - processes[i].arrival_time - processes[i].burst_time;
                turnaround_time += total_time - processes[i].arrival_time;
                semaphore = false;
            }

            if(i == processes.size() - 1)
            {
                i = 0;
            }
            else if(processes[i+1].arrival_time <= total_time)
            {
                i++;
            }
            else
            {
               i = 0;
            }
        }

        double rr_times[3] = {
            (wait_time / processes.size()),
            (turnaround_time / processes.size()),
            (double)time_quantum
        };

        present_results(RR, processes, rr_times);

    }

    void OpSys::first_come_first_serve(const std::vector< std::pair<int, int> > &_procs)
    {
        //This method needs values sorting and manipulation.
        //  the vector received as argument should not be modified.
        std::vector<process> processes;

        for(uint i = 0; i < _procs.size(); i++)
        {
            processes.push_back(
                process(
                    i+1,
                    _procs[i].first,
                    _procs[i].second
                )
            );
        }

        processes[0].return_time = processes[0].burst_time - processes[0].arrival_time;
        processes[0].response_time = processes[0].arrival_time;
        processes[0].wait_time = processes[0].arrival_time;

        for(uint i = 1; i < processes.size(); i++)
        {
            processes[i].return_time =
                processes[i-1].return_time + processes[i].burst_time;

            processes[i].response_time =
                processes[i-1].return_time - processes[i].arrival_time;

            processes[i].wait_time =
                processes[i-1].return_time - processes[i].arrival_time;

        }

        present_results(FCFS, processes, NULL);

    }

    void OpSys::shortest_job_first(const std::vector< std::pair<int, int> > &_procs)
    {

        //This method needs values sorting and manipulation.
        //  the vector received as argument should not be modified.
        std::vector<process> processes;

        for(uint i = 0; i < _procs.size(); i++)
        {
            processes.push_back(
                process(
                    i+1,
                    _procs[i].first,
                    _procs[i].second
                )
            );
        }

        sort_pcb(processes);

        double sjf_times[3];

        double total_time = 0;

        processes[0].wait_time = 0.0;

        for(uint i = 1; i < processes.size(); i++)
        {
            processes[i].wait_time = 0;
            for(uint j = 0; j < i; j++)
                processes[i].wait_time += processes[j].burst_time;

            total_time += processes[i].wait_time;
        }

        sjf_times[2] = total_time / processes.size();//whait time

        total_time = 0;

        for(uint i = 0; i < processes.size(); i++)
        {
            total_time += processes[i].burst_time + processes[i].wait_time;
        }

        sjf_times[1] = (double)total_time / (double)processes.size();//resp
        sjf_times[0] = sjf_times[2];//esp

        present_results(SJF, processes, sjf_times);

    }

}

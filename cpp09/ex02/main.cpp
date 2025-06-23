
#include "PmergeMe.hpp"
#include <sys/time.h>

int main(int argc, char **argv)
{
    timeval     start;
    timeval     end;
    PmergeMe    sortTool;
    

    if (argc < 3)
        return (std::cerr << RED << "Not enough elements to sort!" << RESET << std::endl, 1);
    if (argc > 5000)
        return (std::cerr << RED << "Too many elements!" << RESET << std::endl, 1);
    
    if (!sortTool.getArguments(argc, argv))
        return (std::cerr << RED << "One or more elements were invalid!" << RESET << std::endl, 1);
    std::cout << std::endl;

    sortTool.printContainerV("Before", sortTool.getContainerV());

    gettimeofday(&start, NULL);
    std::vector<int>    sortedV = sortTool.vcSort(sortTool.getContainerV());
    gettimeofday(&end, NULL);
    sortTool.printContainerV("After", sortedV);
    sortTool.printTime("std::vector", sortTool.getN(), start, end);

    gettimeofday(&start, NULL);
    std::deque<int>    sortedD = sortTool.dcSort(sortTool.getContainerD());
    gettimeofday(&end, NULL);
    sortTool.printTime("std::deque", sortTool.getN(), start, end);

    return (0);
}


#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    PmergeMe    sortTool;
    double      time;

    if (argc < 3)
        std::cerr << RED << "Not enough elements to sort!" << RESET << std::endl;
    
    if (!sortTool.getArguments(argc, argv))
        return (std::cerr << RED << "One or more elements were invalid!" << RESET << std::endl, 1);
    
    //sortTool.printContainerD(sortTool.getContainerD());
    sortTool.printContainerV(sortTool.getContainerV());

    clock_t start = clock();
    std::vector<int>    sortedV = sortTool.vcSort(sortTool.getContainerV());
    clock_t end = clock();
    time = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    std::cout << "------------" << std::endl;
    sortTool.printContainerV(sortedV);

    std::cout << GREEN << "Time: " << time << RESET << std::endl;



    return (0);
}

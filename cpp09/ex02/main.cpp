
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe    sortTool;

    if (argc < 3)
        std::cerr << RED << "Not enough elements to sort!" << RESET << std::endl;
    
    if (!sortTool.getArguments(argc, argv))
        return (std::cerr << RED << "One or more elements were invalid!" << RESET << std::endl, 1);
    
    sortTool.printContainerD(sortTool.getContainerD());
    sortTool.printContainerV(sortTool.getContainerV());

    return (0);
}
#include "Easyfind.hpp"

void    fill_containers(int number, std::vector<int> &vct, std::deque<int> &deq, std::list<int> &lst)
{
    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cout << GRAY << "Please introduce a number (" << i << "/5)" << RESET << std::endl;
        if (std::cin >> number)
        {
            vct.push_back(number);
            deq.push_back(number);
            lst.push_back(number);
        }
        else
        {
            if (std::cin.eof())
                exit(1);
            std::cout << "The number is not valid. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--;
        }
    }
    ::printContainer(vct);
}

void    search_containers(int number, std::vector<int> &vct, std::deque<int> &deq, std::list<int> &lst)
{
        srand(time(0));
        int r = rand() % 3;

        if (r == 0)
        {
            std::vector<int>::iterator it = ::easyfind(vct, number);
            std::cout << YELLOW << "Searching on a vector..." << RESET << std::endl;
            if (it != vct.end())
                std::cout << GREEN << "Coincidence found! -> " << *it << RESET << std::endl;
            else
                std::cout << RED << "Coincidence not found!" << RESET << std::endl;
        }
        else if (r == 1)
        {
            std::deque<int>::iterator it = ::easyfind(deq, number);
            std::cout << YELLOW << "Searching on a deque..." << RESET << std::endl;
            if (it != deq.end())
                std::cout << GREEN << "Coincidence found! -> " << *it << RESET << std::endl;
            else
                std::cout << RED << "Coincidence not found!" << RESET << std::endl;
        }
        else
        {
            std::list<int>::iterator it = ::easyfind(lst, number);
            std::cout << YELLOW << "Searching on a list..." << RESET << std::endl;
            if (it != lst.end())
                std::cout << GREEN << "Coincidence found! -> " << *it << RESET << std::endl;
            else
                std::cout << RED << "Coincidence not found!" << RESET << std::endl;
        }
}

int main()
{
    std::vector<int> vct;
    std::deque<int> deq;
    std::list<int> lst;

    int number = 0;

    fill_containers(number, vct, deq, lst);
    std::cout << GRAY << "Please introduce an occurence to search:" << RESET << std::endl;
    if (std::cin >> number)
        search_containers(number, vct, deq, lst);
    else
    {
        if (std::cin.eof())
            return (1);
        std::cout << RED << "The occurence is not valid!" << RESET << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return (1);
    }
    return (0);
}
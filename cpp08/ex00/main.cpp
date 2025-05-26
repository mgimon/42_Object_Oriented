#include "Easyfind.hpp"

int main()
{
    std::vector<int> vct;
    std::deque<int> deq;
    std::list<int> lst;

    int number;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Please introduce a number (" << i << "/5)" << std::endl;
        if (std::cin >> number)
        {
            (void)vct;
            (void)deq;
            (void)lst;
        }
        else
        {
            std::cout << "The number is not valid. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            i--;
        }
    }
    return (0);
}
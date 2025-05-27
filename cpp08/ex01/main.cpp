#include "Span.hpp"


int main(void) {

    int size = 5;
    Span<std::vector<int> >      vectorSpan(size);
    Span<std::deque<int> >       dequeSpan(size);
    Span<std::list<int> >        listSpan(size);


    try {

        for (int i = 0; i < size; i++)
        {
            std::cout << GRAY << "Please input numbers to fill container:" << RESET << std::endl;

            int number = 0;
            if (std::cin >> number)
            {
                vectorSpan.addNumber(number);
                dequeSpan.addNumber(number);
                listSpan.addNumber(number);
            }
            else
            {
                if (std::cin.eof())
                    return (1);
                std::cout << RED << "The input is not valid!" << RESET << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return (1);
            }
        }
        ::printContainer(vectorSpan.getContainer());
    }
    catch (const std::exception &e) {
        std::cout << RED << e.what() << ": not enough numbers for span" << RESET << std::endl;
    }
    return (0);
}
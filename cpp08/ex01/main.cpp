
#include "Span.hpp"

void	fillVector(std::vector<int> &vctor, int amount, int max)
{
	int		r;

	for (int i = 0; i < amount; i++)
	{
		r = rand() % max;
		vctor.push_back(r);
	}
}

int main()
{
	srand(time(0));

	Span				sp = Span(std::numeric_limits<int>::max());
	std::vector<int>	vctor;

	std::cout << YELLOW << "--- TESTING WITH 10 NUMBERS ---" << RESET << std::endl;
	try
	{
		fillVector(vctor, 10, 100);
		sp.addNumber(vctor.begin(), vctor.end());
		sp.printContainer();

		std::cout << GREEN << "The shortest span is " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "The longest span is " << sp.longestSpan() << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	sp.clearContainer();
	vctor.clear();

	std::cout << YELLOW << "--- TESTING WITH 20 NUMBERS ---" << RESET << std::endl;
	try
	{
		fillVector(vctor, 20, 100);
		sp.addNumber(vctor.begin(), vctor.end());
		sp.printContainer();

		std::cout << GREEN << "The shortest span is " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "The longest span is " << sp.longestSpan() << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	sp.clearContainer();
	vctor.clear();

	std::cout << YELLOW << "--- TESTING WITH 20000 NUMBERS ---" << RESET << std::endl;
	try
	{
		fillVector(vctor, 20000, 20000);
		sp.addNumber(vctor.begin(), vctor.end());
		sp.printContainer();

		std::cout << GREEN << "The shortest span is " << sp.shortestSpan() << RESET << std::endl;
		std::cout << GREEN << "The longest span is " << sp.longestSpan() << RESET << std::endl;
		std::cout << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	sp.clearContainer();
	vctor.clear();

}

/*int main()
{ 
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
 }*/

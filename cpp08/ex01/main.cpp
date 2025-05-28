
#include "Span.hpp"

// TODO : customize exceptions and create main testing huge ranges
int main()
{ 
	Span sp = Span(10);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.printContainer();

	return 0;
 }

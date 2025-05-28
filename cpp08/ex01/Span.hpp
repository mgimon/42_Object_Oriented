#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
#include <sstream>
#include <limits>
#include <algorithm>
#include <vector>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

class Span {

	private:

		unsigned int		_N;
		std::vector<int>	_container;

	public:

		Span();
		Span(unsigned int N);
		Span(const Span &ref);
		Span& operator = (const Span &ref);
		~Span();

		void				printContainer();

		int		shortestSpan();
		int		longestSpan();
		void	addNumber(int number);
		void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);

};

#endif


#include "Span.hpp"

// ** CANONICAL ** //

Span::Span() : _N(0), _container() {
	std::cout << GRAY << "Creating a Span object..." << RESET << std::endl;
}

Span::Span(unsigned int N) : _N(N), _container() {
	std::cout << GRAY << "Creating a Span object..." << RESET << std::endl;
}

Span::Span(const Span &ref) : _N(ref._N), _container(ref._container) {
	std::cout << GRAY << "Copying a Span object..." << RESET << std::endl;
}

Span& Span::operator = (const Span &ref) {
	if (this != &ref)
	{
		this->_N = ref._N;
		this->_container = ref._container;
	}
	std::cout << GRAY << "Assigning a Span object..." << RESET << std::endl;
	return (*this);
}

Span::~Span() {
	std::cout << GRAY << "Destroying a Span object..." << RESET << std::endl;
}

// ** METHODS ** //

void	Span::printContainer() {

	std::cout << std::endl;
	std::cout << "The container has:" << std::endl;

	for (size_t i = 0; i < _container.size(); i++)
		std::cout << _container[i] << std::endl;

	std::cout << std::endl;
}

int		Span::longestSpan() {

	std::vector<int>	tmp;

	if (this->_container.size() < 2)
		throw (std::exception());

	tmp = this->_container;
	std::sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *tmp.begin());
}

int		Span::shortestSpan() {

	std::vector<int>	tmp;
	int					shortSpan;

	if (this->_container.size() < 2)
		throw (std::exception());

	tmp = this->_container;
	shortSpan = std::numeric_limits<int>::max();
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 1; i < tmp.size(); i++)
	{
		shortSpan = std::min(shortSpan, (tmp[i] - tmp[i - 1]));
	}
	return (shortSpan);
}

void	Span::addNumber(int number) {

	if (this->_container.size() >= _N)
		throw (std::exception());

	this->_container.push_back(number);
}

void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {

	if (this->_container.size() >= _N)
		throw (std::exception());
	if ((this->_container.size() + (end - start)) > _N)
		throw (std::exception());

	_container.insert(_container.end(), start, end);
}

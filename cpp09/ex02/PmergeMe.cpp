
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& ref) : vC(ref.vC), dC(ref.dC) {}

PmergeMe& PmergeMe::operator = (const PmergeMe& ref) {
	if (this != &ref)
	{
		this->vC = ref.vC;
		this->dC = ref.dC;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void    PmergeMe::printContainers() const {

    std::vector<int>::const_iterator vIt = this->vC.begin();
    std::deque<int>::const_iterator  dIt = this->dC.begin();

    std::cout << GRAY << "### Printing vector ###" << RESET << std::endl;
    while (vIt < this->vC.end())
    {
        std::cout << *vIt << std::endl;
        ++vIt;
    }
    std::cout << std::endl;
    std::cout << GRAY << "### Printing deque ###" << RESET << std::endl;
    while (dIt < this->dC.end())
    {
        std::cout << *dIt << std::endl;
        ++dIt;
    }
}

bool	PmergeMe::isNumber(const std::string& s) {

	if (s.empty())
		return (false);
	size_t start = 0;
	if (s[0] == '-' || s[0] == '+')
		start = 1;
	if (start == s.size())
		return (false);
	for (size_t i = start; i < s.size(); ++i) {
		if (!isdigit(s[i]))
			return (false);
	}
	return (true);
}

bool PmergeMe::isSmallNum(const std::string& s) {

    if (s.empty())
        return (false);
    if (!isNumber(s))
        return (false);

    errno = 0;
    char* endptr;
    long long val = strtoll(s.c_str(), &endptr, 10);

    if (*endptr != '\0' || errno == ERANGE)
        return (false);

    if (val < INT_MIN || val > INT_MAX)
        return (false);

    return (true);
}

bool    PmergeMe::getArguments(int argc, char **argv) {

    for (int i = 1; i < argc; i++)
    {
        if (!isSmallNum(argv[i]))
            return (false);
        this->vC.push_back(atoi(argv[i]));
        this->dC.push_back(atoi(argv[i]));
    }
    return (true);
}
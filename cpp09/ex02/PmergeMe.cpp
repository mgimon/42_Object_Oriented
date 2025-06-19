
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

const std::deque<int>  PmergeMe::getContainerD() const { return (this->dC); }

const std::vector<int>  PmergeMe::getContainerV() const { return (this->vC); }


void    PmergeMe::printContainerD(const std::deque<int> &dC) const {

    std::deque<int>::const_iterator  dIt = dC.begin();

    std::cout << std::endl;
    std::cout << GRAY << "### Printing deque ###" << RESET << std::endl;
    while (dIt < dC.end())
    {
        std::cout << *dIt << std::endl;
        ++dIt;
    }
}

void    PmergeMe::printContainerV(const std::vector<int> &vC) const {

    std::vector<int>::const_iterator vIt = vC.begin();

    std::cout << std::endl;
    std::cout << GRAY << "### Printing vector ###" << RESET << std::endl;
    while (vIt < vC.end())
    {
        std::cout << *vIt << std::endl;
        ++vIt;
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

std::vector<int>    vcExtractMaxs(std::vector<int> vC) {
    
}

std::vector<int>    vcExtractMins(std::vector<int> vC) {
    
}

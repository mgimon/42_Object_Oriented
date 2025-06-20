
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

std::vector<int>    PmergeMe::vcExtractMaxs(std::vector<int> vC) {
    std::vector<int>            extraction;
    int                         stop;

    if (vC.size() % 2 == 0)
        stop = 1;
    else
        stop = 2;
    for (size_t i = 0; i < vC.size() - stop; i += 2)
    {
            if (vC[i] > vC[i + 1])
                extraction.push_back(vC[i]);
            else
                extraction.push_back(vC[i + 1]);
    }
    return (extraction);
}

std::vector<int>    PmergeMe::vcExtractMins(std::vector<int> vC) {
    std::vector<int>            extraction;
    int                         stop;

    if (vC.size() % 2 == 0)
        stop = 1;
    else
        stop = 2;
    for (size_t i = 0; i < vC.size() - stop; i += 2)
    {
            if (vC[i] < vC[i + 1])
                extraction.push_back(vC[i]);
            else
                extraction.push_back(vC[i + 1]);
    }
    return (extraction);
}

int PmergeMe::findInsertPosition(std::vector<int> sorted, int number) {

    for (int i = 0; i < (int)sorted.size(); i++)
    {
        if (number <= sorted[i])
            return (i);
    }
    return (sorted.size());
}

std::vector<int>    PmergeMe::vcSort(std::vector<int> vC) {

    std::vector<int>    sortedMaxs;
    int                 pos;
    int                 odd = 0;

    if (vC.size() <= 1)
        return (vC);
    std::vector<int>    maxs = vcExtractMaxs(vC);
    std::vector<int>    mins = vcExtractMins(vC);
    if (vC.size() % 2 != 0)
        odd = vC.back();
    
    sortedMaxs = vcSort(maxs); // recursion-sort maxs

    // find pos and insert mins
    for (std::vector<int>::iterator it = mins.begin(); it < mins.end(); ++it)
    {
        pos =  findInsertPosition(sortedMaxs, *it);
        sortedMaxs.insert(sortedMaxs.begin() + pos, *it);
    }
    // find pos and insert lonely element (if odd array)
    if (odd)
    {
        pos =  findInsertPosition(sortedMaxs, odd);
        sortedMaxs.insert(sortedMaxs.begin() + pos, odd);
    }
    
    return (sortedMaxs);
}


#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): N(0) {}

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

int PmergeMe::getN() const { return (this->N); }

const std::deque<int>  PmergeMe::getContainerD() const { return (this->dC); }

const std::vector<int>  PmergeMe::getContainerV() const { return (this->vC); }


void    PmergeMe::printContainerD(const std::string& word, const std::deque<int> &dC) const {

    std::deque<int>::const_iterator  dIt = dC.begin();

    std::cout << GRAY << word << ": ";
    while (dIt < dC.end())
    {
        std::cout << *dIt << " ";
        ++dIt;
    }
    std::cout << RESET << std::endl;
}

void    PmergeMe::printContainerV(const std::string& word, const std::vector<int> &vC) const {

    std::vector<int>::const_iterator vIt = vC.begin();

    std::cout << GRAY << word << ": ";
    while (vIt < vC.end())
    {
        std::cout << *vIt << " ";
        ++vIt;
    }
    std::cout << RESET << std::endl;
}

void    PmergeMe::printTime(const std::string& word, int number, timeval start, timeval end)
{
    double      time;

    time = (end.tv_sec - start.tv_sec) * 1000.0 +  // get ms
            (end.tv_usec - start.tv_usec) / 1000.0; // gets microseconds

    std::cout << "Time to process an array of " << number << " numbers using " << word << " : " << GREEN << time * 1000.0 << " microseconds (" << time << ") milliseconds" << RESET << std::endl;
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

    if (val < INT_MIN || val > INT_MAX || val < 0)
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
        this->N++;
    }
    return (true);
}

// ************************* VECTOR IMPLEMENTATIONS ************************* //

std::vector<int>    PmergeMe::vcExtractMaxs(const std::vector<int>& vC) {
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

std::vector<int>    PmergeMe::vcExtractMins(const std::vector<int>& vC) {
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

std::vector<int> PmergeMe::vcSort(const std::vector<int>& vC) {

    if (vC.size() <= 1)
        return (vC);

    std::vector<int> maxs = vcExtractMaxs(vC);
    std::vector<int> mins = vcExtractMins(vC);
    std::vector<int> sortedMaxs = vcSort(maxs); // recursion

    // binary insertion
    for (std::vector<int>::iterator it = mins.begin(); it < mins.end(); ++it)
        sortedMaxs.insert(std::lower_bound(sortedMaxs.begin(), sortedMaxs.end(), *it), *it);

    if (vC.size() % 2 != 0)
        sortedMaxs.insert(std::lower_bound(sortedMaxs.begin(), sortedMaxs.end(), vC.back()), vC.back());

    return (sortedMaxs);
}


// ************************* DEQUE IMPLEMENTATIONS ************************* //

std::deque<int>    PmergeMe::dcExtractMaxs(const std::deque<int>& dC) {
    std::deque<int>            extraction;
    int                         stop;

    if (dC.size() % 2 == 0)
        stop = 1;
    else
        stop = 2;
    for (size_t i = 0; i < dC.size() - stop; i += 2)
    {
            if (dC[i] > dC[i + 1])
                extraction.push_back(dC[i]);
            else
                extraction.push_back(dC[i + 1]);
    }
    return (extraction);
}

std::deque<int>    PmergeMe::dcExtractMins(const std::deque<int>& dC) {
    std::deque<int>            extraction;
    int                         stop;

    if (dC.size() % 2 == 0)
        stop = 1;
    else
        stop = 2;
    for (size_t i = 0; i < dC.size() - stop; i += 2)
    {
            if (dC[i] < dC[i + 1])
                extraction.push_back(dC[i]);
            else
                extraction.push_back(dC[i + 1]);
    }
    return (extraction);
}

std::deque<int> PmergeMe::dcSort(const std::deque<int>& dC) {

    if (dC.size() <= 1)
        return (dC);

    std::deque<int> maxs = dcExtractMaxs(dC);
    std::deque<int> mins = dcExtractMins(dC);

    std::deque<int> sortedMaxs = dcSort(maxs); // recursion

    // binary insertion
    for (std::deque<int>::iterator it = mins.begin(); it < mins.end(); ++it)
        sortedMaxs.insert(std::lower_bound(sortedMaxs.begin(), sortedMaxs.end(), *it), *it);

    if (dC.size() % 2 != 0)
        sortedMaxs.insert(std::lower_bound(sortedMaxs.begin(), sortedMaxs.end(), dC.back()), dC.back());

    return (sortedMaxs);
}


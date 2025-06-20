#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <sstream>
#include <limits>
#include <algorithm>
#include <vector>
#include <deque>
#include <fstream>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"


class PmergeMe {
    private:
        std::vector<int>    vC;
        std::deque<int>     dC;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator = (const PmergeMe& ref);
        ~PmergeMe();

        bool	isNumber(const std::string& s);
        bool    isSmallNum(const std::string& s);
        bool    getArguments(int argc, char **argv);
        void    printContainerD(const std::deque<int> &dC) const;
        void    printContainerV(const std::vector<int> &vC) const;
        const std::deque<int>  getContainerD() const;
        const std::vector<int>  getContainerV() const;

        std::vector<int>    vcExtractMaxs(std::vector<int> vC);
        std::vector<int>    vcExtractMins(std::vector<int> vC);
        int                 findInsertPosition(std::vector<int> sorted, int number);
        std::vector<int>    vcSort(std::vector<int> vC);
};

#endif

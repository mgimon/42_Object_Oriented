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
        int                 N;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& ref);
        PmergeMe& operator = (const PmergeMe& ref);
        ~PmergeMe();

        // Prints
        void    printContainerD(const std::string& word, const std::deque<int> &dC) const;
        void    printContainerV(const std::string& word, const std::vector<int> &vC) const;
        void    printTime(const std::string& word, int number, timeval start, timeval end);

        // Utils
        bool	isNumber(const std::string& s);
        bool    isSmallNum(const std::string& s);
        bool    getArguments(int argc, char **argv);

        const std::deque<int>   getContainerD() const;
        const std::vector<int>  getContainerV() const;
        int                     getN() const;

        // Algo - Vector
        std::vector<int>    vcExtractMaxs(const std::vector<int>& vC);
        std::vector<int>    vcExtractMins(const std::vector<int>& vC);
        std::vector<int>    vcSort(const std::vector<int>& vC);

        // Algo - Deque
        std::deque<int>    dcExtractMaxs(const std::deque<int>& dC);
        std::deque<int>    dcExtractMins(const std::deque<int>& dC);
        std::deque<int>    dcSort(const std::deque<int>& dC);

};

#endif

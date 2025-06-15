#ifndef RPN_HPP
#define RPN_HPP

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
#include <stack>
#include <fstream>

#define RED     "\033[31m"
#define GRAY    "\033[90m"
#define YELLOW	"\033[33m"
#define RESET   "\033[0m"
#define GREEN   "\033[32m"

class RPN {
	private:

		std::stack<int>	myStack;
		long			result;

	public:

		RPN();
		RPN(const RPN& ref);
		RPN& operator = (const RPN& ref);
		~RPN();

		bool	isOperator(const std::string& str);
		bool	isSmallNum(const std::string& str);
		bool	isValid(const std::string& str);
		bool	tooManySpaces(const std::string& str);
		bool	isNumber(const std::string& s);

		const long&	getResult() const;
		bool	executeStr(const std::string& str);

};

#endif

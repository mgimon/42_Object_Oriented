#include "RPN.hpp"

RPN::RPN() : result(0) {}

RPN::RPN(const RPN& ref) : nCount(ref.nCount), myStack(ref.myStack), result(ref.result) {}

RPN& RPN::operator = (const RPN& ref) {
	if (this != &ref)
	{
		this->nCount = ref.nCount;
		this->myStack = ref.myStack;
		this->result = ref.result;
	}
	return (*this);
}

RPN::~RPN() {}

const long&	RPN::getResult() const { return (this->result); }

bool isNumber(const std::string& s) {

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

bool	RPN::isOperator(const std::string& str) {
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return (true);
	return (false);
}

// checks also spaces
bool	RPN::parseStr(const std::string& str) {
	std::istringstream	ss(str);
	std::string			token;

	if (!isValid(str))
		return (std::cout << RED << "Invalid arguments!" << RESET << std::endl, false);
	while (ss >> token)
	{
		if (isNumber(token))
		{
			this->myStack.push(std::atoi(token.c_str()));
			this->nCount++;
		}
		else if (isOperator(token))
		{
			int M = myStack.top(); myStack.pop();
			int N = myStack.top(); myStack.pop();
			long result;

			switch (token[0]) {
				case '+': result = N + M; break;
				case '-': result = N - M; break;
				case '*': result = N * M; break;
				case '/': 
				if (M == 0) {
					return (std::cout << RED << "Cannot divide by 0!" << RESET << std::endl, false); break; }
				result = N / M; break;
			}
			myStack.push(result);
		}
	}
	this->result = myStack.top();
	return (true);
}

bool	RPN::isSmallNum(const std::string& str) {

	long l = std::atol(str.c_str());

	if (l <= INT_MAX)
		return (true);
	return (false);
}

bool	RPN::isValid(const std::string& str) {
	std::istringstream	ss(str);
	std::string			token;
	int					numbers = 0;

	while (ss >> token)
	{
		if (numbers >= 10)
			return (false);
		if (!isNumber(token) && !isOperator(token))
			return (false);
		if (isNumber(token))
		{
			if (!isSmallNum(token))
				return (false);
			numbers++;
		}
	}
	return (true);
}

#include "RPN.hpp"

RPN::RPN() : result(0) {}

RPN::RPN(const RPN& ref) : myStack(ref.myStack), result(ref.result) {}

RPN& RPN::operator = (const RPN& ref) {
	if (this != &ref)
	{
		this->myStack = ref.myStack;
		this->result = ref.result;
	}
	return (*this);
}

RPN::~RPN() {}

const long&	RPN::getResult() const { return (this->result); }

bool	RPN::isNumber(const std::string& s) {

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


bool	RPN::executeStr(const std::string& str) {

	std::istringstream	ss(str);
	std::string			token;
	int					M;
	int					N;

	if (!isValid(str)) // parsing here
		return (std::cerr << RED << "Invalid arguments!" << RESET << std::endl, false);
	while (ss >> token)
	{
		if (isNumber(token))
			this->myStack.push(std::atoi(token.c_str()));
		else if (isOperator(token))
		{
			if (this->myStack.size() > 0)
			{
				M = myStack.top();
				myStack.pop();
			}
			else
				return (std::cerr << RED << "The pile is empty!" << RESET << std::endl, false);
			if (this->myStack.size() > 0)
			{
				N = myStack.top();
				myStack.pop();
			}
			else
				return (std::cerr << RED << "The pile is empty!" << RESET << std::endl, false);

			long result;

			switch (token[0]) {
				case '+': result = N + M; break;
				case '-': result = N - M; break;
				case '*': result = N * M; break;
				case '/': 
				if (M == 0) {
					return (std::cerr << RED << "Cannot divide by 0!" << RESET << std::endl, false); break; }
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

	if (l > INT_MAX || l < INT_MIN)
		return (false);
	return (true);
}

bool	RPN::tooManySpaces(const std::string& str)
{
	int	space = 0;
	int	i = 0;

	while(str[i])
	{
		if (std::isspace(str[i]))
		{
			space++;
			if (space > 1)
				return (true);
		}
		else
			space--;
		i++;
	}
	if (str[0] && str[0] == ' ' && str.length() == 1)
		return (true);
	return (false);
}

bool	RPN::isValid(const std::string& str) {
	std::istringstream	ss(str);
	std::string			token;
	int					numbers = 0;

	if (tooManySpaces(str))
		return (false);
	while (ss >> token)
	{
		if (numbers >= 20)
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

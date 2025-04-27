#ifndef GENERALEXCEPTION_HPP
#define GENERALEXCEPTION_HPP

#include "Bureaucrat.hpp"

class GeneralException : public std::exception {
	public:
		const char* what() const throw() {
			return "GeneralException: ";
		}
};

#endif

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <fstream>
#include <string>

class Brain {

    protected:
        std::string ideas[100];
    public:
    	Brain();
		Brain(Brain& ref);
		Brain& operator = (Brain& ref);
		~Brain();

		void		setIdeaInIdeas(int const n, std::string const idea);
		std::string	getIdeafromIdeas(int const n) const;
		void		printIdeas();
};

#endif
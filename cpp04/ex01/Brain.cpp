#include "Brain.hpp"

Brain::Brain() {
    std::cout << "A brain was created" << std::endl;
};

Brain::Brain(Brain& ref) {
	for (int i = 0; i < 100; i++)
        this->ideas[i] = ref.ideas[i];
}

Brain& Brain::operator = (Brain& ref) {
    if (this != &ref) {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = ref.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "A brain was destroyed" << std::endl;
};

void    Brain::setIdeaInIdeas(int const n, std::string const idea) {
    this->ideas[n] = idea;
}

std::string Brain::getIdeafromIdeas(int const n) const {
    return (this->ideas[n]);
}

void    Brain::printIdeas() {
    for (int i = 0; i < 100; i++)
    {
        if (!ideas[i].empty())
            std::cout << "Idea " << i << ": " << ideas[i] << std::endl;
    }
}
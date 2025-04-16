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
    std::cout << "A brain was deleted" << std::endl;
};
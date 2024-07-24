#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout <<"Dog Default Constructor" <<std::endl;
    brain = new Brain;
}

Dog::~Dog() {
    std::cout <<"Dog Destructor" <<std::endl;
    delete brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout <<"Dog Copy Constructor" <<std::endl;
    brain = new Brain;
    for(int i = 0; i < 100; i++){
        this->brain->ideas[i] = other.brain->ideas[i];
    }
}

Dog &Dog::operator=(const Dog &other) {
    std::cout <<"Dog assignment Operator" <<std::endl;
    Animal::operator=(other);
    this->brain = new Brain;
    for(int i = 0; i < 100; i++){
        this->brain->ideas[i] = other.brain->ideas[i];
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "INU DESU" << std::endl;
}

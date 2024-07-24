#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout <<"Cat Constructor" <<std::endl;
    brain = new Brain();
}

Cat::~Cat() {
    std::cout <<"Cat Destructor" <<std::endl;
    delete brain;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout <<"Cat Copy Constructor" <<std::endl;
    brain = new Brain();
    for(int i = 0; i < 100; i++){
        this->brain->ideas[i] = other.brain->ideas[i];
    }
}

Cat &Cat::operator=(const Cat &other) {
    std::cout <<"Cat Assignment Operator" <<std::endl;
    Animal::operator=(other);
    this->brain = new Brain();
    for(int i = 0; i < 100; i++){
        this->brain->ideas[i] = other.brain->ideas[i];
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "NEKO DESU" << std::endl;
}

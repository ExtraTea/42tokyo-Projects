#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout <<"Cat Constructor" <<std::endl;
}

Cat::~Cat() {
    std::cout <<"Cat Destructor" <<std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout <<"Cat Copy Constructor" <<std::endl;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout <<"Cat Assignment Operator" <<std::endl;
    Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const {
    std::cout << "NEKO DESU" << std::endl;
}

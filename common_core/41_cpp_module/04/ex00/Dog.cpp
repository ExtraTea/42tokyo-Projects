#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout <<"Dog Default Constructor" <<std::endl;
}
Dog::~Dog() {
    std::cout <<"Dog Destructor" <<std::endl;
}
Dog::Dog(const Dog &other) : Animal(other) {
    std::cout <<"Dog Copy Constructor" <<std::endl;
}
Dog &Dog::operator=(const Dog &other) {
    std::cout <<"Dog assignment Operator" <<std::endl;
    Animal::operator=(other);
    return *this;
}
void Dog::makeSound() const {
    std::cout << "INU DESU" << std::endl;
}

#include "Animal.hpp"

Animal::Animal() : type("Unknown") {
    std::cout <<"Animal Default Constructor" <<std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
    std::cout <<"Animal Constructor" <<std::endl;
}

Animal::~Animal() {
    std::cout <<"Animal Destructor" <<std::endl;
}
Animal::Animal(const Animal &animal) : type(animal.type) {
    std::cout <<"Animal Copy Constructor" <<std::endl;
}
Animal &Animal::operator=(const Animal &animal) {
    std::cout <<"Animal assignment operator" <<std::endl;
    if (this != &animal) {
        type = animal.type;
    }
    return *this;
}
std::string Animal::getType() const {
    return (this->type);
}

void Animal::makeSound() const {
    std::cout << "ANIMAL DESU" << std::endl;
}
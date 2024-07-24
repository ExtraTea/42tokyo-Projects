#include "FakeAnimal.hpp"

FakeAnimal::FakeAnimal() : type("Unknown") {
    std::cout <<"FakeAnimal Default Constructor" <<std::endl;
}

FakeAnimal::FakeAnimal(const std::string& type) : type(type) {
    std::cout <<"FakeAnimal Constructor" <<std::endl;
}

FakeAnimal::~FakeAnimal() {
    std::cout <<"FakeAnimal Destructor" <<std::endl;
}
FakeAnimal::FakeAnimal(const FakeAnimal &animal) : type(animal.type) {
    std::cout <<"FakeAnimal Copy Constructor" <<std::endl;
}
FakeAnimal &FakeAnimal::operator=(const FakeAnimal &animal) {
    std::cout <<"FakeAnimal assignment operator" <<std::endl;
    if (this != &animal) {
        type = animal.type;
    }
    return *this;
}
std::string FakeAnimal::getType() const {
    return (this->type);
}

void FakeAnimal::makeSound() const {
    std::cout << "ANIMAL DESU" << std::endl;
}
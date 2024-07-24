#include "FakeCat.hpp"

FakeCat::FakeCat() : FakeAnimal("FakeCat") {
    std::cout <<"FakeCat Constructor" <<std::endl;
}

FakeCat::~FakeCat() {
    std::cout <<"FakeCat Destructor" <<std::endl;
}

FakeCat::FakeCat(const FakeCat &other) : FakeAnimal(other) {
    std::cout <<"FakeCat Copy Constructor" <<std::endl;
}

FakeCat &FakeCat::operator=(const FakeCat &other) {
    std::cout <<"FakeCat Assignment Operator" <<std::endl;
    FakeAnimal::operator=(other);
    return *this;
}

void FakeCat::makeSound() const {
    std::cout << "NEKO DESU" << std::endl;
}

#ifndef FAKECAT_HPP
#define FAKECAT_HPP

#include "FakeAnimal.hpp"

class FakeCat : public FakeAnimal {
public:
    FakeCat();
    ~FakeCat();
    FakeCat(const FakeCat &other);
    FakeCat &operator=(const FakeCat &other);
    void makeSound() const;
};

#endif
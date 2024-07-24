#ifndef FAKEANIMAL_HPP
#define FAKEANIMAL_HPP

#include <string>
#include <iostream>

class FakeAnimal {
protected:
    std::string type;

public:
    FakeAnimal();
    FakeAnimal(const std::string& type = "Unknown");
    virtual ~FakeAnimal();
    FakeAnimal(const FakeAnimal &animal);
    FakeAnimal &operator=(const FakeAnimal &animal);
    std::string getType() const;
    void makeSound() const;
};

#endif

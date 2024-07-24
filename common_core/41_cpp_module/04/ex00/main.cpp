#include "Dog.hpp"
#include "Cat.hpp"
#include "FakeCat.hpp"

int main() {
    std::cout <<"-----HONMONO ANIMAL AREA-----" <<std::endl;
    const Animal* meta = new Animal("Generic Animal");
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;
    std::cout <<"-----USO ANIMAL AREA-----" <<std::endl;
    const FakeAnimal* fmeta = new FakeAnimal("Generic Animal Modoki");
    const FakeAnimal* fi = new FakeCat();

    std::cout << fi->getType() << std::endl;

    fi->makeSound();
    fmeta->makeSound();

    delete fi;
    delete fmeta;
    return 0;
}
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* i = new Dog;
    const Animal* j = new Cat;

    delete i;
    delete j;
    return 0;
}

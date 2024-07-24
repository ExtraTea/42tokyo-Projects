#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* i = new Dog;
    const Animal* j = new Cat;

    delete i;
    delete j;
    // Dog basic;
    // {
    // Dog tmp = basic;
    // }
    return 0;
}

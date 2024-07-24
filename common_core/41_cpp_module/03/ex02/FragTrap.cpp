#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Unknown", 100, 50, 20) {
	this->codename = "FragTrap ";
	std::cout <<"FragTrap default constructor called." <<std::endl;
}

FragTrap::FragTrap(const std::string &name, const int hit, const int energy, const int attack)
		: ClapTrap(name, hit, energy, attack) {
	this->codename = "FragTrap ";
	std::cout <<"FragTrap constructor called." <<std::endl;
}

FragTrap::~FragTrap(){
	std::cout <<"FragTrap destructor called." <<std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout <<"FragTrap copy constructor called." <<std::endl;
	this->codename = "FragTrap ";
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	std::cout <<"FragTrap assignment operator called." <<std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
	this->codename = "FragTrap ";
    return *this;
}

void FragTrap::highFiveGuys(){
	std::cout <<"HIGH FIVE!" <<std::endl;
}

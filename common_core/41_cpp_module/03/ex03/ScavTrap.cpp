#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Unknown", 100, 50, 20) {
	this->codename = "ScavTrap ";
}

ScavTrap::ScavTrap(const std::string &name, const int hit, const int energy, const int attack)
		: ClapTrap(name, hit, energy, attack) {
	this->codename = "ScavTrap ";
}

ScavTrap::~ScavTrap(){
	std::cout <<"Destructor called." <<std::endl;
}

void ScavTrap::guardGate(){
	std::cout <<codename <<"is now in Gate keeper mode." <<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	this->codename = "ScavTrap ";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
    if (this != &other) {
        ClapTrap::operator=(other);
    }
	this->codename = "ScavTrap ";
    return *this;
}
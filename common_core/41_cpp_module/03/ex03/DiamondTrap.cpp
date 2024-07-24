#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name", 100, 50, 20) {
	this->codename = "DiamondTrap ";
	std::cout <<"DiamondTrap default constructor called." <<std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name, const int hit, const int energy, const int attack)
		: ClapTrap(name, hit, energy, attack) {
	this->name = ClapTrap::name;
	ClapTrap::name.append("_clap_name");
	this->codename = "DiamondTrap ";
	std::cout <<"DiamondTrap constructor called." <<std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout <<"DiamondTrap destructor called." <<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other) {
	std::cout <<"DiamondTrap copy constructor called." <<std::endl;
	this->codename = "DiamondTrap ";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other){
	std::cout <<"DiamondTrap assignment operator called." <<std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
	this->codename = "DiamondTrap ";
    return *this;
}

void DiamondTrap::whoAmI(){
	std::cout <<"I am " <<this->name <<" and " <<ClapTrap::name <<std::endl;
}

// void attack(const std::string& target){
// 	FragTrap::attack(target);
// }
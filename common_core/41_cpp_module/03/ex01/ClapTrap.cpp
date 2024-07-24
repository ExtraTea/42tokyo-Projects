#include "ClapTrap.hpp"

ClapTrap *ClapTrap::now = NULL;

ClapTrap::ClapTrap() : name("Unknown"), hit_point(10), energy_point(10), attack_damage(0), codename("ClapTrap "){
	this->next = now;
	now = this;
	std::cout <<"Default constructor called." <<std::endl;
}

ClapTrap::ClapTrap(const std::string &name, const int hit, const int energy, const int attack){
	std::cout <<"Normal constructor called." <<std::endl;
	this->name = name;
	this->hit_point = hit;
	this->energy_point = energy;
	this->attack_damage = attack;
	this->next = now;
	this->codename = "ClapTrap ";
	now = this;
}

ClapTrap::~ClapTrap(){
	std::cout <<"Destructor called." <<std::endl;
	ClapTrap** ptr = &now;
	while (*ptr && *ptr != this) {
		ptr = &(*ptr)->next;
	}
	if (*ptr) {
		*ptr = this->next;
	}
}

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout <<"Copy constructor called." <<std::endl;
	this->name = other.name;
	this->hit_point = other.hit_point;
	this->energy_point = other.energy_point;
	this->attack_damage = other.attack_damage;
	this->next = now;
	this->codename = other.codename;
	now = this;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
        if (this != &other) {
            std::cout << "Assignment operator called." << std::endl;
            name = other.name;
            hit_point = other.hit_point;
            energy_point = other.energy_point;
            attack_damage = other.attack_damage;
			codename = other.codename;
        }
        return *this;
    }

void ClapTrap::attack(const std::string &target){
	if (this->hit_point <= 0){
		std::cout <<this->name <<" is dead." <<std::endl;
		return ;
	}
	if (this->energy_point <= 0){
		std::cout <<this->name <<" has no energy." <<std::endl;
		return ;
	}
	this->energy_point--;
	ClapTrap *ptr = now;
	while (ptr != NULL){
		if (ptr->name.compare(target) == 0){
			ptr->takeDamage(this->attack_damage);
			std::cout <<codename <<this->name <<" attacks " <<target <<", causing " <<this->attack_damage <<" points of damage!" <<std::endl;
			return ;
		}
		ptr = ptr->next;
	}
	std::cout <<codename <<this->name <<" could not find " <<target <<std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->hit_point <= amount){
		this->hit_point = 0;
	}
	else{
		this->hit_point -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->hit_point <= 0){
		std::cout <<this->name <<" is dead." <<std::endl;
		return ;
	}
	if (this->energy_point <= 0){
		std::cout <<this->name <<" has no energy." <<std::endl;
		return ;
	}
	if (UINT_MAX - amount < this->hit_point){
		this->hit_point = UINT_MAX;
	}
	else{
		this->hit_point += amount;
	}
	this->energy_point--;
	std::cout <<codename <<this->name <<" was repaired by " <<amount <<std::endl;
}

void ClapTrap::printStatus(){
	std::cout <<"Name: " <<this->name <<std::endl;
	std::cout <<"HP  : " <<this->hit_point <<std::endl;
	std::cout <<"MP  : " <<this->energy_point <<std::endl;
	std::cout <<"ATT : " <<this->attack_damage <<std::endl;
}
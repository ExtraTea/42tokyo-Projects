#include "HumanA.h"

HumanA::HumanA() : name("unknown"), weapon(NULL) {};

HumanA::HumanA(std::string new_name, Weapon &new_weapon){
	name = new_name;
	weapon = &new_weapon;
}

HumanA::~HumanA(void){
}

void HumanA::attack(void){
	if (weapon == NULL)
		std::cout <<name <<" attacks with their fist" <<std::endl;
	else
		std::cout <<name <<" attacks with their " <<weapon->getType() <<std::endl;
}
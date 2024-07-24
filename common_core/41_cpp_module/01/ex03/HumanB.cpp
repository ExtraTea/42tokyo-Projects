#include "HumanB.h"

HumanB::HumanB() : name("unknown"), weapon(NULL) {};

HumanB::HumanB(std::string new_name){
	name = new_name;
	weapon = NULL;
}

HumanB::~HumanB(void){
}

void HumanB::attack(void){
	if (weapon)
		std::cout <<name <<" attacks with their " <<weapon->getType() <<std::endl;
	else
		std::cout <<name <<" attacks with their fist" <<std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon){
	weapon = &newWeapon;
}
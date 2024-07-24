#include "Weapon.h"

const std::string Weapon::getType(void){
	return (type);
}

void Weapon::setType(std::string s){
	type = s;
}

Weapon::Weapon() : type("fist") {}

Weapon::Weapon(std::string s){
	type = s;
}

Weapon::~Weapon(void){
}
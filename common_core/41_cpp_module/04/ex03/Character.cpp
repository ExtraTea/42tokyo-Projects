#include "Character.hpp"

Character::Character() : name("Unknown") {
	for(int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string name) : name(name) {
	for(int i = 0; i < 4; i++){
		this->inventory[i] = NULL;
	}
}

Character::~Character(){
	for(int i = 0; i < 4; i++){
		delete this->inventory[i];
	}
	unequip(-1);
}

Character::Character(const Character &other){
	this->name = other.getName();
	for(int i = 0; i < 4; i++){
		delete this->inventory[i];
		this->inventory[i] = other.getInventory(i)->clone();
	}
}

Character &Character::operator=(const Character &other){
	if (this != &other){
		this->name = other.getName();
		for(int i = 0; i < 4; i++){
			delete this->inventory[i];
			this->inventory[i] = other.getInventory(i)->clone();
		}
	}
	return (*this);
}

std::string const &Character::getName() const{
	return (this->name);
}

AMateria * Character::getInventory(int id) const{
	if (id < 0 || id > 3)
		return (NULL);
	return (this->inventory[id]);
}

void Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++){
		if (this->inventory[i] == NULL){
			this->inventory[i] = m;
			return ;
		}
	}
	return ;
}

void Character::unequip(int idx){
	static AMateria *leftover = NULL;

	delete leftover;
	leftover = NULL;
	if (idx < 0 || idx > 3){
		return ;
	}
	else{
		leftover = this->inventory[idx];
		this->inventory[idx] = NULL;
	}
	
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
		return ;
	this->inventory[idx]->use(target);
}

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++){
		inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource(){
	for(int i = 0; i < 4; i++){
		delete this->inventory[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &other){
	for(int i = 0; i < 4; i++){
		inventory[i] = other.getInventory(i);
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
	if (this != &other){
		for(int i = 0; i < 4; i++){
			inventory[i] = other.getInventory(i);
		}
	}
	return (*this);
}

AMateria * MateriaSource::getInventory(int id) const{
	if (id < 0 || id > 3)
		return (NULL);
	return (this->inventory[id]);
}

void MateriaSource::learnMateria(AMateria *mat){
	for(int i = 0; i < 4; i++){
		if (this->inventory[i] == NULL){
			this->inventory[i] = mat;
			return ;
		}
	}
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for(int i = 0; i < 4; i++){
		if (this->inventory[i]->getType().compare(type)){
			return this->inventory[i]->clone();
		}
	}
	return (NULL);
}
#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure(){
}

Cure::Cure(const Cure &other) : AMateria(other) {
	this->type = other.getType();
}

Cure &Cure::operator=(const Cure &other){
	if (this != &other){
		this->type = other.getType();
	}
	return (*this);
}

AMateria *Cure::clone() const{
	Cure *ret = new Cure(*this);
	return (ret);
}

void Cure::use(ICharacter &target){
	std::cout <<"* heals  " <<target.getName() <<"’s wounds *" <<std::endl;
}


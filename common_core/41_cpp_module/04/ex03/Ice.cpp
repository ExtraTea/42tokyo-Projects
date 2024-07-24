#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice(){
}

Ice::Ice(const Ice &other)  : AMateria(other)  {
	this->type = other.getType();
}

Ice &Ice::operator=(const Ice &other){
	if (this != &other){
		this->type = other.getType();
	}
	return (*this);
}

AMateria *Ice::clone() const{
	Ice *ret = new Ice(*this);
	return (ret);
}

void Ice::use(ICharacter &target){
	std::cout <<"* shoots an ice bolt at " <<target.getName() <<" *" <<std::endl;
}


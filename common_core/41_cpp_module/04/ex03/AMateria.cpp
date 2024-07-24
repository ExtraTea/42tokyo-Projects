#include "AMateria.hpp"

AMateria::AMateria() : type("Unknown") {}

AMateria::AMateria(std::string typea) : type(typea) {}

AMateria::~AMateria(){
}

AMateria::AMateria(const AMateria &other){
    this->type = other.getType();
}

AMateria &AMateria::operator=(const AMateria &other){
    if (this != &other){
        this->type = other.getType();
    }
    return (*this);
}

std::string const &AMateria::getType() const {
    return (this->type);
}


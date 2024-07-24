#include "Fixed.hpp"

Fixed::Fixed(void){
	setRawBits(0);
	std::cout <<"Default constructor called" <<std::endl;
};

Fixed::Fixed(const Fixed &obj){
	std::cout <<"Copy constructor called" <<std::endl;
	this->num = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout <<"Copy assignment operator called" <<std::endl;
	if (this != &other){
		this->num = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void){
	std::cout <<"Destructor called" <<std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout <<"getRawBits member function called" <<std::endl;
	return (num);
}

void Fixed::setRawBits(const int raw){
	num = raw;
}
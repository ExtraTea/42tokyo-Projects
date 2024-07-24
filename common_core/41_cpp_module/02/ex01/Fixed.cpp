#include "Fixed.hpp"

Fixed::Fixed(void){
	setRawBits(0);
	std::cout <<"Default constructor called" <<std::endl;
};

Fixed::Fixed(const Fixed &obj){
	std::cout <<"Copy constructor called" <<std::endl;
	*this = obj;
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

Fixed::Fixed(const int num){
	std::cout <<"Int constructor called" <<std::endl;
	this->num = num * (1<<bits);
}

Fixed::Fixed(const float num){
	std::cout <<"Float constructor called" <<std::endl;
	this->num = static_cast<int>(roundf(num * static_cast<float>(1 << bits)));
}

int Fixed::getRawBits(void) const{
	return (num);
}

void Fixed::setRawBits(const int raw){
	num = raw;
}

int Fixed::toInt(void) const{
	return (num / (1 << bits));
}

float Fixed::toFloat(void) const{
	return (static_cast<float>(num) / static_cast<float>(1 << bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed){
	os <<fixed.toFloat();
	return (os);
}
#include "Fixed.hpp"

Fixed::Fixed(void){
	setRawBits(0);
};

Fixed::Fixed(const Fixed &obj){
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &other){
	if (this != &other){
		this->num = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void){
}

Fixed::Fixed(const int num){
	this->num = num * (1<<bits);
}

Fixed::Fixed(const float num){
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

Fixed Fixed::operator+() const {
	return (*this);
}

Fixed Fixed::operator-() const {
	Fixed r;
	
	r.setRawBits(-1 * this->getRawBits());
	return (r);
}

Fixed Fixed::operator+(const Fixed &obj) const {
	Fixed r;

	r.setRawBits(this->getRawBits() + obj.getRawBits());
	return (r);
}

Fixed Fixed::operator-(const Fixed &obj) const {
	Fixed r;

	r.setRawBits(this->getRawBits() - obj.getRawBits());
	return (r);
}

Fixed Fixed::operator*(const Fixed &obj) const {
	Fixed r;

	int64_t tmp = static_cast<int64_t>(this->getRawBits()) * static_cast<int64_t>(obj.getRawBits());
	r.setRawBits(static_cast<int>(tmp >> this->bits));
	return (r);
}

Fixed Fixed::operator/(const Fixed &obj) const {
	Fixed r;
	
	if (obj.getRawBits() == 0){
		throw std::runtime_error("Division by zero");
	}
	int64_t tmp = (static_cast<int64_t>(this->getRawBits()) << this->bits);
	r.setRawBits(static_cast<int>(tmp / obj.getRawBits()));
	return (r);
}

bool Fixed::operator>(const Fixed &obj) const {
	if (this->getRawBits() > obj.getRawBits()){
		return (true);
	}
	else{
		return (false);
	}
}

bool Fixed::operator<(const Fixed &obj) const {
	if (this->getRawBits() < obj.getRawBits()){
		return (true);
	}
	else{
		return (false);
	}
}

bool Fixed::operator>=(const Fixed &obj) const {
	if (this->getRawBits() >= obj.getRawBits()){
		return (true);
	}
	else{
		return (false);
	}
}

bool Fixed::operator<=(const Fixed &obj) const {
	if (this->getRawBits() <= obj.getRawBits()){
		return (true);
	}
	else{
		return (false);
	}
}

bool Fixed::operator==(const Fixed &obj) const {
	if (this->getRawBits() == obj.getRawBits()){
		return (true);
	}
	else{
		return (false);
	}
}

bool Fixed::operator!=(const Fixed &obj) const {
	if (this->getRawBits() != obj.getRawBits()){
		return (true);
	}
	else{
		return (false);
	}
}

Fixed &Fixed::operator++(){
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int){
	Fixed r;

	r.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() + 1);
	return (r);
}

Fixed &Fixed::operator--(){
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed r;

	r.setRawBits(this->getRawBits());
	this->setRawBits(this->getRawBits() - 1);
	return (r);
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2) {
	if (obj1.getRawBits() < obj2.getRawBits()){
		return (obj1);
	}
	else{
		return (obj2);
	}
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.getRawBits() < obj2.getRawBits()){
		return (obj1);
	}
	else{
		return (obj2);
	}
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2) {
	if (obj1.getRawBits() > obj2.getRawBits()){
		return (obj1);
	}
	else{
		return (obj2);
	}
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2) {
	if (obj1.getRawBits() > obj2.getRawBits()){
		return (obj1);
	}
	else{
		return (obj2);
	}
}
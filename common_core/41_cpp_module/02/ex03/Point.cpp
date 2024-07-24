#include "Point.hpp"
#include <iostream>

Point::Point() : x(Fixed(0)), y(Fixed(0)) {
};

Point::Point(const float a, const float b): x(Fixed(a)), y(Fixed(b)) {
}

Point::Point(const Point &p): x(p.x), y(p.y) {
}

Point &Point::operator=(const Point &p){
    (void)p;
    return (*this);
}

Point Point::operator-(const Point &other) const{
    return Point((this->get_x() - other.get_x()).toFloat(), (this->get_y() - other.get_y()).toFloat());
}

Point::~Point(){
}

const Fixed Point::get_x() const{
    return this->x;
}

const Fixed Point::get_y() const{
    return this->y;
}

bool Point::cross(const Point &other) const{
    if (this->get_x() * (other.get_y()) - this->get_y() * other.get_x() >= 0)
        return true;
    else
        return false;
}

bool Point::is_same(const Point &other) const{
    return (this->get_x() - other.get_x() == Fixed(0) && this->get_y() - other.get_y() == Fixed(0));
}
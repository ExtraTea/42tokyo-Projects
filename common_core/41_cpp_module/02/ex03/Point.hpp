#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point(const float a, const float b);
        Point(const Point &p);
        Point &operator=(const Point &p);
        ~Point();

        Point operator-(const Point &other) const;
        const Fixed get_x() const;
        const Fixed get_y() const;

        bool cross(const Point &other) const;
        bool is_same(const Point &other) const;
};

#endif
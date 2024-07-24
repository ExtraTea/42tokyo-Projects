#include "Point.hpp"
#include <iostream>
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(){
    Point p1 (0, 0);
    Point p2 (1, 1);
    Point p3 (1, -1);
    Point pp(0.5, 0.5);
    bsp(p1, p2, p3, pp);

}

bool bsp(Point const a, Point const b, Point const c, Point const point){
    if (a.is_same(b) || b.is_same(c) || c.is_same(a)){
        std::cout <<"Not even a triangle." <<std::endl;
        return (false);
    }
    else if (((b - a).cross(point - b) && (c - b).cross(point - c) && (a - c).cross(point - a)) ||
        (!(b - a).cross(point - b) && !(c - b).cross(point - c) && !(a - c).cross(point - a))){
        std::cout <<"Inside the triangle." <<std::endl;
        return (true);
    }
    else
        std::cout <<"Outside the triangle." <<std::endl;
    return (false);
}
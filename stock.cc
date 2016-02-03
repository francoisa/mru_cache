#include "circle.h"
#include <sstream>

Circle::Circle(const Circle& c) {
}

Circle::Circle(const Point& p, int r) : point(p), radius{r} {
}

double Circle::area() const {
  static const double pi = 3.1415927;
  double a = 2*radius*pi;
  return a;
}

Point Circle::center() const {
  return point;
}

void Circle::move(Point to) {
}

void Circle::draw() const {
}
 
void Circle::rotate(int angle) {
}
 
void Circle::print(std::ostream& o) const {
  o << "circle centered at " << point 
    << " with radius " << radius;
}

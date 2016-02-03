#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

class Circle : public Shape {
 public:
  Circle(const Point& p, int r);
  Circle(const Circle& c) = default;
  Circle& operator=(const Circle& c) = default;
  Circle(Circle&& c) = default;
  Circle& operator=(Circle&& c) = default;
  double area() const;
  Point center() const;
  void move(Point to);
  void draw() const;
  void rotate(int angle);
  ~Circle() {}
  void print(std::ostream& o) const;
 private:
  Point point;
  int radius;
};
#endif

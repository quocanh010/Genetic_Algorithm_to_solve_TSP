#include "Point.hh"
#include "math.h"

// Default constructor:  initializes the point to (0, 0).
Point::Point() {
  x_coord = 0;
  y_coord = 0;
  z_coord = 0;
}

// Initializes the point to (x, y).
Point::Point(double x, double y, double z) {
  x_coord = x;
  y_coord = y;
  z_coord = z;
}

// Destructor - Point allocates no dynamic resources.
Point::~Point() {
  // no-op
}

// Mutators:

void Point::setX(double val) {
  x_coord = val;
}

void Point::setY(double val) {
  y_coord = val;
}
void Point::setZ(double val) {
  z_coord = val;
}

// Accessors:

double Point::GetX() const{
  return x_coord;
}

double Point::GetY() const{
  return y_coord;
}

double Point::GetZ() const{
  return z_coord;
}

double Point::Distance(const Point& Cpoint) const
{
  return sqrt((Cpoint.GetX()-x_coord)*(Cpoint.GetX()-x_coord) + (Cpoint.GetY()-y_coord)*(Cpoint.GetY()-y_coord) + (Cpoint.GetZ()-z_coord)*(Cpoint.GetZ()-z_coord));
}

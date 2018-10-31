// A 2-dimensional point class!
// Coordinates are double-precision floating point.
class Point {

private:
  double x_coord;
  double y_coord;
  double z_coord;

public:
  // Constructors
  Point();                      // default constructor
  Point(double x, double y,double z);    // Three-argument constructor

  // Destructor
  ~Point();

  // Mutator methods
  void setX(double val);
  void setY(double val);
  void setZ(double val);
  double Distance (const Point&) const;
  // Accessor methods
  double GetX() const;
  double GetY() const;
  double GetZ() const;
};

//
// Created by Zachary Kurmas on 2019-07-23.
//

#ifndef GETTINGSTARTED_POINT2D_H
#define GETTINGSTARTED_POINT2D_H

#include <iostream>

namespace cis263 {

  class Point2D {

  private:
    double x;
    double y;

  public:

    Point2D(double x, double y) : x(x), y(y) {};

    // Notice that this constructor calls the other constructor.
    Point2D() : Point2D(0.0, 0.0) {};

    double getX() const { return x; }

    double getY() const { return y; }

    // Notice the use of "this" to distinguish between the instance variable x and the
    // local variable x.
    void setX(double x) { this->x = x; }

    void setY(double y) { this->y = y; }

    void translate(double dx, double dy) {
      x += dx;
      y += dy;
    }
  };

  // In C++ you can overload operators.
  std::ostream& operator<<(std::ostream& out, const Point2D& point) {
    return out << "(" << point.getX() << ", " << point.getY() << ")";
  }

}

#endif //GETTINGSTARTED_POINT2D_H

//
// Created by Zachary Kurmas on 2019-07-23.
//


#include <iostream>
#include "Point2D.h"

using namespace cis263;

// Unlike Java, the Point2D object will be passed by value:
// The local value `point` will be a copy of the object passed in.
// Any changes to the object will not have an effect in the calling method.
void brokenSlidePoint(Point2D point) {
  point.translate(1.0, 2.0);
  std::cout << "Point at the end of broken: " << point << std::endl;
}

// Using the `&` will pass the point by reference.  This behavior
// will be identical to Java.
void slidePointUsingReferences(Point2D& point) {
  point.translate(2.0, 4.0);
  std::cout << "Point at the end of slidPointUsingReferences: " << point << std::endl;
}

// References are relatively new to C++. The "old" way of passing an object by
// reference was to use a pointer.  In general, don't use a pointer unless you
// must.
void slidePointUsingPointers(Point2D *point) {
  point->translate(10.0, 20.0);

  // the '*' in front of '*point' means to return the object at the given memory location.
  std::cout << "Point at the end of slidePointUsingPointers: " << *point << std::endl;
}

int main(int argc, char *argv[]) {

  Point2D p1(10.0, 20.0);
  std::cout << "Initial point: " << p1 << std::endl;

  brokenSlidePoint(p1);
  std::cout << "After brokenSlidePoint " << p1 << std::endl;

  slidePointUsingReferences(p1);
  std::cout << "After slidePointUsingReferences " << p1 << std::endl;

  // Notice that the '&' below returns the memory address of the object -- a pointer.
  slidePointUsingPointers(&p1);
  std::cout << "After slidePointUsingPointers " << p1 << std::endl;

}

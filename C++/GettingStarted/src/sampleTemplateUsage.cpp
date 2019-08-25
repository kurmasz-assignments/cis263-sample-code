//
// Created by Zachary Kurmas on 2019-07-24.
//

#include <iostream>
#include "MyVector.h"
#include "Point2D.h"

using namespace cis263;

class Dummy {
  // This doesn't actually need to do anything.
};

int main(int argc, char* argv[]) {

  MyVector<int> intVector(4);
  intVector[0] = 33;
  intVector[1] = 77;
  intVector[2] = 29;
  intVector[3] = 44;

  std::cout << "intVector: " << intVector << std::endl;


  MyVector<double> doubleVector(4);
  doubleVector[0] = 33.1;
  doubleVector[1] = 77.2;
  doubleVector[2] = 29.3;
  doubleVector[3] = 44.4;

  std::cout << "doubleVector: " << doubleVector << std::endl;

  MyVector<Point2D> pointVector(4);
  pointVector[0] = Point2D(11.8, 5.4);
  pointVector[1] = Point2D(12.7, 4.1);
  pointVector[2] = Point2D(13.6, 3.2);
  pointVector[3] = Point2D(14.5, 2.9);

  std::cout << "pointVector: " << pointVector << std::endl;

  MyVector<Dummy> dummyVector(2);
  dummyVector[0] = Dummy();
  dummyVector[1] = Dummy();

  // This line won't compile because the "<<" operator isn't defined
  // for Dummy.  Notice that this error isn't detected until we actually
  // try to use the vector's << operator with a Dummy.
  // This is what can make template compiler errors very frustrating.
  // std::cout << "dummyVector: " << dummyVector << std::endl;


}

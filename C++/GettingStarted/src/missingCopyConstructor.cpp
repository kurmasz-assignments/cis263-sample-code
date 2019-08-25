//
// Created by Zachary Kurmas on 2019-07-24.
//

#include <iostream>

// Ignore the provided copy constructor and assignment operator and just use the C++ default.
#define EXCLUDE_COPY_CONSTRUCTOR
#define EXCLUDE_ASSIGNMENT_OPERATOR
#include "MyIntVector.h"

using namespace cis263;

void modifyLocalVector(MyIntVector local) {
  local[0] = -19;
}


int main(int argc, char *argv[]) {

  int size = 10;
  MyIntVector v1(size);

  for (int i = 0; i < size; ++i) {
    v1[i] = 3 * i;
  }

  std::cout << "Initial v1: " << v1 << std::endl;

  MyIntVector v2(v1);

  v2[size / 2] = -15;

  std::cout << "Updating v2 also modifies v1 since they share the same underlying array" <<
            std::endl;
  std::cout << "v2: " << v2 << std::endl;
  std::cout << "v1: " << v1 << std::endl;
  std::cout << std::endl;

  modifyLocalVector(v1);
  std::cout << "Likewise, modifyLocalVector does not have the expected 'pass-by-value' "
               "semantics:" << std::endl;
  std::cout << "(The local change to element 0 should not be visible here.)" << std::endl;
  std::cout << "v1: " << v1 << std::endl;
  std::cout << std::endl;

  // Notice I used two lines here instead of MyIntVector v3 = v1.
  // I did this so that the compiler would use the assignment operator instead of the copy
  // constructor.
  MyIntVector v3(size*2);
  v3 = v1;

  v3[size -1] = -100;
  std::cout << "Failing to oveload the = operator causes similar issues:" <<
            std::endl;
  std::cout << "v3: " << v3 << std::endl;
  std::cout << "v1: " << v1 << std::endl;
  std::cout << std::endl;
}

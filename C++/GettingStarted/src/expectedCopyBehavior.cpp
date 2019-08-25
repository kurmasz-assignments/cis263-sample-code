//
// Created by Zachary Kurmas on 2019-07-24.
//

#include "MyIntVector.h"

using namespace cis263;

void modifyLocalVector(MyIntVector local) {
  local[0] = -19;
}


int main(int argc, char *argv[]) {

  int size = 10;
  MyIntVector v1(size);
  MyIntVector v2(size*2);

  for (int i = 0; i < size; ++i) {
    v1[i] = 5 * i;
  }

  std::cout << "Initial v1: " << v1 << std::endl;

  v2 = v1;
  v2[size / 2] = -15;

  std::cout << "Now, changing v2 does not change v1" << std::endl;
  std::cout << "v2: " << v2 << std::endl;
  std::cout << "v1: " << v1 << std::endl;
  std::cout << std::endl;

  modifyLocalVector(v1);
  std::cout << "Likewise, modifyLocalVector now has the expected 'pass-by-value' "
               "semantics:" << std::endl;
  std::cout << "(The local change to element 0 is not be visible here.)" << std::endl;
  std::cout << "v1: " << v1 << std::endl;
  std::cout << std::endl;
}
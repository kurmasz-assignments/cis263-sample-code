//
// Created by Zachary Kurmas on 2019-09-11.
//

#include <iostream>

int main() {

  int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int dummy = 32231;

  int sum = 0;

  // The <= is bug that valgrind shoud detect
  for (int i = 0; i <= 10; ++i) {
    sum += array[i];
  }

  std::cout << "The sum is " << sum << " followed by " << dummy << std::endl;

}
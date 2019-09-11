//
// Created by Zachary Kurmas on 2019-09-11.
//
// To check for memory issues run
// valgrind --leak-check=yes [./name-of-executable]
// (remember the "./")
//

#include <vector>
#include <iostream>

int main() {

  std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int sum = 0;

  // The <= is bug that valgrind shoud detect
  for (int i = 0; i <= 10; ++i) {
    sum += array[i];
  }

  std::cout << "The sum is " << sum <<  std::endl;

}

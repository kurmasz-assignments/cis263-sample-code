//
// Created by Zachary Kurmas on 2019-09-10.
//
// To check for memory issues run
// valgrind --leak-check=yes [./name-of-executable]
// (remember the "./")
//

#include <iostream>

struct Pair {
  int x;
  int y;
};


int main() {

  Pair *a = new Pair{1, 2};
  Pair *b = new Pair{3, 4};
  Pair *c = new Pair{5, 6};

  delete a;
  // forgot to delete b
  delete c;

  std::cout << "When run through valgrind, you should see a memory leak of 8 bytes." << std::endl;

}
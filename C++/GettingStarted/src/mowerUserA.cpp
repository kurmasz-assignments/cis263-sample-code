#include <iostream>

#include "LawnMower.h"

// Notice that we specifically reference the namespace whenever we use cout and LawnMower

int main() {
  std::cout << "Hello, World!" << std::endl;

  // Notice we don't need the "new" keyword.
  lawn::LawnMower mower(3.0, 15000);

  std::cout << "How big is the lawn?" << std::endl;

  double lawnSize;
  std::cin >> lawnSize;

  mower.addGas(3.0);

  double sizeLeft = mower.mow(lawnSize);
  if (sizeLeft < .0000001) {
    std::cout << "We were able to mow all " << lawnSize << " sq. feet and still have " <<
      mower.gasLeft() << " gallons of gas left." << std::endl;
  } else {
    std::cout << "We ran out of gas with " << sizeLeft << " sq feet to go." << std::endl;
  }

  return 0;
}
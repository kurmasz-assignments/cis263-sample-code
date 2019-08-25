#include <iostream>

#include "LawnMower.h"

// Notice that the "using" construct allows us to reference items in the namespaces without
// qualification.  Use this feature with caution.  Sometimes it makes the code easier to read;
// sometimes it makes the code harder to read.
using namespace std;
using namespace lawn;

int main() {
  cout << "Hello, World!" << endl;

  LawnMower mower(3.0, 15000);

  cout << "How big is the lawn?" << endl;
  double lawnSize;
  cin >> lawnSize;

  mower.addGas(3.0);

  double sizeLeft = mower.mow(lawnSize);
  if (sizeLeft < .0000001) {
    cout << "We were able to mow all " << lawnSize << " sq. feet and still have " <<
      mower.gasLeft() << " gallons of gas left." << endl;
  } else {
    cout << "We ran out of gas with " << sizeLeft << " sq feet to go." << endl;
  }

  return 0;
}
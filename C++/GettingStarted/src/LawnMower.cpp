//
// Created by Zachary Kurmas on 2019-07-21.
//

#include "LawnMower.h"

namespace lawn {

  // Notice that instance variables are typically constructed *outside* the body of the
  // constructor.  (It is not unusual for a constructor to have an empty body.)
  LawnMower::LawnMower(double tankSize, double sqFeetPerGallon) : tankSize(tankSize),
  sqFeetPerGallon(sqFeetPerGallon), gasInTank(0.0) {};

  // This method has enough logic that it should probably be defined in the .cpp file.
  double LawnMower::mow(double size) {
    double gasNeeded = size/sqFeetPerGallon;

    if (gasNeeded < gasInTank) {
      gasInTank -= gasNeeded;
      return 0.0;
    } else {
      double amountMowed = gasInTank*sqFeetPerGallon;
      gasInTank = 0.0;
      return size - amountMowed;
    }
  }

  double LawnMower::addGas(double gallons) {

    if (gallons + gasInTank <= tankSize) {
      gasInTank += gallons;
      return gallons;
    } else {
      double amountAccepted = tankSize - gasInTank;
      gasInTank = tankSize;
      return amountAccepted;
    }
  }
}



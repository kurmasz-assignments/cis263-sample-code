//
// Created by Zachary Kurmas on 2019-07-21.
//

#ifndef GETTINGSTARTED_LAWNMOWER_H
#define GETTINGSTARTED_LAWNMOWER_H

namespace lawn {

class LawnMower {

private:
  double gasInTank;
  double tankSize;
  double sqFeetPerGallon;

public:
  LawnMower(double tankSize, double sqFeetPerGallon);

  // Simple methods can be implemented directly in the header file.
  double gasLeft() {
    return gasInTank;
  }

  double mow(double size);

  double addGas(double gallons);

};

}


#endif //GETTINGSTARTED_LAWNMOWER_H

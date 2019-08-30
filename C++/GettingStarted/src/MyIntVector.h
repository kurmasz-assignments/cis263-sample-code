//
// Created by Zachary Kurmas on 2019-07-24.
//

#ifndef GETTINGSTARTED_MYINTVECTOR_H
#define GETTINGSTARTED_MYINTVECTOR_H

#include <stdexcept>
#include <iostream>

namespace cis263 {
  class MyIntVector {

  private:
    int *data;
    int vectorSize;

  public:
    MyIntVector(int initialSize) : data(new int[initialSize]), vectorSize(initialSize) {}

    /*
      MyIntVector(int initialSize) {
        data = new int[initialSize];
        vectorSize = initialSize;
    }
     */

    // Use the macro to allow us to easily "remove" the copy constructor.
#ifndef EXCLUDE_COPY_CONSTRUCTOR

    MyIntVector(const MyIntVector &other) : data(new int[other.vectorSize]),
                                            vectorSize(other.vectorSize) {
      std::cout << "In copy constructor" << std::endl;
      for (int i = 0; i < vectorSize; i++) {
        data[i] = other.data[i];
      }
    }

#endif

#ifndef EXCLUDE_ASSIGNMENT_OPERATOR

    MyIntVector& operator=(const MyIntVector &other) {
      std::cout << "In assignment operator" << std::endl;

      int* newData = new int[other.vectorSize];
      for (int i = 0; i < other.vectorSize; i++) {
        newData[i] = other.data[i];
      }
      delete [] data;
      data = newData;
      vectorSize = other.vectorSize;
      return *this;
    }

#endif


    int size() const { return vectorSize; }

    int &operator[](int index) {
      if (index >= vectorSize) {
        throw std::runtime_error("Resizing not implemented yet.");
      }
      return data[index];
    }

    // Yes, sometimes const correctness leads us to cut-and-paste code.
    // See MyVector for an example of how to avoid cut-and-paste.
    // https://softwareengineering.stackexchange.com/questions/289853/const-c-dry-strategies
    const int &operator[](int index) const {
      if (index >= vectorSize) {
        throw std::runtime_error("Resizing not implemented yet.");
      }
      return data[index];
    }
  };

  std::ostream &operator<<(std::ostream &out, const MyIntVector &vec) {
    out << "{";
    if (vec.size() > 0) {
      out << vec[0];
    }
    for (int i = 1; i < vec.size(); ++i) {
      out << ", " << vec[i];
    }
    return out << "}";
  }
}


#endif //GETTINGSTARTED_MYINTVECTOR_H

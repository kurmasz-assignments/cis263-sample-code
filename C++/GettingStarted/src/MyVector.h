//
// Created by Zachary Kurmas on 2019-07-24.
//

#ifndef GETTINGSTARTED_MYVECTOR_H
#define GETTINGSTARTED_MYVECTOR_H

namespace cis263 {

  template<typename T>
  class MyVector {

    T *data;
    int vectorSize;

  public:
    MyVector(int initialSize) : data(new T[initialSize]), vectorSize(initialSize) {}

    MyVector(const MyVector &other) : data(new T[other.vectorSize]),
                                      vectorSize(other.vectorSize) {
      for (int i = 0; i < vectorSize; i++) {
        data[i] = other.data[i];
      }
    }

    MyVector &operator=(const MyVector &other) {

      T *newData = new T[other.vectorSize];
      for (int i = 0; i < other.vectorSize; i++) {
        newData[i] = other.data[i];
      }
      delete[] data;
      data = newData;
      vectorSize = other.vectorSize;
      return *this;
    }

    int size() const { return vectorSize; }

    // One example of how to avoid repeating code when the
    // const and non-const versions are nearly identical.
    // https://softwareengineering.stackexchange.com/questions/289853/const-c-dry-strategies
    T &operator[](int index) {
      return accessorImplementation(index);
    }

    const T &operator[](int index) const {
      return accessorImplementation(index);
    }

  private:

    T &accessorImplementation(int index) const {
      if (index >= vectorSize) {
        throw std::runtime_error("Resizing not implemented yet.");
      }
      return data[index];
    }

  };

  // This is a templatized function
  template<typename T>
  std::ostream &operator<<(std::ostream &out, const MyVector<T> &vec) {
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


#endif //GETTINGSTARTED_MYVECTOR_H

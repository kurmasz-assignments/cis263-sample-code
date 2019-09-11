//
// Created by Zachary Kurmas on 2019-09-10.
//

#include <iostream>
#include<vector>
#include<list>
#include<set>
#include<map>

using namespace std;



// Collection may not be empty
template<typename T, typename V>
V findMax(const T& dataStructure) {

   typename T::const_iterator i = dataStructure.begin();

  // Notice that we get the current value of *i, _then_ increment it.
  // *(++i) would give us the _second_ value in the list.
  V maxThusFar = *(i++);

  for (; i != dataStructure.end(); ++i) {
     if (*i > maxThusFar) {
       maxThusFar = *i;
     }
  }
  return maxThusFar;
}



int main() {

  vector<int> v1 = {4, 5, 9, 3, 2};
  cout << "Max in vector is " << findMax<vector<int>, int>(v1) << endl;

  list<int> l1 = {3, 2, 7, 8, 2, 1, 6};
  cout << "Max in list is " << findMax<list<int>, int>(l1) << endl;

  set<int> s1 = {4, 3, 1, 2, 6, 5, 0};
  cout << "Max in set is " << findMax<set<int>, int>(s1) << endl;


  // Notice that this won't compile, because for maps, *i isn't the value type, but a
  // pair
  //map<int, int> m1 = {{1, 31}, {2, 28}, {3, 31}, {4, 30}};
  //cout << "Max in set is " << findMax<map<int, int>, int>(m1) << endl;
}

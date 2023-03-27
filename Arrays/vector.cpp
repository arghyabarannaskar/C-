/* In C++, vectors are used to store elements of similar data types. However, unlike arrays, the size of a vector can grow dynamically.

Vectors are part of the C++ Standard Template Library. To use vectors, we need to include the vector header file in our program.


Once we include the header file, here's how we can declare a vector in C++:

std::vector<T> vector_name;
The type parameter <T> specifies the type of the vector. It can be any primitive data type such as int, char, float, etc. For example,

vector<int> num;
Here, num is the name of the vector.

Notice that we have not specified the size of the vector during the declaration. This is because the size of a vector can grow dynamically so it is not necessary to define it. */

#include<iostream>
#include<vector>
using namespace std;

int main(){
    // initializer list
  vector<int> vector1 = {1, 2, 3, 4, 5};

  // uniform initialization
  vector<int> vector2{6, 7, 8, 9, 10};

  // method 3
  vector<int> vector3(5, 12);

  cout << "vector1 = ";

  // ranged loop
  for (const int& i : vector1) {
    cout << i << "  ";
  }

  cout << "\nvector2 = ";

  // ranged loop
  for (const int& i : vector2) {
    cout << i << "  ";
  }

  cout << "\nvector3 = ";

  // ranged loop
  for (int i : vector3) {
    cout << i << "  ";
  }


    return 0;
}
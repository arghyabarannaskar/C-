#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vint{5, 6, 3, 7, 8, 54};
    cout << "Capacity: " << vint.capacity() << endl;
    cout << "size: " << vint.size() << endl;
    cout << &vint[0] << endl
         << &vint[1] << endl;

    return 0;
}
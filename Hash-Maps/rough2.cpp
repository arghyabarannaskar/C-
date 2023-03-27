#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    string name;
    int id;
    cout << "Please enter your id: \n";
    cin>>id;
    cout << "Enter your name: \n";
    getline(cin, name);

    cout << "your id is : " << id << "\n";
    cout << "Hello, " << name << " welcome to gfg.\n";
    getline(cin, name);

    cout << "Hello, " << name << " welcome to gfg.\n";

    return 0;
}
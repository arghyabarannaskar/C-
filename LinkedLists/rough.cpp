#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<string, int> m1{
        {"Rahul", 654},
        {"Aditi", 555},
        {"Salil", 455},
        {"Vibha", 470},
        {"Beena", 378},
    };

    cout << "total elements in m1: " << m1.size() << endl;
    cout << "Elements in map m1: " << endl;
    for(auto element: m1)
        cout << "Name: " << element.first << " Marks: " << element.second << endl;
    pair<string, int> p;
    p.first = "Shailesh";
    p.second = 665;
    m1.insert(p);

    return 0;
}
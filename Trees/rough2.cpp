#include<iostream>
#include<fstream>
using namespace std;


int main(){
    struct Employee{
        string name;
        int age;
        float basic, gross;
    };
    Employee e;
    char ch = 'Y';
    ofstream outfile;
    outfile.open("hello.txt", ios::out | ios::binary);
    while(ch == 'Y' || ch == 'y'){
        cout << endl
             << "Enter Name, Age, Basic Sal, Gross Sal: " << endl;
        cin >> e.name >> e.age >> e.basic >> e.gross;
        outfile.write(reinterpret_cast<const char *>(&e), sizeof(e));
        cout << "Add anohter(Y/N)";
        cin >> ch;
    }

    outfile.close();

    ifstream infile;
    infile.open("hello.txt", ios::in | ios::binary);

    cout << endl;
    while(infile.read(reinterpret_cast<char *>(&e), sizeof(e))){
        cout << e.name << '\t' << e.age << '\t' << e.basic << '\t' << e.gross << endl;
    }
    

    return 0;
}
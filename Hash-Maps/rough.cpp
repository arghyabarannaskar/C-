#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream fout;
    string line;
    fout.open("Sample.txt");

    while(fout){
        getline(cin, line);
        if(line == "-1")
            break;
        fout << line << endl;
    }

    fout.close();

    ifstream fin;
    fin.open("Sample.txt");
    while(fin){
        getline(fin, line);
        cout << line << endl;
    }
    fin.close();

    return 0;
}
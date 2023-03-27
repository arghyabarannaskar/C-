#include<iostream>
#include<string>
using namespace std;

void palindrom(string s){
    bool palin = true;
    int length = s.size();
    for (int i = 0; i <= length/2;i++){
        if(s[i] != s[length - 1 - i]){
            palin = false;
            break;
        }
    }
    if(palin)
        cout << "It is a palindrome" << endl;
    else
        cout << "It is not a palindrome" << endl;
}

int main(){
    string str;
    cin >> str;
    palindrom(str);

    return 0;
}
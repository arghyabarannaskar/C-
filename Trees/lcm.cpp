#include<iostream>
using namespace std;

int lcm(int, int);

int main(){
    int a, b, gcd;
    cout<<"Enter two number: ";
    cin >> a >> b;
    cout << endl;
    cout << "the lcm of the two numbers is: " << lcm(a, b);
    gcd = ( (a * b)/lcm(a, b) );
    cout << endl
         << "The gcd is: " << gcd << endl;

    return 0;
}

int lcm(int a, int b){
    int res;
    for (int i = 1; i <= b; i++){
        res = a * i;
        if(res % b == 0)
            break;
    }
    return res;
}
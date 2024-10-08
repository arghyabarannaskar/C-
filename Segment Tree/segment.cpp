#include <iostream>
#include <climits>
using namespace std;
int a[100005], seg[4*100005];

void build(int ind, int low, int high){
    if(low == high){
        seg[ind] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2*ind + 1, low, mid);
    build(2*ind + 2, mid+1, high);

    seg[ind] = max(seg[2*ind + 1], seg[2*ind + 2]);
}

int query(int ind, int low, int high, int l, int r){
    if(l <= low && high <= r) return seg[ind];
    if(r < low || high < l) return INT_MIN;

    int mid = (low + high) / 2;
    int left = query(2*ind+1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, high, l, r);

    return max(left, right);
}

int main(){
    int n;
    cout << "Enter no. of elements: ";
    cin>>n;
    for(int i = 0; i< n; i++){
        cout << "Enter element no " << i << ": ";
        cin>>a[i];
    }

    build(0, 0, n-1);

    cout << "Enter the total no. of queries: ";
    int q;
    cin>>q;
    while(q--){
        cout << "Enter the left bound & right bound: ";
        int l, r;
        cin>>l>>r;
        cout<<"The maximum is: "<<query(0, 0, n-1, l, r)<<endl;
    }

    return 0;
}
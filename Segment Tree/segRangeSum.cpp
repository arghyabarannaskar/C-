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

    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
}

int query(int ind, int low, int high, int l, int r){
    if(l <= low && high <= r) return seg[ind];
    if(r < low || high < l) return 0;

    int mid = (low + high) / 2;
    int left = query(2*ind+1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, high, l, r);

    return left + right;
}

void pointUpdate(int ind, int low, int high, int node, int val){ // node is the index whose value has to be updated
    if(low == high){
        seg[ind] += val;
        return;
    }

    int mid = (low + high) >> 1;
    if(node<=mid)
        pointUpdate(ind * 2 + 1, low, mid, node, val);
    else
        pointUpdate(ind * 2 + 2, mid + 1, high, node, val);

    seg[ind] = seg[ind * 2 + 1] + seg[ind * 2 + 2];
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
    int q, l, r;
    cin>>q;
    while(q--){
        cout << "Enter the left bound & right bound: ";
        cin>>l>>r;
        cout<<"The maximum is: "<<query(0, 0, n-1, l, r)<<endl;
    }

    int node, val;
    cout << "Enter the node whoose value you want to update: ";
    cin >> node;
    cout << "Enter the value by which you want it to increase: ";
    cin >> val;

    pointUpdate(0, 0, n - 1, node, val);
    cout << "New sum: " << query(0, 0, n - 1, l, r) << endl;

    return 0;
}
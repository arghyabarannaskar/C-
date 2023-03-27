#include<iostream>
using namespace std;

void heapify(int[], int, int);

int main(){
    int arr[] = {11, 2, 9, 13, 3, 25, 17, 1, 90, 57};
    int i, size = 10;

    for (i = (size / 2) - 1; i >= 0;i--)
        heapify(arr, size, i);

    for (i = 0; i < size; i++)
        cout << arr[i] << "\t";

        return 0;
}

void heapify(int arr[], int sz, int i){
    int largest, lch, rch, t;

    lch = 2 * i + 1;
    rch = 2 * i + 2;

    if(lch>= sz)
        return;
    largest = i;

    if (lch < sz && arr[lch]>arr[largest])
        largest = lch;
    if(rch<sz && arr[rch]>arr[largest])
        largest = rch;
    
    if(largest != i){
        t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;

        heapify(arr, sz, largest); // heapify the child in case there was a very low value towards the top of the tree
    }
}
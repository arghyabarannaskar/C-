#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &sqnc){
    cout << endl;
    for(auto ele:sqnc){
        cout << ele << " ";
    }
}

void func(int i, int nums[], int size, vector<int> &sqnc){
    if(i == size){
        print(sqnc);
        return;
    }
    sqnc.push_back(nums[i]);
    func(i + 1, nums, size, sqnc);
    sqnc.pop_back();
    func(i + 1, nums, size, sqnc);
}

int main(){
    int nums[] = {6, 77, 4};
    int size = *(&nums + 1) - nums;
    vector<int> sqnc;
    func(0, nums, size, sqnc);

    return 0;
}
#include<iostream>
#include<vector>
using namespace std;

void findCombination(int i, int amount, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds);

int main()
{
    int amount;
    vector<int> nums = {1, 1, 1, 1, 3, 5, 6, 7, 9};
    vector<vector<int>> ans;
    vector<int> ds;
    cout << "Enter the amount: ";
    cin >> amount;
    findCombination(0, amount, nums, ans, ds);
    cout << "Back from call";
    for(auto vect: ans){
        cout << endl;
        for(auto ele:vect){
            cout << ele << " ";
        }
    }

    return 0;
}

void findCombination(int i, int amount, vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds){
    // if(i == nums.size()){
    //     if(amount == 0)
    //         ans.push_back(ds);
    //     return;
    // }

    if(amount == 0){
        ans.push_back(ds);
        return;
    }
    if(i==nums.size()){
        return;
    }

    cout << "i = " << i << " ";

    if(amount>=nums[i]){
        ds.push_back(nums[i]);
        findCombination(i, amount-nums[i], nums, ans, ds);
        ds.pop_back();
    }

    findCombination(i + 1, amount, nums, ans, ds);
}
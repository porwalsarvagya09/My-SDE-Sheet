// leetcode question 75

#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();

    int i = 0;     //denotes for 0
    int j = 0;     //denotes for 1
    int k  = n-1;  //denotes for 2

    while(j <= k) {
        if(nums[j] == 1){
            j++;
        } 
        else if(nums[j] == 0) {
            swap(nums[j], nums[i]);
            i++;
            j++;
        }
        else {
            // nums[j] == 2
            swap(nums[j], nums[k]);
            k--;
        }
    }
}

int main() {

    int n = 6;

    vector<int> nums = { 0, 2, 1, 2, 0, 1};

    sortColors(nums);

    cout<<"Sorted array: {";
    for(int i=0; i<n; i++) {
        cout<<nums[i]<<" ";
    } 
    cout<<"}"<<endl;
    return 0;

}
// T.C.: O(n)
// S.C.: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void nextPermutation(vector<int>& nums){
        int n = nums.size();

        int main_idx = -1;

        for(int i=n-1; i>0; i--) {
            if(nums[i] > nums[i-1]){
                main_idx = i-1;
                break;
            }
        }

        if(main_idx != -1){
            int swap_idx = main_idx;
            for(int j=n-1; j>main_idx; j--) {
                if(nums[j] > nums[main_idx]) {
                    swap_idx = j;
                    break;
                }
            }
            swap(nums[main_idx], nums[swap_idx]);
        }
        reverse(nums.begin() + main_idx + 1, nums.end());
    }
};

int main() {

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
 
    cout << "Enter the elements in the array: ";
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    sol.nextPermutation(nums);

    cout<<"Next permutation is: ["; 
    for(auto& num : nums) {
        cout << " " << num << " ";
    }
    cout<<"]";
    return 0;
}
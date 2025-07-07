// leetcode - 229
// Optimal Approach
// Boyer's Moore Voting Algorithm
// Three steps: 1.Assume Candidate
//              2.Count
//              3.Verification

/*

(n/2) -> 1 majority element only in array
(n/3) -> 2 majority elements in array
(n/k) -> k-1 majority elements in array

*/

// T.C.: O(n)
// S.C.: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int maj1 = 0; 
        int count1 = 0;

        int maj2 = 0;
        int count2 = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == maj1){
                count1++;
            }
            else if(nums[i] == maj2){
                count2++;
            }
            else if(count1 == 0){
                maj1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0){
                maj2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }

        // verification
        vector<int> result;
        int freq1 = 0;
        int freq2 = 0;

        for(auto &num : nums){
            if(num == maj1){
                freq1++;
            }
            else if(num == maj2){
                freq2++;
            }
        }

        if(freq1 > floor(n/3)){
            result.push_back(maj1);
        }
        if(freq2 > floor(n/3)){
            result.push_back(maj2);
        }
        return result;
    }
};

int main(){
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    Solution sol;
    vector<int> ans = sol.majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
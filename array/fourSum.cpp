// leetcode-18 (Four Sum)
/*
| Aspect                         | Complexity              |
| ------------------------------ | ----------------------- |
| **Time**                       | O(n³)                   |
| **Auxiliary Space**            | O(1)                    |
| **Total Space (incl. output)** | O(n⁴) in the worst case |
*/

/*
⏱️ Time Complexity
Sorting Step:
Sorting the input array takes O(n log n) time.

Main Loops:
You have two nested for loops (i, j), followed by a two-pointer scan (p, q) inside, 
which runs in O(n) time. Overall, that's O(n² * n) = O(n³) for the main logic 
→ Total Time Complexity: O(n³) (since n³ dominates n log n).
*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n;){
                int p = j+1;
                int q = n-1;

                while(p < q){
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[p] + (long long)nums[q];
                    
                    if(sum < target){
                        p++;
                    }       
                    else if(sum > target){
                        q--;
                    }       
                    else{
                        // sum == 0
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        while(p<q && nums[p] == nums[p-1]) p++;
                    }    
                }
                j++;
                while(j<n && nums[j] == nums[j-1]) j++;
            }
        }
        return ans;
    }
}; 
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n; 

    vector<int> nums(n);

    for(int i=0; i<n; i++){
        cout<<"Enter nums["<<i<<"]: ";
        cin>>nums[i];
        cout<<endl;
    }

    int target;
    cout<<"target: ";
    cin>>target;

    Solution sol;
    vector<vector<int>> res = sol.fourSum(nums, target);

    cout<<"The result: [";

    for(auto num : res){
        cout<<" { ";
        for(int idx : num){
            cout<<idx<<" ";
        }
        cout<<"}, ";
    }

    cout<<"]";
    return 0;
}

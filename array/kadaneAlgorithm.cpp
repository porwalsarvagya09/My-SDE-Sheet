// Find Maximum subarray sum 
// Better Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// 
// This code finds the maximum subarray sum using a brute force approach.
// It iterates through all possible subarrays and calculates their sums, keeping track of the maximum sum found.
// The solution is not optimal but demonstrates the basic idea of finding subarrays and their sums.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int max_sum = INT_MIN;
        

        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j]; 
            }
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements in the array: ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    Solution sol;
    
    int max_sum = sol.maxSubArray(nums);
    cout << "Maximum subarray sum is: " << max_sum << endl;
    
    return 0;
}


/*--------------------------------------------------------------------------------*/


// Find Maximum subarray sum using Kadane's Algorithm
// Optimal Approach
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    long long ansStart = -1;
    long long ansEnd = -1;
    int maxSubArray(vector<int>& nums) {
        long long n = nums.size();
        
        long long max_sum = INT_MIN;
        long long current_sum = 0;
        
        

        long long start_index;

        for(long long i = 0; i < n; i++) {
            if(current_sum == 0){
                start_index = i; // Start a new subarray
            }
            current_sum += nums[i];

            if(current_sum > max_sum){
                max_sum = current_sum;
                ansStart = start_index;
                ansEnd = i;
            }

            if(current_sum < 0) {
                current_sum = 0; // Reset current sum if it becomes negative
            }
        }
        return max_sum;
    }

    void printSubArray(vector<int>& nums, long long ansStart, long long ansEnd) {
        cout << "Subarray with maximum sum is: [";
        for(long long i = ansStart; i <= ansEnd; i++) {
            cout << " " << nums[i] << " ";
        }
        cout << "]" << endl;
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
    int max_sum = sol.maxSubArray(nums);

    cout << "Maximum subarray sum is: " << max_sum << endl;

    sol.printSubArray(nums, sol.ansStart, sol.ansEnd);
    return 0;
}

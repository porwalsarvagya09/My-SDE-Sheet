
/*
Problem Statement: Given an array print all the sum of the subset generated from it, 
in the increasing order.

Examples:

Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case 
the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the 
sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case 
the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the 
sums we get will be  0,1,2,3,3,4,5,6
*/


#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void subsetSumHelper(int index, vector<int> &arr, int n, vector<int> &ans, int sum)
    {
        if (index == n)
        {
            ans.push_back(sum);
            return;
        }

        // element picked
        subsetSumHelper(index + 1, arr, n, ans, sum + arr[index]);

        // element not picked
        subsetSumHelper(index + 1, arr, n, ans, sum);
    }

    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        subsetSumHelper(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int n = 3;
    vector<int> arr{3, 1, 2};
    Solution ob;
    vector<int> ans = ob.subsetSums(arr, arr.size());
  
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}

/*
Output:

The sum of each subset is
0 1 2 3 3 4 5 6

Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. 
You can either pick it up or not pick it. So for n index time complexity 
for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated
 for an array of size n.
*/
// leetcode - 1
//T.C. : O(n)
// S.C.: O(n)

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int remaining = target - nums[i];

        if (mp.find(remaining) != mp.end())
        {
            return {mp[remaining], i};
        }

        mp[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 5};
    int target = 9;

    vector<int> res = twoSum(nums, target);

    for (int idx : res)
        cout << idx << " ";
    cout << "\n";

    return 0;
}
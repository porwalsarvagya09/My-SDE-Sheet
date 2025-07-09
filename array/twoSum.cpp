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


/*------------------APPROACH-2-----------*/

/*
Time Complexity: O(N) + O(N*logN), where N = size of the array.
Reason: The loop will run at most N times. And sorting the array
will take N*logN time complexity.

Space Complexity: O(1) as we are not using any extra space.
*/

#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}
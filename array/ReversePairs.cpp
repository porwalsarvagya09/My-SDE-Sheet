// leetcode - 493
// BruteForce approach
// T.C. : O(n^2)
// S.C. : O(1) 


#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

int team(vector <int> & skill, int n) {
    return countPairs(skill, n);
}


int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}




/*---------------------------------------------------------------------*/

// APPROACH-2
// MERGE SORT
// T.C. = O(2N*log N)
// S.C. = O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long reversePairs(vector<int>& nums) {
        return mergesortAndCount(nums, 0, nums.size() - 1);
    }

  private:
    long long mergesortAndCount(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;
        long long count = 0;

        count += mergesortAndCount(arr, low, mid);
        count += mergesortAndCount(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }

    int merge(vector<int>& arr, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;
        int current_count = 0;
        vector<int> temp;

        int j = low;
        for(int i = mid+1; i <= high; ++i){
            while(j <= mid && (long long)arr[j] <= 2LL *arr[i]) j++;
            current_count += mid-j +1;
        }

        while (left <= mid && right <= high) {
            if (arr[left] > arr[right]) {
                temp.push_back(arr[right++]);
            } else {
                temp.push_back(arr[left++]);
            }
        }

        while (left <= mid) temp.push_back(arr[left++]);
        while (right <= high) temp.push_back(arr[right++]);

        for (int i = low; i <= high; ++i) {
            arr[i] = temp[i - low];
        }

        return current_count;
    }
};

int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    Solution sol;
    int cnt = sol.reversePairs(a);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}






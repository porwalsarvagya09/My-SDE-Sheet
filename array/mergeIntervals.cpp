// leetcode-56
// Problem: Merge Intervals
// T.C. : O(nlogn) for sorting, O(n) for merging overall O(n)
// S.C. : O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<pair<int, int>> merge(vector<pair<int, int>>& intervals) {

        int n = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<pair<int, int>> result;

        for(int i=0; i<n; i++) {
            if(result.empty() || result.back().second < intervals[i].first) {
                result.push_back(intervals[i]);
            } else {
                result.back().second = max(result.back().second, intervals[i].second);
            }
        }
        return result;

    }

};

int main() {
    int n;
    cout<<"Enter the number of intervals: ";
    cin >> n;
    
    vector<pair<int, int>> intervals(n);

    for(int i=0; i<n; i++) {
       cout<<endl; 
       cout << "Enter interval[" << i << "].first: ";
       cin >> intervals[i].first;
       cout<<"Enter interval[" << i << "].second: ";
       cin >> intervals[i].second;
    }

    Solution sol;

    vector<pair<int, int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for(const auto& interval : mergedIntervals) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }

    return 0;
}
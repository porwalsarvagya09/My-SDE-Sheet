// leetcode-455

/*
✅ Time Complexity:
Sorting g → O(m log m)

Sorting s → O(n log n)

Two-pointer traversal → O(m + n)

Overall Time Complexity:

𝑂(𝑚 log 𝑚 + 𝑛 log 𝑛)
O(mlogm+nlogn)
​
 
✅ Space Complexity:
Sorting is done in-place

Only constant extra variables (i, j, count)

Overall Space Complexity:
O(1)
​

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size();
        int n = s.size();

        int i = 0, j = 0;
        int count = 0;

        while(i < m && j < n) {
            if(s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};

int main(){
    Solution obj;

    vector<int> g = {1,2,3};     // greed factor
    vector<int> s = {1,1};       // cookie sizes

    int ans = obj.findContentChildren(g, s);
    cout << "Maximum content children: " << ans << endl;

    return 0;
}

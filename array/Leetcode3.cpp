/*
Output: The length of the longest substring without repeating characters is 9

Time Complexity: O( 2*N ) (sometimes left and right both have to travel a complete array)

Space Complexity: O(N) where N is the size of HashSet taken for storing the elements
*/


#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int lengthofLongestSubstring(string s) {
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
    }
};

int main() {
  string str = "takeUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}
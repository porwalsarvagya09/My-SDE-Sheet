// Approach
// T.C.: O(n^2), S.C.: O(1)
// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.
// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle

 
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    vector<vector<int>> generate(int n) {
       vector<vector<int>> result(n);
        for(int i=0; i<n; i++) {
            result[i] = vector<int>(i+1, 1);
            for(int j=1; j<i; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
        return result;
    }

};

int main() {
    int n;
    cout << "Enter the number of rows for pascal's triange: ";
    cin >> n;

    Solution S1;

    vector<vector<int>> ans = S1.generate(n);

    cout << "Pascal's Triangle:" << endl;

    for(auto& row : ans){
        for(auto& val : row) {
            cout << val << " ";
        }
        cout<<endl;
    }

    return 0;
}
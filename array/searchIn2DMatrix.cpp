// leetcode- 74
// Search in sorted 2D matrix

// -------------------Brute Force approach---------

// T.C.: O(m*n)
// S.C.: O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();
        
        int store_idx = -1;
        
        // find the row where target is present
        for(int i=0; i<m; i++){
            if(target <= matrix[i][n-1]){
                store_idx = i;
                break;
            }
        }
        
        if(store_idx == -1) return false;
    
        // Find the target in the row
        int k = store_idx;
        for(int j=n-1; j>=0; j--){
            
            if(matrix[k][j] == target){
                return true;
            }
        }
        return false;
    }
};

int main(){

    int m, n;
    cout<<"Enter m: ";
    cin>>m; cout<<endl;
    cout<<"Enter n: ";
    cin>>n;


    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter the value matrix["<<i<<"] ["<<j<<"]: ";
            cin>>matrix[i][j];
            cout<<endl;
        }
        cout<<"\n\n";
    }

    int target;
    cout<<"Enter the target value: "; cin>>target;


    Solution sol;

    bool result = sol.searchMatrix(matrix, target);
    cout<<boolalpha; // print true or false

    cout<<"Target is present: "<<result<<endl;
    
    return 0;

}
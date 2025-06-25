// Brute force
// Approach-1 (By taking extra space) 
// T.C.: O(m*n *(m+n)), S.C.: O(m*n) 
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
    void setMatrixZero(vector<vector<int>> &matrix){
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns

        // create a temperory 2d vector array
        vector<vector<int>> temp = matrix;
        
        // iterate through the matrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    // set the entire row = 0
                    for(int k=0; k<n; k++){
                        temp[i][k] = 0;
                    }
                    // set the entire column = 0
                    for(int k=0; k<m; k++){
                        temp[k][j] = 0;
                    }
                }
            }
        }
        // copy the values from temp to matrix
        matrix = temp;

    }

};

int main(){
    int m, n; // m=rows, n=columns
    cout<<"Enter the number of rows : ";
    cin>>m;
    cout<<"Enter the number of columns : ";
    cin>>n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Input the values in the matrix
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<< "Enter the value for matrix[" <<i<< "][" <<j<< "]: ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    Solution sol;

    sol.setMatrixZero(matrix);

    cout << "Modified Matrix: " << endl;

    // Print the modified matrix
    for(auto &row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

/*-----------------------------------------------------------------------*/


// Approach-2 (usin m+n extra space)
// Better Approach
// T.C.: O(m*n), S.C.: O(m+n)


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void setMatrixZero(vector<vector<int>> &matrix) {
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns

        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    row[i] = true; // mark the row
                    col[j] = true; // mark the column
                }
            }
        }

        // set the rows and columns to zero
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0; // set to zero if row or column is marked
                }
            }
        }
        
    }
};

int main(){
    int m,n;
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of columns: ";  
    cin>>n;

    vector<vector<int>> matrix(m, vector<int>(n));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter the value for matrix["<<i<<"]["<<j<<"]: ";
            cin>>matrix[i][j];
        }
        cout<<endl;
    }

    Solution sol;
    sol.setMatrixZero(matrix);

    cout << "Modified Matrix: " << endl;

    for(auto &row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout<<endl;
    }
    return 0;
}




/*-------------------------------------------------------------------------------*/
// Approach-3 (without using extra space, inplace)
// Optimal Approach
// T.C.: O(m*n), S.C.: O(1) (inplace modification)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void setMatrixZero(vector<vector<int>> &matrix) {

        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns

        bool firstRowImpacted = false; // to check if the first row has any zero
        bool firstColImpacted = false; // to check if the first column has any zero

        // Check if the first row has any zero
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0){
                firstRowImpacted = true;
                break;
            }
        }

        // Check if the first column has any zero
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0){
                firstColImpacted = true;
                break;
            }
        }

        // Set marker for first row and first column
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; // mark the first column
                    matrix[0][j] = 0; // mark the first row
                }
            }
        }

        // Set the matrix to zero based on markers
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0; // set to zero if marked
                }
            }
        }

        // Handle the first row
        if(firstRowImpacted){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0; // set the first row to zero
            }
        }

        // Handle the first column
        if(firstColImpacted){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0; // set the first column to zero
            }
        }

    }
};

int main(){
    int m,n;
    cout<<"Enter the number of rows: ";
    cin>>m;
    cout<<"Enter the number of columns: ";  
    cin>>n;

    vector<vector<int>> matrix(m, vector<int>(n));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<"Enter the value for matrix["<<i<<"]["<<j<<"]: ";
            cin>>matrix[i][j];
        }
        cout<<endl;
    }

    Solution sol;
    sol.setMatrixZero(matrix);

    cout << "Modified Matrix: " << endl;

    for(auto &row : matrix){
        for(int val : row){
            cout << val << " ";
        }
        cout<<endl;
    }
    return 0;
}





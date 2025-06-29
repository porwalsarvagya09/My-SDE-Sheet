// leetcode-48
// T.C. : O(n^2)
// S.C. : O(1)

#include <bits/stdc++.h>
using namespace std;

void rotateImage(vector<vector<int>>& matrix) {

    // Take n as the size of 2d matrix bcoz both
    // row and column size are same in this case
    int n = matrix.size();

    // Transpose the matrix
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row of the transposed matrix
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    // cout << "Enter the elements of the matrix row by row:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Element at position: ["<< i << "], [" << j << "] : ";
            cin >> matrix[i][j];
        }
        cout << endl;
    }

    rotateImage(matrix);
    cout << "Rotated matrix:" << endl;

    for(auto &row : matrix) {
        for(auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;

}
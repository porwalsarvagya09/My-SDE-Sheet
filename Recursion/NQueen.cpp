//leetcode- 51

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> result;
    unordered_set<int> cols;
    unordered_set<int> diag;
    unordered_set<int> antiDiag;

    int N;

    void solve(vector<string> &board, int row)
    {
        if (row >= N)
        {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++)
        {
            if (cols.count(col) || diag.count(row + col) || antiDiag.count(row - col))
            {
                continue; // Skip if the column or diagonals are already occupied
            }

            cols.insert(col);
            diag.insert(row + col);
            antiDiag.insert(row - col);
            board[row][col] = 'Q'; // Place the queen

            solve(board, row + 1); // Recur to place the next queen

            // Backtrack
            cols.erase(col);
            diag.erase(row + col);
            antiDiag.erase(row - col);
            board[row][col] = '.'; // Remove the queen
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        N = n;

        vector<string> board(n, string(n, '.'));

        solve(board, 0);
        return result;
    }

    void print()
    {
        cout << "[ ";
        for (const auto &solution : result)
        {
            cout << "{ ";
            for (const auto &row : solution)
            {
                cout << "[ ";
                cout << row << "], ";
            }
            cout << "}, ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the size of the chessboard (N): ";
    cin >> n;

    Solution sol;
    sol.solveNQueens(n);
    sol.print();

    return 0;
}
/*
🔁 Time Complexity (T.C.)

Let’s denote N as the size of the board (i.e., number of queens to place).

Worst-Case Time Complexity:

You attempt to place a queen in each row.

For each row, you try N columns.

Before placing, you check whether placing a queen at (row, col) is valid using unordered_set lookups (O(1) average-case time).

But this is backtracking. So, the real complexity depends on the number of valid recursive calls made.

In the worst case, we try N options per row, and the recursion tree can have up to N! leaf nodes (when one queen per row is successfully placed with no conflicts).

Thus, the upper bound on time complexity is:

𝑂(𝑁!)
(backtracking with pruning)
O(N!)(backtracking with pruning)

⚠️ Note: With optimizations (like sets for constraints), the actual number of recursive calls is significantly less than N! for large N, but the worst-case is still O(N!).

🧠 Space Complexity (S.C.)

Let’s break it down:

Call Stack (Recursion Depth):

Depth is N (one level for each row).

So, O(N) space on the call stack.

Data Structures:

cols, diag, antiDiag: each can hold up to N elements → O(N) each.

board: size N x N → O(N²) (temporary board during recursion).

result: stores all valid configurations. The number of solutions varies with N:

In the worst case, there can be exponential number of solutions.

Each solution is N x N board.

So total space can be up to O(K * N²) where K is number of valid solutions.
*/
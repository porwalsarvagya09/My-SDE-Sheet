/*
Problem Statement: Given a value V, if we want to make a change for V Rs,
and we have an infinite supply of each of the denominations in Indian currency,
i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued
coins/notes, what is the minimum number of coins and/or notes needed to make the change.

Examples:

Example 1:

Input: V = 70

Output: 2

Explaination: We need a 50 Rs note and a 20 Rs note.

Example 2:

Input: V = 121

Output: 3

Explaination: We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.
Solution:
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 9;                                            // Total number of different coin denominations
    int v = 70;                                           // Value we want to make change for
    int coins[n] = {1, 2, 5, 10, 20, 50, 100, 500, 1000}; // Available coin denominations (sorted in increasing order)

    // Vector to store the coins used
    vector<int> ans;

    // Traversing from the largest denomination to the smallest
    for (int i = n - 1; i >= 0; i--)
    {
        // Keep taking the current coin while it can fit into remaining value 'v'
        while (v >= coins[i])
        {
            v = v - coins[i];        // Reduce the value by the denomination
            ans.push_back(coins[i]); // Store the coin used
        }
    }

    cout << "The minimum number of coins required: " << ans.size() << endl;

    cout << "Coins are: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

/*
✅ Time Complexity (T.C.)
O(n + k)

The outer loop runs n times (where n = number of denominations).

The inner while loop runs k times (total number of coins added into ans).

In worst case, k is proportional to the value v (e.g., using 1-rupee coins for v).

Thus, combined time complexity is approximately O(n + k).

Generally acceptable and efficient for greedy coin change with fixed denominations.

✅ Space Complexity (S.C.)
O(k)

The extra space used is the vector ans which stores the coins used in the solution.

If k coins are required to make amount v, then the space used is proportional to k.

Apart from this, only a few variables are used → no extra large space taken.
*/
// Hare and tortoise algorithm to find duplicate in an array
//  Floyd’s Tortoise and Hare (Cycle Detection)

// slow == fast it mean cycle detected
//leetcode - 287
//T.C. = O(n)
//S.C. = O(1)

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& arr) {

    // Initialize slow and fast pointers
    int slow = arr[0];
    int fast = arr[0];

    slow = arr[slow]; // Move slow pointer by 1 step
    fast = arr[arr[fast]]; // Move fast pointer by 2 steps

    // Phase 1: Detecting the intersection point
    while(slow != fast){
        slow = arr[slow]; // Move slow pointer by 1 step
        fast = arr[arr[fast]]; // Move fast pointer by 2 steps
    }

    slow = arr[0]; // Reset slow pointer to the start of the array

    // Phase 2: Returning the duplicate element

    while(slow != fast) {
        slow = arr[slow]; // Move slow pointer by 1 step
        fast = arr[fast]; // Move fast pointer by 1 step
    }

    return fast; // The duplicate element is found when slow and fast meet
    //return slow; // Alternatively, you can return slow as well

}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n+1);

    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < n+1; i++) {
        cout << "Element " << "nums[" << i << "] << : ";
        cin >> arr[i];
        cout << endl;
    }

    int duplicateElement = findDuplicate(arr);

    cout << "The duplicate element is: " << duplicateElement << endl;
    return 0;
    
}
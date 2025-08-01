/*

Problem Statement: There is one meeting room in a firm. You are given two arrays,
start and end each of size N.For an index ‘i’, start[i] denotes the starting time
of the ith meeting while end[i]  will denote the ending time of the ith meeting.
Find the maximum number of meetings that can be accommodated if only one meeting can
happen in the room at a  particular time. Print the order in which these meetings
will be performed.

Example:

Input:  N = 6,  start[] = {1,3,0,5,8,5}, end[] =  {2,4,5,7,9,9}

Output: 1 2 4 5

Explanation: See the figure for a better understanding.

*/

#include <bits/stdc++.h>
using namespace std;

// Structure to store the start time, end time, and original position of each meeting
struct Meeting {
    int start;
    int end;
    int pos;
};

class Solution {
public:

    // Comparator function to sort meetings by their end time
    static bool comparator(struct Meeting m1, Meeting m2){
        if(m1.end < m2.end) return true;         // Prefer earlier end time
        else if(m1.end > m2.end) return false;
        else if(m1.pos < m2.pos) return true;    // Tie-breaker: maintain original order if end times are same
        return false;
    }

    void maxMeetings(int s[], int e[], int n){
        struct Meeting meet[n];  // Array of meeting structs

        // Fill the meeting struct array with start, end, and position
        for(int i = 0; i < n; i++){
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i + 1; // 1-based indexing for output
        }

        // Sort meetings based on custom comparator
        sort(meet, meet + n, comparator);

        vector<int> answer;      // To store selected meeting indices
        int limit = meet[0].end; // First meeting always selected
        answer.push_back(meet[0].pos);

        // Iterate and select non-overlapping meetings
        for(int i = 1; i < n; i++){
            if(meet[i].start > limit){   // Check if meeting starts after previous ends
                limit = meet[i].end;     // Update limit to current end
                answer.push_back(meet[i].pos);
            }
        }

        // Print the selected meetings in order of selection
        for(int i = 0; i < answer.size(); i++){
            cout << answer[i] << " ";
        }
    }
};

int main() {
    Solution obj;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 5, 7, 9, 9};

    obj.maxMeetings(start, end, n); // output: 1 2 4 5

    return 0;
}


/*

Output:

The order in which the meetings will be performed is
1 2 4 5

Time Complexity: O(n) to iterate through every position and insert them in a data structure. 
O(n log n)  to sort the data structure in ascending order of end time. 
O(n)  to iterate through the positions and check which meeting can be performed.

Overall : O(n) +O(n log n) + O(n) ~O(n log n)

Space Complexity: O(n)  since we used an additional data structure for storing the start 
time, end time, and meeting no.

*/
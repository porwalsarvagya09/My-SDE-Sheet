/* Statement: You are given a read-only array of N integers 
   with values also in the range [1, N] both inclusive. 
   Each integer appears exactly once except A which appears
   twice and B which is missing. The task is to find the repeating 
   and missing numbers A and B where A repeats twice and B is missing.
*/

// leetcode- 2965 check out
// Here A is the repeating number and B is the missing number.
// Example: Input: arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10]
//          Output: A = 10, B = 11


// Brute Force Approach
// Time Complexity: O(N)
// Space Complexity: O(N)


#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> findNumbers(vector<int> &arr){
        int n = arr.size();

        int A = -1, B = -1;

        unordered_map<int, int> mp;
        
        // Traverse the array and count the frequency of each number
        for(int i=0; i<n; i++){
            mp[arr[i]]++;
        }

        // Find the repeating and missing numbers
        for(int num=1; num<=n; num++){
            if(!mp.count(num)) {
                B = num; // If the number is not present, it is the missing number
            }
            else if(mp[num] == 2){
                A = num; // If the number appears twice, it is the repeating number
            }

            if(A != -1 && B != -1){
                break; // If both numbers are found, exit the loop
            }
        }
        return {A, B};
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<long long> arr(n);
     
    // Input the elements of the array    
    for (int i=0; i<n; i++) {
        cout<<"Enter element arr[" << i << "]: ";
        cin >> arr[i];
        cout<<endl;
    }

    Solution sol;

    vector<int> result = sol.findNumbers(arr);
    cout << "The repeating number A is: " << result[0] << endl;
    cout << "The missing number B is: " << result[1] << endl;
   
    return 0;

}


// ---------------------------------------------------------------------------------



// -------OPTIMAL APPROACH-1-----------//

// Mathematical Approach
// T.C. = O(n)
// S.C. = O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:

    vector<int> findNumbers(vector<long long> &arr){
        long long n = arr.size();
        
        long long arrSum = 0;
        long long arrSqSum = 0;
        
        for(long long i=0; i<n; i++){
            arrSum += arr[i];
            arrSqSum += (arr[i]*arr[i]);
        }

        long long expectedArrSum = (n*(n+1))/2;
        long long expectedArrSqSum = (n*(n+1)*(2*n + 1))/6;

        long long sumDiff = expectedArrSum - arrSum;
        long long sumSqDiff = expectedArrSqSum - arrSqSum;

        int b = (sumSqDiff/sumDiff + sumDiff)/2;
        int a = (sumSqDiff/sumDiff - sumDiff)/2;

        return {a, b};

    }

};

int main(){
    int n;
    cout<<"Enter the value n: ";
    cin>>n;

    vector<long long> arr(n);

    for(int i=0; i<n; i++){
        cout<<"Enter element arr[" << i << "]: ";
        cin>>arr[i]; 
    }cout<<endl;

    Solution sol;

    vector<int> res = sol.findNumbers(arr);

    cout<<"Repeating number: " << res[0] << endl;
    cout<<"Missing number: " << res[1] << endl;

    return 0;
}

// -------OptimalApproach-2-------
// using XOR Do it when revise (in tutorial of striver sde sheet)






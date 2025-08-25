// Question link = https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

// T.C. = O(n. log m)
// S.C. = O(1)

#include <iostream>
#include <vector>
using namespace std;

// function to calculate base^expo 
// returns early if result exceeds the 
// given limit to avoid overflow
int power(int base, int expo, int limit) {
    int result = 1;
    for (int i = 0; i < expo; i++) {
        result *= base;
        
        if (result > limit)  
            return result;
    }
    return result;
}

// function to find the 
// n-th root of m
int nthRoot(int n, int m) {
    
    // n-th root of 0 is 0
    if (m == 0) return 0;

    // If n is 1, the answer 
    // is m itself
    if (n == 1) return m;

    // binary search to find 
    // the integer root
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;

        // compute mid^n and compare it with m
        int val = power(mid, n, m);

        if (val == m)
            return mid;  
        else if (val < m)
            low = mid + 1;  
        else
            high = mid - 1; 
    }

    return -1;
}

int main() {
    int n = 4, m = 625;  
    
    int result = nthRoot(n, m);
    cout << result << endl; 

    return 0;
}
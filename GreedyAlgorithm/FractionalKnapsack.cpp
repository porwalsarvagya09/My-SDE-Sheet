#include <bits/stdc++.h>
using namespace std;

// Structure representing an item with value and weight
struct item{
    int value;
    int weight;
};

class Solution{
    public:
    // Comparator to sort items according to value/weight ratio (descending order)
    static bool comparator(item a, item b){
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2; 
    }

    // Function to find maximum total value in the knapsack (fractional knapsack)
    double fractionalKnapsack(int W, item arr[], int n){
        // Sort items by decreasing order of value-to-weight ratio
        sort(arr, arr + n, comparator);

        int currWeight = 0;       // Current weight of knapsack
        double finalValue = 0.0;  // Resulting total value

        // Loop through sorted items
        for(int i = 0; i < n; i++){
            // If adding the whole item doesn't overflow capacity, take it fully
            if(currWeight + arr[i].weight <= W){
                currWeight += arr[i].weight;
                finalValue += arr[i].value;
            }
            else{
                // Otherwise, take the fractional part of the remaining item
                int remain = W - currWeight;
                finalValue += (arr[i].value / (double) arr[i].weight) * (double) remain;
                break;  // Knapsack is full
            }
        }
        return finalValue;
    }
};

int main(){
    int n = 3, weight = 50;

    // Array of items: each with (value, weight)
    item arr[n] = { {100,20}, {60,10}, {120,30} };

    Solution obj;

    // Call the function to calculate max possible value
    double maxValue = obj.fractionalKnapsack(weight, arr, n);

    // Print result upto 2 decimal places
    cout << "The maximum value is: "
         << setprecision(2)      // Print only 2 digits after decimal
         << fixed                // Use fixed-point notation
         << maxValue << endl;
    return 0;
}



// Using DP Bottom-Up Approach
// T.C. : O(n)
// S.C. : O(1)

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    int maxiProfit = 0;
    int bestBuy = prices[0];

    for(int i=1; i<n; i++){
        if(prices[i] > bestBuy){
            maxiProfit = max(maxiProfit, prices[i] - bestBuy);
        }
        bestBuy = min(bestBuy, prices[i]);
    }
    return maxiProfit;

}

int main() {
    int n;
    cout<<"Enter the number of days: ";
    cin >> n;

    vector<int> prices(n);

    cout << "Enter the stock prices for each day: ";
    for(int i=0; i<n; i++) {
        cin >> prices[i];
    }

    int maxProfitValue = maxProfit(prices);
    cout << "Maximum profit that can be achieved: " << maxProfitValue << endl;

    return 0;
}
// You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the 
// future to sell that stock. Return the maximum profit you can achieve from this transaction. 
// If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]   , prices[i] -> stock price on that ith day
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.


// LOGIC -> Aapko max profit tabhi milega jab aap stock minimum price day pe kharidonge and max price day pe bechonge
//          Its just like how we do in Stock market in real life


// NAIVE -> O(n^2) 
// [current ith element ko min consider kro and inner loop me valid days(arr[j]>arr[i]) se profit compare kro ]
//                        
// Optimal -> O(n) [keep track of min while running the loop and calculate the profit when arr[i] > min ]


#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}

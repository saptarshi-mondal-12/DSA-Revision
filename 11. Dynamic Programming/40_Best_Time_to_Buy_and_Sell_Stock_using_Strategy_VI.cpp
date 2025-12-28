#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/* Q. Best Time to Buy and Sell Stock using Strategy

You are given two integer arrays prices and strategy, where:
prices[i] is the price of a given stock on the ith day.
strategy[i] represents a trading action on the ith day, where:
    -1 indicates buying one unit of the stock.
    0 indicates holding the stock.
    1 indicates selling one unit of the stock.

You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

    Selecting exactly k consecutive elements in strategy.
    Set the first k / 2 elements to 0 (hold).
    Set the last k / 2 elements to 1 (sell).

The profit is defined as the sum of strategy[i] * prices[i] across all days.

Return the maximum possible profit you can achieve.

Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.



Input: prices = [4,2,8], strategy = [-1,0,1], k = 2
Output: 10
Explanation:

Modification	Strategy	Profit Calculation	Profit
Original	[-1, 0, 1]	(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8	4
Modify [0, 1]	[0, 1, 1]	(0 × 4) + (1 × 2) + (1 × 8) = 0 + 2 + 8	10
Modify [1, 2]	[-1, 0, 1]	(-1 × 4) + (0 × 2) + (1 × 8) = -4 + 0 + 8	4
Thus, the maximum possible profit is 10, which is achieved by modifying the subarray [0, 1]​​​​​​​.



Input: prices = [5,4,3], strategy = [1,1,0], k = 2
Output: 9
Explanation:

Modification	Strategy	Profit Calculation	Profit
Original	[1, 1, 0]	(1 × 5) + (1 × 4) + (0 × 3) = 5 + 4 + 0	9
Modify [0, 1]	[0, 1, 0]	(0 × 5) + (1 × 4) + (0 × 3) = 0 + 4 + 0	4
Modify [1, 2]	[1, 0, 1]	(1 × 5) + (0 × 4) + (1 × 3) = 5 + 0 + 3	8
Thus, the maximum possible profit is 9, which is achieved without any modification.


Explanation:
------------

Intuition
Let n be the length of the array prices. Assuming that the k consecutive elements we choose lie within the interval [i−k+1,i] (where i≥k−1), the profit consists of three parts:

    1. The sum of all strategy[j]×prices[j] in the interval [0,i−k]
    2. The sum of all prices[j] in the interval [i−k/2+1]
    3. The sum of all strategy[j]×prices[j] in the interval [i+1,n−1]

We use the array profitSum to keep track of the prefix sums of strategy[j]×prices[j], and the array priceSum to keep track of the prefix sums of prices[j]. We iterate through i in order and use the prefix sum arrays to calculate the three parts of the profit, returning the maximum profit obtained.

*/

long long maxProfit(vector<int> &prices, vector<int> &strategy, int k){
    int n = prices.size();
    vector<long long> prefixProfitSum(n);
    vector<long long> prefixPriceSum(n);

    prefixProfitSum[0] = prices[0] * strategy[0];
    prefixPriceSum[0] = prices[0];

    for (int i = 1; i < n; i++){
        prefixProfitSum[i] = prefixProfitSum[i - 1] + prices[i] * strategy[i];
        prefixPriceSum[i] = prefixPriceSum[i - 1] + prices[i];
    }

    long long maxProfit = prefixProfitSum[n - 1];

    for (int i = 0; i < n - k + 1; i++){
        long long leftProfit = 0;
        if (i > 0){
            leftProfit = prefixProfitSum[i - 1];
        }
        long long rightProfit = prefixProfitSum[n - 1] - prefixProfitSum[i + k - 1];
        long long k_size_profit = prefixPriceSum[i + k - 1] - prefixPriceSum[i + k / 2 - 1];
        // cout<<i<<" = "<<k_size_profit<<endl;

        long long total = leftProfit + rightProfit + k_size_profit;
        maxProfit = max(maxProfit, total);
    }

    return maxProfit;
}

int main(){

}
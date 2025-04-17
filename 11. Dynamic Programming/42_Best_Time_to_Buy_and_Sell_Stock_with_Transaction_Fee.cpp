#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Best Time to Buy and Sell Stock with Transaction Fee -> variation = infinite transaction

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again). The transaction fee is only charged once for each stock purchase and sale.


Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6


Intuition: Same code as Q.38 
change: After sell dedecut a transaction fee 
        // Decide to sell the stock on ith day, decesion change to 1 because next we are going to buy
        int sell = (prices[index]-fee) + solve1(index+1, 1, prices, fee);
*/

// Recursion-------------------------------------------------------------
int solve1(int index, int decesion, vector<int>& prices, int fee){
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if(index == prices.size()) return 0;

    int profit = 0;

    // We can buy the stock
    if(decesion == 1){
        // Decide to buy the stock on ith day, decesion change to 0 because next we are going to sell 
        int buy = -prices[index] + solve1(index+1, 0, prices, fee);

        // Decide not to buy the stock on ith day, decesion still remain to 1 because we are going to buy stocks on next day
        int notBuy = 0 + solve1(index+1, 1, prices, fee);

        profit = max(buy, notBuy);
    }

    // We can sell the stock 
    if(decesion == 0){
        // Decide to sell the stock on ith day, decesion change to 1 because next we are going to buy
        int sell = (prices[index]-fee) + solve1(index+1, 1, prices, fee);
        
        // Decide not to sell the stock on ith day, decesion still remain to 0 because we are going to sell stocks on next day
        int notSell = 0 + solve1(index+1, 0, prices, fee);

        profit = max(sell, notSell);
    }

    return profit;
}
int maxProfit1(vector<int>& prices, int fee) {
    // Time complexity: O(2^n) because for every we either sell or buy
    // Space complexity: O(N) - auxalary stack space

    int n=prices.size();
    
    // (sell)0 <--- buy --->1 (buy)     
    return solve1(0, 1, prices, fee);
}



// memoization----------------------------------------------------------
int solve2(int index, int decesion, vector<int>& prices, vector<vector<int>>&dp, int fee){
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if(index == prices.size()) return 0;

    int profit = 0;

    // If the result for this state has already been calculated, return it
    if (dp[index][decesion] != -1) {
        return dp[index][decesion];
    }

    // We can buy the stock
    if(decesion == 1){
        // Decide to buy the stock on ith day, decesion change to 0 because next we are going to sell 
        int buy = -prices[index] + solve2(index+1, 0, prices, dp, fee);

        // Decide not to buy the stock on ith day, decesion still remain to 1 because we are going to buy stocks on next day
        int notBuy = 0 + solve2(index+1, 1, prices, dp, fee);

        profit = max(buy, notBuy);
    } 
    else{ // We can sell the stock

        // Decide to sell the stock on ith day, decesion change to 1 because next we are going to buy
        int sell = prices[index]-fee + solve2(index+1, 1, prices, dp, fee);
        
        // Decide not to sell the stock on ith day, decesion still remain to 0 because we are going to sell stocks on next day
        int notSell = 0 + solve2(index+1, 0, prices, dp, fee);

        profit = max(sell, notSell);
    }

    return dp[index][decesion] = profit;
}
int maxProfit2(vector<int>& prices, int fee) {
    // Time complexity: O(N*2)
    // Space complexity: O(N*2) + O(N)

    int n=prices.size();   
    vector<vector<int>>dp(n, vector<int>(2, -1));
    return solve2(0, 1, prices, dp, fee);
}



// Tabulation----------------------------------------------------------
int maxProfit3(vector<int>prices, int fee){
    // Time complexity: O(N*2)
    // Space complexity: O(N*2)

    // 1->buy , 0->sell

    int n=prices.size();
    vector<vector<int>>dp(n+1, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    int profit;

    for(int i=n-1;i>=0;i--){
        for(int decesion=0;decesion<=1;decesion++){
            // We can buy the stock
            if(decesion == 1){
                int buy = -prices[i] + dp[i+1][0];
                int notBuy = 0 + dp[i+1][1];
                profit = max(buy, notBuy);
            }
            else{ // We can sell the stock 
                int sell = prices[i]-fee + dp[i+1][1];
                int notSell = 0 + dp[i+1][0];
                profit = max(sell, notSell);
            }

            dp[i][decesion] = profit;
        }
    }
    return dp[0][1];
}



// Space optimization----------------------------------------------------------
int maxProfit4(vector<int>prices, int fee){
    // Time complexity: O(N*2)
    // Space complexity: O(1)

    int n=prices.size();

    // Create arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
    vector<int>ahead(2, 0);

    // Base condition: When there are no stocks left, the profit is 0.
    ahead[0] = 0;
    ahead[1] = 0;

    int profit;

    for(int i=n-1;i>=0;i--){
        vector<int>curr(2, 0);
        for(int decesion=0;decesion<=1;decesion++){
            // We can buy the stock
            if(decesion == 1){
                int buy = -prices[i] + ahead[0];
                int notBuy = 0 + ahead[1];
                profit = max(buy, notBuy);
            }

            // We can sell the stock 
            if(decesion == 0){
                int sell = prices[i]-fee + ahead[1];
                int notSell = 0 + ahead[0];
                profit = max(sell, notSell);
            }
            curr[decesion] = profit;
        }
        // Update the "ahead" array with the current values
        ahead = curr;
    }
    return ahead[1];
}




int main(){
    vector<int>prices={1,3,2,8,4,9};
    int fee=2;

    // Recursion
    cout<<maxProfit1(prices, fee)<<endl;

    // Memoization
    cout<<maxProfit2(prices, fee)<<endl;

    // Tabulation
    cout<<maxProfit3(prices, fee)<<endl;

    // Space optimization
    cout<<maxProfit4(prices, fee)<<endl;
}
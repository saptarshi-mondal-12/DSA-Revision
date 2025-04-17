#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Input: prices = [1]
Output: 0


Intuition : Same code Q.38 (Best Time to Buy and Sell Stock II) 

but change is - After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Change line in code : ONLY 1 CHANGE (INDEX+1)
int sell = prices[index] + solve1(index+2, 1, prices);

Tabulation: while declareing dp change it to n+2 because we are accessing dp[index+2].

When we sell a stock on day index, we can’t buy it on day ind+1 ( according to the cooldown clause) therefore we simply skip that day and find the profit starting from day ind+2, therefore we recursively call f(indes+2,1, prices).
*/

// Recursion-------------------------------------------------------------
int solve1(int index, int decesion, vector<int>& prices){
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if(index >= prices.size()) return 0;

    int profit = 0;

    // We can buy the stock
    if(decesion == 1){
        // Decide to buy the stock on ith day, decesion change to 0 because next we are going to sell 
        int buy = -prices[index] + solve1(index+1, 0, prices);

        // Decide not to buy the stock on ith day, decesion still remain to 1 because we are going to buy stocks on next day
        int notBuy = 0 + solve1(index+1, 1, prices);

        profit = max(buy, notBuy);
    }

    // We can sell the stock 
    if(decesion == 0){
        // Decide to sell the stock on ith day, decesion change to 1 because next we are going to buy
        int sell = prices[index] + solve1(index+2, 1, prices);
        
        // Decide not to sell the stock on ith day, decesion still remain to 0 because we are going to sell stocks on next day
        int notSell = 0 + solve1(index+1, 0, prices);

        profit = max(sell, notSell);
    }

    return profit;
}
int maxProfit1(vector<int>& prices) {
    // Time complexity: O(2^n) because for every we either sell or buy
    // Space complexity: O(N) - auxalary stack space

    int n=prices.size();
    
    // (sell)0 <--- buy --->1 (buy)     
    return solve1(0, 1, prices);
}



// memoization----------------------------------------------------------
int solve2(int index, int decesion, vector<int>& prices, vector<vector<int>>&dp){
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if(index >= prices.size()) return 0;

    int profit = 0;

    // If the result for this state has already been calculated, return it
    if (dp[index][decesion] != -1) {
        return dp[index][decesion];
    }

    // We can buy the stock
    if(decesion == 1){
        // Decide to buy the stock on ith day, decesion change to 0 because next we are going to sell 
        int buy = -prices[index] + solve2(index+1, 0, prices, dp);

        // Decide not to buy the stock on ith day, decesion still remain to 1 because we are going to buy stocks on next day
        int notBuy = 0 + solve2(index+1, 1, prices, dp);

        profit = max(buy, notBuy);
    } 
    else{ // We can sell the stock

        // Decide to sell the stock on ith day, decesion change to 1 because next we are going to buy
        int sell = prices[index] + solve2(index+2, 1, prices, dp);
        
        // Decide not to sell the stock on ith day, decesion still remain to 0 because we are going to sell stocks on next day
        int notSell = 0 + solve2(index+1, 0, prices, dp);

        profit = max(sell, notSell);
    }

    return dp[index][decesion] = profit;
}
int maxProfit2(vector<int>& prices) {
    // Time complexity: O(N*2)
    // Space complexity: O(N*2) + O(N)

    int n=prices.size();   
    vector<vector<int>>dp(n, vector<int>(2, -1));
    return solve2(0, 1, prices, dp);
}



// Tabulation----------------------------------------------------------
int maxProfit3(vector<int>prices){
    // Time complexity: O(N*2)
    // Space complexity: O(N*2)

    // 1->buy , 0->sell

    int n=prices.size();
    vector<vector<int>>dp(n+2, vector<int>(2, 0));

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
                int sell = prices[i] + dp[i+2][1];
                int notSell = 0 + dp[i+1][0];
                profit = max(sell, notSell);
            }

            dp[i][decesion] = profit;
        }
    }
    return dp[0][1];
}



// Space optimization----------------------------------------------------------
int maxProfit4(vector<int>& prices) {
    // Time complexity: O(N*2)
    // Space comlexity: O(1)
    int n=prices.size();

    // Initialize three arrays to track the maximum profit for buying and selling
    vector<int> curr(2, 0);       // Current maximum profit
    vector<int> ahead1(2, 0);    // Maximum profit one step ahead
    vector<int> ahead2(2, 0);    // Maximum profit two steps ahead

    // Base condition: When there are no stocks left, the profit is 0.
    ahead1[0] = 0;
    ahead1[1] = 0;

    int profit;

    for(int i=n-1;i>=0;i--){
        for(int decesion=0;decesion<=1;decesion++){
            // We can buy the stock
            if(decesion == 1){
                int buy = -prices[i] + ahead1[0];
                int notBuy = 0 + ahead1[1];
                profit = max(buy, notBuy);
            }

            // We can sell the stock 
            if(decesion == 0){
                int sell = prices[i] + ahead2[1];
                int notSell = 0 + ahead1[0];
                profit = max(sell, notSell);
            }
            curr[decesion] = profit;
        }
        // Update the 'ahead1' and 'ahead2' arrays with current values
        ahead2=ahead1;
        ahead1 = curr;
    }
    return ahead1[1];
}




int main(){
    vector<int>prices={1,2,3,0,2};

    // Recursion
    cout<<maxProfit1(prices)<<endl;

    // Memoization
    cout<<maxProfit2(prices)<<endl;

    // Tabulation
    cout<<maxProfit3(prices)<<endl;

    // Space optimization
    cout<<maxProfit4(prices)<<endl;
}
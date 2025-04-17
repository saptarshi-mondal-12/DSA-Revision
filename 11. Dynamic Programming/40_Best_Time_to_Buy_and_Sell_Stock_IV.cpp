#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q.  Best Time to Buy and Sell Stock III -> variation = atmost k transactions 

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.


Intuition - Same code as Q.39 
*/

// Recursion---------------------------------------------------------------
int solve1(int index, int decesion, vector<int>& prices, int transactions){
    // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
    if(index == prices.size() || transactions == 0) return 0;

    int profit = 0;

    // We can buy the stock
    if(decesion == 1){
        // Decide to buy the stock on ith day, decesion change to 0 because next we are going to sell 
        int buy = -prices[index] + solve1(index+1, 0, prices, transactions);

        // Decide not to buy the stock on ith day, decesion still remain to 1 because we are going to buy stocks on next day
        int notBuy = 0 + solve1(index+1, 1, prices, transactions);

        profit = max(buy, notBuy);
    }

    // We can sell the stock 
    if(decesion == 0){
        // Decide to sell the stock on ith day, decesion change to 1 because next we are going to buy
        int sell = prices[index] + solve1(index+1, 1, prices, transactions-1);
        
        // Decide not to sell the stock on ith day, decesion still remain to 0 because we are going to sell stocks on next day
        int notSell = 0 + solve1(index+1, 0, prices, transactions);

        profit = max(sell, notSell);
    }

    return profit;
}
int maxProfit1(int k, vector<int>& prices) {
    // Time complexity: exponential
    // Space complexity: O(N) - auxalary stack space

    int n=prices.size();
    
    // (sell)0 <--- buy --->1 (buy)  
    return solve1(0, 1, prices, k);
}


// Memoization-------------------------------------------------------------
int solve2(int index, int decesion, vector<int>& prices,  vector<vector<vector<int>>>&dp, int transactions){
    // Base case: If we reach the end of the array or run out of allowed transactions, return 0.
    if(index == prices.size() || transactions == 0) return 0;

    int profit = 0;

    // If the result for this state has already been calculated, return it
    if (dp[index][decesion][transactions] != -1) {
        return dp[index][decesion][transactions];
    }

    // We can buy the stock
    if(decesion == 1){
        // Decide to buy the stock on ith day, decesion change to 0 because next we are going to sell 
        int buy = -prices[index] + solve2(index+1, 0, prices, dp, transactions);

        // Decide not to buy the stock on ith day, decesion still remain to 1 because we are going to buy stocks on next day
        int notBuy = 0 + solve2(index+1, 1, prices, dp, transactions);

        profit = max(buy, notBuy);
    } 
    else{ // We can sell the stock

        // Decide to sell the stock on ith day, decesion change to 1 because next we are going to buy
        int sell = prices[index] + solve2(index+1, 1, prices, dp, transactions-1);
        
        // Decide not to sell the stock on ith day, decesion still remain to 0 because we are going to sell stocks on next day
        int notSell = 0 + solve2(index+1, 0, prices, dp, transactions);

        profit = max(sell, notSell);
    }

    return dp[index][decesion][transactions] = profit;
}
int maxProfit2(int k, vector<int>& prices) {
    // Time complexity:  O(N*2*k)
    // Space complexity:  O(N*2*k) + O(N)

    int n=prices.size();    
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solve2(0, 1, prices, dp, k);

    // NOTE: vector<int>(k+1, -1) 
    // k+1 because it signifies 0 transaction remaining or 1 transaction remaining or k transaction remaining. so we have k+1 different set of transactions.
    
}


// Tabulation----------------------------------------------------------------
int maxProfit3(int k, vector<int>& prices) {
    // Time complexity:  O(N*2*k)
    // Space complexity:  O(N*2*k)

    // 1->buy , 0->sell

    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    // if transactions is 0, which means index & decesion can be anything 
    for(int index=0;index<n;index++){
        for(int decesion = 0; decesion<=1; decesion++){
            dp[index][decesion][0] = 0;
        }
    }

    // if index is n, decesion & transaction can be anything 
    for(int decesion=0;decesion<=1;decesion++){
        for(int transactions = 0; transactions<=k; transactions++){
            dp[n][decesion][transactions] = 0;
        }
    }

    // note: above base case is not necessary because its already is 0

    int profit;

    for(int i=n-1;i>=0;i--){
        for(int decesion=0;decesion<=1;decesion++){
            for(int transactions = 1; transactions<=k; transactions++){
                // We can buy the stock
                if(decesion == 1){
                    int buy = -prices[i] + dp[i+1][0][transactions];
                    int notBuy = 0 + dp[i+1][1][transactions];
                    profit = max(buy, notBuy);
                }
                else{ // We can sell the stock 
                    int sell = prices[i] + dp[i+1][1][transactions-1];
                    int notSell = 0 + dp[i+1][0][transactions];
                    profit = max(sell, notSell);
                }
                dp[i][decesion][transactions] = profit;
            }
        }
    }
    return dp[0][1][k];
    
}


// Space Optimization------------------------------------------------------------------
int maxProfit4(int k, vector<int>& prices) {
    // Time complexity:  O(N*2*k)
    // Space complexity: O(1)

    int n=prices.size();
    
    // Create two 2D arrays to store the profit information, one for the current state and one for the ahead state.
    vector<vector<int>> ahead(2, vector<int>(k+1, 0));
    vector<vector<int>> cur(2, vector<int>(k+1, 0));


    int profit;

    for(int i=n-1;i>=0;i--){
        for(int decesion=0;decesion<=1;decesion++){
            for(int transactions = 1; transactions<=k; transactions++){
                // We can buy the stock
                if(decesion == 1){
                    int buy = -prices[i] + ahead[0][transactions];
                    int notBuy = 0 + ahead[1][transactions];
                    profit = max(buy, notBuy);
                }
                else{ // We can sell the stock 
                    int sell = prices[i] + ahead[1][transactions-1];
                    int notSell = 0 + ahead[0][transactions];
                    profit = max(sell, notSell);
                }
                cur[decesion][transactions] = profit;
            }
        }
        ahead = cur;
    }
    return ahead[1][k];
    
}



int main(){
    vector<int>prices={3,2,6,5,0,3};
    int k=2;

    // Recursion
    cout<<maxProfit1(k, prices)<<endl;

    // Memoization
    cout<<maxProfit2(k, prices)<<endl;

    // Tabulation
    cout<<maxProfit3(k, prices)<<endl;

    // Space optimization
    cout<<maxProfit4(k, prices)<<endl;
}
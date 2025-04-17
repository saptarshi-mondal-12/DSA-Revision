#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Best Time to Buy and Sell Stock II -> variation = infinite transaction

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.


Intuition: 
Every day, we will have two choices, either to do nothing and move to the next day or to buy/sell (based on the last transaction) and find out the profit. Therefore we need to generate all the choices in order to compare the profit. As we need to try out all the possible choices, we will use recursion.

Step 1: Express the problem in terms of indexes.

We need to think in the terms of the number of days, therefore one variable will be the array index( say ind). Next, we need to respect the condition that we can’t buy a stock again, that is we need to first sell a stock, and then we can buy that again. Therefore we need a second variable ‘buy’ which tells us on a particular day whether we can buy or sell the stock. 

0-> we can buy the stocks 
1-> we can sell the stocks


Step 2: Try out all possible choices at a given index.
Every day, we have two choices:

To either buy/sell the stock(based on the buy variable’s value). 
To do nothing and move on to the next day.
We need to generate all the choices. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”.

Case 1: When buy == 0, we can buy the stock.

If we can buy the stock on a particular day, we have two options:
    Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have not bought the stock, the ‘buy’ variable value will still remain 0, indicating that we can buy the stock the next day.

    Option 2: The other option is to buy the stock on the current day. In this case, the net profit earned from the current transaction will be -Arr[i]. As we are buying the stock, we are giving money out of our pocket, therefore the profit we earn is negative. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have bought the stock, the ‘buy’ variable value will change to 1, indicating that we can’t buy and only sell the stock the next day.

Case 2: When buy == 1, we can sell the stock.
If we can buy the stock on a particular day, we have two options:
    Option 1: To do no transaction and move to the next day. In this case, the net profit earned will be 0 from the current transaction, and to calculate the maximum profit starting from the next day, we will recursively call f(ind+1,1). As we have not bought the stock, the ‘buy’ variable value will still remain at 1, indicating that we can’t buy and only sell the stock the next day.
    
    Option 2: The other option is to sell the stock on the current day. In this case, the net profit earned from the current transaction will be +Arr[i]. As we are selling the stock, we are putting the money into our pocket, therefore the profit we earn is positive. To calculate the maximum profit starting from the next day, we will recursively call f(ind+1,0). As we have sold the stock, the ‘buy’ variable value will change to 0, indicating that we can buy the stock the next day.

Step 3:  Return the maximum 
As we are looking to maximize the profit earned, we will return the maximum value in both cases.
*/

// Recursion-------------------------------------------------------------
int solve1(int index, int decesion, vector<int>& prices){
    // Base case: When we reach the end of the array, there are no more decisions to make.
    if(index == prices.size()) return 0;

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
        int sell = prices[index] + solve1(index+1, 1, prices);
        
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
    if(index == prices.size()) return 0;

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
        int sell = prices[index] + solve2(index+1, 1, prices, dp);
        
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
                int sell = prices[i] + dp[i+1][1];
                int notSell = 0 + dp[i+1][0];
                profit = max(sell, notSell);
            }

            dp[i][decesion] = profit;
        }
    }
    return dp[0][1];
}



// Space optimization----------------------------------------------------------
int maxProfit4(vector<int>prices){
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
                int sell = prices[i] + ahead[1];
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
    vector<int>prices={7,1,5,3,6,4};

    // Recursion
    cout<<maxProfit1(prices)<<endl;

    // Memoization
    cout<<maxProfit2(prices)<<endl;

    // Tabulation
    cout<<maxProfit3(prices)<<endl;

    // Space optimization
    cout<<maxProfit4(prices)<<endl;
}
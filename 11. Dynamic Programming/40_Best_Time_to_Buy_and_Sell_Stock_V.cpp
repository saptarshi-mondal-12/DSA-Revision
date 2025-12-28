#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/* Q. Best Time to Buy and Sell Stock V

You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.
You are allowed to make at most k transactions, where each transaction can be either of the following:

    Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
    Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

Return the maximum total profit you can earn by making at most k transactions.


Input: prices = [1,7,9,8,2], k = 2
Output: 14
Explanation: We can make $14 of profit through 2 transactions:
A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.


Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
Output: 36
Explanation: We can make $36 of profit through 3 transactions:
A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.



Explantion: 
-----------

Key State Definition (Very Important)

We must track what position we are in:

State	Meaning
0	No open position (flat)
1	Holding a long position (bought, waiting to sell)
2	Holding a short position (sold, waiting to buy back)


Function Parameters
day        -> current index
k          -> remaining transactions
state      -> 0 (flat), 1 (long), 2 (short)
entryPrice -> price at which buy/sell happened


Visual Summary: 

    FLAT (0)
    ├── BUY → LONG (1)
    └── SELL → SHORT (2)

    LONG (1)
    └── SELL → FLAT (0)   [complete transaction]

    SHORT (2)
    └── BUY → FLAT (0)    [complete transaction]



Why This Is Correct

Explicitly models:
    Flat
    Long (buy → sell)
    Short (sell → buy)

Transaction count decreases only on close
Prevents overlapping transactions
Memoization reduces time from exponential to O(N² × K)

Complexity

Time: O(N² × K)
Space: O(N² × K)



1. Flat Position (State = 0)

Meaning:

You have no open transaction
You are not holding the stock
You are not short the stock

In simple terms You are out of the market.

What you can do
    Do nothing
    Start a normal transaction (buy)
    Start a short-selling transaction (sell first)

Example:
Day 3, price = 10
You are flat → you can buy or sell




2. Long Position (State = 1)

Meaning

You bought the stock
You currently own the stock
You will profit if the price goes up

Transaction flow: BUY → SELL


Profit formula : profit = sell_price - buy_price


What you can do

Hold the stock (wait)
Sell the stock to complete the transaction

Code meaning = state == 1


Example:
Buy at 5 → Price rises to 9 → Sell → Profit = +4



3. Short Position (State = 2)

Meaning

You sold the stock without owning it
You must buy it back later
You profit if the price goes down

Transaction flow : SELL → BUY BACK


Profit formula : profit = sell_price - buyback_price

What you can do

Wait (price may drop)
Buy back the stock to complete the transaction

Code meaning state == 2


Example:
Sell at 10 → Price drops to 6 → Buy back → Profit = +4


Visual Summary: 

    FLAT (0)
    ├── BUY → LONG (1)
    └── SELL → SHORT (2)

    LONG (1)
    └── SELL → FLAT (0)   [complete transaction]

    SHORT (2)
    └── BUY → FLAT (0)    [complete transaction]



*/

// 1. Recursion Soln ---------------------------------------------------------------------------------------
long long solve(int day, int k, int state, long long entryPrice, vector<int> &prices){
    // If we reach the end of days
    if (day == prices.size()){
        // If a position is still open, it's invalid (can't close it)
        return (state == 0) ? 0 : LLONG_MIN / 2;
    }

    // If no transactions left, we cannot open new ones
    if (k == 0 && state == 0){
        return 0;
    }

    long long profit = LLONG_MIN / 2;

    // -------- FLAT STATE --------
    if (state == 0){
        // Option 1: Do nothing
        profit = solve(day + 1, k, 0, 0, prices);

        if (k > 0){
            // Option 2: Start a normal transaction (BUY)
            profit = max(profit, solve(day + 1, k, 1, prices[day], prices));

            // Option 3: Start a short-selling transaction (SELL)
            profit = max(profit, solve(day + 1, k, 2, prices[day], prices));
        }
    }

    // -------- LONG POSITION --------
    else if (state == 1){
        // Option 1: Hold
        profit = solve(day + 1, k, 1, entryPrice, prices);

        // Option 2: Sell and close transaction
        long long gain = prices[day] - entryPrice;
        profit = max(profit, gain + solve(day + 1, k - 1, 0, 0, prices));
    }

    // -------- SHORT POSITION --------
    else{
        // Option 1: Hold
        profit = solve(day + 1, k, 2, entryPrice, prices);

        // Option 2: Buy back and close transaction
        long long gain = entryPrice - prices[day];
        profit = max(profit, gain + solve(day + 1, k - 1, 0, 0, prices));
    }

    return profit;
}
long long recursion_maximumProfit(vector<int> &prices, int k){
    // Time complexity: O(3ⁿ) -> TLE for large inputs
    // Space complexity: O(1)

    return solve(0, k, 0, 0, prices);
}





// 2. Memoization -----------------------------------------------------------------------------------------

long long solve2(int day, int k, int state, vector<int> &prices, vector<vector<vector<long long>>> &dp){
    // If we reach the end of days
    if (day == prices.size()){
        // If a position is still open, it's invalid (can't close it)
        return (state == 0) ? 0 : LLONG_MIN / 2;
    }

    if (dp[day][k][state] != LLONG_MIN)
        return dp[day][k][state];

    long long profit = LLONG_MIN / 2;

    // -------- FLAT STATE --------
    if (state == 0){
        // Option 1: Do nothing
        profit = solve2(day + 1, k, 0, prices, dp);

        if (k > 0){
            // Option 2: Start a normal transaction (BUY)
            profit = max(profit, -prices[day] + solve2(day + 1, k, 1, prices, dp));

            // Option 3: Start a short-selling transaction (SELL)
            profit = max(profit, prices[day] + solve2(day + 1, k, 2, prices, dp));
        }
    }

    // -------- LONG POSITION --------
    else if (state == 1){
        // Option 1: Hold
        profit = solve2(day + 1, k, 1, prices, dp);

        // Option 2: Sell and close transaction
        long long gain = prices[day];
        profit = max(profit, gain + solve2(day + 1, k - 1, 0, prices, dp));
    }

    // -------- SHORT POSITION --------
    else{
        // Option 1: Hold
        profit = solve2(day + 1, k, 2, prices, dp);

        // Option 2: Buy back and close transaction
        long long gain = -prices[day];
        profit = max(profit, gain + solve2(day + 1, k - 1, 0, prices, dp));
    }

    return dp[day][k][state] = profit;
}
long long memoization_maximumProfit(vector<int> &prices, int k){
    // Time: O(N² × K)
    // Space: O(N² × K)

    int n = prices.size();

    // dp[day][k][state]
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(k+1, vector<long long>(3, LLONG_MIN)));
    return solve2(0, k, 0, prices, dp);
}




int main(){
    vector<int> prices = {1, 7, 9, 8, 2};
    int k = 2;

    // 1. Recursion
    cout << recursion_maximumProfit(prices, k) << endl;

    // 2. Memoization
    cout << memoization_maximumProfit(prices, k) << endl;
}
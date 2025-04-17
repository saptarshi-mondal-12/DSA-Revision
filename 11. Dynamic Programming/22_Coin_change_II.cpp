#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Coin Change II

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0. You may assume that you have an infinite number of each kind of coin.

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1 


Intuition: 

Step 1: Express the problem in terms of indexes.

We are given ‘n’ coins. Their denomination value is given by the array ‘arr’.So clearly one parameter will be ‘ind’, i.e index up to which the array items are being considered.

There is one more parameter, the given target value “T” which we want to achieve so that while generating subsequences, we can decide whether we want to include a particular coin or not. 

So, we can say that initially, we need to find f(n-1, T) where T is the initial target given to us in the question. f(n-1, T) means we are finding the total number of ways to form the target T by considering coins from index 0 to index n-1 of the arr array.

Base Cases:
If ind==0, it means we are at the first item so we have only one coin denomination, therefore the following two cases can arise:
    T is divisible by arr[0]  (eg: arr[0] = 4 and T = 12)

In such a case where the target is divisible by the coin element value, we will return 1 as we will be able to form the target.
    T is not divisible by arr[0] (eg: arr[0] = 4 and T = 7)
In all other cases, we will not be able to form the target, so we will return 0.


Step 2: Try out all possible choices at a given index.
We need to generate all the subsequences. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”.

We have two choices:
    Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index coin. If we exclude the current coin, the target sum will not be affected. So we will call the recursive function f(ind-1,T) to find the remaining answer.

    Include the current element in the subsequence: We will try to find a subsequence by considering the current icoin. As we have included the coin, the target sum will be updated to T-arr[ind].

Now here is the catch, as there is an unlimited supply of coins, we want to again form a solution with the same coin value. So we will not recursively call for f(ind-1, T-arr[ind]) rather we will stay at that index only and call for f(find, T-arr[ind]) to find the answer.
Note: We will consider the current coin only when its denomination value (arr[ind]) is less than or equal to the target T.


Step 3:  Return the sum of take and notTake
As we have to return the total number of ways we can form the target, we will return the sum of notTake and take as our answer.
 
*/

// Recursion--------------------------------------------------------------------
int solve1(int index, int amount, vector<int>& coins){
    // Base case 
    if(index == 0){
        if(amount % coins[index] == 0){
            return 1;
        }else{
            return 0;
        }
    }

    long notTake = 0 + solve1(index-1, amount, coins);
    int take = 0;
    if(coins[index] <= amount){
        take = solve1(index, amount-coins[index], coins);
    }
    return take + notTake;
}
int change1(vector<int>& coins, int amount) {
    int n = coins.size();
    return solve1(n-1, amount, coins);
}



// Memoization--------------------------------------------------------------------
int solve2(int index, int amount, vector<int>& coins, vector<vector<int>>&dp){
    // Base case 
    if(index == 0){
        if(amount % coins[index] == 0){
            return 1;
        }else{
            return 0;
        }
    }

    if(dp[index][amount] != -1) return dp[index][amount];

    long notTake = 0 + solve2(index-1, amount, coins, dp);
    int take = 0;
    if(coins[index] <= amount){
        take = solve2(index, amount-coins[index], coins, dp);
    }
    return dp[index][amount] = take + notTake;
}
int change2(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, -1));
    return solve2(n-1, amount, coins, dp);
}



// Tabulation---------------------------------------------------------------------
int change3(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, 0));

    // Base case
    for(int i=0;i<=amount;i++){
        if(i % coins[0] == 0){
            dp[0][i] = 1;
        }
    }

    for(int index=1;index<n;index++){
        // j represent amount -> amount i.e j can be anything in between 0->amount
        for(int j=0;j<=amount;j++){
            long notTake = dp[index-1][j];
            int take = 0;
            if(coins[index] <= j){
                take = dp[index][j-coins[index]];
            }
            dp[index][j] = take + notTake;
        }
    }
    return dp[n-1][amount];
}



// Space optimization---------------------------------------------------------------------
int change4(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int>prev(amount+1, 0);

    // Base case
    for(int i=0;i<=amount;i++){
        if(i % coins[0] == 0){
            prev[i] = 1;
        }
    }

    for(int index=1;index<n;index++){
        vector<int>curr(amount+1, 0);
        // j represent amount -> amount i.e j can be anything in between 0->amount
        for(int j=0;j<=amount;j++){
            long notTake = prev[j];
            int take = 0;
            if(coins[index] <= j){
                take = curr[j-coins[index]];
            }
            curr[j] = take + notTake;
        }
        prev=curr;
    }
    return prev[amount];
}



int main(){
    vector<int>coins={1,2,5};
    int amount = 5;

    // Recursion
    cout<<change1(coins, amount)<<endl;

    // Memoization
    cout<<change2(coins, amount)<<endl;

    // Tabulation
    cout<<change3(coins, amount)<<endl;

    // Space optimization
    cout<<change4(coins, amount)<<endl;
}

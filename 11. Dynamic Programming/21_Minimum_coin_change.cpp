#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. You may assume that you have an infinite number of each kind of coin.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Input: coins = [2], amount = 3
Output: -1

Input: coins = [1], amount = 0
Output: 0


Intuition: 

Why a Greedy Solution doesn’t work?

The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because there is no ‘uniformity’ in data. While selecting a local better choice we may choose an item that will in the long term give less value.

E.g coins=[9,6,5,1], amount = 11

A Greedy solution will be to take the highest denomination coin first, so we will take an item on index 0, with a value of 9. Now the remaining target sum will be 2. Therefore we can only consider coins with a value of 1. We will take 2 coins of value 1 to meet the target. So a greedy solution gives us the answer 3 {9,1,1}.

Now we can clearly see that a non-greedy solution of taking 2 coins valued 6 and 5 will give us a better option. So we can say that the greedy solution doesn’t work for this problem. 

As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion and select the combination which gives us the minimum number of coins.

Step 1: Express the problem in terms of indexes.

We are given ‘n’ distinct numbers. Their denomination is represented by the ‘arr’ array. So clearly one parameter will be ‘ind’, i.e index up to which the array items are being considered.
There is one more parameter “T”. We need to know the given target that we want to achieve.
So, we can say that initially, we need to find f(n-1, T) where T is the initial target given to us. f(n-1, T) means we are finding the minimum number of coins required to form the target sum by considering coins from index 0 to n-1.


Base Cases:
If ind==0, it means we are at the first item, so in that case, the following cases can arise:
    arr[0] = 4 and T = 12

In such a case where the target is divisible by the coin element, we will return T%arr[0].
    arr[0] =4 and T=1 , arr[0]=3 T=10

In all other cases, we will not be able to form a solution, so we will return a big number like 1e9


Step 2: Try out all possible choices at a given index.

We need to generate all the subsequences. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”. There will be a slight change for this question which is discussed below.

We have two choices:
    Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index coin. If we exclude the current coin, the target sum will not be affected and the number of coins added to the solution will be 0. So we will call the recursive function f(ind-1,T)

    Include the current element in the subsequence: We will try to find a subsequence by considering the current icoin. As we have included the coin, the target sum will be updated to T-arr[ind] and we have considered 1 coin to our solution.
    
Now here is the catch, as there is an unlimited supply of coins, we want to again form a solution with the same coin value. So we will not recursively call for f(ind-1, T-arr[ind]) rather we will stay at that index only and call for f(ind, T-arr[ind]) to find the answer.
Note: We will consider the current coin only when its denomination value (arr[ind]) is less than or equal to the target T.


Step 3:  Return the minimum of take and notTake
As we have to return the minimum number of coins, we will return the minimum of take and notTake as our answer.


-----Explanation: take = 1 + solve1(index, amount - coins[index], coins); 
Q. Why not index-1 ?

e.g. Denominations: [1, 6, 9], amount = 30

We always don't need all coins of smae type -> amount/coins[i]. Suppose for above example,
Greedy approach,
total coins = 30/9 => 3 times (9*3=27). Probably their might be a case where we need to take 2 denomination of 9, make it 9*2=18 and plus other coins.

[1,6,9], amount = 30
30/9 = 3 (9*3=27)
1/1 = 1 (1*1=1) 
total = 9*3 + 1*3 = 30 ==> Total 6 coins (9, 9, 9, 1, 1, 1)

But their might be a case where we don't require all of of larger denomination coin 

Denominations: [1, 6, 9]
Target Sum: 30
Greedy Result: 6 coins (9, 9, 9, 1, 1, 1)
Optimal Result: 4 coins (9, 9, 6, 6)

i.e why we remain on same index and check for all possible combination using recursion.

*/

// Recursion--------------------------------------------------------------------
int solve1(int index, int amount, vector<int>coins){
    if(index==0){
        if(amount % coins[index] == 0){
            return amount / coins[index];
        }else{
            return 1e9;
        }
    }

    int notTake = 0 + solve1(index-1, amount, coins);
    
    int take = 1e9;
    if(coins[index] <= amount){
        take = 1 + solve1(index, amount - coins[index], coins);
    }

    return min(take, notTake);
}
int coinChange1(vector<int> &coins, int amount){
    // Time complexity: > O(2^N) exponential - Every time our recurrence stand up on same index. for an index don't have 2 ways we have multiple ways. Time complexity is exponential as of now.

    // Space complexity: O(N)

    int n=coins.size();
    int ans = solve1(n-1, amount, coins);

    // If 'ans' is still very large, it means it's not possible to form the target sum
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}



// Memoization--------------------------------------------------------------------
int solve2(int index, int amount, vector<int>coins, vector<vector<int>>&dp){
    if(index==0){
        if(amount % coins[index] == 0){
            return amount / coins[index];
        }else{
            return 1e9;
        }
    }

    if(dp[index][amount] != -1) return dp[index][amount];

    int notTake = 0 + solve2(index-1, amount, coins, dp);
    
    int take = 1e9;
    if(coins[index] <= amount){
        take = 1 + solve2(index, amount - coins[index], coins, dp);
    }

    return dp[index][amount] = min(take, notTake);
}
int coinChange2(vector<int> &coins, int amount){
    // Time complexity: O(N * amount)
    // Space complexity: O(N * amount) + O(N)

    int n=coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, -1));
    int ans = solve2(n-1, amount, coins, dp);

    // If 'ans' is still very large, it means it's not possible to form the target sum
    if(ans >= 1e9){
        return -1;
    }
    return ans;
}



// Tabulation---------------------------------------------------------------------
int coinChange3(vector<int> &coins, int amount){
    // Time complexity: O(N * amount)
    // Space complexity: O(N * amount)
    
    int n=coins.size();
    vector<vector<int>>dp(n, vector<int>(amount+1, 0));

    for(int i=0;i<=amount;i++){
        if(i % coins[0] == 0){
            dp[0][i] = i / coins[0];
        }else{
            dp[0][i] = 1e9;
        }
    }
    // note j represent the amount (0 -> amount)
    for(int index=1;index<n;index++){
        for(int j=0;j<=amount;j++){

            int notTake = 0 + dp[index-1][j];
            
            int take = 1e9;
            if(coins[index] <= j){
                take = 1 + dp[index][j - coins[index]];
            }

            dp[index][j] = min(take, notTake);
        }
    }

    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][amount];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9){
        return -1;
    }
    
    // Return the minimum number of elements needed
    return ans;
}



// Space optimization---------------------------------------------------------------------
int coinChange4(vector<int> &coins, int amount){
    // Time complexity: O(N * amount)
    // Space complexity: O(amount)

    int n=coins.size();

    // Create a vectors to store the previous DP states
    vector<int>prev(amount+1, 0);

    // Initialize the first row of the DP table
    for(int i=0;i<=amount;i++){
        if(i % coins[0] == 0){
            prev[i] = i / coins[0];
        }else{
            // Set it to a very large value if not possible
            prev[i] = 1e9;
        }
    }
    for(int index=1;index<n;index++){
        // Create a vectors to store the current DP states
        vector<int>curr(amount+1, 0);

        for(int j=0;j<=amount;j++){
            // Calculate the minimum elements needed without taking the current element
            int notTake = 0 + prev[j];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9;
            if(coins[index] <= j){
                // in this line we use curr because we did not move to index-1, we remain at same index i..e curr is used instead of prev. dp[index][j - coins[index]];
                take = 1 + curr[j - coins[index]];
            }

            // Store the minimum of 'notTake' and 'take' in the current DP state
            curr[j] = min(take, notTake);
        }

        // Update the previous DP state with the current state for the next iteration
        prev=curr;
    }

    // The answer is in the bottom-right cell of the DP table
    int ans = prev[amount];
    
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9){
        return -1;
    }
    
    // Return the minimum number of elements needed
    return ans;
}


int main(){
    vector<int>coins={1,2,5};
    int amount = 11;

    // Recursion
    cout<<coinChange1(coins, amount)<<endl;

    // Memoization
    cout<<coinChange2(coins, amount)<<endl;

    // Tabulation
    cout<<coinChange3(coins, amount)<<endl;

    // Space optimization
    cout<<coinChange4(coins, amount)<<endl;
}

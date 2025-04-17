#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Input: nums = [1,5]
Output: 10

Intuition: 
https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/
*/


// Recursion ---------------------------------------------------------
int solve1(int i, int j, vector<int>nums){
    if(i>j) return 0;

    int maxi=INT_MIN;

    // Iterate through each possible balloon to burst last
    for(int k=i;k<=j;k++){
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i-1]*nums[k]*nums[j+1];

        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = solve1(i, k - 1, nums) + solve1(k + 1, j, nums);

        // Update the maximum coins
        maxi = max(maxi, coins + remainingCoins);
    }
    return maxi;
}
int maxCoins1(vector<int>nums) {
    // Time complexity: Exponential
    // Space complexity: O(N)
    
    int n=nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(),1);
    nums.push_back(1);

    return solve1(1, n, nums);
}



// Memoization--------------------------------------------------------
int solve2(int i, int j, vector<int>nums, vector<vector<int>>&dp){
    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxi=INT_MIN;

    // Iterate through each possible balloon to burst last
    for(int k=i;k<=j;k++){
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i-1]*nums[k]*nums[j+1];

        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = solve2(i, k - 1, nums, dp) + solve2(k + 1, j, nums, dp);

        // Update the maximum coins
        maxi = max(maxi, coins + remainingCoins);
    }
    return dp[i][j] = maxi;
}
int maxCoins2(vector<int>nums) {
    // Time complexity: O(N^3)
    // Spac complexity: O(N^N) + O(N)

    int n=nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(),1);
    nums.push_back(1);

    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    return solve2(1, n, nums, dp);
}



// Tabulation---------------------------------------------------------
int maxCoins3(vector<int>nums) {
    // Time complexity: O(N^3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
    // Space complexity: O(N*N)

    int n=nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(),1);
    nums.push_back(1);

    vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

    for(int i=n; i>=1; i--){
        for(int j=1; j<=n;j++){
            if (i > j) continue;

            int maxi=INT_MIN;

            // Iterate through each possible balloon to burst last
            for(int k=i;k<=j;k++){
                // Calculate the coins obtained by bursting the k-th balloon last
                int coins = nums[i-1]*nums[k]*nums[j+1];

                // Recursively calculate the maximum coins for the remaining balloons
                int remainingCoins = dp[i][k - 1] + dp[k + 1][j];

                // Update the maximum coins
                maxi = max(maxi, coins + remainingCoins);
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}


int main(){
    vector<int>nums={3,1,5,8};

    // Recursion
    cout<<maxCoins1(nums)<<endl;

    // Memoization
    cout<<maxCoins2(nums)<<endl;

    // Tabulation
    cout<<maxCoins3(nums)<<endl;
}
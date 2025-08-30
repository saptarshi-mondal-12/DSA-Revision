#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Jump Game II - AMAZON 2025 - 2 times

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Input: nums = [2,3,0,1,4]
Output: 2
*/

// Recursion soln -------------------------------------------------------------------------
int solve(int index, vector<int> &nums){
    int n = nums.size();

    // Base case 1: We reach our destination or we cross out destination
    if (index >= n - 1){
        return 0;
    }

    // Base case 2: We are at a position where we cannot take next jump - stuck, can't move
    if (nums[index] == 0){
        return 1e9;
    }

    int minSteps = 1e9;

    for (int i = 1; i <= nums[index]; i++){
        int jump = 1 + solve(index + i, nums);
        if (jump != 1e9){
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
}
int jump(vector<int> &nums){
    int result = solve(0, nums);
    return result;
}



// Memoization soln ---------------------------------------------------------------------------
int solve(int index, vector<int> &nums, vector<int> &dp){
    int n = nums.size();
    // Base case 1: We reach our destination or we cross out destination
    if (index >= n - 1){
        return 0;
    }

    // Base case 2: We are at a position where we cannot take next jump - stuck, can't move
    if (nums[index] == 0){
        return 1e9;
    }

    if (dp[index] != -1)
        return dp[index];

    int minSteps = 1e9;

    for (int i = 1; i <= nums[index]; i++){
        int jump = 1 + solve(index + i, nums, dp);
        if (jump != 1e9){
            minSteps = min(minSteps, jump);
        }
    }
    return dp[index] = minSteps;
}
int jump(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, -1);
    int result = solve(0, nums, dp);
    return result;
}



// Tabulation soln --------------------------------------------------------------------------
int jump(vector<int> &nums){
    int n = nums.size();

    // initializing large value = unreachable
    vector<int> dp(n, 1e9);

    // last index needs 0 jumps
    dp[n - 1] = 0;

    for (int index = n - 2; index >= 0; index--){
        for (int i = 1; i <= nums[index]; i++){
            int jump = 1e9;
            if (index + i < n){
                jump = 1 + dp[index + i];
            }
            dp[index] = min(dp[index], jump);
        }
    }
    return dp[0];
}




int main(){
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Partition Array for Maximum Sum

Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1

Intuition: using Front partition -. start from 0
https://takeuforward.org/data-structure/partition-array-for-maximum-sum-front-partition-dp-54/
*/

// Recursion----------------------------------------------------------------
int solve1(int i, int n, vector<int>nums, int k){
    // Base case: If the current index is equal to the size of the array, return 0.
    if (i == n) return 0;

    int len = 0;
    int maxiEle = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = i; j < min(i + k, n); j++) {
        len++;
        maxiEle = max(maxiEle, nums[j]);
        int sum = len * maxiEle + solve1(j + 1, n, nums, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}
int maxSumAfterPartitioning1(vector<int> nums, int k) {
    // Time complexity: Exponential
    // Space complexity: O(N)
    int n=nums.size();
    return solve1(0, n, nums, k);
}


// Memoization--------------------------------------------------------------
int solve2(int i, int n, vector<int>nums, int k, vector<int>&dp){
    // Base case: If the current index is equal to the size of the array, return 0.
    if (i == n) return 0;

    if(dp[i] != -1) return dp[i];

    int len = 0;
    int maxiEle = INT_MIN;
    int maxAns = INT_MIN;

    // Loop through the array starting from the current index.
    for (int j = i; j < min(i + k, n); j++) {
        len++;
        maxiEle = max(maxiEle, nums[j]);
        int sum = len * maxiEle + solve2(j + 1, n, nums, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[i]=maxAns;
}
int maxSumAfterPartitioning2(vector<int> nums, int k) {
    // Time complexity: O(N*k)
    // Space complexity: O(N) + O(N)

    int n=nums.size();
    vector<int>dp(n, -1);
    return solve2(0, n, nums, k, dp);
}



// Tabulation---------------------------------------------------------------
int maxSumAfterPartitioning3(vector<int> nums, int k) {
    // Time complexity: O(N*k)
    // Space complexity: O(N)
    
    int n=nums.size();
    vector<int>dp(n+2, 0);

    for(int i=n-1;i>=0;i--){
        int len = 0;
        int maxiEle = INT_MIN;
        int maxAns = INT_MIN;

        // Loop through the array starting from the current index.
        for (int j = i; j < min(i + k, n); j++) {
            len++;
            maxiEle = max(maxiEle, nums[j]);
            int sum = len * maxiEle + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[i]=maxAns;

    }
    return dp[0];
}


int main(){
    vector<int>nums={1,15,7,9,2,5,10};
    int k=3;

    // Recursion
    cout<<maxSumAfterPartitioning1(nums,k)<<endl;

    // Memoization
    cout<<maxSumAfterPartitioning2(nums,k)<<endl;

    // Tabulation
    cout<<maxSumAfterPartitioning3(nums,k)<<endl;
}
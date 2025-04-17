#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Input: nums = [0,1,0,3,2,3]
Output: 4

Input: nums = [7,7,7,7,7,7,7]
Output: 1


NOTE : To print the LIS below all solution won't works only Q.44 solution works
*/


// Recursion----------------------------------------------------------------------------
int solve1(int index, int prev_index, vector<int>&nums){
    // Base case
    if(index == nums.size()) return 0;

    int notTake = 0 + solve1(index+1, prev_index, nums);
    int take = 0;
    if(prev_index==-1 || nums[index] > nums[prev_index]){
        take = 1 + solve1(index+1, index, nums);
    }
    return max(take, notTake);
}
int lengthOfLIS1(vector<int>& nums) {
    // Time complexity: O(2^n)
    // Space complexity: O(n)

    int n=nums.size();
    return solve1(0,-1,nums);
}


// Memoization---------------------------------------------------------------------------
int solve2(int index, int prev_index, vector<int>&nums, vector<vector<int>>&dp){
    // Base case
    if(index == nums.size()) return 0;

    if(dp[index][prev_index+1] != -1) return dp[index][prev_index+1];

    int notTake = 0 + solve2(index+1, prev_index, nums, dp);
    int take = 0;
    if(prev_index == -1 || nums[index] > nums[prev_index]){
        take = 1 + solve2(index+1, index, nums, dp);
    }
    return dp[index][prev_index+1] = max(take, notTake);
}
int lengthOfLIS2(vector<int>& nums) {
    // Time complexity: O(N*N)
    // Space complexity: O(N*N) + O(n)

    int n=nums.size();
    vector<vector<int>>dp(n, vector<int>(n+1, -1));

    // NOTE: prev_index = -1 
    // but we cannot use -1 in dp. So we start with -1 and whenever we store we do a +1 to prev_index
    return solve2(0,-1,nums, dp);
}


// Tabulation---------------------------------------------------------------------------
int lengthOfLIS3(vector<int>& nums) {
    // Time complexity: O(N*N)
    // Space complexity: O(N*N)

    int n=nums.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

    // Base case : Now the base case is if(ind==n), we return 0. We can initialize the entire dp array as 0. In this way, we need to write the base case explicitly.

    // We will set for a loop of ind to range from n-1 to 0.
    // If we look closely at the recursive tree, we will see a pattern that the second parameter, prev_index is always smaller than the first parameter ind. Therefore we will write the for loop for prev_index to start from ind-1 till -1.

    for(int index = n-1; index >= 0 ; index--){
        for(int prev_index=index-1; prev_index >= -1; prev_index--){
            // NOTE: Second parameter always +1 state
            int notTake = 0 + dp[index+1][prev_index+1];
            int take = 0;
            if(prev_index == -1 || nums[index] > nums[prev_index]){
                take = 1 + dp[index+1][index+1];
            }

            dp[index][prev_index+1] = max(take, notTake);
        }
    }
    return dp[0][0];
}


// Space Optimization--------------------------------------------------------------------
int lengthOfLIS4(vector<int>& nums) {
    // Time complexity: O(N*N)
    // Space complexity: O(N)

    int n=nums.size();
    vector<int>nextRow(n+1, 0);
    vector<int>curr(n+1, 0);

    for(int index = n-1; index >= 0 ; index--){
        for(int prev_index=index-1; prev_index >= -1; prev_index--){
            // NOTE: Second parameter always +1 state
            int notTake = 0 + nextRow[prev_index+1];
            int take = 0;
            if(prev_index == -1 || nums[index] > nums[prev_index]){
                take = 1 + nextRow[index+1];
            }

            curr[prev_index+1] = max(take, notTake);
        }
        nextRow = curr;
    }
    return nextRow[0];
}



// Best solution using Binary search
int lengthOfLIS5(vector<int>& nums){
    // Time complexity: O(n log n)
    // Space complexity: O(n)

    int n=nums.size();

    // Create a temporary vector to store the increasing subsequence
    vector<int> temp;
    temp.push_back(nums[0]);

    int len = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > temp.back()) {
            // If arr[i] is greater than the last element of temp, extend the subsequence
            temp.push_back(nums[i]);
            len++;
        } else {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return len;
}



int main(){
    vector<int>nums={0,1,0,3,2,3};

    // Recursion
    cout<<lengthOfLIS1(nums)<<endl;

    // Memoization
    cout<<lengthOfLIS2(nums)<<endl;

    // Tabulation
    cout<<lengthOfLIS3(nums)<<endl;

    // Space optimization
    cout<<lengthOfLIS4(nums)<<endl;

    // Best solution - binary search 
    cout<<lengthOfLIS5(nums)<<endl;
}
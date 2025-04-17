#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Maximum sum of non-adjacent elements

Given an array of ‘N’  positive integers, we need to return the maximum sum of the subsequence such that no two elements of the subsequence are adjacent elements in the array.

Note: A subsequence of an array is a list with elements of the array where some elements are deleted ( or not deleted at all) and the elements should be in the same order in the subsequence as in the array.

Intuition: 
As we need to find the sum of subsequences, one approach that comes to our mind is to generate all subsequences and pick the one with the maximum sum. 
To generate all the subsequences, we can use the pick/non-pick technique. This technique can be briefly explained as follows:

At every index of the array, we have two options.
    First, to pick the array element at that index and consider it in our subsequence.
    Second, to leave the array element at that index and not to consider it in our subsequence.

First, we will try to form the recursive solution to the problem with the pick/non-pick technique. T

Step 1: Form the function in terms of indexes: 
We are given an array which can be easily thought of in terms of indexes. 
We can define our function f(ind) as : Maximum sum of the subsequence starting from index 0 to index ind.
We need to return f(n-1) as our final answer.

Step 2: do all stuffs on that index to reach the goal.
If we pick an element then, pick = arr[ind] + f(ind-2). The reason we are doing f(ind-2) is because we have picked the current index element so we need to pick a non-adjacent element so we choose the index ‘ind-2’ instead of ‘ind-1’.
Next we need to ignore the current element in our subsequence. So nonPick= 0 + f(ind-1). As we don’t pick the current element, we can consider the adjacent element in the subsequence.


Step 3: Take the maximum of all the choices
As the problem statement asks to find the maximum subsequence total, we will return the maximum of two choices of step2.


Base Conditions
If ind=0, then we know to reach at index=0, we would have ignored the element at index = 1. Therefore, we can simply return the value of arr[ind] and consider it in the subsequence.
If ind<0, this case can hit when we call f(ind-2) at ind=1. In this case we want to return to the calling function so we simply return 0 so that nothing is added to the subsequence sum.
*/

// Recursion-------------------------------------------------
int solve1(int index, vector<int>nums){
    // Base cases
    if(index==0){
        return nums[index];
    }
    if (index < 0){
        return 0;
    }

    // Choosing the current element and move to non adjacent index i.e index-2
    int pick = nums[index] + solve1(index-2, nums);
    // skipping the current element and move to adjacent index i.e index-1
    int notpick = 0 + solve1(index-1, nums);

    // Taking maximum
    return max(pick, notpick);
}
int maximumNonAdjacentSum(vector<int>nums){
    // Time complexity: O(n^2)
    // space complexity: O(n)

    // Intuition: choose the current element or skip it, and take the maximum

    int n=nums.size();
    return solve1(n-1, nums);
}


// Memoization-----------------------------------------------
int solve2(int index, vector<int>nums, vector<int>&dp){
    // Base cases
    if(index==0){
        return nums[index];
    }
    if (index < 0){
        return 0;
    }

    // If the result for this index is already computed, return it
    if (dp[index] != -1){
        return dp[index];
    }

    // Choose the current element or skip it, and take the maximum
    int pick = nums[index] + solve2(index-2, nums, dp); // Choosing the current element
    int notpick = 0 + solve2(index-1, nums, dp); // skip the current element

    // Store the result in the DP table and return it
    return dp[index]=max(pick, notpick);
}
int memo_maximumNonAdjacentSum(vector<int>nums){
    // Time complexity: O(n)
    // space complexity: O(n) + O(n) - recursion stack space + dp

    int n=nums.size();

    // Initialize the DP table with -1
    vector<int>dp(n, -1);

    // Start solving from the last element
    return solve2(n-1, nums, dp);
}


// Tabulation------------------------------------------------
int tabulation_maximumNonAdjacentSum(vector<int>nums){
    // Time complexity: O(n)
    // Space complexity: O(n)

    int n=nums.size();
    vector<int>dp(n);

    // Base case
    dp[0]=nums[0];

    // Iterate through the elements of the array
    for (int index = 1; index < n; index++){
        // Calculate the maximum value by either picking the current element or not picking it (i.e. taking the maximum of dp[i-2] + arr[i] and dp[i-1])

        int pick = nums[index];
        if (index > 1){
            pick += dp[index - 2];
        }
        int nonPick = dp[index - 1];
        
        // Store the maximum value in the dp array
        dp[index] = max(pick, nonPick);
    }
    return dp[n-1];
}


// Space optimization------------------------------------------
int spaceOptimize_maximumNonAdjacentSum(vector<int>nums){
    // Time complexity: O(n)
    // Space complexity: O(1)

    int n=nums.size();
    int prev2=0;
    int prev=nums[0];

    for (int index = 1; index < n; index++){
        // Maximum sum if we pick the current element sopick the current element and pick the non adjacent element i.e prev2
        int pick = nums[index];
        if (index > 1){
            pick += prev2; 
        }

        // Maximum sum if we don't pick the current element so skip the current element and pick the adjacent element i.e prev
        int nonPick = prev;
        
        // Maximum sum ending at the current element
        int cur_i = max(pick, nonPick);  
        
        // Update the maximum sum two elements ago
        prev2 = prev;   
        prev = cur_i;   
    }

    return prev;
}


int main(){
    vector<int>nums={2, 1, 4, 9};

    // Recursion solution - Time limit exceed 
    cout<<maximumNonAdjacentSum(nums)<<endl;

    // Memoization
    cout<<memo_maximumNonAdjacentSum(nums)<<endl;

    // Tabulation 
    cout<<tabulation_maximumNonAdjacentSum(nums)<<endl;

    // Space optimization
    cout<<spaceOptimize_maximumNonAdjacentSum(nums)<<endl;
}


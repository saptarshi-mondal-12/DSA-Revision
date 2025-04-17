#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Array partition with minimum difference

You are given an array 'arr' containing 'n' non-negative integers.
Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.

Note:
1. Each array element should belong to exactly one of the subsets.
2. Subsets need not always be contiguous.
For example, for the array : [1, 2, 3], some of the possible divisions are 
   a) {1,2} and {3}
   b) {1,3} and {2}.
3. Subset-sum is the sum of all the elements in that subset.


Input: 'n' = 5, 'arr' = [3, 1, 5, 2, 8].
Ouput: 1
Explanation: We can partition the given array into {3, 1, 5} and {2, 8}. 
This will give us the minimum possible absolute difference i.e. (10 - 9 = 1).

Input : arr = [1, 2, 3, 4]
Output : 0
Explanation: We can partition the given array into {2,3} and {1,4}. 
This will give us the minimum possible absolute difference i.e. (5 - 5 = 0) in this case.

Input : arr = [8, 6, 5]
Output : 3
Explanation : We can partition the given array into {8} and {6,5}. 
This will give us the minimum possible absolute difference i.e. (11 - 8 = 3).


Intuition: 

According to question we have to find the minimum sum between any two subsets. 
for e.g. nums=[1,2,3,4]
There can be multiple subsets and they are -
[1] & [2,3,4] absolute difference be sum of 2 subsets are : |1 - (2+3+4)| = 8
[1,2] & [3,4] : |3 - 7| = 4
[1,2,3] & [4] : |6 - 4| = 2
[1,3] & [2,4] : |4 - 6| = 2
[1,4] & [2,3] : |5 - 5| = 0
.
. 
so on 

In above example 0 is the minimum absolute difference between two subsets [1,4] & [2,3].

if i get the sum of subset1 and sum of subset 2 then then i can easily calculate the minimum absolute difference between any 2 subsets.

So what are my elements in subset 1? 
It can be [1] or [1,2] or [1,2,3] or [1,2,3,4] or [1,3] or [1,4] any thing else. 

Now my question arise what is the minimum and maximum sum that i can get in subset1?
it can be from 0 to totalSum because . 
subset1 may have 0 element. subset1=[], subset2=[1,2,3,4] 
and subset1 can have all element means totalSum. subset1=[1,2,3,4], subset2=[0] 


So i write a for loop (0 -> totalSum) and check for all possible target that can be achieved or not. if i achieve the target i.e sum (sum(subset1)) then i can easily calculate the sum for subset2. 

In this question, we need to partition the array into two subsets( say with sum S1 and S2) and we need to return the minimized absolute difference of S1 and S2. But do we need two variables for it? The answer is No. We can use a variable totSum, which stores the sum of all elements of the input array, and then we can simply say S2 = totSum - S1. Therefore we only need one variable S1.

if i have total sum of the array and sum of subset1 i.e s1 then i can automaticaly get the sum of subset2 by subtracting totalSum and s1. 

s1 = sum of subset1 
s2 = sum of subset2
totalSum = total sum of array 

s1 + s2 = totalSum
s2 = totalSum - s1

After this - i have s1, s2 and i have to find minimum between these two subsets

maxi = 1e9 
result = min(maxi, abs(s1 - s2))

At last i am going to return result

Now i have to write a function that can tell me if x sum is possible or not. for that i can use subset sum problem  approach where i have given a target and I have to determine if there is a subset of arr[] with sum equal to given target. 

Eg. nums=[3,2,7] 
totalSum=12 

dp of last row : 
      [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
dp[2]=[T, F, T, T, F, T, F, T, F, T,  T,  F,  T]

This can all be my sum(subset1)
d[2][0] can be achieved with a target of 0
d[2][2] can be achieved with a target of 2
d[2][3] can be achieved with a target of 3
d[2][5] can be achieved with a target of 5
d[2][7] can be achieved with a target of 7
d[2][9] can be achieved with a target of 9
d[2][10] can be achieved with a target of 10
d[2][12] can be achieved with a target of 12


corrsponding Sum(subset2) will be
s1 = 0, s2 = 12 |s1-s2| = 12
s1 = 2, s2 = 10 |s1-s2| = 8
s1 = 3, s2 = 9  |s1-s2| = 6
s1 = 5, s2 = 7  |s1-s2| = 2
s1 = 7, s2 = 5  |s1-s2| = 2
s1 = 9, s2 = 3  |s1-s2| = 6
s1 = 10, s2 = 2 |s1-s2| = 8
s1 = 12, s2 = 0 |s1-s2| = 12

minimum is 2. So 2 is our answer


Q. In Memoization/Tabulation approach what does if (dp[n - 1][i] == true) means or what does dp[i][j] signifies?
Ans:  In subset sum problem, we find our answer in dp[n-1][target] we return true or false.
Last row represent that did i acheive the target or not. 

Suppose nums = [1,3,9,6,8], target is = 7 
      [0, 1, 2, 3, 4, 5, 6, 7]
d[n-1][T, T, F, T, T, F, T, T]

last row in dp signifies that 
if from 0 to last index did i achieve target 0 or not : True : in the entire array target 0 can be achieved by picking 0 element
if from 0 to last index did i achieve target 1 or not - T
if from 0 to last index did i achieve target 2 or not - False
if from 0 to last index did i achieve target 3 or not - T
if from 0 to last index did i achieve target 4 or not - T
if from 0 to last index did i achieve target 5 or not - F
if from 0 to last index did i achieve target 6 or not - T
if from 0 to last index did i achieve target 7 or not - T

I can tell yes or no for every target value from 1 to 7. i can definetely say yes/no. 
our target is 7 dp[4][7] = true -> this is our answer 

this dp (last row) will strictly help you to tell if can can achieve a target 7 or not. this is what tabulation siginifies. 

With the help this that is we are going to solving our current problem.

Tabulation approach: 
Our work is very simple, using the last row of the dp array, we will first find which all S1 values are valid. Using the valid S1 values, we will find S2 (totSum - S1). From this S1 and S2, we will find their absolute difference. We will return the minimum value of this absolute difference as our answer.
*/

// Recursion-------------------------------------------------------------------
bool solve1(int index, int target, vector<int>&arr){
    // Base case 1: If the target sum is 0, we have found a subset
    if(target == 0){
        return true;
    }

    // Base case 2: If we have reached the first element in 'arr'
    if(index==0){
        return arr[0] == target;
    }
    
    // Try not taking the current element into the subset
    bool notTake = solve1(index-1, target, arr);
    
    // Try taking the current element into the subset if it doesn't exceed the target
    bool take = false;
    if(arr[index] <= target){
        take = solve1(index-1, target-arr[index], arr);
    }
    // if any one is true return true
    return notTake || take;
}
int minSubsetSumDifference1(vector<int>& nums, int n){
    // Time complexity: O(N*totalSum) +O(N) +O(N)
    // Space complexity: O(N)

    // Calculating total sum of the array
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }

    // mimimum difference between two subsets in the array
    int mini = 1e9;
    for (int target = 0; target <= totalSum; target++) {

        // if target is possible in the array taht means we get our subset1 i.e s1
        if (solve1(n-1, target, nums)) {

            // sum of subset1 
            int s1 = target;

            // sum of subset2
            int s2= totalSum - s1;

            // Calculate the absolute difference between two subset sums
            int diff = abs(s1 - s2);
            mini = min(mini, diff);
        }
    }
    return mini;
}



// Memoization : Reduce repetative calculation using dp -------------------------
bool solve2(int index, int target, vector<int>&arr, vector<vector<int>>&dp){
    if(target == 0){
        return true;
    }
    if(index==0){
        return arr[0] == target;
    }
    
    // If the result for this subproblem has already been computed, return it
    if (dp[index][target] != -1){
        return dp[index][target];
    }
    
    bool notTake = solve2(index-1, target, arr, dp);
    
    bool take = false;
    if(arr[index] <= target){
        take = solve2(index-1, target-arr[index], arr, dp);
    }
    
    // Store the result in the dp array to avoid recomputation
    return dp[index][target] = notTake || take;
}
int minSubsetSumDifference2(vector<int>& nums, int n){
    // Time complexity: O(N*totalSum) +O(N) +O(N)
    // Space complexity: O(N*totalSum) + O(N)


    // Calculating total sum of the array
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }

    // Initialize a 2D DP array for memoization
    vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));

    // Calculate the subset sum for each possible sum from 0 to the totalSum
    for (int i = 0; i <= totalSum; i++) {
        bool dummy = solve2(n - 1, i, nums, dp);
    }

    // mimimum difference between two subsets in the array
    int mini = 1e9;
    for (int target = 0; target <= totalSum; target++) {

        // if target is possible in the array, means we get our sum of subset1 i.e s1
        if (dp[n-1][target] == true) {

            // sum of subset1 
            int s1 = target;

            // sum of subset2
            int s2= totalSum - s1;

            // Calculate the absolute difference between two subset sums
            int diff = abs(s1 - s2);
            mini = min(mini, diff);
        }
    }
    return mini;
}



// Tabulation-------------------------------------------------------------------
int minSubsetSumDifference3(vector<int>& nums, int n){
    // Time complexity: O(N*totalSum) +O(N) +O(N)
    // Space complexity: O(N*totalSum) 

    // Calculate the total sum of the array
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    // Initialize the first row based on the first element of the array
    if(nums[0] <= totalSum){
        dp[0][totalSum] = true;
    }

    for(int i=1;i<n;i++){
        for(int j=1; j<=totalSum;j++){
            bool notTake = dp[i-1][j];
            bool take=false;
            if(nums[i] <= j){
                take = dp[i-1][j-nums[i]];
            }
            dp[i][j] = take || notTake;
        }
    }

    int mini = 1e9;
    for (int i = 0; i <= totalSum; i++) {
        if (dp[n - 1][i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totalSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}



// Space optimization------------------------------------------------------------
int minSubsetSumDifference4(vector<int>& nums, int n){
    // Time complexity: O(N*totalSum) +O(N) +O(N)
    // Space complexity: O(totalSum) 

    // Calculate the total sum of the array
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }
    vector<bool>prev(totalSum + 1, false);

    // Base case: If no elements are selected (sum is 0), it's a valid subset
    for(int i=0;i<n;i++){
        prev[0]=true;
    }

    // Initialize the first row based on the first element of the array
    if(nums[0] <= totalSum){
        prev[totalSum] = true;
    }

    for(int i=1;i<n;i++){
        vector<bool>curr(totalSum + 1, false);
        curr[0] = true;
        for(int j=1; j<=totalSum;j++){
            bool notTake = prev[j];
            bool take=false;
            if(nums[i] <= j){
                take = prev[j-nums[i]];
            }
            curr[j] = take || notTake;
        }
        prev=curr;
    }

    int mini = 1e9;
    for (int i = 0; i <= totalSum; i++) {
        if (prev[i] == true) {
            // Calculate the absolute difference between two subset sums
            int diff = abs(i - (totalSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}


int main(){
    vector<int>nums={3,2,7};

    // Recursion 
    cout<<minSubsetSumDifference1(nums, 3)<<endl;

    // Memoization 
    cout<<minSubsetSumDifference2(nums, 3)<<endl;

    // Tabulation 
    cout<<minSubsetSumDifference3(nums, 3)<<endl;

    // Space optimization 
    cout<<minSubsetSumDifference4(nums, 3)<<endl;
}

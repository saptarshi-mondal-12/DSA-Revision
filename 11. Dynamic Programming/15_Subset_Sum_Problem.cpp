#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Subset Sum Problem

Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.

Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.



Intuition: 
Step 1: Express the problem in terms of indexes.
The array will have an index but there is one more parameter “target”. We are given the initial problem to find whether there exists in the whole array a subsequence whose sum is equal to the target.

So, we can say that initially, we need to find(n-1, target) which means that we need to find whether there exists a subsequence in the array from index 0 to n-1, whose sum is equal to the target. Similarly, we can generalize it for any index ind as follows:

Base Cases:
    If target == 0, it means that we have already found the subsequence from the previous steps, so we can return true.
    If ind==0, it means we are at the first element, so we need to return arr[ind]==target. If the element is equal to the target we return true else false.

Step 2: Try out all possible choices at a given index.
We need to generate all the subsequences. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”.

We have two choices:
    Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index element. For this, we will make a recursive call to f(ind-1,target).

    Include the current element in the subsequence: We will try to find a subsequence by considering the current index as element as part of subsequence. As we have included arr[ind], the updated target which we need to find in the rest if the array will be target - arr[ind]. Therefore, we will call f(ind-1,target-arr[ind]).

Step 3:  Return (taken || notTaken)
As we are looking for only one subset, if any of the one among taken or not taken returns true, we can return true from our function. Therefore, we return ‘or(||)’ of both of them.


*/

// Recursion------------------------------------------------------------------
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
bool isSubsetSum1(vector<int>& arr, int target) {
    // Time complexity: O(N*K)
    // space complexity: O(N) recursion stack space
    
    // recursion - Top down approach (n-1 to 0)
    int n=arr.size();
    return solve1(n-1, target, arr);
}


// Memoization------------------------------------------------------------------
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

bool isSubsetSum2(vector<int>& arr, int target) {
    // Time complexity: O(N*K)
    // space complexity: O(N*K) + O(N)
    
    // Memoization - using 2D dp
    
    int n=arr.size();
    
    // Initialize a 2D DP array for memoization
    vector<vector<int>>dp(n,vector<int>(target+1,-1));

    return solve2(n-1, target, arr, dp);
}


// Tabulation-------------------------------------------------------------------
bool isSubsetSum3(vector<int>& arr, int target) {
    // Time complexity: O(N*K)
    // space complexity: O(N*K)

    /* Tabulation - opposite of recursion i.e (0 to n-1)
    First, we need to initialize the base conditions of the recursive solution.

    If target == 0, ind can take any value from 0 to n-1, therefore we need to set the value of the first column as true.

    The first row dp[0][] indicates that only the first element of the array is considered, therefore for the target value equal to arr[0], only cell with that target will be true, so explicitly set dp[0][arr[0]] =true, (dp[0][arr[0]] means that we are considering the first element of the array with the target equal to the first element itself). Please note that it can happen that arr[0]>target, so we first check it: if(arr[0]<=target) then set dp[0][arr[0]] = true..
    */

    int n=arr.size();
    
    // Initialize a 2D DP array with dimensions (n x k+1) to store subproblem results
    vector<vector<bool>>dp(n,vector<bool>(target+1, false));
    
    // Base case 1: If the target sum is 0, we can always achieve it by taking no elements
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    
    // Base case 2: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    // at index 0, can i form this target this target arr[0] and the answer is yes because at only on arr[0] array you can form a target arr[0]. You can't create form apart from that.
    if (arr[0] <= target) {
        dp[0][arr[0]] = true;
    }
    
    // 0 is completed so start from 1
    for(int index=1; index<n; index++){
        // target i.e j : (In recursion we started from target to 0 and in tabulation we move opposite i.e from 1 to target because 0 has been already done in line no 145)
        for (int j = 1; j <= target; j++){
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = dp[index - 1][j];

            // If we take the current element, subtract its value from the target i.e, j and check the previous row
            bool taken = false;
            if (arr[index] <= j) {
                taken = dp[index - 1][j - arr[index]];
            }

            // Store the result in the DP array for the current subproblem
            dp[index][j] = notTaken || taken;
        }
    }
    // The final result is stored in dp[n-1][k]
    return dp[n-1][target];
}


// Space optimization-----------------------------------------------------------
bool isSubsetSum4(vector<int>& arr, int target) {
    // Time complexity: O(N*K)
    // space complexity: O(K)

    /*If we closely look the relation, dp[ind][target] =  dp[ind-1][target] || dp[ind-1][target-arr[ind]]
    We see that to calculate a value of a cell of the dp array, we need only the previous row values (say prev). So, we don’t need to store an entire array. Hence we can space optimize it.*/

    int n=arr.size();
    
    // Initialize a vector 'prev' to store the previous row of the DP table
    vector<bool> prev(target + 1, false);
    
    // Base case: If the target sum is 0, we can always achieve it by taking no elements
    prev[0] = true;
    
    // Base case: If the first element of 'arr' is less than or equal to 'k', set prev[arr[0]] to true
    if (arr[0] <= target) {
        prev[arr[0]] = true;
    }

    
    for(int index=1; index<n; index++){
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<bool> curr(target + 1, false);
        
        // Base case: If the target sum is 0, we can achieve it by taking no elements
        curr[0] = true;
        
        for (int j = 1; j <= target; j++){
            // If we don't take the current element, the result is the same as the previous row
            bool notTaken = prev[j];

            // If we take the current element, subtract its value from the target and check the previous row
            bool taken = false;
            if (arr[index] <= j) {
                taken = prev[j - arr[index]];
            }

            // Store the result in the DP array for the current subproblem
            curr[j] = notTaken || taken;
        }
        // Update 'prev' with the current row 'cur' for the next iteration
        prev=curr;
    }

    // The final result is stored in prev[target]
    return prev[target];
}


int main(){
    vector<int>arr={2,1,0,4,2,9};
    int target = 3;

    // Recursion 
    cout<<isSubsetSum1(arr, target)<<endl;

    // Memoization 
    cout<<isSubsetSum2(arr, target)<<endl;

    // Tabulation 
    cout<<isSubsetSum3(arr, target)<<endl;

    // Space optimization 
    cout<<isSubsetSum4(arr, target)<<endl;
}


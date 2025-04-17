#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count All Subsets with Sum equal to K

Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.


Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.


Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.


Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.

Intuition :
We can try to generate all subsequences using recursion and whenever we get a single subsequence whose sum is equal to the given target, we can count it.
Same as subset sum problem. In subet sum problem we check if target exist and in this problem we add all subsets that is equal to target,
So return take + nottake

Recursion Base case 1 Explanation :

E.g = [0,0,1], target = 1 
ans=4 because there are 4 sunsets with target sum 1 and they are: [0,1],[0,1],[0,0,1],[1]. 
So we have to consider all zeros. 
Addition of 0 or removal 0 never alter the sum. This is the idea that will take into consideration.

Lets think.... 

if i am standing at index 0 . i have single element arr[0] and imagin if target is 0 and arr[0]=0. What options do we have? 
Ans: we can take this 0 into my subsequence or either not take i into my subsequence (both ways do not alter my sum)
There are 2 option for single guy either i take 0 or not take 0. there are 2 possibel case (taking it not taking it)

when we are at index 0, if the target sum is 0 and the first index is also 0, like in case [0,1], we can form the subset in two ways, either by considering the first element or leaving it, so we can return 2.


1st case :  if(target==0 && arr[0]==0){
                return 2;
            } 

Let's think other case i am at index 0 and arr[0]=5 and target is 0. if i decide to take this 5 my target will alter i.e target become -5 which is problem. Just 1 way not take 
or if arr[0]=5 and target is 5 if i not take it then target will not go to 0 which is problem and if take it the target become 0. So Just 1 way take it. 

Else at index 0, if target == 0, and the first element is not 0, it means we will not pick the first element so we just return 1 way.

Or if at index 0, when the first element is not 0, and the target is equal to the first element , then we will include it in the subset and we will return 1 way.


2nd case:   if(target==0 || target == arr[0]){
                return 1;
            }           
*/

// Recursion-------------------------------------------------------------------
int solve1(int index, int target, vector<int>arr){
    // Base case 1: 
    if(index == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    // Try not taking the current element into the subset
    int notTake = solve1(index-1, target, arr);
    
    // Try taking the current element into the subset if it doesn't exceed the target
    int take = 0;
    if(arr[index] <= target){
        take = solve1(index-1, target-arr[index], arr);
    }
    // return the sum of taken and notTaken from our recursive call.
    return notTake + take;
}
int countAllSubsetsEqualToK1(vector<int>nums, int target){
    // Time complexity: O(n*target) 
    // space complexity: O(n)

    int n=nums.size();
    return solve1(n-1, target, nums);
}


// Memoization------------------------------------------------------------------
int solve2(int index, int target, vector<int>arr, vector<vector<int>>& dp){
    // Base case 1: 
    if(index == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[index][target] != -1){
        return dp[index][target];
    }
    
    // Try not taking the current element into the subset
    int notTake = solve2(index-1, target, arr, dp);
    
    // Try taking the current element into the subset if it doesn't exceed the target
    int take = 0;
    if(arr[index] <= target){
        take = solve2(index-1, target-arr[index], arr, dp);
    }
    // return the sum of taken and notTaken from our recursive call.
    return dp[index][target] = notTake + take;
}
int countAllSubsetsEqualToK2(vector<int>nums, int target){
    // Time complexity: O(n*target) 
    // space complexity: O(n) + O(n*target)

    int n=nums.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return solve2(n-1, target, nums, dp);
}


// Tabulation-------------------------------------------------------------------
int countAllSubsetsEqualToK3(vector<int>nums, int target){
    // Time complexity: O(n*target)
    // space complexity: O(n*target)

    int n=nums.size();

    // Create a dp array of size [n][target+1]. The size of the input array is ‘n’, so the index will always lie between ‘0’ and ‘n-1’. The target can take any value between ‘0’ and ‘k’.
    vector<vector<int>>dp(n, vector<int>(target+1, 0));

    // If nums[0] is zero, then two subsets exist for sum 0: `{}` and `{0}`
    // first parameter [0] represent index and second parameter represent sum [0][0]
    if (nums[0] == 0) { // 2 cases -pick and not pick
        dp[0][0] = 2;
    }
    else{ // 1 case - not pick
        dp[0][0] = 1;
    }

    // The first row dp[0][] indicates that only the first element of the array is considered, therefore for the target value equal to arr[0], only cell with that target will be true, so explicitly set dp[0][arr[0]] =1, (dp[0][arr[0]] means that we are considering the first element of the array with the target equal to the first element itself). Please note that it can happen that arr[0]>target, so we first check it: if(arr[0]<=target) then set dp[0][arr[0]] = 1. in other words - Till first index(0th index) did i achieve the target i.e (nums[0]) or not. if(arr[0]<=target) means we achieved (true) otherwise false 

    /* Suppose nums[0]=5 and target =5 then their is only 1 way which is correct but this will fail what if 
    nums[0]=0 and dp[0][nums[0]] which is dp[0][0] become 1 which is false 

    if it has 5 only 1 way if it has 0 should have 2 ways
    */
    // Initialize the first row based on the first element of the array
    if(nums[0]!=0 && nums[0]<=target){
        dp[0][nums[0]] = 1;  // 1 case -pick
    }

    // Fill in the DP table using a bottom-up approach
    for (int index = 1; index < n; index++) {
        for (int j = 0; j <= target; j++) {
            // Exclude the current element
            int notTaken = dp[index - 1][j];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (nums[index] <= j) {
                taken = dp[index - 1][j - nums[index]];
            }

            // Update the DP table
            dp[index][j] = notTaken + taken;
        }
    }

    // The final result is in the last cell of the DP table
    return dp[n - 1][target];
}

// Space optimization------------------------------------------------------------
int countAllSubsetsEqualToK4(vector<int>nums, int target){
    // Time complexity: O(N*target)
    // space complexity: O(target)

    int n=nums.size();

    // Initialize a vector 'prev' to store the previous row of the DP table
    vector<int> prev(target + 1, 0);
    
    // Base case
    if (nums[0] == 0) {
        prev[0] = 2;
    }else{
        prev[0]=1;
    }

    if(nums[0]!=0 && nums[0]<=target){
        prev[nums[0]] = 1;  // 1 case -pick
    }
    
    for(int index=1; index<n; index++){
        // Initialize a new row 'cur' to store the current state of the DP table
        vector<int> curr(target + 1, 0);
        
        // Base case: If the target sum is 0, we can achieve it by taking no elements
        curr[0] = 1;
        
        for (int j = 0; j <= target; j++){
            // If we don't take the current element, the result is the same as the previous row
            int notTaken = prev[j];

            // If we take the current element, subtract its value from the target and check the previous row
            int taken = 0;
            if (nums[index] <= j) {
                taken = prev[j - nums[index]];
            }

            // Store the result in the DP array for the current subproblem
            curr[j] = notTaken + taken;
        }
        // Update 'prev' with the current row 'cur' for the next iteration
        prev=curr;
    }

    // The final result is stored in prev[target]
    return prev[target];
}


int main(){
    vector<int>nums={0,0,1};
    int target=1;

    // Recursion 
    cout<<countAllSubsetsEqualToK1(nums, target)<<endl;

    // Memoization 
    cout<<countAllSubsetsEqualToK2(nums, target)<<endl;

    // Tabulation 
    cout<<countAllSubsetsEqualToK3(nums, target)<<endl;

    // Space optimization 
    cout<<countAllSubsetsEqualToK4(nums, target)<<endl;
}

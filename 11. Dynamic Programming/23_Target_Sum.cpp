#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q 494. Target Sum

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


Input: nums = [1], target = 1
Output: 1




-----Intuition: Same answer - Count partition with given difference d

The first approach that comes to our mind is to generate all subsequences and try both options of placing ‘-’ and ‘+’ signs and count the expression if it evaluates the answer.
This surely will give us the answer but can we try something familiar to the previous problems we have solved?

The answer is yes! We can use the concept we studied in the following article Count Partitions with Given Difference (DP – 18).

The following insights will help us to understand intuition better:

If we think deeper, we can say that the given ‘target’ can be expressed as addition of two integers (say S1 and S2). 
S1 + S2 = target   – (i)

Now, from where will this S1 and S2 come?  If we are given the array as [a,b,c,d,e], we want to place ‘+’ or ‘-’ signs in front of every array element and then add it. One example is :
+a-b-c+d+e which can be written as (+a+d+e) + (-b-c).

Therefore, we can say that S1=(+a+d+e) and S2=(-b-c) for this example.

 If we calculate the total sum of elements of the array (say totSum), we can can say that,
S1 = totSum - S2      – (ii)

Now solving for equations (i) and (iii), we can say that 
S2 = (totSum - target)/2    – (iv)

Therefore this question is modified to “Count Number of subsets with sum (totSum - target)/2 ”. This is exactly what we had discussed in the article  Count Subsets with Sum K.

Edge Cases:

The following edge cases need to be handled:

As the array elements are positive integers including zero, we don’t want to find the case when S2 is negative or we can say that totSum is lesser than D, therefore if totSum<target, we simply return 0.
S2 can’t be a fraction, as all elements are integers, therefore if totSum - target is odd, we can return 0.
From here on we will discuss the approach to “Count Subsets with Sum K” with the required modifications. Moreover, as the array elements can also contain 0, we will handle it as discussed in part-1 of this article.
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
int countPartitions1(vector<int>& arr, int d) {
    // Time complexity: O(N*target)
    // Space complexity: O(N)

    int n=arr.size();

    // Total Sum of array
    int totalSum = 0;
    for(int i=0; i<arr.size();i++){
        totalSum+= arr[i];
    }
    
    //Checking for edge cases
    if(totalSum-d < 0) return 0;
    if((totalSum-d) % 2 != 0) return 0;
    
    int s2 = (totalSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return solve1(n-1,s2,arr);
    
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
int countPartitions2(vector<int>& arr, int d) {
    // Time complexity: O(n) + O(N*target)
    // Space complexity: O(N*target) + O(N)

    int n=arr.size();

    // Total Sum of array
    int totalSum = 0;
    for(int i=0; i<arr.size();i++){
        totalSum+= arr[i];
    }
    
    //Checking for edge cases
    if(totalSum-d < 0) return 0;
    if((totalSum-d) % 2 != 0) return 0;
    
    int s2 = (totalSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return solve2(n-1,s2,arr,dp);
    
}



// Tabulation------------------------------------------------------------------
int countPartitions3(vector<int>& arr, int d) {
    // Time complexity: O(N) + O(N*target) 
    // Space complexity: O(N*target)

    int n=arr.size();

    // Total Sum of array
    int totalSum = 0;
    for(int i=0; i<arr.size();i++){
        totalSum+= arr[i];
    }
    
    //Checking for edge cases
    if(totalSum-d < 0) return 0;
    if((totalSum-d) % 2 != 0) return 0;
    
    int s2 = (totalSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,0));

    if (arr[0] == 0) { // 2 cases -pick and not pick
        dp[0][0] = 2;
    }
    else{ // 1 case - not pick
        dp[0][0] = 1;
    }

    int target = s2;
   
    if(arr[0]!=0 && arr[0]<=target){
        dp[0][arr[0]] = 1;  // 1 case -pick
    }

    for (int index = 1; index < n; index++) {
        for (int j = 0; j <= target; j++) {

            // Exclude the current element
            int notTaken = dp[index - 1][j];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (arr[index] <= j) {
                taken = dp[index - 1][j - arr[index]];
            }
            dp[index][j] = notTaken + taken;
        }
    }
    return dp[n - 1][target];
}


// Space optimization-----------------------------------------------------------
int countPartitions4(vector<int>& arr, int d) {
    // Time complexity: O(N) + O(N*target)
    // Space complexity:  O(target)

    int n=arr.size();

    // Total Sum of array
    int totalSum = 0;
    for(int i=0; i<arr.size();i++){
        totalSum+= arr[i];
    }
    
    //Checking for edge cases
    if(totalSum-d < 0) return 0;
    if((totalSum-d) % 2 != 0) return 0;
    
    int s2 = (totalSum-d)/2;
    
    vector<int> prev(s2+1,0);

    if (arr[0] == 0) {
        prev[0] = 2;
    }
    else{
        prev[0] = 1;
    }

    int target = s2;
   
    if(arr[0]!=0 && arr[0]<=target){
        prev[arr[0]] = 1; 
    }

    for (int index = 1; index < n; index++) {
        vector<int> curr(s2 + 1, 0);
        curr[0] = 1;

        for (int j = 0; j <= target; j++) {

            // Exclude the current element
            int notTaken = prev[j];

            // Include the current element if it doesn't exceed the target
            int taken = 0;
            if (arr[index] <= j) {
                taken = prev[j - arr[index]];
            }
            curr[j] = notTaken + taken;
        }
        prev=curr;
    }
    return prev[target];
}




int main(){
    vector<int>nums={1,1,1,1,1};
    int target=3;

    cout<<countPartitions1(nums, target)<<endl;

    cout<<countPartitions2(nums, target)<<endl;

    cout<<countPartitions3(nums, target)<<endl;

    cout<<countPartitions4(nums, target)<<endl;
}

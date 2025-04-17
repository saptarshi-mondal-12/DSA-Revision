#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Count partitions with given difference

Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 

Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2

Intuition: --------------------------------- 

S1 = sum of subset 1
S2 = sum of subset 2
totalSum = total sum of array

We have the following two conditions.
    1. [S1 >= S2]      ---> (Equation - 1)
    2. [S1 - S2 = D]   ---> (Equation - 2)
    

If we calculate the total sum of elements of the array (say totalSum), we can say that,
    S1 + S2 = totalSum
    S2 = totalSum - S1

    3. [S1 = totalSum - S2]  ---> (Equation - 3)

Now solving for equations (2) and (3), we can say that, by substituting the value of S1 in equation 2 we get
    S1 - S2 = D 
    totalSum - S2 - S2 = D
    totalSum - D = S2 + S2
    totalSum - D = 2 * S2 

    4. S2 = (totalSum - D)/2  ---> (Equation - 4)

Therefore the question “Count Partitions with a difference D” is boil down to “Count all subsets with sum equal to K. here k is -> (totSum - D)/2 ”. This is exactly what we had discussed in the article Count all Subsets with Sum K.
Same code here target = S2.

Edge Cases:

1. (totalSum - D) greater than equal to 0 why ? what is S2 = Sum of a subsets and array elements are greater than 0 then how can a sum of a subset be -ve, Therefore we don’t want to find the case when S2 is negative or we can say that totalSum is lesser than D (totSum<D), we simply return 0.

2. (totalSum - D) has to be even because S2 can’t be a fraction, as all elements are integers, therefore if totSum - D is odd, we can return 0.

Q. Question arise why s2 cannot be odd? 
Ans: because if (totalSum - d) is odd it becomes a fraction (e.g 3/2 = 1.5) which is not possible i.e (totalSum - D) has to be even.
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

    vector<int>nums={1, 2, 1, 0, 1, 3, 3};
    int d=11;

    // Recursion 
    cout<<countPartitions1(nums, d)<<endl;

    // Memoization 
    cout<<countPartitions2(nums, d)<<endl;

    // Tabulation 
    cout<<countPartitions3(nums, d)<<endl;

    // Space optimization 
    cout<<countPartitions4(nums, d)<<endl;
}

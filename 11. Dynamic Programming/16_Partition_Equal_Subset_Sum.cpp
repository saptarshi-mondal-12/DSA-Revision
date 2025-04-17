#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Partition Equal Subset Sum

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

Intuition: 
This question is a slight modification of the problem discussed in Subset-sum equal to target. 
We need to partition the array(say S) into two subsets(say S1 and S2). According to the question:

We have to find 2 subsets from the given array. Sum of subset 1 should equal to Sum of subset 2. if totalSum is odd we cannot find two subsets of equal sum, so return false. 
And if it is even we try to find 1 subsets with target = totalSum / 2 in the given array. if 1 subsets is found the remaining elements sum will be automaticall be subsets 2. so return true

totalSum = S1 + S2 (Sum of elements of S1 + sum of elements of S2 = sum of elements of totalSum).
S1 = S2 (Sum of elements of S1 = sum of elements of S2).
These two conditions imply that S1 = S2 = (totalSum/2). 

Now, 
    If S (sum of elements of the input array) is odd , there is no way we can divide it into two equal halves, so we can simply return false.
    If S is even, then we need to find a subsequence in the input array whose sum is equal to S/2 because if we find one subsequence with sum S/2, the remaining elements sum will be automatically S/2. So, we can partition the given array. Hence we return true.

So we use the solution of Subset-sum equal to target -> to find 1 subsequence with target = S/2 in the array. the remaining elements sum in the array will be automatically S/2. Hence, we partition the array into 2 equal subsets, return true.
*/

bool isSubsetSum(vector<int>& arr, int target) {
    // Time complexity: O(N*K)
    // space complexity: O(K)

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

bool canPartition(vector<int>& nums) {
    // Time compexity: O(N*K) +O(N)
    // space complexity: O(target)

    int n=nums.size();

    // Calculate the total sum of the array
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }

    // If the total sum is odd, it cannot be partitioned into two equal subsets
    if(totalSum%2 != 0) return false;

    // if total sum is even, we find only 1 subsequence with target = totalSum/2 in the array.
    int target=totalSum/2;
    if(isSubsetSum(nums, target)){
        return true;
    }
    return false;  
}



int main(){
    vector<int>arr={5,5,1,2,3,4,2};
    if (canPartition(arr))
        cout << "True - The Array can be partitioned into two equal subsets";
    else
        cout << "False - The Array cannot be partitioned into two equal subsets";
}

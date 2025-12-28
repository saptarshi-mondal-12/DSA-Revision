#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Q. Maximum Subarray Sum With Length Divisible by K

You are given an array of integers nums and an integer k.
Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

Input: nums = [1,2], k = 1
Output: 3
Explanation: The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

Input: nums = [-1,-2,-3,-4,-5], k = 4
Output: -10
Explanation: The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

Input: nums = [-5,1,2,-3,4], k = 2
Output: 4
Explanation: The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.
*/


long long brute_maxSubarraySum(vector<int>& nums, int k) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)

    int n = nums.size();
    long long int result=INT_MIN;

    if(n==1) return nums[0];

    for(int i=0;i<n;i++){
        long long int currSum=0;
        for(int j=i;j<n;j++){
            currSum+=nums[j];
            int size = j-i+1;

            if(size%k == 0){
                result=max(result, currSum);
            }
        }
    }
    return result;
}


long long optimal_maxSubarraySum(vector<int>& nums, int k) {
    // Time complexity: O(n)
    // Space complexity: O(k)
    

    int n = nums.size();
    if(n==1) return nums[0];

    long long maxSum=LONG_LONG_MIN;
    long long currSum = 0;

    vector<long long>kSum(k, LONG_LONG_MAX/2);
    kSum[k-1]=0;

    for(int i=0;i<n;i++){
        currSum += nums[i];
        maxSum = max(maxSum, currSum - kSum[i%k]);
        kSum[i%k]=min(kSum[i%k], currSum);
    }
    return maxSum;    
}

int main(){

    vector<int>nums={1,2,3,4,5,6,7,8,9};
    int k = 3;

    // 1. brute soln
    cout<<brute_maxSubarraySum(nums, k)<<endl;

    // 2. optimal soln
    cout<<optimal_maxSubarraySum(nums, k)<<endl;

}
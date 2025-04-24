#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q.  Minimum Size Subarray Sum - same question as 65 but not contains -ve no 

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

int minSubArrayLen(int target, vector<int>& nums) {
    // Time complexity: O(N^3)
    // Space complexity: O(1)
    // int minLen=INT_MAX;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         int sum=0;
    //         for(int m=i;m<=j;m++){
    //             sum+=nums[m];
    //         }
    //         if(sum>=target){
    //             minLen=min(minLen,j-i+1);
    //         }
    //     }
    // }
    // if(minLen==INT_MAX) return 0;
    // return minLen;




    // Time complexity: O(N^2)
    // Space complexity: O(1)
    // int minLen=INT_MAX;
    // int n=nums.size();
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=nums[j];
    //         if(sum>=target){
    //             minLen=min(minLen,j-i+1);
    //         }
    //     }
    // }
    // if(minLen==INT_MAX) return 0;
    // return minLen;



    // Time complexity: O(N)
    // Space complexity: O(1)
    int n=nums.size(), left=0, right=0, sum=0,  minLen=INT_MAX;
    while(right<n){
        sum+=nums[right];

        while (left<=right && sum >= target){
            minLen=min(minLen,right-left+1);
            sum-=nums[left];
            left++;
        }

        right++;
    }
    if(minLen==INT_MAX) return 0;
    return minLen;
    
}

int main(){
    vector<int>nums={2,3,1,2,4,3};
    int target=7;
    cout<<minSubArrayLen(target, nums)<<endl;
}
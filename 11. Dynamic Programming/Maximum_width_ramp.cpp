#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Maximum Width Ramp

A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i. Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Input: nums = [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: The maximum width ramp is achieved at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
*/

int maxWidthRamp(vector<int>& nums) {
    // Time complexity - O(n)
    // space complexity - O(n)
    int n=nums.size();
    int result=0;
    vector<int>right_max(n);
    right_max[n-1]=nums[n-1];
    for(int i=n-2;i>=0; i--){
        right_max[i]=max(nums[i], right_max[i+1]);
    }
    int left=0, right=0;
    while (right<n){
        while (left<right && nums[left] > right_max[right]){
            left++;
        }
        result=max(result, right-left);
        right++;
    }
    return result;


    // Time complexity = O(n^2)
    // int n=nums.size();
    // int result=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if (nums[i] <= nums[j]){
    //             result=max(result, j-i);
    //         }
    //     }
    // }
    // return result;  
}

int main(){
    vector<int>nums={6,0,8,2,1,5};
    cout<<maxWidthRamp(nums);
}

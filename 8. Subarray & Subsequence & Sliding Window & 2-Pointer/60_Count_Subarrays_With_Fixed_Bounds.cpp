#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count Subarrays With Fixed Bounds

You are given an integer array nums and two integers minK and maxK.
A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
    The minimum value in the subarray is equal to minK.
    The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.
A subarray is a contiguous part of an array.

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.


Intuition-------------------------------------
To count the number of fixed-bound subarrays, we need to identify the subarrays where the minimum value is equal to minK and the maximum value is equal to maxK. We can iterate through the array and keep track of the indices of the last occurrence of minK and maxK. Then, for each index, we can calculate the number of fixed-bound subarrays ending at that index.

Approach -----------------------------------------
1. Initialize variables res to store the result, bad_idx to store the index of the last occurrence of a value outside the range [minK, maxK], and left_idx and right_idx to store the indices of the last occurrence of minK and maxK respectively.
2. Iterate through the array nums and update the values of bad_idx, left_idx, and right_idx accordingly.
3. For each index i, calculate the number of fixed-bound subarrays ending at i by taking the minimum of left_idx and right_idx, and subtracting bad_idx. Add this count to res.
4. Return the final result res.
*/

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    // Time complexity: O(N)
    // Space complexity: O(1)
    int n=nums.size();
    long long result=0;

    // to store the indices of the last occurrence of minK 
    int lastMin=-1;

    // to store the indices of the last occurrence of maxK 
    int lastMax=-1;

    // to store the index of the last occurrence of a value outside the range [minK, maxK]
    int leftBound=-1;
    for(int i=0;i<n;i++){
        if(nums[i] >= minK and nums[i] <= maxK){
            if(nums[i] == minK){
                lastMin=i;
            }
            if(nums[i] == maxK){
                lastMax=i;
            }
            result+=max(0, min(lastMin, lastMax) - leftBound);
        }else{
            leftBound = i;
            lastMin = -1;
            lastMax = -1;
        }
    }
    return result;


    // Brute Soln------------------------------------------------
    // Time complexity: O(N^2)
    // Space complexity: O(1)
    // int n=nums.size();
    // int result=0;
    // for(int i=0;i<n;i++){
    //     int currMin=INT_MAX;
    //     int currMax=INT_MIN;
    //     for(int j=i;j<n;j++){
    //         currMin=min(currMin, nums[j]);
    //         currMax=max(currMax, nums[j]);
    //         if(currMin == minK && currMax == maxK){
    //             result++;
    //         }
    //     }
    // }
    // return result;
}

int main(){
    vector<int>nums={1,3,5,2,7,5};
    int minK=1, maxK=5;
    cout<<countSubarrays(nums, minK, maxK)<<endl;
}
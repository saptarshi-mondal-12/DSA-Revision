#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Subarray Sums Divisible by K

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k. A subarray is a contiguous part of an array.

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Input: nums = [5], k = 9
Output: 0
*/

int subarraysDivByK(vector<int>& nums, int k) {
    // Time complexity: O(N)
    // Space complexity: O(N)

    int n=nums.size();
    int result=0;
    unordered_map<int,int>mp;
    mp[0]=1;
    int prefixSum=0;
    int rem=0;
    for(int i=0;i<n;i++){
        prefixSum+=nums[i];
        rem=prefixSum%k;

        // Handle negative remainders
        if (rem < 0) rem += k;

        if(mp.find(rem) != mp.end()){
            result+=mp[rem];
        }
        mp[rem]++;
    }
    return result;


    // Time complexity: O(N^2)
    // Space complexity: O(1)
    // int n=nums.size();
    // int result=0;
    // for(int i=0;i<n;i++){
    //     int currSum=0;
    //     for(int j=i;j<n;j++){
    //         currSum+=nums[j];
    //         if(currSum % k == 0){
    //             result++;
    //         }
    //     }
    // }
    // return result;
}

int main(){
    vector<int>nums={4,5,0,-2,-3,1};
    int k=5;
    cout<<subarraysDivByK(nums, k)<<endl;
}
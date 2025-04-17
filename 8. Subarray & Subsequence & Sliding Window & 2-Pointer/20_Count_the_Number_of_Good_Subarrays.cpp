#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* 
Count the Number of Good Subarrays

Given an integer array nums and an integer k, return the number of good subarrays of nums.
A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
*/



int countGood(vector<int>&nums, int k){
    // Time complexity - O(n)
    // space complexity - O(n)

    int n = nums.size();
    long long result = 0;
    unordered_map<int, int> d;
    int left = 0;
    int right = 0;
    int count = 0;

    while (right < n) {
        int curr = nums[right];
        if (d.find(curr) == d.end()) {
            d[curr] = 1;
        } else {
            d[curr]++;
            count += d[curr] - 1;
        }

        while (count >= k) {
            result += n - right;
            d[nums[left]]--;
            count -= d[nums[left]];
            left++;
        }

        right++;
    }
    return result;
}


int main(){
    vector<int>nums={1,1,1,1,1};
    int k=10;
    cout<<countGood(nums, k)<<endl;
}
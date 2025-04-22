#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Divide Array in Sets of K Consecutive Numbers

Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

Return true if it is possible. Otherwise, return false.

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.*/

bool isPossibleDivide(vector<int>& nums, int k) {
    // Time complexity: O(n log n)  = O(n) + O(m log m) + O(m * k) (count frequenct + sort + traverse through sorted keys)
    // Space complexity: O(m) no of unique element

    int n = nums.size();
    if (n % k != 0) return false; // Total elements must be divisible by k

    map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    for (auto it = freq.begin(); it != freq.end(); ++it) {
        int start = it->first; 
        int count = it->second; 


        if (count > 0) {
            for (int i = 0; i < k; i++) {
                if (freq[start + i] < count) {
                    return false;
                }
                freq[start + i] -= count;
            }
        }
    }

    return true;
}

int main(){
    vector<int>nums={1,2,3,3,4,4,5,6};
    int k=4;

    cout<<isPossibleDivide(nums,k)<<endl;
}
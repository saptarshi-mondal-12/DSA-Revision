#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* 
Count Complete Subarrays in an Array

You are given an array nums consisting of positive integers. We call a subarray of an array complete if the following condition is satisfied:
The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.

*/



int brute_countCompleteSubarrays(vector<int>&nums){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int n = nums.size();
    int result = 0;

    // Calculate the total number of distinct elements in the array
    std::unordered_set<int> uniqueElements(nums.begin(), nums.end());
    int totalDistinct = uniqueElements.size();

    // Iterate over all subarrays
    for (int i = 0; i < n; ++i) {
        std::unordered_set<int> s;
        for (int j = i; j < n; ++j) {
            s.insert(nums[j]);
            if (s.size() == totalDistinct) {
                result++;
            }
        }
    }

    return result;

}

int optimal_countCompleteSubarrays(vector<int>&nums){
    // Time complexity - O(n)
    // space complexity - O(n)

    int n = nums.size();
    int result = 0;

    // Find the total number of distinct elements in nums
    unordered_set<int> uniqueElements(nums.begin(), nums.end());
    int totalDistinct = uniqueElements.size();

    int left = 0, right = 0;
    unordered_map<int, int> d;

    while (right < n) {
        int curr = nums[right];
        d[curr]++;

        while (d.size() == totalDistinct) {
            result += (n - right);

            if (d[nums[left]] > 1) {
                d[nums[left]]--;
            } else {
                d.erase(nums[left]);
            }
            left++;
        }

        right++;
    }
    return result;
}


int main(){
    vector<int>nums={1,3,1,2,2};
    cout<<brute_countCompleteSubarrays(nums)<<endl;
    cout<<optimal_countCompleteSubarrays(nums)<<endl;
}
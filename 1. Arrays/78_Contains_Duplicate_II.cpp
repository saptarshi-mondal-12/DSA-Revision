#include <bits/stdc++.h>
using namespace std;

/* Q. Contains Duplicate II - HashedIn 2026

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Input: nums = [1,2,3,1], k = 3
Output: true

Input: nums = [1,0,1,1], k = 1
Output: true

Input: nums = [1,2,3,1,2,3], k = 2
Output: false

*/

bool containsNearbyDuplicate(vector<int> &nums, int k){
    // Time complexity: O(n)
    // Space complexity: O(n);

    // 1. Optimized Approach using Hashing

    int n = nums.size();

    // {num, last_index}
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++){
        int num = nums[i];

        // check is num is present in map or not
        // if present check diff of indexes
        if (mp.find(num) != mp.end()){
            int prevIndex = mp[num];
            int currentIndex = i;

            if (abs(prevIndex - currentIndex) <= k){
                return true;
            }
        }
        mp[num] = i;
    }
    return false;

    // 2. Brute Force Approach

    // Time complexity: O(n^2)
    // space complexity: O(1)
    // int n = nums.size();
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i] == nums[j] && abs(j-i) <= k){
    //             return true;
    //         }
    //     }
    // }
    // return false;
}

int main(){
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;

    bool result = containsNearbyDuplicate(nums, k);
    if(result){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

}   

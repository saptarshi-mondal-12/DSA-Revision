#include<bits/stdc++.h>
using namespace std;
/* Q. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

*/

int firstMissingPositive(vector<int>& nums) {
    // Time complexity: O(2n)
    // Space complexity: O(n)
    
    int n = nums.size();
    vector<bool> seen(n + 1, false);  // Array for lookup

    // Mark the elements from nums in the lookup array
    for (int num : nums) {
        if (num > 0 && num <= n) {
            seen[num] = true;
        }
    }

    // Iterate through integers 1 to n
    // return smallest missing positive integer
    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            return i;
        }
    }

    // If seen contains all elements 1 to n
    // the smallest missing positive number is n + 1
    return n + 1;
}

int main(){
    vector<int>nums={1,6,3,4,8};
    cout<<firstMissingPositive(nums);
}

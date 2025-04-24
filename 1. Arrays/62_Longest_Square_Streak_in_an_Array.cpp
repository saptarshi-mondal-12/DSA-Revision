#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Square Streak in an Array

You are given an integer array nums. A subsequence of nums is called a square streak if:

The length of the subsequence is at least 2, and
after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.


Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.

Input: nums = [2,3,5,6,7]
Output: -1
Explanation: There is no square streak in nums so return -1



Intuition: -----------------------------------------
We start by initializing a set uniqueNumbers to store all the numbers from the array. As before, we loop through the array and treat each number as the starting point of a streak. Inside this loop, we continue searching for the square of the previous number in the sequence using the set. The longest streak we find by counting how many times the inner loop runs gives us the desired result..
*/

int longestSquareStreak(vector<int>& nums) {
    // Time complexity: O(nlogn)
    // Space complexity: O(n)

    int longestStreak = 0;

    // Create a set to store all unique numbers from the input array
    unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

    // Iterate through each number in the input array
    for (int startNumber : nums) {
        int currentStreak = 0;
        long long current = startNumber;

        // Continue the streak as long as we can find the next square in the
        // set
        while (uniqueNumbers.find((int)current) != uniqueNumbers.end()) {
            currentStreak++;

            // Break if the next square would be larger than 10^5 (problem
            // constraint)
            if (current * current > 1e5) break;

            current *= current;
        }

        // Update the longest streak if necessary
        longestStreak = max(longestStreak, currentStreak);
    }

    // Return -1 if no valid streak found, otherwise return the longest
    // streak
    return longestStreak < 2 ? -1 : longestStreak;
}


int main(){
    vector<int>nums={4,3,6,16,8,2};
    cout<<longestSquareStreak(nums)<<endl;
}
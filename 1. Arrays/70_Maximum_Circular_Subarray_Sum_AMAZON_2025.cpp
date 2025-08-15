#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum Sum Circular Subarray - Kadane - AMAZON 2025

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
*/



// Brute soln --------------------------------------------------------------------------
int brute_maxSubarraySumCircular(vector<int>& nums) {
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int n = nums.size();
    int res = nums[0];
        
    // Subarray that starts with index i
    for(int i = 0; i < n; i++) {
        int currSum = 0;
            
        // Considering all possible endpoints of the 
        // Subarray that begins with index i
        for(int j = 0; j < n; j++) {
                
            // Circular index
            int idx = (i + j) % n;
            currSum = currSum + nums[idx];            
            res = max(res, currSum);
        }
    }
    return res;
}




// Optimal Soln ------------------------------------------------------------------------------------

// Function to find the maximum subarray sum (Kadane's algorithm)
int kadaneMax(vector<int> &nums){
    // Time complexity - O(n)
    // space complexity - O(1)

    int n = nums.size();
    int currSum = 0;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++){
        currSum += nums[i];

        // Update maximum sum if current running sum is greater
        if (currSum > mx){
            mx = currSum;
        }

        // If current running sum becomes negative, reset to 0
        // because negative sum will reduce future sums
        if (currSum < 0){
            currSum = 0;
        }
    }
    return mx;
}

// Function to find the minimum subarray sum (Kadane's algorithm)
int kadaneMin(vector<int> &nums){
    // Time complexity - O(n)
    // space complexity - O(1)

    int n = nums.size();
    int currSum = 0;
    int mx = INT_MAX;

    for (int i = 0; i < n; i++){
        currSum += nums[i];

        // Update minimum sum if current running sum is smaller
        if (currSum < mx){
            mx = currSum;
        }

        // For minimum sum, if current running sum becomes positive
        // reset to 0 because a positive sum will increase future sums
        if (currSum > 0){
            currSum = 0;
        }
    }
    return mx; // Return the minimum sum found
}

int maxSubarraySumCircular(vector<int> &nums){
    int n = nums.size();

    // Step 1: Find maximum subarray sum for non-wrapping case
    int maxNormal = kadaneMax(nums);

    // Special case: If all numbers are negative, return maxNormal
    // because wrapping case would give 0 (invalid)
    if (maxNormal < 0){
        return maxNormal;
    }

    // Step 2: Calculate the sum of all elements in the array
    int totalSum = 0;
    for (int num : nums){
        totalSum += num;
    }

    // Step 3: Find minimum subarray sum (non-wrapping)
    int minNormal = kadaneMin(nums);

    // Step 4: Calculate wrapping case sum
    // Wrapping sum = total array sum - minimum subarray sum
    int maxCircular = totalSum - minNormal;

    // Step 5: Return the maximum between non-wrapping and wrapping case
    return max(maxNormal, maxCircular);
}

int main(){
    int n = 3;
    vector<int>nums = {-3, -2, -3};


    // 1. Brute Soln
    cout<<brute_maxSubarraySumCircular(nums)<<endl;

    // 2. Optimal Soln
    cout<<maxSubarraySumCircular(nums)<<endl;
}
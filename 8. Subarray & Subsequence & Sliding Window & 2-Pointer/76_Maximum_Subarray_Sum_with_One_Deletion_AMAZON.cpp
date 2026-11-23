#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum Subarray Sum with One Deletion AMAZON 2026

Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.

Note that the subarray needs to be non-empty after deleting one element.

Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.

Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.

Input: arr = [-1,-1,-1,-1]
Output: -1
Explanation: The final subarray needs to be non-empty. You can't choose [-1] and delete -1 from it, then get an empty subarray to make the sum equals to 0.



Intuition -------------------------------------------------------------

The intuition is to maintain two running states while scanning the array. noDel tracks the maximum subarray sum ending at the current index without using any deletion (like standard Kadane’s algorithm). oneDel tracks the best subarray sum where we are allowed to use at most one deletion, so at each step we either extend the previous deleted state or switch from the non-deleted state. At every index, we update the answer using the best of both states.

We maintain two states:
    noDeletion: Maximum subarray sum ending at the current index without deleting any element.
    oneDeletion: Maximum subarray sum ending at the current index with at most one deletion.
 
*/

int maximumSum(vector<int>& nums) {
    int noDeletion = nums[0];
    int oneDeletion = 0;
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int x = nums[i];
            
        // Either delete current element
        // OR extend previous deleted subarray
        oneDeletion = max(noDeletion, x + oneDeletion);

        // Kadane transition
        noDeletion = max(x, x + noDeletion);

        ans = max(ans, max(noDeletion, oneDeletion));
    }
    return ans;
}
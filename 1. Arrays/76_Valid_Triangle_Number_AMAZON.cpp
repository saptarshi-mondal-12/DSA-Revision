#include <bits/stdc++.h>
using namespace std;

/* Q. Valid Triangle Number - AMAZON 2025

Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Input: nums = [2,2,3,4]
Output: 3
Explanation: Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

Input: nums = [4,2,3,4]
Output: 4
*/


// 1. Brute Force Approach -----------------------------
int brute_triangleNumber(vector<int>& nums) {
    // Time Complexity: O(N^3)
    // Space Complexity: O(1)

    // Intuition: A simple approach is to run three nested loops that select three different values from an array. And in the innermost loop, we checks for the triangle property which specifies the sum of any two sides must be greater than the value of the third side.

    int n = nums.size();
    int result = 0;

    sort(nums.begin(), nums.end());

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                // Sum of two sides is greater than the third
                if (nums[i] + nums[j] > nums[k] &&
                    nums[i] + nums[k] > nums[j] &&
                    nums[k] + nums[j] > nums[i]){
                    result++;
                }
            }
        }
    }

    return result;
}


// 2. Optimal Approach ---------------------------------
int optimal_triangleNumber(vector<int>& nums) {
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)

    // Intuition: We can sort the array first. Then, we can fix two sides of the triangle using two nested loops. For the third side, we can use a while loop to find the maximum index 'k' such that the sum of the two fixed sides is greater than the third side. The number of valid triangles with the two fixed sides is then (k - j - 1).

    int n = nums.size();
    int count = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; j++) {
            while (k < n && nums[i] + nums[j] > nums[k]) {
                k++;
            }
            count += (k - j - 1);
        }
    }
    return count;
}


// 3. Two Pointer Approach -----------------------------
int twoPointer_triangleNumber(vector<int>& nums) {
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)

    int n = nums.size();
    int count = 0;

    sort(nums.begin(), nums.end());

    for (int i = 2; i < n; i++) {
        int left = 0, right = i-1;
        while (left < right) {
            if (nums[left] + nums[right] > nums[i]) {
                count += (right - left);
                right--;
            } else {
                left++;
            }
        }
    }
    return count;
}



int main() {
    vector<int> nums = {2, 2, 3, 4};

    // 1. Brute Force Approach
    cout << "Number of valid triangles: " << brute_triangleNumber(nums) << endl;

    // 2. Optimal Approach
    cout << "Number of valid triangles: " << optimal_triangleNumber(nums) << endl;

    // 3. Two Pointer Approach
    cout << "Number of valid triangles: " << twoPointer_triangleNumber(nums) << endl;

}
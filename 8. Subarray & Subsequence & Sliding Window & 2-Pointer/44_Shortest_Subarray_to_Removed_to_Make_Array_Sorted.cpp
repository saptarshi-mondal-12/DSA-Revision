#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Shortest Subarray to be Removed to Make Array Sorted

Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
Return the length of the shortest subarray to remove.

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
*/

int findLengthOfShortestSubarray(vector<int>& nums){ 
    int n = nums.size(); 
    
    // checking longest sorted prefix 
    int i=0;
    while (i+1<n && nums[i] <= nums[i+1]){
        i++;
    }

    // if our entire array is sorted
    if(i==n-1){
        return 0;
    }

    // checking longest sorted suffix 
    int j=n-1;
    while (j > 0 && nums[j-1] <= nums[j]){
        j--;
    }

    // our answer could be either (prefix of right or suffix of left) whichever is minimum
    int result=min(n-i-1, j);

    // Try to merge the prefix and suffix by checking if we can connect arr[left] and arr[right]
    int left=0;
    int right=j;

    while (left <= i && right < n){
        if(nums[left] <= nums[right]){
            result=min(result, right-left-1);
            left++;
        }else{
            right++;
        }
    }

    return result;
}

int main(){
    vector<int>nums={1,2,3,10,4,2,3,5}; 
    cout<<findLengthOfShortestSubarray(nums)<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
*/


int brute_longestSubarray(vector<int>& nums, int limit) {
    // Time complexity: O(N^2)
    // Space complexity: O(1)

    int n=nums.size();
    int result=0;
    for(int i=0;i<n;i++){
        if(n-i < result){
            break;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int j=i;j<n;j++){
            mini=min(mini, nums[j]);
            maxi=max(maxi, nums[j]);

            if(abs(mini-maxi) <= limit){
                result=max(result, j-i+1);
            }else{
                break;
            }
        }
    }
    return result;
}


int optimal_longestSubarray(vector<int>& nums, int limit) {
    // Time Complexity: O(n log n)
    // Space Complexity: O(n)

    /*Intuition
    If we could use a single data structure that can retrieve the maximum and minimum values in constant time, we could reduce the space complexity of our solution. Fortunately, multisets are capable of maintaining elements in sorted order, allowing us to efficiently retrieve both the maximum and minimum values in constant time.

    Using a multiset, we can efficiently track elements within the current window. Inserting and removing elements take logarithmic time, while finding the maximum and minimum values is constant time, as they are at the ends of the sorted container. A multiset, unlike a set, allows multiple instances of the same element and can be thought of as a combination of a min heap and a max heap.*/

    int n=nums.size();
    int result=0;

    // multiset to maintain the elements within the current window
    multiset<int> window;
    int left = 0, right=0;
    
    while(right<n){
        int curr=nums[right];
        window.insert(curr);

        // Check if the absolute difference between the maximum and minimum values in the current window exceeds the limit

        while(*window.rbegin() - *window.begin()  > limit){
            // Remove the element at the left pointer from the multiset
            window.erase(window.find(nums[left]));
            // Move the left pointer to the right to exclude the element
            left++;
        }

        // Update maxLength with the length of the current valid window
        result = max(result, right - left + 1);
        right++;
    }
    return result;
}


int main(){
    vector<int>nums={8,2,4,7};
    int limit=4;

    // Brute soln
    // cout<<brute_longestSubarray(nums, limit)<<endl;


    // optimal soln
    cout<<optimal_longestSubarray(nums, limit)<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Maximum Sum Path in Two Arrays

Given two sorted arrays having some elements in common. Find the sum of the maximum sum path to reach from the beginning of any array to the end of any of the two arrays. We can switch from one array to another array only at common elements. 

Note: The common elements do not have to be at the same indexes. And individual arrays have distinct elements only (no repetition within the array).

Input: ar1[] = {2, 3, 7, 10, 12}, ar2[] = {1, 5, 7, 8}
Output: 35
Explanation: 35 is sum of 1 + 5 + 7 + 10 + 12.
Start from the first element of ar2 which is 1, then move to 5, then 7.  From 7 switch to ar1 (as 7 is common) and traverse 10 and 12.


Input: ar1[] = {10, 12}, ar2 = {5, 7, 9}
Output: 22
Explanation: 22 is the sum of 10 and 12. 
Since there is no common element, take all elements from the array with more sum.
*/


int maxPathSum(vector<int>nums1, vector<int>&nums2){
    // Time complexity: O(m+n)
    // Space complexity: O(1)

    int m=nums1.size();
    int n=nums2.size();
    int result=0;
    int sum1=0, sum2=0, i=0, j=0;
    while (i<m && j<n){
        // if nums1[i] < nums2[j] -> add element of nums1 to sum1 
        if (nums1[i] < nums2[j]){
            sum1+=nums1[i];
            i++;
        }
        // if nums1[i] > nums2[j] -> add element of nums2 to sum2 
        else if (nums2[j] < nums1[i]){
            sum2+=nums2[j];
            j++;
        }
        else{ // we reached a common point
    
            // Take the maximum of two sums and add to result Also add the common element of array, once
            result+=max(sum1, sum2) + nums1[i];
    
            // Update sum1 and sum2 for elements after this intersection point
            sum1 = 0;
            sum2 = 0;
    
            // update i and j to move to next element of each array
            i++;
            j++;
        }
    } 
    
    // Add remaining elements of nums1
    while (i < m){
        sum1 += nums1[i];
        i++;
    }
    
    // Add remaining elements of nums1
    while (j < n){
        sum2 += nums2[j];
        j++;
    }
    
    // Add maximum of two sums of remaining elements
    result += max(sum1, sum2);
    return result;
}

int main(){
    vector<int>nums1={10,20,21,40,50,60};
    vector<int>nums2={1,5,20,30,40,60,100};
    cout<<maxPathSum(nums1, nums2)<<endl;
}
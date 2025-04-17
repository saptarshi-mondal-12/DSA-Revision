#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Find the Power of K-Size Subarrays II

You are given an array of integers nums of length n and a positive integer k.
The power of an array is defined as:
Its maximum element if all of its elements are consecutive and sorted in ascending order.-1 otherwise.
You need to find the power of all subarrays of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

Input: nums = [1,2,3,4,3,2,5], k = 3
Output: [3,4,-1,-1,-1]
Explanation: There are 5 subarrays of nums of size 3:
[1, 2, 3] with the maximum element 3.
[2, 3, 4] with the maximum element 4.
[3, 4, 3] whose elements are not consecutive.
[4, 3, 2] whose elements are not sorted.
[3, 2, 5] whose elements are not consecutive.

Input: nums = [2,2,2,2,2], k = 4
Output: [-1,-1]

Input: nums = [3,2,3,2,3,2], k = 2
Output: [-1,3,-1,3,-1]
*/

vector<int>optimal_resultsArray(vector<int>&nums, int k){
    // Time complexity - O(n)
    // space complexity - O(n-k+1)

    int n=nums.size();
    vector<int>result;
    int count=1;
    for(int i=0;i<n;i++){
        if (i && nums[i]==nums[i-1]+1){
            count++;
        }else{
            count=1;
        }

        if(i+1 >= k){
            if(count>=k){
                result.push_back(nums[i]);
            }else{
                result.push_back(-1);
            }
        }
    }
    return result;

}

vector<int>brute_resultsArray(vector<int>&nums, int k){
    // Time complexity - O(n*k)
    // space complexity - O(n-k+1)

    int n=nums.size();
    vector<int>result;

    for(int i=0;i<n-k+1;i++){
        int curr=nums[i];
        bool flag=true;
        for(int j=i+1;j<i+k;j++){
            if (nums[j]!=curr+1){
                flag=false;
            }
            curr+=1;
        }
        if(flag){
            result.push_back(curr);
        }else{
            result.push_back(-1);
        }
    }
    return result;
}

int main(){
    vector<int>nums={3,2,3,2,3,2};
    int k=2;

    // vector<int>result=optimal_resultsArray(nums, k);
    vector<int>result=brute_resultsArray(nums, k);

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count the Number of Fair Pairs

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
A pair (i, j) is fair if:
    0 <= i < j < n, and
    lower <= nums[i] + nums[j] <= upper

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
*/

int findLowerIndex(int num, int start, vector<int>& nums, int lower){
    int n=nums.size();
    int low=start;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(num+nums[mid] >= lower){
            high = mid-1;
        }else{
            low=mid+1;
        }
    }
    return low;
}

int findUpperIndex(int num, int start, vector<int>& nums, int upper){
    int n=nums.size();
    int low=start;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(num+nums[mid] <= upper){
            low = mid+1;
        }else{
            high=mid-1;
        }
    }
    return low;
}

long long countFairPairs(vector<int>& nums, int lower, int upper) {
    int n=nums.size();
    long long result=0;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        int lowerIndex = findLowerIndex(nums[i], i+1, nums, lower);
        int upperIndex = findUpperIndex(nums[i], i+1, nums, upper);
        result += (upperIndex - lowerIndex);
    }
    return result;

    // [0,1,4,4,5,7]


    // Time complexity: O(N^2)
    // Space complxity: O(1)
    // int n=nums.size();
    // int result=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         int total = nums[i]+nums[j];
    //         if(lower <= total && total <= upper){
    //             result++;
    //         }
    //     }
    // }
    // return result;
}

int main(){
    vector<int>nums={0,1,7,4,4,5};
    int lower=3, upper=6;
    cout<<countFairPairs(nums, lower,upper)<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Input: target = 4, nums = [1,4,4]
Output: 1

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0*/



void brute_longestSubarray(int n, int nums[], int target){
    // time complexity - O(n^3)
    // space comlexity - O(1)

    int minLen=INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int m=i;m<=j;m++){
                sum+=nums[m];
            }
            if(sum>=target){
                minLen=min(minLen,j-i+1);
            }
        }
    }
    if(minLen==INT_MAX) cout<<0<<endl;
    else cout<<minLen<<endl;
}


void Naive_longestSubarray(int n, int nums[], int target){
    // time complexity - O(n^2)
    // space comlexity - O(1)

    int minLen=INT_MAX;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum>=target){
                minLen=min(minLen,j-i+1);
            }
        }
    }
    if(minLen==INT_MAX) cout<<0<<endl;
    else cout<<minLen<<endl;  
}


void optimal_longestSubarray(int n, int nums[], int target){
    // time complexity - O(2n)
    // space comlexity - O(1)


    int left=0, right=0, sum=0,  minLen=INT_MAX;
    while(right<n){
        sum+=nums[right];

        while (left<=right && sum >= target){
            minLen=min(minLen,right-left+1);
            sum-=nums[left];
            left++;
        }

        right++;
    }
    if(minLen==INT_MAX) cout<<0<<endl;
    else cout<<minLen<<endl;
    
}

int main(){
    int n=6;
    int target=7;
    int arr[n]={2,3,1,2,4,3};


    // 1. brute force 
    brute_longestSubarray(n,arr,target);

    // 2. Naive soln 
    // Naive_longestSubarray(n,arr,target);

    // 3. optimal soln
    // optimal_longestSubarray(n,arr,target);
    
}
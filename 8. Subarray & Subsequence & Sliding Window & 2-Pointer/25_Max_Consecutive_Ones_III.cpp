#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [0,1,1,1,1,0] Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
*/

void brute_longestOnes(int n, int nums[], int k){
    int longest=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++){
            if(nums[j]==0){
                count++;
            }
            if (count <= k) {
                longest = max(longest, j - i + 1);
            }
        }
    }
    cout<<longest<<endl;

}

void optimal_longestOnes(int n, int nums[], int k){
    int left=0, right=0;
    int longest=INT_MIN;
    int count=0;

    while(right<n){
        if(nums[right]==0){
            count++;
        }

        while(count > k){
            if(nums[left]==0){
                count-=1;
            }
            left++;

        }
        longest=max(longest,right-left+1);
        right++;
    }
    cout<<longest<<endl;

}

int main(){
    int n=10;
    int nums[n]={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;

    // brute
    brute_longestOnes(n,nums,k);

    // optimal
    optimal_longestOnes(n,nums,k);
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Binary Subarray Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]


Input: nums = [0,0,0,0,0], goal = 0
Output: 15

*/


int brute_binarySubarraySum(int n, int arr[], int goal){
    // time complexity - O()
    // space comlexity - O()
    
    // intuition = generate all subarray and check sum equal to goal
    int result=0;
    for(int i=0;i<n;i++){
        int currSum=0;
        for(int j=i;j<n;j++){
            currSum+=arr[j];
            if (currSum==goal){
                result+=1;
            }else if (currSum > goal){
                break;
            }
        }
    }
    return result;
}

int compute(int n, int arr[], int goal){
    if(goal < 0){
        return 0;
    }
    int count=0;
    int left=0, right=0;
    int currSum=0;
    while(right < n){
        currSum+=arr[right];
        while (currSum > goal){
            currSum-=arr[left];
            left++;
        }
        count=count+(right-left+1);
        right++;
    }
    return count;
}


int better_binarySubarraySum(int n, int arr[], int goal){
    // time complexity - O(n + n) * 2
    // space comlexity - O(1)

    // Intuition - 2 pointer + sliding window;
    int result = compute(n, arr, goal) - compute(n, arr, goal-1);
    return result;
}



int main(){
    int n=6;
    int goal=2;
    int arr[n]={1,0,0,1,1,0};


    // 1. brute force 
    cout<<brute_binarySubarraySum(n,arr,goal)<<endl;

    // 2. better soln 
    cout<<better_binarySubarraySum(n,arr,goal)<<endl; 
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q1. Longest Subarray with sum less than equal to k
Given an array and a sum k, we need to print the length of the longest subarray that sums less than equal to k.

Input : N = 5, k = 14, array[] = [2,5,1,7,10]
Result: 3
Explanation: The longest subarray with sum 5 is {2, 5, 1}. And its length is 3.

int[] arr = {1, 2, 1, 0, 1, -8, -9, 0};
int k = 4
Output is 7

int arr[] = {1, 2, 1, 0, 1, 1, 0};
int k = 4;
output is 5

*/



void brute_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n^2)
    // space comlexity - O(1)

    // using 2 loop
    int result=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if (sum<=k){
                result=max(result, j-i+1);
            }else if(sum > k){
                break;
            }
        }
    }
    cout<<result<<endl;
}


void better_longestSubarray(int n, int arr[], int k){
    // time complexity - O(2n)
    // space comlexity - O(1)

    int result=0;
    int left=0, right=0;
    int sum=0;
    while(right<n){
        sum+=arr[right];

        while(sum > k){
            sum-=arr[left];
            left+=1;
        }

        if(sum<=k){
            result=max(result, right-left+1);
        }
        right++;
    }
    cout<<result<<endl; 
}


void optimal_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n)
    // space comlexity - O(1)
    int result=0;
    int left=0, right=0;
    int sum=0;
    while(right<n){
        sum+=arr[right];

        if(sum > k){
            sum-=arr[left];
            left+=1;
        }
        if(sum<=k){
            result=max(result, right-left+1);
        }
        right++;
    }
    cout<<result<<endl; 
}

int main(){
    int n=8;
    int k=4;
    int arr[n]={1, 2, 1, 0, 1, -8, -9, 0};


    // 1. brute force 
    brute_longestSubarray(n,arr,k);

    // 2. better soln 
    better_longestSubarray(n,arr,k);

    // 3. optimal soln
    optimal_longestSubarray(n,arr,k); 
}
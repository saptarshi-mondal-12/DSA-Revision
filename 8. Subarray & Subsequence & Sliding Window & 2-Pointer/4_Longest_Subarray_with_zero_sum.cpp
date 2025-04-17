#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*longest subarray with zero Sum 

Given an array containing both positive and negative integers, 
we have to find the length of the longest subarray with the sum of all elements equal to zero.

Input: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result: 5
Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!

Input: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result: 8
Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
Length of longest subarray = 8

Input Format: N = 3, array[] = {1, 0, -5}
Result: 1
Subarray : {0}
Length of longest subarray = 1

*/

void brute_longest0Sum(int n, int arr[]){
    // Time complexity - O(n^3)
    // Space complexity - O(1)

    int maxLen=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int m=i;m<=j;m++){
                sum+=arr[m];
            }
            if (sum==0)
                maxLen=max(maxLen,j-i+1);
        }
    }
    cout<<maxLen;
}

void better_longest0Sum(int n, int arr[]){
    // Time complexity - O(n^2)
    // Space complexity - O(1)

    int maxLen=0;

    for(int i=0;i<n;i++){
         int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if (sum==0)
                maxLen=max(maxLen,j-i+1);
        }
    }
    cout<<maxLen;
}


void optimal_longest0Sum(int n, int arr[]){
    // Time complexity - O(n)
    // Space complexity - O(n)
    map<int,int>mpp;
    int sum=0;
    int maxLen=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==0){
            maxLen=max(maxLen,i+1);
        }

        int remaining = sum-0;
        

        if(mpp.find(remaining)!=mpp.end()){
            maxLen=max(maxLen,i-mpp[remaining]);
        }

        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
    }

    cout<<maxLen;
}


int main(){
    int n=6;
    int arr[n]={9,-3,3,-1,6,-5};

    // 1. brute
    // brute_longest0Sum(n,arr);

    // 2. better
    // better_longest0Sum(n,arr);

    // 3. optimal
    optimal_longest0Sum(n,arr);
    
}
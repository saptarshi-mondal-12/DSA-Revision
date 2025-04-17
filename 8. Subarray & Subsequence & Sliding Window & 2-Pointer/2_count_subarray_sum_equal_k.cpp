#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q1. Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,1,1], k = 2
Output: 2

Input: nums = [1,2,3], k = 3
Output: 2
*/




void brute_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n^3)
    // space comlexity - O(1)

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int m=i;m<=j;m++){
                sum+=arr[m];
            }
            if (sum==k){
                count+=1;
            }
        }
    }
    cout<<count<<endl;
}


void Naive_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n^2)
    // space comlexity - O(1)

    // Intuition - using two loop
    int count=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if (sum==k)
                cout<<i<<" "<<j<<endl;
                count+=1;
        }
    }
    cout<<count;
}

void better_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n log n)
    // space comlexity - O(n)

    // using prefix sum

    map<int, int> mpp;
    int sum = 0;
    int count = 0;

     mpp[0] = 1; // Setting 0 in the map.
    
    for (int i = 0; i < n; i++) {
        // Calculate the prefix sum till index i:
        sum += arr[i];

        // Calculate the sum of the remaining part i.e. x - k:
        int remaining = sum - k;

        // If the remaining part i.e. x - k exists in the map, update the count:
        count += mpp[remaining];
    
        // Increment the frequency of the current prefix sum:
        mpp[sum]+=1;
    }
    cout<< count;
}





int main(){
    int n=10;
    int k=3;
    int arr[n]={1,2,3,-3,1,1,1,4,2,-3};


    // 1. brute force 
    // brute_longestSubarray(n,arr,k);

    // 2. Naive soln 
    // Naive_longestSubarray(n,arr,k);

    // 3. Better soln 
    better_longestSubarray(n,arr,k);

    
}
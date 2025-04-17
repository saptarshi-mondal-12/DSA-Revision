#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q1. Longest Subarray with given Sum K (Positives)
Given an array and a sum k, we need to print the length of the longest subarray that sums to k.

Input : N = 3, k = 5, array[] = {2,3,5}
Result: 2
Explanation: The longest subarray with sum 5 is {2, 3}. And its length is 2.

Example 2:
Input : N = 5, k = 10, array[] = {2,3,5,1,9}
Result: 3
Explanation: The longest subarray with sum 10 is {2, 3, 5}. And its length is 3.
*/

// NOTE : Edge case - arr{2,0,0,3}, k=3 , o/p=3
// O(n^3) >  O(n^2) > O(n log n) > O(n)



void brute_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n^3)
    // space comlexity - O(1)

    // Intuition - using three loop

    int maxLen=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int m=i;m<=j;m++){
                sum+=arr[m];
            }
            if (sum==k)
                maxLen=max(maxLen,j-i+1);
        }
    }
    cout<<maxLen;
}


void naive_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n^2)
    // space comlexity - O(1)

    // Intuition - using two loop

    int maxLen=0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];

            if (sum==k)
            maxLen=max(maxLen,j-i+1);
        }
    }
    cout<<maxLen;
}


void better_longestSubarray(int n, int arr[], int k){
    // time complexity - O(n log n)
    // space comlexity - O(n)

    // Intuition : using Hashing 
    map<int, int> prefixSumMap;
    int sum=0;
    int maxLen=0;
    
    for(int i=0;i<n;i++){
        //calculate the prefix sum till index i:
        sum+=arr[i];

        // if the sum = k, update the maxLen:
        if (sum==k) 
            maxLen=max(maxLen,i+1);

        // calculate the sum of remaining part i.e. x-k:
        int remaining = sum-k;

        // If the remaining part i.e. x-k exists in the map, we will calculate the length and update maxLen: 
        if(prefixSumMap.find(remaining)!=prefixSumMap.end()){
            maxLen=max(maxLen, i-prefixSumMap[remaining]);
        }

        /*If the sum, does not exist in the map we will add that with the current index into the map. 
        We are checking the map before insertion because we want the index to be as minimum as possible 
        and so we will consider the earliest index where the sum x-k has occurred.*/
        if(prefixSumMap.find(sum)==prefixSumMap.end()){
            prefixSumMap[sum]=i;
        }  
    }
    cout<<maxLen;
}


void optimal_longestSubarray(int n, int arr[], int k){
    /* time complexity - O(n) + O(n) = O(2n)

    Reason: The outer while loop i.e. the right pointer can move up to index n-1(the last index). 
    Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. 
    So, every time the inner loop does not run for n times rather it can run for n times in total. 
    So, the time complexity will be O(2*N) instead of O(N2). 

    space comlexity - O(1)*/

    // Intuition : using two pointer 
    int left=0, right=0;
    int sum=arr[0];
    int maxLen=0;

    while(right<n){
        // if sum > k, reduce the subarray from left until sum becomes less or equal to k:
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }

        // after shifting if sum == k, update the maxLen
        if(sum==k)
            maxLen=max(maxLen,right-left+1);
        
        // Move forward the right pointer and update sum
        right++;
        if(right<n)
            sum+=arr[right];
    }
    cout<<maxLen;
}

int main(){
    int n=5;
    int k=10;
    int arr[n]={2,3,5,1,9};


    // 1. brute force 
    // brute_longestSubarray(n,arr,k);

    // 2. Naive soln 
    // Naive_longestSubarray(n,arr,k);

    // 3. better soln
    // better_longestSubarray(n,arr,k);

    // 4. optimal soln
    optimal_longestSubarray(n,arr,k);
    
}
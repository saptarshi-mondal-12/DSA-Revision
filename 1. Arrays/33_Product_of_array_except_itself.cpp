#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Product of Array Except Itself
Problem Statement: Given an array arr[] of integers, you need to 
return the product of given array elements except including the element itself.

NOTE – You should not use division operator ‘ / ’ 

Input: N = 5, array[] = {1,2,3,4,5}
Output: 120 60 40 30 24
Explanation: For 0th index, excluding 1 from product of whole array will give 120
             For 1th index, excluding 2 from product of whole array will give 60

*/

void brute_findproduct(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(n)+O(n)

    // using Prefix and Suffix Array
    int product[n];

    int prefix[n];
    prefix[0]=1;
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*arr[i-1];
    }

    int suffix[n];
    suffix[n-1]=1;
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]*arr[i+1];
    }

    for(int i=0;i<n;i++){
        product[i]=prefix[i]*suffix[i];
    }

    for(int i=0;i<n;i++) cout<<product[i]<<" ";
    cout<<endl;

}

void optimize_findproduct(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(n)

    int product[n];

    int prefix[n];
    prefix[0]=1;
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]*arr[i-1];
    }

    int suffix=1;
    for(int i=n-1;i>=0;i--){
        product[i]=prefix[i]*suffix;
        suffix*=arr[i];
    }

    for(int i=0;i<n;i++) cout<<product[i]<<" ";
    cout<<endl;

}

int main(){
    int n=5;
    int arr[n]={1,2,3,4,5}; // 120,60,40,30,24


    // 1. brute 
    brute_findproduct(n,arr);

    // 2. optimize 
    optimize_findproduct(n,arr);

}

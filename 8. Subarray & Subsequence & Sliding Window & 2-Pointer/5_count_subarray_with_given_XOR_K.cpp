#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q1. Given an array of integers A and an integer B. 
Find the total number of subarrays having bitwise XOR of all elements equal to k.

Input: nums = [[4, 2, 2, 6, 4], k = 6
Output: 4

Input: nums = [5, 6, 7, 8, 9], k = 5
Output: 2
*/




void brute_subarraysWithXorK(int n, int arr[], int k){
    // time complexity - O(n^3)
    // space comlexity - O(1)

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xorr=0;
            for(int m=i;m<=j;m++){
                xorr^=arr[m];
            }
            if (xorr==k){
                count+=1;
            }
        }
    }
    cout<<count<<endl;
}


void Naive_subarraysWithXorK(int n, int arr[], int k){
    // time complexity - O(n^2)
    // space comlexity - O(1)

    // Intuition - using two loop
    int count=0;
    for(int i=0;i<n;i++){
        int xorr=0;
        for(int j=i;j<n;j++){
            xorr^=arr[j];
            if (xorr==k)
                count+=1;
        }
    }
    cout<<count;
}

void better_subarraysWithXorK(int n, int arr[], int k){
    // time complexity - O(n log n)
    // space comlexity - O(n)


    map<int, int> mpp;
    int count = 0;
    int xr=0;

     mpp[0] = 1; // Setting 0 in the map.
    
    for (int i = 0; i < n; i++) {
        // Calculate the prefix xor till index i:
        xr=xr ^ arr[i];

         //By formula: x = xr^k:
        int x = xr ^ k;

        count += mpp[x];
    
        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]+=1;
    }
    cout<< count;
}





int main(){
    int n=5;
    int k=6;
    int arr[n]={4,2,2,6,4};


    // 1. brute force 
    // brute_subarraysWithXorK(n,arr,k);

    // 2. Naive soln 
    // Naive_subarraysWithXorK(n,arr,k);

    // 3. Better soln 
    better_subarraysWithXorK(n,arr,k);

    
}
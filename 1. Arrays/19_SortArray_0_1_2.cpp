#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. 
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]*/


void better_sort(int n, int arr[]){
    // Time complexity - O(n) + O(n) = O(2n)
    // Space complexity - O(1)

    int zero=0;
    int one=0;
    int two=0;

    for(int i=0;i<n;i++){
        if(arr[i]==0) zero++;
        else if (arr[i]==1) one+=1;
        else two+=1;
    }

    //Replace the places in the original array:
    for(int i=0;i<zero;i++) arr[i]=0; // replacing 0's

    for(int i=zero;i<zero+one;i++) arr[i]=1; // replacing 1's

    for(int i=zero+one;i<n;i++) arr[i]=2; // replacing 2's

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}

void optimal_sort(int n, int arr[]){
    // Time complexity - O(n)
    // Space complexity - O(1)

    /* Dutch national flag algorithm
    arr[0….low-1] contains 0. [Extreme left part]
    arr[low….mid-1] contains 1.
    arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
    The middle part i.e. arr[mid….high] is the unsorted segment.*/

    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;

        }
        else if(arr[mid]==1){
            mid++;

        }
        else{
            swap(arr[mid],arr[high]);
            high--;

        }
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}



int main(){
    int n=12;
    int arr[n]={0,1,2,0,1,2,1,2,0,0,0,1};

    // 1. brute force - sorting using merg sort - tc=O(n log n), sc=O(n)
    // sort(arr,arr+n);

    // 2. better solution
    // better_sort(n,arr);

    // 3. optimal solution 
    optimal_sort(n,arr);
    

    

}
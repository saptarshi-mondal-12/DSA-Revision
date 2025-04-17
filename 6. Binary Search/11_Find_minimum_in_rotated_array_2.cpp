#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Minimum in Rotated Sorted Array 

Given an integer array arr of size N, sorted in ascending order (duplicates values). 
Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.

Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 0
Explanation: Here, the element 0 is the minimum element in the array.

Input Format: arr = [3,4,5,1,2]
Result: 1
Explanation: Here, the element 1 is the minimum element in the array.

*/

int brute_minimum(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        mini=min(mini,arr[i]);
    }
    return mini;
}

int optimal_minimum(int n, int arr[]){
    // Time complexity - O(log n)
    // space complexity - O(1)

    int low=0, high=n-1;
    int mini=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;

        // if low==mid==high
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            mini=min(mini,arr[low]);
            low++;
            high--;
            continue;
        }

        // left half is sorted
        if(arr[low]<=arr[mid]){
            mini=min(mini,arr[low]);
            low=mid+1;
        }else{ // right half is sorted

            // keep the minimum
            mini=min(mini,arr[mid]);
            // eliminate right half
            high=mid-1;
        }
    }
    return mini;
}



int main(){
    int n=8;
    int arr[n]={4,5,6,7,0,1,2,3};

    // 1. brute - linear search
    cout<<brute_minimum(n,arr)<<endl;

    // optimal
    cout<<optimal_minimum(n,arr)<<endl;

    /* edge case - [7,8,1,2,3,4,5,6]*/
}
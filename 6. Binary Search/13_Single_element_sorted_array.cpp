#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once. Return the single element that appears only once.

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

int brute_singleNonDuplicate(int n, int arr[]){
    // Time Complexity - O(n)
    // space complexity - O(1)

    if(n==1) return arr[0];

    for(int i=0;i<n;i++){
        // check for first index
        if(i==0){
            if(arr[i]!=arr[i+1]){
                return arr[i];
            }
        }
        // check for last index
        else if(i==n-1){
            if(arr[n-1]!=arr[n-2]){
                return arr[n-1];
            }
        }else{
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]){
                return arr[i];
            }
        }
    }
    return -1;
}

int optimal_singleNonDuplicate(int n, int arr[]){
    // Time Complexity - O(log n)
    // space complexity - O(1)

    /* left half - (even, odd) -> element is on right half -> eleminate left half
       right half - (odd, even) -> element is on left half -> eleminate right half
    */

    // if single element
    if(n==1) return arr[0];

    // edge case
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;

        //if arr[mid] is the single element:
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }


        // //we are in the left
        if(mid%2==1 && arr[mid-1]==arr[mid] || mid%2==0 && arr[mid]==arr[mid+1]){
            // eleminate left half
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return -1;
}


int main(){
    int n=9;
    int arr[n]={1,1,2,3,3,4,4,8,8};

    // 1. brute 
    cout<<brute_singleNonDuplicate(n,arr)<<endl;

    // 2. optimal
    cout<<optimal_singleNonDuplicate(n,arr)<<endl;


    /*The index sequence of the duplicate numbers in the left half is always (even, odd). 
    That means one of the following conditions will be satisfied if we are in the left half:

    - If the current index is even, the element at the next odd index will be the same as the current element.
    - Similarly, If the current index is odd, the element at the preceding even index will be the same as the current element.

    The index sequence of the duplicate numbers in the right half is always (odd, even).
    That means one of the following conditions will be satisfied if we are in the right half:

    - If the current index is even, the element at the preceding odd index will be the same as the current element.
    - Similarly, If the current index is odd, the element at the next even index will be the same as the current element.
    */

    
}
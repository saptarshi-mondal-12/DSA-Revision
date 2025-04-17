#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Single Element in a Sorted Array

Given an array of length N. Peak element is defined as the element greater than both of its neighbors. 
Formally, if ‘arr[i]’ is the peak element, ‘arr[i – 1]’ < ‘arr[i]’ and ‘arr[i + 1]’ < ‘arr[i]’. 
Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

Input: nums = [1,2,3,4,5]
Output: 5

Input: nums = [5,4,3,2,1]
Output: 5
*/

int brute_peakElement(int n, int arr[]){
    // Time Complexity - O(n)
    // space complexity - O(1)

    int result=-1;
    for(int i=0;i<n;i++){
        if((i==0 || arr[i-1] < arr[i]) 
            && (i==n-1 || arr[i] > arr[i+1])){
            return arr[i];
        }
    }
    return -1;
}


int optimal_peakElement(int n, int arr[]){
    // Time Complexity - O(log n)
    // space complexity - O(1)

    /*
                 (mid)
                   *
                *      * (mid)
            *               *
        * (mid) 
    *
    
    */

    // Edge cases
    if(n==1) return arr[0];
    if(arr[0] > arr[1]) return arr[0];
    if(arr[n-2] < arr[n-1]) return arr[n-1];

    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;

        // if my mid is a peak
        if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
            return arr[mid];
        }

        // left half is sorted
        if(arr[mid-1] < arr[mid]){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    
}


int main(){
    // int n=7;
    // int arr[n]={1,2,1,3,5,6,4};

    int n=4;
    int arr[n]={1,2,3,1};

    

    // 1. brute 
    cout<<brute_peakElement(n,arr)<<endl;

    // 2. optimal
    cout<<optimal_peakElement(n,arr)<<endl;

    /*The left half of the peak element has an increasing order. This means for every index i, arr[i-1] < arr[i].
    On the contrary, the right half of the peak element has a decreasing order. This means for every index i, arr[i+1] < arr[i].
    Now, using the above observation, we can easily identify the left and right halves, just by checking the property of the current index, 
    i, like the following:

    If arr[i] > arr[i-1]: we are in the left half.
    If arr[i] > arr[i+1]: we are in the right half.
    How to eliminate the halves accordingly:

    If we are in the left half of the peak element, we have to eliminate this left half (i.e.    
    low = mid+1). Because our peak element appears somewhere on the right side.
    If we are in the right half of the peak element, we have to eliminate this right half (i.e.high = mid-1). 
    Because our peak element appears somewhere on the left side.
    */

    
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Binary Search

Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

void linear_search(int n, int arr[], int target){
    // Time complexity - O(n)
    // space complexity - O(1)

    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            index=i;
            break;
        }
    }

    cout<<index<<endl;
}

void binary_search(int n, int arr[], int target){
    // Time complexity - O(log n) 
    /*
    In the algorithm, we are basically dividing the search space into 2 equal halves. 
    This is actually equivalent to dividing the size of the array by 2, every time. 
    After a certain number of divisions, the size will reduce to such an extent 
    that we will not be able to divide that anymore and the process will stop. 
    The number of total divisions will be equal to the time complexity.

    If a number n can be divided by 2 for x times:
        2^x = n
    Therefore, x = logn (base is 2)
    */

    // space complexity - O(1)

    int index=-1;
    int low=0, high=n-1;
    while (low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==target){
            index=mid;
            break;
        }
        else if(arr[mid] > target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    cout<<index<<endl;
}

int search(int arr[], int low, int high, int target){
    if(low>high) return -1;

    int mid=(low+high)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid] > target){
        return search(arr,low,mid-1,target);
    }
    return search(arr, mid+1,high,target);
}


void recursion_search(int n, int arr[], int target){
    // Time complexity - O(Log n)
    // space complexity - O(1)

    cout<<search(arr,0,n-1,target)<<endl;
}


int main(){
    int n=8;
    int arr[n]={3,4,6,7,9,12,16,17};
    int target=6;

    // brute - linear search 
    linear_search(n,arr, target);

    // optimal - binary search
    binary_search(n,arr, target);

    // recursion
    recursion_search(n,arr,target);

    /* Overflow case - 
    1. make mid = long long mid 
        or
    2. mid=low + (high-low)/2
    */
}
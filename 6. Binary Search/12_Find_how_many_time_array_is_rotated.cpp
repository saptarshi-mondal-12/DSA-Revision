#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Find out how many times the array has been rotated

Given an integer array arr of size N, sorted in ascending order (with distinct values). 
Now the array is rotated between 1 to N times which is unknown. Find how many times the array has been rotated. 

Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 4
Explanation: The original array should be [0,1,2,3,4,5,6,7]. So, we can notice that the array has been rotated 4 times.

Input Format: arr = [3,4,5,1,2]
Result: 3
Explanation: The original array should be [1,2,3,4,5]. So, we can notice that the array has been rotated 3 times.*/

void brute_findRotation(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    int ans = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < ans) {
            ans = arr[i];
            index = i;
        }
    }
    cout<<index<<endl;
}

void optimal_findRotation(int n, int arr[]){
    // Time complexity - O(log n)
    // space complexity - O(1)

    int low=0, high=n-1;
    int index=-1;
    int mini=INT_MAX;

    while(low<=high){
        int mid=(low+high)/2;

        // if left is sorted
        if(arr[low]<=arr[mid]){
            // keep the minimum:
            if(arr[low] < mini){
                mini=arr[low];
                index=low;
            }
            // Eliminate left half
            low=mid+1;
        }else{

            if (arr[mid]<mini){
                mini=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    cout<<index<<endl;
}


int main(){
    int n=8;
    int arr[n]={4,5,6,7,0,1,2,3};

    // 1.brute
    brute_findRotation(n,arr);

    // 2. optimal
    optimal_findRotation(n,arr);
}
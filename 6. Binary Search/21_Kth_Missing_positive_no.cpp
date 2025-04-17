#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Kth Missing Positive Number

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

 Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/



void brute_findKthPositive(int n, int arr[], int k){
    // TC = O(n)
    // SC = O(1)

    for(int i=0;i<n;i++){
        if(arr[i]<=k) k++;
        else break;
    }
    cout<<k<<endl;
}

void optimal_findKthPositive(int n, int arr[], int k){
    // TC = O(log n)
    // SC = O(1)

    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        int missing=arr[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    cout<<k+high+1<<endl;
}

int main(){
    // int n=5;
    // int arr[n]={2,3,4,7,11};
    // int k=5;

    int n=4;
    int arr[n]={1,2,3,4};
    int k=2;

    // brute 
    brute_findKthPositive(n,arr,k);

    // optimal 
    optimal_findKthPositive(n,arr,k);
}
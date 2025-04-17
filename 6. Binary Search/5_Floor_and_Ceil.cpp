#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Floor and Ceil in Sorted Array 

You’re given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].

The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
*/

int brute_floor(int n, int arr[], int x){
    // Time complexity - O(n)

    // longest no in array <= x
    int ans;
    for(int i=0;i<n;i++){
        if(arr[i]<=x){
            ans=arr[i];
        }
    }
    return ans;

}

int optimal_floor(int n, int arr[], int x){
    // Time complexity - O(n)

    // largest no in array <= x
    int ans=-1;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]<=x){
            ans=arr[mid];
            //look for larger index on the left
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans; 
}



int brute_ceil(int n, int arr[], int x){
    // Time complexity - O(n)

    // smallest no in array >= x
    int ans;
    for(int i=0;i<n;i++){
        if (arr[i]>=x){
            ans=arr[i];
            break;
        }
    }
    return ans;
}

int optimal_ceil(int n, int arr[], int x){
    // Time complexity - O(log n)

    // smallest no in array >= x

    int ans=-1;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>=x){
            ans=arr[mid];
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans; 
}



int main(){
    int n=6;
    int arr[n]={3, 4, 4, 7, 8, 10};
    int x=5;

    // 1. brute floor
    cout<<brute_floor(n,arr,x)<<endl;

    // 2. optimal floor
    cout<<optimal_floor(n,arr,x)<<endl; 


    // 1. brute ceil
    cout<<brute_ceil(n,arr,x)<<endl;

    //2. optimal  
    cout<<optimal_ceil(n,arr,x)<<endl;

}
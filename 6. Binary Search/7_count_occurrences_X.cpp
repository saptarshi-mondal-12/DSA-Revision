#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count Occurrences in Sorted Array

You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Input: N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output: 4
Explanation: 3 is occurring 4 times in the given array 

Input: N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output: 5
Explanation: 2 is occurring 5 times in the given array
*/

int brute_occurrences(int n, int arr[], int x){
    // Time complexity - O(n)
    // space complexity - O(1)

    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==x) count++;
    }
    return count;
}

int binary_first(int n, int arr[], int x){
    int first=-1;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==x){
            first=mid;
            high=mid-1;
        }
        else if(arr[mid] > x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return first;
}

int binary_last(int n, int arr[], int x){
    int last=-1;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==x){
            last=mid;
            low=mid+1;
        }
        else if(arr[mid] > x){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return last;
}

int optimal_occurrences(int n, int arr[], int x){
    // Time complexity - O(log n)
    // space complexity - O(1)

    // we use first occurrence and last occurrence concept

    int first_Occurrence=binary_first(n,arr,x);
    if (first_Occurrence!=-1){
        int last_Occurrence=binary_last(n,arr,x);
        return last_Occurrence-first_Occurrence+1;
    }
    return 0;
}

int main(){
    int n=7;
    int arr[n]={2, 2 , 3 , 3 , 3 , 3 , 4};
    int x=14;

    // brute - linear search
    cout<<brute_occurrences(n,arr,x)<<endl;

    // optimal 
    cout<<optimal_occurrences(n,arr,x)<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Implement Upper Bound - arr[i] > x

Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 3
Explanation: Index 3 is the smallest index such that arr[3] > x.

Input Format: N = 6, arr[] = {3,5,8,9,15,19}, x = 9
Result: 4
Explanation: Index 4 is the smallest index such that arr[4] > x.
*/

void brute_upperBound(int n, int arr[], int x){
    // Time complexity - O(n)
    // space complexity - O(1)

    int index=n;
    for(int i=0;i<n;i++){
        if (arr[i]>x){
            index=i;
            break;
        }
    }
    cout<<index<<endl;
}

void optimal_upperBound(int n, int arr[], int x){
    // Time complexity - O(log n) 
    // space complexity - O(1)

    int index=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        // maybe an answer
        if (arr[mid] > x) {
            index = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }
    cout<<index<<endl; 
}



int main(){
    int n=6;
    int arr[n]={3,5,8,9,15,19};
    int x=9;

    // brute - linear search 
    brute_upperBound(n,arr, x);

    // optimal - binary search
    optimal_upperBound(n,arr, x);

}
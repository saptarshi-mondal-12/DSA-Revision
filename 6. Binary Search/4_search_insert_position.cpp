#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

void brute_searchInsert(int n, int arr[], int x){
    // Time complexity - O(n) 
    // space complexity - O(1)

    int index=n;
    for(int i=0;i<n;i++){
        if(arr[i]>=x){
            index=i;
            break;
        }
    }
    cout<<index<<endl;
}



void optimal_searchInsert(int n, int arr[], int x){
    // Time complexity - O(log n) 
    // space complexity - O(1)

    int index=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]>=x){
            index=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    cout<<index<<endl;
}

int main(){
    int n=4;
    int arr[]={1,3,5,6};
    int x=7;

    // brute - linear search
    brute_searchInsert(n,arr,x);

    // optimal
    optimal_searchInsert(n,arr,x);


}
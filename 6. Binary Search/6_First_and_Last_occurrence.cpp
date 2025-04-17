#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*Find First and Last Position of Element in Sorted Array 

Given a sorted array of N integers, write a program to find the index of the first and last occurrence of the target key. 
If the target is not found then return [-1,-1].

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Input: nums = [], target = 0
Output: [-1,-1]
*/

void brute_search(int n, int arr[], int target){
    // Time complexity - O(n) 
    // space complexity - O(1)
    
    int firstIndex=-1;
    int lastIndex=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            if(firstIndex==-1){
                firstIndex=i;
            }
            lastIndex=i;
        }
    }
    cout<<firstIndex<<" "<<lastIndex<<endl;
}

int lowerBound(int n, int arr[], int x){
    
    int index=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        // maybe an answer
        if (arr[mid] >= x) {
            index = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; 
        }
    }
    return index; 
}

int upperBound(int n, int arr[], int x){

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
    return index;
}

void optimal_search(int n, int arr[], int target){
    // Time complexity - O(log n)
    // space complexity - O(1)

    int lb=lowerBound(n,arr,target);
    int ub=upperBound(n,arr,target);

    if(lb==n || arr[lb]!=target){
        cout<<-1<<" "<<-1<<endl;
    }else{
        cout<<lb<<" "<<ub-1<<endl;
    }
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

int main(){
    int n=6;
    int arr[n]={5,7,7,8,8,10};
    int target=5;

    // 1. brute 
    brute_search(n,arr,target);

    // optimal
    optimal_search(n,arr,target);

    /* use binary search to find first and last occurrence of x
    we cannot find both in single binary search so we have to use seperate to find first and last occurrence of x */

    cout<<binary_first(n,arr,target)<<" "<<binary_last(n,arr,target)<<endl;
}
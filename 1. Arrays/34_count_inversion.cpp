#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count inversions in an array

Given an array of N integers, count the inversion of the array (using merge-sort).
What is an inversion of an array? Definition: for all i & j < size of array, 
if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i]

Input Format: N = 5, array[] = {1,2,3,4,5}
Result: 0
Explanation: we have a sorted array and the sorted array has 0 inversions as for i < j you will never find a pair such that A[j] < A[i]. 

Input Format: N = 5, array[] = {5,4,3,2,1}
Result: 10
Explanation: we have a reverse sorted array and we will get the maximum inversions as for i < j we will always find a pair such that A[j] < A[i]. 

Input Format: N = 5, array[] = {5,3,2,1,4}
Result: 7
Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition. 
*/



void brute_countInversion(int n, int arr[]){
    // Time complexity - O(n^2)
    // Space complexity - O(1)

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    cout<<count<<endl;
}
int merge(int arr[], int low, int mid, int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;

    int count=0;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            count+=(mid-left+1);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    int indx=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[indx];
        indx++;
    }
    return count;
}

int mergeSort(int arr[], int low, int high){
    int count=0;
    if (low>= high) return count;
    int mid=(low+high)/2;
    count+=mergeSort(arr,0,mid);
    count+=mergeSort(arr,mid+1,high);
    count+=merge(arr,low,mid,high);

    return count;
}
void better_countInversion(int n, int arr[]){
    // Time complexity - O(n log n)
    // Space complexity - O(n)

    cout<<mergeSort(arr,0,n-1)<<endl;
}



int main(){
    int n=5;
    int arr[n]={5,4,3,2,1};

    // 1. brute
    // brute_countInversion(n,arr);

    // 2. optimal
    better_countInversion(n,arr);
}
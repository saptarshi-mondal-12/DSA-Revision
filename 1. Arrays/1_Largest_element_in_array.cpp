#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an array A[] of size n. The task is to find the largest element in it.

Input: n = 5 ,A[] = {1, 8, 7, 56, 90}
Output: 90
Explanation: The largest element of given array is 90.
*/

// NOTE : o(N) < o(nlogn)

int find_max(int n, int arr[]){
    // Time complexity - O(n log n) 
    // Space complexity - O(1)

    // sort the array
    // return last index(n-1)

    sort(arr,arr+n);
    return arr[n-1];
}

int findMax(int n, int arr[]){
    // Time complexity - O(n)
    // We can maintain a maxElement variable that will update 
    // whenever the current value is greater than the value in the max variable.   

    int maxElement =arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]> maxElement) maxElement=arr[i];
    }
    return maxElement;
}

int main(){
    int n=7;
    int arr[n]={1,8,7,56,90,3,4};

    // 1. brute force 
    // cout<<"largest element in array: "<<find_max(n,arr)<<endl;

    // 2. optimal solution 
    cout<<"largest element in array: "<<findMax(n,arr)<<endl;
}



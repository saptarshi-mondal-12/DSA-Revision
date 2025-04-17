#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q1.left rotate an array by one
input : arr={1,2,3,4,5}
output : {2,3,4,5,1}


Q2.left rotate an array by k position
input : arr={1,2,3,4,5}, k=3
output : {4,5,1,2,3}
*/

void leftRotateByOne(int n, int arr[]){
    // Time complexity - O(n)

    int temp=arr[0];
    for(int i=1;i<n;i++) arr[i-1]=arr[i];
    arr[n-1]=temp;

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

void leftRotateByk(int n, int arr[], int k){
    k=k%n;

    // Time complexity - O(k) + O(n-k) + O(k) = O(n+k)
    // space complexity - O(k)

    // 1. Brute force

    // int temp[k];
    // for(int i=0;i<k;i++){
    //     temp[i]=arr[i];
    // }
    // for(int i=k;i<n;i++){
    //     arr[i-k]=arr[i];
    // }
    // int j=0;
    // for(int i=n-k;i<n;i++){
    //     arr[i]=temp[j];
    //     j++;
    // }



    // Time complexity - O(k) + O(n-k) + O(n) = O(2n)
    // space complexity - O(1)

    // 2. Optimal soln (1 2 n)
    //step 1: first k reverse
    reverse(arr, arr + k);
    //step 2: after k reverse
    reverse(arr + k, arr + n);
    //step 3: whole array reverse
    reverse(arr, arr + n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

int main(){

    int n=7;
    int arr[n]={1,2,3,4,5,6,7};
    int k=4;

    // Q1. left Rotate By One
    // leftRotateByOne(n,arr);

    // Q2. left Rotate by k
    leftRotateByk(n,arr,k);
    
}
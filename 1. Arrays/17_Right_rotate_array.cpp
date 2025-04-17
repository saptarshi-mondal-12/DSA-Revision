#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q1.Right rotate an array by one
input : arr={1,2,3,4,5}
output : {5,1,2,3,4}


Q2.Right rotate an array by k position
input : arr={1,2,3,4,5}, k=3
output : {3,4,5,1,2}
*/

void RightRotateByOne(int n, int arr[]){
    // Time complexity - O(n)

    int temp=arr[n-1];
    for(int i=n-1;i>=0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}

void brute_RightRotateByk(int n, int arr[], int k){
    // Time complexity - O(k) + O(n-k) + O(k) = O(n+k)
    // space complexity - O(k)
    
    k=k%n;

    // Create a temporary array to hold the last 'k' elements
    vector<int>v;  

    // Copy the last 'k' elements from the original array to the temp array
    for(int i=n-k;i<n;i++){
        v.push_back(arr[i]);
    }

    // Shift elements in the original array to the right to make space for rotated elements
    for(int i=n-k-1;i>=0;i--){
        arr[i+k]=arr[i];
    }

    // Copy elements from the temp array back to the beginning of the original array
    for(int i=0;i<v.size();i++){
        arr[i]=v[i];
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    
}

void optimal_RightRotateByk(int n, int arr[], int k){
    // Time complexity - O(n) + O(k) + O(n-k) = O(2n)
    // space complexity - O(1)

    k=k%n;


    // step 1: all reverse
    reverse(arr, arr+n); 

    //step 2: first k reverse
    reverse(arr, arr + k);

    //step 3: after k reverse
    reverse(arr+k, arr+n);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

}

int main(){

    int n=7;
    int arr[n]={1,2,3,4,5,6,7};
    int k=3;

    // Q1. Right Rotate By One
    // RightRotateByOne(n,arr);

    // Q2. Right Rotate by k
    // brute_RightRotateByk(n,arr,k);
    optimal_RightRotateByk(n,arr,k);
    
}
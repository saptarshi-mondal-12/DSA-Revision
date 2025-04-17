#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Move all zero to end of the array 
input : arr={1,0,2,3,2,0,0,4,5,1};
output : {1,2,3,2,4,5,1,0,0,0}
*/

void brute_moveZeroes(int n, int arr[]){
    // Time complexity : O(n) + O(x) + O(n-x) = O(2n)
    // space complexity : O(x) where x is no of non zero no (worst case O(n))

    // 1. move all non zero element to temp
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0) temp.push_back(arr[i]);
    }
    // pick up all element from the temp and put in front of array (i=0 to k (size of temp))
    int k=temp.size();
    for(int i=0;i<k;i++) arr[i]=temp[i];

    // filling up zero at back (k to n)
    for(int i=k;i<n;i++) arr[i]=0;
}

void optimal_moveZero(int n, int arr[]){
    // time complexity : O(x) + O(n-x) = O(n)
    // space complexity : O(1)

    // using 2 pointer
    // 1. point j to 1st zero 
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main(){
    int n=10;
    int arr[n]={1,0,2,3,2,0,0,4,5,1};

    // 1. brute force
    // brute_moveZeroes(n,arr);

    // 2. optimal solution
    optimal_moveZero(n,arr);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";



}
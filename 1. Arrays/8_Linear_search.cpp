#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int linearSearch(int n, int arr[], int num){
    // Time complexity - O(n)
    
    for(int i=0;i<n;i++){
        if(arr[i]==num) return i;
    }
    return -1;
}

int main(){
    int n=5;
    int arr[n]={1,2,3,4,5};
    int num=4;
    cout<<linearSearch(n,arr,num);
}
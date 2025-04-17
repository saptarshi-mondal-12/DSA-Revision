#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Given an unsorted array, remove duplicates from the array. Remove Duplicates From an Unsorted Array
Input: arr[]={2,3,1,9,3,1,3,9}
Output: [2,3,1,9]
Explanation: Total number of unique elements are 4, i.e[2,3,1,9]*/

void brute_removeDuplicates(int n, int arr[]){
    //  Time complexity - O(n^2) + O(n)
    //  space complexity - O(n) 

    int mark[n]={0};

    for(int i=0;i<n;i++){
        if(mark[i]==0){
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j])
                    mark[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++)
        if(mark[i]==0) cout<<arr[i]<<" ";
}

void optimal_removeDuplicates(int n, int arr[]){
    //  Time complexity - O(n) + O(n) = O(2n) (Iteration in array + searching hash table)
    //  space complexity - O(n) - worst case

    map<int,int>mp;
    for(int i=0;i<n;i++){
        if(mp.find(arr[i])==mp.end()){
            cout<<arr[i]<<" ";
            mp[arr[i]]++;
        }
    }
}

int main(){
    int n=8;
    int arr[n] = {2,3,1,9,3,1,3,9};

    // 1. Brute force 
    // brute_removeDuplicates(n,arr);

    // 2. optimal force 
    optimal_removeDuplicates(n,arr);

    
}
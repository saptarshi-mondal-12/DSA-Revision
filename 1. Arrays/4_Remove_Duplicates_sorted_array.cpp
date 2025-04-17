#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Remove Duplicates in-place from Sorted Array

Given an integer array sorted in non-decreasing order, remove the duplicates in place such that 
each unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

Note: Return k after placing the final result in the first k slots of the array.

Input: arr[1,1,2,2,2,3,3]
Output: arr[1,2,3,_,_,_,_]
Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array*/

int brute_removeDuplicates(int n, int arr[]){
    //  Time complexity - O(n log n) + O(n)
    //  space complexity - O(n)

    // Declare a Hashset
    // Run a for loop from starting to the end.
    // Put every element of the array in the set.
    set<int>set;
    for(int i=0;i<n;i++) set.insert(arr[i]);

    // Store size of the set in a variable K.
    // Now put all elements of the set in the array from the starting of the array.
    int k=set.size();
    int i=0;
    for(auto it:set){
        arr[i]=it;
        i++;
    }
    return k;
}

int optimal_removeDuplicates(int n, int arr[]){
    //  Time complexity - o(n);
    //  space complexity - O(1)

    // using two pointer 
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n=7;
    int arr[] = {1,1,2,2,2,3,3};

    // 1. Brute force 
    // int k=brute_removeDuplicates(n,arr);

    // 2. optimal force 
    int k=optimal_removeDuplicates(n,arr);

    for(int i=0;i<k;i++) cout<<arr[i]<<" ";
}
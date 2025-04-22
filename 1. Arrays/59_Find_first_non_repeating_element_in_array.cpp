#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Find first non-repeating element in a given Array

Given an array of integers of size N, the task is to find the first non-repeating element in this array. 

Input: {-1, 2, -1, 3, 0}
Output: 2
Explanation: The first number that does not repeat is : 2

Input: {9, 4, 9, 6, 7, 4}
Output: 6*/

int firstNonRepeating(int arr[], int n){

    // Insert all array elements in map table
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
 
    // Traverse array again and return first element with count 1.
    for (int i = 0; i < n; i++)
        if (mp[arr[i]] == 1)
            return arr[i];
    return -1;
}
 

int main(){
    int arr[] = { 9, 4, 9, 6, 7, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << firstNonRepeating(arr, n);
    return 0;
}
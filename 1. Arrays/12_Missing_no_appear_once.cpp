#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Find the number that appears once, and the other numbers twice

Given a non-empty array of integers arr, every element appears twice except for one. 
Find that single one.
Input : arr[] = {4,1,2,1,2}
Result: 4
Explanation: In this array, only the element 4 appear once and so it is the answer.*/

int brute_getSingleElement(int n, int arr[]){
    // time complexity - O(n^2)
    // space complexity - O(1)

    // intuition - For every element present in the array, we will do a linear search and count the occurrence. 
    // If for any element, the occurrence is 1, we will return it.
    
    // Run a loop for selecting elements:
    for(int i=0;i<n;i++){
        int num=arr[i]; // selected element
        int count=0;

        //find the occurrence using linear search:
        for(int j=0;j<n;j++){
            if(arr[j]==num) count++;
        }

        // if the occurrence is 1 return ans:
        if (count==1) return num;
    }

}


int better_getSingleElement(int n, int arr[]){
    // Time complexity : O(n log m) + O(m) where M = size of the map 
    // We are inserting n elements in the map data structure and insertion takes logM time(where m = size of the map))
    // space complexity : O(/m)


    // using map data structure
    map<int,int>mp;
    for(int i=0;i<n;i++) mp[arr[i]]++;

    for(auto it:mp){
        if(it.second==1) return it.first;
    }
}


int optimal_getSingleElement(int n, int arr[]){
    // Time complexity : O(n)
    // space complexity : O(1)

    // Intuition - using XOR
    int xorr=arr[0];
    for(int i=1;i<n;i++) xorr^=arr[i];
    return xorr;

}


int main(){
    int n=5;
    int arr[n]={4,1,2,1,2};

    // 1. Brute force
    // cout<<brute_getSingleElement(n,arr);

    // 2. Better soln
    // cout<<better_getSingleElement(n,arr);

    // 3. optimal soln
    cout<<optimal_getSingleElement(n,arr);

}
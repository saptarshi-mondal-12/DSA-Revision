#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array.
Input: prices = {1, 1, 0, 1, 1, 1}
Output: 3
Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

Input: prices = {1, 0, 1, 1, 0, 1} 
Output: 2
Explanation: There are two consecutive 1's in the array*/

int maxConsecutive(int n, int arr[]){
    // Time complexity - O(n)
    // Space complexity - O(1)

    int mx=INT_MIN;
    int count=0;
    for(int i=0;i<n;i++){
        if (arr[i]==1) count++;
        else count=0;
        mx=max(mx,count);
    }
    return mx;
}

int main(){
    int n=14;
    int arr[n]={1,1,0,1,1,1,0,0,1,0,1,1,1,1};

    cout<<maxConsecutive(n,arr);
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Max Sum Subarray of size K

Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Input: arr[] = [100, 200, 300, 400] , k = 2
Output: 700
Explanation: arr3  + arr4 = 700, which is maximum.

Input: arr[] = [100, 200, 300, 400] , k = 4
Output: 1000
Explanation: arr1 + arr2 + arr3 + arr4 = 1000, which is maximum.

Input: arr[] = [100, 200, 300, 400] , k = 1
Output: 400
Explanation: arr4 = 400, which is maximum.
*/

int maximumSumSubarray(vector<int>& arr, int k) {
    // Time complexity : O(n)
    // Space complexity : O(1)
    int n=arr.size();
    int result=INT_MIN;
    int left=0, right=0, currSum=0;
    while(right<n){
        currSum+=arr[right];
    
        while(right-left >= k){
            currSum-=arr[left];
            left++;
        }
        result=max(result, currSum);
        right++;
    }
    return result;
    
    
    
    // Time complexity : O(n*k)
    // Space complexity : O(1)
    // int n=arr.size();
    // int result=INT_MIN;
    // for(int i=0; i<n-k+1; i++){
    //     int currSum=0;
    //     for(int j=i;j<i+k;j++){
    //         currSum+=arr[j];
    //     }
    //     result=max(result, currSum);
    // }
    // return result;
}
int main(){
    vector<int>arr={100,200,300,400};
    int k=2;
    cout<<maximumSumSubarray(arr,k)<<endl;
}
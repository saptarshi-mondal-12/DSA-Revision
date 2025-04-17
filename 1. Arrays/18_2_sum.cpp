#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/

int brute_targetSum(int n, int arr[], int target){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j and arr[i]+arr[j]==target){
                return true; 
            }
        }
    }
    return false;
}

int better_targetSum(int n, int arr[], int target){
    // Time complexity - O(n log n)
    // space complexity - O(n)

    map<int,int>mp;
    for(int i=0;i<n;i++){
        int a=arr[i];
        int required=target-a;

        if(mp.find(required)!=mp.end()){
            return true;
        }
        mp[a]=i;
    }
    return false;
}

int Optimal_targetSum(int n, int arr[], int target){
    // Time complexity - O(n) + O(n log n) for sorting
    // space complexity - O(1)

    sort(arr,arr+n);

    int i=0;
    int j=n-1;
    while (i<j){
        if(arr[i]+arr[j]==target){
            return true;
        }
        else if (arr[i]+arr[j]>target){
            j-=1;
        }else{
            i+=1;
        }
    }
    return false;
}




int main(){
    int n=5;
    int arr[n]={2,6,5,8,11};
    int target=14;

    // 1. Brute force - for loop O(n^2)
    // cout<<brute_targetSum(n,arr,target);

    // 2. Better soln - hashing, tc=O(n) sc=O(n)
    // cout<<better_targetSum(n,arr,target);

    // 3. Optimal soln - 2 pointer, tc=O(n) sc=O(n)
    cout<<Optimal_targetSum(n,arr,target);




}
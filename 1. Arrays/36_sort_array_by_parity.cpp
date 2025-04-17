#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Sort Array By Parity

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.

 Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Input: nums = [0]
Output: [0]
*/

void brute_sortArrayByParity(int n, int nums[]){
    // Time complexity - O(n)
    // space complexity - O(n)

    vector<int>even;
    vector<int>odd;
    for(int i=0;i<n;i++){
        if(nums[i]%2==0){
            even.push_back(nums[i]);
        }else{
            odd.push_back(nums[i]);
        }
    }
    for(int i=0;i<odd.size();i++){
        even.push_back(odd[i]);
    }
    
    for(int i=0;i<even.size();i++) cout<<even[i]<<" ";
    cout<<endl;
}


void optimal_sortArrayByParity(int n, int nums[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    int evenIndex=0;
    for(int j=0;j<n;j++){
        if(nums[j]%2==0){
            swap(nums[evenIndex],nums[j]);
            evenIndex++;
        }
    }
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    cout<<endl;
}


int main(){
    int n=4;
    int arr[n]={3,1,2,4};

    // 1. brute
    brute_sortArrayByParity(n,arr);

    // 2. optimal
    optimal_sortArrayByParity(n,arr);
}
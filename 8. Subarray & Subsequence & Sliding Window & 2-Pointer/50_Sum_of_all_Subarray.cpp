#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>&nums){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int n=nums.size();
    int totalSubarraySum=0;
    for(int i=0;i<n;i++){
        int currSum=0;
        for(int j=i;j<n;j++){
            currSum+=nums[j];
            totalSubarraySum+=currSum;
        }
    }
    return totalSubarraySum;
}

int optimalSubarraySum(vector<int>&nums){
    // Time complexity - O(n)
    // space complexity - O(1)

    int n=nums.size();
    int totalSubarraySum=0;

    // current index contribution = ((no of starting) * (no of ending)) * nums[i] 
    // i.e. (i-(-1) * (n-i)) * nums[i]

    for(int i=0;i<n;i++){
        totalSubarraySum = totalSubarraySum + ((i-(-1)) * (n-i))*nums[i];
    }
    return totalSubarraySum;
}

int main(){
    vector<int>nums={1,2,2,1,3};

    // brute
    cout<<subarraySum(nums)<<endl;

    // optimal
    cout<<optimalSubarraySum(nums)<<endl;

}
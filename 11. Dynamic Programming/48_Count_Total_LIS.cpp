#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

/* Q. Count no of longest increasing subsequence 
*/

int count_longestIncreasingSubsequence(vector<int>nums){
    int n=nums.size();

    // The max length will be 1 i.e he itself
    vector<int>dp(n,1);

    // To keep a track of count
    vector<int>count(n,1);

    int maxi = 1;

    for(int i=0; i<=n-1; i++){
        for(int prev = 0; prev <= i-1; prev ++){
            if(nums[prev]<nums[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }else if (nums[prev]<nums[i] && 1+dp[prev] == dp[i]){
                count[i]+=count[prev];
            }
        }
        if(dp[i] > maxi){
            maxi=dp[i];
        }
    } 

    cout<<"Length of Longest Increasing subsequence: "<<maxi<<endl;

    int totalLIS=0;
    for(int i=0;i<n;i++){
        if(dp[i] == maxi){
            totalLIS+=count[i];
        }
    }
    return totalLIS;
}
int main(){
    vector<int>nums = {1,4,3,5,8,1}; // ans = 2 (1,4,5,8) & (1,3,5,8)
    cout<<"Count LIS: "<<count_longestIncreasingSubsequence(nums)<<endl;
}

// nums  = [1, 4, 3, 5, 8, 1]
// dp    = [1, 2, 2, 3, 4, 1]
// count = [1, 1, 1, 2, 2, 1]
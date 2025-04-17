#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. House Robber

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Intuition: concept of pick and not pick 
Answer: same code as maximum sum of non adjacent element
*/


int tabulation_rob(vector<int>& nums){
    // Time complexity: O(n)
    // space complexity: O(n)

    int n=nums.size();
    vector<int>dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        // pick the current element and pick last non adjacent element i.e dp[i-2]
        int pick=nums[i];
        if(i>1){
            pick+=dp[i-2];
        }
        // notpick = skip the current element and pick last value i.e dp[i-1]
        int notpick=dp[i-1];

        // take maximum 
        dp[i]=max(pick, notpick);
    }
    return dp[n-1];
}


int rob(vector<int>& nums) {
    // Time complexity: O(n)
    // space complexity: O(1)
    int n=nums.size();
    int prev2=0;
    int prev=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i] + prev2;
        int notpick=prev;
        int curr_i=max(pick, notpick);
        prev2=prev;
        prev=curr_i;
    }
    return prev;
}

int main(){
    vector<int>nums={2,7,9,3,1};

    // Tabulation 
    cout<<tabulation_rob(nums)<<endl;

    // space optimize
    cout<<rob(nums)<<endl;
}


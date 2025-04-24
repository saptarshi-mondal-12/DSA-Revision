#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Distinct Numbers in Each Subarray  -> variation of Q.49

In this problem, we are given an array of integers, nums, and another integer, k. Our task is to find the number of distinct integers in every contiguous subarray of nums that has a length of k. We construct an array ans such that each element ans[i] represents the number of distinct integers in the subarray starting from index i to index i+k-1 inclusively. The result will be an array of the counts of distinct integers for each subarray of size k.

For example, suppose nums is [1, 2, 3, 2, 2, 1] and k is 3. The subarrays of size three are:

[1, 2, 3], which has 3 distinct numbers;
[2, 3, 2], which has 2 distinct numbers;
[3, 2, 2], which has 2 distinct numbers;
[2, 2, 1], which has 2 distinct numbers. The resulting ans would be [3, 2, 2, 2].
*/

vector<int> brute_distinctNumbers(vector<int>nums, int k){
    // Time complexity: O(n*k)
    // space complexity: O(k)

    int n=nums.size();
    vector<int>result;
    for(int i=0;i<n-k+1;i++){
        set<int>st;
        for(int j=i;j<i+k;j++){
            st.insert(nums[j]);
        }
        result.push_back(st.size());
    }
    return result;
}

vector<int> optimal_distinctNumbers(vector<int>nums, int k){
    // Time compleixty: O(n)
    // Space complexity: O(k)

    int n=nums.size();
    unordered_map<int, int>mp;
    vector<int>result;
    int left=0, right=0;
    while(right<n){
        mp[nums[right]]++;
        if((right-left+1) > k){
            mp[nums[left]]--;
            if(mp[nums[left]] == 0){
                mp.erase(nums[left]);
            }
            left++;
        }

        if((right-left+1) == k){
            result.push_back(mp.size());
        }
        right++;
    }
    return result;
}

int main(){
    vector<int>nums={1, 2, 3, 2, 2, 1};
    int k=3;

    // brute
    // vector<int>ans=brute_distinctNumbers(nums, k);

    // optimal
    vector<int>ans=optimal_distinctNumbers(nums, k);

    for(auto it: ans){
        cout<<it<<" ";
    }
}
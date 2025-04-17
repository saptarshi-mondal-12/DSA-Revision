#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Count distinct elements in every window of size k

Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Input: K=4,array[] = {1,2,1,3,4,2,3}
Output: 3  4  3  3
Explanation:First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3
*/

vector<int> brute_countDistinct(vector<int> &nums, int k) {
    // Time complexity - O(n * k)
    // space complexity - O(1)

    int n=nums.size();
    vector<int>result;
    for(int i=0;i<n-k+1;i++){
        unordered_set<int>st;
        for(int j=i;j<i+k;j++){
            st.insert(nums[j]);
        }
        result.push_back(st.size());
    }
    return result;   
}

vector<int> optimal_countDistinct(vector<int> &nums, int k) {
    // Time complexity - O(n)
    // space complexity - O(n)

    int n=nums.size();
    vector<int>result;
    unordered_map<int,int> mp;
    int left=0;
    for(int right=0;right<n;right++){
        mp[nums[right]]++;
        
        if(right-left+1 == k){
            result.push_back(mp.size());
                
            mp[nums[left]]--;
            if(mp[nums[left]]==0)
            {
                mp.erase(nums[left]);
            }
            left++;
        }
    }
    return result;
}

int main(){
    int k=3;
    vector<int>nums={1,2,3,2,2,1,3};

    // brute
    // vector<int>result=brute_countDistinct(nums, k);

    // optimal
    vector<int>result=optimal_countDistinct(nums, k);

    for(auto it:result){
        cout<<it<<' ';
    }
}
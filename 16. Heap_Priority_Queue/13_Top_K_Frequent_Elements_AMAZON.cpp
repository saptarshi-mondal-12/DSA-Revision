#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Top K Frequent Elements - AMAZON 2026

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Input: nums = [1], k = 1
Output: [1]

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
*/

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Time complexity: O(n log k)
    // Spac ecomplexity: O(n)
        
    int n = nums.size();

    // 1. storing frequency of each element
    unordered_map<int,int>freq;
    for(int i=0;i<n;i++){
        freq[nums[i]]++;
    }

    // 2. Using min heap to storing top k most frequent element 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

    for(auto it: freq){
        int val = it.first;
        int frequency = it.second;
        pq.push({frequency, val});
        if(pq.size() > k){
            pq.pop();
        }
    }

    // 3. store in answer
    vector<int>result;

    while(!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;   
}
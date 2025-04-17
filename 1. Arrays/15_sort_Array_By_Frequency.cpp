#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Given an array of integers nums, sort the array in increasing order based on the frequency of the values. 
If multiple values have the same frequency, sort them in decreasing order. Return the sorted array.

Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.

Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
*/
bool compare(pair<int,int>a, pair<int,int>b){
    if(a.second<b.second) return true;
    if(a.second>b.second) return false;
    
    if (a.first>b.first) return true;
    else return false;

}
vector<int>frequencySort_Compare(vector<int> nums){

    // Time complexity - O(n log n)
    // space complexity - O(n) 

    // 1. creating map to store frequency 
    map<int,int>mp;
    for(int i=0;i<nums.size();i++) mp[nums[i]]++;

    vector<pair<int,int>>v;
    for(auto it:mp) v.push_back({it.first,it.second});

    sort(v.begin(),v.end(),compare);

    // storing result into new vector
    vector<int>result;
    for(auto it:v){
        int element=it.first;
        int freq=it.second;
        for(int i=0;i<freq;i++) result.push_back(element);
    }
    return result;

}


vector<int>frequencySort_PriorityQueue(vector<int> nums){

    map <int,int> mp;
    for(int i=0;i<nums.size();i++) mp[nums[i]]++;

    priority_queue <pair <int,int>> pq;    
    for(auto it:mp) pq.push({-it.second,it.first});

    vector<int>result;   
        
    while(!pq.empty()){
        int freq=-pq.top().first;
        int element=pq.top().second;
        pq.pop();
        for(int i=0;i<freq;i++) result.push_back(element);
    }
    return result;

}
int main(){
    // vector<int>nums={1,1,2,2,2,3};
    vector<int>nums={1,2,2,3,3,3,4,4,4,5,5,5,5,5};
    // 1. using vector + compare
    // vector<int>result=frequencySort_Compare(nums);

    // 2.using priority_queue
    vector<int>result=frequencySort_PriorityQueue(nums);

    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
}

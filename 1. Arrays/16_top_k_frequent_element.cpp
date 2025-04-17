#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. 
If two numbers have the same frequency then the larger number should be given preference. 

input : N = 6, nums = {1,1,1,2,2,3}, k = 2
Output: {1, 2}

input: N = 8, nums = {1,1,2,2,3,3,3,4}, k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the same frequency ie. 2. Therefore, in this case, the answer includes the element 2 as 2 > 1. 
*/

int main(){
    // Time Complexity : O(n log n)
    // space complexity : O(n)
    int n=6;
    vector<int>nums={1,1,1,2,2,3};
    int k=2;

    map<int,int>mpp;
        
    for(int i=0;i<n;i++) mpp[nums[i]]++ ;
        
    priority_queue<pair<int,int>>p;
    for (auto it: mpp) p.push({it.second,it.first});
        
    vector<int>result;

    for(int i=0;i<k;i++){
        result.push_back(p.top().second);
        p.pop();
    }

    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";

}
#include<bits/stdc++.h>
using namespace std;

/* Q. Find k smallest elements in an array 

Given an array arr[] and an integer k, the task is to find k smallest elements in the given array. Elements in the output array can be in any order.

Input: arr[] = [1, 23, 12, 9, 30, 2, 50], k = 3
Output: [1, 2, 9]

Input: arr[] = [11, 5, 12, 9, 44, 17, 2], k = 2
Output: [2, 5]

*/


// brute soln -------------------------------------------------------------------------
vector<int>kSmallest(vector<int>nums, int k){
    // Time complexity: O(n log n) + O(k);
    // space complexity: O(k)

    int n=nums.size();

    // sort the given array in ascending order
    sort(nums.begin(), nums.end());

    vector<int>result;

    // store the first k element in result array
    for(int i=0;i<k;i++){
        result.push_back(nums[i]);
    }

    return result; 
}



// Optimal soln -------------------------------------------------------------------------
vector<int>optimal_kSmallest(vector<int>nums, int k){
    // Time complexity: O(n log k)
    // Space complexity: O(k)

    // [Approach - 2] Using Priority Queue(Max-Heap)

    int n=nums.size();

    priority_queue<int>pq;

    for(int i=0;i<n;i++){
        if(pq.size() < k){
            pq.push(nums[i]);
        }
        else{
            int top = pq.top();
            if(nums[i] < top){
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    vector<int>result;

    // Max heap will contain only k smallest element
    while(!pq.empty()){
        int top = pq.top();
        result.push_back(top);
        pq.pop();
    }

    return result;
}



int main(){
    vector<int>nums={1, 23, 12, 9, 30, 2, 50};
    int k=3;
    
    // 1. brute soln
    // vector<int>result = kSmallest(nums, k);

    // 2. optimal soln
    vector<int>result = optimal_kSmallest(nums, k);

    cout<<"k smallest elements are : "<<endl;
    for(auto it : result){
        cout<<it<<" ";
    }
}
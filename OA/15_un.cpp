#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Maximal Score After Applying K Operations

You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
In one operation:
choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
*/

long long brute_maxKelements(vector<int>& nums, int k) {
        // TC = O(k*n)
        int n=nums.size();
        long long int result=0;
        for(int i=0;i<k;i++){
            int maxi=0;
            int index=0;
            for(int j=0;j<n;j++){
                if (nums[j] > maxi){
                    maxi=nums[j];
                    index=j;
                }
            }
            result+=nums[index];
            nums[index]=ceil(nums[index] / 3.0);
        }
        return result;
}

long long optimal_maxKelements(vector<int>& nums, int k) {
        // O(K∗Log(N))
        // intuition - priority queue
        int n=nums.size();
        long long int result=0;
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i=0;i<k;i++){
            int maxi=pq.top();
            pq.pop();
            result+=maxi;
            int newValue=ceil(maxi/3.0);
            pq.push(newValue);
        }
        return result;
}

int main(){
    vector<int>nums={1,10,3,3,3};
    int k=3;

    // brute
    cout<<brute_maxKelements(nums, k)<<endl;

    // optimal
    // cout<<optimal_maxKelements(nums, k)<<endl;
}
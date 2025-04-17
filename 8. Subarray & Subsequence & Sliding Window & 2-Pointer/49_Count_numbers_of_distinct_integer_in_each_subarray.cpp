#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Q1. Distinct Numbers in Each Subarray

For example:
Subarrays of [1, 2, 2, 1] are:

[1] → Distinct count = 1
[1, 2] → Distinct count = 2
[1, 2, 2] → Distinct count = 2
[1, 2, 2, 1] → Distinct count = 2
[2] → Distinct count = 1
[2, 2] → Distinct count = 1
[2, 2, 1] → Distinct count = 2
[2] → Distinct count = 1
[2, 1] → Distinct count = 2
[1] → Distinct count = 1

So we should return vector = [1,2,2,2,1,1,2,1,2,1]


Q2. Sum of count of Distinct Numbers in Each Subarray
Sum of distinct counts = 1 + 2 + 2 + 2 + 1 + 1 + 2 + 1 + 2 + 1 = 15



NOTE - Final Thoughts
Q1. Ans : If you need to store all distinct counts for each subarray explicitly, brute force is the only way (O(n²)).
Q2. Ans: If you just need a sum of distinct numbers across all subarrays, the optimized O(n) method is the best choice.


/*  Expalnation:

i−prev[i]:  This represents the number of subarrays that start after the previous occurrence of nums[i] and include nums[i].

n-i: This represents the number of subarrays that end at or after nums[i]

Contribution = (i−prev[i]) × (n−i)

nums=[1,2,2,1,3]
contribution=[5,8,3,6,5]

How index 1 i.e 2 contributes 8 time

part 1: (i-prev[i]) = 2
This represents the number of subarrays that start after the previous occurrence of nums[i] and include nums[i].

    Subarrays starting at index 0 and including nums[1] = 2.
    Subarrays starting at index 1 and including nums[1] = 2.

So, there are 2 starting points for subarrays that include nums[1] = 2.


part 2: (n-i) = 4
This represents the number of subarrays that end at or after nums[i]
Since i=1 and n=5, the subarrays can end at indices 1, 2, 3, or 4.
So, there are 4 ending points for subarrays that include nums[1] = 2.

Total subarray = 2*4=8

Starting at Index 0:
    [1, 2] → Ends at index 1
    [1, 2, 2] → Ends at index 2
    [1, 2, 2, 1] → Ends at index 3
    [1, 2, 2, 1, 3] → Ends at index 4

Starting at Index 1:
    [2] → Ends at index 1
    [2, 2] → Ends at index 2
    [2, 2, 1] → Ends at index 3
    [2, 2, 1, 3] → Ends at index 4

    For nums[1] = 2:

Summary:
    Starting points: 2 (index 0 and index 1)
    Ending points: 4 (indices 1, 2, 3, 4)
    Total subarrays: 2×4=8
    Contribution: 8
*/


vector<int> distinct_in_each_subarray(vector<int>&nums){
    // Time complexity - O(n^2)
    // space complexity - O(n)
    int n=nums.size();
    unordered_map<int, int> mp;
    vector<int>result;
    for(int i=0;i<n;i++){
        mp.clear();
        int distinct=0;
        for(int j=i;j<n;j++){
            mp[nums[j]]++;
            if (mp[nums[j]] == 1){
                distinct++;
            }
            result.push_back(distinct);
        }
    }
    return result;
}

int brute_distinct(vector<int>&nums){
    // Time complexity : O(n^2)
    // space complexity : O(n)
    int n=nums.size();
    int result=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp.clear();
        for(int j=i;j<n;j++){
            mp[nums[j]]++;
            result+=mp.size();
        }

    }
    return result;
}


int optimal_distinct(vector<int>& nums) {
    // Time Complexity: O(n)
    // space complexity: 

    int n = nums.size();

    // Map to store the last seen index of each value
    unordered_map<int, int> lastSeen;

    // store the index of the previous occurrence of the current element
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++) {
        if (lastSeen.count(nums[i])) {
            prev[i] = lastSeen[nums[i]];
        }
        lastSeen[nums[i]] = i;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        // Contribution of nums[i] is the number of subarrays where it is the first occurrence
        result += (i - prev[i]) * (n - i);
    }
    return result;
}



int main(){
    vector<int>nums={1,2,2,1,3};

    // Q1. brute but most optimal solution O(n^2)
    // vector<int>result=distinct_in_each_subarray(nums);
    // for(auto it:result){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // --------------------------------------------------------------------------



    // Q2. brute
    cout<<brute_distinct(nums)<<endl;


    // Q2. optimal 
    cout<<optimal_distinct(nums)<<endl;
}


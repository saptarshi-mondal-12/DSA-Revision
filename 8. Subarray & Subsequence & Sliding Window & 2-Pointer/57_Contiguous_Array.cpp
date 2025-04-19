#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
*/

int findMaxLength(vector<int>& nums) {
    // Time complexity: O(n^2)
    // space complexity: O(n)
    int n=nums.size();
    int maxi = 0;
    int count = 0;
    unordered_map<int, int> d;
    d[0] = 0;

    for (int i = 0; i < n; i++){
        if (nums[i] == 1)
            count++;
        else{
            count--;
        }
        if (d.find(count) != d.end()) {
            maxi = max(maxi, i-d[count]+1 );
            // if count is present we not update the map because we want maximum 
        } else {
            // if count is not present we update 
            d[count] = i + 1;
        }
    }
    return maxi;


    // Time complexity: O(n^2)
    // space complexity: O(1)
    // int n=nums.size();
    // int maxi=0;
    // for(int i=0;i<n;i++){
    //     int o=0, z=0;
    //     for(int j=i;j<n;j++){
    //         if (nums[j]==0){
    //             z+=1;
    //         }else{
    //             o+=1;
    //         }
    //         if(z==o){
    //             maxi=max(maxi, j-i+1);
    //         }
    //     }
    // }
    // return maxi;
}

int main(){
    vector<int>nums={0,1,1,1,1,1,0,0,0};
    cout<<findMaxLength(nums)<<endl;
}
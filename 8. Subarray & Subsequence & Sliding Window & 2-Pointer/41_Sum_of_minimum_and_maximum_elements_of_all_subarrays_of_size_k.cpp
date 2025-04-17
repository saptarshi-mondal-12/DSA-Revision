#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Sum of minimum and maximum elements of all subarrays of size k.
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.


Input : arr[] = {2, 5, -1, 7, -3, -1, -2}  
        K = 4
Output : 18
Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4   
     
     Sum of all min & max = 6 + 4 + 4 + 4 = 18
*/

int brute_sumOfSubarray(vector<int>&nums, int k){
    // Time complexity - O(n*k)
    // space complecity - O(1)
    int n=nums.size();
    int result=0;
    for(int i=0;i<n-k+1;i++){
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int j=i;j<i+k;j++){
            maxi = max(maxi, nums[j]);
            mini = min(mini, nums[j]);
        }
        result+=(mini+maxi);
    }
    return result;
}

int optimal_sumOfSubarray(vector<int>&nums, int k){
    // Time complexity - O(nlogk)
    // space complexity - O(k)
    int n=nums.size();
    int result = 0; 

    // multiset because numbers can be repeated and also we required in sorted way so ordered multiset. 
    // multiset pair is {number,index} - index help us to remove current index from multiset
    multiset<pair<int, int> > ms;

    int i = 0, j = 0; 

    while (j < n && i < n) {
        // inserting {number,index} in multiset
        ms.insert({ nums[j], j });

        // checking if window size == k
        int windowSize = j - i + 1;

        if (windowSize == k) {

            // extracting first since set is always in sorted ascending order
            int mini = ms.begin()->first;

            // extracting last element 
            int maxi = ms.rbegin()->first;

            result += (maxi + mini);

            // erasing the ith index element from set as it won't appaer in next window of size k
            ms.erase({ nums[i], i });

            i++;
        }
        j++; 
    }
    return result;
}

int main(){
    vector<int>nums{2, 5, -1, 7, -3, -1, -2};
    int k=4;

    // brute
    cout<<brute_sumOfSubarray(nums,k)<<endl;

    // optimal
    cout<<optimal_sumOfSubarray(nums,k)<<endl;

}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Subarrays with K Different Integers
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.

For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.


Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].




Intuition:  Given nums=[1,2,3,3] k=3 

----------Solving f(nums, <=k) less than equal to k
[1]=1
[1,2]=2
[1,2,3]=3
[1,2,3,3]=3

[2]=1
[2,3]=2
[2,3,3]=2

[3]=1
[3,3]=1

[3]=1

So total 10 subarray are there where distinct element is <= 3  is [1,2,3,3,1,2,2,1,1,1]


----------Solving f(nums, <= k-1) less than equal to k-1 i.e k=3 , k-1=2 therefore k=2
[1]=1
[1,2]=2


[2]=1
[2,3]=2
[2,3,3]=2

[3]=1
[3,3]=1

[3]=1

So total 8 subarray are there where distinct element is <= 2  is [1,2,1,2,2,1,1,1]

Our answer = k - (k-1) => 10 - 8 = 2

[1,2,3]=3
[1,2,3,3]=3

total 2 subarray are there where k (K=3) distinct element is present other get cance out .
*/

int brute_countDistinctSubarray(int n, int arr[], int k){
    // Time complexity - O(n^2)
    // Space complexity - O(n)

    int result=0;
    for(int i=0;i<n;i++){
        set<int>st;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if (st.size()==k){
                result+=1;
            }else if(st.size() > k){
                break;
            }
        }
    }
    return result;
}

int compute(int n, int arr[], int k){
    int left=0, right=0;
    int count=0;
    unordered_map<int, int>mp;
    while(right < n){
        mp[arr[right]]++;
        
        while(mp.size() > k){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){
                mp.erase(arr[left]);
            }
            left++;
        }
        count=count+(right-left+1);
        right++;
    }
    return count;
}

int better_countDistinctSubarray(int n, int arr[], int k){
    // Time complexity - O(n+n) - 2 * O(2n)
    // Space complexity - O(n)

    /* cannot use sliding window - do dry run - we missed out some subarray - not sure about shrinking or expanding 
    change problem statement - (no of subarray where distinct integer are <= k)
    ans= (no of subarray where distinct integer are <= k) - (no of subarray where distinct integer are <= k-1)
    */

    int result=compute(n, arr, k) - compute(n, arr, k-1);
    return result;
}

int main(){
    int n=4;
    int arr[n]={1,2,3,3};
    int k=3;

    // brute
    cout<<brute_countDistinctSubarray(n, arr, k)<<endl;

    // better
    cout<<better_countDistinctSubarray(n, arr, k)<<endl;
}
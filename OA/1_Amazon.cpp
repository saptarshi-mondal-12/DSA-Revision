#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given a binary array and an integer k, find the position of zeroes flipping which creates maximum number of consecutive 1s in array.

Input: arr = [1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1], m = 2
Output: [5, 7]
Explanation: We are allowed to flip maximum 2 zeroes. If we flip arr[5] and arr[7], we get 8 consecutive 1's which is maximum possible under given constraints 


Input: arr = [1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1], m = 1
Output: [7]

Input: arr = [0, 0, 0, 1], m = 4
Output: [0, 1, 2]
*/

vector<int> longestOnes(vector<int>nums, int k){
    int n=nums.size();
    vector<int>result;
    int left=0;
    int right=0;
    int maxi=0;
    int count=0;

    while(right<n){
        if(nums[right]==0){
            result.push_back(right);
            count+=1;
        }

        while(count > k){
            if(nums[left]==0){
                count-=1;
                result.erase(result.begin());
            }
            left+=1;
        }

        if (right-left+1 >= maxi){
            maxi=right-left+1;
        }
        right+=1;
    }

    return result;

}

int main(){
    vector<int>nums={0,0,0,1};
    int k=4;

    vector<int> result=longestOnes(nums,k);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

}



// HINT : Find the longest subarray with at most K zeros. Keep the index of Zeroes in the longest subarray in a list
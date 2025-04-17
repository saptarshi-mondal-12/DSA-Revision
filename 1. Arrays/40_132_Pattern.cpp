#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 132 Pattern

Given an array of n integers nums, a 132 pattern is a subsequence of 
three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
Return true if there is a 132 pattern in nums, otherwise, return false.

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/

bool brute_Pattern(int n, int arr[]){
    // Time complexity - O(n^3)
    // space complexity - O(1)

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if (arr[i] < arr[k] && arr[k] < arr[j]){
                    return true;
                }
            }
        }
    }
    return false;
}

bool better_Pattern(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int mini=INT_MAX;
    for(int j=0;j<n;j++){
        mini=min(mini, arr[j]);
        for(int k=j+1;k<n;k++){
            if(mini < arr[k] && arr[k] < arr[j]){
                return true;
            }
        }
    }
    return false;
}

bool optimal_Pattern(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(n)

    int third=INT_MIN;
    stack<int>st;

    for(int i=n-1;i>=0;i--){
        if(arr[i] < third) return true;

        while(!st.empty() && arr[i]>st.top()){
            third=st.top();
            st.pop();
        }
        st.push(arr[i]);
    }
    return false;
}

int main(){
    int n=4;
    int arr[n]={1,2,3,4};
    

    // 1. Brute
    // cout<<brute_Pattern(n,arr)<<endl;

    // 2. better
    // cout<<better_Pattern(n,arr)<<endl;

    // 3. optimal
    cout<<optimal_Pattern(n,arr)<<endl;

}
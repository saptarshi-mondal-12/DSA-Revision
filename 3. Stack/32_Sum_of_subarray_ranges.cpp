#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Sum of Subarray Ranges

You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.


Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.


Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.

Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
*/

vector<int>prev_greater_element(vector<int>& arr){
    // Time complexity - O(2n)
    // space complexity -  O(n) + O(n) = O(2n)
    int n=arr.size();
    vector<int>pge(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i] > arr[st.top()] ){
            st.pop();
        }
        if(st.empty()){
            pge[i]=-1;
        }else{
            pge[i]=st.top();
        }
        st.push(i);
    }
    return pge;
}
vector<int>next_greater_element(vector<int>& arr){
    // Time complexity - O(2n)
    // space complexity -  O(n) + O(n) = O(2n)
    int n=arr.size();
    vector<int>nge(n,0);
    stack<int>st;
    for(int i=n-1;i>=0;i--){

        // pop till arr[i] <= arr[st.top()]because we want next smaller
        while (!st.empty() && arr[i] >= arr[st.top()]){
            st.pop();
        }

        // if stack become empty assign to n because whole element can be considered after current index 
        if(st.empty()){
            nge[i]=n;
        }else{
            nge[i]=st.top();
        }

        // Push index not array element because we need index
        st.push(i);
    }
    return nge;
}
    
long long sumSubarrayMaxs(vector<int>& arr) {
    // Time complexity - O(2n) + O(2n) + O(n) = O(5n)
    // space complexity - O(2n + 2n + n) = O(5n) = O(n)
    
    int n=arr.size();
    long long result=0;
    int mod=(1e9)+7;
    
    vector<int>prevGreaterElement = prev_greater_element(arr);
    vector<int>nextGreaterElement = next_greater_element(arr);

    for(int i=0;i<n;i++){
        int left = i - prevGreaterElement[i];
        int right = nextGreaterElement[i] - i;

        result = (result + (left * right * 1LL * arr[i])) ;
    }
    return result;
}

vector<int>prev_smaller_element(vector<int>& arr){
    // Time complexity - O(2n)
    // space complexity -  O(n) + O(n) = O(2n)
    int n=arr.size();
    vector<int>pse(n,0);
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i] < arr[st.top()] ){
            st.pop();
        }
        if(st.empty()){
            pse[i]=-1;
        }else{
            pse[i]=st.top();
        }
        st.push(i);
    }
    return pse;
}
vector<int>next_smaller_element(vector<int>& arr){
    // Time complexity - O(2n)
    // space complexity -  O(n) + O(n) = O(2n)
    // 1 4 6 7 3 7 8 1
    int n=arr.size();
    vector<int>nse(n,0);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        // pop till arr[i] <= arr[st.top()]because we want next smaller
        while (!st.empty() && arr[i] <= arr[st.top()]){
            st.pop();
        }
        // if stack become empty assign to n because whole element can be considered after current index 
        if(st.empty()){
            nse[i]=n;
        }else{
            nse[i]=st.top();
        }
    
        // Push index not array element because we need index
        st.push(i);
    }
    return nse;
}
    
long long sumSubarrayMins(vector<int>& arr) {
    // Time complexity - O(2n) + O(2n) + O(n) = O(5n)
    // space complexity - O(2n + 2n + n) = O(5n) = O(n)
    
    int n=arr.size();
    long long result=0;
    int mod=(1e9)+7;
            
    vector<int>prevSmallerElement = prev_smaller_element(arr);
    vector<int>nextSmallerElement = next_smaller_element(arr);
    
    for(int i=0;i<n;i++){
        int left = i - prevSmallerElement[i];
        int right = nextSmallerElement[i] - i;
        result = (result + (left * right * 1LL * arr[i])) ;
    }
    return result;
}


long long subArrayRanges(vector<int>& nums) {
    // (sum of all maximum) - (sum of all minimum)
    long long result = sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    return result;
}

long long brute_subArrayRanges(vector<int>& nums) {
    // Time complexity - O(n^2)
    // space complexity - O(1)
    int n=nums.size();
    long long result=0;
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int j=i;j<n;j++){
            mini=min(mini, nums[j]);
            maxi=max(maxi, nums[j]);
            result+=maxi-mini;
        }
    }
    return result; 
}


int main(){
    vector<int>arr={4,-2,-3,4,1};

    // brute
    // cout<<brute_subArrayRanges(arr)<<endl;

    // optimal
    cout<<subArrayRanges(arr)<<endl;

}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Q. Sum of Subarray Maximum

Given an array arr[], the task is to find the sum of the maximum elements of every possible non-empty sub-arrays of the given array arr[].

Input: arr[] = [1, 3, 2]
Output: 15
Explanation: All possible non-empty subarrays of [1, 3, 2] are {1}, {3}, {2}, {1, 3}, {3, 2} and {1, 3, 2}. The maximum elements of the subarrays are 1, 3, 2, 3, 3, 3 respectively. The sum will be 15.


Input: arr[] = [3, 1]
Output: 7
Explanation: All possible non-empty subarrays of [3, 1] are {3}, {1} and {3, 1}. The maximum elements of the subarrays are 3, 1, 3 respectively. The sum will be 7.


Input: arr[] = [8, 0, 1]
Output: 26
Explanation: All possible non-empty subarrays of [8, 0, 1] are {8}, {0}, {1}, {8, 0}, {0, 1} and {8, 0, 1}. The maximum elements of the subarrays are 8, 0, 1, 8, 1, 8 respectively. The sum will be 26.
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
    
int sumSubarrayMaxs(vector<int>& arr) {
    // Time complexity - O(2n) + O(2n) + O(n) = O(5n)
    // space complexity - O(2n + 2n + n) = O(5n) = O(n)
    
    int n=arr.size();
    int result=0;
    int mod=(1e9)+7;
    
    vector<int>prevGreaterElement = prev_greater_element(arr);
    vector<int>nextGreaterElement = next_greater_element(arr);

    for(int i=0;i<n;i++){
        int left = i - prevGreaterElement[i];
        int right = nextGreaterElement[i] - i;
        

        result = (result + (left * right * arr[i]));
    }
    return result;
}
    

int main(){
    vector<int>arr={8, 0, 1};

    // brute
    // cout<<brute_sumSubarrayMins(arr);

    // optimal
    cout<<sumSubarrayMaxs(arr);
}
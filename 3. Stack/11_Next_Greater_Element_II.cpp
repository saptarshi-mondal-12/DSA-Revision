#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/* Next Greater element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

*/


void nextGreaterII(int nums[], int n){
    // time complexity = O(n)  
    // space complexity = O(n)

    int n = nums.size();
    vector<int>result(n, -1);
    stack<int>st;
    // push all element in stack in reverse order (right to left)
    for(int i=n-1;i>=0;i--){
        st.push(nums[i]);
    }
    // find next greater element 
    for(int i=n-1;i>=0;i--){
        int curr = nums[i];
        while(!st.empty() && st.top() <= curr ){
            st.pop();
        }
        if(!st.empty()){
            result[i] = st.top();
        }
        st.push(curr);
    }
    
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    
}

int main(){
    int n=5;
    int arr[n]={1,2,3,4,3}; 
    nextGreaterII(arr,n);
}

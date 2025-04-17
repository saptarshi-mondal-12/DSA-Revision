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


void nextGreaterII(int arr[], int n){
    // time complexity = 
    // space complexity = 

    stack<int>s;
    vector<int>result(n,-1);

    for(int i=2*n-1; i>=0;i--){
        int curr=arr[i%n];

        while(!s.empty() && s.top()<=curr){
            s.pop();
        }
        
        if(!s.empty() && i<n){
            result[i]=s.top();
        }
        s.push(curr);
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

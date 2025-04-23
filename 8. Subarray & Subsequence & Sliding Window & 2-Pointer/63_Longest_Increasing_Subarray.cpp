#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Increasing Subarray

Given an array arr[] of integers. The problem is finding the longest contiguous subarray's length such that every element is strictly greater than its previous element in the same subarray.

Input: arr[] = [5, 6, 3, 5, 7, 8, 9, 1, 2]
Output: 5
Explanation: here the subarray arr[2:6] = [3, 5, 7, 8, 9] is longest subarray to follow strictly increasing order.

Input: arr[] = [12, 13, 1, 5, 4, 7, 8, 10, 10, 11]
Output: 4
Explanation: here the subarray arr[4:7] = [4, 7, 8, 10] is longest subarray to follow strictly increasing 
*/

int lenOfLongIncSubArr(vector<int> &nums) {
    // Time complexity: O(N)
    // Space complexity: O(1)
    
    int n=nums.size();
    int result = 1;
    int currLen = 1;

    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            currLen++;
            result = max(result, currLen);
        } else {
            currLen = 1;
        }
    }
    return result;
    
    
    // Brute soln ---------------------------------------
    // Time complexity: O(N^2)
    // Space complexity: O(1)
    // int n=nums.size();
    // int result=1;
    // for(int i=0;i<n;i++){
    //     int prev=nums[i];
    //     for(int j=i+1;j<n;j++){
    //         if(prev < nums[j]){
    //             result = max(result, j-i+1);
    //             prev=nums[j];
    //         }else{
    //             break;
    //         }
    //     }
    // }
    // return result;
}
int main(){
    vector<int>nums={12, 13, 1, 5, 4, 7, 8, 10, 10, 11};
    cout<<lenOfLongIncSubArr(nums)<<endl;
}

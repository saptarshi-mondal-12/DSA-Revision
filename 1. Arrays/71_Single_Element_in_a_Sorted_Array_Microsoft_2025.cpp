#include <bits/stdc++.h>
using namespace std;

/* Q. Single Element in a Sorted Array - Microsoft 2025

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Input: nums = [3,3,7,7,10,11,11]
Output: 10

*/

int singleNonDuplicate(vector<int> &nums){
    // Optimal Soln---------------------------------------------
    // Time comlexity: O(n)
    // Space complexity: O(1)
    int n = nums.size();
    int result=-1;
    if(n==1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    for(int i=1;i<n-1;i++){
        if(nums[i-1] < nums[i] && nums[i] < nums[i+1]){
            result = nums[i];
            break;
        }
    }
    return result;




    // Better Soln------------------------------------------
    // Time comlexity: O(n) + O(n)
    // Space complexity: O(n) in worst case
    // int n = nums.size();
    // unordered_map<int,int>freq;
    // for(int i=0;i<n;i++){
    //     freq[nums[i]]++;
    // }
    // int result=-1;
    // for(auto it : freq){
    //     int num = it.first;
    //     int frequency = it.second;
    //     if(frequency == 1){
    //         result=num;
    //     }
    // }
    // return result;

    
    
    
    
    // Brute Soln-----------------------------------------
    // Time comlexity: O(n^2)
    // Space complexity: O(1)
    // int n = nums.size();
    // int result=-1;
    // for(int i=0;i<n;i++){
    //     int count=0;
    //     for(int j=0;j<n;j++){
    //         if(nums[i] == nums[j]){
    //             count++;
    //         }
    //     }
    //     if(count == 1){
    //         result = nums[i];
    //         return result;
    //     }
    // }
    // return -1;
}


int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout<<singleNonDuplicate(nums);
}
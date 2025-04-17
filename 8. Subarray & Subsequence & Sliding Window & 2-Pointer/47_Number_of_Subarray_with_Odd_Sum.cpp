#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Number of Sub-arrays With Odd Sum

Given an array of integers arr, return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 109 + 7.

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 
*/

int brute_countOddSum(vector<int>& nums){
    // Time cmlexity - O(n^2)
    // Space complexity - O(1)
    int n=nums.size();
    int result=0;
    for(int i=0;i<n;i++){
        int currSum=0;
        for(int j=i;j<n;j++){
            currSum+=nums[j];
            if(currSum%2!=0){
                result+=1;
            }
        }
    }
    return result;
}

int countOddSum(vector<int>& nums) {
    // Time complexity - O(n)
    // Space complexity - O(1)
    int n=nums.size();
    int result=0;
    long long mod=(1e9+7);

    int oddCount=0, evenCount=0;
    int prefixSum=0;

    for(int i=0;i<n;i++){
        prefixSum+=nums[i];
    
        // If two prefix sums have different parity (one is even, the other is odd), their difference will be odd, meaning the subarray sum is odd.
        // If prefixSum is even, it means the subarray sum from the start to the current index is even. To form an odd subarray, we need to subtract a previously seen odd prefix sum. So, we add the count of previously seen odd prefix sums to our answer.
        if(prefixSum % 2 == 0){
            // no of oddCount [.o...o..e] (entire length is not considered because entire array sum is even)
            result = (result + oddCount) % mod;
            evenCount+=1;
        }

        // If prefixSum is odd, the subarray sum from the start to the current index is odd. To form another odd subarray, we need to subtract a previously seen even prefix sum. So, we add the count of previously seen even prefix sums to our answer.
        else{
            // [.e...e..o] 
            // 1. [.e...e..o] +1 for entire array  
            // 2. [e...e..o] 
            // 3. [e..o]
            result = (result + 1 + evenCount) % mod;
            oddCount+=1;
        }
        
    }
    return result;
}

int main(){
    vector<int>nums={1,2,3,4,5,6,7};
    cout<<countOddSum(nums)<<endl;
}
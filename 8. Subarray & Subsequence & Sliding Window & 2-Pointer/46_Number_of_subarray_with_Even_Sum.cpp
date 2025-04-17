#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Number of Sub-arrays With Even Sum
Given an array arr. Find the number of subarrays whose sum is an even number.

Input: arr[] = [1, 2, 2, 3, 4, 1]
Output: 9
Explanation: There are 9 such possible subarrays. These are [1, 2, 2, 3] Sum = 8, [1, 2, 2, 3, 4] Sum = 12, [2] Sum = 2, [2, 2] Sum = 4, [2, 2, 3, 4, 1] Sum = 12, [2] Sum = 2, [2, 3, 4, 1] Sum = 10, [3, 4, 1] Sum = 8 and [4] Sum = 4


Input: arr[] = [1, 3, 1, 1]
Output: 4
Explanation: The array has 4 such possible subarrays. [1, 3] Sum = 4, [1, 3, 1, 1] Sum = 6, [3, 1] Sum = 4 and [1, 1] Sum = 2
*/

long long brute_countEvenSum(vector<int>& nums){
    // Time cmlexity - O(n^2)
    // Soace complexity - O(1)
    int n=nums.size();
    int result=0;
    for(int i=0;i<n;i++){
        int currSum=0;
        for(int j=i;j<n;j++){
            currSum+=nums[j];
            if(currSum%2==0){
                result+=1;
            }
        }
    }
    return result;
}

long long countEvenSum(vector<int>& nums) {
    // Time Complexity: O(n)
    // Space Complexity: 𝑂(1)

    int n=nums.size();
    long long result=0;

    int oddCount=0, evenCount=0;
    int prefixSum=0;

    for(int i=0;i<n;i++){
        prefixSum+=nums[i];
        // If two prefix sums have the same parity (both even or both odd), their difference will be even, meaning the subarray sum is even.
        // If prefixSum is even, it means the subarray sum from the start to the current index is even. It forms a valid subarray with all previous occurrences of even prefix sums.
        if (prefixSum % 2 == 0){
            // [o,e,o,o,e] because even-even=even
            // 1. [e,o,o] 1 even before last index
            // 2. [o,e,o,o,e] and +1 for considering whole array till index i
            // therefore we find 3 subs of even sum till index i
            result = result + 1 + evenCount;
            evenCount+=1;
        }
        // If prefixSum is odd, it means the subarray sum from the start to the current index is odd. It forms a valid subarray with all previous occurrences of odd prefix sums.
        else{
            // [o,e,o,o,e,o] because odd-odd=even
            result = result + oddCount;
            oddCount+=1;
        }
    }
    return result;
}

int main(){
    vector<int>nums={1, 2, 2, 3, 4, 1};
    cout<<countEvenSum(nums)<<endl;
}
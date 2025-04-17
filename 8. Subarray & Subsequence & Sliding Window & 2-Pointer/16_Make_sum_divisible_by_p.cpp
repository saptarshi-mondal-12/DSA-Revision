#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Make Sum Divisible by P

Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
A subarray is defined as a contiguous block of elements in the array.


Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

Input: nums = [6,3,5,2], p = 9
Output: 2

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
*/


int minSubarray(vector<int>nums, int p)
{
    // Time complexity - O()
    // space complexity - O()
    int n=nums.size();
    long long totalSum = 0;
    for(int i=0;i<n;i++){
        totalSum+=nums[i];
    }
    totalSum=totalSum%p;
    if (totalSum == 0) {
        return 0;
    }

    long long prefixSum = 0;
    int result = n;
    unordered_map<long long, int> d;
    d[0] = -1;

    for (int i = 0; i < n; ++i) {
        prefixSum = (prefixSum + nums[i]);
        long long mod = prefixSum%p;
        long long target = (mod - totalSum + p) % p;
        d[mod] = i;
        if (d.find(target) != d.end()) {
            result = min(result, i - d[target]);
        }
    }

    if (result == n) {
        return -1;
    }
    return result;

	
}

int main(){
    int p=9;
    vector<int>v={6,3,5,2};

    cout<<minSubarray(v,p)<<endl;

}

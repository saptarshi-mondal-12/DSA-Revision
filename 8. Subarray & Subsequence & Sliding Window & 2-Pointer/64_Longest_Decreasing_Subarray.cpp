#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest Decreasing Subarray
*/

int longestDecreasingSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int result = 1;
    int left = 0;

    for (int right = 1; right < n; right++) {
        if (nums[right] >= nums[right - 1]) {
            left = right;
        }
        result = max(result, right - left + 1);
    }
    return result;
}

int main(){
    vector<int>nums={12, 11, 10, 15, 4, 3, 2, 10, 10, 11};
    cout<<longestDecreasingSubarray(nums)<<endl;
}

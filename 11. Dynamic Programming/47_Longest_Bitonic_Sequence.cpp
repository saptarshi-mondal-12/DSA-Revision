#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Longest Bitonic sequence

A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing. For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.
You are given an array 'arr' consisting of 'n' positive integers.Find the length of the longest bitonic subsequence of 'arr'.

NOTE: A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.

Input: 'arr' = [1, 2, 1, 2, 1]
Output: 3
Explanation: The longest bitonic subsequence for this array will be [1, 2, 1]. Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive 2's are neither strictly increasing, nor strictly decreasing.


Intuition: 
A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:

First, increase till a point and then decrease.
    Goes on increasing (Longest increasing subsequence)
    Goes on decreasing (Longest decreasing subsequence)

The length of the increasing and then decreasing subsequence gives us the hint to think in terms of the longest increasing subsequence (LIS). Now, what does this dp[i] represent? It represents the LIS in the array ‘arr’ from index 0 to index i in the array ending with element arr[i]. Therefore the maximum value of dp[i] gives us the LIS of the array.

       /\
      /  \
     /    \
    /      \

SEE FROM LEFT -> strictly increasing
SEE FROM right -> strictly increasing

As we can see in the second part of the bitonic subsequence, the decreasing part, LDS from index i to index n-1 can also be thought of in terms of LIS from index n-1 to index i. Therefore we can compute this two LIS separately to determine the length of the bitonic subsequence:

Now with these two separate lengths of LIS, we can calculate the length of the longest bitonic subsequence for each index i. Here index i is acting as the pivot point of the points. Therefore the length of the longest bitonic subsequence at pivot [ i ] will be dp1[i] + dp2[i] -1. (Note that we are counting the element at index i twice in both the parts so we need to subtract 1 from the final answer). We will return the maximum value of this addition as the final answer as the length of the longest bitonic subsequence.

NOTE: If only increasing or only decreasing is not consider their is a minor change  
if(dp1[i]>1 && dp2[i]>1){
    maxi = max(maxi, dp1[i] + dp2[i] - 1);
}
*/

int longestBitonicSubsequence(vector<int> &nums, int n){
    // Time complexity: O(n^2) + O(n^2) + O(N)
    // space complexity: O(n)


    // From left side LIS
    vector<int> dp1(n, 1);
    for (int i = 0; i < n; i++){
        for (int prev = 0; prev <= i - 1; prev++){
            if (nums[prev] < nums[i] && 1 + dp1[prev] > dp1[i]){
                dp1[i] = 1 + dp1[i];
            }
        }
    }

    // From right side LIS
    vector<int> dp2(n, 1);
    for (int i = n - 1; i >= 0; i--){
        for (int prev = n - 1; prev >= i + 1; prev--){
            if (nums[prev] < nums[i] && 1 + dp2[prev] > dp2[i]){
                dp2[i] = 1 + dp2[i];
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++){
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
}

int main(){
    int n=6;
    vector<int>nums = {1, 4, 2, 7, 9, 10};
    cout<<longestBitonicSubsequence(nums, n)<<endl;
}

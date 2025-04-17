#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count Subarrays With Score Less Than K

The score of an array is defined as the product of its sum and its length.
For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.

Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.


Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
*/

void brute_countSubarrays(vector<int>v, int k){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int n=v.size();
    int count=0;

    for(int i=0;i<n;i++){
        int total_sum=0;
        for (int j=i;j<n;j++){
            total_sum+=v[j];
            int length=(j-i+1);

            if(total_sum*length < k){
                count+=1;
            }
        }
    }
    cout<<count<<endl;
}

void optimal_countSubarrays(vector<int>v, int k){
    // Time complexity - 
    // space complexity - O(1)

    int n=v.size();
    int count=0;

    int left=0;
    int right=0;

    int total_sum=0;

    while(right<n){
        total_sum+=v[right];

        while (total_sum*(right-left+1) >= k){
            total_sum-=v[left];
            left++;
        }
        count+=(right-left+1);
        right++;
    }
    cout<<count<<endl;
}

int main(){
    vector<int>v={2,1,4,3,5};
    int k=10;

    // 1. brute
    brute_countSubarrays(v,k);

    // 2. optimal
    optimal_countSubarrays(v,k);




}

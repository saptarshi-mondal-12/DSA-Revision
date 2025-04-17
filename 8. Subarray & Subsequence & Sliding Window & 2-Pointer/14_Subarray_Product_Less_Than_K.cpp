#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Subarray Product Less Than K

Given an array of integers nums and an integer k, return the number of contiguous subarrays where 
the product of all the elements in the subarray is strictly less than k.

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.


Input: nums = [1,2,3], k = 0
Output: 0
*/

void brute_numSubarrayProductLessThanK(vector<int>v, int k){
    // Time complexity - O(n^2)
    // spac e complexity - O(1)

    if (k<=1) return ;

    int n=v.size();
    int count=0;

    for(int i=0;i<n;i++){
        int product=1;
        for(int j=i;j<n;j++){
            product*=v[j];

            if(product < k){
                count++;
            }
        }
    }
    cout<<count<<endl;
}

void optimal_numSubarrayProductLessThanK(vector<int>v, int k){
    // Time complexity - O(n)
    // spac e complexity - O(1)

    if (k<=1) return ;

    int n=v.size();
    int count=0;

    int left=0;
    int right=0;

    int product=1;

    while(right<n){
        product*=v[right];

        while (product >= k){
            product=product/v[left];
            left+=1;
        }
        count+=(right-left+1);
        right++;
    }
    cout<<count<<endl;
}



int main(){
    vector<int>v={10,5,2,6};
    int k=100;

    // brute
    brute_numSubarrayProductLessThanK(v,k);

    // optimal
    optimal_numSubarrayProductLessThanK(v,k);
}


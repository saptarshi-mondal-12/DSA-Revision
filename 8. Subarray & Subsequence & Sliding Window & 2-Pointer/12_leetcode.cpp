#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Length of Longest Subarray With at Most K Frequency

You are given an integer array nums and an integer k. The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.


Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. 
Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good. It can be shown that there are no good subarrays with length more than 6.


Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray.
Note that the subarray [2,1] is also good. It can be shown that there are no good subarrays with length more than 2.

Input: nums = [5,5,5,5,5,5,5], k = 4
Output: 4
Explanation: The longest possible good subarray is [5,5,5,5] since the value 5 occurs 4 times in this subarray.
It can be shown that there are no good subarrays with length more than 4.
*/

void brute_maxSubarrayLength(int n, int arr[], int k){
    // Time complexity = O(n^3)
    // space complexity - O(n)
    int mxLen=1;

    for(int i=0;i<n;i++){
        map<int,int>mp;
        for(int j=i;j<n;j++){
            mp[arr[j]]++;

            int flag=0;
            for(int it=0;it<mp.size();it++){
                if (mp[it] > k){
                    flag=1;
                    break;
                }
            }
            if (flag==0){
                mxLen=max(mxLen, j-i+1);

            }
        }
    }
    cout<<mxLen<<endl;
}

void optimal_maxSubarrayLength(int n, int arr[], int k){
    int mxLen=1;
    map<int,int>mp;
    int i=0;

    for(int j=0;j<n;j++){
        mp[arr[j]]++;

        if (mp[arr[j]] > k){

            while (i<j && mp[arr[j]]>k){
                if (mp[arr[i]]>=1){
                    mp[arr[i]]-=1;
                }
                i++;
            }
            
        }
        mxLen=max(mxLen,j-i+1);
    }
    cout<<mxLen;

}

int main(){
    int n=8;
    int arr[n]={1,2,3,1,2,3,1,2};
    int k=2;


    //brute
    brute_maxSubarrayLength(n,arr,k);

    // optimal
    optimal_maxSubarrayLength(n,arr,k);

}

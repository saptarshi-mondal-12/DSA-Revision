#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Split Array – Largest Sum

Given an integer array ‘A’ of size ‘N’ and an integer ‘K’. Split the array ‘A’ into ‘K’ non-empty subarrays such that 
the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.
A subarray is a contiguous part of the array.

Input : N = 5, a[] = {1,2,3,4,5}, k = 3
Result: 6
Explanation: There are many ways to split the array a[] into k consecutive subarrays. 
The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.


Input : N = 3, a[] = {3,5,1}, k = 3
Result: 5
Explanation: There is only one way to split the array a[] into 3 subarrays, i.e., [3], [5], and [1]. The largest sum among these subarrays is 5.


Maximum subarray sum is minimum Answer - min(max)
[10] [20,30,40] - 10, 90 -> Maximum subarray sum  = 90
[10,20] [30,40] - 30, 70 - 70
[10,20,30] [40] - 60, 40 - 60

ans - 60 is minimum 

Observations:

Minimum possible answer: 
We will get the minimum answer when we split the array into n subarrays(i.e. Each subarray will have a single element). 
Now, in this case, the maximum subarray sum will be the maximum element in the array. So, the minimum possible answer is max(arr[]).

Maximum possible answer: 
We will get the maximum answer when we put all n elements into a single subarray. 
The maximum subarray sum will be the summation of array elements i.e. sum(arr[]). So, the maximum possible answer is sum(arr[]).

From the observations, it is clear that our answer lies in the range [max(arr[]), sum(arr[])].
*/

int countPartition(int n, vector<int>arr, int maxSum){
    int partition=1;
    int subarraySum=0;

    for(int i=0;i<n;i++){
        if(subarraySum+arr[i] <= maxSum){
            subarraySum+=arr[i];
        }else{
            partition++;
            subarraySum=arr[i];
        }
    }
    return partition;
}

int splitArrayLargestSum(int n, vector<int>arr, int k){
    int mini=*min_element(arr.begin(),arr.end());
    int maxi=accumulate(arr.begin(),arr.end(),0);

    for(int low=mini; low<=maxi; low++){
        if(countPartition(n,arr,low)==k){
            return low;
        }
    }
    // because this the minimum possible answer
    return mini;
}

int optimal_splitArrayLargestSum(int n, vector<int>arr, int k){
    int low=*min_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    int ans;
    while(low<=high){
        int mid=(low+high)/2;

        if(countPartition(n,arr,mid)<=k){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n=4;
    vector<int>arr={10,20,30,40};
    int k=2;

    // 1. brute 
    cout<<splitArrayLargestSum(n,arr,k)<<endl;

    // 2. optimal 
    cout<<optimal_splitArrayLargestSum(n,arr,k)<<endl;

}


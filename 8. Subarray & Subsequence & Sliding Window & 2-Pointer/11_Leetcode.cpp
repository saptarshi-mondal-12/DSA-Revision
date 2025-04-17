#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
/* Count Subarrays Where Max Element Appears at Least K Times

You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
A subarray is a contiguous sequence of elements within an array.

 Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
*/

void brute_countSubarrays(int n, int arr[], int k){
    int count=0;
    int maxi=*max_element(arr,arr+n);

    for(int i=0;i<n;i++){
        int max_count=0;
        for(int j=i;j<n;j++){
            if (arr[j]==maxi){
                max_count+=1;
            }

            if (max_count>=k){
                count++;
            }
        }
    }
    cout<<count<<endl;
}


void optimal_countSubarrays(int n, int arr[], int k){
    int result=0;
    int maxi=*max_element(arr,arr+n);
    
    int low=0;
    int maxi_count=0;

    for(int high=0;high<n;high++){
        if(arr[high]==maxi){
            maxi_count++;
        }

        while(maxi_count >= k){
            result+=n-high;
            
            if (arr[low]==maxi){
                maxi_count-=1;
            }
            low++;
        }
    }
    cout<<result;
}


int main(){
    int n=5;
    int arr[n]={1,3,2,3,3};
    int k=2;

    // int n=4;
    // int arr[n]={1,4,2,1};
    // int k=3;

    //brute
    brute_countSubarrays(n,arr,k);

    // optimal
    optimal_countSubarrays(n,arr,k);

}

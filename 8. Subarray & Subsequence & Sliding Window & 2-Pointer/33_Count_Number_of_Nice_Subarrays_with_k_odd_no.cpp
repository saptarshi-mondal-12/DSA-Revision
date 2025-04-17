#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count Number of Nice Subarrays

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
*/

int brute_numberOfSubarrays(int n, int nums[], int k){
    // Time complexity - 
    // space complexity - O(1)

    int result=0;
    for(int i=0;i<n;i++){
        int oddCount=0;
        for(int j=i;j<n;j++){
            if(nums[j]%2!=0){
                oddCount++;
            }
            if(oddCount==k){
                result+=1;
            }
        }
    }
    return result; 
}

int better_numberOfSubarrays(int n, int nums[], int k){
    // Time complexity - 
    // space complexity - O(1)

    int result=0;
    int i=0;
    int j=0;
    int oddCount=0;
    int count=0;
    while(j<n){
        int curr=nums[j];
        if(curr%2!=0){
            oddCount+=1;
            count=0;
        }
        while(oddCount==k){
            count+=1;
            if(nums[i]%2!=0){
                oddCount-=1;
            }
            i+=1;
        }
        j++;
        result+=count;
    }
    return result;
}

int main(){
    int n=5;
    int arr[n]={1,1,2,1,1};
    int k=3;

    // brute
    cout<<brute_numberOfSubarrays(n,arr,k)<<endl;

    // better
    cout<<better_numberOfSubarrays(n,arr,k);
}


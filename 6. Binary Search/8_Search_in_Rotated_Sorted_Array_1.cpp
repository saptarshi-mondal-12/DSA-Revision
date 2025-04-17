#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Search in Rotated Sorted Array 1

Given an integer array arr of size N, sorted in ascending order (with distinct values) 
and a target value k. Now the array is rotated at some pivot point unknown to you. 
Find the index at which k is present and if k is not present return -1.

Input Format: arr = [4,5,6,7,0,1,2,3], k = 0
Result: 4
Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. 
Thus, we get output as 4, which is the index at which 0 is present in the array.


Input Format: arr = [4,5,6,7,0,1,2], k = 3
Result: -1
Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
*/

int brute_search(int n , int arr[], int x){
    // Time complexity - O(n)
    //  space complexity - O(1)

    int ans=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            ans=i;
            break;
        }
    }
    return ans;
}

int optimal_search(int n , int arr[], int x){
    // Time complexity - O(log n)
    //  space complexity - O(1)

    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        
        // if mid points the target
        if(arr[mid]==x) return mid;

        // if left part is sorted
        if(arr[low] <= arr[mid]){
            if(arr[low] <= x && x <= arr[mid]){
                // we eliminate right half
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        else{ // if right part is sorted
            if(arr[mid] <= x && x <= arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int n=8;
    int arr[n]={4,5,6,7,0,1,2,3};
    int x=3;

    // brute - linear search
    cout<<brute_search(n,arr,x)<<endl;

    // optimal 
    cout<<optimal_search(n,arr,x)<<endl;
}
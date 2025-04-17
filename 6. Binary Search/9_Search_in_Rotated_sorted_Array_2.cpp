#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Search in Rotated Sorted Array 2

Given an integer array arr of size N, sorted in ascending order (may contains distinct) 
and a target value k. Now the array is rotated at some pivot point unknown to you. 
Return True if k is present and otherwise, return False. 

Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result: True
Explanation: The element 3 is present in the array. So, the answer is True

Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result: false

*/

bool brute_search(int n , int arr[], int x){
    // Time complexity - O(n)
    //  space complexity - O(1)

    int ans=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            ans=i;
            break;
        }
    }
    if(ans==-1) return false;
    return true;
}

bool optimal_search(int n , int arr[], int x){
    // Time complexity - O(log n)
    //  space complexity - O(1)

    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        
        // if mid points the target
        if(arr[mid]==x) return true;

        // Edge case
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low=low+1;
            high=high-1;
            continue;
        }

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
    return false;
}

int main(){
    int n=10;
    int arr[n]={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int x=1;


    // 1. brute - linear search
    int ans=brute_search(n,arr,x);
    if (!ans)
        cout << "False\n";
    else
        cout << "True\n";

    
    /* Edge case - [3,1,2,3,3,3,3] where low=0, high=6 and mid =3
    and as per above optimal solution if arr[0] <= arr[mid] i.e 3 <= 3
    means left half [3,1,2] is sorted which is not , so it fails

    arr[low] == arr[mid] == arr[mid] -> problem
    trim down search space - 

    if(arr[low]==arr[mid] && arr[mid]==arr[high]){
        low++;
        high--;
        continue;
    }
    */

    // 2. optimal 
    int a=optimal_search(n,arr,x);
    if (!a)
        cout << "False\n";
    else
        cout << "True\n";
}
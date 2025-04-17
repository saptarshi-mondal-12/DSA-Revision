#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void brute_NextPermutation(int n, int arr[]){
    // Time complexity - O(n! * n)
    // space complexity - O(1)

    /*1. Find all possible permutations of elements present and store them.
      2. Search input from all possible permutations.
      3. Print the next permutation present right after it.
    */

}

void better_NextPermutation(int n, int arr[]){

    /* Using STL function*/
    next_permutation(arr,arr+n);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void optimal_NextPermutation(int n, int nums[]){
    // Time complexity - O(3n)
    // space complexity - O(1)

    // Step 1: Find the break point:
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if (nums[i]<nums[i+1]){
            index=i;
            break;
        }
    }
    // If break point does not exist:
    if (index==-1){
        // reverse the whole array:
        reverse(nums,nums+n);
    }

    // Step 2: Find the next greater element and swap it with arr[ind]:
    else{
        // finding minimum index
        for(int i=n-1;i>index;i--){
            if (nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        // Step 3: reverse the right half:
        reverse(nums+index+1,nums+n);
    }

    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    cout<<endl;
}

int main(){
    int n=7;
    int arr[n]={2,1,5,4,3,0,0};

    // Brute Force 
    // brute_NextPermutation(n,arr);

    // Better
    // better_NextPermutation(n,arr);

    // Optimal 
    optimal_NextPermutation(n,arr);

}
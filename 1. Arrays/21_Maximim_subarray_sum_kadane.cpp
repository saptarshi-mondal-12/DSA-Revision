#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Kadane’s Algorithm : Maximum Subarray Sum in an Array
Given an integer array nums, find the subarray with the largest sum, and return its sum.

 Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

int brute_maximumSubarray(int n, int arr[]){
    // Time complexity - O(n^3)
    // space complexity - O(1)

    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            mx=max(mx,sum);
        }
    }
    return mx;
}

int better_maximumSubarray(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int mx=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            mx=max(mx,sum);
        }
    }
    return mx;
}

int optimal_maximumSubarray(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    /*The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. 
    A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.
    Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. 
    Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray 
    with a negative sum. Among all the sums calculated, we will consider the maximum one. Thus we can solve this problem with a single loop.*/

    int currSum=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        currSum+=arr[i];

        if(currSum>mx){
            mx=currSum;
        }

        if (currSum<0){
            currSum=0;
        }
    }
    return mx;
}




int follow_up(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    int currSum=0;
    int mx=INT_MIN;

    int start=0;
    int startIndex=-1;
    int endIndex=-1;

    for(int i=0;i<n;i++){
        if (currSum==0){
            start=i;
        }

        currSum+=arr[i];

        if(currSum>mx){
            mx=currSum;

            startIndex=start;
            endIndex=i;

        }

        if (currSum<0){
            currSum=0;
        }
    }
    
    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = startIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << "]"<<endl;

    return mx;
}



int main(){
    int n=9;
    int arr[n]={-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // 1. brute - try for all subarray, 3 loop
    // cout<<brute_maximumSubarray(n,arr)<<endl;

    // 2. better - try for all subarray, 2 loop
    // cout<<better_maximumSubarray(n,arr)<<endl;

    // 3. optimal - kadane algo
    cout<<optimal_maximumSubarray(n,arr)<<endl;

    // follow up question - // print maximum subarray sum and print its subarray
    // cout<<follow_up(n,arr);



}


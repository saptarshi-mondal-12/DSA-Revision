#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Maximum Product Subarray in an Array 

Given an array that contains both negative and positive integers, find the maximum product subarray.

Input: Nums = [1,2,3,4,5,0]
Output:120
Explanation:In the given array, we can see 1×2×3×4×5 gives maximum product value.

Input: Nums = [1,2,-3,0,-4,-5]
Output:20
Explanation: In the given array, we can see (-4)×(-5) gives maximum product value.

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

void brute_maxProduct(int n, int arr[]){
    // Time complexity - O(n^3)
    // space complexity - O(1)

    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int product=1;
            for(int k=i;k<=j;k++){
                product*=arr[k];
            }
            mx=max(mx,product);
        }
    }

    cout<<mx<<endl;
}

void better_maxProduct(int n, int arr[]){
    // Time complexity - O(n^2)
    // space complexity - O(1)

    int mx=0;
    for(int i=0;i<n;i++){
        int product=1;
        for(int j=i;j<n;j++){
            product*=arr[j];
            mx=max(mx,product);
        }
    }
    cout<<mx<<endl;
}

void optimal_maxProduct(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    /* Some observations :-
    1. If the given array only contains positive numbers: then the maximum product subarray will be the entire array itself.
    2. If the given also array contains an even number of negative numbers : then the maximum product subarray will be the entire array itself.
    3. If the given array also contains an odd number of negative numbers: 

    eg - {3, 2, -1, 4, -6, 3, -2, 6}
    if I ignore -1 then max of {3,2} , {4,-6,3,-2,6} is my answer
    if I ignore -2 then max of {3,2,-1,4,-6,3} , {6} is my answer
    what we are taking is either prefix or either suffix
    */

    int mx=INT_MIN;

    int prefix=1;
    for(int i=0;i<n;i++){
        if(prefix==0){
            prefix=1;
        }
        prefix*=arr[i];
        mx=max(mx,prefix);
    }
    
    int suffix=1;
    for(int i=n-1;i>=0;i--){
        if(suffix==0){
            suffix=1;   
        }
        suffix*=arr[i];
        mx=max(mx,suffix);
    }
    cout<<mx<<endl;
}


int main(){
    int n=6;
    int arr[n]={1,2,3,4,5,0};

    // int n=3;
    // int arr[n]={-2,0,-1};

    // 1. brute
    brute_maxProduct(n,arr);

    // 2. better
    better_maxProduct(n,arr);

    // 3. optimal
    optimal_maxProduct(n,arr);
    
}
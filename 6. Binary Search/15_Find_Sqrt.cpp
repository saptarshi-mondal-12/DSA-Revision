#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  Finding Sqrt of a number

You are given a positive integer n. Your task is to find and return its square root. 
If ‘n’ is not a perfect square, then return the floor value of ‘sqrt(n)’.

Input Format: n = 36
Result: 6
Explanation: 6 is the square root of 36.

Input Format: n = 28
Result: 5
Explanation: Square root of 28 is approximately 5.292. So, the floor value will be 5.

*/

void brute_Sqrt(int n){
    // TC = O(n)
    // SC = O(1)

    int ans=0;
    for(int i=0;i<=n;i++){
        if(i*i<=n){
            ans=i;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
}

void optimal_Sqrt(int n){
    // TC = O(log n)
    // SC = O(1)

    int low=1, high=n;
    int ans=1;
    while(low<=high){
        int mid=(low+high)/2;

        if(mid*mid <= n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int n=28;

    // 1. brute - linear search
    brute_Sqrt(n);

    // 2. optimal - binary search
    optimal_Sqrt(n);
}

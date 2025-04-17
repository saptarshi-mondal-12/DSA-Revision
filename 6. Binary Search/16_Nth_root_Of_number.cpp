#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*  Nth Root of a Number

Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X 
when raised to the power N equals M. If the ‘nth root is not an integer, return -1.

Input Format: N = 3, M = 27
Result: 3
Explanation: The cube root of 27 is equal to 3.

Input Format: N = 4, M = 69
Result: -1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

void brute_NthRoot(int n, int m){
    // TC = O(m * log n)
    // SC = O(1)

    int ans=-1;
    for(int i=1;i<=m;i++){
        int val=pow(i,n);
        if(val==m){
            ans=i;
            break;
        }else if(val > m){
            break;
        }
    }
    cout<<ans<<endl;
}

void optimal_NthRoot(int n, int m){
    // TC = O(log n)
    // SC = O(1)

    int ans=-1;
    int low=1, high=m;
    while(low<=high){
        int mid=(low+high)/2;
        int val=pow(mid,n);

        if(val==m){
            ans=mid;
            break;
        }
        else if(val > m){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    cout<<ans<<endl;
}

int main(){
    int n=3, m=27;
    // int n=4, m=69;

    // 1. brute - linear search
    brute_NthRoot(n,m);

    // 2. optimal - binary search
    optimal_NthRoot(n,m);
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N. 
Find the number(between 1 to N), that is not present in the given array.
Input: N = 5, array[] = {1,2,4,5}
Result: 3
*/

// NOTE : O(n) < O(2n) < O(n^2)


int brute_missingNumber(int n, int arr[]){
    // Time complexity - O(n^2)

    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
}

int better_missingNumber(int n, int arr[]){
    // Time complexity - O(n) + O(n) = O(2n)
    // space complexity - O(n)

    // using hashing 
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(hash[i]==0) return i;
    }

}

int optimal_missingNumber(int n, int arr[]){
    // Time complexity - O(n)
    // space complexity - O(1)

    
    //  Sum of first N numbers(N) = S1= (N*(N+1))/2
    // Sum of all array elements() = S2
    // The missing number = S1-S2

    int s1=(n*(n+1))/2;
    int s2=0;
    for(int i=0;i<n-1;i++) s2+=arr[i];
    return s1-s2;


}


int main(){
    int n=5;
    int arr[n]={1,2,4,5};

    // 1. brute force
    // cout<<brute_missingNumber(n,arr);

    // 2. better soln
    // cout<<better_missingNumber(n,arr);

    // 3. optimal soln
    cout<<optimal_missingNumber(n,arr);

}
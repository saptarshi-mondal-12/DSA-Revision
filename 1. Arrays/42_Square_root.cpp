#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* 
Square root of a number
Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Input: n = 5
Output: 2
Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.

Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.

*/


int SquareRoot(int n){
    // Time Complexity = : O(Sqrt(n))
    // space complexity = O(1)

    long long int i;
    for(i = 1; i * i <= n; i++) {
        if(i * i >= n) {
            break;
        }
    }
    if(i * i == n) return i;
    else return i-1;
         
}

int OptimalSquareRoot(int n){
    // Time complexity -  O(log n)
    // space complexity - O(1)
    // base case
    if (n == 0 || n == 1)
        return n;

    long long int start = 1, end = n, ans;

    // binary search to find square root of a number
    while (start <= end) {
        long long mid = (start + end) / 2;

        // check if mid*mid == n
        if (mid * mid == n)
            return mid;

        // if mid*mid < n, then iterate on the upper half
        if (mid * mid < n) {
            start = mid + 1;
            ans = mid;
        }
        // else, iterate for the lower half
        else
            end = mid - 1;
    }
    return ans;
}


int main(){
    int n=5;
    cout<<SquareRoot(n)<<endl;
    cout<<OptimalSquareRoot(n)<<endl;
}





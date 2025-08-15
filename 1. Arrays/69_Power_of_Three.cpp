#include <iostream>
#include <bits/stdc++.h>
using namespace std;


/* Q. Power of Three

Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.


Input: n = 27
Output: true
Explanation: 27 = 33

Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).
*/

bool isPowerOfThree(int n){
        
    if (n==1)
        return true;
    if (n<=0)
        return false;
    while(n>1){
        if (n%3!=0){
            return false;
        }else{
            n=n/3;
        }
    }
    return true;
}

int main(){
    int n=27;
    cout<<isPowerOfThree(n);
}
            
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Pascal’s Triangle
Given the row number n. Print the n-th row of Pascal’s triangle.

Input: n=6
Output: [1,5,10,10,5,1]

       1
     1   1
    1  2  1
   1  3  3  1
 1  4  6  4  1
1 5  10 10  5  1

*/

int optimal_nCr(int n, int r){
  // Time Complexity - O(r)
  // space complexity - O(1)
  
  int result=1;
  for(int i=0;i<r;i++){
    result=result*(n-i);
    result=result/(i+1);
  }
  return result;
}


void brute_generateRow(int n){
  // Time Complexity - O(n*r)
  for(int c=1;c<=n;c++){
    cout<<optimal_nCr(n-1,c-1)<<" ";
  }
  cout<<endl;
}

void optimal_generateRow(int n){
  // Time Complexity - O(n)

  int result=1;
  cout<<result<<" ";
  for(int i=1;i<n;i++){
    result=result*(n-i);
    result=result/i;
    cout<<result<<" ";
  }

}


int main(){
    int n=6;

    // brute - generate one by one element - n! / r! * (n-r)!
    brute_generateRow(n);

    // optimal
    optimal_generateRow(n);


    

}
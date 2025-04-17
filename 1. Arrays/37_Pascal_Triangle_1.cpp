#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Pascal’s Triangle
Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle

Input : N = 5, r = 5, c = 3
Result: 6

       1
     1   1
    1  2  1
   1  3  3  1
 1  4  6  4  1
1 5  10 10  5  1
*/

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

int brute_nCr(int n, int r){
  // Time Complexity - O(n^2)

  // Approach - generate the entire Pascal triangle and then find the element at position (r,c). 

  vector<vector<int>> ans;

  //store the entire pascal's triangle:
  for (int row = 1; row <= n; row++) {
    ans.push_back(generateRow(row));
  }
  return ans[n-1][r-1];
    
}

int optimal_nCr(int n, int r){
  // Time Complexity - O(r)
  // space complexity - O(1)

  /*  r-1
        C    => n! / r! * (n-r)!
        c-1 
  */

  /* 1. don't run a loop for n! and r! and (n-r)! and it take more time
     2. try to reduce time nCr = 7C2 = 7*6*(5*4*3*2*1)
                                      -----------------
                                      (2*1) * (5*4*3*2*1)

                                      7   6
                                      - * - 
                                      1   2
  */
  
  int result=1;
  for(int i=0;i<r;i++){
    result=result*(n-i);
    result=result/(i+1);
  }
  return result;
}

int main(){
    int r=6;
    int c=5;
    // 1. Brute
    cout<<brute_nCr(r,c)<<endl;

    // 2. Better
    cout<<optimal_nCr(r-1,c-1)<<endl;

}
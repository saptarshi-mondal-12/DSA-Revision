#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Pascal’s Triangle
Given the number of rows n. Print the first n rows of Pascal’s triangle.

Input: n=5
output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

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

vector<vector<int>> brute_pascalTriangle(int n){
  /* Time Complexity: O(n*n*r) ~ O(n3), where n = number of rows, and r = column index.
    Reason: The row loop will run for approximately n times. And generating a row 
    using the naive approach of variation 2 takes O(n*r) time complexity.
  */

  vector<vector<int>> ans;

  //Store the entire pascal's triangle:
  for (int row = 1; row <= n; row++) {
    vector<int> tempLst; // temporary list
    for (int col = 1; col <= row; col++) {
        tempLst.push_back(optimal_nCr(row - 1, col - 1));
    }
    ans.push_back(tempLst);
  }

  return ans;
}

vector<int> generateRow(int row) {
    long long result = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    for (int i = 1; i < row; i++) {
        result = result * (row - i);
        result = result / i;
        ansRow.push_back(result);
    }
    return ansRow;
}


vector<vector<int>> optimal_pascalTriangle(int n){
  // O(n^2)

  vector<vector<int>> ans;
  for (int row = 1; row <= n; row++) {
    ans.push_back(generateRow(row));
  }
  return ans;

}

int main(){
  int n=6;

  // Brute 
  // vector<vector<int>> ans = brute_pascalTriangle(n);

  // optimal 
  vector<vector<int>> ans = optimal_pascalTriangle(n);

  for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout <<endl;
    }
    
    

}
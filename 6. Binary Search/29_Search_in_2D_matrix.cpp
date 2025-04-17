#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Search in 2D matrix 

You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order. The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

*/



bool brute_searchMatrix(vector<vector<int>> matrix, int target){
    // time complexity - O(n*m)
    // space complexity - O(1)

    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==target) return true;
        }
    }
    return false;
}


bool better_searchMatrix(vector<vector<int>> matrix, int target){
    // time complexity - O(n) + (log m)
    // space complexity - O(1)

    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++){
        if(matrix[i][0] <= target && matrix[i][m-1] >= target){
            int low=0;
            int high=m-1;
            while(low<=high){
                int mid=(low+high)/2;

                if(matrix[i][mid]==target){
                    return true;
                }
                else if(matrix[i][mid]>target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }
    }
    return false;
}


bool optimal_searchMatrix(vector<vector<int>> matrix, int target){
    // time complexity - O(log(m*n))
    // space complexity - O(1)

    /* flattern 2D matrix in 1D matrix in hypothetical 
    But if we really try to flatten the 2D matrix, it will take O(N x M) time complexity and extra space to store the 1D array. 
    In that case, it will not be the optimal solution anymore.
    
    row = index/m
    col = index%m
    */

    int n=matrix.size();
    int m=matrix[0].size();

    int low=0, high=(m*n)-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=mid/m, col=mid%m;

        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return false;  
}


int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int k=8;

    // 1. brute 
    cout<<brute_searchMatrix(matrix,k)<<endl;

    // 2. better 
    cout<<better_searchMatrix(matrix,k)<<endl;

    // 3. optimal 
    cout<<optimal_searchMatrix(matrix,k)<<endl;

}

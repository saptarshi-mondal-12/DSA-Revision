#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Search in 2D matrix II

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
*/

bool brute_searchMatrix_II(vector<vector<int>> matrix, int target){
    // time complexity - O(n*m) We are starting traversal from (0, M-1), and at most, we can end up being in the cell (M-1, 0). 
    // So, the total distance can be at most (N+M). So, the time complexity is O(N+M).
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


bool better_searchMatrix_II(vector<vector<int>> matrix, int target){
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


bool optimal_searchMatrix_II(vector<vector<int>> matrix, int target){
    // time complexity - O(n+m)
    // space complexity - O(1)


    int n=matrix.size();
    int m=matrix[0].size();

    int row=0, col=m-1;
    while(row<n && col>=0){
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]<target){
           row++;

        }else{
            col--;

        }
    }
    return false;  
}


int main(){
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};

    int k=14;

    // 1. brute 
    cout<<brute_searchMatrix_II(matrix,k)<<endl;

    // 2. better 
    cout<<better_searchMatrix_II(matrix,k)<<endl;

    // 3. optimal 
    cout<<optimal_searchMatrix_II(matrix,k)<<endl;

}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Median in a row-wise sorted Matrix

Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.


Input: mat[][] = [[1, 3, 5],
                [2, 6, 9],
                [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

Input: mat[][] = [[2, 4, 9],
                [3, 6, 7],
                [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.

Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
*/

int brute_median(vector<vector<int>> matrix)
{
    // time complexity - O(n*m) + (n*m * log(n*m))
    // space complexity - O(n*m)

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            nums.push_back(matrix[i][j]);
        }
    }
    sort(nums.begin(), nums.end());
    return nums[(n * m) / 2];
}

int optimal_median(vector<vector<int>> matrix){
    // time complexity - O(32 * n * log(m))
    // space complexity - O(1)

    
    int n = matrix.size();
    int m = matrix[0].size();

    int medianIndex = (n * m) / 2;

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }

    while (low <= high){
        int mid = (low + high) / 2;
        int count = 0;

        for (int i = 0; i < n; i++){
            int left = 0, right = m - 1;
            int index = -1;
            while (left <= right){
                int middle = (left + right) / 2;

                if (matrix[i][middle] <= mid){
                    index = middle;
                    left = middle + 1;
                }
                else{
                    right = middle - 1;
                }
            }
            count += (index + 1);
        }

        if (count <= medianIndex){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }

    return low;
}

int main(){
    vector<vector<int>> matrix = {{1, 5, 7, 9, 11}, {2, 3, 4, 5, 10}, {9, 10, 12, 14, 16}};

    // 1. brute
    cout << brute_median(matrix) << endl;

    // 2. optimal
    cout << optimal_median(matrix) << endl;
}
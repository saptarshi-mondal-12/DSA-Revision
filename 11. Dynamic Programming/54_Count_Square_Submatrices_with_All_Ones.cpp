#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Q. Count Square Submatrices with All Ones

Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Input: matrix =
[ [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1] ]

Output: 15
Explanation: There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Input: matrix = 
[ [1,0,1],
  [1,1,0],
  [1,1,0]]

Output: 7
Explanation: There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.


Intuition: 

Brute force:
In order to solve this question, we will first try the brute force approach. In the brute force approach, we will just check for every cell(i, j)(if the cell contains 1) that if there exists a k-sized square where k can range from 1 to min(n-i, m-j)(considering 0-based indexing). The implementation will be very much complex. So, we will move on to the optimized approach i.e. the dynamic programming approach.

Optimized approach (dynamic programming approach):
Until now, all the dynamic programming problems, we have solved were based on recursion. Here, in this problem, we can apply the recursion as well but that will be not much intuitive. That is why, in order to solve this type of square problem, we generally use the tabulation method. This is much more intuitive than the recursive approach.

Intuition:
Following the tabulation method, we will first create a 2D dp array of the same size as the given 2D matrix. And in the dp array, dp[i][j] will signify, how many squares end at the cell (i, j) i.e. for how many squares the rightmost bottom cell is (i, j).

For example, consider the following matrix:
[1,1]
[1,1]


For the given matrix, the dp array will be the following:
[1,1]
[1,2]


For the above matrix, dp[0][0] stores 1, whereas dp[1][1] stores 2. For cell (0, 0), there is only 1 square(i.e. the cell itself) that ends at (0,0). But for cell (1,1), there is a square of size 1 i.e. the cell itself and there is also a square of size 2 (i.e. the whole matrix) that end at cell (1,1).

Similarly, let’s try it for the following 3X3 matrix:
[1,1,1]    [1,1,1]
[1,1,1]    [1,2,2]
[1,1,1]    [1,2,3]

given       dp array
matrix


Now, to get the final answer, we will just add all the values of the cells and the total sum will be our final answer. So, for the 2X2 matrix, the answer is (1+1+1+2) = 5 squares and for the 3X3 matrix, the answer is (1+1+1+1+2+2+1+2+3) = 14 squares.

Now, it’s time to discuss how to fill the values of the dp array:

If we carefully observe, for the first row and for the first column, each cell (i, j), itself will be the one and only square(if cell(i, j) contains 1) that ends at that particular cell i.e. (i, j). So, for the first row and first column, we will just copy the values of the matrix as it is to the dp array. 
Now, to fill the other cells, we will check the following:
If the cell contains 1, we will have to check its three adjacent cells i.e. (i-1, j), (i-1, j-1), and (i, j-1). We will first figure out the minimum number of squares that end at these adjacent cells. And while filling the value for cell(i, j) we will add 1 with that minimum value as the cell (i, j) itself is a square. The formula will be the following:dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) +1
Otherwise, if the cell(i, j) contains 0, we will also set the value of dp[i][j] as 0.
 Using this approach, we will fill all the cells of the dp array.

Note: If you wish to see the dry run of the above approach, you can watch the video attached to this article.

Approach: 
    1. First, we need to create a dp array of the same size as the matrix.
    2. Then, we will copy the values of the first row and first column of the matrix as it is to the dp array.
    3. Then, we will start iterating over the rest of the cells and we will observe two cases:
        a. If the cell (i, j) contains 0, we will set the value 0 to the cell dp[i][j].
        b. If the cell (i, j) contains 1, we will first find the minimum value among the adjacent three cells i.e. min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]). And with that minimum value, we will add 1 and set it to the cell dp[i][j]. The formula will look like the following:
        dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) +1
        
    4. After filling all the cells in this way, we will just add all the values of the dp array to get the total sum. And this total sum will be the final answer.
*/

int countSquares(vector<vector<int>>& matrix) {
    // Time Complexity: O(N*M)
    // Space Complexity: O(N*M)

    int row=matrix.size();
    int col=matrix[0].size();

    vector<vector<int>>dp(row, vector<int>(col, 0));
    for (int i = 0; i < col; i++) dp[0][i] = matrix[0][i];
    for (int j = 0; j < row; j++) dp[j][0] = matrix[j][0];

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (matrix[i][j] == 0) dp[i][j] = 0;
            else {
                int up=dp[i - 1][j];
                int left=dp[i][j-1];
                int diagonal=dp[i - 1][j-1];
                dp[i][j] = 1 + min(left, min(up, diagonal));
            }
        }
    }

    // Sum up all element in dp
    int sum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            sum += dp[i][j];
        }
    }
    return sum;
}

int main() {
    vector<vector<int>> arr = {{0, 1, 1, 1}, {1, 1, 1, 1},{0, 1, 1, 1}};
    int squares = countSquares(arr);
    cout<<"The number of squares: "<<squares<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Matrix Chain Multiplication 

Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

Given an array nums of size n. Dimension of matrix Ai ( 0 < i < n ) is nums[i - 1] x nums[i].Find a minimum number of multiplications needed to multiply the chain.


Input : nums = [10, 15, 20, 25]
Output : 8000
Explanation : There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required is 8000.

Input : nums = [4, 2, 3]
Output : 24
Explanation : There is only one way to multiply the chain - A1*A2.
Thus minimum number of multiplications required is 24.

Intuition: 
COPY NOTES
https://takeuforward.org/dynamic-programming/matrix-chain-multiplication-dp-48/
https://takeuforward.org/data-structure/matrix-chain-multiplication-tabulation-method-dp-49/

*/


// Recirsion-----------------------------------------------------------------------------------
int solve1(int i, int j, vector<int>nums){
    // Base case: 
    if(i==j) return 0;
    
    int mini=INT_MAX;

    // partioning loop
    for(int k=i;k<=j-1;k++){
        int ans = nums[i-1]*nums[k]*nums[j] + solve1(i, k, nums) + solve1(k+1, j, nums);
        mini=min(mini, ans);
    }
    return mini;
}
int matrixMultiplication1(vector<int> &nums){
    // Time complexity: Exponenetial
    // Space complexity: O(N)

    int n=nums.size();
    return solve1(1, n-1, nums);
}



// Memoization---------------------------------------------------------------------------------
int solve2(int i, int j, vector<int>nums, vector<vector<int>>&dp){
    // Base case: 
    if(i==j) return 0;

    if (dp[i][j] != -1) return dp[i][j];
    
    int mini=INT_MAX;

    // partioning loop
    for(int k=i;k<=j-1;k++){
        int ans = nums[i-1]*nums[k]*nums[j] + solve2(i, k, nums, dp) + solve2(k+1, j, nums, dp);
        mini=min(mini, ans);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication2(vector<int> &nums){
    // Time complexity: O(N*N*N)
    // Space complexity: O(N*N) + O(N)

    int n=nums.size();
    vector<vector<int>>dp(n, vector<int>(n, -1));
    return solve2(1, n-1, nums, dp);
}



// Tabulation-----------------------------------------------------------------------------------------------
int matrixMultiplication3(vector<int> &nums){
    // Time complexity:  O(N*N*N)
    // Space complexity:  O(N*N)

    int n=nums.size();
    vector<vector<int>>dp(n, vector<int>(n, 0));

    // Initialize the diagonal elements of the DP table to 0
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }

    // Loop for the length of the chain
    for (int i = n-1; i >= 1; i--) {
        for (int j = i+1; j < n ; j++) {
            int mini = INT_MAX;

            // Try different partition points to find the minimum
            for (int k = i; k < j; k++) {
                int ans = (nums[i - 1] * nums[k] * nums[j]) + dp[i][k] + dp[k + 1][j] ;
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }

    // The result is stored in dp[1][N-1]
    return dp[1][n - 1];
}




int main(){
    vector<int>nums={10,20,30,40,50};

    // Recursion
    cout<<matrixMultiplication1(nums)<<endl;

    // Memoization
    cout<<matrixMultiplication2(nums)<<endl;

    // Tabulation
    cout<<matrixMultiplication3(nums)<<endl;


}
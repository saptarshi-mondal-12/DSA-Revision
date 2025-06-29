#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Input: nums = [1,5]
Output: 10





Intuition: -------------------------------------------------------------------------------------------

Move in opposite direction - reverse direction because sub problem is dependent. So solving in reverse direction it would be independent

[b1,b2,b3,b4,b5,b6,b7,b8] 

[b1,b2,b3,*,b5,b6,b7,b8]
if i burst b4 [b1,b2,b3] & [b5,b6,b7,b8] cannot be solved independtly because if we brust b4, then b3 is dependent on b5 which is anpther subproblem.
Similartly b5 is dependent on b3. So solving independtly cannot worked. 

So we go in reverse direction, In example we brust 8 last 

1*8*1 = 8 
then

[3,8]

Now 3 has to be brust. Can i say for this 3 i definetely know since i brusted out before 8 , 8 wiil be the right guy because i am going in reverse direcion. i am very much sure that 3 has a right guy 8

1*3*8 = 24 
then 

[3,5,8]

3*5*8=120

[3,1,5,8]

3*1*5=15 


Total = 8+24+120+15=167


[b1,b2,b3] * [b5, b6] Now this 2 subproblen is independent here. Because let me show with example 

Suppose we brust b4 at last ---> [b1,b2,b3,b4,b5, b6]


1*b4*1 

Now 1st subproblem [b1,b2,b3] and 2nd sub problem [b5,b6] we have to solve 

As i know b4 is the last guy brusted i definetely know b4 will exit over 2nd last step i.e

Second last step 6: [b4] exist here then only b4 brusted at last step 
last step 7:        [b4]

Can i say probably step 6: anyone can be [b1,b4] or [b2,b4] or [b3,b4] or [b4,b5] or [b4,b6] no matter who is i am not dependent on [b1,b2,b3]
instead of that b5 or b5 i am dependent on b4 who is gou left to it. So i proved it is not dependent on left subproblem 

if you solving for b1 it is dependent on range right guy i.e b4, not dependent on right sub problem([b5,b6]) So i proved





https://takeuforward.org/data-structure/burst-balloons-partition-dp-dp-51/
*/


// Recursion ---------------------------------------------------------
int solve1(int i, int j, vector<int>nums){
    if(i>j) return 0;

    int maxi=INT_MIN;

    // Iterate through each possible balloon to burst last - every one can be my last guy
    for(int k=i;k<=j;k++){
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i-1]*nums[k]*nums[j+1];

        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = solve1(i, k - 1, nums) + solve1(k + 1, j, nums);

        // Update the maximum coins
        maxi = max(maxi, coins + remainingCoins);
    }
    return maxi;
}
int maxCoins1(vector<int>nums) {
    // Time complexity: Exponential
    // Space complexity: O(N)
    
    int n=nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(),1);
    nums.push_back(1);

    // n= 4
    // [1,3,1,5,8,1]

    return solve1(1, n, nums);
}



// Memoization--------------------------------------------------------
int solve2(int i, int j, vector<int>nums, vector<vector<int>>&dp){
    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxi=INT_MIN;

    // Iterate through each possible balloon to burst last - every one can be my last guy
    for(int k=i;k<=j;k++){
        // Calculate the coins obtained by bursting the k-th balloon last
        int coins = nums[i-1]*nums[k]*nums[j+1];

        // Recursively calculate the maximum coins for the remaining balloons
        int remainingCoins = solve2(i, k - 1, nums, dp) + solve2(k + 1, j, nums, dp);

        // Update the maximum coins
        maxi = max(maxi, coins + remainingCoins);
    }
    return dp[i][j] = maxi;
}
int maxCoins2(vector<int>nums) {
    // Time complexity: O(N^3)
    // Space complexity: O(N^N) + O(N)

    int n=nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(),1);
    nums.push_back(1);

    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    return solve2(1, n, nums, dp);
}



// Tabulation---------------------------------------------------------
int maxCoins3(vector<int>nums) {
    // Time complexity: O(N^3), There are total N2 no. of states. And for each state, we are running a partitioning loop roughly for N times.
    // Space complexity: O(N*N)

    int n=nums.size();

    // Add 1 to the beginning and end of the nums array
    nums.insert(nums.begin(),1);
    nums.push_back(1);

    vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

    for(int i=n; i>=1; i--){
        for(int j=1; j<=n;j++){
            if (i > j) continue;

            int maxi=INT_MIN;

            // Iterate through each possible balloon to burst last
            for(int k=i;k<=j;k++){
                // Calculate the coins obtained by bursting the k-th balloon last
                int coins = nums[i-1]*nums[k]*nums[j+1];

                // Recursively calculate the maximum coins for the remaining balloons
                int remainingCoins = dp[i][k - 1] + dp[k + 1][j];

                // Update the maximum coins
                maxi = max(maxi, coins + remainingCoins);
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}


int main(){
    vector<int>nums={3,1,5,8};

    // Recursion
    cout<<maxCoins1(nums)<<endl;

    // Memoization
    cout<<maxCoins2(nums)<<endl;

    // Tabulation
    cout<<maxCoins3(nums)<<endl;
}
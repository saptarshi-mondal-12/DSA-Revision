#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. Frog Jump

Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

Input: heights[] = [20, 30, 40, 20] 
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20-30|  = 10
Total Cost = 10 + 10 = 20


Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40-50|  = 10
Total Cost = 20 + 10 = 30



Intuition: 

1. Recursion - 
Try all possible ways using recursion and get the minimum and return ans
Step 1: Express the problem in terms of index
Step 2: Do all stuffs on index
Step 3: take minimum of all stuffs

Q. if i a, jump from index to index-1 what is the energy that is consumed?
Ans: abs(height[index]-height[index-1]) this much amount of energy is consumed.
i asked the recursion, hey i have reached to index-1, now its your job to tell me from index-1 to 0 that how much it will cost you. Recursion will do the job. I know the cost of index to index-1 i.e (abs(height[index]-height[index-1])) get me remaining. 

int jumpOne= solve1(index-1, height)+ abs(height[index]-height[index-1]);


Q. Similarly if i a, jump from index to index-2 what is the energy that is consumed?
Ans: abs(height[index]-height[index-2]) this much amount of energy is consumed.


2. Memoization - top down (n to 0):
dp with recursion where we use O(n) recursive stack space and O(n) for dp


3. Tabultion - bottom up (0 to n):
dp with for loop

3. space optimization: 
Rule NOTE: Whenever there is index-1 or index-2 there can always be an space optimization 

If we closely look at the values required at every iteration, 
dp[i], dp[i-1], and  dp[i-2]
we see that for any i, we do need only the last two values in the array. So is there a need to maintain a whole array for it? The answer is ‘No’. Let us call dp[i-1] as prev and dp[i-2] as prev2. Now understand the following illustration.

*/


// Recursive solution - (Time limit exceed) - (repetetive calculation)
int solve1(int index, vector<int>height){
    if(index==0){
        return 0;
    }
        
    // The frog can jump either by one step or by two steps. We will calculate the cost of the jump from the height array. The rest of the cost will be returned by the recursive calls that we make
    int jumpOne= solve1(index-1, height)+ abs(height[index]-height[index-1]);
        
    // Base case: when we are at 1 we can't jump to n-2 because 1-2 = -1 which is invalid
    int jumpTwo = INT_MAX;
    if(index>1)
        jumpTwo = solve1(index-2, height)+ abs(height[index]-height[index-2]);
        
    return min(jumpOne, jumpTwo);
}
int recursion_minCost(vector<int>& height){
    // Time complexity: O(n)
    // space complexity: O(n)

    int n=height.size();

    // We can say that f(n-1) signifies the minimum amount of energy required to move from stair 0 to stair n-1. 
    int minimum_cost=solve1(n-1,height);
    return minimum_cost;
}



// Memoization approach---------------------------------------------------------------------------------
int solve2(int index, vector<int>height, vector<int>&dp){
    if(index==0){
        return 0;
    }

    // if we calculated earlier, return it 
    if(dp[index]!=-1){
        return dp[index];
    }

    // Jump one step
    int jumpOne= solve2(index-1, height, dp)+ abs(height[index]-height[index-1]);

    // jump two step
    int jumpTwo = INT_MAX;
    if(index>1)
        jumpTwo = solve2(index-2, height, dp)+ abs(height[index]-height[index-2]);

    // store value in DP
    return dp[index]=min(jumpOne, jumpTwo);

}
int Memoization_minCost(vector<int>& height){
    // Time complexity: O(n)
    // space complexity: O(n) + O(n) - We are using a recursion stack space(O(N)) and an array O(N) for dp. 

    int n=height.size();
    vector<int> dp(n,-1); 
    int minimum_cost=solve2(n-1, height, dp);
    return minimum_cost;
}



// Tabulation approach----------------------------------------------------------------------------------
int Tabulation_minCost(vector<int>& height){
    // Time complexity: O(n)
    // space complexity: O(n)

    int n=height.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int index=1;index<n;index++){
        int jumpOne= dp[index-1] + abs(height[index]-height[index-1]);
        int jumpTwo = INT_MAX;
        if(index>1){
            jumpTwo = dp[index-2] + abs(height[index]-height[index-2]);
        }
        dp[index]=min(jumpOne, jumpTwo);
    }
    return dp[n-1];
}



// space optimization approach -------------------------------------------------------------------------
int spaceOptimization_minCost(vector<int>& height){
    // Time complexity: O(n)
    // space complexity: O(1)
    int n=height.size();

    // dp[i-1] as prev and dp[i-2] as prev2.
    int prev=0;
    int prev2=0;
    for(int i=1;i<n;i++){
        int jumpOne= prev + abs(height[i]-height[i-1]);
        int jumpTwo = INT_MAX;
        if(i>1)
            jumpTwo = prev2 + abs(height[i]-height[i-2]);
        
        int cur_i=min(jumpOne, jumpTwo);
        prev2=prev;
        prev=cur_i;    
    }
    return prev;
}




int main(){
    vector<int>height={20,30,40,20};

    // 1. Recursion approach
    cout<<recursion_minCost(height)<<endl;

    // 2 Memoization approach -> n to 0 -> Steps to convert Recursive code to memoization solution -> using DP
    cout<<Memoization_minCost(height)<<endl;

    // 3.Tabulation approach - 0 to n
    cout<<Tabulation_minCost(height)<<endl;

    // 4. space optimization approach
    cout<<spaceOptimization_minCost(height)<<endl;
}


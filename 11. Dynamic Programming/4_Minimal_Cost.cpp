#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Minimal Cost - 

NOTE: Follow up question of frog jump. 
In frog jump question, frog can jump only one or two step. what if frog can jump to stones i + 1, i + 2, … i + k. What is the minimum cost?

Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be |10-30| + |30-20| = 30, which is minimum.
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.

Intuition: 
In frog jump question, we worte 2 recursion i.e (i+1, i+2). Here we have to write for k jumps. So just add a for loop form 1 to k. Instead of writing index-1, index-2 .... so on we r write a for loop from 1 <= k and get the minimum of all(k jumps)
*/




// Recursive solution - (Time limit exceed) - (repetetive calculation)
int solve1(int index, vector<int>height, int k){
    if(index==0){
        return 0;
    }
    int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        if(index-i >= 0){  
            int jump= solve1(index-i, height, k)+ abs(height[index]-height[index-i]);
            mini=min(mini, jump);
        }else{
            break;
        }
    }
    return mini;
}
int recursion_minimumCost(vector<int>height, int k){
    // Time complexity: O(n*k)
    // space complexity: O(n)

    int n=height.size();
    int minimum_cost=solve1(n-1,height, k);
    return minimum_cost;
    
}



// Memoization approach---------------------------------------------------------------------------------
int solve2(int index, vector<int>height, vector<int>&dp, int k){
    if(index==0){
        return 0;
    }

    // if we calculated earlier, return it 
    if(dp[index]!=-1){
        return dp[index];
    }

    int mini=INT_MAX;
    for(int i=1;i<=k;i++){
        if(index-i >= 0){  
            int jump= solve2(index-i, height, dp, k)+ abs(height[index]-height[index-i]);
            mini=min(mini, jump);
        }else{
            break;
        }
    }
    return dp[index]=mini;
}
int Memoization_minimumCost(vector<int>& height, int k){
    // Time complexity: O(n*k)
    // space complexity: O(n) + O(n) - We are using a recursion stack space(O(N)) and an array O(N) for dp. 

    int n=height.size();
    vector<int> dp(n,-1); 
    int minimum_cost=solve2(n-1, height, dp, k);
    return minimum_cost;
}



// Tabulation approach----------------------------------------------------------------------------------
int Tabulation_minimumCost(vector<int>& height, int k){
    // Time complexity: O(n*k)
    // space complexity: O(n)

    int n=height.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int index=1;index<n;index++){
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            if(index-i >= 0){  
                int jump= dp[index-i]+ abs(height[index]-height[index-i]);
                mini=min(mini, jump);
            }
        }
        dp[index]=mini;
    }

    return dp[n-1];
}



// space optimization approach -------------------------------------------------------------------------
void spaceOptimize_minimumCost(vector<int>& height, int k){
    /*
    No we cannot optimize the space. We can just optimize the space from O(n) to O(k) because we need minimum from k last values. Suppose if k=n then worst case again become O(n). So no need of space optimization  
    
    We can do by keep track of last k using a priority_queue but no need
    minimum = (i-k)....(i-3)(i-2)(i-1) */

}



int main(){
    vector<int>height={10, 20, 10};
    int k=1;

    // recursive
    cout<<recursion_minimumCost(height,k)<<endl;

    // Memoization
    cout<<Memoization_minimumCost(height,k)<<endl;

    // Tabulation
    cout<<Tabulation_minimumCost(height,k)<<endl;

    // space optimize
    spaceOptimize_minimumCost(height,k);
}


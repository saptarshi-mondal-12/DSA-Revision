#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Unbounded Knapsack Problem

Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Input: val = [1, 1], wt = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.


Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.


Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element .hence, total profit is 0.

Intuition : same knapsack code but 2 change 
1. change in base case 
2. change in take part - we have to remain in same index


1. base case: 
    If ind==0, it means we are at the first item. Now, in an unbounded knapsack we can pick an item any number of times we want. As there is only one item left, we will pick for W/wt[0] times because we ultimately want to maximize the value of items while respecting the constraint of weight of the knapsack. The value added will be the product of the number of items picked and value of the individual item. Therefore we return (W/wt[0]) * val[0].


2. take = remain in same index 

Step 2: Try out all possible choices at a given index.
We need to generate all the subsequences. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”.

We have two choices:
    Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index item. If we exclude the current item, the capacity of the bag will not be affected and the value added will be 0 for the current item. So we will call the recursive function f(ind-1,W)
    
    Include the current element in the subsequence: We will try to find a subsequence by considering the current item to the knapsack. As we have included the item, the capacity of the knapsack will be updated to W-wt[ind] and the current item’s value (val[ind]) will also be added to the further recursive call answer.

Now here is the catch, as there is an unlimited supply of coins, we want to again form a solution with the same item value. So we will not recursively call for f(ind-1, W-wt[ind]) rather we will stay at that index only and call for f(ind, W-wt[ind]) to find the answer.
Note: We will consider the current item in the subsequence only when the current element’s weight is less than or equal to the capacity ‘W’ of the knapsack, if it isn’t we will not be considering it.

*/

// Recursion-------------------------------------------------------------------------
int solve1(int index, int bagWeight, vector<int> &value, vector<int> &weight){
    // Base case
    if(index==0){
        if(weight[index] <= bagWeight){
            return (bagWeight / weight[0]) * value[0];
		}else{
			return 0;
        }
    } 

    int notTake = 0 + solve1(index-1, bagWeight, value, weight);
    int take=INT_MIN;
    if(weight[index] <= bagWeight){
        take = value[index] + solve1(index, bagWeight - weight[index], value, weight);
    }
    return max(take, notTake);


}
int unboundedKnapsack1(int n, int bagWeight, vector<int> &value, vector<int> &weight){
    // Time complexity: O(2^bagWeight) exponential - Every time our recurrence stand up on same index. for an index don't have 2 ways we have multiple ways. Time complexity is exponential as of now.

    // Space complexity: O(N)
    return solve1(n-1, bagWeight, value, weight);
}



// Memoization----------------------------------------------------------------------
int solve2(int index, int bagWeight, vector<int> &value, vector<int> &weight, vector<vector<int>>&dp){
    // Base case
    if(index==0){
        if(weight[index] <= bagWeight){
            return (bagWeight / weight[0]) * value[0];
		}else{
			return 0;
        }
    } 

    if (dp[index][bagWeight] != -1) return dp[index][bagWeight];

    int notTake = 0 + solve2(index-1, bagWeight, value, weight, dp);
    int take=INT_MIN;
    if(weight[index] <= bagWeight){
        take = value[index] + solve2(index, bagWeight - weight[index], value, weight, dp);
    }
    return dp[index][bagWeight] = max(take, notTake);


}
int unboundedKnapsack2(int n, int bagWeight, vector<int> &value, vector<int> &weight){
    // Time complexity: O(N*bagWeight)
    // Space complexity: O(N*bagWeight) + O(N)

    vector<vector<int>>dp(n, vector<int>(bagWeight+1, -1));
    return solve2(n-1, bagWeight, value, weight, dp);
}



// Tabulation-------------------------------------------------------------------------
int unboundedKnapsack3(int n, int bagWeight, vector<int> &value, vector<int> &weight){
    // Time complexity: O(N*bagWeight)
    // Space complexity: O(N*bagWeight)

    vector<vector<int>>dp(n, vector<int>(bagWeight+1, 0));

	// Base condition: Fill in the first row for the weight of the first item
    for (int i = 0; i <= bagWeight; i++) {
		if (weight[0] <= i) {
			dp[0][i] = (i/weight[0]) * value[0];  // If first item can fit, take its value
		} 
	}

	for(int i=1; i<n; i++){
		for(int capacity=0; capacity <= bagWeight; capacity++){
			int notTake = 0 + dp[i-1][capacity];

			int take=INT_MIN;
			if(weight[i] <= capacity){
				take = value[i] + dp[i][capacity - weight[i]];
			}

			dp[i][capacity] = max(take, notTake);
		}
	}
	return dp[n-1][bagWeight];
}



// space optimization ----------------------------------------------------------------
int unboundedKnapsack4(int n, int bagWeight, vector<int> &value, vector<int> &weight){
    // Time complexity: O(N*bagWeight)
    // Space complexity: O(bagWeight)

    vector<int>prev(bagWeight+1, 0);

	// Base condition: Fill in the first row for the weight of the first item
    for (int i = 0; i <= bagWeight; i++) {
		if (weight[0] <= i) {
			prev[i] = (i/weight[0]) * value[0];  // If first item can fit, take its value
		} 
	}
    
    for(int i=1; i<n; i++){
		vector<int>curr(bagWeight+1, 0);
    	for(int capacity=0; capacity <= bagWeight; capacity++){
    		int notTake = 0 + prev[capacity];
    
    		int take=INT_MIN;
    		if(weight[i] <= capacity){
                // note: we have to remain in same index 
                // that's why we curr instead of prev this part -> curr[capacity - weight[i]];
    			take = value[i] + curr[capacity - weight[i]];
    		}
    
    		curr[capacity] = max(take, notTake);
    	}
		prev=curr;
    }
    return prev[bagWeight];
}

int main(){
    int n=4;
    vector<int>weight={5, 4, 2, 3};
    vector<int>value={10, 40, 30, 50};
    int bagWeight = 5;

    // Recursion
    cout<<unboundedKnapsack1(n, bagWeight, value, weight)<<endl;

    // Memoization
    cout<<unboundedKnapsack2(n, bagWeight, value, weight)<<endl;

    // Tabulation
    cout<<unboundedKnapsack3(n, bagWeight, value, weight)<<endl;

    // Space optimization
    cout<<unboundedKnapsack4(n, bagWeight, value, weight)<<endl;
}
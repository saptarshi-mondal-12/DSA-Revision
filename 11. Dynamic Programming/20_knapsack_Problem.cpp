#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Knapsack Problem

Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).

Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.

Intuition: 

Q. Why a Greedy Solution doesn’t work?

The first approach that comes to our mind is greedy. A greedy solution will fail in this problem because there is no ‘uniformity’ in data. While selecting a local better choice we may choose an item that will in long term give less value. Try with below example with greedy. 

Weight=[3,2,5]
value=[30,40,60]
W=6

A Greedy solution will be to take the most valuable item first, so we will take an item on index 2, with a value of 60, and put it in the knapsack. Now the remaining capacity of the knapsack will be 1. Therefore we cannot add any other item. So a greedy solution gives us the answer 60.

Now we can clearly see that a non-greedy solution of taking the first two items will give us the value of 70 (30+40) in the given capacity of the knapsack.

As the greedy approach doesn’t work, we will try to generate all possible combinations using recursion and select the combination which gives us the maximum value in the given constraints.


Step 1: Express the problem in terms of indexes.

We are given ‘n’ items. Their weight is represented by the ‘wt’ array and value by the ‘val’ array. So clearly one parameter will be ‘ind’, i.e index up to which the array items are being considered.
There is one more parameter “W”. We need the capacity of the knapsack to decide whether we can pick an array item or not in the knapsack.
So, we can say that initially, we need to find f(n-1, W) where W is the overall capacity given to us. f(n-1, W) means we are finding the maximum value of items that the thief can steal from items with index 0 to n-1 capacity W of the knapsack.


Base Cases:
    If ind==0, it means we are at the first item, so in that case we will check whether this item’s weight is less than or equal to the current capacity W, if it is, we simply return its value (val[0]) else we return 0.

Step 2: Try out all possible choices at a given index.

We need to generate all the subsequences. We will use the pick/non-pick technique as discussed in this video “Recursion on Subsequences”.

We have two choices:
    1. Exclude the current element in the subsequence: We first try to find a subsequence without considering the current index item. If we exclude the current item, the capacity of the bag will not be affected and the value added will be 0 for the current item. So we will call the recursive function f(ind-1,W)

    2. Include the current element in the subsequence: We will try to find a subsequence by considering the current item to the knapsack. As we have included the item, the capacity of the knapsack will be updated to W-wt[ind] and the current item’s value (val[ind] will also be added to the further recursive call answer. We will make a recursive call to f(ind-1, W- wt[ind]).

Step 3:  Return the maximum of take and notTake
As we have to return the maximum amount of value, we will return the max of take and notTake as our answer.
*/



// Recursion----------------------------------------------------------------------------
int solve1(int index, vector<int> weight, vector<int> value, int bagWeight){
	// Base case 1:
	if(index==0){
		if(weight[index] <= bagWeight){
			return value[index];
		}else{
			return 0;
		}
	}

	int notTake = 0 + solve1(index-1, weight, value, bagWeight);

	int take=INT_MIN;
	if(weight[index] <= bagWeight){
		take = value[index] + solve1(index-1, weight, value, bagWeight - weight[index]);
	}

	return max(take, notTake);
}
int knapsack1(vector<int> weight, vector<int> value, int n, int bagWeight) {
    // Time complexity: (2^N)
    // Space complexity: O(N)

	return solve1(n-1, weight, value, bagWeight);
}


// Memoization--------------------------------------------------------------------------
int solve2(int index, vector<int> weight, vector<int> value, int bagWeight, vector<vector<int>>&dp){
	// Base case:
	if(index==0){
		if(weight[index] <= bagWeight){
			return value[index];
		}else{
			return 0;
		}
	}

	if(dp[index][bagWeight] != -1) return dp[index][bagWeight];


	int notTake = 0 + solve2(index-1, weight, value, bagWeight, dp);

	int take=INT_MIN;
	if(weight[index] <= bagWeight){
		take = value[index] + solve2(index-1, weight, value, bagWeight - weight[index], dp);
	}

	return dp[index][bagWeight] = max(take, notTake);
}
int knapsack2(vector<int> weight, vector<int> value, int n, int bagWeight){
    // Time complexity: O(N * bagWeight)
    // Space complexity: O(N * bagWeight) + (N)
    
	vector<vector<int>>dp(n, vector<int>(bagWeight+1, -1));
	return solve2(n-1, weight, value, bagWeight, dp);
}


// Tabulation-----------------------------------------------------------------------------
int knapsack3(vector<int> weight, vector<int> value, int n, int bagWeight) {
    // Time complexity: O(N * bagWeight)
    // Space complexity: O(N * bagWeight)
    
	vector<vector<int>>dp(n, vector<int>(bagWeight+1, 0));

	// Base condition: Fill in the first row for the weight of the first item
    for (int i = 0; i <= bagWeight; i++) {
		if (weight[0] <= i) {
			dp[0][i] = value[0];  // If first item can fit, take its value
		} 
	}

	for(int i=1; i<n; i++){
		for(int capacity=0; capacity <= bagWeight; capacity++){
			int notTake = 0 + dp[i-1][capacity];

			int take=INT_MIN;
			if(weight[i] <= capacity){
				take = value[i] + dp[i-1][capacity - weight[i]];
			}

			dp[i][capacity] = max(take, notTake);
		}
	}
	return dp[n-1][bagWeight];
}


// Space optimiztion 
int knapsack4(vector<int> weight, vector<int> value, int n, int bagWeight) {
    // Time complexity: O(N * bagWeight)
    // Space complexity: O(bagWeight)
    
	vector<int>prev(bagWeight+1, 0);

    // Base condition: Fill in the first row for the weight of the first item
    for (int i = 0; i <= bagWeight; i++) {
    	if (weight[0] <= i) {
    		prev[i] = value[0];  // If first item can fit, take its value
    	} 
    }
    
    for(int i=1; i<n; i++){
		vector<int>curr(bagWeight+1, 0);
    	for(int capacity=0; capacity <= bagWeight; capacity++){
    		int notTake = 0 + prev[capacity];
    
    		int take=INT_MIN;
    		if(weight[i] <= capacity){
    			take = value[i] + prev[capacity - weight[i]];
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
    cout<<knapsack1(weight, value, n, bagWeight)<<endl;

    // Memoization
    cout<<knapsack2(weight, value, n, bagWeight)<<endl;

    // Tabulation
    cout<<knapsack3(weight, value, n, bagWeight)<<endl;

    // Space optimization
    cout<<knapsack4(weight, value, n, bagWeight)<<endl;


}
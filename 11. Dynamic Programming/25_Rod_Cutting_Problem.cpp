#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Rod Cutting Problem

Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.

Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.

Input: price[] = [1, 10, 3, 1, 3, 1, 5, 9]
Output: 40




----Intuition: Same unbounded Knapsack code - Treat problem as unbounded Knapsack

In unbounded knapsack problem a bagWeight is given with a array of weight and values. 
In Rod cutting Problem a rodLength is given and with a array of weight where price[i] denotes the value of a piece of length i.  

Recursion: 
bagWeight = rodLength

*/


// Recursion-----------------------------------------------------------------------
int solve1(int index, int rodLength, vector<int> &price){
	// Base case: When `index == 0`, the only available rod length is `index + 1`, which is 1.  
	// We need to cut the rod into pieces of length 1 until the total rod length is exhausted.  
	// Since each piece of length 1 costs `price[0]`, the total cost for cutting a rod of `rodLength` will be `rodLength * price[0]`.  
	if (index == 0) {
		return rodLength * price[0];
	}

	int notTake = 0 + solve1(index-1, rodLength, price);
	int take = INT_MIN;

	// `index + 1` represents the current rod length we are trying to cut.
	// The condition `if (index + 1 <= rodLength)` checks whether we can make this cut.  
	// If the remaining rod length is less than `index + 1`, it is impossible to cut the rod further.  
	// For example, if the rod length is 5 and we attempt to cut a piece of length 6, it is not possible.  
	// Therefore, we can only proceed with the cut if `index + 1` is less than or equal to `rodLength`.  
	if (index + 1 <= rodLength) {
		take = price[index] + solve1(index, rodLength - (index + 1), price);
	}
	return max(take, notTake);
}
int cutRod1(vector<int> &price){
    // Time complexity: O(2^N)
    // Space complexity: O(N)

    // length of rod
	int rodLength = price.size();

    // (rodLength-1) represent current rod length. We start from rodLength-1 and go upto 0 in recursion.
	return solve1(rodLength-1, rodLength, price);
}



// Memoization-----------------------------------------------------------------------
int solve2(int index, int rodLength, vector<int> &price, vector<vector<int>>&dp){
	if (index == 0) {
		return rodLength * price[0];
	}
	int notTake = 0 + solve2(index-1, rodLength, price, dp);
	int take = INT_MIN;

	if(dp[index][rodLength] != -1) return dp[index][rodLength];

	if (index + 1 <= rodLength) {
		take = price[index] + solve2(index, rodLength - (index + 1), price, dp);
	}
	return dp[index][rodLength] = max(take, notTake);
}
int cutRod2(vector<int> &price){
    // Time complexity: O(N*rodLength)
    // Space complexity: O(N) + O(N*rodLength)

	int rodLength = price.size();
	vector<vector<int>>dp(rodLength, vector<int>(rodLength+1, -1));
	return solve2(rodLength-1, rodLength, price, dp);
}



// Tabulation-----------------------------------------------------------------------
int cutRod3(vector<int> &price){
    // Time complexity: O(N*rodLength)
    // Space complexity: O(N*rodLength)

	int rodLength = price.size();

	vector<vector<int>>dp(rodLength, vector<int>(rodLength+1, 0));

	// Base case - index represent current rod length
	for(int currentRodLength=0; currentRodLength <= rodLength; currentRodLength++){
		dp[0][currentRodLength] = currentRodLength * price[0];
	}

	for(int cut=1; cut<rodLength; cut++){
		// index represent current rod length
		for(int currentRodLength = 0 ; currentRodLength <= rodLength; currentRodLength++){

			int notTake = 0 + dp[cut-1][currentRodLength];

			int take = INT_MIN;

			// if current cut is less than total rod length i.e cur
			if (cut + 1 <= currentRodLength) {
				take = price[cut] + dp[cut][currentRodLength - (cut+1)];
			}

			dp[cut][currentRodLength] = max(take, notTake);
		}
	}
	return dp[rodLength-1][rodLength];
}



// Space optimization---------------------------------------------------------------
int cutRod4(vector<int> &price){
    // Time complexity: O(N*rodLength)
    // Space complexity: O(rodLength)

	int rodLength = price.size();

	vector<int>prev(rodLength+1,0);

	// Base case - index represent current rod length
	for(int currentRodLength=0; currentRodLength <= rodLength; currentRodLength++){
		prev[currentRodLength] = currentRodLength * price[0];
	}

	for(int cut=1; cut<rodLength; cut++){
		vector<int>curr(rodLength+1,0);
		// index represent current rod length
		for(int currentRodLength = 0 ; currentRodLength <= rodLength; currentRodLength++){

			int notTake = 0 + prev[currentRodLength];

			int take = INT_MIN;

			// if current cut is less than total rod length i.e cur
			if (cut + 1 <= currentRodLength) {
				take = price[cut] + curr[currentRodLength - (cut+1)];
			}

			curr[currentRodLength] = max(take, notTake);
		}
		prev=curr;
	}
	return prev[rodLength];
}




int main(){
    vector<int>price={1, 5, 8, 9, 10, 17, 17, 20};

    // Recursion
    cout<<cutRod1(price)<<endl;

    // Memoiazation
    cout<<cutRod2(price)<<endl;

    // Taulation
    cout<<cutRod3(price)<<endl;

    // Space optimmization
    cout<<cutRod4(price)<<endl;
}

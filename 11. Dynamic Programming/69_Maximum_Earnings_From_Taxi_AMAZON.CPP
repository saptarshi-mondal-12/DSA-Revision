#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* q. Maximum Earnings From Taxi - AMAZON / MEESHO

There are n points on a road you are driving your taxi on. The n points on the road are labeled from 1 to n in the direction you are going, and you want to drive from point 1 to point n to make money by picking up passengers. You cannot change the direction of the taxi.

The passengers are represented by a 0-indexed 2D integer array rides, where rides[i] = [starti, endi, tipi] denotes the ith passenger requesting a ride from point starti to point endi who is willing to give a tipi dollar tip.

For each passenger i you pick up, you earn endi - starti + tipi dollars. You may only drive at most one passenger at a time.
Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.

Note: You may drop off a passenger and pick up a different passenger at the same point.


Input: n = 5, rides = [[2,5,4],[1,5,1]]
Output: 7
Explanation: We can pick up passenger 0 to earn 5 - 2 + 4 = 7 dollars.

Input: n = 20, rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
Output: 20
Explanation: We will pick up the following passengers:
- Drive passenger 1 from point 3 to point 10 for a profit of 10 - 3 + 2 = 9 dollars.
- Drive passenger 2 from point 10 to point 12 for a profit of 12 - 10 + 3 = 5 dollars.
- Drive passenger 5 from point 13 to point 18 for a profit of 18 - 13 + 1 = 6 dollars.
We earn 9 + 5 + 6 = 20 dollars in total.
 
*/

class Solution {
public:
    long long solve1(int i, int end, int n, vector<vector<int>>& rides){
        // Base case 
        if(i >= rides.size()) return 0;

        int s = rides[i][0];
        int e = rides[i][1];
        int t = rides[i][2];

        // take current ride
        long long take = 0;
        if(s>=end){
            take += (abs(e-s) + t) + solve1(i+1, e, n, rides);
        }
        long long notTake = solve1(i + 1, end, n, rides);

        return max(take, notTake);
    }

    long long solve2(int i, int end, int n, vector<vector<int>>& rides, vector<vector<long long>>& dp) {

        if (i >= rides.size())
            return 0;

        if (dp[i][end] != -1)
            return dp[i][end];

        int s = rides[i][0];
        int e = rides[i][1];
        int tip = rides[i][2];

        long long take = 0;

        if (s >= end) {
            take = (e - s + tip) + solve2(i + 1, e, n, rides, dp);
        }

        long long notTake = solve2(i + 1, end, n, rides, dp);

        return dp[i][end] = max(take, notTake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // Recursion soln - O(2^n) ----------------------------------------
        // long long result = 0;
        // sort(rides.begin(), rides.end());
        // int end = 0;
        // result = solve1(0, end, n, rides);
        // return result;



        // Memoization soln -------------------------------------------------
        // sort(rides.begin(), rides.end());
        // vector<vector<long long>> dp(rides.size(),vector<long long>(n + 1, -1));
        // return solve2(0, 0, n, rides, dp);



        // Tabulation --------------------------------------------------------
        // Time complexity O(m log m)

        sort(rides.begin(), rides.end());

        int m = rides.size();
        vector<long long> dp(m + 1, 0);

        // Store all ride start times for binary search
        vector<int> starts;
        for (auto &ride : rides)
            starts.push_back(ride[0]);

        for (int i = m - 1; i >= 0; i--) {
            int s = rides[i][0];
            int e = rides[i][1];
            int tip = rides[i][2];

            // Find the next ride that starts at or after 'e'
            int next = lower_bound(starts.begin(), starts.end(), e) - starts.begin();

            long long take = (e - s + tip) + dp[next];
            long long notTake = dp[i + 1];

            dp[i] = max(take, notTake);
        }
        return dp[0];
    }
};

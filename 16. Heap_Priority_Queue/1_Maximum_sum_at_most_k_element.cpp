#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
Q. Maximum Sum With at Most K Elements

You are given a 2D integer matrix grid of size n x m, an integer array limits of length n, and an integer k. The task is to find the maximum sum of at most k elements from the matrix grid such that:
The number of elements taken from the ith row of grid does not exceed limits[i].
Return the maximum sum.

Input: grid = [[1,2],[3,4]], limits = [1,2], k = 2
Output: 7
Explanation:From the second row, we can take at most 2 elements. The elements taken are 4 and 3. The maximum possible sum of at most 2 selected elements is 4 + 3 = 7.


Input: grid = [[5,3,7],[8,2,6]], limits = [2,2], k = 3
Output: 21
Explanation:From the first row, we can take at most 2 elements. The element taken is 7. From the second row, we can take at most 2 elements. The elements taken are 8 and 6. The maximum possible sum of at most 3 selected elements is 7 + 8 + 6 = 21.
*/

long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    int n=grid.size();
    int m=grid[0].size();

    priority_queue<int>pq;

    for(int i=0; i<n; i++){
        vector<int>element;;
        for(int j=0; j<m; j++){
            int val=grid[i][j];
            element.push_back(val);
        }

        sort(element.begin(), element.end(), greater<>());

        for(int j=0; j<limits[i]; j++){
            int val=element[j];
            pq.push(val);
        }
    }

    long long int  result=0;
    while(!pq.empty() && k > 0){
        int val=pq.top();
        result+=val;
        pq.pop();
        k-=1;
    }

    return result;
}

int main(){
    vector<vector<int>>grid = {{5,3,7},{8,2,6}};
    vector<int>limits={2,2};
    int k = 3;
    cout<<maxSum(grid, limits, k);

}


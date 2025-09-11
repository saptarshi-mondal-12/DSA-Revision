#include <bits/stdc++.h>
using namespace std;

/* Q. Jump Game IV - AMAZON

Given an array of integers arr, you are initially positioned at the first index of the array.
In one step you can jump from index i to index:
    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.

Return the minimum number of steps to reach the last index of the array.
Notice that you can not jump outside of the array at any time.

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You do not need to jump.

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.

*/


// Brute ------------------------------------------------------------
int solve(int index, vector<int> &arr, vector<int> &visited){
    int n = arr.size();

    // Base case: reached last index
    if (index == n - 1)
        return 0;

    // If already visited, avoid infinite recursion
    if (visited[index])
        return 1e9;
    visited[index] = 1;

    int ans = INT_MAX;

    // 1. Move to index+1
    if (index + 1 < n){
        ans = min(ans, 1 + solve(index + 1, arr, visited));
    }

    // 2. Move to index-1
    if (index - 1 >= 0){
        ans = min(ans, 1 + solve(index - 1, arr, visited));
    }

    // 3. Move to any j where arr[j] == arr[index] and j != index
    for (int j = 0; j < n; j++){
        if (j != index && arr[j] == arr[index]){
            ans = min(ans, 1 + solve(j, arr, visited));
        }
    }

    visited[index] = 0; // backtrack
    return ans;
}
int brute_minJumps(vector<int> &arr){
    // Time complexity: O(3^n) Exponential
    // space complexity: O(n)

    int n = arr.size();

    if(n==1) return 0;

    vector<int> visited(n, 0);
    int result = solve(0, arr, visited);
    return result;
}



// optimal ----------------------------------------------------------
int optimal_minJumps(vector<int> &arr){
    // to be implemented
}





int main(){
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    // brute force
    // int result = brute_minJumps(arr);

    // Optimal solution
    int result = optimal_minJumps(arr);



    cout << "Minimum jumps to reach the last index: " << result << endl;
}
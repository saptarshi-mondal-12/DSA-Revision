#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Longest common subarray 

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].


Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].


Intuition: Same code as Q.28---------------------------------------------------
*/


// Tabulation-----------------------------------------------------
int findLength3(vector<int>& s1, vector<int>& s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    int ans=0;
    int coordinate_x=-1, coordinate_y=-1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > ans){
                    ans = dp[i][j];
                    coordinate_x=i;
                    coordinate_y=j;
                }
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    /* 
    Q. Print the longest common substring.
    Intuition: store the coordinate(i,j) of maximum using dp table. 
    To print the string, move to diagonal only coordinate(i,j) ---> (top left corner side) and then reverse the string.    
    */

    int i = coordinate_x;
    int j = coordinate_y;
    vector<int>printResult;
    while (i > 0 && j > 0){
        printResult.push_back(s2[j-1]); 
        i--;
        j--;
    }
    reverse(printResult.begin(), printResult.end());
    cout<<"Longest Common Subarray: ";
    for(auto it: printResult){
        cout<<it<<" ";
    }
    cout<<endl;
    return ans;
}


// Space optimize-------------------------------------------------
int findLength4(vector<int>& s1, vector<int>& s2) {
    int n = s1.size();
    int m = s2.size();

    vector<int>prev(m+1, 0);

    int ans=0;
    for (int i = 1; i <= n; i++) {
        vector<int>curr(m+1, 0);
        for (int j = 1; j <= m; j++){
            if (s1[i-1] == s2[j-1]) {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
            else {
                curr[j] = 0;
            }
        }
        prev=curr;
    }
    return ans;
}

int main(){
    vector<int>s1={1,2,3,2,1};
    vector<int>s2={3,2,1,4,7};


    // Tabulation
    cout<<findLength3(s1,s2)<<endl;


    // Space optimize
    cout<<findLength4(s1,s2)<<endl;
}




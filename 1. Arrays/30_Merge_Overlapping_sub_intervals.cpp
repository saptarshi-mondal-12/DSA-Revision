#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Merge Overlapping Sub-intervals 
Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
intervals.
*/

vector<vector<int>> brute_mergeOverlappingIntervals(vector<vector<int>> &arr){
    // Time complexity - O(n log n) + O(2n)
    // space complexity - O(n)

    int n=arr.size(); 

    sort(arr.begin(),arr.end());

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];

        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }

        for(int j=i+1;j<n;j++){
            if(arr[j][0] <=end){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;

}

vector<vector<int>> optimal_mergeOverlappingIntervals(vector<vector<int>> &arr){
    // Time complexity - O(n log n) + O(n)
    // space complexity - O(n)

    int n=arr.size();

    // sort the given intervals:
    sort(arr.begin(),arr.end());

    vector<vector<int>> ans;

    for(int i=0;i<n;i++){

        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);

        }else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }
    }
    return ans;

}


int main(){
    vector<vector<int>>arr={{1,3},{2,6},{8,10},{15,18}};
    
    // 1. brute
    // vector<vector<int>> ans = brute_mergeOverlappingIntervals(arr);


    // 2. Optimal
    vector<vector<int>> ans = optimal_mergeOverlappingIntervals(arr);


    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

}
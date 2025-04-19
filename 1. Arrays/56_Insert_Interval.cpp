#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Intuition:
Step 1: Insert new interval using binary search 
Step 2: Use code of merger overlapping intervals solution

*/

vector<vector<int>> insert(vector<vector<int>> intervals, vector<int> newInterval){
    // If the intervals vector is empty, return a vector containing thenewInterval
    if (intervals.empty()){
        return {newInterval};
    }

    int n = intervals.size();
    int target = newInterval[0];
    int left = 0, right = n - 1;

    // Binary search to find the position to insert newInterval
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (intervals[mid][0] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    // Insert newInterval at the found position
    intervals.insert(intervals.begin() + left, newInterval);

    // using Merge overlapping intervals
    vector<vector<int>> result;

    // Increase length of intervals because we insert a newInterval
    n += 1;
    for (int i = 0; i < n; i++){
        if (result.empty() || intervals[i][0] > result.back()[1]){
            result.push_back(intervals[i]);
        }
        else{
            result.back()[1] = max(result.back()[1], intervals[i][1]);
        }
    }
    return result;
}

int main(){
    vector<vector<int>>intervals={{1,3},{6,9}};
    vector<int>newInterval={2,5};
    
    vector<vector<int>> ans = insert(intervals, newInterval);


    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

}
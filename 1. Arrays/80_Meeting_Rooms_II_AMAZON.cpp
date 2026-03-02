#include <bits/stdc++.h>
using namespace std;

/* Q. Meeting Rooms II - AMAZON 2026

Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Return the minimum number of rooms required to attend all meetings.

Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.

Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
Output: 1
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.

Input: start[] = [2, 9, 6], end[] = [4, 12, 10]
Output: 2
Explanation: 1st and 2nd meetings at one room but for 3rd meeting one another room required.*/

// brute Soln --------------------------------------------------------------

int minMeetingRooms(vector<int> &start, vector<int> &end) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)

    // Intuition: The idea is to go through each meeting's start and end times, comparing them with every other meeting to identify any overlap. In other words, for each meeting, we assess how many other meetings are taking place in the room at the same time and maximum among all these meeting will be our required answer.

    int n = start.size();

    int room = 1, res = 1;
        
    // Run a nested for-loop to find the overlap
    for (int i = 0; i < n; i++) {
    
        // Initially one room is needed
        room = 1;
        for (int j = 0; j < n; j++) {
            if (i != j){
                // Increment room when there is an overlap
                if (start[i] >= start[j] && end[j] > start[i]){ // means, Meeting j started before i, and is still running when i starts.
                    room++;
                }
            }
        }
    
        // Update the result
        res = max(room, res);
    }
    return res;
}

// Optimal soln ------------------------------------------------------------
int minMeetingRooms(vector<int> &start, vector<int> &end){
    // Time complexity: O(nlogn) + O(nlogn) + O(n) ~ O(nlogn)
    // Space complexity: O(1)

    /* Intuition: The Idea is to use sorting and two-pointer technique to reduce the time complexity. First, we sort the start and end time arrays of all meetings. Then, using two pointers, we traverse through both arrays to find minimum rooms required.

    In this approach, we aim to determine the number of rooms required at any given point in time. These points correspond to the start and end times of the meetings.
    
    Whenever we encounter the start time of a meeting, we increase the room count. Similarly, when we encounter the end time of a meeting, we decrease the room count. The maximum value of the room count at any point during this process represents the minimum number of rooms needed to host all the meetings.*/

    int n = start.size();

    // sorting the start and end time of meetings
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    // {2,6,9}
    // {4,10,12}

    int result = 0;
    int room = 0;
    int i = 0, j = 0;

    while (i < n){
        // encountered start time of meeting.
        if (start[i] < end[j]){
            room++;
            i++;
        }

        // encountered end time of meeting.
        else{
            room--;
            j++;
        }
        result = max(result, room);
    }

    return result;
}

int main(){
}
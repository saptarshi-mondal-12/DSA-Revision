#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Meeting rooms - Find minimum meeting rooms 

Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. Task is to find minimum number of rooms required to attend all meetings.

Note: A person can also attend a meeting if it's starting time is same as the previous meeting's ending time.


Input: start[] = [1, 10, 7], end[] = [4, 15, 10]
Output: 1
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings in a single room.

Input: start[] = [2, 9, 6], end[] = [4, 12, 10]
Output: 2
Explanation: 1st and 2nd meetings can be attended at one room but for 3rd meeting another room is required.

*/


int brute_getMinimumRooms(vector<int>&start, vector<int>&end){
    // Time complexity: O(n^2)
    // Space complexity: O(1)

    /* The idea  is to go through each meeting's start and end times, comparing them with every other meeting to identify any overlap. In other words, for each meeting, we assess how many other meetings are taking place in the room at the same time and maximum among all these meeting will be our required answer.
    */

    int n=start.size();
    int result=0;

    for(int i=0;i<n;i++){
        int room=1;
        for(int j=0;j<n;j++){

            if(i!=j){
                // Increment room when there is an overlap
                if (start[i] >= start[j] && end[j]>start[i]){
                    room++;
                }
            }
        }
        result=max(result, room);
    }
    return result;
}



int optimal_getMinimumRooms(vector<int>&start, vector<int>&end){
    // Time complexity: O(n * log n)
    // Space complexity: O(1)

    /* The Idea is to use sorting and two-pointer technique to reduce the time complexity. First, we sort the start and end time arrays of all meetings. Then, using two pointers, we traverse through both arrays to find minimum rooms required.

    Whenever we encounter the start time of a meeting, we increase the room count. Similarly, when we encounter the end time of a meeting, we decrease the room count. The maximum value of the room count at any point during this process represents the minimum number of rooms needed to host all the meetings.
    */


    int n=start.size();

    // sorting the start and end time of meetings
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    // {2,6,9}
    // {4,10,12}


    int result=0;
    int room=0;
    int i=0, j=0;

    while(i<n){
        // encountered start time of meeting.
        if(start[i] < end[j]){
            room++;
            i++;
        }

        // encountered end time of meeting.
        else{
            room--;
            j++;

        }
        result=max(result, room);
    }

    return result;
}

int main(){
    // vector<int>start={1,10,7};
    // vector<int>end={4,15,10};

    // vector<int>start={2,9,6};
    // vector<int>end={4,12,10};

    // vector<int>start={0,5,15};
    // vector<int>end={30,10,20};

    vector<int>start={7,2};
    vector<int>end={10,4};

    // brute soln
    cout<<brute_getMinimumRooms(start,end)<<endl;

    // optimal soln
    cout<<optimal_getMinimumRooms(start,end);
}
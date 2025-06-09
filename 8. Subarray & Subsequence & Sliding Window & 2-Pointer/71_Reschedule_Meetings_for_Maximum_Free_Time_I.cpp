#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Reschedule Meetings for Maximum Free Time I

You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.

The relative order of all the meetings should stay the same and they should remain non-overlapping.

Return the maximum amount of free time possible after rearranging the meetings.

Note that the meetings can not be rescheduled to a time outside the event.



Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
Output: 2
Explanation: Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].


Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]
Output: 6
Explanation: Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during the time [3, 9].


Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]
Output: 0
Explanation: There is no time during the event not occupied by meetings.




Hint:
In a sequence of K meetings and K + 1 gaps, you could move all meetings to the start of the sequence to get the max free time.
Use a sliding window of K + 1 size to store sum of gaps and take the maximum.


----------------------------------------------------------------------------------------

Intuition:
The problem requires us to maximize the longest continuous free time by rescheduling at most k meetings.
Since we are modifying at most k meetings, we are allowed to merge at most k + 1 gaps into a single continuous period.

Approach:
If we can shift up to k meetings, then we can combine up to k + 1 gaps.
This means we are looking for the largest contiguous segment of k + 1 gaps (Since order of meetings should be preserved).

To efficiently find the maximum sum of any contiguous segment of k + 1 gaps, we can use prefix sum or a sliding window.

Complexity:
Time Complexity: O(n)
Space Complexity: O(n)
*/

int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime){
    int n = startTime.size();

    // n+1 because for n meeting there are n+1 gaps
    vector<int> gaps(n + 1);

    // calculating first and last gap seperately
    gaps[0] = startTime[0];
    gaps[n] = eventTime - endTime[n - 1];

    // calculating gaps between meetings
    for (int i = 1; i < n; i++){
        gaps[i] = startTime[i] - endTime[i - 1];
    }

    // using sliding window of K + 1 size to store sum of gaps and take the maximum.
    int currSum = 0;
    for (int i = 0; i < k + 1; i++){
        currSum += gaps[i]; // sum of first k+1 gaps
    }

    int maxi = currSum;
    int left = 0;
    int right = k + 1;
    while (right < gaps.size()){
        // add from right
        currSum += gaps[right];

        // remove from left
        currSum -= gaps[left];

        maxi = max(maxi, currSum);

        left++;
        right++;
    }

    return maxi;
}
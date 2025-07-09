#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum Number of Events That Can Be Attended

You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi. You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.


Example 1:


-------|
        -----------|
                    ------------|
                                 ------------|



-------|------------|------------|------------|----------|
    Day 1         Day 2        Day 3        Day 4


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.


Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
*/

int maxEvents(vector<vector<int>> &events){
    int n = events.size();
    int result = 0;

    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<>> pq;

    int maxDay = 0;
    for (int i = 0; i < events.size(); i++){
        maxDay = max(maxDay, events[i][1]);
    }

    int i = 0;
    for (int day = 1; day <= maxDay; day++){
        // Add all events starting today
        while (i < n && events[i][0] <= day){
            pq.push(events[i][1]); // store endDay
            i++;
        }

        // Remove expiry events
        while (!pq.empty() && pq.top() < day){
            pq.pop();
        }

        // Attend the event that ends earliest
        if (!pq.empty()){
            pq.pop();
            result++;
        }
    }
    return result;
}

int main(){
    vector<vector<int>>events={{1,2},{2,3},{3,4}};
    cout<<maxEvents(events);

}
#include <bits/stdc++.h>
using namespace std;

/* Q. Max bandwidth at any given time - AMAZON 2026 - similar as Meeting Rooms II

Given a list of shows (StartTime, EndTime, Bandwidth), find the maximum bandwidth required at any given time

We have input of startTime, endTime and bandwidth consumed. like

1234  5678   12
2345  6789   10
7900  8790   20
6790  8123   8

We have to calculate max bandwithd consumed. Like for above it will be 28 from input set {7900 8790}{6790 8123} since these sets has intersection


Explanation:
------------
Make pairs

{t; v} 
where 
t=time
v = +bandwidth for start of interval or 
    -bandwidth for end of interval
Sort list of these pair by time (in case of tie +first).

1234; 12
5678; -12
2345; 10
6789;  -10
7900; 20
8790;- 20
6790; 8
8123; -8
Walk through this list, adding v to the current bandwidth value. Maximal reached value is what you need

1234; 12     : 12
2345; 10     : 22
5678; -12    : 10
6789;  -10   : 0
6790; 8      : 8
7900; 20     : 28
8123; -8     : 20
8790;- 20    : 0

*/


int maxBandwidth(vector<vector<int>>& shows) {
    vector<pair<int, int>> events;

    for (auto& s : shows) {
        int start = s[0], end = s[1], bw = s[2];
        events.push_back({start, bw});   // start event
        events.push_back({end, -bw});    // end event
    }

    sort(events.begin(), events.end());

    int current = 0, maxBW = 0;

    for (auto& e : events) {
        current += e.second;
        maxBW = max(maxBW, current);
    }

    return maxBW;
}


int main(){
    vector<vector<int>> shows = {
        {1234, 5678, 12},
        {2345, 6789, 100},
        {7900, 8790, 20},
        {6790, 8123, 8}
    }; 

    // GOOD APPROACH
    cout << maxBandwidth(shows)<<endl;  
}
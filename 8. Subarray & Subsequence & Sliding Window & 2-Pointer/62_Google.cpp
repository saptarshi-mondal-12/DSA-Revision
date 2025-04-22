#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Maximum frequency subarray

The organizers of a gaming tournament want to analyze player participation based on event logs. There are n event logs, where arr[i] indicates the playerId of the player who participated in the ith event. The organizers need to identify subarrays of these logs that are consistent, meaning that the frequency of the most frequent player in the subarray matches the frequency of the least frequent player in the entire array. Determine the maximum length of such consistent logs.

n = 10
arr = [1, 2, 1, 3, 4, 2, 4, 3, 3, 4]
The frequencies of playerIds 1 and 2 are 2.
The frequencies of playerIds 3 and 4 are 3.

The minimum frequency in the array is 2.
The longest valid subarray with this property is [1, 2, 1, 3, 4, 2, 4, 3], which has 8 elements. In this subarray, the most common element appears 2 times, which matches the minimum frequency in the entire array. Therefore, the maximum length of consistent logs is 8.


--- The most frequent element in that subarray appears exactly minFreq times.
--- minFreq is the minimum frequency of any player in the entire array.
*/


int findConsistentLogs(std::vector<int>& arr) {
    int n = arr.size();

    // Step 1: Find global minimum frequency
    unordered_map<int, int> totalFreq;
    for (int id : arr) {
        totalFreq[id]++;
    }

    int minFreq = INT_MAX;
    for (auto& p : totalFreq) {
        minFreq = min(minFreq, p.second);
    }

    // Step 2: Sliding window to find max length subarray
    unordered_map<int, int> windowFreq;
    int maxLen = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        windowFreq[arr[right]]++;

        // Determine max frequency in current window
        int localMaxFreq = 0;
        for (auto& p : windowFreq) {
            localMaxFreq = max(localMaxFreq, p.second);
        }

        // Shrink window if not valid
        while (localMaxFreq > minFreq) {
            windowFreq[arr[left]]--;
            if (windowFreq[arr[left]] == 0)
                windowFreq.erase(arr[left]);
            left++;

            localMaxFreq = 0;
            for (auto& p : windowFreq) {
                localMaxFreq = max(localMaxFreq, p.second);
            }
        }

        if (localMaxFreq == minFreq) {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1,1,2,2,2,3,3,3,3,4,4,4,4,4};
    cout << findConsistentLogs(arr) << endl; // Output: 8
}


#include <iostream>
#include <bits/stdc++.h>
using namespace std;





int maxPopulation(vector<int>& population, string& unit) {
    int n = population.size();
    int ans = 0;

    int i = 0;
    while (i < n) {
        // skip '0's
        if (unit[i] == '0') {
            i++;
            continue;
        }

        // finding start and end of '1's segment
        int l = i;
        while (i < n && unit[i] == '1'){
            i++;
        }
        int r = i - 1;

        // Total no of 1's in this segment
        int k = r - l + 1;

        // shifting window to include one '0' on left if possible
        int start = max(0, l - 1);
        int end = r;

        // Add all population values in the window to a candidate list
        vector<int> cand;
        for (int j = start; j <= end; j++) {
            cand.push_back(population[j]);
        }

        // Sort candidate list in descending order and pick top k values
        sort(cand.begin(), cand.end(), greater<int>());

        // Pick top k values from candidate list and add it final answer
        for (int t = 0; t < k; t++) {
            ans += cand[t];
        }
    }

    return ans;
}


int main(){
    vector<int>nums = {20, 10, 9, 30, 20, 19};
    string s = "000000";
    cout<<maxPopulation(nums, s);
}
#include <bits/stdc++.h>
using namespace std;

/* Q. Given an array and an integer T, find the minimum length subarray that contains all its distinct elements at least T times.

Input: arr = [1,2,2,3,1,2,1,3], T = 2
Output: 6

*/

int minimumLengthSubarray(vector<int>& nums, int T) {
    int n = nums.size();
    if (n == 0) return 0;

    // Count distinct elements
    unordered_set<int> st(nums.begin(), nums.end());
    int k = st.size();

    unordered_map<int, int> mp;
    int left = 0;
    int countAtLeastT = 0;
    int result = INT_MAX;

    for (int right = 0; right < n; right++) {
        mp[nums[right]]++;

        if (mp[nums[right]] == T) {
            countAtLeastT++;
        }

        // Shrink window while valid
        while (countAtLeastT == k) {
            result = min(result, right - left + 1);

            mp[nums[left]]--;
            if (mp[nums[left]] == T - 1) {
                countAtLeastT--;
            }
            left++;
        }
    }

    return (result == INT_MAX) ? 0 : result;
}

int main(){
    vector<int> arr = {1,2,2,3,1,2,1,3};
    int T = 2;

    int result = minimumLengthSubarray(arr, T);
    cout << "Minimum length subarray: " << result << endl;
}
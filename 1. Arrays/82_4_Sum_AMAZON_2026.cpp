#include <bits/stdc++.h>
using namespace std;

vector<int> fourSum(vector<int>& arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long sum = 1LL * arr[i] + arr[j]
                                  + arr[k] + arr[l];

                    if (sum == target) {
                        return {arr[i], arr[j], arr[k], arr[l]};
                    }
                }
            }
        }
    }

    return {};
}

int main() {
    vector<int> arr = {4, 7, 12, 1, 6, 5, 2};
    int target = 16;

    vector<int> ans = fourSum(arr, target);

    if (ans.empty()) {
        cout << "No solution found";
    } else {
        for (int x : ans) cout << x << " ";
    }

    return 0;
}
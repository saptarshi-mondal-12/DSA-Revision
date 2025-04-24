#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Shortest Subarray with Sum at Least K 

Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

Input: nums = [1], k = 1
Output: 1

Input: nums = [1,2], k = 4
Output: -1

Input: nums = [2,-1,2], k = 3
Output: 3



------------------------------------------------------------------------------------
nums = [84, -37, 32, 40, 95]
k = 167

✅ Step 1: Build Prefix Sum Array
We construct a prefix array of size n + 1 = 6, where:
prefix[0] = 0
prefix[1] = prefix[0] + nums[0] = 0 + 84 = 84
prefix[2] = prefix[1] + nums[1] = 84 - 37 = 47
prefix[3] = prefix[2] + nums[2] = 47 + 32 = 79
prefix[4] = prefix[3] + nums[3] = 79 + 40 = 119
prefix[5] = prefix[4] + nums[4] = 119 + 95 = 214

Final prefix sum array:
prefix = [0, 84, 47, 79, 119, 214]
index     0   1   2   3    4    5


✅ Step 2: Initialize
deque dq = {}
result = n + 1 = 6 (we will minimize this)

🔁 Step 3: Loop from i = 0 to 5

▶ i = 0
    prefix[0] = 0
    Deque is empty.
    Push 0 to deque
    dq = [0]

▶ i = 1
    prefix[1] = 84
    Check prefix[1] - prefix[dq.front()] = 84 - 0 = 84 < k → Not valid
    Maintain monotonicity: prefix[1] > prefix[0], OK
    Push 1 to deque
    dq = [0, 1]

▶ i = 2
    prefix[2] = 47
    47 - 0 = 47 < k
    Maintain monotonicity: prefix[2] < prefix[1] = 84, pop 1
    Also prefix[2] < prefix[0] = 0 → No, so stop
    Push 2 to deque
    dq = [0, 2]

▶ i = 3
    prefix[3] = 79
    79 - 0 = 79 < k
    Maintain monotonicity: 79 > 47 → OK
    Push 3 to deque
    dq = [0, 2, 3]

▶ i = 4
    prefix[4] = 119
    119 - 0 = 119 < k
    Maintain monotonicity: 119 > 79 → OK
    Push 4 to deque
    dq = [0, 2, 3, 4]

▶ i = 5
    prefix[5] = 214
    Check prefix[5] - prefix[dq.front()] = 214 - 0 = 214 >= 167 ✅

Valid subarray found: index range [dq.front(), i-1] = [0, 4] → length = 5 - 0 = 5
    Update result = min(result, 5) = 5
    Pop front (0)
    dq = [2, 3, 4]

Now check again:
    214 - 47 = 167 ✅ → Valid
    Length = 5 - 2 = 3 → result = min(5, 3) = 3
    Pop front (2)
    dq = [3, 4]

Check again:
    214 - 79 = 135 < 167 ❌ → Stop
    Maintain monotonicity: 214 > 119 → OK
    Push 5 to deque
    dq = [3, 4, 5]

✅ Final Answer: result = 3  Subarray: [32, 40, 95] → sum = 167

*/

int brute_shortestSubarray(vector<int>nums, int k) {
    // Time complexity: O(n^2)
    // Space complexity: O(1)

    int n = nums.size();
    int result = INT_MAX;

    for (int i = 0; i < n; ++i) {
        int total = 0;
        for (int j = i; j < n; ++j) {
            total += nums[j];
            if (total >= k) {
                result = min(result, j - i + 1);
                // if it is atleast k we will break the loop because we need minimum subarray with sum atleast k
                break;
            }
        }
    }
    if (result == INT_MAX) {
        return -1;
    }
    return result;
}


int optimal_shortestSubarray(vector<int>nums, int k) {
    // Time complexity: O(n)
    // Space complexity: O(n)

    int n = nums.size();

    vector<long long> prefix(n + 1, 0);  // prefix[0] = 0
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // (we will minimize this)
    int result = INT_MAX ;
    deque<int> dq;

    for (int i = 0; i <= n; ++i) {
        // Check if current subarray sum is >= k
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            result = min(result, i - dq.front());
            dq.pop_front();
        }

        // Maintain monotonic increasing order of prefix values
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }
    
    if(result==INT_MAX){
        return -1;
    }
    return result;
}



int main(){
    vector<int>nums={2,-1,2};
    int k=3;
    cout<<brute_shortestSubarray(nums, k)<<endl;
    cout<<optimal_shortestSubarray(nums, k)<<endl;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Four number equal to target - AMAZON 2026

Given an array of integers, find four element whose sum equals the target value.

Input: nums = [4,7,12,1,6,5,2], target = 16
Output: [7,1,6,2]]

*/

vector<int> brute_solve(vector<int>& nums, int target){
    // Time complexity: O(n^4)
    // Space complexity: O(1)
    vector<int> ans;
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target){
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[k]);
                        ans.push_back(nums[l]);
                        return ans;
                    }
                }
            }
        }
    }
    return ans;
}

vector<int> better_solve(vector<int>& nums, int target){
    // Time complexity: O(n^3)
    // Space complexity: O(1)

    // Intuition : Fix two elements and use two pointers for the remaining two elements

    vector<int> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int left = j+1;
            int right = n-1;
            while(left < right){
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target){
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[left]);
                    ans.push_back(nums[right]);
                    return ans;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
    }
    return ans;
}

vector<int> optimal_solve(vector<int>& nums, int target){
    // Time complexity: O(n^2)
    // Space complexity: O(n^2)

    /* Intuition : Instead of checking all 4 element with nested loops, store the sums of pairs of elements in a hashmap. Then, for each pair of elements, check if the complement (target - sum of the pair) exists in the hashmap. If it does, we have found our four elements.

    1. Select a pair (j,k)
    2. claculate the required sum for the other two elements
    3. Looks for previously stored pairs with that sum.
    4. Ensure that all four indices are distinct by only storing pairs ending at index i after checking for complements.
    5. if a match is found, return the four elements.

    emplace() inserts only if the key doesn't already exist; operator[] assignment replaces the mapped value.
    */ 

    int n = nums.size();

    // {sum, {index1, index2}}
    unordered_map<long long, pair<int, int>> mp;

    for (int i = 0; i < n; i++) {
        // Find a complementary pair among previously stored pairs
        for (int j = i + 1; j < n; j++) {
            long long sum = (long long)nums[i] + nums[j];
            long long remaining = (long long)target - sum;

            auto it = mp.find(remaining);

            if (it != mp.end()) {
                int a = it->second.first;
                int b = it->second.second;
                return {nums[a], nums[b], nums[i], nums[j]};
            }
        }

        // Store pairs ending at i, after checking
        // so all four indices are distinct.
        for (int j = 0; j < i; j++) {
            long long sum = (long long)nums[j] + nums[i];
            mp.emplace(sum, make_pair(j, i));
        }
    }

    return {};
}


int main(){
    vector<int> nums = {4,7,12,1,6,5,2};
    int target = 16;

    // 1. Brute soln
    // vector<int>ans = brute_solve(nums, target);

    // 2. better soln
    // vector<int> ans = better_solve(nums, target);

    // 3. optimal soln
    vector<int> ans = optimal_solve(nums, target);


    for(auto it: ans){
        cout<<it<<" ";
    }

}
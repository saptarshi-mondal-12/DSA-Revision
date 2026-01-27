#include <bits/stdc++.h>
using namespace std;

/* Q. Find the minimum length subarray that contains all distinct elements of the array.

Input: arr[] = {1, 2, 2, 3, 1, 4, 2}
Output: 4
Explanation: The smallest subarray that contains all distinct elements is {3, 1, 4, 2}.

Input: arr[] = {1, 1, 1, 1}
Output: 1
Explanation: The smallest subarray that contains all distinct elements is {1}.

*/

int minLengthSubarrayWithAllDistinctElements(vector<int>& nums) {
    // Time complexity: O(n) + O(n) = O(n)
    // Space complexity: O(k) + O(k) = O(k)

    int n = nums.size();
    int result = n;

    if (n == 0) return 0;

    // 1. Find no of distinct element 
    int k = 0;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        int num = nums[i];
        if(st.find(num) == st.end()){
            st.insert(num);
            k++;
        }
    }

    // 2. minimum length subarray that contains all distinct elements 
    // i.e k distinct element 

    unordered_map<int,int>mp;
    int left = 0, right = 0;
    
    while(right < n){
        int num = nums[right];
        mp[num]++;

        while(mp[nums[left]] > 1){
            mp[nums[left]]--;
            left++;
        }


        if(mp.size() == k){
            result = min(result, right-left+1);
        }

        right++;
    }

    return result;
}

int main(){
    vector<int>nums = {1, 2, 1, 3, 2, 1};
    int result = minLengthSubarrayWithAllDistinctElements(nums);
    cout<<result<<endl;
}
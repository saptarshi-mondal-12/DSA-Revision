#include<bits/stdc++.h>
using namespace std;

/* Q. Find triplet from array having sum 0  - AMAZON 2025
we have to include duplicate also and we have to return all valid index in the form of vector

follow up ---------------------------------------------

Then he told me imagine that what if we have to start every loop from 0 ? How you solve it .

then he told ok now optimize code.

*/

// Brute ----------------------------------------------------------------------------
vector<vector<int>>findTripletsWithSum_Zero(vector<int>nums){
    // Time complexity: O(n^3)
    // Space complexity: O(1)

    int n = nums.size();
    vector<vector<int>>result;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    result.push_back({i,j,k});
                }
            }
        }
    }

    return result;
}



// Follow up question --------------------------------------------------------------
vector<vector<int>>findTripletsWithSum_Zero_FollowUpQuestion(vector<int>nums){
    // Time complexity: O(n^3)
    // Space complexity: O(1)

    /* If all loops start from 0, then we will revisit the same indices in different orders (like (i=0,j=1,k=2) and (i=1,j=0,k=2) → same triplet but different order). That causes duplicate results. */

    int n = nums.size();
    
    vector<vector<int>>result;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0 && i<j && j<k) {
                    result.push_back({i, j, k});
                }
            }
        }
    }

    return result;
}



// Optimal approach ----------------------------------------------------------------
vector<vector<int>>findTripletsWithSum_Zero_Optimal(vector<int>nums){
    // Time complexity: O(n log n) + O(n^2)
    // Space complexity: O(1)


    int n = nums.size();
    vector<vector<int>>result;

    // Sort the array
    sort(nums.begin(), nums.end());


    for (int i = 0; i < n; i++) {
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                // push original indices (not sorted positions)
                result.push_back({i, left, right});
                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return result;
}

int main(){
    vector<int>nums={-1, -2, -2, 0, 3, 3 };

    // 1. Brute force approach
    vector<vector<int>>result = findTripletsWithSum_Zero(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl;
    }

    cout<<"-----------------"<<endl;


    // 2. Follow up question
    vector<vector<int>>result1 = findTripletsWithSum_Zero_FollowUpQuestion(nums);

    for(int i=0;i<result1.size();i++){
        cout<<result1[i][0]<<" "<<result1[i][1]<<" "<<result1[i][2]<<endl;
    }


    cout<<"-----------------"<<endl;


    // 3. Optimized approach
    vector<vector<int>>result2 = findTripletsWithSum_Zero_Optimal(nums);

    for(int i=0;i<result2.size();i++){
        cout<<result2[i][0]<<" "<<result2[i][1]<<" "<<result2[i][2]<<endl;
    }
}
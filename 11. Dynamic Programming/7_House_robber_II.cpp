#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Q. House Robber II

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: nums = [1,2,3]
Output: 3


Intuition: same as house robber question but has some twist. 
For a circular street, the first and last house are adjacent, therefore one thing we know for sure is that the answer will not consider the first and last element simultaneously (as they are adjacent). (if we take it become adjacent and in question we cannot rob adjacent house). So we either take first and skip last or skip first and take last. We have to return maximum. 


we can say that maybe the last element is not considered in the answer. In that case, we can consider the first element. Let’s call this answer ans1. Hence we have reduced our array(arr- last element), say arr1, and found ans1 on it by using the article DP5 approach.

arr={1,2,3,4,5,6,7,8,9,10} 
    |----------------| last


Now, it can also happen that the final answer does consider the last element. If we consider the last element, we can’t consider the first element( again adjacent elements). We again use the same approach on our reduced array( arr - first element), say arr2. Let’s call the answer we get as ans2.

Now, the final answer can be either ans1 or ans2. As we have to return the maximum money robbed by the robber, we will return max(ans1, ans2) as our final answer.

arr={1,2,3,4,5,6,7,8,9,10} 
       |-----------------|

Approach : 
1. Make two reduced arrays temp1 & temp2. 
2. Add all element in temp1 skipping last element and add all element in temp2 skipping first element
3.Find the maximum of non-adjacent elements on arr1 and arr2 separately. Let’s call the answers we got ans1 and ans2 respectively.
Return max(ans1, ans2) as our final answer.
*/

int solve(vector<int>nums){
    int n=nums.size();
    int prev2=0;
    int prev=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i] + prev2;
        int notpick=prev;
        int curr_i=max(pick, notpick);
        prev2=prev;
        prev=curr_i;
    }
    return prev;
}
int rob(vector<int>& nums) {
    // Time complexity: O(n) + O(n) = O(n)
    // space compelxity: O(1)

    int n=nums.size();
    
    // if n==1 return nums[0]
    if (n==1){
        return nums[0];
    }

    // create 2 empty list
    vector<int>temp1, temp2;
    for(int i=0;i<n;i++){
        if(i!=0){
            temp1.push_back(nums[i]);
        }
        if(i!=n-1){
            temp2.push_back(nums[i]);
        }
    }

    // solve for maximum with a skip of first element
    int ans1=solve(temp1);
    // solve for maximum with a skip of last element
    int ans2=solve(temp2);

    // return maximum from both ans1 & ans2
    return max(ans1, ans2);
}


int main(){
    vector<int>nums={1,2,3,1};
    cout<<rob(nums)<<endl;
}


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Minimum Swaps to Group All 1's Together II

A swap is defined as taking two distinct positions in an array and swapping the values in them.
A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 
Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps. Thus, the minimum number of swaps required is 1.


Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps. Thus, the minimum number of swaps required is 2.

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array. Thus, the minimum number of swaps required is 0.
*/


/* Intuition
1st part 
totalOnes = no of 1's given in input
find the window of size totalOnes that contains maximum no of 1's 
0 1 1 0 0 1 1 0 0 1 1 0
          |---------|
totalOnes=6
window size = 6 
ans = 6 - 4 = 2 => totalOnes - totalOnesPresentInWindows -  (no of 0's present in window = 2 so we need minimum 2 swap )

2 part
for this type of input circular = [1,1,0,0,0,1,1] or [0,1,1,0] or [1,1,1,0,1]
ans= append same input to last 
eg. [1,1,0,0,1] = [1,1,0,0,1]+[1,1,0,0,1] = [1,1,0,0,1,1,1,0,0,1]
so totalOnes=3
window = 3 [1,1,0,0,1,1,1,0,0,1]
                    |---|
ans= totalOnes - totalOnesPresentInWindows => 3 - 3 = 0 (0 swap required)
*/


int minSwaps(vector<int>nums){
    int n=nums.size();
    int totalOnes=0;
    for(int i=0;i<n;i++){
        if(nums[i]==1){
            totalOnes+=1;
        }
    }

    int left=0;
    int right=0;
    int maxi=0;
    int windowsOnes=0;

    while(right < 2*n){
        if(nums[right%n]==1){
            windowsOnes+=1;
        }
        // if length of our window > totalOnes we need to shift our left pointer but before
        // shifting if nums[l]==1 we need to decrement windowOnes
        if(right-left+1 > totalOnes){
            if(nums[left%n]==1){
                windowsOnes-=1;
            }
            left+=1;
        }
        maxi=max(maxi,windowsOnes);
        right+=1;
    }
    return totalOnes-maxi;    
}

int main(){
    vector<int>nums={0,1,1,1,0,0,1,1,0};
    cout<<minSwaps(nums);
}




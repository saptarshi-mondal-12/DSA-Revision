#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Q. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

Input: nums = [10,9,2,5,3,7,101,18]
Output: [2,3,7,101]
Explanation: The longest increasing subsequence is [2,3,7,101]

Input: nums = [0,1,0,3,2,3]
Output: 4

Input: nums = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
Output: [0, 4, 6, 9, 13, 15] 
Explanation: longest Increasing subsequence is 0 4 6 9 13 15  and the length of the longest increasing subsequence is 6.



-------------Intuition: 

NOTE: All previous Q 43. solution won't help us to print the LIS. So We have to to write another solution to print the LIS.

dp[i] siginifies the longest increasing subsequence that ends at index i.

For ex. [5,4,11,1,16,8]

Q. what is the longest increasing subsequence that ends with 5?
Ans: the length is 1 definetely because before 5 i cannot have anyone.

Q. Similarly if i ask you what is the longest increasing subsequence that ends with 4?
Ans: 5 cannot be a part of it so length is 1. 

Q. Similarly if i ask you what is the longest increasing subsequence that ends with 11?
Ans: 5 can be a part of it (5,11) or 4 can be a part of it (4,11). So i can say it can have length of 2. 

Q. for 16 -> [5,11,16] or [4,11,16] length 3

nums = [5, 4, 11, 1, 16, 8]
dp =   [1, 1, 2,  1, 3,  2]

ans = max(dp) i.e 3 [5,11,16] 


index 2 : if 5 can become previous of 11 yes then i know LIS that ends 5. 
1 + 1 = 2

index 3 : can 5 be a part of 1 -> no, can 4 be a part of 1 -> no, can 11 be a part of 1 -> no 
1

index 4: if 5 can become previous of 16 yes then i know LIS that ends 5. 1 + 1 = 2
        if 4 can become previous of 16 yes then i know LIS that ends 4. 1 + 1 = 2
        if 11 can become previous of 16 yes then i know LIS that ends 11. 2 + 1 = 3
        if 1 can become previous of 16 yes then i know LIS that ends 1. 1 + 1 = 2
    max is 3 [5,11,16]

When i am at index i, then I check all the previous index from 0 till (i-1)


// NOTE: Above solution will be required to print the LIS

---------Intuition: print the LIS
We create a another array of length n and assign it to index from 0 to n-1. This hash array will say who was the previous index to it. 

nums = [5, 4, 11, 1, 16, 8]
dp =   [1, 1, 1,  1, 1,  1]
hash = [0, 1, 2,  3, 4,  5]

STEP 1: When we are at 11, 5 give 1 + 1 = 2. i.e dp[2]=2
    nums = [5, 4, 11, 1, 16, 8]
    dp =   [1, 1, 2,  1, 1,  1]
    hash = [0, 1, 0,  3, 4,  5]

Now remember this 5 got before 11 thereby dp[2] is updated to 2. So can u say before 11 there was 5. At 11 there was index 0. so update hash[2] = 0;

STEP 2: When we are at 1, no one can be before 1 so it remains 1 dp[3]=1
    nums = [5, 4, 11, 1, 16, 8]
    dp =   [1, 1, 2,  1, 1,  1]
    hash = [0, 1, 0,  3, 4,  5]

STEP 3: When we are at 16, 5 can be before 16 so update dp[4] = 1 + 1 = 2 and hash[4] = 0 because 5 is at 0
    nums = [5, 4, 11, 1, 16, 8]
    dp =   [1, 1, 2,  1, 2,  1]
    hash = [0, 1, 0,  3, 0,  5]

    4 can be before 16 -> 1+1 = 2 which is already there

    11 can be before 16 yes dp[4]=2+1 = 3, and 11 is comming before 16 update hash[4]=2, index of 16 is 2
    nums = [5, 4, 11, 1, 16, 8]
    dp =   [1, 1, 2,  1, 3,  1]
    hash = [0, 1, 0,  3, 2,  5]

So on

In order to print the LIS, we maintain a separate array along with a dp array (say hash).

Whenever we update our dp[i] value in the inner loop, we know that for index i, the previous index is prev_index. Therefore we simply store prev_index to hash[ i ]. In this way, we will have a way to trace back the LIS.

Whenever we have computed the entire dp array and we find the maximum value in it. We store that maximum value’s index in a variable ( say last_index). Now with this last_index, and the hash array we can trace back the LIS elements.

*/

// Length ---------------------------------------------------------------
void Lenght_longestIncreasingSubsequence(vector<int>nums){
    // Time complexity: O(N^2)
    // Space complexity: O(N)

    int n=nums.size();

    // The max length will be 1 i.e he itself
    vector<int>dp(n,1);

    int maxi=1;
    for(int i=0;i<n;i++){
        for(int prev=0; prev <= i-1; prev++){
            if(nums[prev] < nums[i]){
                dp[i]=max(dp[i], 1+dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    // Length of longest increasing subsequence
    int lengthOfLIS = maxi;
    cout<<"Length of longest increasing subsequence = "<<lengthOfLIS<<endl;
}


// Print the LIS---------------------------------------------------------
void print_longestIncreasingSubsequence(vector<int>nums){
    int n=nums.size();

    // The max length will be 1 i.e he itself
    vector<int>dp(n,1);

    // For printing LIS  - backtrack
    vector<int>hash(n,1);

    int maxi = 1;

    // Index where max is store in dp
    int lastIndex =-1;

    for(int i=0; i<=n-1; i++){
        hash[i] = i; // initializing with current index
        for(int prev = 0; prev <= i-1; prev ++){
            if(nums[prev]<nums[i] && 1 + dp[prev] > dp[i]){

                // updating dp
                dp[i] = 1 + dp[prev];

                // updateing hash with prev
                hash[i] = prev;
            }
        }
        // finding index of maxi (max(dp))
        if (dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }

    if(lastIndex==-1){
        lastIndex = 0;
    }

    // Printing LIS 
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);    
    }
    
    // reverse the array 
    reverse(temp.begin(),temp.end());
    
    cout<<"The subsequence elements are: ";
    
    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;   
}



int main(){
    vector<int>nums = {1};
    Lenght_longestIncreasingSubsequence(nums);

    // NOTE: Above solution will be required to print the LIS
    print_longestIncreasingSubsequence(nums);
}


#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/* Largest Divisible Subset
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
    answer[i] % answer[j] == 0, or
    answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


--------Intuition : Same solution Q.44 (print LIS) with some modification

subset -  In a subset there is no constraint on the order of the elements. (order does'nt matter), set of any element from the array in any order is a subset.
nums = [1,2,3,4,5], then subsets are: [1,2], [3,1,2], [4,2,1,3], [5], [5,1] many more

A divisible subset is the one in which if we pick two elements i and j from the subset, then either arr[i]%arr[j] == 0 or arr[j] % arr[i] == 0. For example, [1,2,4,8] is a divisible subset. Every of pair must be divisible. 
2%1=0
4%1=0, 4%2=0
8%1=0, 8%2=0, 8%4=0

Largest increasing subsequence 
Largest divisible subsequence (Question change to this. The question state we can print ans in order like [1,2,8,4] or [8,4,2,1] or [1,4,8,2]. if we change question to Largest divisible subsequence then our answer won't change)

Print any answer -> What if i sort the array. Since i can print any answer in any order.
Q. Why sort? 
Because [1,4,8,16] order does'nt matter. Answer is 4.

if i try to divide 4%8!=0 which is false but 8%4==0 which is true. In question it is given either 
answer[i] % answer[j] == 0, or either this answer[j] % answer[i] == 0. 
So if i sort the array then i check for 8-> 8 is divisible by 4 and we already calcuated that 4 is divisible by 1 
[1,4,8,16]
[1]
[1,2]
[1,2,3]
[1,2,3,4] 16 is divisible by 8 ans 8 has 3. Which means 16 is divisible by 8,4 & 1. Thats why sorting help us. so 1+3 = 4. 
answer is 4.

Question boils down to Largest divisible subsequence. The next no has to be pick has to be divisible. So use code of print LIS.

Sorting is the key observation.

*/

void largestDivisibleSubset(vector<int>& nums) {
    // Time complexity: O(n log n ) + O(n^2) 
    // Space complexity: O(n)


    // NOTE: We can use LIS method but that solution (recursion, memoization, tabulation, space optimization) gives me only the length of longest divisible subset. As The question state we have to print the largest subset so we use the solution of print LIS so that we can trace back the answer using a hash.


    int n=nums.size();
    
    // dp[i] stores the length of the divisible subset ending at arr[i]
    vector<int>dp(n,1);

    // hash[i] stores the previous index in the divisible subset ending at arr[i]
    vector<int>hash(n,0);

    // Sort the array in ascending order
    sort(nums.begin(), nums.end());

    int lastIndex = -1;
    int maxi=0;

    for(int i=0;i<n;i++){
        hash[i] = i;
        for(int j=0;j<=i-1;j++){
            if((nums[i] % nums[j] == 0) && (1+ dp[j] > dp[i])){
                dp[i] = 1+dp[j];
                hash[i] = j;
            }
        }
        // finding index of maxi (max(dp))
        if (dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
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
    vector<int>nums = {1,2,4,8};
    largestDivisibleSubset(nums);
}
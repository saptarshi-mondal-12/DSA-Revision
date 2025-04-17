'''
Count Number of Bad Pairs

You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
Return the total number of bad pairs in nums.

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
'''

class Solution:
    def countBadPairs(nums):
        # nums = [4,1,3,3,5]
        # badPair=totalPair - goodPair
        # goodPair = j-i == nums[j]-nums[i] or j-nums[j] == i-nums[i]
        # [-4, 0, -1, 0, -1]

        n=len(nums)
        totalPairs=0
        goodPairs=0
        d={}
        for i in range(0,n):
            totalPairs+=(n-i-1)
            diff=i-nums[i]
            if diff not in d:
                d[diff]=1 
            else:
                goodPairs+=d[diff]
                d[diff]+=1
        return totalPairs - goodPairs
    
        # n=len(nums)
        # count=0
        # for i in range(0,n):
        #     for j in range(i+1,n):
        #         if (j-i) != nums[j]-nums[i]:
        #             count+=1 
        # return count
        
        

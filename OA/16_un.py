'''
Smallest Range Covering Elements from K Lists

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
'''


class Solution:
    def optimal_smallestRange(self, nums):
        # Time complexity: O(n)
        # Space complexity: O(n)

        n=len(nums)
        ordered=[]
        count={}
        for i in range(0,n):
            for j in range(0, len(nums[i])):
                ordered.append([nums[i][j], i])
        ordered.sort()
        result=[]
        miniDifference = float('inf')
        left=0
        right=0
        while right < len(ordered):
            # Increase the count of the second element (0, 1, or 2)
            if ordered[right][1] not in count:
                count[ordered[right][1]]=1
            else:
                count[ordered[right][1]]+=1

            while len(count)==n:
                difference=ordered[right][0]-ordered[left][0]
                if difference < miniDifference:
                    miniDifference=difference
                    result=[ordered[left][0],ordered[right][0]]
                
                count[ordered[left][1]]-=1 
                if (count[ordered[left][1]] == 0):
                    del count[ordered[left][1]]
                left+=1
            right+=1

        return result
    
    
soln = Solution()
nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]

# optimal
result=soln.optimal_smallestRange(nums)
print(result)
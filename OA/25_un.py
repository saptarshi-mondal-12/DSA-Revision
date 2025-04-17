'''
Special Array II

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray nums[fromi..toi] is special or not.
Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

Input: nums = [3,4,1,2,6], queries = [[0,4]]
Output: [false]
Explanation: The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
Output: [false,true]
Explanation: The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
'''

class Solution:
    def isArraySpecial(self, nums, queries):
        #Time Complexity: O(M+N), Space Complexity: O(M)

        n = len(nums)
        max_reach = [0] * n
        end = 0

        # Step 1: Compute the maximum reachable index for each starting index
        for start in range(n):
            # Ensure 'end' always starts from the current index or beyond
            end = max(end, start)
            # Expand 'end' as long as adjacent elements have different parity
            while end < n - 1 and nums[end] % 2 != nums[end + 1] % 2:
                end += 1
            # Store the farthest index reachable from 'start'
            max_reach[start] = end

        ans = []

        # Step 2: Answer each query based on precomputed 'max_reach'
        for start, end_query in queries:
            # Check if the query range [start, end] lies within the max reachable range
            ans.append(end_query <= max_reach[start])
        return ans        


        # result=[]
        # for i in range(0, len(queries)):
        #     start=queries[i][0]
        #     end=queries[i][1]
        #     if nums[start]%2==0:
        #         flag=0
        #         check=0
        #         for j in range(start, end+1):
        #             curr=nums[j]
        #             if curr%2==0 and flag==0:
        #                 flag=1
        #             elif curr%2!=0 and flag==1:
        #                 flag=0
        #             else:
        #                 check=1
        #                 break
        #         if check==0:
        #             result.append(True)
        #         else:
        #             result.append(False)
        #     elif nums[start]%2!=0:
        #         flag=0
        #         check=0
        #         for j in range(start, end+1):
        #             curr=nums[j]
        #             if curr%2!=0 and flag==0:
        #                 flag=1
        #             elif curr%2==0 and flag==1:
        #                 flag=0
        #             else:
        #                 check=1
        #                 break
        #         if check==0:
        #             result.append(True)
        #         else:
        #             result.append(False)
        # return result
        
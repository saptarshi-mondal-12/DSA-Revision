'''
Shortest Subarray to be Removed to Make Array Sorted

Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
Return the length of the shortest subarray to remove. A subarray is a contiguous subsequence of the array.

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].

Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].

Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
'''

class Solution:
    def findLengthOfShortestSubarray(self, arr) -> int:
        n=len(arr)

        # Step 1: Find the longest non-decreasing prefix
        i=0
        while i+1 < n and arr[i]<=arr[i+1]:
            i+=1 

        # if entire array is sorted
        if i==n-1:
            return 0
        
        # Step 2: Find the longest non-decreasing suffix
        j=n-1
        while j > 0 and arr[j-1] <= arr[j]:
            j-=1 
        
        # 1. Removing all elements from right of 'left' or left of 'right'
        result = min(n-i-1, j)
        print("result =",result, " i =",i," j =",j)

        # Step 4: Try to merge the prefix and suffix by checking if we can connect arr[left] and arr[right]
        left=0
        right=j
        while left <= i and right < n:
            if arr[left] <= arr[right]:
                result=min(result, right-left-1)
                left+=1 
            else:
                right+=1
        return result

s= Solution()
print(s.findLengthOfShortestSubarray([1,2,3]))



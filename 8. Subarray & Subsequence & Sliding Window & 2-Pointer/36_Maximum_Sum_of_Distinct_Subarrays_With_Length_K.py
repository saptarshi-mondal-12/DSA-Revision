'''
Maximum Sum of Distinct Subarrays With Length K

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
The length of the subarray is k, and All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
'''

def maximumSubarraySum( nums, k: int) -> int:
        # TC = O(N)
        # SC = O(N)
        n=len(nums)
        result=0
        left=0
        right=0
        currSum=0
        d={}
        while right < n:
            currSum+=nums[right]
            if nums[right] not in d:
                d[nums[right]]=1 
            else:
                d[nums[right]]+=1

            if  right >= k-1:
                if len(d)==k:
                    result=max(result, currSum)
                currSum-=nums[left]
                d[nums[left]]-=1 
                if d[nums[left]]==0:
                    d.pop(nums[left])
                left+=1
            right+=1

        return result
    



        # TC = O(N^2)
        # SC = O(K)
        # n=len(nums)
        # result=0
        # for i in range(0, n-k+1):
        #     uniqueList=[]
        #     flag=0
        #     for j in range(i, i+k):
        #         if nums[j] in uniqueList:
        #             flag=1
        #             break
        #         else:
        #             uniqueList.append(nums[j])
        #     if flag==0:
        #         result=max(result, sum(uniqueList))
        # return result

nums = [1,5,4,2,9,9,9]
k = 3
print(maximumSubarraySum(nums, k))

        
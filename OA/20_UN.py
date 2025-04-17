'''
Count the Number of Fair Pairs

Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
A pair (i, j) is fair if:
0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
'''
def find_lower_bound(num, start, nums, lower) :
        i=start
        j=len(nums)-1
        while i<=j:
            mid=(i+j)//2
            if num+nums[mid] >= lower:
                j=mid-1
            else:
                i=mid+1
        return i

def find_upper_bound(num, start, nums, upper):
    i=start
    j=len(nums)-1
    while i<=j:
        mid=(i+j)//2
        if num+nums[mid] <= upper:
            i=mid+1
        else:
            j=mid-1
    return i


def countFairPairs(nums, lower, upper):
    # TC = O(NLogN)
    n=len(nums)
    result=0
    nums.sort()
    for i in range(0,n):
        # finding lower value such that sum >= lower
        low=find_lower_bound(nums[i], i+1, nums, lower)

        # finding upper value such that sum <= upper
        high=find_upper_bound(nums[i], i+1, nums, upper) 

        result+=(high-low)

    return result


nums = [0,1,7,4,4,5]
lower = 3
upper = 6
print(countFairPairs(nums, lower, upper))
'''
Prime Subtraction Operation

You are given a 0-indexed integer array nums of length n. You can perform the following operation as many times as you want:
Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
Return true if you can make nums a strictly increasing array using the above operation and false otherwise.
A strictly increasing array is an array whose each element is strictly greater than its preceding element.

Input: nums = [4,9,6,10]
Output: true
Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
After the second operation, nums is sorted in strictly increasing order, so the answer is true.

Input: nums = [6,8,11,12]
Output: true
Explanation: Initially nums is sorted in strictly increasing order, so we don't need to make any operations.

Input: nums = [5,8,3]
Output: false
Explanation: It can be proven that there is no way to perform operations to make nums sorted in strictly increasing order, so the answer is false.
'''
def getPrime(primes, l, h):
        for p in range(0,len(primes)):
            if primes[p]==1 and p <= l and  l-p < h:
                return p
        return -1

def primeSubOperation(nums):
    n=len(nums)
    maxElement=max(nums)
    primes=[1]*(maxElement+1)
    primes[1]=0
    for i in range(2, maxElement+1):
        if primes[i]==1:
            index=i*i
            while index <= maxElement:
                primes[index]=0
                index+=i
    print(primes)
    for i in range(n - 2, -1, -1):
        if nums[i] >= nums[i + 1]:
            p = getPrime(primes, nums[i], nums[i+1])
            if p == -1 or nums[i]-p==0:
                return False
            else:
                nums[i] -= p
    return True

        
nums=[4,9,6,10]
print(primeSubOperation(nums))
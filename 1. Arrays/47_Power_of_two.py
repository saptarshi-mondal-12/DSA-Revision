'''
Power of Two

Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.

Input: n = 1
Output: true
Explanation: 20 = 1

Input: n = 16
Output: true
Explanation: 24 = 16

Input: n = 3
Output: false
'''

def isPowerOfTwo(self, n: int) -> bool:
    if n==1:
        return True
    low = 1
    high=31

    while (low<=high):
        mid=(low+high)//2

        if 2**mid == n:
            return True
        elif 2**mid > n:
            high=high-1
        else:
            low=low+1
    return False

def isPowerOfTwo(self, n: int) -> bool:
    if n==0:
        return False
    return (n and (not(n & (n - 1))))
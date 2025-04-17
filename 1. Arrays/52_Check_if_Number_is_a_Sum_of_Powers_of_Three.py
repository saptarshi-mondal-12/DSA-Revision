'''
Q. Check if Number is a Sum of Powers of Three

Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.
An integer y is a power of three if there exists an integer x such that y == 3x.

Input: n = 12
Output: true
Explanation: 12 = 31 + 32

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34

Input: n = 21
Output: false
'''

class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        # Time complexity: O(log n) since we repeatedly divide n by 3.
        # Space complexity: O(1)
        while n > 0:
            if n % 3 == 2:
                return False
            n //= 3
        
        return True

'''
Intution : 

A number can be written as a sum of distinct powers of three if each power is used at most once.
The base-3 representation tells us exactly how many times each power of three appears in the sum.
If any digit in base-3 is 2, it means we would need to use a power of three twice, which is not allowed.


1. Convert n to base-3.
2. In base-3 representation, if any digit is 2, then n cannot be represented as a sum of distinct powers of three.
    Since we can only use 0 or 1 for distinct powers, having 2 means we would need to reuse a power of three, which is not allowed.
3. If all digits in the base-3 representation are 0 or 1, return true, otherwise return false.

e.g. n = 12
3 | 12 | 0  
3 | 4  | 1  
3 | 1  | 1  
    0  
Base-3: 110₃ → Only 0s and 1s → ✅ True


e.g. n = 91
3 | 91 | 1  
3 | 30 | 0  
3 | 10 | 1  
3 | 3  | 0  
3 | 1  | 1  
    0  
Base-3: 10101₃ → Only 0s and 1s → ✅ True


e.g. n=21
3 | 21 | 0  
3 | 7  | 1  
3 | 2  | 2  
    0  

Base-3: 210₃ → Contains 2 → ❌ False
210₃ means:
2x(3^2) (⚠ Used twice, not allowed)
1x(3^1)
0x(3^0)

The term 2×(3^2) is invalid because each power should be used at most once. Since we need two (3^2)s, but we are only allowed to use one distinct power of three, 21 is not representable in this form.

(3^2) + (3^2) + (3^1) 
9 + 9 + 3 = 21 
we use two (3^2)s which is invalid 
'''
    
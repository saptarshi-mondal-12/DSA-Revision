'''
Q. Check if a number can be represented as sum of non zero powers of 2

Given an integer N, the task is to check whether N can be represented as the sum of powers of 2 where all the powers are > 0 i.e. 20 cannot contribute to the sum.
 
Input: N = 10 
Output: 1 
23 + 21 = 10


Input: N = 9 
Output: 0 
 

Approach: There are two cases: 

1. When N is even then it can always be represented as the sum of powers of 2 when power > 0.
2. When N is odd then it can never be represented as the sum of powers of 2 if 20 is not included in the sum.
'''

def isSumOfPowersOfTwo(n):
    # Time Complexity: O(1)
    if n % 2 == 1:
        return False
    else:
        return True
print(isSumOfPowersOfTwo(3))
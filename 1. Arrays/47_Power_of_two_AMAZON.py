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

'''
Q. Why 2**31 is used in binary search?
Ans: I used 2³¹ as the upper bound because the input n is a 32-bit signed integer.
The largest possible power of two that fits in a signed 32-bit int is 2³⁰, and 2³¹ is the first value that exceeds the positive range (INT_MAX = 2³¹ − 1).
So using 2³¹ safely covers all valid powers of two for the given constraints without overflow.


Q: Why not 2³²?
Ans: 2³² does not fit into a signed 32-bit integer. Since n is of type int, any value ≥ 2³¹ would overflow or be invalid, so 2³¹ is the logical cutoff.”
'''

def isPowerOfTwo(self, n: int) -> bool:
    # Time Complexity: O(log n)
    # Space Complexity: O(1)

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

'''
c++ bit manipulation code: 



bool isPowerOfTwo(int n) {
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    if(n==1) return true;

    if((n > 0) && (n & (n-1)) == 0 ){
        return true;
    }

    return false;
}


2 = 0010
4 = 0100
8 = 1000
16= 10000
32=100000
64=1000000

There is only one set bit in all the powers of two. 

So if we do n & (n-1), it will result in 0 only for the powers of two.

Eg: n=8 (1000)
n-1=7 (0111)
n & (n-1) = 1000 & 0111 = 0000


'''

''' Check If Array Pairs Are Divisible by k

Given an array of integers arr of even length n and an integer k. We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
Return true If you can find a way to do that or false otherwise.

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
'''

class Solution:
    def canArrange(self, arr: str, k: int) -> bool:
        freq=[0]*k 
        for i in arr:
            rem=i%k
            freq[rem]+=1

        for i in arr:
            rem=i%k
            if rem == 0:
                if freq[rem]%2 == 1:
                    return False
            elif freq[rem] != freq[k-rem]:
                return False
        return True

soln = Solution()
arr=[1,2,3,4,5,10,6,7,8,9]
k=5
result=soln.canArrange(arr, k)
print(result)
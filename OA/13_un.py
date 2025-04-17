'''
Maximum Swap

You are given an integer num. You can swap two digits at most once to get the maximum valued number.
Return the maximum valued number you can get.

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Input: num = 9973
Output: 9973
Explanation: No swap.
'''


class Solution:

    def maximumSwap(self, num: str) -> str:
        # Time complexity: O(n^2)
        # Space complexity: O(n)

        num=str(num)
        n=len(num)
        result=int(num)
        for i in range(0, n):
            for j in range(i+1, n):
                s=list(num)
                temp=s[i]
                s[i]=s[j]
                s[j]=temp
                s="".join(s)
                result=max(result, int(s))
        return result


    def optimal_maximumSwap(self, num: str) -> str:
        # Time complexity: O(n)
        # Space complexity: O(n)

        numStr=str(num)
        n=len(numStr)
        lastSeen=[-1]*10
        for i in range(0, len(numStr)):
            lastSeen[int(numStr[i])]=i
        for i in range(0,n):
            for d in range(9, int(numStr[i]), -1):
                if lastSeen[d] > i:

                    numStr=list(numStr)
                    numStr[i] , numStr[lastSeen[d]] = numStr[lastSeen[d]], numStr[i]

                    numStr="".join(numStr)
                    return int(numStr)
        return num
    
    
soln = Solution()
s=2736

# brute
# result=soln.maximumSwap(s)
# print(result)

# optimal
result=soln.optimal_maximumSwap(s)
print(result)
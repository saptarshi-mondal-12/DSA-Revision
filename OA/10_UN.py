'''
Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Input: s = "aab"
Output: "aba"

Input: s = "aaab"
Output: ""
'''
class Solution:
    def reorganizeString(self, s: str) -> str:
        n=len(s)
        d={}
        for i in s:
            if i not in d:
                d[i]=1
            else:
                d[i]+=1 
        d=dict(sorted(d.items(), key=lambda x: x[1], reverse=True ))
        max_freq=list(d.values())[0]
        required=max_freq-1
        total=n-max_freq

        if total < required :
            return ""
        result=[""]*n

        # Placing most frequent character 
        letter=list(d.keys())[0]
        index=0
        while d[letter] > 0:
            result[index]=letter
            index+=2
            d[letter]-=1 

        # Place rest of the letters in any order
        for key, val in d.items():
            while val > 0:
                if index >= len(s):
                    index=1 
                result[index]=key
                index+=2 
                val-=1 
        return "".join(result)

soln = Solution()
s="aab"
result=soln.reorganizeString(s)
print(result)
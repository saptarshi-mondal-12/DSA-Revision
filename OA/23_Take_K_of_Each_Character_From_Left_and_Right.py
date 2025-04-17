'''
Take K of Each Character From Left and Right
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
'''

def takeCharacters(s,k) -> int:
        # TC = O(N)
        # SC= O(3)
        if s.count('a') < k or s.count('b') < k or s.count('c') < k:
            return -1 

        n=len(s)
        # count total occurrences
        count=[0]*3
        for c in s:
            if c=='a':
                count[0]+=1
            elif c=='b':
                count[1]+=1
            else:
                count[2]+=1

        window=[0]*3
        maxi_window=0
        left=0
        right=0
        while right < n:
            ch=s[right]
            window[ord(ch) - ord('a')]+=1

            while left <= right and (
                count[0] - window[0] < k or 
                count[1] - window[1] < k or 
                count[2] - window[2] < k):

                window[ord(s[left]) - ord('a')]-=1
                left+=1
            
            maxi_window=max(maxi_window, right-left+1)
            right+=1 
        return n-maxi_window

s = "aabaaaacaabc"
k = 2
print(takeCharacters(s,k))
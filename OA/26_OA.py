'''
Construct K Palindrome Strings

Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
'''



'''
Intuition
To approach this problem, we need to consider how the frequencies of characters in the string s affect the ability to form palindromes.

What key insight can we gain from knowing that a single character can be a palindrome? If every individual character in the string can be a palindrome, then the maximum number of palindromes we can form is the length of the string s. If k is greater than the length of s, it’s impossible to form k palindromes, so the answer will be false. Similarly, if k equals the length of s, we can form k palindromes, with each character of s forming its own palindrome.

Next, consider even-frequency characters. These characters can be used to form the mirrored halves of palindromes, meaning we can freely distribute them across multiple palindromes without any issue. Thus, even-frequency characters do not limit the number of palindromes we can form.

The real challenge lies with odd-frequency characters. A palindrome can only have one odd-frequency character at its center; the rest must appear in even numbers. Therefore, the number of odd-frequency characters in the string determines how many palindromes we can form. Specifically, the minimum number of palindromes we can make is equal to the number of odd-frequency characters, because each odd-frequency character requires its own palindrome.

Thus, if the number of odd-frequency characters is greater than k, it’s impossible to form k palindromes, so we return false. If the number of odd-frequency characters is less than or equal to k, we can form k palindromes, and the answer will be true.
'''

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # TC = O(N)
        n=len(s)
        if n < k:
            return False
        if n==k:
            return True
        
        # storing character frequency 
        freq={}
        for i in s:
            if i not in freq:
                freq[i]=1 
            else:
                freq[i]+=1 
        print(freq)
        oddCount=0
        for i in set(s):
            if freq[i]%2==1:
                oddCount+=1
        if oddCount<=k:
            return True
        return False
'''
Count K-Length Substrings With No Repeated Characters

Given a string S and an integer k, the task is to return the number of substrings in S of length k with no repeated characters.

Input: S = "geeksforgeeks", k = 5
Output: 4
Explanation: There are 4 substrings, they are: 'eksfo', 'ksfor', 'sforg', 'forge'.

Input: S = "home", k = 5
Output: 0
Explanation: Notice k can be larger than the length of S. In this case, it is not possible to find any substring.
'''
def count_K_Len_Substr_No_Repeats(s,k):
    n=len(s)
    result=0
    left=0
    right=0
    d={}
    while right < n:
        ch=s[right]
        if ch not in d:
            d[ch]=1 
        else:
            d[ch]+=1
        
        while d[ch] > 1 or len(d) > k:
            d[s[left]]-=1
            if d[s[left]]==0:
                d.pop(s[left])
            left+=1
        
        if (right-left+1 == k):
            result+=1
        right+=1

    return result


s="home"
k = 5
print(count_K_Len_Substr_No_Repeats(s,k))
#include<bits/stdc++.h>
using namespace std;

/* Q. The k-th Lexicographical String of All Happy Strings of Length n - AMAZON 2025

A happy string is a string that:
consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"

---------------------------------------------------------------------------------------------------------------------------------

hint: backtrack

Hint 1
Generate recursively all the happy strings of length n.

Hint 2
Sort them in lexicographical order and return the kth string if it exists.


""  
├── "a"  
│   ├── "ab"  
│   │   ├── "aba" ✅
│   │   └── "abc" ✅
│   └── "ac"  
│       ├── "aca" ✅
│       └── "acb" ✅
├── "b"  
│   ├── "ba"  
│   │   ├── "bab" ✅
│   │   └── "bac" ✅
│   └── "bc"  
│       ├── "bca" ✅
│       └── "bcb" ✅
└── "c"  
    ├── "ca"  
    │   ├── "cab" ✅
    │   └── "cac" ✅
    └── "cb"  
        ├── "cba" ✅
        └── "cbc" ✅


We now have 12 strings of length 3:
["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]


Sort them:
["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]

Pick the k-th string Here k = 9
The 9th string is "cab"
✅ Answer = "cab"


------------Time complexity: ---------------

At each position, we branch into at most 2 choices (not equal to last character).
Total happy strings = 3 × 2^(n-1).
Each string takes O(n) to build (concatenation or copying).
So generation = O(n × 3 × 2^(n-1)) 

Sorting adds O(M log M) but since M = number of happy strings

✅ Final Time Complexity: O(n × 3 × 2^(n−1) log(3×2^(n−1)))


------------Space Complexity:----------------

Recursion depth = O(n)
Storage for all strings = O(n x 3 x 2^(n-1))

There are 3 * 2^(n-1) happy strings of length n.
Each string is length n.
So total complexity = O(3 * 2^(n-1) * n) (for generation).

✅ Final Space Complexity: O(n × 3 × 2^(n−1))



Time Complexity: O(n) + O(M log M)
Space Complexity: O(n × 3 × 2^(n-1))




*/

vector<string> allHappyStrings;
    
void dfs(string current, int n) {
    if (current.size() == n) {
        allHappyStrings.push_back(current);
        return;
    }
        
    for (char ch : {'a', 'b', 'c'}) {
        if (current.empty() || current.back() != ch) {
            dfs(current + ch, n);
        }
    }
}
    
string getHappyString(int n, int k) {
    dfs("", n);
    sort(allHappyStrings.begin(), allHappyStrings.end()); // lexicographical order
        
    if (k > allHappyStrings.size()) return "";
    return allHappyStrings[k - 1]; // 1-indexed
}

int main(){
    int n = 3, k = 9;
    cout<<getHappyString(n,k)<<endl;
}




        
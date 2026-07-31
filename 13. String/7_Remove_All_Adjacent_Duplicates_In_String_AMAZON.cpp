#include<bits/stdc++.h>
using namespace std;

/* Remove All Adjacent Duplicates In String - AMAZON 2026

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Input: s = "abbaca"
Output: "ca"
Explanation: For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Input: s = "azxxzy"
Output: "ay"

*/

string removeDuplicates(string s) {
    // Time complexity: O(n)
    // Space complexity: O(n)
    int n = s.size();
    string result = "";
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(result.size() != 0 && ch == result.back()){
            result.pop_back();
        }else{
            result.push_back(ch);
        }
    }
    return result;
}
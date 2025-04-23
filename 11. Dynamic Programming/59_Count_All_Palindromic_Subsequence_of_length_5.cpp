#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count All Palindromic Subsequence of length 5 - Salesforce Question 

For a string s which consists only of characters '0' and '1', find the number of subsequences of length 5 which are palindromes.
As the answer can be really big, return the answer mod (10^9+7).
Note
    • A palindrome is a string that reads the same backward as forward.
    • A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.

• Two subsequences are considered different if the indices of the string that forms the subsequences are different.

Example
s = "0100110"
Using 1-based indexing, the 5 subsequences are
• indices (1, 2, 3, 6, 7) -> 01010
• indices (1, 2, 3, 5, 7) -> 01010
• indices (1, 2, 4, 6, 7) -> 01010
• indices (1, 2, 4, 5, 7) -> 01010
• indices (1, 2, 5, 6, 7) -> 01110
5 modulo (10^9+7)=5
*/

// Recursion--------------------------------------------------------------
bool isPalindrome(string &s) {
    int left = 0, right = s.size() - 1; 
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++; 
        right--;
    }
    return true; 
}
int solve1(string &s, int i, string curr) {
    // Base case: if we've considered all characters
    if (i == s.size()) {
        // Only check palindromes of length 5
        if (curr.size() == 5 && isPalindrome(curr)) {
            return 1;
        }else{
            return 0;
        }
    }

    int res1 = 0;
    if (curr.size() < 5) {
        // Include s[i] if current length < 5
        res1 = solve1(s, i + 1, curr + s[i]);
    }

    // Always valid to exclude current character
    int res2 = solve1(s, i + 1, curr);

    return res1 + res2;
}
int countPalindromicSubsequenceLength5_1(string s) {
    return solve1(s, 0, "");
}




int main(){
    string s="0100110";

    // Recursion
    cout<<countPalindromicSubsequenceLength5_1(s)<<endl;
}
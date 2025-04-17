#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Replace the Substring for Balanced String

You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.
A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.
Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER". 
*/
bool isValid(unordered_map<char, int> &windowFreq, map<char, int> &extraFreqCount) {
    for (auto it : extraFreqCount) {  // Loop through required excess characters
        char ch = it.first;  // The character
        int req = it.second; // The extra count needed

        if (windowFreq[ch] < req) {  
            return false;  // If window doesn't have enough of this character, return false
        }
    }
    return true;  // If all extra characters are covered, return true
}
int balancedString(string s) {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int n = s.size();
    int required = n / 4;
    map<char, int> mp;

    // Step 1: Count character frequencies
    for (char c : s) {
        mp[c]++;
    }

    // Step 2: Identify excess characters
    map<char, int> extraFreqCount;
    for (auto it : mp) {
        if (it.second > required) {
            extraFreqCount[it.first] = (it.second - required);
        }
    }

    // If no excess characters, string is already balanced
    if (extraFreqCount.empty()) return 0;

    // Step 3: Sliding Window to find the minimum substring covering all excess
    int i = 0, j = 0, minLen = INT_MAX;
    unordered_map<char, int> windowFreq;

    while (j < n) {
        char rightChar = s[j];
        windowFreq[rightChar]++;
        
        // Shrink the window while it satisfies the excess character counts
        while (isValid(windowFreq, extraFreqCount)) {
            minLen = min(minLen, j - i + 1);
            char leftChar = s[i];
            windowFreq[leftChar]--;
            i++;  // Move left pointer
        }

        j++;  // Expand right pointer
    }

    return minLen;
}

int main(){
    string s="QQQW";
    cout<<balancedString(s)<<endl;

}
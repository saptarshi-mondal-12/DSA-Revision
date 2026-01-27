#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Reorganize String - AMAZON 2025 - 5 times

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Input: s = "aab"
Output: "aba"

Input: s = "aaab"
Output: ""

-------------------------------------------------------------------------------------------------------

🔑 Key Idea:

If one character’s frequency is more than (n+1)/2, rearrangement is impossible.

Otherwise, we can place the most frequent characters in alternate positions (0, 2, 4, …) first, then fill the remaining gaps with the rest.

*/

string reorganizeString(string s){
    // Time complexity: O(n) + O(maxFreq) + O(n) = O(n)
    // Space complexity: O(n)


    int n = s.size();

    unordered_map<char, int> mp;
    int maxFreq = 0;
    char maxChar;

    for (int i = 0; i < n; i++){
        mp[s[i]]++;

        if (mp[s[i]] > maxFreq){
            maxFreq = mp[s[i]];
            maxChar = s[i];
        }
    }

    // Impossible case
    if (maxFreq > (n + 1) / 2)
        return "";

    // length n, filled with spaces
    string result(n, ' ');

    // Place most frequent char first
    int index = 0;
    while (mp[maxChar] > 0){
        result[index] = maxChar;
        index += 2;
        mp[maxChar]--;
    }

    // Place remaining chars
    for (auto it : mp){
        char ch = it.first;
        int freq = it.second;

        while (freq != 0){
            if (index >= n){
                index = 1;
            }
            result[index] = ch;
            index += 2;
            freq--;
        }
    }

    return result;
}

int main(){
    string s = "aab";
    cout << reorganizeString(s) << endl;
}
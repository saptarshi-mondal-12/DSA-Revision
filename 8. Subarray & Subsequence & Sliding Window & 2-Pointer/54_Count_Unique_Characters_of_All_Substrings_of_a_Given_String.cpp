#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Count Unique Characters of All Substrings of a Given String
Let's define a function countUniqueChars(s) that returns the number of unique characters in s.

For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10

Input: s = "ABA"
Output: 8
Explanation: The same as example 1, except countUniqueChars("ABA") = 1.

Input: s = "LEETCODE"
Output: 92*/

int uniqueLetterString(string s) {
    unordered_map<char, vector<int>> index;
    int n = s.length();

    // Step 1: Store all indices for each character
    for (int i = 0; i < n; ++i) {
        index[s[i]].push_back(i);
    }

    // Step 2: Add -1 at the beginning and n at the end for each character's index list
    for (auto it = index.begin(); it != index.end(); ++it) {
        it->second.insert(it->second.begin(), -1); // insert -1 at start
        it->second.push_back(n);                  // append n at end
    }

    int result = 0;

    // Step 3: For each character and its index list, calculate contribution
    for (auto it = index.begin(); it != index.end(); ++it) {
        vector<int>& posList = it->second;

        for (int i = 1; i < posList.size() - 1; ++i) {
            int prev = posList[i - 1];
            int curr = posList[i];
            int next = posList[i + 1];

            result += (curr - prev) * (next - curr);
        }
    }

    return result;
}

int main(){
    string s= "ABC";
    cout<<uniqueLetterString(s)<<endl;
}
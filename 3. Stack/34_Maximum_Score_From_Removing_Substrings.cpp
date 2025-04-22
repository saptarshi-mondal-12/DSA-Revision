#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/* Q. Maximum Score From Removing Substrings

You are given a string s and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
    For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
    For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20*/

int removePattern(string &s, char first, char second, int value) {
    string stack = "";
    int score = 0;

    for (char ch : s) {
        if (!stack.empty() && stack.back() == first && ch == second) {
            stack.pop_back();
            score += value;
        } else {
            stack.push_back(ch);
        }
    }
    s = stack; // Update the string after removing the pattern
    return score;
}
int maximumGain(string s, int x, int y) {
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    int score = 0;
    if (x > y) {
        score += removePattern(s, 'a', 'b', x); // Remove "ab" first
        score += removePattern(s, 'b', 'a', y); // Then "ba"
    } else {
        score += removePattern(s, 'b', 'a', y); // Remove "ba" first
        score += removePattern(s, 'a', 'b', x); // Then "ab"
    }
    return score;
}

int main() {
    string s1 = "cdbcbbaaabab";
    int x1 = 4, y1 = 5;
    cout << maximumGain(s1, x1, y1) << endl; // Output: 19

    string s2 = "aabbaaxybbaabb";
    int x2 = 5, y2 = 4;
    cout << maximumGain(s2, x2, y2) << endl; // Output: 20

    return 0;
}
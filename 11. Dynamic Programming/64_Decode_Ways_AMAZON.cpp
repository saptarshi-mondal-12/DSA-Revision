#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Decode Ways - AMAZON 2025

You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'
"2" -> 'B'

...

"25" -> 'Y'
"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

The test cases are generated so that the answer fits in a 32-bit integer.

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Input: s = "06"
Output: 0
Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.


Intuition ---------------------------------------------------------------------

🎯 Goal
Given s = "226" → Count how many valid ways we can split this to get a message.

226 →

    "2 2 6" → B B F
    "22 6" → V F
    "2 26" → B Z

✅ 3 valid ways → Output = 3

We need to count number ways to decode input string with one digit or two digits little by little. That's why I felt like I need memo to keep results and I started to think about dynamic programming.

First of all, we initialize array for dynamic programming with length of input string + 1. The array is used to count decode ways from beginning to current character.

And update index 0 and index 1 with 1.

dp = [0,0,0,0,0]
dp = [1,1,0,0,0]

index0: ("")
index1: (2)
Index 0 is for empty string. That is one pattern.
Index 1 is for the first character(= 2). That is one pattern, because we cannot create two digits.

So, we start from index 2. And somebody is wondering we don't check the second "2" at index 1 in the input string yet. But If we are at index 2, it's easy to get one digit and two digits. just subtract 1 from current index for one digits and get characters between current index - 2 and current index for two digits.

Input = "2215"
            ↑

Possible combination with "5" should be
(2,2,1), (22,1), (2,21) → (2,2,1,5), (22,1,5), (2,21,5)

Possible combination with "15" should be
(2,2), (22) → (2,2,15), (22,15)

dp = [1,1,2,3,5]

index0: ("")
index1: (2)
index2: (2,2), (22)
index3: (2,2,1), (22,1), (2, 21)
index4: (2,2,1,5), (22,1,5), (2,21,5), (2,2,15), (22,15)


✅ Key Observations:
A digit '0' cannot be mapped to any letter by itself (e.g., "0" is invalid).
A valid 2-digit number must be between "10" and "26" inclusive.
For each position i in the string s, we consider:
    1-digit decode: If s[i-1] is not '0', it contributes dp[i-1] ways.
    2-digit decode: If s[i-2:i] is between "10" and "26", it contributes dp[i-2] ways.

✅ Dynamic Programming Approach
Let dp[i] be the number of ways to decode the substring s[0...i-1].

Initialization:
    dp[0] = 1 → Base case: empty string has one way to decode.
    dp[1] = 1 if s[0] != '0' else 0.

Transition:
For i = 2 to n:
    If s[i-1] != '0', then dp[i] += dp[i-1]
    If 10 <= int(s[i-2:i]) <= 26, then dp[i] += dp[i-2]


✅ Example: 

Let’s take string s = "226"
We will use a DP array like this:

Index:   0  1  2  3
s:          2  2  6
dp[i]:  1  1  ?  ?
Step 1: dp[0] = 1
Empty string → 1 way to decode (base case)

Step 2: dp[1] = 1
First digit is '2' → valid → 1 way to decode

Step 3: dp[2]
Last 1 digit → '2' → valid → add dp[1] = 1

Last 2 digits → '22' → valid → add dp[0] = 1

So, dp[2] = 1 + 1 = 2

Step 4: dp[3]
Last 1 digit → '6' → valid → add dp[2] = 2

Last 2 digits → '26' → valid → add dp[1] = 1

So, dp[3] = 2 + 1 = 3

✅ Final Result: dp[3] = 3

*/

int numDecodings(string s){
    // Time complexity: O(n)
    // Space complexity: O(n)


    int n = s.size();
    if (n == 0 || s[0] == '0')
        return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // empty string
    dp[1] = 1; // one character (checked above it's not '0')

    for (int i = 2; i <= n; ++i){
        // One digit decode
        if (s[i - 1] != '0'){
            dp[i] += dp[i - 1];
        }

        // Two digit decode
        int twoDigit = stoi(s.substr(i - 2, 2));
        if (twoDigit >= 10 && twoDigit <= 26){
            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main(){
    string s= "1223";
    cout<<numDecodings(s);
}
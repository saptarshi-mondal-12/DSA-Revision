#include<bits/stdc++.h>
using namespace std;

/* Q. Largest Number - Microsoft 2025n

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.


Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

-------------------------------------------------------------------------------------------------------------

Step-by-step on nums = [3,30,34,5,9]

Convert to strings: ["3","30","34","5","9"].

Sort with mycomp. Below are the key pairwise decisions (the exact sequence of comparisons depends on the sort’s internals, but these are sufficient to determine the final order):

"3" vs "30":
t1="330", t2="303" ⇒ t1>t2 ⇒ "3" before "30".

"34" vs "3":
t1="343", t2="334" ⇒ "34" before "3".

"5" vs "34":
t1="534", t2="345" ⇒ "5" before "34".

"9" vs "5":
t1="95", t2="59" ⇒ "9" before "5".

"9" vs "34":
t1="934", t2="349" ⇒ "9" before "34".

"34" vs "30":
t1="3430", t2="3034" ⇒ "34" before "30".

From these, a consistent descending order emerges:

["9", "5", "34", "3", "30"]


Concatenate in that order:
"9" + "5" + "34" + "3" + "30" = "9534330".

Q. Why this works ?

Placing a before b when ab > ba is a local rule that guarantees the global maximum concatenation. If any adjacent pair violated this rule, swapping them would increase the result—so the sorted order is optimal.

Edge case to handle in code

If after sorting the first element is "0" (e.g., input has only zeros), return "0" instead of "000...".


-------------------------------------------------------------------------
Bucket {3, 33, 303, 19, 12, 122}

Do pairwise:
    "3" vs "33": "333" vs "333" → tie → "3" first.
    "3" vs "303": "3303" vs "3033" → "3303" > "3033" → "3" first.
    "33" vs "303": "33303" vs "30333" → "33" first.

So order: 3, 33, 303.

Bucket {3, 33, 303, 19, 12, 122}
    "19" vs "12": "1912" vs "1219" → "1912" > "1219" → "19" first.
    "19" vs "122": "19122" vs "12219" → "19" first.
    "122" vs "12": "12212" vs "12122" → "122" first.

So order: 19, 122, 12.

final = ["3","33","303","19","122","12"]

*/

static bool mycomp(string a, string b){
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}

string largestNumber(vector<int> &nums){
    // Time Complexity: O(n log n)
    // Space Complexity: O(n + s)

    vector<string> numStrings;
    // Convert each integer to a string
    for (int num : nums){
        numStrings.push_back(to_string(num));
    }

    // Sort strings based on concatenated values
    sort(numStrings.begin(), numStrings.end(), mycomp);


    // Handle the case where the largest number is zero
    if (numStrings[0] == "0") return "0";

    // Concatenate sorted strings to form the largest number
    string ans = "";
    for (auto str : numStrings){
        ans += str;
    }
    return ans;
}

int main(){
    vector<int>nums = {3, 33, 303, 19, 12, 122};
    cout<<largestNumber(nums);
}
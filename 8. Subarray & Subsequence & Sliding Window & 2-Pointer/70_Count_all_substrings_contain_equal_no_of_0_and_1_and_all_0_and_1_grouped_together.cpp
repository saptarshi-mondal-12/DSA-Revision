#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Q. Count all substrings contains equal no of 0 and 1 and all 0 and 1 are grouped together 
Given a binary string contains only 0 and 1, find the number of substrings that contain an equal number of 0s and 1s and all the 0s and 1s are grouped together. Note that duplicate substrings are also counted in the answer.

Eg. s="011001"
Ans: 4 [01,1100,10,01]


Intuition: ----------------------------------------------------

Eg. s="011001"

Step 1: Group Same Characters Together
Final groups array = [1, 2, 2, 1]
    1 zero
    2 ones
    2 zeros
    1 one

Step 2: Count Valid Substrings from Adjacent Groups
Now for every pair of adjacent groups, the number of valid substrings we can form = minimum of the two group sizes.

Let’s go through each pair:

(1, 2) → min(1, 2) = 1
→ substring: "01"

(2, 2) → min(2, 2) = 2
→ substrings: "10" and "1100"

(2, 1) → min(2, 1) = 1
→ substring: "01"

So total substrings = 1 + 2 + 1 = 4


*/

int countBinarySubstrings(string s) {
    vector<int> groups;
    int count = 1;

    // Step 1: Group same characters
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            groups.push_back(count);
            count = 1;
        }
    }
    groups.push_back(count); // Push the last group

    // Step 2: Count valid substrings
    int result = 0;
    for (int i = 1; i < groups.size(); i++) {
        result += min(groups[i - 1], groups[i]);
    }

    return result;
}

int main() {
    string s = "011001";
    cout << countBinarySubstrings(s) << endl;
    return 0;
}

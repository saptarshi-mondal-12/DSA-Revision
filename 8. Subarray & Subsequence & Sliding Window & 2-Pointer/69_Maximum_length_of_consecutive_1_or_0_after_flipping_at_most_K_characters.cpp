#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Maximum length of consecutive 1s or 0s after flipping at most K characters

Given a binary string S of size N and an integer K, the task is to find the maximum length of consecutive 1s or 0s after flipping at most K characters of the given binary string S.

Input: S = “1001”, K = 1
Output: 3
Explanation: Flip the K(= 1) characters at index 3 of the string modifies the string S to “1000”. Now the maximum length of consecutive 0s is 3, which is the required result.

Input: S = “11011011”, K = 3
Output: 8

Intuition: 
a=First check for max consecutive 1 after flipping at most K 0's
b=Second check for max consecutive 0 after flipping at most K 1's

then take max length i.e max(a,b), both of them and return as answer.
*/

int maxLength(string s, char c, int k){
    int n = s.size();
    
    // Stores the maximum length
    int ans = -1;
 
    // Stores the count of char 'c'
    int cnt = 0;

    int left = 0;
 
    for (int right = 0; right < n; right++) {

        if (s[right] == c) {
            cnt++;
        }

        // Remove the extra 'c' from left
        while (cnt > k) {
            if (s[left] == c) {
                cnt--;
            }
            // Increment the value of the left
            left++;
        }
 
        // Update the resultant maximum length of character ch
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int maxConsecutiveSegment(string s, int k){
    // Time Complexity: O(N) + O(N)
    // Auxiliary Space: O(1)
    
    int n = s.length();
 
    // Print the maximum of the maximum length of 0s or 1s
    return max(maxLength(s, '0', k), maxLength(s, '1', k));
}

int main(){
    string s="11011011";
    int k=3;
    cout<<maxConsecutiveSegment(s,k)<<endl;
}
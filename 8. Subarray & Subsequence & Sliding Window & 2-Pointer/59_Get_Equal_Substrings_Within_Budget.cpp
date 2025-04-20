#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Get Equal Substrings Within Budget

You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.

Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.

Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You cannot make any change, so the maximum length is 1.
*/

int equalSubstring(string s, string t, int maxCost) {
    // Time complexity: O(n)
    // space complexity: O(1)

    int n=s.size();
    int maxLen=0;
    long long int currCost=0;
    int left=0, right=0;;
    while(right<n){
        currCost += abs((s[right]-'a') - (t[right]-'a'));
        // Remove the indices from the left end till the cost becomes less than the allowed
        while(currCost > maxCost){
            currCost -= abs((s[left]-'a') - (t[left]-'a'));
            left++;
        }
        maxLen=max(maxLen, right-left+1);
        right++;
    }
    return maxLen;



    // Brute Soln-------------------------------------------------
    // Time complexity: O(n^2)
    // space complexity: O(1)
    // int n=s.size();
    // int maxLen=0;
    // for(int i=0;i<n;i++){
    //     int currCost=0;
    //     for(int j=i;j<n;j++){
    //         currCost += abs((s[j]-'a') - (t[j]-'a'));
    //         if (currCost <= maxCost){
    //             maxLen=max(maxLen, j-i+1);
    //         }
    //     }
    // }
    // return maxLen;
}

int main(){
    string s="abcd";
    string t="bcdf";
    int maxCost=3;
    cout<<equalSubstring(s, t, maxCost)<<endl;
}
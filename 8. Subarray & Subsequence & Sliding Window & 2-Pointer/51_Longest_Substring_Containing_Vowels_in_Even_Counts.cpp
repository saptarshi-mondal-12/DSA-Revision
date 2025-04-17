#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Find the Longest Substring Containing Vowels in Even Counts

Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
*/

bool hasEvenVowels(const unordered_map<char, int>& count) {
    return count.at('a') % 2 == 0 &&
        count.at('e') % 2 == 0 &&
        count.at('i') % 2 == 0 &&
        count.at('o') % 2 == 0 &&
        count.at('u') % 2 == 0;
}
int findTheLongestSubstring(string s) {
    // Time Complexity:	O(n²)
    // Space complexity: O(1) 

    int n=s.size();
    int result=0;
    for(int i=0;i<n;i++){
        unordered_map<char, int> mp = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        for(int j=i;j<n;j++){
            mp[s[j]]++;
            if(hasEvenVowels(mp)){
                result = max(result, j - i + 1);
            }
        }
    }
    return result;
}

int main(){
    string s = "eleetminicoworoep";
    cout<<findTheLongestSubstring(s)<<endl;

}
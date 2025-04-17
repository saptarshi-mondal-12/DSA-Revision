#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*Longest repeating character replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA". The substring "BBBB" has the longest repeating letters, which is 4. There may exists other ways to achieve this answer too.
*/

int longest_repeating_character_replacement(string s, int k){
    // Time complexity - O(n^2)
    // space complexity - O(26)

    int n=s.size();
    int result=0;
    for(int i=0;i<n;i++){
        unordered_map<char, int>mp;
        int maxFreq=0;
        for(int j=i;j<n;j++){
            mp[s[j]]++;
            maxFreq=max(maxFreq, mp[s[j]]);
            int changes=(j-i+1)-maxFreq;
            if(changes <= k){
                result=max(result, j-i+1);
            }else{
                break;
            }
        }
    }
    return result;
}

int better_longest_repeating_character_replacement(string s, int k){
    // Time complexity - O(n+n) - O(2n)
    // space complexity - O(26)


    // note = int TotalChangeRequired = (right-left+1) - maxFreq;

    int n=s.size();
    int result=0;
    map<char, int>mp;
    int left=0, right=0;
    int maxFreq=0;
    while(right<n){
        mp[s[right]]++;
        maxFreq=max(maxFreq, mp[s[right]]);

        while ((right-left+1) - maxFreq > k){
            mp[s[left]]--;
            if (mp[s[left]] == 0){
                mp.erase(s[left]);
            }
            maxFreq=max(maxFreq, prev(mp.end())->second);
            left++;
        }
        if ((right-left+1) - maxFreq <= k){
            result=max(result, right-left+1);
        }
        right++;
    }
    return result;
}

int optimal_longest_repeating_character_replacement(string s, int k){
    // Time complexity - O(n)
    // space complexity - O(26)

    int n=s.size();
    int result=0;
    map<char, int>mp;
    int left=0, right=0;
    int maxFreq=0;
    while(right<n){
        mp[s[right]]++;
        maxFreq=max(maxFreq, mp[s[right]]);

        if ((right-left+1) - maxFreq > k){
            mp[s[left]]--;
            if (mp[s[left]] == 0){
                mp.erase(s[left]);
            }
            left++;
        }
        if ((right-left+1) - maxFreq <= k){
            result=max(result, right-left+1);
        }
        right++;
    }
    return result;

}

int main(){
    string s="AABABBA";
    int k=2;

    // brute
    cout<<longest_repeating_character_replacement(s,k)<<endl;

    // better
    cout<<better_longest_repeating_character_replacement(s,k)<<endl;

    // optimal
    cout<<optimal_longest_repeating_character_replacement(s,k)<<endl;

}
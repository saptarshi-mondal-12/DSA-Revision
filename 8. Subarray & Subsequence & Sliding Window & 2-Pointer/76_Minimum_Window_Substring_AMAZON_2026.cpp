#include<bits/stdc++.h>
using namespace std;

/* Q. Minimum Window Substring - AMAZON 2026

Given two strings s and t, Find the samllest substring of the first string that contains all the characters of the second string, including their frequencies.

Input: s = "timetopractice", t = "toc"
Output: "toprac"

*/

string brute_solve(string s, string t){
    // Time complexity: O(n^2)
    // Space complexity: O(1)

    // Intuition : Check all substrings of s and check if they contain all characters of t with their frequencies.

    int n = s.size();
    int m = t.size();

    string ans = "";
    int min_len = INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            string sub = s.substr(i, j-i+1);
            unordered_map<char, int> mp;
            for(auto it: sub){
                mp[it]++;
            }

            bool flag = true;
            for(auto it: t){
                if(mp.find(it) == mp.end() || mp[it] == 0){
                    flag = false;
                    break;
                }
                else{
                    mp[it]--;
                }
            }

            if(flag && sub.size() < min_len){
                min_len = sub.size();
                ans = sub;
            }
        }
    }

    return ans;
}

string optimal_solve(string s, string t){
    // Time complexity: O(n)
    // Space complexity: O(n)

    // Intuition : Use sliding window technique to find the smallest substring of s that contains all characters of t with their frequencies.
    // step 1: Create a map of characters of t and their frequencies.
    // step 2: Use two pointers to create a window and check if the window contains all characters of t with their frequencies.   


    unordered_map<char, int> mp;
    for(auto it: t){
        mp[it]++;
    }

    int left = 0, right = 0;
    int count = mp.size();
    int min_len = INT_MAX;
    string ans = "";

    while(right < s.size()){
        if(mp.find(s[right]) != mp.end()){
            mp[s[right]]--;
            if(mp[s[right]] == 0){
                count--;
            }
        }

        while(count == 0){
            if(right - left + 1 < min_len){
                min_len = right - left + 1;
                ans = s.substr(left, min_len);
            }

            if(mp.find(s[left]) != mp.end()){
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    count++;
                }
            }
            left++;
        }
        right++;
    }

    return ans;
}


int main(){
    string s = "timetopractice";
    string t = "toc";

    // 1. brute force solution
    cout<<brute_solve(s, t)<<endl;

    // 2. optimal solution
    cout<<optimal_solve(s, t)<<endl;
}
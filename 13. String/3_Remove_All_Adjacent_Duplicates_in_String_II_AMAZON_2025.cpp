#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Remove All Adjacent Duplicates in String II - AMAZON 2025 - 2 times

You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.


Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: First delete "eee" and "ccc", get "ddbbbdaa". Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"


*/

string brute_removeDuplicates(string s, int k){
    // Time complexity: O(n*k)
    // Spacecomplexity: O(n)

    int n = s.size();
    vector<char> v;

    for (int i = 0; i < n; i++){
        v.push_back(s[i]);

        if (v.size() >= k){
            bool allEqual = true;
            // check last k chars
            for (int j = v.size() - k + 1; j < v.size(); j++){ // O(k) check
                if (v[j] != v[j - 1]){
                    allEqual = false;
                    break;
                }
            }
            // if all last k chars equal → remove them
            if (allEqual){
                v.erase(v.end() - k, v.end()); // O(k)
            }
        }
    }
    string ans = "";
    for (auto it : v){
        ans += it;
    }
    return ans;
}


string optimal_removeDuplicates(string s, int k) {
    // Time complexity: O(n)
    // Spacecomplexity: O(n)

    int n=s.size();

    // {char, frequency}
    vector<pair<char,int>>v;

    for(int i=0;i<n;i++){
        if(!v.empty() && v.back().first == s[i]){
            v.back().second++;
            if (v.back().second == k) v.pop_back();
        }else{
            v.push_back({s[i], 1});
        }
    }
        
    string ans = "";
    for(auto it: v){
        char ch = it.first;
        int freq = it.second;

        // repeat ch freq times 
        ans += string(freq, ch); 
    }

    return ans;
}

int main(){
    string s = "deeedbbcccbdaa";
    int k=3;

    // 1. brute soln 
    cout<<brute_removeDuplicates(s, k)<<endl;


    // 2. optimal soln 
    cout<<optimal_removeDuplicates(s, k)<<endl;
}
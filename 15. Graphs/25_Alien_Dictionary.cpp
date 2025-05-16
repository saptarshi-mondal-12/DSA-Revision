#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Alien Dictionary

A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.


Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary.
So, 'c' → 'a' → 'b' is a valid ordering.


Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.


Intuition: -----------------------------------------------------------------

kahn's algo 

Let’s consider the first example where N = 5, K = 4 and dict = {"baa", "abcd", "abca", "cab", "cad"}. So, here we need to find out the correct ordering of the first 4 letters of the alphabet(i.e. ‘a’, ‘b’, ‘c’, ‘d’). If we consider the first 2 words and try to figure out why “baa” appears before “abcd”, we can clearly observe that they are differentiated by the first letter i.e. ‘b’ and ‘a’. That is why, we can conclude that in the alien dictionary, ‘b’ appears before ‘a’( i.e. ‘b’ is smaller than ‘a’). We can correspond this differentiating factor to a directed graph like the following:

(b)------>(a)


The follow-up question for the interview:

Q. When is the ordering not possible?
Ans: There are two such cases when ordering is not possible:

1. If every character matches and the largest word appears before the shortest word: For example, if “abcd” appears before “abc”, we can say the ordering is not possible.
    
2. If there exists a cyclic dependency between the characters: For example, in the dictionary: dict: {“abc”, “bat”, “ade”} there exists a cyclic dependency between ‘a’ and ‘b’ because the dictionary states ‘a’ < ‘b’ < ‘a’, which is not possible.

*/

string findOrder(vector<string> &words){
    // Time Complexity: O(n * m)
    // Space complexity: O(26)

    int n = words.size();

    // Adjacency list
    vector<vector<int>> adj(26);

    // In-degree of each character
    vector<int> inDegree(26, 0);

    // Tracks which characters are present
    vector<bool> exists(26, false);

    // Mark existing characters
    for (const string &word : words){
        for (char ch : word){
            exists[ch - 'a'] = true;
        }
    }

    // Build the graph from adjacent words
    for (int i = 0; i < n - 1; i++){
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.length(), s2.length());
        bool check = false;
        for (int j = 0; j < len; j++){
            if (s1[j] != s2[j]){
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';
                adj[u].push_back(v);
                inDegree[v]++;
                check = true;
                break;
            }
        }
        if (!check && s1.length() > s2.length()){
            return "";
        }
    }

    // if character is present and its indegree is 0
    // push it into queue
    queue<int> q;
    for (int i = 0; i < 26; i++){
        if (exists[i] && inDegree[i] == 0){
            q.push(i);
        }
    }

    string result = "";
    while (!q.empty()){
        int node = q.front();
        q.pop();
        result += (char)(node + 'a');

        for (int it : adj[node]){
            inDegree[it]--;
            if (inDegree[it] == 0){
                q.push(it);
            }
        }
    }

    // Check, there was a cycle or not
    for (int i = 0; i < 26; i++){
        if (exists[i] && inDegree[i] > 0){
            return "";
        }
    }
    return result;
}

int main(){
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    cout<<findOrder(words);
}
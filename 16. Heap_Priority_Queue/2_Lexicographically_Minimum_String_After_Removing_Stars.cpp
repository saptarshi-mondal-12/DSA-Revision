#include <iostream>
using namespace std;
#include <bits/stdc++.h>

/* Q. Lexicographically Minimum String After Removing Stars

You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.



Input: s = "aaba*"
Output: "aab"
Explanation: We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.


Input: s = "abc"
Output: "abc"
Explanation: There is no '*' in the string.
*/

// Custom comparator for priority queue
struct Compare{
    bool operator()(const pair<char, int> &a, const pair<char, int> &b){
        if (a.first == b.first)
        {
            // For same char, bigger index has higher priority (top)
            return a.second < b.second; // smaller index is "less"
        }
        // Smaller char has higher priority
        return a.first > b.first; // bigger char is "less"
    }
};

string clearStars(string s){
    // Time complexity: O(n log n)
    // space complexity: O(n)

    int n = s.size();
    vector<bool> removed(n, false);
    priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;

    for (int i = 0; i < n; ++i){
        if (s[i] != '*'){
            pq.push({s[i], i});
        }
        else{
            int index = pq.top().second;
            pq.pop();
            removed[index] = true;
        }
    }

    string result;
    for (int i = 0; i < n; i++){
        if (s[i] != '*' && removed[i] == false){
            result.push_back(s[i]);
        }
    }
    return result;





    // Time complexity: O(n) + O(n^2) + O(n) = O(n^2)
    // int n=s.size();
    // // Total no of stars
    // vector<int>starIndex;
    // for(int i=0;i<n;i++){
    //     if(s[i]=='*'){
    //         starIndex.push_back(i);
    //     }
    // }
    // if(starIndex.size() == n) return "";
    // for(int i=0;i<starIndex.size();i++){
    //     int index=starIndex[i];
    //     // Finding smallest char to its left
    //     char minChar='z'+1;
    //     int miniIndex=-1;
    //     for(int j=0;j<index;j++){
    //         if(s[j] != '*' && s[j] <= minChar){
    //             minChar=s[j];
    //             miniIndex=j;
    //         }
    //     }
    //     s[miniIndex] = '*';
    // }
    // s.erase(remove(s.begin(), s.end(), '*'), s.end());
    // return s;
}

int main(){
    string s="aaba*";
    cout<<clearStars(s)<<endl;
}
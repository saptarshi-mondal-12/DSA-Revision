#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q Longest String Chain

You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


Intuition: 

words = {"a","b","ba","bca","bda","bdca"}
Longest strig chain = ['a', 'ba', 'bca', 'bdca']

We need to print the length of the longest string chain, in this case: 4.
Two consecutive strings in this string chain need to have an insertion of a single character. The character can be added to any place on the string.

Note: This question Longest String Chain expects us to find the longest chain subset instead of subsequence, therefore we will first sort the array (on the basis of the length of the string) to get the answer
*/


bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}


int longestStrChain(vector<string>& arr){
    // Time complexity: O(N*N*L) - We are setting up two nested loops and the compare function can be estimated to L, where L is the length of the longest string in the words [ ] array. Also, we are sorting so the time complexity will be (N^2 * L + NlogN)
    // Space complexity: O(N)

    int n = arr.size();
    
    //sort the array
    sort(arr.begin(), arr.end(),comp);
    vector<int> dp(n,1);
    
    int maxi = 1;
    
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if( compare(arr[i], arr[prev_index]) && 1 + dp[prev_index] > dp[i]){
                dp[i] = 1 + dp[prev_index];
            }
        }
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    return maxi;
}

int main(){
    vector<string>words = {"a","b","ba","bca","bda","bdca"};
    cout<<longestStrChain(words)<<endl;
}
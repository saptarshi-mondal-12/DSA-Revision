#include<iostream>
#include<bits/stdc++.h>
using namespace std;


/* Count Substrings That Can Be Rearranged to Contain a String I

You are given two strings word1 and word2. A string x is called valid if x can be rearranged to have word2 as a 
prefix. Return the total number of valid substrings of word1.

Input: word1 = "bcca", word2 = "abc"
Output: 1
Explanation: The only valid substring is "bcca" which can be rearranged to "abcc" having "abc" as a prefix.

Input: word1 = "abcabc", word2 = "abc"
Output: 10
Explanation: All the substrings except substrings of size 1 and size 2 are valid.

Input: word1 = "abcabc", word2 = "aaabc"
Output: 0
*/

int brute_validSubstringCount(string word1, string word2){
    int result=0;
    int n=word1.size();
    int m=word2.size();
    for(int i=0;i<n;i++){
        int hash[256]={0};
        int count=0;

        // Pre inserting the word 2
        for(int j=0;j<m;j++){
            hash[word2[j]]++;
        }
        for(int j=i;j<n;j++){
            if (hash[word1[j]] > 0){
                count+=1;
            }
            hash[word1[j]]--;
            if(count==m){
                result++;
            }
        }
    }
    return result;
}

int optimal_validSubstringCount(string word1, string word2){
    int n=word1.size();
    int m=word2.size();
    long long int result=0;
    int hash[256]={0};
    for(int i=0;i<m;i++){
        hash[word2[i]]++;
    }
    int left=0, right=0;
    int count=0;
    while(right < n){
        if (hash[word1[right]] > 0){
            count++;
        }
        hash[word1[right]]--;
        while (count==m){
            result=result+(n-right);
            hash[word1[left]]++;
            if(hash[word1[left]] > 0){
                count--;
            }
            left++;
        }
        right++;
    }
    return result;
}

int main(){
    string s="bcca";
    string t="abc";

    // brute
    cout<<brute_validSubstringCount(s,t)<<endl;

    // optimal
    cout<<optimal_validSubstringCount(s,t)<<endl;
}
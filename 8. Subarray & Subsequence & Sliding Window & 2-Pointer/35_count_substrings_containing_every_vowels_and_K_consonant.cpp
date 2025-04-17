#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Count of Substrings Containing Every Vowel and K Consonants II

You are given a string word and a non-negative integer k. Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 
Input: word = "aeioqq", k = 1
Output: 0
Explanation: There is no substring with every vowel.

Input: word = "aeiou", k = 0
Output: 1
Explanation: The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Input: word = "ieaouqqieaouqq", k = 1
Output: 3
Explanation: The substrings with every vowel and one consonant are:
word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".


Intuition: 
The key intuition behind the equation:

exactlyK(word, k) = atLeastK(word, k) - atLeastK(word, k+1)

is that it helps count substrings with exactly k consonants using a simpler approach.

Defining atLeastK(word, k):
    a. This counts the number of substrings that contain at least k consonants and all vowels.
    b. If a substring is valid for k consonants, it is also valid for k+1, k+2, etc.
    c. Expanding the substring beyond k consonants keeps it valid.

Why Does Subtracting Work?
    a. atLeastK(word, k) includes substrings with k, k+1, k+2, ... consonants.
    b. atLeastK(word, k+1) includes substrings with k+1, k+2, k+3, ... consonants.
    c. The difference atLeastK(word, k) - atLeastK(word, k+1) leaves only substrings that have exactly k consonants.

eg. 
Example String: "aeibcd"

Given k = 2 (Count substrings with exactly 2 consonants)

Step 1: Compute atLeastK(word, k)
Find substrings with at least 2 consonants and all vowels (a, e, i, o, u) present.

Valid substrings (containing all vowels and at least 2 consonants):

"aeibc"
"aeibcd"

Count = 2

Step 2: Compute atLeastK(word, k+1)
Find substrings with at least 3 consonants and all vowels present.

Valid substrings:

"aeibcd"

Count = 1

Step 3: Compute exactlyK(word, k)
exactlyK(word, 2) = atLeastK(word, 2) - atLeastK(word, 3)
exactlyK(word, 2) = 2 - 1 = 1

So, there is exactly 1 substring with all vowels and exactly 2 consonants.
*/

int brute_countOfSubstrings(string word, int k){
    // Time complexity - O(n^2)
    // Space complexity - O(n)

    int n=word.size();
    int result=0;
    for(int i=0;i<n;i++){
        int hash[256]={0};
        int countConsonant=0;
        for(int j=i;j<n;j++){
            if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u' ){
                hash[word[j]]++;
            }else{
                countConsonant+=1;
            }
            if (hash['a']!=0 && hash['e']!=0 && hash['i']!=0 && hash['o']!=0 && hash['u']!=0 && countConsonant == k){
                result++;
            }
        }
    }
    return result;   
}

long atLeastK(string word, int k) {
    long numValidSubstrings = 0;
    int start = 0;
    int end = 0;
    // Keep track of counts of vowels and consonants.
    unordered_map<char, int> vowelCount;
    int consonantCount = 0;

    // Start sliding window.
    while (end < word.length()) {
        // Insert new letter.
        char ch = word[end];

        // Update counts.
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowelCount[ch]++;
        }else {
            consonantCount++;
        }

        // Shrink window while we have a valid substring.
        while (vowelCount.size() == 5 and consonantCount >= k) {
            numValidSubstrings += word.length() - end;

            char ch = word[start];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount[ch]--;
                if (vowelCount[ch] == 0) {
                    vowelCount.erase(ch);
                }
            } else {
                consonantCount--;
            }
            start++;
        }

        end++;
    }

    return numValidSubstrings;
}

long better_countOfSubstrings(string word, int k) {
    return atLeastK(word, k) - atLeastK(word, k + 1);
}



int main(){
    string s="ieaouqqieaouqq";
    int k=1;

    // brute
    cout<<brute_countOfSubstrings(s, k)<<endl;

    // better
    cout<<better_countOfSubstrings(s, k)<<endl;
}
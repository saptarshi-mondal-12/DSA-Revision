#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Amazon OA 

A substring of a string is redundant if length of substring i.e. L = |substring| = A*V + B*C where A and B are integers given to us and V and C are the number of vowels and consonants in the substring. Find count of all such redundant substrings of a given string. Assume that string has only lower case english alphabets.

Eg: Given string “abbacc” , A = -1 , B = 2
ans: 5
“abb” [len = 3 , V=1, C =2] [-1*1 + 2*2]
“bba”
“bac”
“acc”
“abbacc”

photo: https://www.reddit.com/r/leetcode/s/clfd6Kdm9y


Intuition--------------

The Main Idea:
Prefix Count for Vowels and Consonants:
Track the number of vowels and consonants encountered as we move through the string. For each index i, we know how many vowels and consonants are in the substring from index 0 to i.

Transform the Equation:
For each index i, calculate a score (or difference) based on the number of vowels and consonants seen so far:
    score=A×vowels so far+B×consonants so far−(length of substring)

This score represents the difference between the left-hand side (the formula) and the right-hand side (the substring length). If the score for a substring starting from some index j to i is 0, then that substring satisfies the condition.

Hash Map (score_count):
    We use a hash map (score_count) to store how many times each score has occurred as we process the string.
    If the same score occurs again at index i, it means there exists a valid substring ending at i and starting from some previous index j. This is because the difference between the score at i and the score at j is zero, meaning the substring between these indices satisfies the equation.

Key Formula:
As we go through each character in the string, we keep updating the score.

The key observation is that when the same score is seen multiple times, the difference between the occurrences of that score corresponds to valid substrings.*/

int brute_countRedundantSubstrings(string word, int A, int B){
    // Time complexity: O(N^2)
    // Space complexity: O(1)

    int n=word.size();
    int count=0;
    for(int i=0;i<n;i++){
        int V=0, C=0;
        for(int j=i;j<n;j++){
            if(word[j]=='a' || word[j]=='e' || word[j]=='i' || word[j]=='o' || word[j]=='u'  ){
                V++;
            }else{
                C++;
            }

            // if length matches of current substring, then count++
            if((j-i+1) == (A*V + B*C)){
                count++;
            }
        }
    }
    return count;
}


int optimal_countRedundantSubstrings(string word, int A, int B){
    // thinking For each index i can we calculate the score (A*V + B*C) 
    // if (socre - length) = 0 then valid count++ i.e initialize with {0:1}

    int n=word.size();

    unordered_map<int, int> score_count;
    score_count[0] = 1; // For handling substrings starting at index 0

    int V = 0, C = 0, score = 0, count = 0;

    for (int i = 0; i < word.size(); ++i) {
        char ch = word[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            V++;
        } else {
            C++;
        }

        score = A * V + B * C - (i + 1);

        // If this score was seen before, it means there exists a prefix that can be removed to make the substring redundant
        if (score_count.count(score)) {
            count += score_count[score];
        }

        score_count[score]++;
    }

    return count;
}

int main(){
    // string word = "abbacc";
    // int A=-1, B=2;


    // string word = "akljfs";
    // int A=-2, B=1;


    string word = "afejipl";
    int A=4, B=-2;

    // Brute
    cout<<brute_countRedundantSubstrings(word, A, B)<<endl;

    // Optimal
    cout<<optimal_countRedundantSubstrings(word, A, B)<<endl;
}


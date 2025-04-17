#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Longest valid Parenthesis

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Input: s = ""
Output: 0
*/



void brute_LongestValid(string s){
    // Time complexity = O(n)
    // space complexity = O(n)

    stack<int>st;
    st.push(-1);
    int result=0;
    
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            st.push(i);
        }
        else{
            st.pop();

            if(st.empty()){
                st.push(i);
            }else{ 

                // we find a valid parenthesis
                result=max(result, i-st.top());
            }
        }
    }
    cout<<result<<endl;
}


void optimal_LongestValid(string s){
    // Time complexity = O(n)
    // space complexity = O(1)


    int left=0;
    int right=0;
    int maxLength=0;

    // Iterating the string from left to right
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            left+=1;
        }else{
            right+=1;
        }

        /* When L and R become equal, we have found a valid substring*/

        if(left==right){
            maxLength=max(maxLength,2*right);
        }

        /* When R becomes greater than L, it means we have more ‘)’ than ‘(‘ in our substring, this cannot be a valid substring. Hence, we reset R and L to zero, equivalent to making the substring empty.*/
        else if(left < right){
            left=0;
            right=0;
        }
    }

    // Iterating the string from left to right
    /* This is done because it is possible to miss the longest substring while we traverse left to right. */
    left=0;
    right=0;

    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='('){
            left+=1;
        }else{
            right+=1;
        }

        if(left==right){
            maxLength=max(maxLength,2*right);
        }
        else if(left > right){
            left=0;
            right=0;
        }
    }
    cout<<maxLength<<endl;
}


int main(){
    
    // string s="(()";
    // output=2

    
    // string s=")()())";
    // output=4
    
    // string s="((()()()()(((())";
    // output=8

    // string s="((())))()";
    // output=6


    // form checking left to right it gives output = 0 but from checking right to left it gives output = 2 
    // i.e we use left to right and right to left
    string s="(()";

    // brute
    brute_LongestValid(s);

    // optimal
    brute_LongestValid(s);
}
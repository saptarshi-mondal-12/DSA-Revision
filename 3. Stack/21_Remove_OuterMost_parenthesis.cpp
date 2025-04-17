#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Remove Outermost Parentheses

Given a valid parentheses string s, consider its primitive decompositios.Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Input: s = "(()())(())"
Output: "()()()"
Explanation: The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".


Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Input: s = "()()"
Output: ""
Explanation: The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
*/

string removeOuterMostParenthesis(string s){
    // Time complexity: O(n)
    // space complexity: O(n)

    string result;
    int n=s.size();
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='('&& count==0){
            count++;
        }else if(s[i]=='(' && count>=1){
            result+=s[i];
            count++;
        }else if(s[i]==')' && count>1){
            result+=s[i];
            count--;
        }else if(s[i]==')' && count==1){
            count--;
        }
    }
    return result;
}

int main(){
    // string s="(()())(())"; // "()()()""
    // string s="()()"; // ""
    // string s= "(()())(())(()(()))"; // "()()()()(())"
    string s= "(()(()))"; // "()(())"


    string result=removeOuterMostParenthesis(s);
    for(int i=0;i<result.size();i++){
        cout<<result[i];
    }
}
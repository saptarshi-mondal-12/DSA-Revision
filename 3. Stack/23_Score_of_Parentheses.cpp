#include<iostream>
#include<stack>
using namespace std;

/* Q. Score of Parentheses

Given a balanced parentheses string s, return the score of the string.
The score of a balanced parentheses string is based on the following rule:
    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

Input: s = "()"
Output: 1

Input: s = "(())"
Output: 2

Input: s = "()()"
Output: 2
 

*/

int scoreOfParentheses(string s) {
    int n=s.size();
    int score=0;
    int multiply=1;
    int i=0;
    while(i<n){
        if(s[i]=='(' && s[i+1]=='('){
            multiply*=2;
        }
        else if(s[i]=='(' && s[i+1]==')'){
            score=score + multiply;
            i+=1;
        }
        else if(s[i]==')'){
            multiply/=2;
        }
        i+=1;
    }
    return score;
}

int main(){
    string s="(()(()))";
    cout<<scoreOfParentheses(s);
}
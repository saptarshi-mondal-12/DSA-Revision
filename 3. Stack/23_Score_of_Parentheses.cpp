#include<iostream>
#include<stack>
using namespace std;

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
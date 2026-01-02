#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;

            char top = st.top();
            if ((top == '(' && ch == ')') ||
                (top == '{' && ch == '}') ||
                (top == '[' && ch == ']')) {
                st.pop();
            } else {
                return false;   // MISMATCH
            }
        }
    }

    return st.empty();
}


int main(){
    string s = "()()()[]()";
    if (isValid(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
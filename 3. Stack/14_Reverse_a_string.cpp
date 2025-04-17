#include<iostream>
#include<stack>
using namespace std;

// Time complexity - O(n) + O(n)
// space comlexity - O(1)

string reverse(string s){

    stack<char>st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }

    int i=0;
    while(!st.empty()){
        s[i]=st.top();
        st.pop();  
        i++;
    }
    return s;
}

int main(){
    string s="abcde";
    cout<<reverse(s)<<endl;
}
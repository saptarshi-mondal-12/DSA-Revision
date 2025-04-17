#include<iostream>
#include<stack>
using namespace std;



// check if expression contain redundant parenthesis - bina matlab ka braces

// Time complexity - O(n)
// space complexity - 

bool redundant(string s){
    stack<char> st;
    bool ans=false;
    for(int i=0;i<s.length();i++){
        if (s[i]=='(' or s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            // if there is empty between two bracket ( ),  it means it has redundant brackets
            if (st.top()=='('){
                ans= true;
            }
            while (st.top()=='+' or st.top()=='-' or st.top()=='*' or st.top()=='/'){
                st.pop();
            }
            st.pop();
        }
    }
    return ans;

}


int main(){

    string s="()";
    if(redundant(s)){
        cout<<"Redundant"<<endl;
    }else{
        cout<<"not Redundant"<<endl;
    }
    
}

#include<iostream>
#include<stack>
using namespace std;

/* Reverse a string

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Input: s = "God Ding"
Output: "doG gniD"
*/

string brute_reverse(string s){
    // Time complexity - O(n)
    // space complexity - O(n)

    int n=s.size();
    stack<char>st;
    string result="";

    for(int i=0;i<n;i++){
        if (s[i]!=' '){
            st.push(s[i]);
        }else{
            while(!st.empty()){
                result+=st.top();
                st.pop();
            }
            result+=" ";
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    return result;
}

string optimal_reverse(string s){
    // Time complexity - O(n)
    // space complexity - O(1)

    int n=s.size();
    int left=0, right=0;

    for(int i=0;i<n;i++){
        if(s[i]==' '){
            right=i-1;
            
            while(left<right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            left=i+1;
        }
    }

    right=n-1;
    while(left<right){
        swap(s[left],s[right]);
        left++;
        right--;
    }

    return s;
}


int main(){
    string s="Let's take LeetCode contest";

    // 1. brute 
    cout<<brute_reverse(s)<<endl;

    // 2. optimal
    cout<<optimal_reverse(s)<<endl;

}
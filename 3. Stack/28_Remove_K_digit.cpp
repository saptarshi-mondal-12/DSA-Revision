#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

/*
Intuition :
    Removing only max element from string does'nt give us smallest because
    num=1432219 , k=3 => max are : 9,4,3 
    after removing = 1221 but smallest is 1219

    If num sorted removing only k max digit is our answer
    for e.g num=12345, k=2 result=123 is smalles 

    So if i keep smaller digit at first and get rid of larger once then we get smallest number.
    initial digit are as small as possible 
*/

string removeKdigits(string num, int k){
    // Time complexity - O(3n) + O(k)
    // space complexity - (n) + O(n)
        
    int n=num.size();

    // if n==k means remove all element then return 0
    if (n==k){
        return "0";
    }

    // declare stack to store element
    stack<char>st;

    for(int i=0;i<n;i++){
        int curr=num[i];

        while(!st.empty() && st.top()-'0' > curr-'0' && k > 0){
            st.pop();
            k-=1;
        }
        st.push(num[i]);
    }

    // if k is still left remove it
    while(k>0 && !st.empty()){
        st.pop();
        k-=1;
    }

    // after removal check if stack is empty
    if (st.empty()){
        return "0";
    }

    string result="";
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    // removing preceding zero
    while(result.size()!=0 && result.back()=='0'){
        result.pop_back();
    }

    if (result.size()==0) {
        return "0";
    }

    // reverse the string 
    reverse(result.begin(),result.end());
        
    return result;
}

int main(){
    string num="1432219";
    int k=3;

    cout<<removeKdigits(num, k);

}
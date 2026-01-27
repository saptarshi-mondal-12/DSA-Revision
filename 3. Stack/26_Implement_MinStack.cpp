#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// insert = 2*val-min;
// retrive = 2*mini-st.top()

/* Smaller val than min then its modified value */

class brute_MinStack{
    // Time complexity: O(1)
    // Space complexity: O(2n)
    public:
    stack<pair<int, int>>st;

    void push(int x){
        int min;
        if(st.empty()){
            min=x;
        }else{
            min=std::min(st.top().second, x);
        }
        st.push({x,min});
    }
    void pop(){
        st.pop();
    }
    int top(){
        return st.top().first;

    }
    int getMin(){
        return st.top().second;
    }
};

class optimal_MinStack{
    // Time complexity: O(1)
    // Space complexity: O(n)

    /* if val is smaller than min then its a modified value - so we return min
    if val is greater than min then it is not modified value - so we val itself
    */


    public:
    stack<long long> st;
    long long mini;

    optimal_MinStack(){
        mini=INT_MAX;
    }

    void push(int x){
        long long val=x;
        if(st.empty()){
            mini=val;
            st.push(val);
        }else{
            if(val<mini){
                st.push(2*val*1LL-mini);
                mini=val;
            }else{
                st.push(val);
            }
        }
    }
    void pop(){
        if(!st.empty()){
            long long el=st.top();
            st.pop();
            if(el<mini){
                mini=2*mini-el;
            }
        }
    }
    int top(){
        if(st.empty()){
            return -1;
        }
        long long el=st.top();
        if(el<mini){
            return mini;
        }else{
            return el;
        }

    }
    int getMin(){
        return mini;
    }
};

int main(){
    // optimal_MinStack s;
    brute_MinStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(-1);
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
}


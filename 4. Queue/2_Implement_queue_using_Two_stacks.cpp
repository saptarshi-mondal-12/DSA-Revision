#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Implement queue using 2 stack - AMAZON 2025

Intuition : By making enQueue operation costly: This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used.
*/

// Time Complexity: Push: O(N) (because we transfer elements twice), Pop: O(1), Front: O(1)
// Space Complexity: O(N)




class MyQueue{
    public:
   
    int top;
    stack<int>st, st2; // Two stacks

    // Push element to the back of queue
    void push(int x){
        // 1. Move all element to stack 2 
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }

        // 2. Push item (x) into st
        st.push(x);

        // 3. Push everything back to stack 1
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    }

    // Remove the element from the front of queue
    void pop(){
        // if stack is empty return 
        if(st.empty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        st.pop();
    }

    // Get the front element
    int front(){
        if(!st.empty()){
            return st.top();
        }
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"Front = "<<q.front()<<endl;
    q.pop();
    cout<<"Front = "<<q.front()<<endl;
}


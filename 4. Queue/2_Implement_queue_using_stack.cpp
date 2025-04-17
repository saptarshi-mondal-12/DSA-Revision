#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Implement queue using stack

Intuition : By making enQueue operation costly: This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just pops from stack1. To put the element at top of stack1, stack2 is used.
*/

// Time Complexity: Push: O(N), Pop: O(1)
// Space Complexity: O(N)



class Queue{
    public:
    int top;

    // Using 2 stack 
    stack<int>st, st2;

    void enqueue(int x){
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

    void dequeue(){
        // if stack is empty return 
        if(st.empty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        st.pop();
    }
    int front(){
        if(!st.empty()){
            return st.top();
        }
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
};

int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<"Front = "<<q.front()<<endl;
    q.dequeue();
    cout<<"Front = "<<q.front()<<endl;
}

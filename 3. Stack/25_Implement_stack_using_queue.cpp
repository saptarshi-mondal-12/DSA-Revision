#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Stack Operations: A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. Some stack operation are :
1. push() 
2. pop()
3. top()
4. isEmpty()

As we know stack follows last in first out, which means we get the most recently inserted element whenever we remove an element from the stack. But queue follows first in first out, it means we get that element which we inserted in the starting at each deletion, it means if we want to use the queue like a stack we have to arrange elements in the queue such that we get the most recent element at each deletion.

So, according to the FIFO rule of the queue, the second element that was inserted will be at the front and then the first element as it was pushed again later and its first copy was popped out. 

Take a single queue.
push(x): Push the element in the queue.
Use a for loop of size()-1, remove element from queue and again push back to the queue, hence the most recent element becomes the most former element and vice versa.
pop(): remove the element from the queue.
top(): show the element at the top of the queue.
size(): size of the current queue.
*/

class Stack{
    // Time Complexity: O(N)
    // Space Complexity: O(N)

    public:
    queue<int>q;
    
    // 1. PUSH =  push element x onto the stack
    void Push(int x){
        int n=q.size();

        // push the current element
        q.push(x);

        // pop all the previous element and put them after current element
        for(int i=0;i<n;i++){
            // pushing front element
            q.push(q.front());

            // deleting front element
            q.pop();
        }
    }

    // 2. POP = Remove element on top of the stack
    int Pop(){
        if (q.empty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }else{
            int n=q.front();
            q.pop();
            return n;
        }
    }
    
    // 3. TOP = return the top element from the stack
    int Top(){
        if (q.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return q.front();
    }

    // 4. EMPTY = check if stack is empty
    bool empty(){
        return q.empty();
    }

    // 5. SIZE = Return size of queue
    int Size(){
        return q.size();
    }
};

int main(){
    Stack st;

    st.Push(11);
    st.Push(22);
    st.Push(33);
    st.Push(44);
    st.Push(55);
    st.Push(66);

    cout<<"Top element = "<< st.Top()<<endl;
    cout<<"Size of the stack before removing element: " << st.Size() << endl;
    cout<<"The deleted element is: " << st.Pop() << endl;
    cout<<"Top of the stack after removing element: " << st.Top() << endl;
    cout<<"The deleted element is: " << st.Pop() << endl;
    cout<<"Top of the stack after removing element: " << st.Top() << endl;
    cout<<"Size of the stack after removing element: " << st.Size();
}
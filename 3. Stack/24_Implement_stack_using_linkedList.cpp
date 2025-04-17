#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Stack Operations: A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. Some stack operation are :
1. push(): Insert a new element into the stack i.e just insert a new element at the beginning of the linked list.
2. pop(): Return the top element of the Stack i.e simply delete the first element from the linked list.
3. top(): Return the top element.
4. isEmpty(): returns a boolean value for whether the stack is empty or not. simply chek if head == NULL. 
5. display(): print all element present in the stack



Explaining : 
In this implementation, we define a Node class that represents a node in the linked list, and a Stack class that uses this node class to implement the stack. The head attribute of the Stack class points to the top of the stack (i.e., the first node in the linked list).


*/

// Time complexity - O(1)
// space complexity - O(n)

// Class representing a node in the linked list
class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int val){
        data=val;
        next=NULL;
    }
};

// Class to implement stack using a singly linked list
class Stack{
    public:
    ListNode* head;
    Stack(){
        head=NULL;
    }

    // 1. PUSH = Function to push an element onto the stack
    void push(int x){
        ListNode* n=new ListNode(x);
        n->next=head;
        head=n;
    }

    // 2. POP = Function to remove an element from the stack
    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }else{
            ListNode* temp=head;
            int val=temp->data;
            head=head->next;
            delete temp;
            return val;
        }
    }

    // 3. TOP = Function to return the top element from the stack
    int top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return head->data;
    }

    // 4. isEmpty = Function to check if stack is empty
    bool isEmpty(){
        return head==NULL;
    }

    // 5. display = Function to print all element in the stack
    void display(){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
            return;
        }
        ListNode* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    // creating a stack 
    Stack st;

    // push - pushing element
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);

    // top - print top element 
    cout<<"Top element = "<< st.top()<<endl;

    // pop - removing element from top
    cout<<"The deleted element is: " << st.pop() << endl;

    // top - print top element 
    cout<<"Top element = "<< st.top()<<endl;

    // isEmpty - print if stack is empty or not
    cout<<"Stack empty or not ? = "<<st.isEmpty()<<endl;

    // display - print all element 
    cout<<"All stack element are :"<<endl;
    st.display();
}

/*
Benefits of implementing a stack using linked list:

1. Dynamic memory allocation: The size of the stack can be increased or decreased dynamically by adding or removing nodes from the linked list, without the need to allocate a fixed amount of memory for the stack upfront.

2. Efficient memory usage: Since nodes in a singly linked list only have a next pointer and not a prev pointer, they use less memory than nodes in a doubly linked list.

3. ast Insertions & Deletions – O(1) time complexity for push() and pop() since we operate at the head.



Real time examples of stack:

1. Undo/Redo operations: In many applications, such as text editors, image editors, or web browsers, the undo and redo functionalities are implemented using a stack. Every time an action is performed, it is pushed onto the stack. When the user wants to undo the last action, the top element of the stack is popped and the action is reversed.

2. Browser history: Web browsers use stacks to keep track of the pages visited by the user. Every time a new page is visited, its URL is pushed onto the stack. When the user clicks the “Back” button, the last visited URL is popped from the stack and the user is directed to the previous page.
*/
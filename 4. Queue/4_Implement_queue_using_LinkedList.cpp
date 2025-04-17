#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    // Time complexity: O(1)
    // Space Complexity: O(1)
    public:
    int data;
    ListNode* next;

    // Constructor
    ListNode(int data){
        this->data=data;
        next=NULL;
    }
};

class Queue{
    public:
    ListNode* front;
    ListNode* rear;
    Queue(){
        front=NULL;
        rear=NULL;
    }

    // Function to add an element to the queue
    void enqueue(int x){
        // creating new node
        ListNode* n= new ListNode(x);

        // If queue is empty, the new node is both the front and rear
        if(front==NULL){
            rear=n;
            front=n;
        }else{
            // add new node to end of queue abd update rear
            rear->next=n;
            rear=n;
        }
    }

    // pop element from front i.e head of linkedlist
    void dequeue(){
        // Checking if the queue is empty
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        ListNode* temp=front;
        front=front->next;
        delete temp;
    }

    // front element of the queue
    int Front(){
        // Checking if the queue is empty
        if(front==NULL){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return front->data;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    cout<<"front = "<<q.Front()<<endl;

    q.dequeue();
    cout<<"front = "<<q.Front()<<endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<"front = "<<q.Front()<<endl;

    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    cout<<"front = "<<q.Front()<<endl;

    q.dequeue();
    cout<<"front = "<<q.Front()<<endl;
}
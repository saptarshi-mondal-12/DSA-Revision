/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

node* display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* insertAtTail(node* &head, int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return head;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return head;
}

node* oddEvenList(node* &head){
    node* even=head;
    node* odd=head->next;
    node* h1=even;
    node* h2=odd;
    

    while(even->next!=NULL && odd->next!=NULL){
        even->next=even->next->next;
        odd->next=odd->next->next;

        even=even->next;
        odd=odd->next;
    }

    even->next=h2;
    head=h1;
}



int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,4);
    insertAtTail(head,7);

    
    display(head); 

    oddEvenList(head);
    display(head);

    

}

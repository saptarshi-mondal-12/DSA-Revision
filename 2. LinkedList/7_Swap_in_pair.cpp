#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Reverse in pair 2 

input: arr={1 2 3 4 5 6 7 8}
output: 2 1 4 3 6 5 8 7

*/

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


node* reverse_in_pair(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;
    int count=1;
    while(curr!=NULL && count<=2){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(curr!=NULL){
        head->next=reverse_in_pair(curr);
    }
    return prev;
}

int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    insertAtTail(head,60);
    display(head);

    node* h1=reverse_in_pair(head);
    display(h1);

    

    
}


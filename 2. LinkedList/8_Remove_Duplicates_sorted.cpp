#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Remove duplicates from sorted linkedList 

input: arr=[1,1,1,2,3,4,5,5,6,6,6,6,6]
output: 1 2 3 4 5 6

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

node* removeDuplicates(node* &head){
    if(head==NULL){
        return head;
    }
    node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            node* todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
            
        }else{
            temp=temp->next;
        }
    }
    return head;
    
}


int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,10);
    insertAtTail(head,10);
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    insertAtTail(head,60);
    insertAtTail(head,60);
    insertAtTail(head,60);
    display(head);

    removeDuplicates(head);
    display(head);

    

    

    
}


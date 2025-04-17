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

node* reverse(node* &head){
    node* prev=NULL;
    node* curr=head;
    node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node* plusOne(node* &head){
    head=reverse(head);
    node* temp=head;
    int carry=1;
    int sum;
    node* prev;
    while(temp!=NULL){
        sum=carry+temp->data;
        carry=sum/10;
        sum=sum%10;
        temp->data=sum;
        prev=temp;
        temp=temp->next;
    }
    if(carry>0){
        node* curr=new node(carry);
        prev->next=curr;
    }
    node* h1=reverse(head);
    return h1;
}


int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    display(head);

    node* h1=plusOne(head);
    display(h1);
}


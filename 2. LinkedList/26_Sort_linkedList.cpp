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

node* sort_LinkedList(node* &head){
    // Time complexity - O(n log n)
    // space complexity - O(n)

    // array based approach

    vector<int>v;
    node*temp=head;
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }

    sort(v.begin(),v.end());

    node* n=new node(0);
    node* p=n;
    for(int i=0;i<v.size();i++){
        node* curr=new node(v[i]);
        p->next=curr;
        p=p->next;
    }
    head=n->next;
    return head;


    // another method - merge sort
}




int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,22);
    insertAtTail(head,16);
    insertAtTail(head,4);
    insertAtTail(head,55);
    insertAtTail(head,2);
    insertAtTail(head,9);
    display(head); 

    sort_LinkedList(head);
    display(head);

}
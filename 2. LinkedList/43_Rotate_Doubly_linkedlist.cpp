#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* Rotate Doubly linked list by N nodes

Given a doubly-linked list, rotate the linked list anti-clockwise by N nodes. 
Here N is a given positive integer and is smaller than the count of nodes in linked list. 

Input : 1,2,3,4,5   N = 2
Output : 3 4 5 1 2 

*/


class node{
    public:

    int data;
    node* next;
    node* prev;

    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void display(node* &head){
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

    if (head->next==NULL){
        head->next=n;
        n->prev=head;
        return head;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    return head;
}

int find_length(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    return count;
}

node* rotate_by_N_node(node* &head, int n){
    // Time Complexity = O(n)+O(n) = O(2n)
    // space complexity - O(1)

    int length=find_length(head);
    n=n%length;

    if (n==0) return head;

    // 1. finding last node to make our list circular
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    head->prev=temp;

    // 2. move head by n
    temp=head;
    int count=1;
    while(count<n){
        temp=temp->next;
        count++;
    }

    head=temp->next;
    head->prev=NULL;
    temp->next=NULL;
    return head;
}



int main(){
    node* head=NULL;
    
    head=insertAtTail(head,1);
    head=insertAtTail(head,2);
    head=insertAtTail(head,3);
    head=insertAtTail(head,4);
    head=insertAtTail(head,5);
    display(head);

    rotate_by_N_node(head,2);
    display(head);


}
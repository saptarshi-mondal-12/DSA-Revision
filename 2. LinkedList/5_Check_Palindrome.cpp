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
    while (curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node* middle(node* &head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow; 
}

bool isPalindrome(node* &head){
    // Time complexity - O(N/2)+O(N/2)+O(N/2)
    /* O(N/2) for finding the middle element, reversing the list from the middle element, and traversing again to find palindrome respectively.*/

    if(head==NULL||head->next==NULL) return true;

    node* p1=head;
    node* mid=middle(head);
    node* p2=reverse(mid);

    // 10 20 30 30 20 10 original
    // 10 -> 20 -> 30 ->40 -> NULL = p1      
    // NULL <- 40 <- 30 <- 20 <- 10 = p2

    while(p2!=NULL){
        if(p1->data!=p2->data){
            return false;
        }
        p1=p1->next;
        p2=p2->next;
    }
    return true;
}

int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,30);
    insertAtTail(head,20);
    insertAtTail(head,10);
    display(head);

    cout<<isPalindrome(head)<<endl;
    
}


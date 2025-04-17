/* Remove duplicates from a sorted Doubly Linked List 

Input: 1 <-> 2 <-> 2 <-> 2 <-> 3
Output: 1 <-> 2 <-> 3
Explanation: We will delete the duplicate values ‘2’ present in the linked lis*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



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



node* removeDuplicatesDDL(node* &head){
    // Time complexity - O(n)
    // space complexity - O(1)
    
    if(head==NULL || head->next==NULL) return head;

    node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            node* todelete=temp->next;

            if(temp->next->next!=NULL){
                temp->next->next->prev=temp;
            }
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
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,3);
    insertAtTail(head,7);
    insertAtTail(head,8);
    display(head);

    removeDuplicatesDDL(head);
    display(head);

    
}


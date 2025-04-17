/* Delete nodes having greater value on right

Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. 
(Not just immediate Right , but entire List on the Right)

Input: LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are the elements which have greater elements on the following nodes. So, after deleting
them, the linked list would like be 15,11, 6, 3.

Input: LinkedList = 10->20->30->40->50->60
Output: 60
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



node* compute(node* &head){
    // Time complexity - O(n)
    // space complexity - O(1)

    node* curr = head;
    node* prev = NULL;
    while(curr != NULL){
        node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr = prev;
    int v = INT_MIN;
    prev = NULL;
    while(curr != NULL){
        node* next = curr->next;
        if(curr->data >= v){
            curr->next = prev;
            prev = curr;
            v = curr->data;
        }
        curr = next;
    }
    head=prev;
    return head;  
}

int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,12);
    insertAtTail(head,15);
    insertAtTail(head,10);
    insertAtTail(head,11);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);

    compute(head);
    display(head);

    
    
    
}


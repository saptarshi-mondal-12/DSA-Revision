#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Nth node from end of linked list

Given a linked list consisting of L nodes and given a number N. T
he task is to find the Nth node from the end of the linked list.

Input: N = 2 , LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
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



node* find_nth(node* &head, int k){
    // Time Complexity: O(n)
    // Time complexity: O(1)
    
    node* slow=head;
    node* fast=head;

    int result;

    for(int i=1; i<=k; i++){
        fast=fast->next;
    }
    
    // 1,2,3,4,5,6 - k=6 - 1 ko print krna hai
    if (fast==NULL){
        result=head->data;

    }else{
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        result=slow->next->data;
    }

    cout<<result;
}


int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);

    find_nth(head,6);
    
}


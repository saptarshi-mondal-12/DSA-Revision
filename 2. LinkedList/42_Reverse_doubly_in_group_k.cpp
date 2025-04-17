#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Reverse a doubly linked list in groups of given size

input: arr={1 2 3 4 5 6 7 8}, k=2
output: 2 1 4 3 6 5 8 7

input: arr={1 2 3 4 5 6 7 8}, k=3
output: 3 2 1 6 5 4 8 7

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



node* reverseDDL_k_Group(node* &head, int k){
    // Time Complexity: O(N)
    // Space Complexity: O(1)
 

    node* prev=NULL;
    node* curr=head;
    node* next;
    int count=1;
    while(curr!=NULL && count<=k){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
        count++;
    }

    /*  If the number of nodes is not a multiple of k then reverse left-out nodes also 1 2 3 4 5, k=3 , ans= 3 2 1 5 4 , alst 2 (4,5) reversed
    */
    if(curr!=NULL){
        head->next=reverseDDL_k_Group(curr,k);
    }else{
        head->next=curr;
    }
    return prev;
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
    insertAtTail(head,7);
    insertAtTail(head,8);
    display(head);

    int k=3;
    node* h1=reverseDDL_k_Group(head,k);
    display(h1);
}


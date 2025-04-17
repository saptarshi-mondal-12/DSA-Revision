#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Reverse in group of given size

input: arr={1 2 3 4 5 6 7 8}, k=2
output: 2 1 4 3 6 5 8 7

input: arr={1 2 3 4 5 6 7 8}, k=3
output: 3 2 1 6 5 4 7 8

input: arr={1 2 3 4 5 6 7 8}, k=5
output: 5 4 3 2 1 6 7 8

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

bool check(node* head, int k){
    node* temp=head;
    int count=1;
    while(temp!=NULL){
        if(count==k){
            return true;
        }else{
            count++;
            temp=temp->next;
        }
    }
    return false;
}

node* reverse_k_Group(node* &head, int k){
    // Time Complexity: O(N)
    // Space Complexity: O(1)
 

    node* prev=NULL;
    node* curr=head;
    node* next;
    int count=1;
    while(curr!=NULL && count<=k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    /*  If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. that's why we put check condition
    1 2 3 4 5, k=3 , ans= 3 2 1 4 5

    otherwise we put if(curr!=NULL) ans= 3 2 1 5 4
    */
    if(check(curr,k)){
        head->next=reverse_k_Group(curr,k);
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

    int k=2;
    node* h1=reverse_k_Group(head,k);
    display(h1);
}


/* Put last k node to start of linkedList

Input: [1,2,3,4,5,6,7]
Output: [5,6,7,1,2,3,4]

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

int length(node* &head){
    node* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

node* appendKNodes(node* &head, int k){
    int l=length(head);
    k=k%l;

    if (k==0) return head;

    node* temp=head;

    int count=0;
    while(count < l-k-1){
        temp=temp->next;
        count++;
    }

    node* newTail=temp;
    node* newHead=temp->next;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=head;
    newTail->next=NULL;
    head=newHead;
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
    display(head);  

    appendKNodes(head,7); 
    display(head);  


}

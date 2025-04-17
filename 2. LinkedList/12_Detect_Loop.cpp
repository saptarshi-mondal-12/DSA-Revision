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

void creteLoop(node* &head, int k){
    // if there is only 1 node and k==1
    if(head->next==NULL && k==1){
        head->next=head;
        return ;
    }
    
    node*temp=head;
    node*loop;
    int count=1;
    while(temp->next!=NULL){
        if (count==k){
            loop=temp;
        }
        temp=temp->next;
        count++;
    }
    // if k==0 means there is no loop
    if(k!=0){
        temp->next=loop;
    }
}

bool detectLoop(node* head){
    // Time complexity - O(n)

    // NOTE- when list is circular i.e there is no NULL the condition will be (fast->next!=NULL && fast->next->next!=NULL)
    if(head == NULL) return false;
    
    node* slow=head;
    node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}



int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);

    creteLoop(head,1);

    cout<<detectLoop(head)<<endl;
    

}


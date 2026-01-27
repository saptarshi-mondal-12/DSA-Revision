/* 

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

node* move_Last_To_Front(node* &head){
    // Time complexity - O(n)
    // Space complexity - O(1)

    if(head==NULL || head->next==NULL){
        return head;
    }

    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    // 1. store last to new head
    node* newHead=temp->next;

    // 2. link head to next of new head 
    newHead->next=head;

    // 3. make temp next NULL
    temp->next=NULL;

    // 4. our head=newHead
    head=newHead;
    return head;
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

    move_Last_To_Front(head);
    display(head);


    

}
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
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

node* addTwoLinkedList(node* &head1, node* &head2){
    // Time complexity - O(max(m,n))
    // space complexity - O(max(m,n)) to create new LinkedList
    
    node* p1=(head1);
    node* p2=(head2);

    node* result=new node(0);
    node* dummy=result;
    int carry=0;
    int sum;

    while(p1!=NULL && p2!=NULL){
        sum=carry+p1->data+p2->data;
        carry=sum/10;
        sum=sum%10;
        dummy->next=new node(sum);
        dummy=dummy->next;
        p1=p1->next;
        p2=p2->next;
    }

    while(p1!=NULL){
        sum=carry+p1->data;
        carry=sum/10;
        sum=sum%10;
        dummy->next=new node(sum);
        dummy=dummy->next;
        p1=p1->next;

    }
    while(p2!=NULL){
        sum=carry+p2->data;
        carry=sum/10;
        sum=sum%10;
        dummy->next=new node(sum);
        dummy=dummy->next;
        p2=p2->next;
    }
    if(carry > 0){
        dummy->next=new node(carry);
    }
    return (result->next);
}

int main(){

    node* head1=NULL;

    // 1. insert at tail
    insertAtTail(head1,1);
    insertAtTail(head1,9);
    insertAtTail(head1,9);
    display(head1);

    node* head2=NULL;
    insertAtTail(head2,1);
    // insertAtTail(head2,6);
    // insertAtTail(head2,4);
    display(head2);

    node* head3=addTwoLinkedList(head1,head2);
    display(head3);

    
    
}


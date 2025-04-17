

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

node* makeIntersection(node* &head1, node* &head2, int k){
    node*  temp1=head1;
    int count=0;
    while(count<k-1){
        count++;
        temp1=temp1->next;
    }

    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;

}



int main(){

    node* head1=NULL;

    // 1. insert at tail
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    display(head1);  

    node* head2=NULL;

    insertAtTail(head2,7);
    insertAtTail(head2,8);
    insertAtTail(head2,9);
    display(head2);  

    makeIntersection(head1,head2,2);
    display(head2);  

   

}

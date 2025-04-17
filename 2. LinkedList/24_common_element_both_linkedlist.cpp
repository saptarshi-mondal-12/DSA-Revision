/*
intersection of two linkedlist
find common in both linkedlist

head1= 1,2,3,4,5,6
head2= 2,3,5,8,10,11,12,14

output - 2,3,5
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

node* common(node* &head1, node* &head2){
    // first chek if head1 is null or head2 is null

    node* n=new node(0);
    node* p=n;
    node* p1=head1;
    node* p2=head2;

    while(p1!=NULL && p2!=NULL){
        if(p1->data==p2->data){
            p->next=p1;
            p=p->next;

            p1=p1->next;
            p2=p2->next;
        }else{
            if (p1->data<p2->data){
                p1=p1->next;
            }else{
                p2=p2->next;
            }
        }
    }
    p->next=NULL;
    return n->next;
}



int main(){

    node* head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    display(head1); 


     node* head2=NULL;
    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,5);
    insertAtTail(head2,8);
    insertAtTail(head2,10);
    insertAtTail(head2,11);
    insertAtTail(head2,12);
    insertAtTail(head2,14);
    display(head2);  

    node* result=common(head1,head2);
    display(result);



   

}

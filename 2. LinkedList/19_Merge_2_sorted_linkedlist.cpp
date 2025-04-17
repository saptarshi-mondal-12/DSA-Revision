/* Put all even node before odd node 

Input : 1->2->4->NULL , 1->3->4->5->NULL
Output : 1->1->2->3->4->4->5->NULL 

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

node* merge(node* &head1, node* &head2){
    node* n=new node(-1);
    node* p=n;

    node* temp1=head1;
    node* temp2=head2;

    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data <= temp2->data){
            node* curr=new node(temp1->data);
            p->next=curr;
            p=p->next;
            temp1=temp1->next;
        }else{
            node* curr=new node(temp2->data);
            p->next=curr;
            p=p->next;
            temp2=temp2->next;
        }
    }

    if (temp1!=NULL){
        p->next=temp1;
    }
    if (temp2!=NULL){
        p->next=temp2;
    }
    return n->next;
}



int main(){

    node* head1=NULL;

    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    display(head1);  

    node* head2=NULL;

    insertAtTail(head2,1);
    insertAtTail(head2,3);
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    display(head2);   

    node* result=merge(head1,head2);
    display(result);

}

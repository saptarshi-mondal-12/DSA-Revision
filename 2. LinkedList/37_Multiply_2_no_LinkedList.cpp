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

node* Multiply_Two_LinkedList(node* &head1, node* &head2){
    // Time complexity - O(max(m,n)) + O(n) + O(n)
    // space complexity - O(n)
    
    long long num1=0, num2=0;
    long long m=1000000007;
    
    node* temp1=head1;
    node* temp2=head2;

    while(temp1!=NULL || temp2!=NULL){
        if (temp1!=NULL){
            num1=( (num1*10)%m + (temp1->data)%m )%m;
            temp1=temp1->next;
        }

        if (temp2!=NULL){
            num2=( (num2*10)%m + (temp2->data)%m )%m;
            temp2=temp2->next;
        }
        
    }

    // if we have to return integer just return 
    long long result=num1*num2;


    // if we have to return node
    node* n = new node(0);
    node* t=n;


    if (result!=0){
        while (result!=0){
            int s=result%10;
            t->next=new node(s);
            t=t->next;
            result=result/10;
        }
        t->next=NULL;
        n=n->next;
    }


    node* prev=NULL;
    node* curr=n;
    node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
    
}

int main(){

    node* head1=NULL;

    // 1. insert at tail
    insertAtTail(head1,999999);
    // insertAtTail(head1,6);
    // insertAtTail(head1,3);
    display(head1);

    node* head2=NULL;
    insertAtTail(head2,99999);
    // insertAtTail(head2,4);
    // insertAtTail(head2,2);
    display(head2);

    node* head3=Multiply_Two_LinkedList(head1,head2);
    display(head3);

    
    
}


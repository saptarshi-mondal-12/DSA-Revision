/* Segregate even and odd nodes in LinkedList

Input : 17->15->8->9->2->4->6->NULL
Output : 8->2->4->6->17->15->9->NULL 

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

node* even_odd(node* &head){
    // Time complexity - O(n);
    // space complexity - O(1)
    
    node* oddHead=new node(-1);
    node* oddTail=oddHead;

    node* evenHead=new node(-1);
    node* evenTail=evenHead;

    node* temp=head;

    while(temp!=NULL){
        int val=temp->data;
        node* n=new node(val);

        if(val%2==0){
            evenTail->next=n;
            evenTail=evenTail->next;
        }else{
            oddTail->next=n;
            oddTail=oddTail->next;
        }
        temp=temp->next;
    }

    evenTail->next=oddHead->next;
    oddTail->next=NULL;

    head=evenHead->next;
}

int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,17);
    insertAtTail(head,15);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,6);
    display(head); 

    even_odd(head);  
    display(head);

}

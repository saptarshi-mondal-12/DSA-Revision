#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Remove duplicates from unsorted linkedList 

input: arr=[]
output: 

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

node* removeDuplicates(node* &head){
    unordered_set<int> seen;
    node* temp=head;
    node* prev=NULL;

    while (temp!=NULL){
        if(seen.find(temp->data)!=seen.end()){
            prev->next=temp->next;
            delete temp;
        }else{
            seen.insert(temp->data);
            prev=temp;
        }
        temp=prev->next;
    }
}


int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,4);
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtTail(head,2);
    insertAtTail(head,2);
    display(head);

    removeDuplicates(head);
    display(head);

    

    

    
}


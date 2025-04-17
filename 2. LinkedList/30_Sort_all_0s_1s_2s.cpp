/* Sort linked list of 0s 1s 2s 

Given a linked list of 'N' nodes, where each node has an integer value that can be 
0, 1, or 2. You need to sort the linked list in non-decreasing order and the 
return the head of the sorted list.

Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1
Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

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

node* sort_LinkedList(node* &head){
    // Time complexity - O(n)
    // space complexity - O(1)

    if(head==NULL || head->next==NULL){
        return head;
    }

    node* zeroHead=new node(-1);
    node* p1=zeroHead;

    node* oneHead=new node(-1);
    node* p2=oneHead;

    node* twoHead=new node(-1);
    node* p3=twoHead;

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            p1->next=temp;
            p1=p1->next;
        }else if(temp->data==1){
            p2->next=temp;
            p2=p2->next;
        }else{
            p3->next=temp;
            p3=p3->next;
        }
        temp=temp->next;
    }

    if(oneHead->next!=NULL){
        p1->next=oneHead->next;
        p2->next=twoHead->next;
    }else{
        p1->next=twoHead->next;
    }
    p3->next=NULL;
    
    head=zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}




int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,0);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,0);
    insertAtTail(head,0);
    display(head); 

    sort_LinkedList(head);
    display(head);

}
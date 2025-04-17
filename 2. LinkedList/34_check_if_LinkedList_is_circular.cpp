/* Check If Linked List is circular or not 

Given head, the head of a singly linked list, find if the linked list is circular or not. 
A linked list is called circular if it not NULL terminated and all nodes are connected in 
the form of a cycle. An empty linked list is considered as circular.

Note: The linked list does not contains any inner loop.

Input: 1->2->3->4->5 (the first and last node is connected, i.e. 5 --> 1)
Output: 1
*/

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

void isCircular(node* &head){
    // Time complexity - 
    // space complexity - 

    node* temp=head;
    while(temp->next!=NULL && temp->next!=head){
        temp=temp->next;
    }

    if(temp->next==NULL){
        cout<<"False - NO LOOP";
    }else{
        cout<<"True - LOOP IS PRESENT";
    } 
    

    
    /* code for detect loop also accepted
    
    node* slow=head;
    node* fast=head;

    int check=false;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            check=true;
            break;
        }
    }

    if(check) cout<<"True";
    else cout<<"False";
    */
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
    creteLoop(head,0); 

    isCircular(head);
}
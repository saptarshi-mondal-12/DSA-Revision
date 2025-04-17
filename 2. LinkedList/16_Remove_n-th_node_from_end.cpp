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

int find_length(node* &head){
    node* t=head;
    int count=0;
    while(t!=NULL){
        count++;
        t=t->next;
    }
    return count;
}

node* brute_remove_nth(node* &head, int k){
    // Time Complexity: O(N) + O(n) = O(2n)

    /* We can traverse through the Linked List while maintaining a count of nodes, let’s say in the variable count, 
    and then traversing for the 2nd time for (n – count) nodes to get to the nth node of the list.*/


    int length=find_length(head);
    
    if (k==length){
        head=head->next;
        return head;
    }

    node* temp=head;
    int count=1;

    while(count < length-k){
        temp=temp->next;
        count++;
    }

    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    return head;
}


node* optimal_remove_nth(node* &head, int k){
    // Time complexity - O(n)
    // space complexity - O(1)
    
    node* slow=head;
    node* fast=head;

    for(int i=1; i<=k; i++){
        fast=fast->next;
    }
    
    // 1,2,3,4,5,6 - k=6 - 1 ko delete krna hai
    if (fast==NULL){
        head=head->next;
        return head;
    }

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    node* todelete=slow->next;
    slow->next=slow->next->next;
    delete todelete;

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
    display(head);

    // brute
    // brute_remove_nth(head,2);
    // display(h1);

    // optimal
    optimal_remove_nth(head,6);
    display(head);
    





}


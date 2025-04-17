// Merge sort in LinkedList

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


node* middle(node* &head){
    // Time complexity - O(n)
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow; 
}

node* merge(node* &left, node* &right){
    if(left==NULL){
        return right;
    }

    if (right==NULL){
        return left;
    }

    node* dummy=new node(-1);
    node* p=dummy;

    // Merge 2 sorted linkedlist method
    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            p->next=left;
            p=p->next;
            left=left->next;
        }else{
            p->next=right;
            p=p->next;
            right=right->next;
        }
    }

    while(left!=NULL){
        p->next=left;
        p=p->next;
        left=left->next;
    }

    while(right!=NULL){
        p->next=right;
        p=p->next;
        right=right->next;
    }
    p->next=NULL;

    return dummy->next;
}


node* mergeSort(node* &head){
    // Time complexity - O(n log n) log n for recursion depth, n for merge, n/2 for finding middle
    // space complexity - O(log n) for recursive stack space

    if (head==NULL || head->next==NULL){
        return head;
    }

    // 1. break linkedlist in 2 halfs
    node* mid=middle(head);
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;


    // 2. Recursive call to sort both halves
    left=mergeSort(left);
    right=mergeSort(right);

    // 3. merge both left and right halves
    node* result=merge(left,right);

    return result;
}


int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,7);
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,4);
    insertAtTail(head,6);
    insertAtTail(head,3);
    insertAtTail(head,1);
    display(head);

    head=mergeSort(head);
    display(head);


}


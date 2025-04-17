/* Find pairs with given sum in doubly linked list 

Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list 
whose sum is equal to given value x, without using any extra space? 

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9    x = 7
Output: (6, 1), (5,2)

*/




#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
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

    if (head->next==NULL){
        head->next=n;
        n->prev=head;
        return head;
    }

    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    return head;
}



void findPairs(node* &head, int x){
    // Time complexity - O(n) + O(n)= O(2n)
    // space complexity - O(1)

    vector<pair<int,int>> ans;

    node* j=head;
    while(j->next!=NULL){
        j=j->next;
    }

    node* i=head;

    while(i->data < j->data){
        if(i->data + j->data == x){
            ans.push_back({i->data,j->data});
            i=i->next;
            j=j->prev;
        }else if(i->data + j->data < x){
            i=i->next;
        }else{
            j=j->prev;
        }
    }

    for (const auto& pair : ans) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;
}





int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,8);
    insertAtTail(head,9);
    display(head);

    findPairs(head, 7);
}


/* Count triplets in a sorted doubly linked list whose sum is equal to a given value x

Given a sorted doubly linked list of distinct nodes(no two nodes have the same data) and a value x. 
Count triplets in the list that sum up to a given value x.

input: 1 2 4 5 6 8 9, x=17
Output: 2
Explanation : (2,6,9) , (4,5,8)
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



void count_Triplets(node* &head, int x){
    // Time complexity - O(n) + O(n^2)
    // space complexity - O(1)

    int count=0;
    vector<vector<int>> result;

    node* last=head;
    while(last->next!=NULL){
        last=last->next;
    }

    node* temp=head;
    while(temp!=NULL){

        if(temp!=head && temp->data==temp->prev->data){
            temp=temp->next;
        }
        else{
            node* l=temp->next;
            node* r=last;

            while(l!=NULL && r!=NULL && l->data<r->data){

                int total=temp->data+l->data+r->data;
                
                if (total==x){
                    result.push_back({temp->data,l->data,r->data});
                    cout<<"( "<<temp->data<<", "<<l->data<<", "<<r->data<<" )"<<endl;
                    count++;
                    l=l->next;
                    r=r->prev;

                    // skipping duplicates
                    while(l!=NULL && l->data<r->data && l->data==l->prev->data){
                        l=l->next;
                    }

                    while(r!=NULL && l->data<r->data && r->data==r->next->data){
                        r=r->prev;
                    }
                }
                else if(total < x){
                    l=l->next;
                }else{
                    r=r->prev;
                }
            }
            temp=temp->next;
        }
    }
    cout<<count<<endl;
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

    count_Triplets(head, 17);
}


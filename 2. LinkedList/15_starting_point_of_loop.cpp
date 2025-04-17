// Find first node of loop in a linked list


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

int starting_point(node* &head){
    // Time complexity - O(n)
    
    if(head==NULL){
        return -1;
    }
    
    node* slow=head;
    node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            slow=head;

            if (fast==slow){
                // in question we have to return node remember that
                return fast->data;
            }else{
                while(fast->next!=slow->next){
                    fast=fast->next;
                    slow=slow->next;
                }
                // in question we have to return node remember that 
                return fast->next->data;
            }
        }
    }
    return -1;
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

    creteLoop(head,1);
    // display(head);

    cout<<starting_point(head)<<endl;

}


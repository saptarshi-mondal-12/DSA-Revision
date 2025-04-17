/* Delete all occurrence of a key in doubly LinkedList

Delete all the nodes having data equal to ‘k’.

Input: 10 4 10 3 5 20 10
k=10
Output: 4 3 5 20

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



node* deleteAllOccurrences(node* &head, int key){
    // Time complexity - O(n)
    // space complexity - O(1)

    if(head==NULL){
        return head;
    }

    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            node* todelete=temp;

            // Change prev only if node to be deleted is NOT the first node
            if(temp->prev!=NULL){
                temp->prev->next=temp->next;
            }
            

            // Change next only if node to be deleted is NOT the last node
            if(temp->next!=NULL){
                temp->next->prev=temp->prev;
            }

            // if node to be deleted is head
            if(temp==head){
                head=head->next;
            }

            temp=temp->next;
            delete todelete;

        }else{
            temp=temp->next;
        }
    }
    return head;
}





int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,10);
    insertAtTail(head,4);
    insertAtTail(head,10);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,20);
    insertAtTail(head,10);
    display(head);

    deleteAllOccurrences(head, 10);
    display(head);

    
}


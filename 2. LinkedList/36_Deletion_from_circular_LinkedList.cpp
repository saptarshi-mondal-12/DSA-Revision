

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
    if (head==NULL) return ;
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

node* delete_node(node* &head, int key){
    // Time complexity - O(n)
    // space complexity - O(1)

    // 1. if linkedlist is empty
    if (head==NULL) return NULL;

    // 2. If the list contains only a single node 
    if (head->next==head && head->data==key){
        delete head;
        head=NULL;
        return head;
    }

    // 3. if head==key
    if(head->data==key){
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
        head=temp->next;
        return head;
    }

    node* temp=head;
    while(temp->next->data!=key && temp->next!=head){
        temp=temp->next;
    }
    if (temp->next->data==key){
        node* todelete=temp->next;
        temp->next=temp->next->next;
        delete todelete;
    }
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
    insertAtTail(head,7);
    display(head); 
    creteLoop(head,1); 

    delete_node(head,1);  
}


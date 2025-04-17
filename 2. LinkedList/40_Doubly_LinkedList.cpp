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

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* insertAtHead(node* &head, int val){
    node* n=new node(val);

    if(head==NULL){
        head=n;
        return head;
    }
    n->next=head;
    head->prev=n;
    head=n;
    return head;

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

node* insertAtIndex(node* &head, int val, int index){
    node* n=new node(val);
    if(index==0){
        insertAtHead(head, val);
        return head;
    }

    int count=0;
    node* temp=head;
    while(count<index-1){
        temp=temp->next;
        count++;
    }
    n->next=temp->next;
    temp->next->prev=n;
    temp->next=n;
    n->prev=temp;
    return head;
}

node* deleteAtHead(node* &head){
    if(head==NULL || head->next==NULL){
        head=NULL;
        return head;
    }

    head=head->next;
    head->prev=NULL;
    return head;

}

node* deleteAtTail(node* &head){
    if(head==NULL || head->next==NULL){
        head=NULL;
        return head;
    }

    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;

    }
    node* todelete=temp->next;
    temp->next=NULL;
    return head;
}

node* deleteAtIndex(node* &head, int index){
    if (index==0){
        deleteAtHead(head);
        return head;
    } 

    // 1 2 3 4 5 - 2

    int count=0;
    node* temp=head;
    while(count<index-1){
        temp=temp->next;
        count++;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;

    if(temp->next!=NULL){
        temp->next->prev=temp;
    }

    delete todelete;
    return head;

}


int main(){
    node* head=NULL;
    
    head=insertAtTail(head,1);
    head=insertAtTail(head,2);
    head=insertAtTail(head,3);
    head=insertAtTail(head,4);
    head=insertAtTail(head,5);
    display(head);

    // 1. insert at head
    // insertAtHead(head,0);
    // display(head);

    // 2. insert at given index
    // insertAtIndex(head,20,2);
    // display(head);

    // 3.delete at head
    // deleteAtHead(head);
    // display(head);

    // 4. delete at tail
    // deleteAtTail(head);
    // display(head);

    // 5. delete at given index
    deleteAtIndex(head,1);
    display(head);


    

    


}
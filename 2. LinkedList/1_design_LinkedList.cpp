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

node* insertAtHead(node* &head, int val){
    node* n=new node(val);
    n->next=head;
    head=n;
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
    temp->next=n;
    return head;
}

node* deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
    return head;
}

node* deleteAtIndex(node* &head, int index){
    if(index==0){
        deleteAtHead(head);
        return head;
    }

    int count=0;
    node*temp=head;
    while(count<index-1){
        temp=temp->next;
        count++;
    }
    node*todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    return head;
}

node* deleteVal(node* &head, int val){
    if(head==NULL){
        return head;
    }
    if(head->data==val){
        deleteAtHead(head);
        return head;
    }

    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
        
    }
    node*todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
    return head;
}

int getVal(node* &head, int index){
    int count=0;
    node* temp=head;
    while(temp!=NULL){
        if(count==index){
            return temp->data;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}

int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    insertAtTail(head,60);
    display(head);

    // 2. insert At head
    // insertAtHead(head,9);
    // insertAtHead(head,8);
    // display(head);


    // 3. insert At given index
    // insertAtIndex(head,1,0); // start
    // insertAtIndex(head,35,5); // middle
    // insertAtIndex(head,75,9); // end
    // display(head);

    // 4. delete at head
    // deleteAtHead(head);
    // display(head);

    // 5. delete at given index
    // deleteAtIndex(head,2); // start
    // deleteAtIndex(head,3); // middle
    deleteAtIndex(head,5); // end
    display(head);

    // 6. delete given value;
    // deleteVal(head, 60);
    // deleteVal(head, 8);
    // display(head);

    // 7. get value from given index;
    // cout<<getVal(head,0)<<endl; // start 
    // cout<<getVal(head,2)<<endl; // middle 
    // cout<<getVal(head,5)<<endl; // end 
}


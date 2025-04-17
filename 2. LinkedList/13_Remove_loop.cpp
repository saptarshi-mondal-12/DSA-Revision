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

void detectLoop(node* head){
    node* slow=head;
    node* fast=head;

    // note - here we first detect loop so it is possible there is no loop or there is a loop
    // if there is no loop means there is NULL, if loop exist means no NULL

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            slow=head;

            // if slow==fast the move fast till fast is != slow and make fast->next =NULL
            if(slow==fast){
                fast=fast->next;
                while(fast->next!=slow){
                    fast=fast->next;
                }
                fast->next=NULL;
                return;
            }
            else{
                while(slow->next!=fast->next){
                    fast=fast->next;
                    slow=slow->next;
                }
                fast->next=NULL;
                return ;
            }
        }
    
    }
}



int main(){

    node* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);

    creteLoop(head,1);

    detectLoop(head);
    display(head);
    

}


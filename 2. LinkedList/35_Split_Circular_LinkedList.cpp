/* Split a Circular Linked List into two halves

Given a Cirular Linked List of size N, split it into two halves circular lists.

If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, 
first list should have one node more than the second list. The resultant lists should also be circular lists 
and not linear lists.

Circular LinkedList: 1->5->7
Output:
1 5
7

Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

*/



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

void splitList(node* &head){
    // Time complexity - O(n)
    // space complexity - O(1)

    node* fast=head->next;
    node* slow=head;

    // note - here we have to find the middle element to split into 2 half so condition - 
    // so if we put NULL it will never end so we have to put head so that we stand at middle

    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    
    // if fast is not at last move fast because we have to make it circular
    if(fast->next->next==head){
        fast=fast->next;
        slow=slow->next;
    }


    // now create 2 halve
    node* half1;
    node* half2;

    // 1. put head to half1
    half1=head;

    // 2. put slow->next to half 2
    half2=slow->next;

    // 3. make half2 to circular that is fast(stand at last) -> next= slow->next;
    fast->next=NULL;

    // 4. make half1 circular 
    slow->next=NULL;


    // checking
    display(half1);
    display(half2);
    
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

    splitList(head);

    
}


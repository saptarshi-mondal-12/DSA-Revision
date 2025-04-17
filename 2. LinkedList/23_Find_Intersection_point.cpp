


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


node* makeIntersection(node* &head1, node* &head2, int k){
    node*  temp1=head1;
    int count=0;
    while(count<k-1){
        count++;
        temp1=temp1->next;
    }

    node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;

}
int length(node* head){
    int count=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

int long_findIntersection(node* &head1, node* &head2){
    // Time complexity - O(m) + O(m-n) + O(n) = O(2m)
    // space complexity - O(1)

    // long code - not to tell
  

    int l1=length(head1);
    int l2=length(head2);

    node* ptr1=head1;
    node* ptr2=head2;

    if(l1>l2){
        int diff=l1-l2;
        while(diff!=0){
            ptr1=ptr1->next;
            diff--;
        }
    }else{
        int diff=l2-l1;
        while(diff!=0){
            ptr2=ptr2->next;
            diff--;
        }
    }

    if(ptr1==ptr2){
        return ptr1->data;
    }

    while(ptr1->next!=ptr2->next){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }

    return ptr1->next->data;
}


int short_findIntersection(node* &head1, node* &head2){
    // Time complexity - O(2 * max(m,n))
    // space complexity - O(1)
    node* temp1=head1;
    node* temp2=head2;

    while(temp1!=temp2){
        if(temp1==NULL){
            temp1=head2;
        }else{
            temp1=temp1->next;
        }

        if(temp2==NULL){
            temp2=head1;
        }else{
            temp2=temp2->next;
        }
    }
    return temp1->data;

}


int main(){

    node* head1=NULL;

    // 1. insert at tail
    insertAtTail(head1,4);
    insertAtTail(head1,1);
    insertAtTail(head1,8);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    display(head1);  

    node* head2=NULL;

    insertAtTail(head2,5);
    insertAtTail(head2,6);
    insertAtTail(head2,1);
    display(head2);  

    makeIntersection(head1,head2,3);
    display(head2); 

    // long code but optimized 
    // cout<<long_findIntersection(head1,head2);

    // short code optimized 
    cout<<short_findIntersection(head1,head2);

   

}
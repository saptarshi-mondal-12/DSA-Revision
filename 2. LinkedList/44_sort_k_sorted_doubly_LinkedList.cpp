/* Sort a k sorted doubly linked list 

You’re given a doubly-linked list with N nodes, where each node deviates at max K position from its position in the sorted list. 
Your task is to sort this given doubly linked list.

For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, 
can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.

Input: 3 6 2 12 56 8, k=2
Output: 2 3 6 8 12 56

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

void display(node* &head){
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
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

node* sortAKSortedDLL(node* &head, int k){
    // Time complexity - O(n log k)
    // space complexity - O(k)

    /* O(N * LogK), where N is the number of nodes in the given linked list and K is the maximum deviation of an element 
    from its target position. As removing an element and adding a new element to min heap will take logK time, hence for N nodes it will be O( N * log K)
    */

    // we can sort in nlogn time complexity using merge sort 
    // but we can reduce time more thats why we use priprity queue because each element is atmost k distance away (left / right) from original position.

    if(head==NULL || head->next==NULL){
        return head;
    }

    // stores k+1 element in ascending order
    priority_queue<node*, vector<node*>, compare> pq;

    // 1. put k+1 node in priority queue
    int count=1;
    node* temp=head;
    while(temp!=NULL && count<=k+1){
        pq.push(temp);
        temp=temp->next;
        count+=1;
    }

    node* newHead=NULL;
    node* last=NULL;

    // traverse till queue is non-empty
    while(pq.size()!=0){
        node* top=pq.top();
        pq.pop();

        if (newHead==NULL){
            newHead=top;
            newHead->prev=NULL;
            last=newHead;
        }else{
            last->next=top;
            top->prev=last;
            last=top;
        }

        if(temp!=NULL){
            pq.push(temp);
            temp=temp->next;
        }
    }
    last->next=NULL;
    head=newHead;
    return newHead;

}

int main(){
    node* head=NULL;
    
    head=insertAtTail(head,3);
    head=insertAtTail(head,6);
    head=insertAtTail(head,2);
    head=insertAtTail(head,12);
    head=insertAtTail(head,56);
    head=insertAtTail(head,8);
    display(head);

    sortAKSortedDLL(head,2);
    display(head);


}
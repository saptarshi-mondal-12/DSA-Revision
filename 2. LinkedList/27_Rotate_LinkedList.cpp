/* Given the head of a linked list, rotate the list to the right by k places.

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
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

node* brute_rotate_Right_by_k(node* &head, int k){
    // Time complexity - O(n*k) = or k times, we are iterating through the entire list to get the last element and move it to first.
    // space complexity - O(1)

    // 1 2 3 4 5

    if(head == NULL || head->next == NULL) return head;

    while(k!=0){
        node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        // standing at 4

        // 1. store end 
        node* end=temp->next; 

        // 2. make 4->next = NULL,  1->2->3->4->NULL 5
        temp->next=NULL;

        // 3. put the head to next of end , 5->1->2->3->4->NULL
        end->next=head; 

        // 4. make head=end
        head=end;

        k-=1;
    }
    return head;
}


node* optimal_rotate_Right_by_k(node* &head, int k){
    // Time complexity - O(n) + O(n - (length%k)) : O(n) for calculating the length of the list. O(length of the list – (length of list%k)) for breaking link.
    // space complexity - O(1)

    if(head == NULL||head->next == NULL||k == 0) return head;

    // 1. calculate length
    node* temp=head;
    int length=1;

    while(temp->next!=NULL){
        temp=temp->next;
        length+=1;
    }

    // 2. connect last node to head
    temp->next=head;

    // 3. calculate k
    k=k%length;

    // 4. to get end of the list
    int end=length-k;

    while(end!=0){
        temp=temp->next;
        end--;
    }

    // 5. currently stand at end of list, make head=temp->next 
    head=temp->next;

    // 6 
    temp->next=NULL;
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
    display(head);  

    // brute
    // brute_rotate_Right_by_k(head,2);
    // display(head);

    // optimal
    optimal_rotate_Right_by_k(head,2);
    display(head);

    

   

}
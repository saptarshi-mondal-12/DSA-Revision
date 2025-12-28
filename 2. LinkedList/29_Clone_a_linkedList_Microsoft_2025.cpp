#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* brute_copyRandomList(Node* head) {
        // /time complexity - O(n)+O(n)
        // space complexity - O(n)

        unordered_map<Node*,Node*> hashMap;
        

        //first iteration for inserting deep nodes of every node in the hashmap.
        Node* temp = head;

        while(temp != NULL) {
            Node* newNode = new Node(temp->val);
            hashMap[temp] = newNode;
            temp = temp->next;
        }


        //second iteration for linking next and random pointer as given question.
        Node* ptr = head;

        while (ptr!=NULL) {
            hashMap[ptr]->next = hashMap[ptr->next]; // linking to next
            hashMap[ptr]->random = hashMap[ptr->random];
            ptr = ptr->next;
        }
        return hashMap[head];
    }



    Node* optimal_copyRandomList(Node* head) {
        // /time complexity - O(n)+O(n)+O(n) ~ O(n)
        // space complexity - O(1)

        /*
        1. Create deep nodes of all nodes. Instead of storing these nodes in a hashmap, we will point it to the next of the original nodes.
        means in middle of two node

        2. Take a pointer, say itr, point it to the head of the list. This will help us to point random pointers as per the original list. 
        This can be achieved by itr->next->random = itr->random->next
        
        3. Use three pointers. One dummy node whose next node points to the first deep node. itr pointer at the head of the original list 
        and fast which is two steps ahead of the itr. This will be used to separate the original linked list with the deep nodes list.
        */

        // 1. making deep copy - in middle

        Node* temp=head;
        while(temp!=NULL){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }

        // step 2 - connecting random 

        Node* itr=head;
        while(itr!=NULL){
            if(itr->random!=NULL){
                // itr->next = 1dash i.e we point randome to 1 dash node (deep copy node)
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        // step 3 - differentiate the original list and deep copy one.
        
        Node* dummy=new Node(0);
        Node* temp1=dummy;

        Node* itr1=head;
        Node* fast;

        while(itr1!=NULL){
            fast=itr1->next->next;
            temp1->next=itr1->next;
            temp1=temp1->next;
            itr1->next=fast;
            itr1=fast;
        }
        return dummy->next;
    }
};
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Q. Insert in Sorted Circular Linked List - AMAZON 2025 

Given a sorted circular linked list, the task is to insert a new node in this circular linked list so that it remains a sorted circular linked list.

Input: head = 1->2->4, data = 2
Output: 1->2->2->4
Explanation: We can add 2 after the second node.

Input: head = 1->4->7->9, data = 5
Output: 1->4->5->7->9
Explanation: We can add 5 after the second node.
*/


class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {

        // Insert before head (new minimum)
        if (data <= head->data) {
            Node* n = new Node(data);
            Node* temp = head;

            // Find last node
            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = n;
            n->next = head;
            return n;
        }

        Node* temp = head;

        // Traverse circular list
        while (temp->next != head) {

            // Normal increasing order case
            if (temp->data <= data && data <= temp->next->data) {
                break;
            }

            temp = temp->next;
        }

        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;

        return head;
    }
};

int main(){

}
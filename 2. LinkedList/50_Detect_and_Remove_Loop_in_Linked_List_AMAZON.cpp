#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Detect and Remove Loop in Linked List | Amazon 2025

Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).
*/

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// Function to detect a loop in the linked list
bool detectLoop(Node *head){
    // Time complexity: O(n) In the presence or absence of a loop, the fast and slow pointers traverse the list at most once.
    // Space complexity: O(1)

    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// Function to remove a loop in the linked list.
void removeLoop(Node *head){
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow){

            // Moving slow pointer to head of linkedList
            slow = head;

            // if slow==fast the move fast till fast is != slow and make fast->next =NULL
            if (slow == fast){
                fast = fast->next;
                while (fast->next != slow)
                {
                    fast = fast->next;
                }
                fast->next = NULL;
                return;
            }
            else{
                while (slow->next != fast->next)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                fast->next = NULL;
                return;
            }
        }
    }
}

void Detect_And_Remove_Loop(Node *head){
    // Time Complexity: O(N)
    // Space Complexity: O(1)


    // if loop is detected i.e true we are going to remove loop 
    if (detectLoop(head) == true){
        removeLoop(head);
    }
}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a loop for testing: 5 -> 3
    head->next->next->next->next->next = head->next->next;


    Detect_And_Remove_Loop(head);
    display(head);

}
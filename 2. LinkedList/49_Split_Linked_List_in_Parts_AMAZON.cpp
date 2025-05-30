#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Split Linked List in Parts | Amazon 2025

Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.


Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

*/

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

ListNode* display(ListNode* head){
    ListNode* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int findLength(ListNode *head){
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

ListNode* insertAtTail(ListNode* &head, int val){
    ListNode* n=new ListNode(val);
    if(head==NULL){
        head=n;
        return head;
    }
    ListNode* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return head;
}


vector<ListNode *> splitListToParts(ListNode *head, int k){
    // 1. calculate length of linkedlist
    int length = findLength(head);

    // 2. determine size of each part;
    int partition = length / k;
    int extra = length % k;

    // 3. initialize a vector to store result
    vector<ListNode *> result(k);

    // 4. split linkedlist into parts
    ListNode *temp = head;
    for (int i = 0; i < k; i++){
        int size = partition;
        if (extra > 0){
            size += 1;
            extra -= 1;
        }
        if (size == 0){
            result[i] = NULL;
        }
        else{
            ListNode *dummy = temp;
            while (size - 1 != 0){
                temp = temp->next;
                size--;
            }
            ListNode *curr = temp->next;
            temp->next = NULL;
            result[i] = dummy;
            temp = curr;
        }
    }

    return result;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(){

    ListNode* head=NULL;

    // 1. insert at tail
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,10);
    display(head);

    int k=3;
    vector<ListNode *> result = splitListToParts(head,k);

    // Print each part
    for (int i = 0; i < result.size(); ++i) {
        std::cout << "Part " << i + 1 << ": ";
        printList(result[i]);
    }
    
}
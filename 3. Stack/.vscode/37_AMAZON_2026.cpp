// Q. Design a stack that perform push, pop, getMiddle and top in O(1) operation - AMAZON 2026

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode* prev;
    ListNode(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class Stack{
    public:
    ListNode* head=NULL;
    ListNode* mid = NULL;
    int count = 0;
    
    void push(int val){
        ListNode* n = new ListNode(val);
        
        if(head == NULL){
            head = n;
        }else{
            n->next=head;
            head->prev = n;
            head=n;
        }
        count++;
        if(count == 1){
            mid=n;
        }else if(count % 2 == 0){
            mid = mid->prev;
        }
    }
    
    void pop(){
        if(head == NULL){
            return;
        }
        
        ListNode* temp=head;
        head=head->next;
        
        if(head != NULL){
            head->prev=NULL;
        }
        
        count--;
        
        if(count == 0){
            mid = NULL;
        }
        else if(count%2 == 1){
            mid = mid->next;
        }
        
        delete temp;
    }
    
    int getMiddle(){
        if(mid == NULL) return -1;
        return mid->data;
    }
    
    int top(){
        if(head == NULL) return -1;
        return head->data;
    }
    
};

int main(){
    
    Stack s;

    cout << s.top() << endl;        // -1
    cout << s.getMiddle() << endl;  // -1
    
    s.push(10);
    cout << s.top() << " " << s.getMiddle() << endl;
    
    s.push(20);
    cout << s.top() << " " << s.getMiddle() << endl;
    
    s.push(30);
    cout << s.top() << " " << s.getMiddle() << endl;
    
    s.push(40);
    cout << s.top() << " " << s.getMiddle() << endl;
    
    s.pop();
    cout << s.top() << " " << s.getMiddle() << endl;
    
    s.pop();
    cout << s.top() << " " << s.getMiddle() << endl;
    
    s.pop();
    cout << s.top() << " " << s.getMiddle() << endl;
    
    s.pop();
    cout << s.top() << " " << s.getMiddle() << endl;
    
}

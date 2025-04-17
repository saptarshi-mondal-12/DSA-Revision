#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Time complexity - O(n)
// space complexity - O(n)

void reverse(queue<int>q){
    stack<int>s;
    while(!q.empty()){
        int data=q.front();
        s.push(data);
        q.pop();
    }

    while(!s.empty()){
        int data=s.top();
        q.push(data);
        s.pop();
    }

    while(!q.empty()){
        int data=q.front();
        cout<<data<<" ";
        q.pop();
    }
    cout<<endl;
}

// Time complexity - O(n)
// space complexity - O(1)

void reverseQueue(queue<int> &q) {
    if (q.empty()) {
        return;
    }
    int num = q.front();
    q.pop();
    reverseQueue(q);
    q.push(num);
}

void reverse_recursion(queue<int>q){
    reverseQueue(q);
    while(!q.empty()){
        int data=q.front();
        cout<<data<<" ";
        q.pop();
    }
    cout<<endl;
}


int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // 1. using stack
    // reverse(q);

    // 2. using recursion
    reverse_recursion(q);
}

#include<iostream>
#include<queue>
#include<stack>
using namespace std;


// Time complexity - O(n)
// space complexity - O(1)

void reverseQueue(queue<int> &q, int k, int count) {
    if (count==k) {
        return;
    }
    int num = q.front();
    q.pop();
    reverseQueue(q,k,count+1);
    q.push(num);
}

void reverse_recursion(queue<int>q, int k){
    int count=0;
    reverseQueue(q,k,count);

    // 4 5 3 2 1

    // ans = 3 2 1 4 5
    int t=q.size()-k;

    while(t--){
        int data=q.front();
        q.pop();
        q.push(data);
    }

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

    int k=3;
    reverse_recursion(q,k);
}

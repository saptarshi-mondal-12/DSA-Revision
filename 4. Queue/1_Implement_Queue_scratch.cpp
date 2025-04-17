#include<iostream>
#include<queue>
using namespace std;

// Time complexity : inserting - O(1) , deleing - O(n)
// Space complexity - O(n) - using array


class Queue{
        int *arr;
        int qfront;
        int rear, n;
    public:
        Queue(int N){
            n=N;
            arr = new int[n];
            qfront=0;
            rear=0;
        }

    void enqueue(int x){
        if(rear == n){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        arr[rear]=x;
        rear++;

    }

    void dequeue(){
        if(qfront==rear){
            cout<<"No Element"<<endl;
        }else{
            // shifting all element 1 left
            for (int i = 1; i < rear; i++) {
                arr[i - 1] = arr[i];
            }
            rear--;
        }
    }

    void front(){
        if(qfront == rear){
            cout<<"No Element"<<endl;
        }else{
            cout<< arr[qfront]<<endl;
        }
    }

    void isEmpty(){
        if( qfront==rear){
            cout<<"Empty"<<endl;
        }else{
            cout<<"Not Empty"<<endl;
        }
    }

};

int main(){
    Queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.front();
    q.dequeue();
    q.front();
    q.isEmpty();
}

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* Implement k queue in single array

Method 2 (A space efficient implementation):

The idea is similar to the stack post, here we need to use three extra arrays. In stack post, we needed two extra arrays, one more array is required because in queues, enqueue() and dequeue() operations are done at different ends.

Following are the three extra arrays are used: 

front[]: This is of size k and stores indexes of front elements in all queues. 
rear[]: This is of size k and stores indexes of rear elements in all queues. 
next[]: This is of size n and stores indexes of next item for all items in array arr[]. 
Here arr[] is the actual array that stores k stacks.

Together with k queues, a stack of free slots in arr[] is also maintained. The top of this stack is stored in a variable ‘free’.

All entries in front[] are initialized as -1 to indicate that all queues are empty. All entries next[i] are initialized as i+1 because all slots are free initially and pointing to the next slot. Top of the free stack, ‘free’ is initialized as 0.
*/

class Queue{
    // Time complexities:  enqueue() and dequeue() is O(1).
    public:
    int n;
    int k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

    // constructor
    Queue(int n, int k){
        this->n=n;
        this->k=k;
        arr=new int[n];
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }
        
        next=new int[n];
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
        
        // initialize freeSpot
        freespot=0;
    }
    // 1. PUSH =  push element x on to the queue q 
    void enqueue(int x, int q){
        // check overflow
        if(freespot==-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }

        //  find index to put element
        int index=freespot;

        // update freespot
        freespot=next[index];

        // check whether current element is the first element for q
        if(front[q-1]==-1){
            front[q-1]=index;
        }else{
            // link new element to previous element
            next[rear[q-1]]=index;
        }

        //update next
        next[index]=-1;

        //update rear
        rear[q-1]=index;

        //push element
        arr[index]=x;
    }

    // 2. POP = Remove front element from stack q
    void dequeue(int q){
        // check underflow
        if(front[q-1]==-1){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        // find index to pop
        int index=front[q-1];

        // front ko aage badhao
        front[q-1]=next[index];

        // FreeSlot ko manage kro
        next[index]=freespot;
        freespot=index;
    }

    // 3. Front = return the front element of queue q 
    int Front(int q){
        if(front[q-1]==-1){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        return arr[front[q-1]];
    }
};

int main(){
    Queue q(10,3);

    q.enqueue(10,1);
    q.enqueue(20,1);
    q.enqueue(30,2);
    q.enqueue(40,1);
    cout<<"Front element= "<<q.Front(1)<<endl;

    q.dequeue(1);
    cout<<"Front element= "<<q.Front(1)<<endl;
    q.dequeue(1);
    cout<<"Front element= "<<q.Front(1)<<endl;
    q.dequeue(1);
    cout<<"Front element= "<<q.Front(1)<<endl;
    cout<<"Front element= "<<q.Front(2)<<endl;

}

/*
The best part of the above implementation is, if there is a slot available in the queue, then an item can be enqueued in any of the queues, i.e., no wastage of space. This method requires some extra space. Space may not be an issue because queue items are typically large, for example, queues of employees, students, etc where every item is of hundreds of bytes. For such large queues, the extra space used is comparatively very less as we use three integer arrays as extra space.*/
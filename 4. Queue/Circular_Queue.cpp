#include<iostream>
#include<queue>
using namespace std;

// Time complexity O(1)

class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int currSize;
    int capacity;

    MyCircularDeque(int k) {
        arr = new int[k];
        front=0;
        rear=k-1;
        currSize=0;
        capacity = k;

    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front=(front-1+capacity)%capacity;
        arr[front]=value;
        currSize++;
        return true;
        
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear=(rear+1)%capacity;
        arr[rear]=value;
        currSize++;
        return true;
        
    }
    
    bool deleteFront() {
        if (isEmpty()){
            return false;
        }
        front = (front + 1) % capacity;
        currSize--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear=(rear-1+capacity)%capacity;
        currSize--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        return arr[rear]; 
    }
    
    bool isEmpty() {
        if(currSize==0){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(currSize==capacity){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    int k=5;
    MyCircularDeque q(k);
    q.insertFront(1);
    q.insertFront(2);
    q.insertFront(3);
    q.insertFront(4);
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;  
}

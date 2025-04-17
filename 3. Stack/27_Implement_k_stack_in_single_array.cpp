#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Q. Implement k stacks in a single array

Problem Statement:  Design a data structure to implement ‘K’ stacks using a single array of size ‘S’. It should support the following operations:
push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.
pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.


-----------Solution 1: Brute Force - Divide the array in slots of size n/k
A simple way to implement k stacks is to divide the array in k slots where length of each part will be k/n and each part will have its own top to implement the stack.
The problem with this method is inefficient use of array space. A stack push operation may result in stack overflow even if there is space available in arr[]. For example, say the k is 2 and array size (n) is 6 and we push 3 elements to first and do not push anything to second stack. When we push 4th element to first, there will be overflow even if we have space for 3 more elements in array. 



-----------Solution 2: Optimal - space optimize
The idea is to use two extra arrays for efficient implementation of k stacks in an array.

Following are the two extra arrays are used: 
1) top[]: This is of size k and stores indexes of top elements in all stacks. 
2) next[]: This is of size n and stores indexes of next item for the items in array arr[]. 

Here arr[] is actual array that stores k stacks. Together with k stacks, a stack of free slots in arr[] is also maintained. The top of this stack is stored in a variable ‘free’. All entries in top[] are initialized as -1 to indicate that all stacks are empty. All entries next[i] are initialized as i+1 because all slots are free initially and pointing to next slot. Top of free stack, ‘free’ is initialized as 0. 
*/

class Stack{
    // Time Complexity: O(1)
    // Space Complexity: O(n+k)
    int *arr;
    int *top;
    int *next;
    int n, k, freeSpot;
        
    public:
    Stack(int Size, int K){
        n=Size;
        k=K;
        arr=new int[n];
        top=new int[k];
        next=new int[n];

        // top initialize
        for(int i=0;i<k;i++){
            top[i]=-1;
        }
    
        // next initialize
        for(int i=0;i<n;i++){
            next[i]=i+1;
        }
        next[n-1]=-1;
    
        // initialize freeSpace
        freeSpot=0;
    }
    
    
    // 1. PUSH =  push element x on to the stack m
    bool Push(int x, int m){
        // check for overflow
        if(freeSpot==-1){
            cout<<"Stack Overflow"<<endl;
            return false;
        }

        // 1. find index to put element
        int index=freeSpot;

        // 2. update freeSpot
        freeSpot=next[index];

        // 3. insert element into array
        arr[index]=x;

        // 4. update next;
        next[index]=top[m-1];

        // 5. update top
        top[m-1]=index;

        return true;
    }

    // 2. POP = Remove top element from stack m
    int Pop(int m){
        // check for underflow
        if(top[m-1]==-1){
            cout<<"Stack Underflow"<<endl;
            return -1;
        }

        // find index
        int index =top[m-1];

        //update top
        top[m-1]=next[index];

        //update next
        next[index]=freeSpot;

        // update freeSpot
        freeSpot=index;

        return arr[index];
        
    }
    
    // 3. TOP = return the top element from the stack m
    int Top(int m){
        if(top[m-1]==-1){
            cout<<"Stack Undeflow"<<endl;
            return -1;
        }

        // find index
        int index=top[m-1];
        return arr[index];
    }
};

int main(){
    int n=9, k=3;
    Stack st(n,k);

    cout<<st.Push(10,1)<<endl;
    cout<<st.Push(20,1)<<endl;
    cout<<st.Push(70,1)<<endl;
    cout<<st.Push(30,3)<<endl;
    cout<<st.Push(40,2)<<endl;
    cout<<st.Push(50,1)<<endl;

    cout<<st.Pop(2)<<endl;
    cout<<st.Pop(3)<<endl;
    cout<<st.Pop(1)<<endl;

    cout<<st.Top(1)<<endl;
    cout<<st.Top(2)<<endl;
    cout<<st.Top(3)<<endl;
}
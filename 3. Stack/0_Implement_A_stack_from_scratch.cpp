#include<iostream>
using namespace std;



class Stack{
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    int n;
    int *arr;
    int top;
        
    public:
        Stack(){
            top=-1;
            n=100;
            arr=new int[n];
        }

    void push(int x){
        if(top==n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top=top+1;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow"<<endl;
            return;
        }
        top=top-1;
    }
    int get_top(){
        if(top==-1){
            cout<<"No element"<<endl;
            return 0;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
        
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.get_top()<<endl;
    s.pop();
    cout<<s.get_top()<<endl;
}
#include<iostream>
#include<stack>
using namespace std;


// Helper function to insert an element in sorted stack
void sortElement(stack<int>&st, int element){
    // Base case: stack is empty or element is greater than top
    if(st.empty() or st.top()<element){
        st.push(element);
        return;
    }
    // Otherwise pop the top and recurse
    int num=st.top();
    st.pop();
    sortElement(st,element);
    // Push back the top element
    st.push(num);
}



// 1. Give a array sort it using stack-------------------------------------------------------
void sort(int arr[], int n){
    stack<int>st;
    for(int i=0;i<n;i++){
        int element=arr[i];
        sortElement(st,element);
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}




// 2. Give a stack sort it-----------------------------------------------------------------
void sortStack(stack<int>& st) {
    // Base case: stack has only one element or empty
    if (st.empty()) return;

    int top = st.top();
    st.pop();

    // Sort the remaining stack
    sortStack(st);

    // Insert the top element back in sorted order
    sortElement(st, top);
}
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}


int main(){
    // 1. sort a array using stack
    // int n=6;
    // int arr[n]={5,-2,9,-7,3,0};
    // sort(arr,n);

    

    // 2. sort a stack
    stack<int> st;
    st.push(5);
    st.push(-2);
    st.push(9);
    st.push(-7);
    st.push(3);
    st.push(0);
    sortStack(st);
    printStack(st);
}
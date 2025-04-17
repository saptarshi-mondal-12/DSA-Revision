#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&st, int n, int element){
    if(st.empty()){
        st.push(element);
        return;
    }

    int num=st.top();
    st.pop();
    solve(st,n,element);
    st.push(num);
}

void insertAtFirst(int arr[], int n, int element){
    stack<int>st;
    for(int i=0;i<n;i++){
        st.push(arr[i]);
    }

    solve(st,n,element);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    int n=6;
    int arr[n]={1,2,3,4,5,6};
    int element=9;
    insertAtFirst(arr,n,element);
}
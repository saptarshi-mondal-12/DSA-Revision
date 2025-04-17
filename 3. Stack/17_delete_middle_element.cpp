#include<iostream>
#include<stack>
using namespace std;

// Time complexity - O(n)

void solve(stack<int>&st, int n, int count){
    if(count==n/2){
        st.pop();
        return;
    }
    int num=st.top();
    st.pop();
    
    solve(st,n,count+1);

    st.push(num);
}

void deleteMiddleElement(int arr[], int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(arr[i]);
    }

    int count=0;
    solve(st,n,count);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    int n=7;
    int arr[n]={1,2,3,4,5,6,7};

    deleteMiddleElement(arr,n);
}

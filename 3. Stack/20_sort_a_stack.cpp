#include<iostream>
#include<stack>
using namespace std;

void sortElement(stack<int>&st, int element){
    if(st.empty() or st.top()<element){
        st.push(element);
        return;
    }
    int num=st.top();
    st.pop();
    sortElement(st,element);

    st.push(num);
}

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


int main(){
    int n=6;
    int arr[n]={5,-2,9,-7,3,0};
    sort(arr,n);
}
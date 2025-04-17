#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void prevSmaller(int arr[], int n){
    // Time complexity - O(n)
    // space complexity - O(n)

    stack<int>s;

    vector<int>result(n,-1);

    // NOTE - PREV = STARTING WITH 0 INDEX

    for(int i=0;i<n;i++){
        int curr=arr[i];

        while(!s.empty() and s.top() >= curr){
            s.pop();
        }
        if(!s.empty()){
            result[i]=s.top();
        }

        s.push(curr);
    }

    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n=6;
    int arr[n]={1, 5, 0, 3, 4, 5};
    prevSmaller(arr,n);
}

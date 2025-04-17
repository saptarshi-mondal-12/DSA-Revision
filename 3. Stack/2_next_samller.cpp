#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextSmaller(int arr[], int n){
    stack<int>s;

    vector<int>result(n,-1);

    // NOTE - NEXT = STARTING WITH n-1 INDEX

    for(int i=n-1;i>=0;i--){
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
    int n=4;
    int arr[n]={2,1,4,3};
    nextSmaller(arr,n);
}

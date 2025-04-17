#include<iostream>
#include<stack>
#include<vector>
using namespace std;



void prevGreater(int arr[], int n){
    // time complexity = O(n)
    // space complexity = O(n)  
    
    stack<int>s;

    vector<int>result(n,-1);

    // NOTE - PREV = STARTING WITH 0 INDEX

    for(int i=0;i<n;i++){
        int curr=arr[i];

        while(!s.empty() && s.top() < curr){
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
    int n=7;
    int arr[n]={10, 4, 2, 20, 40, 12, 30};
    prevGreater(arr,n);
}
